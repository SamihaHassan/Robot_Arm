% This script sets parameter values for the following device:
% Maxon ECX 19mm, 30W
% Program 110147
% Mechanically commutating DC motor
% Sleeve Bearings (for mechanical data)

MotorParam = ...
...             % Nominal Values
[24             % NomV          (V)
 47700          % NoLoadSpd     (rpm)
 205            % NoLoadCurr    (mA)
 43600          % NomSpd        (rpm)
 7.47           % NomTorque     (mNm)
 1.74           % NomCurr       (mA)
 101            % StallTorque   (mNm)
 21.3           % StallCurr     (A)
 82             % MaxEff        (%)
...
...             % Characteristics
 1.13           % TermR         (Ohms)
 0.0873         % TermL         (mH)
 4.75           % TorqueConst   (mNm/A)
 2010           % SpdConst      (rpm/V)
 476            % SpdTorqueGrad (rpm/mNm)
 5.74           % MechTimeConst (ms)
 1.15           % RotJ          (gcm^2)
...
...             % Thermal Data
 16.8           % ThermRhous    (K/W)
 2.77           % ThermRwind    (K/W)
 5.55           % ThermTCwind   (s)
 696            % ThermTCmot    (s)
 40             % AmbTemp       (degC)
 155            % MaxTemp       (degC)
...
...             % Mechanical Data
 50000          % MaxSpd        (rpm)
 0.145          % AxialPlay     (mm)
 0              % RadPlay       (mm)
 4              % MaxAxLd       (N)
 70             % MaxF          (N)
 12             % MaxRadLd      (N)
...
...             % Other Specifications
 1              % NoPolePair    (pure)
 3              % NoPhase       (pure)
 78             % Weight        (g)
...
...             % Physical Dimensions
 19             % OuterDiam     (mm)
 42.5];         % Length        (mm)
