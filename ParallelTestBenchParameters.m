clear
clc
Simulink.sdi.setMarkersOn(false)

%% Side A motor parameters, the motor used for generation, augmentation, and starting

SideA_Rs = 0.0102; % Motor stator resistance [ohms]
SideA_Ldq = 4.31e-06; % Motor dq-axis inductance [H]
SideA_lambda = 0.00388; % Motor permanent magnetic flux [Wb]
SideA_N = 7; % Motor number of pole pairs
SideA_MaxTrq = 5.53; % Motor max torque [Nm]
SideA_Physical_Param = [0.0100 1e-8 0]; % Motor inertia,damping, static friction [kgm^2,Nm/rad/s,Nm]
SideA_Ke = 9.75609; % Motor back-emf constant [Vpk-LL/kRPM]
SideA_Kt = 0.04189; % Motor torque constant [Nm/A]

%% Dynamometer motor parameters, the motor used for loading

Dyno_Rs = 0.00780; % Motor stator resistance [ohms]
Dyno_Ldq = 0.000254; % Motor dq-axis inductance [H]
Dyno_lambda = 2.690e-05; % Motor permanent magnetic flux [Wb]
Dyno_N = 21; % Motor number of pole pairs
Dyno_MaxTrq = 17.8; % Motor max torque [Nm]
Dyno_Physical_Param = [0.0100 0 0]; % Motor inertia,damping, static friction [kgm^2,Nm/rad/s,Nm]
Dyno_Ke = 28.7935; % Motor back-emf constant [Vpk/kRPM]
Dyno_Kt = 0.10409; % Motor torque constant [Nm/A]

%% Battery parameters

Batt_Cap = 1; % Battery capacity [Ah]
Batt_Series = 12; % Number of cells in series
Batt_Parr = 6; % Number of cells in parallel


%% Clutch parameters

N_disc = 1; % Number of discs
P_c = 2615336.33; % Applied clutch pressure [Pa]?
P_eng = 2615336.33; % Clutch engagement pressure [Pa]
A_eff = 0.000790307; % Effective area [m^2]
R_eff = 0.044001905; % Effective radius [m]
mew_s = 0.55; % Static friction coefficient
mew_k = 0.5; % Dynamic friction coefficient
omega_i = 733; % Input speed [rad/s]
omega_o = 500; % Output speed [rad/s]
alpha_i = 0.5;
T_i = 2.5; % Input torque [Nm]
J_i = 0.000398; % Input shaft inertia [kgm^2]
J_o = 0.000556; % Output shaft inertia [kgm^2]
b_i = 0.001; % Input shaft damping [Nms/rad]
b_o = 0.001; % Output shaft damping [Nms/rad]

KinFricTrq = 40; % Clutch torque capacity in motion [Nm]
KinFricTrq = 50; % Clutch torque capacity stationary [Nm]

%UNLOCKED
P_c = max(P_c-P_eng,0); % Clutch pressure determination
T_k = N_disc*P_c*A_eff*mew_k*tanh(4*(omega_i-omega_o)); % Kinetic frictional torque [Nm]

%LOCKED
omega_o = omega_i; 
T_s = N_disc*P_c*A_eff*R_eff*mew_s; % Static frictional torque [Nm]
T_o = alpha_i*(J_o+J_i)+omega_i*(b_i+b_o) + T_i; % Net output torque [Nm]


%sim('ParallelTestBench');
