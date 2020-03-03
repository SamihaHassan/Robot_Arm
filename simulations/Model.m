% Elec 341 - 2019
% This script sets the model parameters

% Example: Specifying a Dynamics Block
% n = [1 2 3];
% d = [4 5 6];
% Transfer Function = (s^2 + 2s + 3) / (4s^2 + 5s + 6)

% =====
% FLAGS
% =====
% Set to 0 or 1

% Which values to over-write during development
CtlFlag = 0;                                    % Controller gains
AmpFlag = 0;                                    % Amplifier model
MotFlag = 0;                                    % Motor model
RobFlag = 0;                                    % Robot model
SenFlag = 0;                                    % Sensor model


% ========================
% PHYSICAL UNIT CONVERSION
% ========================
% Example: if you decide to work in (Kg), all masses must be represented
%          in (Kg) but the spec sheet may provide masses in (g)

% Electrical

% Mechanical


% ==============
% XFER FUNCTIONS
% ==============

% ------------------
% Controller Gains
if CtlFlag
 
% Q0
PID0     = 0;
CtlSat0  = 0;
FB0      = 0;
 
% Q1
PID1     = 0;
CtlSat1  = 0;
FB1      = 0;

end; % CtlFlag
% ------------------


% ------------------
% Amplifier Dynamics
if AmpFlag

% Q0
Amp0n    = 0;
Amp0d    = 0;
AmpSat0  = 0;

% Q1
Amp1n    = 0;
Amp1d    = 0;
AmpSat1  = 0;

end; % AmpFlag
% ------------------


% ------------------
% Motor Dynamics
if MotFlag

% Q0
Elec0n   = 0;
Elec0d   = 0;
TConst0  = 0;
BackEMF0 = 0;

% Q1
Elec1n   = 0;
Elec1d   = 0;
TConst1  = 0;
BackEMF1 = 0;

end; % MotFlag
% ------------------


% ------------------
% Robot Dynamics
% Linear approximation of robot
if RobFlag

% Q0
Mech0n = 0;
Mech0d = 0;

% Q1
Mech1n = 0;
Mech1d = 0;

end; % RobFlag
% ------------------


% ------------------
% Sensor Dynamics
if SenFlag

% Q0
Sens0 = 0;

% Q1
Sens1 = 0;

end; % SenFlag
% ------------------
