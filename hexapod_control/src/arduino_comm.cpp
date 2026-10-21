#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include <array>
#include <cerrno>
#include <chrono>
#include <cstring>
#include <functional>
#include <memory>
#include <string>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/leg_actuators.hpp"

using hexapod_interfaces::msg::LegActuators;

// Open and configure a serial port (115200 8N1, raw). Returns fd or -1.
static int open_serial(const std::string &path)
{
    int fd = ::open(path.c_str(), O_RDWR | O_NOCTTY);
    if (fd < 0) {
        return -1;
    }

    termios tty{};
    if (tcgetattr(fd, &tty) != 0) {
        ::close(fd);
        return -1;
    }

    cfmakeraw(&tty);
    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSTOPB;   // 1 stop bit
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 10;     // 1.0 s read timeout (deciseconds)

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        ::close(fd);
        return -1;
    }
    return fd;
}

class ArduinoDriverNode : public rclcpp::Node
{
public:
    explicit ArduinoDriverNode(int fd)
    : Node("arduino_client"), fd_(fd)
    {
        for (size_t i = 0; i < 7; ++i) {
            const std::string topic = "leg" + std::to_string(i + 1);
            subs_[i] = this->create_subscription<LegActuators>(
                topic, 10,
                [this, i](const LegActuators::SharedPtr msg) { this->move_leg(i, *msg); });
        }
    }

    ~ArduinoDriverNode() override
    {
        if (fd_ >= 0) {
            ::close(fd_);
        }
    }

private:
    // Send the data as "Coxa_deg;Femur_deg;Tibia_deg\n"
    void move_leg(size_t leg_index, const LegActuators &msg)
    {
        (void)leg_index;  // NOTE: not transmitted, same as the original Python code
        const std::string cmd =
            std::to_string(static_cast<int>(msg.coxa)) + ";" +
            std::to_string(static_cast<int>(msg.femur)) + ";" +
            std::to_string(static_cast<int>(msg.tibia)) + "\n";

        if (!write_all(cmd)) {
            RCLCPP_ERROR(this->get_logger(), "Serial write failed: %s", std::strerror(errno));
            return;
        }
        RCLCPP_INFO(this->get_logger(), "%s", cmd.c_str());
    }

    bool write_all(const std::string &data)
    {
        size_t sent = 0;
        while (sent < data.size()) {
            ssize_t n = ::write(fd_, data.data() + sent, data.size() - sent);
            if (n < 0) {
                if (errno == EINTR) {
                    continue;
                }
                return false;
            }
            sent += static_cast<size_t>(n);
        }
        return true;
    }

    int fd_;
    std::array<rclcpp::Subscription<LegActuators>::SharedPtr, 6> subs_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // Connect with ACM0, else try ACM1; retry every second.
    int fd = -1;
    const char *ports[] = {"/dev/ttyACM0", "/dev/ttyACM1"};
    while (rclcpp::ok() && fd < 0) {
        for (const char *port : ports) {
            fd = open_serial(port);
            if (fd >= 0) {
                break;
            }
        }
        if (fd >= 0) {
            std::printf("Successfully connected to Serial.\n");
            // Opening the port typically resets the Arduino; give it time to boot.
            std::this_thread::sleep_for(std::chrono::seconds(1));
            tcflush(fd, TCIFLUSH);  // equivalent of reset_input_buffer()
        } else {
            std::printf("Could not connect to Serial. Retrying in 1 second...\n");
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    if (fd < 0) {  // interrupted by Ctrl+C before connecting
        rclcpp::shutdown();
        return 1;
    }

    auto node = std::make_shared<ArduinoDriverNode>(fd);  // node owns and closes fd
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}