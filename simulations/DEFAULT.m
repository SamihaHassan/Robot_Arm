% Elec 341 - 2019
% This script sets default model parameter values
% All forward paths are set to 1
% All feedback paths are set to 0

% Assign the Set-Point Trajectory & Time Vector
TRAJECTORY

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Values you should over-write in Model.m %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% ==========================
% Motor Parameters
% ==========================
ECX19_30W;                   % Default Maxon motor
Q0 = MotorParam;
Q1 = MotorParam;


% ==========================
% Q0
% ==========================

% Controller Gains
PID0     = [1 0 0];
CtlSat0  = BIG;
FB0      = 0;

% Amplifier Dynamics
Amp0n    = 1;                % Numerator
Amp0d    = 1;                % Denominator
AmpSat0  = BIG;

% Motor Dynamics
Elec0n   = 1;                % Numerator
Elec0d   = 1;                % Denominator

Mech0n   = 1;                % Numerator
Mech0d   = 1;                % Denominator

TConst0  = 1;
BackEMF0 = 0;

% Integrator
Integ0   = 0;                % Unity gain / no integrator

% Sensor Dynamics
Sens0    = 1;


% ==========================
% Q1
% ==========================

% Controller Gains
PID1     = [1 0 0];
CtlSat1  = BIG;
FB1      = 0;

% Amplifier Dynamics
Amp1n    = 1;                % Numerator
Amp1d    = 1;                % Denominator
AmpSat1  = BIG;

% Motor Dynamics
Elec1n   = 1;                % Numerator
Elec1d   = 1;                % Denominator

Mech1n   = 1;                % Numerator
Mech1d   = 1;                % Denominator

TConst1  = 1;
BackEMF1 = 0;

% Integrator
Integ1   = 0;                % Unity gain / no integrator

% Sensor Dynamics
Sens1    = 1;
