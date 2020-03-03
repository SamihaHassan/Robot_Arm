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
CtlFlag = 1;                                    % Controller gains
AmpFlag = 1;                                    % Amplifier model
MotFlag = 1;                                    % Motor model
RobFlag = 0;                                    % Robot model
SenFlag = 1;                                    % Sensor model


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
PID0     = [-0.0502 -0.00115 -0.0105];
CtlSat0  = 4.5;
FB0      = 0.9;
 
% Q1
PID1     = [-0.0502 -0.00115 -0.0105];
CtlSat1  = 4.5;
FB1      = 0.9;

end; % CtlFlag
% ------------------


% ------------------
% Amplifier Dynamics
if AmpFlag

% Q0
Amp0n    = [-3.125 -92];
Amp0d    = [.25 8];
AmpSat0  = 24;

% Q1
Amp1n    = [-3.125 -92];
Amp1d    = [.25 8];
AmpSat1  = 24;

end; % AmpFlag
% ------------------


% ------------------
% Motor Dynamics
if MotFlag

% Q0
Elec0n   = [0 1];
Elec0d   = [.0000873 1.13];
TConst0  = 0.0047;
BackEMF0 = 0.0048;

% Q1
Elec1n   = [0 1];
Elec1d   = [.0000873 1.13];
TConst1  = 0.0047;
BackEMF1 = 0.0048;

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
Sens0 = 1.11111;

% Q1
Sens1 = 1.11111;

end; % SenFlag
% ------------------
