clear
clc
Simulink.sdi.setMarkersOn(false)

%% Side A motor parameters, the motor used for generation, augmentation, and starting

SideA_Rs = 0.0102; % Motor stator resistance [ohms]
SideA_Ldq = 4.31e-06; % Motor dq-axis inductance [H]
SideA_lambda = 0.00388; % Motor permanent magnetic flux [Wb]
SideA_N = 7; % Motor number of pole pairs
SideA_MaxTrq = 5.53; % Motor max torque [Nm]
SideA_RatedTrq = 0.77*SideA_MaxTrq; % Usabel torque [Nm]
SideA_Physical_Param = [0.000398 0.000139 0.15]; % Motor inertia,damping, static friction [kgm^2,Nm/rad/s,Nm]
SideA_Ke = 9.75609; % Motor back-emf constant [Vpp/kRPM]
SideA_Kt = 0.04189; % Motor torque constant, Max Torque/Max Current [Nm/A]
BLDC_Driveline_Param = [0.000838 0.00018]; % Inertia and damping of the A side driveline [kgm^2,Nm/rad/s]

%% Dynamometer motor parameters, the motor used for loading

Dyno_Rs = 0.00780; % Motor stator resistance [ohms]
Dyno_Ldq = 0.000254; % Motor dq-axis inductance [H]
Dyno_lambda = 2.690e-05; % Motor permanent magnetic flux [Wb]
Dyno_N = 21; % Motor number of pole pairs
Dyno_MaxTrq = 17.8; % Motor max torque [Nm]
Dyno_Physical_Param = [0.002611 0.000233 0.3];%[0.002611 0.000233 0.3]; % Motor inertia,damping, static friction [kgm^2,Nm/rad/s,Nm]
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
mew_s = 0.35; % Slip friction coefficient
mew_k = 0.3; % Dynamic friction coefficient
Clutch_Param = [0.00336 0.0017]; %[0.00336 0.0018]; % Clutch rotor inertia and damping [kgm^2,Nm/rad/s]

F_clamp = KinFricTrq/(mew_k*R_eff); % Clutch clamp force [N]
P_eng = F_clamp*A_eff; % Clutch clamp pressure [Pa]

%% ICE parameters

Trq_BP = [0 0.4059 0.6089 0.8118 1.0148 1.2177 1.4207 1.6236 2.0295 2.4355 3.2473 4.0591];
Spd_BP = [0 2000 3000 4000 5000 6000 7500];
ICE_Param = [0.070054 0.001748]; % ICE inertia and damping (includes output shaft&rotor) [kgm^2,Nm/rad/s]

Power_Map = [0 0 0 0 0 0 0;
             0 0.13369 0.028648 0 0 0 0;
             0 0.644578 0.27693 0.217246 0.00191 0.095493 0.127327;
             0 1.360774765 0.961295857 0.429718347 0.488923986 0.33581693 0.183346495;
             0 1.718873387 1.273239546 0.74245781 0.592056389 0.612746532 0.632800054;
             0 2.119943844 1.811183254 1.384648006 1.086709953 1.336901523 1.273239546;
             0 2.282281887 2.02126778 1.783331139 1.510698722 1.54380295	1.577543798;
             0 2.411197391 2.218619909 2.100845251 1.846833962 2.088112856 2.33002837;
             0 2.549662191 2.508281906 2.516239653 2.456079085 2.77725376 3.099065055;
             0 2.606957971 2.619690366 2.764521365 2.857149542 3.191056613 3.524327064;
             0 2.616056564 2.727915728 2.955507297 3.223842531 3.616000311 4.008158091;
             0 2.627408674 2.740648123 2.972218566 3.262039717 3.660563695 4.059087673];
Air_Map = [0 0 0 0 0 0 0
           0 0.004545746 0.006857746 0.009303137 0.011961181 0.014932541 0.019939747;
           0 0.005634935 0.008449428 0.011395464 0.014491899 0.017950192 0.023737042;
           0 0.006725872 0.010046472 0.01350019 0.017111901 0.020994361 0.027555582;
           0 0.007833735 0.011660236 0.015522235 0.019714879 0.024068503 0.03141232;
           0 0.008942253 0.013243161 0.01754199 0.022308569 0.027172356 0.025011704;
           0 0.010039048 0.01476198 0.019629706 0.02489737 0.030303635	0.039318773;
           0 0.01115512 0.016325302 0.021745932 0.027414529 0.03344752	0.0433963;
           0 0.01341073 0.019609982 0.026024148 0.032619212 0.039835915 0.051073899;
           0 0.015732246 0.022349716 0.030180698 0.037961869 0.046402151 0.059219463;
           0 0.020648844 0.031256205 0.039570684 0.049762529 0.060621913 0.077298366;
           0 0.020679117 0.038585327 0.049233255 0.06309286 0.080492254 0.098250702];
Fuel_Map = [0 0	0 0	0 0	0;
            0 0.00003 0.0000348	5.24667E-05	0.000058125	0.00005985 7.88125E-05;
            0 3.95833E-05 0.0000439	6.21333E-05	0.00006625 0.0000789 0.0000985;
            0 0.00005365 0.00006305	6.93333E-05	7.88333E-05	0.00008405	0.000111625;
            0 0.0000713	0.0000746 7.83333E-05 0.0000875	0.000105 0.0001375;
            0 8.64667E-05 0.000095 9.66667E-05 9.79167E-05 0.000115	0.00015;
            0 0.00009265 0.00011 0.000113233 0.000120042 0.00014405	0.0001865;
            0 9.68167E-05 0.000118825 0.000123333 0.0001375	0.000165 0.0002125;
            0 0.000131667 0.000149225 0.000155933 0.000173292 0.00020905 0.000261313;
            0 0.0001499	0.000169525	0.000180733	0.000214583	0.0002417 0.00031875;
            0 0.00015385 0.00017845	0.000199167	0.000247667	0.00029545 0.0004;
            0 0.00015605 0.00019375	0.0002171 0.000266667 0.00032 0.00043125];
Temp_Map = [737.9071 789.7519661 941.1103976 1012.130437 1065.523001 1094.556843 1157.129746;
            737.9071 812.4865085 949.025075	1012.130437	1060.156636	1095.488509	1158.460322;
            755.0822 892.0626242 976.7282622 1001.395583 1041.373129 1098.749556 1163.117644;
            772.0370 919.4245522 980.395393	997.6611549	1041.827726	1102.909552	1149.506316;
            793.4022 929.7577967 979.7656161 985.6128672 1045.531643 1103.167608 1143.791839;
            791.7926 933.3838711 976.0184549 981.7932573 1052.982395 1101.513731 1153.77842;
            791.7926 939.4307966 971.5966258 999.0091151 1064.841175 1100.481796 1152.702886;
            861.7001 955.6011198 990.5874424 1009.915165 1081.806471 1109.278733 1139.666955;
            917.4628 971.0304893 1025.309936 1063.282167 1106.719983 1126.920804 1128.949148;
            917.4628 1029.221258 1040.271769 1086.862286 1129.050561 1136.350312 1163.907879;
            917.4628 1165.241132 1107.78207	1142.946594	1171.457216	1164.387071	1125.311122;
            917.4628 1165.577391 1175.138952 1173.994252 1162.45648	1163.654268	1178.6741];
Eff_Map = [0 0 0 0 0 0 0;
           0 443.7938312 445.6701737 454.9419299 468.8329914 489.3868199 524.1066289;
           0 358.1844448 356.3296814 360.9500503 367.1209444 379.5429522 402.1068056;
           0 322.6621502 320.0702731 323.0872701 327.2331843 335.6654592 352.8068612;
           0 299.1833167 296.4123396 296.4438579 300.8518315 306.663252 320.3809655;
           0 283.4914205 280.0333361 278.1775408 283.1033269 287.4374625 360.549164;
           0 272.2789208 266.8970252 266.2136289 270.2272696 274.0502105 284.2057215;
           0 264.9531117 258.4520673 257.7034112 260.5219847 264.8695255 275.1110567;
           0 254.3800797 248.1798924 247.1578692 247.8171329 252.2664305 258.5069234;
           0 250.6864438 240.6665708 238.6043677 240.2638201 244.9182562 249.8591865;
           0 283.556589 247.4064842 234.8998802 236.5326662 240.1755679 272.2832107;
           0 284.0919202 333.4982084 329.3493581 316.7884871 317.1281818 293.449317];
HC_Map = [0	0 0	0 0	0 0;
          0	1.22597E-05	1.80614E-05	2.24533E-05	3.85962E-05	7.62866E-05	8.73095E-05;
          0	1.18465E-05	1.74367E-05	2.20022E-05	3.89799E-05	7.67361E-05	8.69846E-05;
          0	1.2191E-05	1.77561E-05	2.42813E-05	4.04323E-05	7.71516E-05	8.68985E-05;
          0	1.26578E-05	1.87759E-05	2.65238E-05	4.28719E-05	7.73285E-05	8.68665E-05;
          0	1.30638E-05	2.04097E-05	2.8996E-05	4.5696E-05	7.73925E-05	8.68613E-05;
          0	1.33718E-05	2.25465E-05	3.19887E-05	4.83491E-05	7.74573E-05	8.68613E-05;
          0	1.51481E-05	2.48967E-05	3.58568E-05	5.05866E-05	7.74677E-05	8.68613E-05;
          0	1.97838E-05	3.15347E-05	4.2151E-05	5.73259E-05	7.74702E-05	8.68613E-05;
          0	2.37736E-05	3.77262E-05	5.11776E-05	6.41929E-05	7.74702E-05	8.68613E-05;
          0	3.0941E-05	4.75903E-05	6.16591E-05	7.36289E-05	8.27934E-05	9.17989E-05;
          0	3.19882E-05	7.17692E-05	9.27337E-05	0.000104317	0.000103826	9.81161E-05];
CO_Map = [0	0 0	0 0	0 0;
          0 1.31441E-06 2.55695E-06 5.62972E-06 2.48581E-05 8.67685E-05 0.000137032;
          0 2.01367E-06 3.55992E-06 7.47656E-06 2.76877E-05 8.7865E-05 0.000136897;
          0 2.43489E-06 4.59691E-06 1.14864E-05 2.97959E-05 8.96454E-05 0.000136457;
          0 2.23694E-06 4.78123E-06 1.28518E-05 3.26015E-05 9.07927E-05 0.000136111;
          0 1.98289E-06 4.99819E-06 1.36901E-05 3.63317E-05 9.14812E-05 0.000135922;
          0 2.25984E-06 6.38155E-06 1.57047E-05 4.07645E-05 9.19014E-05 0.000135922;
          0 4.3059E-06 1.38641E-05 7.88882E-06 4.06707E-05 9.20283E-05 0.000135922;
          0 1.19945E-05 2.00075E-05 4.47201E-05 7.75209E-05 9.20653E-05 0.000135922;
          0 1.2313E-05 1.13031E-05 2.73645E-05 5.70004E-05 9.20653E-05 0.000135922;
          0 0.000135607 3.51378E-05 0.000117831 0.000132404 0.000113146 0.000174513;
          0 0.000189518 0.001893632 0.002885569 0.002353859 0.000927089 0.001128579];
NOx_Map = [0 0 0 0 0 0 0;
           0 1.41874E-06 3.43848E-06 7.24607E-06 3.8347E-05 0.000142512 0.000130955;
           0 2.90301E-06 6.96716E-06 1.3059E-05 4.42914E-05 0.000146615 0.000131578;
           0 4.44407E-06 1.17971E-05 1.74036E-05 5.39913E-05 0.000148654 0.000131573;
           0 5.91826E-06 1.66806E-05 1.9343E-05 6.34015E-05 0.00014987	0.000131557;
           0 7.40592E-06 1.93572E-05 2.19987E-05 7.35722E-05 0.000150627 0.000131547;
           0 9.20902E-06 1.8365E-05 2.83792E-05 8.50874E-05 0.000151212 0.000131547;
           0 1.46261E-05 1.9752E-05 4.16779E-05 9.24082E-05 0.00015132	0.000131547;
           0 2.9248E-05 4.28921E-05 7.63483E-05 0.000102449 0.000151345 0.000131547;
           0 3.39031E-05 7.11373E-05 0.0001032	0.000122492	0.000151345	0.00131547;
           0 3.14292E-05 7.07251E-05 0.000102686 0.000129941 0.000148604 0.00012657;
           0 3.19912E-05 1.7984E-05 1.6073E-05 4.13605E-05 0.000107362 7.63859E-05];
CO2_Map = [0 0 0 0 0 0 0;
           0 0.000982246 0.001442087 0.001899515 0.003800682 0.008926087 0.009585291;
           0 0.001223973 0.001781027 0.002333068 0.004228015 0.009184234 0.009563887;
           0 0.001456985 0.002129025 0.002784039 0.004781374 0.009314141 0.009548424;
           0 0.001693744 0.002486449 0.003226653 0.005248467 0.009375679 0.009541133;
           0 0.001934825 0.002838499 0.003664574 0.005663853 0.009399637 0.00953899;
           0 0.00217948 0.0031709 0.004100355 0.006058621 0.009413107 0.009538991;
           0 0.002415129 0.003462264 0.004559884 0.006364203 0.009416867 0.009538991;
           0 0.002897401 0.004146793 0.005226871 0.007109866 0.00941799 0.009538991;
           0 0.003393589 0.005138342 0.006855488 0.008390481 0.00941799 0.009538991;
           0 0.004367095 0.006267293 0.007804581 0.009042325 0.009808133 0.009796513;
           0 0.004555315 0.007099536 0.008062907 0.009208486 0.010680682 0.009718486];
PM_Map = [0	0 0	0 0	0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0;
          0 0 0 0 0 0 0];

%% Fuel Map Efficient Zone
Fuel_MapE = zeros(size(Fuel_Map));
Fuel_MapE(3,2) = Fuel_Map(3,2);
Fuel_MapE(4,3) = Fuel_Map(4,3);
Fuel_MapE(5,3) = Fuel_Map(5,3);
Fuel_MapE(5,4) = Fuel_Map(5,4);
Fuel_MapE(6,4) = Fuel_Map(6,4);
Fuel_MapE(7,4) = Fuel_Map(7,4);
Fuel_MapE(7,5) = Fuel_Map(7,5);
Fuel_MapE(8,5) = Fuel_Map(8,5);
Fuel_MapE(8,6) = Fuel_Map(8,6);
Fuel_MapE(9,6) = Fuel_Map(9,6);
Fuel_MapE(11,7) = Fuel_Map(11,7);
Fuel_MapE(12,7) = Fuel_Map(12,7);

%% Throttle Torque Speed Map
Throttle_BP = [0 10 15 20 25 30 35 40 50 60 80 100];

Trq_Thr_Map = [0 0 0 0 0 0 0;
               0 0.133690152 0.02864789	0 0	0 0;
               0 0.64457752	0.276929601	0.217246498	0.001909859	0.095492966	0.127323955;
               0 1.360774765 0.961295857 0.429718347 0.488923986 0.33581693	0.183346495;
               0 1.718873387 1.273239546 0.74245781	0.592056389	0.612746532	0.632800054;
               0 2.119943844 1.811183254 1.384648006 1.086709953 1.336901523 1.273239546;
               0 2.282281887 2.02126778	1.783331139	1.510698722	1.54380295	1.577543798;
               0 2.411197391 2.218619909 2.100845251 1.846833962 2.088112856 2.33002837;
               0 2.549662191 2.508281906 2.516239653 2.456079085 2.77725376	3.099065055;
               0 2.606957971 2.619690366 2.764521365 2.857149542 3.191056613 3.524327064;
               0 2.626056564 2.727915728 2.955507297 3.223842531 3.616000311 4.008158091;
               0 2.597408674 2.740648123 2.972218566 3.262039717 3.660563695 4.059087673];

Power_Thr_Map = Power_Map(2:12,2:7);