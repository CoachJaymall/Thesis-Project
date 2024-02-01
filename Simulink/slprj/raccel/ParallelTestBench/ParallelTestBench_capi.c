#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ParallelTestBench_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "ParallelTestBench.h"
#include "ParallelTestBench_capi.h"
#include "ParallelTestBench_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"ParallelTestBench/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1
, 0 , TARGET_STRING ( "ParallelTestBench/BLDC/Constant" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Constant1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 3 , 0 , TARGET_STRING ( "ParallelTestBench/BLDC/Constant3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Trq_Or_Spd" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 5 , 0 , TARGET_STRING ( "ParallelTestBench/BLDC/ElecTorque/Ld1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/ElecTorque/Subtract2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_InvP/Constant2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_InvP/Minus120" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_InvP/Plus120" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_P/Constant2" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_P/Minus120" ) , TARGET_STRING ( "" ) , 0 , 0 ,
1 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_P/Plus120" ) , TARGET_STRING ( "" ) , 0 , 0 ,
1 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/MechToElec/Constant" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/MechToElec/Constant1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/Constant3" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/FrictionT1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/Pos0" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/Speed0" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/Viscous" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/Divide" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/Product1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/Trq_Or_Spd" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/Constant" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 24 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Constant" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine/Air Flow/Air Flow Table" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Engine Crank Angle Calculation/RPM to deg//s"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"ParallelTestBench/Three-Phase Sine Generator/Model/Constant" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"ParallelTestBench/Three-Phase Sine Generator/Model/Amplitude1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/D-axis/D_Inducance" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/D-axis/Id_0" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/D-axis/Q_Inducance" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 32 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/D-axis/Divide1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/Q-axis/D_Inducance" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 34 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/Q-axis/Id_0" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/Q-axis/Q_Inducance" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 36 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/Q-axis/Divide1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 38 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant6" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 39 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant7" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 40 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant8" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/AND1" ) , TARGET_STRING ( "" )
, 0 , 1 , 0 , 0 , 1 } , { 42 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Mod" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 44 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Relational Operator7" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 45 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Switch1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 46 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Switch3" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 47 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 48 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant6" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 49 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant7" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 50 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant8" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 51 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/AND1" ) , TARGET_STRING ( "" )
, 0 , 1 , 0 , 0 , 1 } , { 52 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Mod" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 54 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Relational Operator7" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 55 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Switch1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 56 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Switch3" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 57 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 58 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant6" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant7" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 60 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant8" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 61 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/AND1" ) , TARGET_STRING ( "" )
, 0 , 1 , 0 , 0 , 1 } , { 62 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Mod" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 63 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 64 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Relational Operator7" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 65 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Switch1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 66 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Switch3" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 67 , 0 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Afr Calculation/div0protect - poly1/Unary Minus"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 68 , 0 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Afr Calculation/div0protect - poly2/Unary Minus"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 69 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Subsystem/Constant" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 70 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Subsystem/rad->deg" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 71 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery Internal/Datasheet Battery/Charge Model/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 72 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery Internal/Datasheet Battery/Charge Model/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 73 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery Internal/Datasheet Battery/State of Charge Capacity/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 74 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery Internal/Datasheet Battery/Voltage and Power Calculation/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 75 , 0 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EngTrq Table"
) , TARGET_STRING ( "EngTrq" ) , 0 , 0 , 0 , 0 , 0 } , { 76 , 0 ,
TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EoCO2 Table"
) , TARGET_STRING ( "EoCO2" ) , 0 , 0 , 0 , 0 , 0 } , { 77 , 0 ,
TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EoCo Table"
) , TARGET_STRING ( "EoCo" ) , 0 , 0 , 0 , 0 , 0 } , { 78 , 0 , TARGET_STRING
(
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EoHc Table"
) , TARGET_STRING ( "EoHc" ) , 0 , 0 , 0 , 0 , 0 } , { 79 , 0 , TARGET_STRING
(
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EoNOx Table"
) , TARGET_STRING ( "EoNOx" ) , 0 , 0 , 0 , 0 , 0 } , { 80 , 0 ,
TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/FuelMassFlw Table"
) , TARGET_STRING ( "FuelMassFlw" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL
) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 81 , TARGET_STRING ( "ParallelTestBench/BLDC" ) ,
TARGET_STRING ( "MechInput" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING (
"ParallelTestBench/BLDC" ) , TARGET_STRING ( "p" ) , 0 , 0 , 0 } , { 83 ,
TARGET_STRING ( "ParallelTestBench/BLDC" ) , TARGET_STRING ( "Rs" ) , 0 , 0 ,
0 } , { 84 , TARGET_STRING ( "ParallelTestBench/BLDC" ) , TARGET_STRING (
"Ld" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING ( "ParallelTestBench/BLDC" ) ,
TARGET_STRING ( "Lq" ) , 0 , 0 , 0 } , { 86 , TARGET_STRING (
"ParallelTestBench/BLDC" ) , TARGET_STRING ( "Lambda" ) , 0 , 0 , 0 } , { 87
, TARGET_STRING ( "ParallelTestBench/BLDC" ) , TARGET_STRING ( "J" ) , 0 , 0
, 0 } , { 88 , TARGET_STRING ( "ParallelTestBench/BLDC" ) , TARGET_STRING (
"B" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING ( "ParallelTestBench/BLDC" ) ,
TARGET_STRING ( "F" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
"ParallelTestBench/BLDC" ) , TARGET_STRING ( "Id_init" ) , 0 , 0 , 0 } , { 91
, TARGET_STRING ( "ParallelTestBench/BLDC" ) , TARGET_STRING ( "Iq_init" ) ,
0 , 0 , 0 } , { 92 , TARGET_STRING ( "ParallelTestBench/BLDC" ) ,
TARGET_STRING ( "Th_init" ) , 0 , 0 , 0 } , { 93 , TARGET_STRING (
"ParallelTestBench/BLDC" ) , TARGET_STRING ( "Omega_init" ) , 0 , 0 , 0 } , {
94 , TARGET_STRING ( "ParallelTestBench/Datasheet Battery" ) , TARGET_STRING
( "BattChargeMax" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery" ) , TARGET_STRING ( "Em" ) , 0 , 3 , 0
} , { 96 , TARGET_STRING ( "ParallelTestBench/Datasheet Battery" ) ,
TARGET_STRING ( "CapLUTBp" ) , 0 , 3 , 0 } , { 97 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery" ) , TARGET_STRING ( "RInt" ) , 0 , 4 ,
0 } , { 98 , TARGET_STRING ( "ParallelTestBench/Datasheet Battery" ) ,
TARGET_STRING ( "BattTempBp" ) , 0 , 5 , 0 } , { 99 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery" ) , TARGET_STRING ( "CapSOCBp" ) , 0 ,
6 , 0 } , { 100 , TARGET_STRING ( "ParallelTestBench/Datasheet Battery" ) ,
TARGET_STRING ( "Ns" ) , 0 , 0 , 0 } , { 101 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery" ) , TARGET_STRING ( "Np" ) , 0 , 0 , 0
} , { 102 , TARGET_STRING ( "ParallelTestBench/Datasheet Battery" ) ,
TARGET_STRING ( "BattCapInit" ) , 0 , 0 , 0 } , { 103 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine" ) , TARGET_STRING ( "f_tbrake_t_bpt" ) ,
0 , 7 , 0 } , { 104 , TARGET_STRING ( "ParallelTestBench/Mapped CI Engine" )
, TARGET_STRING ( "f_tbrake_n_bpt" ) , 0 , 8 , 0 } , { 105 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine" ) , TARGET_STRING ( "f_tbrake" ) , 0 , 9
, 0 } , { 106 , TARGET_STRING ( "ParallelTestBench/Mapped CI Engine" ) ,
TARGET_STRING ( "f_air" ) , 0 , 9 , 0 } , { 107 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine" ) , TARGET_STRING ( "f_fuel" ) , 0 , 9 ,
0 } , { 108 , TARGET_STRING ( "ParallelTestBench/Mapped CI Engine" ) ,
TARGET_STRING ( "f_hc" ) , 0 , 9 , 0 } , { 109 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine" ) , TARGET_STRING ( "f_co" ) , 0 , 9 , 0
} , { 110 , TARGET_STRING ( "ParallelTestBench/Mapped CI Engine" ) ,
TARGET_STRING ( "f_nox" ) , 0 , 9 , 0 } , { 111 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine" ) , TARGET_STRING ( "f_co2" ) , 0 , 9 ,
0 } , { 112 , TARGET_STRING ( "ParallelTestBench/Constant1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 113 , TARGET_STRING (
"ParallelTestBench/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
114 , TARGET_STRING ( "ParallelTestBench/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
"ParallelTestBench/Constant4" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
116 , TARGET_STRING ( "ParallelTestBench/Signal Generator" ) , TARGET_STRING
( "Amplitude" ) , 0 , 0 , 0 } , { 117 , TARGET_STRING (
"ParallelTestBench/Signal Generator" ) , TARGET_STRING ( "Frequency" ) , 0 ,
0 , 0 } , { 118 , TARGET_STRING ( "ParallelTestBench/BLDC/Trq_Or_Spd" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 119 , TARGET_STRING (
"ParallelTestBench/BLDC/ElecTorque/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 120 , TARGET_STRING ( "ParallelTestBench/BLDC/ElecTorque/Gain3" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 121 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_InvP/Constant2" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 122 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_InvP/Minus120" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 123 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_InvP/Plus120" ) , TARGET_STRING ( "Value" ) ,
0 , 1 , 0 } , { 124 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_InvP/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 125 , TARGET_STRING ( "ParallelTestBench/BLDC/Matrix_P/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 126 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_P/Minus120" ) , TARGET_STRING ( "Value" ) , 0
, 1 , 0 } , { 127 , TARGET_STRING ( "ParallelTestBench/BLDC/Matrix_P/Plus120"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 128 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_P/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 ,
0 } , { 129 , TARGET_STRING ( "ParallelTestBench/BLDC/Matrix_P/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 130 , TARGET_STRING (
"ParallelTestBench/BLDC/Matrix_P/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 131 , TARGET_STRING ( "ParallelTestBench/BLDC/Matrix_P/Gain3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 132 , TARGET_STRING (
"ParallelTestBench/BLDC/MechToElec/Constant" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 133 , TARGET_STRING (
"ParallelTestBench/BLDC/Mechanical Equation/Trq_Or_Spd" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 134 , TARGET_STRING (
"ParallelTestBench/BLDC/Motor Equation/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 135 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Max_Lampda_PM_rate" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 136 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine/Air Flow/Air Flow Table" ) ,
TARGET_STRING ( "maxIndex" ) , 2 , 10 , 0 } , { 137 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Engine Crank Angle Calculation/RPM to deg//s"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 138 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine/Engine Crank Angle Calculation/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 139 ,
TARGET_STRING (
"ParallelTestBench/Mapped CI Engine/Engine Crank Angle Calculation/Integrator"
) , TARGET_STRING ( "WrappedStateUpperValue" ) , 0 , 0 , 0 } , { 140 ,
TARGET_STRING (
"ParallelTestBench/Mapped CI Engine/Engine Crank Angle Calculation/Integrator"
) , TARGET_STRING ( "WrappedStateLowerValue" ) , 0 , 0 , 0 } , { 141 ,
TARGET_STRING ( "ParallelTestBench/Three-Phase Sine Generator/Model/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 11 , 0 } , { 142 , TARGET_STRING (
"ParallelTestBench/Three-Phase Sine Generator/Model/Amplitude1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
"ParallelTestBench/Three-Phase Sine Generator/Model/toRad" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 144 , TARGET_STRING (
"ParallelTestBench/Three-Phase Sine Generator/Model/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 146 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 147 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 149 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 150 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 151 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Bias" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 152 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Bias1" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 153 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Bias2" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 154 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Bias3" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 155 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 156 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant10" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 157 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant11" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 158 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant12" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 159 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 161 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 162 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 163 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant7" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 165 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant8" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Constant9" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 167 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 168 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 169 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-a/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 170 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Bias" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Bias1" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 172 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Bias2" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 173 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Bias3" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 174 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 175 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant10" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 176 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant11" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 177 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant12" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 178 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 179 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 180 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 181 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 182 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 183 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant7" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 184 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant8" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 185 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Constant9" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 186 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 187 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 188 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-b/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 189 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Bias" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 190 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Bias1" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 191 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Bias2" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 192 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Bias3" ) , TARGET_STRING (
"Bias" ) , 0 , 0 , 0 } , { 193 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 194 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant10" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 195 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant11" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 196 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant12" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 197 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 198 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 199 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 200 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 201 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 202 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant7" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 203 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant8" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 204 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Constant9" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 205 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 206 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 207 , TARGET_STRING (
"ParallelTestBench/BLDC/d_Psi_d_Theta/Phase-c/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 208 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Afr Calculation/div0protect - poly1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 209 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine/Afr Calculation/div0protect - poly1/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 210 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Afr Calculation/div0protect - poly2/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 211 , TARGET_STRING (
"ParallelTestBench/Mapped CI Engine/Afr Calculation/div0protect - poly2/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 212 , TARGET_STRING (
"ParallelTestBench/BLDC/MotorInfo/Hall sensor/Subsystem/rad->deg" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 213 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery Internal/Datasheet Battery/Charge Model/Integrator Limited"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 214 ,
TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery Internal/Datasheet Battery/Voltage and Power Calculation/R"
) , TARGET_STRING ( "maxIndex" ) , 2 , 10 , 0 } , { 215 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EngTrq Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 10 , 0 } , { 216 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EoCO2 Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 10 , 0 } , { 217 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EoCo Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 10 , 0 } , { 218 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EoHc Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 10 , 0 } , { 219 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/EoNOx Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 10 , 0 } , { 220 , TARGET_STRING (
 "ParallelTestBench/Mapped CI Engine/Mapped Core Engine/Without Temperature Input and with Trq/Mapped Core Engine/FuelMassFlw Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 10 , 0 } , { 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static
const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . hkoqt4keho , & rtB . p3wvq04dag ,
& rtB . iwc3kjrmco , & rtB . pt45h5hjge , & rtB . gy0z0zpdto , & rtB .
fyb11a0byc , & rtB . kx0hemlyld , & rtB . i3rjdtbo1x , & rtB . eefe1liyby [ 0
] , & rtB . fv0duehogi [ 0 ] , & rtB . fi1fzzmmw5 , & rtB . oqrehzq1rd [ 0 ]
, & rtB . lpydzdrxfc [ 0 ] , & rtB . ojrenqmhg3 , & rtB . oi4vt50rct , & rtB
. hmxy34r3a0 , & rtB . fv5d2sh2lx , & rtB . aijej34sel , & rtB . jhspkh2pnv ,
& rtB . efzov3ezec , & rtB . nveuw3rqtc , & rtB . khomf1duv0 , & rtB .
egogztggip , & rtB . iek4fstubw , & rtB . a0ayb25qmj , & rtB . pdiw5iqass , &
rtB . hkg2tchhax , & rtB . aqf34w05ez [ 0 ] , & rtB . parcfkhsio , & rtB .
pntpgyacqb , & rtB . nfowuituae , & rtB . bjvr10i1xh , & rtB . b2k2rf0t1o , &
rtB . j1gs3wlbyf , & rtB . cfptusc1o2 , & rtB . jwqy5kjnca , & rtB .
lyvzolqnf4 , & rtB . fzpbd0kwko , & rtB . o4pbpbusow , & rtB . djbr2nwlhy , &
rtB . p4snq0ykvj , & rtB . ljru5rp5pg , & rtB . km0bbxs3pg , & rtB .
bvn1smh1wj , & rtB . dqvtfxq5pg , & rtB . gg1iibxtko , & rtB . hj0n4eqkhc , &
rtB . agj32u24vd , & rtB . dzznc5n5ya , & rtB . a2bgnx52ge , & rtB .
dj0lrq0jz3 , & rtB . akfaoup2b2 , & rtB . bhs0z1a4bq , & rtB . fylseu1fes , &
rtB . cmqpjmrsw2 , & rtB . e2kxzmdksw , & rtB . lv12rd3q40 , & rtB .
eyst12stjo , & rtB . em4keqr4uy , & rtB . authoigqah , & rtB . ix4azagznh , &
rtB . pduf40h0yn , & rtB . a2tckjiuqf , & rtB . duszlmyn0l , & rtB .
jfvfvv3giv , & rtB . jc2b3utact , & rtB . oo4kaggwwm , & rtB . ktnbcplp2i , &
rtB . gjnfdmbcjm , & rtB . g52te4dnv1 , & rtB . j5bvpiinqj , & rtB .
hygy1qilge , & rtB . pxpvevgrie , & rtB . fdyvfxa4tp , & rtB . kvdqpvhzmq , &
rtB . jmwba0ymud , & rtB . l1nh51d3ja , & rtB . defj4le0qu , & rtB .
pairspzuzs , & rtB . jujtr2tg5z , & rtB . hapipevwha , & rtP . BLDC_MechInput
, & rtP . BLDC_p , & rtP . BLDC_Rs , & rtP . BLDC_Ld , & rtP . BLDC_Lq , &
rtP . BLDC_Lambda , & rtP . BLDC_J , & rtP . BLDC_B , & rtP . BLDC_F , & rtP
. BLDC_Id_init , & rtP . BLDC_Iq_init , & rtP . BLDC_Th_init , & rtP .
BLDC_Omega_init , & rtP . DatasheetBattery_BattChargeMax , & rtP .
DatasheetBattery_Em [ 0 ] , & rtP . DatasheetBattery_CapLUTBp [ 0 ] , & rtP .
DatasheetBattery_RInt [ 0 ] , & rtP . DatasheetBattery_BattTempBp [ 0 ] , &
rtP . DatasheetBattery_CapSOCBp [ 0 ] , & rtP . DatasheetBattery_Ns , & rtP .
DatasheetBattery_Np , & rtP . DatasheetBattery_BattCapInit , & rtP .
MappedCIEngine_f_tbrake_t_bpt [ 0 ] , & rtP . MappedCIEngine_f_tbrake_n_bpt [
0 ] , & rtP . MappedCIEngine_f_tbrake [ 0 ] , & rtP . MappedCIEngine_f_air [
0 ] , & rtP . MappedCIEngine_f_fuel [ 0 ] , & rtP . MappedCIEngine_f_hc [ 0 ]
, & rtP . MappedCIEngine_f_co [ 0 ] , & rtP . MappedCIEngine_f_nox [ 0 ] , &
rtP . MappedCIEngine_f_co2 [ 0 ] , & rtP . Constant1_Value_dsqxhplhg3 , & rtP
. Constant2_Value_amvyq0ozrf , & rtP . Constant3_Value_clw2lo3chi , & rtP .
Constant4_Value_nmxg2ourug , & rtP . SignalGenerator_Amplitude , & rtP .
SignalGenerator_Frequency , & rtP . Trq_Or_Spd_Threshold_bv5qvwcnkb , & rtP .
Gain1_Gain_kogsiikotf , & rtP . Gain3_Gain , & rtP . Constant2_Value , & rtP
. Minus120_Value [ 0 ] , & rtP . Plus120_Value [ 0 ] , & rtP .
Gain2_Gain_jlslrcmtdv , & rtP . Constant2_Value_ozzuwkqilp , & rtP .
Minus120_Value_micf4v4hxs [ 0 ] , & rtP . Plus120_Value_hunie3hozg [ 0 ] , &
rtP . Gain_Gain_an2ok5irfz , & rtP . Gain1_Gain_ovhavq0wpo , & rtP .
Gain2_Gain_lhlkdqm0ee , & rtP . Gain3_Gain_oeu1akxnfz , & rtP .
Constant_Value , & rtP . Trq_Or_Spd_Threshold , & rtP .
Constant_Value_ijz5z22oj1 , & rtP . Max_Lampda_PM_rate_Gain , & rtP .
AirFlowTable_maxIndex [ 0 ] , & rtP . RPMtodegs_Gain , & rtP .
Integrator_IC_lrmnxeinqj , & rtP . Integrator_WrappedStateUpperValue , & rtP
. Integrator_WrappedStateLowerValue , & rtP . Constant_Value_dpuy0h0ihd [ 0 ]
, & rtP . Amplitude1_Gain , & rtP . toRad_Gain , & rtP . Integrator_IC , &
rtP . Constant_Value_jcoszycr0r , & rtP . Constant1_Value_n213dknlmm , & rtP
. Constant2_Value_ntrun4mqdf , & rtP . Constant3_Value_jfxy4qopdq , & rtP .
Constant4_Value_jg1qmih3ue , & rtP . Constant5_Value_m54jfbbmbh , & rtP .
Bias_Bias , & rtP . Bias1_Bias , & rtP . Bias2_Bias , & rtP . Bias3_Bias , &
rtP . Constant1_Value , & rtP . Constant10_Value , & rtP . Constant11_Value ,
& rtP . Constant12_Value , & rtP . Constant2_Value_je4lnbr020 , & rtP .
Constant3_Value , & rtP . Constant4_Value , & rtP . Constant5_Value , & rtP .
Constant6_Value , & rtP . Constant7_Value , & rtP . Constant8_Value , & rtP .
Constant9_Value , & rtP . Gain_Gain , & rtP . Gain1_Gain , & rtP . Gain2_Gain
, & rtP . Bias_Bias_pvrcayevr1 , & rtP . Bias1_Bias_gcbxjqy1ag , & rtP .
Bias2_Bias_ajzwnv2cpb , & rtP . Bias3_Bias_pumqr42kho , & rtP .
Constant1_Value_kimdzexz1x , & rtP . Constant10_Value_j1wyywihpk , & rtP .
Constant11_Value_nlg4rxjaav , & rtP . Constant12_Value_asogurrks4 , & rtP .
Constant2_Value_k1svmewxmc , & rtP . Constant3_Value_ag4er51bcj , & rtP .
Constant4_Value_j0el1tqerf , & rtP . Constant5_Value_hivcl12fft , & rtP .
Constant6_Value_atr0rui2nv , & rtP . Constant7_Value_hf0hbvewrl , & rtP .
Constant8_Value_g0i1o1mso3 , & rtP . Constant9_Value_ovatguv1cd , & rtP .
Gain_Gain_f4q2bv4ant , & rtP . Gain1_Gain_kc23apyjss , & rtP .
Gain2_Gain_cskldqighc , & rtP . Bias_Bias_kp4pcovegv , & rtP .
Bias1_Bias_bpnnrv2g4v , & rtP . Bias2_Bias_iyf2mr5qig , & rtP .
Bias3_Bias_dlzcduozuu , & rtP . Constant1_Value_atqbaqyuhn , & rtP .
Constant10_Value_gft3qlqgqh , & rtP . Constant11_Value_ei54wtxug1 , & rtP .
Constant12_Value_eihaiasqnb , & rtP . Constant2_Value_pdtwrvtyzr , & rtP .
Constant3_Value_bkypk4xhrd , & rtP . Constant4_Value_bwrt5oukhm , & rtP .
Constant5_Value_abvqtbsmbe , & rtP . Constant6_Value_d2i3udqljx , & rtP .
Constant7_Value_ckjsmfweco , & rtP . Constant8_Value_pnqqtlv3vz , & rtP .
Constant9_Value_b1dkmlfthl , & rtP . Gain_Gain_aj4jewynfg , & rtP .
Gain1_Gain_agqevzoajc , & rtP . Gain2_Gain_dfafj4yf5d , & rtP .
Constant_Value_cu2gsqbnxd , & rtP . Switch1_Threshold , & rtP .
Constant_Value_oboowpiodw , & rtP . Switch1_Threshold_hyh3yfwgbh , & rtP .
raddeg_Gain , & rtP . IntegratorLimited_LowerSat , & rtP . R_maxIndex [ 0 ] ,
& rtP . EngTrqTable_maxIndex [ 0 ] , & rtP . EoCO2Table_maxIndex [ 0 ] , &
rtP . EoCoTable_maxIndex [ 0 ] , & rtP . EoHcTable_maxIndex [ 0 ] , & rtP .
EoNOxTable_maxIndex [ 0 ] , & rtP . FuelMassFlwTable_maxIndex [ 0 ] , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof (
uint32_T ) , ( uint8_T ) SS_UINT32 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 18 , 2 , 0 } , {
rtwCAPI_VECTOR , 20 , 2 , 0 } , { rtwCAPI_VECTOR , 22 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 2 , 2 , 3 , 1 , 1 , 101 , 7 , 6
, 1 , 7 , 1 , 6 , 1 , 20 , 1 , 16 , 20 , 16 , 2 , 1 , 1 , 3 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ]
= { { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
( int8_T ) 1 , ( uint8_T ) 0 } , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 81 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 140 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1731618281U , 510667600U , 3146656349U , 3818291459U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * ParallelTestBench_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void ParallelTestBench_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion (
( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ParallelTestBench_host_InitializeDataMapInfo (
ParallelTestBench_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
