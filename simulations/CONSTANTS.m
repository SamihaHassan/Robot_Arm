% Elec 341 - 2019
% This script contains all physical constants and specifications

% Start with a clean slate
% Erase entire Matlab environment
clear all;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Physical & Conversion Constants %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
G   = 9.81;              % (m/s^2)

F2M = 0.3048;            % X(ft)  * F2M = Y(m)
D2R = pi/180;            % X(deg) * D2R = Y(rad)
R2D = 180/pi;            % X(rad) * R2D = Y(deg)
V2W = pi/30;             % X(RPM) * V2W = Y(rad/s)

BIG = 1e6;               % General purpose large number
SML = 1e-6;              % General purpose small number


%%%%%%%%%%%%%%%%%%
% Specifications %
%%%%%%%%%%%%%%%%%%

% Controller
Vmax = 4.5;              % (V)

% Amplifier
R    = 8;                % (ohm)
Rhat = 100;              % (ohm)
L    = 250;              % (mH)
Vss  = 24;               % (V)

% Sensor
N    = 100;              % (number of windows per turn)

% Geometry
Len   = 50;
Zbull = 45;
Zpin  = 15;

% Material Constant
RhoAl   = 2.7;           % Density of 6061 Al (g/cm^3)
RhoFe   = 8.0;           % Density of Fe      (g/cm^3)
RhoDel  = 1.4;           % Density of Delrin  (g/cm^3)
MGrip   = 65;            % Mass of Gripper    (g)


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Indices into MotorParam Vector for Maxon motors %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Values at Nominal Voltage
NomV          = 1;
NoLoadSpd     = 2;
NoLoadCurr    = 3;
NomSpd        = 4;
NomTorque     = 5;
NomCurr       = 6;
StallTorque   = 7;
StallCurr     = 8;
MaxEff        = 9;

% Characteristics
TermR         = 10;
TermL         = 11;
TorqueK       = 12;
SpdK          = 13;
SpdTorqueGrad = 14;
MechTimeK     = 15;
RotJ          = 16;

% Thermal Data
ThermRhous    = 17;
ThermRwind    = 18;
ThermTCwind   = 19;
ThermTCmot    = 20;
AmbTemp       = 21;
MaxTemp       = 22;

% Mechanical Data
MaxSpdBall    = 23;
AxialPlayBall = 24;
RadPlayBall   = 25;
MaxAxLdBall   = 26;
MaxFBall      = 27;
MaxRadLdBall  = 28;

% Other Specifications
NoPolePair    = 29;
NoCommSeg     = 30;   % DC motors
NoPhase       = 30;   % EC motors
Weight        = 31;

% Physical Dimensions
OuterDiam     = 32;
Length        = 33;

% Operational Limit from Operating Range Curve
MaxTorque     = 34;
