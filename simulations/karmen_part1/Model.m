% Elec 341 - 2019
% Mattias Zurkovic 75106880
% Karmen Wang 54144183

% =====
% FLAGS
% =====
% Set to 0 or 1

% Which values to over-write during development
CtlFlag = 1;                                    % Controller gains
AmpFlag = 1;                                    % Amplifier model
MotFlag = 1;                                    % Motor model
RobFlag = 1;                                    % Robot model
SenFlag = 1;                                    % Sensor model

% ========================================================================
% PHYSICAL UNITS: Everything below is in SI units (kg, Nm, V, A, rad/sec
% ========================================================================
% Electrical
R = 8;                      %ohm
R_prime = 100;              %ohm
L = 0.250;                  %H
Vss = 24;                   %V

% Mechanical
UpperArmMass = 0.004029;    %kg
UpperArmLength = 0.1;       %m

ForeArm1Mass = 0.0020145;   %kg
ForeArm0Mass = 0.00302;     %kg
ForeArm1Length = 0.05;      %m
ForeArm0Length = 0.075;     %m

GripperMass = 0.065;        %kg
GripperRadius = sqrt(UpperArmLength^2 + ForeArm0Length^2);  %m

BullGear_r = 45*0.001/2;    %m
BullGearMass = 0.01781;     %kg

Pinion_r = 0.0075;          %m
PinionMass = 0.001397;      %kg



% ==============
% XFER FUNCTIONS
% ==============

% ------------------
% Controller Gains
if CtlFlag
 
% the following PID gains were computed in the document    
% Since system is linearized, we set CtlSat = 1 to turn it "off"

% Q0
PID0     = [0.0672 0.0120 0.0918];
CtlSat0  = 1;
FB0      = 0.9;
 
% Q1
PID1     = [0.0672 0.0120 0.0918];
CtlSat1  = 1;
FB1      = 0.9;

end; % CtlFlag
% ------------------


% ------------------
% Amplifier Dynamics
% 1. Assume motor is ideal
% 2. Amplifier has negative feedback, Vn = Vp
% 3. Perform MNA on the amplifier in the S domain
% 4. Use algebra to get Vout/Vin
% 5. Normalize the transfer function
% Vout/Vin = -(6.25s+184)/(0.5s+16) = -(12.5s+368)/(s+32)

if AmpFlag
    
% Q0
Amp0n    = [-12.5 -368];
Amp0d    = [1 32];
AmpSat0  = 1;          %making the system linear therefore unity

% Q1
Amp1n    = [-12.5 -368];
Amp1d    = [1 32];
AmpSat1  = 1;

end; % AmpFlag
% ------------------


% ------------------
% Motor Dynamics
% i/V = 1/(Ls+R)
% used simple circuit analysis to get obtain TF

if MotFlag

% Q0
Elec0n   = [1];
Elec0d   = [0.0000873 1.13];
TConst0  = 0.00475; %assume motor is in ideal conditions, so Back emf = Tconst
BackEMF0 = 0.00475;

% Q1
Elec1n   = [1];
Elec1d   = [0.0000873 1.13];
TConst1  = 0.00475;
BackEMF1 = 0.00475;

end; % MotFlag
% ------------------


% ------------------
% Robot Dynamics
% Linear approximation of robot explained in report
% Arms were renamed due to typo in project desctiption, look at diagram
% in report.

%Inertia Calculations (all in kg/m^2)
UpperArm0_J = 1/3*(UpperArmMass)*(UpperArmLength)^2;
UpperArm1_J = UpperArm0_J + (ForeArm1Mass)*(ForeArm1Length)^2;

ForeArm1_J = 1/3*(ForeArm1Mass)*(ForeArm1Length)^2;
ForeArm0_J = 1/3*(ForeArm0Mass)*(ForeArm0Length)^2 + UpperArm0_J*3; 
%3*UpperArm0 cus we dont need 1/3 in the shifted J

Gripper_J = (GripperMass)*(GripperRadius)^2;

BullGear_J = ((BullGearMass)*(BullGear_r)^2)/2; 

PinionGear_J = ((PinionMass)*(Pinion_r)^2)/2; 

%divide by 9 cus gear ratio
%do not include J of Bull gear cus we taking that as the origin
%take in sum of the rod+gripper J's then do gear ratio.. then add J of pinion
Total_J = (UpperArm0_J + UpperArm1_J + ForeArm1_J + ForeArm0_J + Gripper_J)*1/9 + 2*PinionGear_J; 

%read report to see how B was calculated
%Y(s)/U(s) = w/tau = 1/(Js+B)

if RobFlag

% Q0
Mech0n = [1];
Mech0d = [0.00012176 0.0000102];

% Q1
Mech1n = [1];
Mech1d = [0.00012176 0.0000102];

end; % RobFlag
% ------------------


% ------------------
% Sensor Dynamics
% 4 readings*number of windows/360 degrees
% sensor gain = 4*100/360

if SenFlag

% Q0
Sens0 = [1.11111];

% Q1
Sens1 = [1.11111];

end; % SenFlag
% ------------------
