#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/msg/coordinates.hpp"

using namespace std;

class control_leg : public rclcpp::Node
{
public:
    control_leg() : Node("leg_control"), counter(1){
        RCLCPP_INFO(this->get_logger(), "Booting UP");
        coords = this->create_publisher<hexapod_interfaces::msg::Coordinates>("coords", 10);
        x = 0;
        y = 150;
        z = 50;
        timer = this->create_wall_timer(chrono::seconds(1), bind(&control_leg::traverse, this));
    }
private:
    struct Point3d {
        float x;
        float y;
        float z;
    };

    Point3d lerp(Point3d start, Point3d end, float t){
        Point3d result;

        result.x = start.x + ((end.x - start.x) * t);
        result.y = start.y + ((end.y - start.y) * t);
        result.z = start.z + ((end.z - start.z) * t);
        
        return result;
    }
    
    void traverse(){
        
        auto node = hexapod_interfaces::msg::Coordinates();
        
        Point3d start = {(float)this->x, (float)this->y, (float)this->z};
        Point3d end = {node.x, node.y, node.z};

        for(int i = 0; i <= 50; i++){
            
            Point3d result = this->lerp(start, end, (float)i/50);
            node.x = result.x;
            node.y = result.y;
            node.z = result.z;
        
            this->coords->publish(node);
            RCLCPP_INFO(this->get_logger(), "X: %d", node.x);
            RCLCPP_INFO(this->get_logger(), "Y: %d", node.y);
            RCLCPP_INFO(this->get_logger(), "Z: %d", node.z);
        }

    }

    // void callback(){
        
        
        
    //     RCLCPP_INFO(this->get_logger(), "X: %d", this->x);
    //     RCLCPP_INFO(this->get_logger(), "Y: %d", this->y);
    //     RCLCPP_INFO(this->get_logger(), "Z: %d", this->z);
    //     this->coords->publish(node);

    // }

    rclcpp::TimerBase::SharedPtr timer;
    int counter;
    int x, y, z;
    // int prev_x, prev_y, prev_z;
    int f = 1;
    rclcpp::Publisher<hexapod_interfaces::msg::Coordinates>::SharedPtr coords;
};


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = make_shared<control_leg>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}

// import numpy as np


// def lerp(start, end, t):

//     start = np.array(start, dtype=float)
//     end = np.array(end, dtype=float)

//     return start + (end - start) * t


// def generate_trajectory(start, end, steps=50):
//     trajectory = []

//     for i in range(steps + 1):
//         t = i / steps
//         point = lerp(start, end, t)
//         trajectory.append(point)

//     return trajectory


// start_position = [0, 150, -80]
// end_position   = [0, 150, 160]

// trajectory = generate_trajectory(
//     start_position,
//     end_position,
//     steps=50
// )

// for point in trajectory:
//     print(
//         f"x={point[0]:.2f}, "
//         f"y={point[1]:.2f}, "
//         f"z={point[2]:.2f}"
//     )

// struct Point3D {
//     float x;
//     float y;
//     float z;
// };


// Point3D lerp(Point3D start, Point3D end, float t)
// {
//     Point3D result;

//     result.x = start.x + (end.x - start.x) * t;
//     result.y = start.y + (end.y - start.y) * t;
//     result.z = start.z + (end.z - start.z) * t;

//     return result;
// }


// int main()
// {
//     Point3D start = {100, 0, -80};
//     Point3D end   = {150, 0, -80};

//     for(int i = 0; i <= 50; i++)
//     {
//         float t = (float)i / 50;

//         Point3D foot = lerp(start, end, t);

//         std::cout 
//             << "X: " << foot.x
//             << " Y: " << foot.y
//             << " Z: " << foot.z
//             << std::endl;
//     }

//     return 0;
// }