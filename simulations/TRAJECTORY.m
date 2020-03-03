% Elece 341 - 2019
% This script sets the trajectory

%%%%%%%%%%%%%%%%%
% Time Interval %
%%%%%%%%%%%%%%%%%

dt = 1e-3;
t1 = 0.2;
T1 = dt:dt:t1;
t2 = 0.17;
T2 = dt:dt:t2;
t3 = 0.13;
T3 = dt:dt:t3;
t4 = 0.1;
T4 = dt:dt:t4;

Time = 0:dt:t1+t2+t3+t4;
SampleTime = dt;

%%%%%%%%%%%%%%%%%%%%%%
% Desired Trajectory %
%%%%%%%%%%%%%%%%%%%%%%

% Constants
r          = 40;          % radius of arc

Xd         = 200;         % start val
Yd         = 0;           % start val

% Compute rest of path
x          = Xd(end) + T1 * -100 / t1;
y          = Yd(end) + T1 *  100 / t1;
Xd         = [Xd x];
Yd         = [Yd y];

th         = [45 270];
theta      = (th(2)-th(1)) * T2 / t2 + th(1);

x          = r * cosd(theta);
y          = r * sind(theta);
x          = Xd(end) + x - x(1);
y          = Yd(end) + y - y(1);
Xd         = [Xd x];
Yd         = [Yd y];

th         = [90 -90];
theta      = (th(2)-th(1)) * T3 / t3 + th(1);

x          = r * cosd(theta);
y          = r * sind(theta);
x          = Xd(end) + x - x(1);
y          = Yd(end) + y - y(1);
Xd         = [Xd x];
Yd         = [Yd y];

x          = Xd(end) * ones(size(T4));
y          = Yd(end) * ones(size(T4));
Xd         = [Xd x];
Yd         = [Yd y];
