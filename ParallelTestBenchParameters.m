clear
clc
Simulink.sdi.setMarkersOn(false)

%% Side A motor parameters, the motor used for generation, augmentation, and starting

SideA_Rs = 0.0102; % Motor stator resistance [ohms]
SideA_Ldq = 4.31e-06; % Motor dq-axis inductance [H]
SideA_lambda = 0.00388; % Motor permanent magnetic flux [Wb]
SideA_N = 7; % Motor number of pole pairs
SideA_MaxTrq = 5.53; % Motor max torque [Nm]
SideA_Physical_Param = [0.0026 1e-8 0.15]; % Motor inertia,damping, static friction [kgm^2,Nm/rad/s,Nm]
SideA_Ke = 9.75609; % Motor back-emf constant [Vpp/kRPM]
SideA_Kt = 0.04189; % Motor torque constant, Max Torque/Max Current [Nm/A]

%% Dynamometer motor parameters, the motor used for loading

Dyno_Rs = 0.00780; % Motor stator resistance [ohms]
Dyno_Ldq = 0.000254; % Motor dq-axis inductance [H]
Dyno_lambda = 2.690e-05; % Motor permanent magnetic flux [Wb]
Dyno_N = 21; % Motor number of pole pairs
Dyno_MaxTrq = 17.8; % Motor max torque [Nm]
Dyno_Physical_Param = [0.0100 1e-8 0.3]; % Motor inertia,damping, static friction [kgm^2,Nm/rad/s,Nm]
Dyno_Ke = 28.7935; % Motor back-emf constant [Vpp/kRPM]
Dyno_Kt = 0.10409; % Motor torque constant, Max Torque/Max Current [Nm/A]
Dyno_Ratio = 0.44; % Pully ratio Side A divided by Dyno

%% Battery parameters

Batt_Cap = 1; % Battery capacity [Ah]
Batt_Series = 12; % Number of cells in series
Batt_Parr = 6; % Number of cells in parallel


%% Clutch parameters

KinFricTrq = 40; % Nominal torque [Nm]
StatFricTrq = 50; % Static torque [Nm]

D_o = 0.099; % Outter diameter of clutch surface [m]
d_o = 0.076; % Inner diameter of clutch surface [m]
A_eff = (pi/4)*(D_o^2-d_o^2); % Effective area [m^2]
R_eff = (2/6)*((D_o^3-d_o^3)/((D_o^2-d_o^2))); % Effective radius [m]
mew_s = 0.15; % Slip friction coefficient
mew_k = 0.2; % Dynamic friction coefficient

F_clamp = KinFricTrq/(mew_k*R_eff); % Clutch clamp force [N]
P_eng = F_clamp*A_eff; % Clutch clamp pressure [Pa]



%sim('ParallelTestBench');
