%leg = [58, (76+63)/2, (58/2) + 120];

%% ===================== LEG PROPERTIES =====================
a = 50;
b = 75;
c = 112;
theta1 = 0;

target_x = 150;
target_y = 75 ;
target_z = 90;

t1 = atan2d(target_y + a,target_x)
target_y = (target_y)/sind(t1);

d = sqrt((target_y + a)^2 + (target_z)^2);

alpha = abs(atand((target_y + a)/-target_z));

if isnan(alpha)
    alpha = 0;
end
beta = acosd( ((b*b) + (d^2) - (c^2)) / (2*b*d));

if isnan(beta)
    beta = 0;
end

gamma = acosd( ((b^2) + (c^2) - (d^2)) / (2*b*c) );

t2 = beta + alpha;
t3 = 180 - (gamma);


void solver(const hexapod_interfaces::msg::Coordinates::SharedPtr msg){

            // Save the current joint angles as the interpolation starting point
            this->start = {this->coxa, this->femur, this->tibia};

            double a = this->coxa_l;
            double b = this->femur_l;
            double c = this->tibia_l;

            double d = hypot(msg->z - 0, msg->y);

            float t1 = atan2(msg->y + a, msg->x);

            float target_y = msg->y/sin(t1);
            
            d = hypot(target_y + a, msg->z);

            float alpha  = abs(atan((target_y + a)/-msg->z));

            if (std::isnan(alpha)) {
                alpha = 0.0f;
            }
            RCLCPP_INFO(this->get_logger(), "target_y:%f sin(t1):%f msg->y:%f msg->y+coxa:%f msg->x:%f t1:%f", target_y, sin(t1) * 180.0f / M_PI, msg->y, msg->y+this->coxa, msg->x, sin(t1));

            float beta = (
                acos(
                    ((b * b) + (d * d) - (c * c)) /
                    (2 * b * d)
                )
            ) * 180.0f / M_PI;

            // Prevent invalid values when the target is unreachable
            if (std::isnan(beta)) {
                beta = 90.0f;
            }

            float gamma = (
                acos(
                    ((b * b) + (c * c) - (d * d)) /
                    (2 * b * c)
                )
            ) * 180.0f / M_PI;

            // IK angles into servo angles
            this->coxa = t1 * 180.0f / M_PI;

            this->femur = std::clamp(
                std::abs(alpha + beta + 90),
                0.0f,
                180.0f
            );

            this->tibia = std::clamp(
                std::abs(gamma),
                0.0f,
                180.0f
            );

            // Set the calculated angles as the interpolation target
            this->end = {this->coxa, this->femur, this->tibia};

            target_reached = false;

            RCLCPP_INFO(
                this->get_logger(),
                "Coxa, Femur, Tibia: %f, %f, %f",
                this->coxa,
                this->femur,
                this->tibia
            );

            time = 0;
        }