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
