#include "rclcpp/rclcpp.hpp"
#include "hexapod_interfaces/srv/inverse_kinematics.hpp"
#include <cmath> 

using namespace std::chrono_literals;
using namespace std;
class IKinematics: public rclcpp::Node{
    public:
        IKinematics():Node("Inverse_Kinematics_Solver"){
            RCLCPP_INFO(this->get_logger(), "Inverse Kinematics Solver Server Created");
            server = this->create_service<hexapod_interfaces::srv::InverseKinematics>("iksolver", std::bind(&IKinematics::solver, this, std::placeholders::_1, std::placeholders::_2));
            RCLCPP_INFO(this->get_logger(), "Solver Ready ONLY SOLVES FEMUR AND TIBIA");
        }
    private:
        void solver(const hexapod_interfaces::srv::InverseKinematics::Request::SharedPtr request, const hexapod_interfaces::srv::InverseKinematics::Response::SharedPtr response){
            // if(!(request->coxa_length <= 0) && !(request->femur_length <= 0)  !(request->tibia_length <= 0)){
                int coxa_length, a, b, target_x, target_y, target_z;
                coxa_length = request->coxa_length;
                a = request->tibia_length;
                b = request->femur_length;
                target_x = request->x;
                target_y = request->y;
                target_z = request->z;
                //ONLY SOLVING TIBIA AND FEMUR ANGLE( Y AND Z COORDINATES )
            
                double c = hypot(target_z - 0, target_y - 0);

                float alpha = (90*3.14) / 180;

                float beta = (acos(((a*a)+(c*c)-(b*b)) / (2*a*c)));

                float gamma = 3.14 - acos(((a*a)+(b*b)-(c*c)) / (2*a*b));


                response->coxa = 0;
                response->femur = alpha + beta;
                response->tibia = gamma;

            // } 
        }
        rclcpp::Service<hexapod_interfaces::srv::InverseKinematics>::SharedPtr server;
};


// %leg = [58, (76+63)/2, (58/2) + 120];

// a = 10;
// b = 10;

// angles = zeros(10,2);
// angled = zeros(10,2);

// for i = 2:2:20
//     c = sqrt((i - 0)^2 + (0 - 0)^2);
//     alpha = 90*3.14/180;
//     beta = acos( ((a*a)+(c*c)-(b*b)) / (2*a*c));
   
//     gamma = 3.14 - acos( ((a*a)+(b*b)-(c*c)) / (2*a*b));
   
//     angles(i/2,:) = [beta, gamma];
//     angled(i/2,:) = [acosd(((a*a)+(c*c)-(b*b)) / (2*a*c)), 180 - acosd( ((a*a)+(b*b)-(c*c)) / (2*a*b))];
// end

// angles
// angled


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<IKinematics>();
    // RCLCPP_INFO(node->get_logger(), "Hello World");

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}