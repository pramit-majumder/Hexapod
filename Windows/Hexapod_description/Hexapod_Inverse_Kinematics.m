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


// void solver(const hexapod_interfaces::msg::Coordinates::SharedPtr msg){

        //     // Save the current joint angles as the interpolation starting point
        //     this->start = {this->coxa, this->femur, this->tibia};

        //     double a = this->femur_l;
        //     double b = this->tibia_l;

        //     // Distance from the femur joint to the target foot position
        //     double c = hypot(msg->z - 0, msg->y);

        //     // Calculate the angles required for the leg geometry
        //     float alpha = atan2(-msg->z, msg->y) * 180.0f / M_PI;

        //     float delta = (
        //         msg->x == 0
        //         ? 0.0f
        //         : (atan2(msg->x, msg->y + this->coxa_l) * 180.0f / M_PI)
        //     );

        //     float beta = (
        //         acos(
        //             ((a * a) + (c * c) - (b * b)) /
        //             (2 * a * c)
        //         )
        //     ) * 180.0f / M_PI;

        //     // Prevent invalid values when the target is unreachable
        //     if (std::isnan(beta)) {
        //         beta = 90.0f;
        //     }

        //     float gamma = (
        //         acos(
        //             ((a * a) + (b * b) - (c * c)) /
        //             (2 * a * b)
        //         )
        //     ) * 180.0f / M_PI;

        //     if (std::isnan(gamma)) {
        //         gamma = 90.0f;
        //     }
            

        //     // IK angles into servo angles
        //     this->coxa = 90 - delta;

        //     this->femur = std::clamp(
        //         std::abs(alpha + beta + 90),
        //         0.0f,
        //         180.0f
        //     );

        //     this->tibia = std::clamp(
        //         std::abs(gamma),
        //         0.0f,
        //         180.0f
        //     );

        //     // Set the calculated angles as the interpolation target
        //     this->end = {this->coxa, this->femur, this->tibia};

        //     target_reached = false;

        //     RCLCPP_INFO(
        //         this->get_logger(),
        //         "Started Interpolating at %d samples and at %d Time",
        //         this->sampling,
        //         this->milliss
        //     );

        //     RCLCPP_INFO(
        //         this->get_logger(),
        //         "Coxa, Femur, Tibia: %f, %f, %f",
        //         this->coxa,
        //         this->femur,
        //         this->tibia
        //     );

        //     time = 0;
        // }