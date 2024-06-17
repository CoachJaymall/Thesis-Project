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
"ParallelTestBench/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1
, 0 , TARGET_STRING ( "ParallelTestBench/Gain1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"ParallelTestBench/kg//s to g//min" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 3 , 0 , TARGET_STRING ( "ParallelTestBench/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"ParallelTestBench/DA50 Power Map" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 5 , 0 , TARGET_STRING ( "ParallelTestBench/DA50 Torque Map" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"ParallelTestBench/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7
, 0 , TARGET_STRING ( "ParallelTestBench/Manual Switch" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"ParallelTestBench/Manual Switch2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 9 , 0 , TARGET_STRING ( "ParallelTestBench/Manual Switch3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"ParallelTestBench/Angular Velocity Conversion/Unit Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"ParallelTestBench/Angular Velocity Conversion1/Unit Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"ParallelTestBench/Angular Velocity Conversion2/Unit Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"ParallelTestBench/Angular Velocity Conversion3/Unit Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"ParallelTestBench/Angular Velocity Conversion4/Unit Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC Speed/fromWS_Signal 1" ) , TARGET_STRING ( "Signal" )
, 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Disengaged" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Disengaged" ) , TARGET_STRING ( "" ) , 1 , 0
, 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Disengaged" ) , TARGET_STRING ( "" ) , 2 , 0
, 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Disengaged" ) , TARGET_STRING ( "" ) , 3 , 0
, 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Engaged, Rated Torque" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Engaged, Rated Torque" ) , TARGET_STRING (
"" ) , 1 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Engaged, Rated Torque" ) , TARGET_STRING (
"" ) , 2 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Engaged, Rated Torque" ) , TARGET_STRING (
"" ) , 3 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Merge" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 25 , 0 , TARGET_STRING ( "ParallelTestBench/Clutch/Merge1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Merge2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 27 , 0 , TARGET_STRING ( "ParallelTestBench/Clutch/Merge3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
"ParallelTestBench/Ice Speed/fromWS_Signal 1" ) , TARGET_STRING ( "Signal" )
, 0 , 0 , 0 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Disengaged" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Disengaged" ) , TARGET_STRING ( "" ) , 1
, 0 , 0 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged" ) , TARGET_STRING ( "" ) , 1 , 0
, 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"ParallelTestBench/Subsystem/Merge" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 34 , 0 , TARGET_STRING ( "ParallelTestBench/Subsystem/Merge1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"ParallelTestBench/TMotorU15/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 36 , 0 , TARGET_STRING ( "ParallelTestBench/TMotorU15/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
"ParallelTestBench/TMotorU15/Gain2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 38 , 0 , TARGET_STRING ( "ParallelTestBench/TMotorU15/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/Merge" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning" ) , TARGET_STRING ( "" )
, 1 , 0 , 0 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning" ) , TARGET_STRING ( ""
) , 1 , 0 , 0 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/System Stationary" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 47 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/System Stationary" ) , TARGET_STRING (
"" ) , 1 , 0 , 0 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Merge" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 49 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Merge1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 50 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Disengaged/PlateSpd" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Disengaged/RotorSpd" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 52 , 2 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/MinMax" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Add" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"ParallelTestBench/Corvid-50/Engine Crank Angle Calculation/RPM to deg//s" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 55 , 0 , TARGET_STRING (
"ParallelTestBench/Corvid-50/Mapped Engine Power Info/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 56 , 0 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery/Output Filter/Gain1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 57 , 0 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery/Output Filter/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 58 , 0 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery/Output Filter/Product" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery/Output Filter/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 60 , 0 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Disengaged/BLDC Spd Cmd" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 61 , 0 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Disengaged/ICE Spd Cmd" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 62 , 6 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Faster BLDC" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 63 , 6 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Faster BLDC" ) , TARGET_STRING (
"" ) , 1 , 0 , 0 , 0 , 0 } , { 64 , 6 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Faster ICE" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 65 , 6 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Faster ICE" ) , TARGET_STRING (
"" ) , 1 , 0 , 0 , 0 , 0 } , { 66 , 6 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Merge" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 67 , 6 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Merge1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 68 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 69 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 70 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 71 , 0 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 72 , 22 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 73 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 74 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/No Dyno Load" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 75 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Merge1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 76 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only BLDC" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 77 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only BLDC" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 78 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 79 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 80 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Merge1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 81 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Merge2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 82 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration/EVAL_KEY/INPUT_1_1_1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 83 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration/EVAL_KEY/OUTPUT_1_0"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 84 , 0 , TARGET_STRING (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration/EVAL_KEY/STATE_1"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 85 , 0 , TARGET_STRING (
"ParallelTestBench/ICE Side Inertias/Solver Configuration/EVAL_KEY/INPUT_1_1_1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 86 , 0 , TARGET_STRING (
"ParallelTestBench/ICE Side Inertias/Solver Configuration/EVAL_KEY/OUTPUT_1_0"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 87 , 0 , TARGET_STRING (
"ParallelTestBench/ICE Side Inertias/Solver Configuration/EVAL_KEY/STATE_1" )
, TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 88 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Vector Concatenate"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 89 , 4 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Faster BLDC/BLDC Spd Cmd" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 90 , 5 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Faster ICE/ICE Spd Cmd" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 91 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 92 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 93 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 94 , 14 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/State Filter"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 2 } , { 95 , 0 , TARGET_STRING (
"ParallelTestBench/TMotorU15/Solver Configuration/EVAL_KEY/INPUT_1_1_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 96 , 0 , TARGET_STRING (
"ParallelTestBench/TMotorU15/Solver Configuration/EVAL_KEY/OUTPUT_1_0" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 97 , 0 , TARGET_STRING (
"ParallelTestBench/TMotorU15/Solver Configuration/EVAL_KEY/STATE_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 98 , 22 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/High Torque"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 99 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/High Torque"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 100 , 22 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Low Torque" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 101 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Low Torque" )
, TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 102 , 22 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Merge" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 103 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Merge1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 104 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/No Dyno Load/MinMax" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 105 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only BLDC/Min" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 106 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/High Torque" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 107 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Low Torque" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 108 , 0 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Merge1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 109 , 2 , TARGET_STRING (
 "ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Solver Configuration/EVAL_KEY/INPUT_1_1_1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 110 , 2 , TARGET_STRING (
 "ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Solver Configuration/EVAL_KEY/LTI_OUTPUT_1_1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 111 , 2 , TARGET_STRING (
 "ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Solver Configuration/EVAL_KEY/LTI_OUTPUT_1_2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 112 , 2 , TARGET_STRING (
 "ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Solver Configuration/EVAL_KEY/LTI_STATE_1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 113 , 0 , TARGET_STRING (
 "ParallelTestBench/Corvid-50/Mapped Core Engine/Without Temperature Input/Mapped Core Engine/EngTrq Table"
) , TARGET_STRING ( "EngTrq" ) , 0 , 0 , 0 , 0 , 0 } , { 114 , 0 ,
TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Charge Model/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 115 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Charge Model/Integrator Limited"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 116 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Charge Model/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 117 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/State of Charge Capacity/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 118 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Voltage and Power Calculation/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 119 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Voltage and Power Calculation/Gain2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 120 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Voltage and Power Calculation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 121 , 0 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Voltage and Power Calculation/Subtract"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 122 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 123 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Gain4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 124 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Gain5"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 125 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Int"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 126 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Int1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 127 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 128 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Index Vector1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 129 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Index Vector2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 130 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 131 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Divide1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 132 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Divide2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 133 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 134 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Motor Units1/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 135 , 13 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Motion control/Discrete-Time Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 136 , 13 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Motion control/Discrete-Time Integrator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 137 , 14 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/State Filter/Gain7"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 138 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 139 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Add2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 140 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Sum of Elements"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 141 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Sum of Elements1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 142 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 143 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 144 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Switch3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 145 , 20 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/High Torque/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 146 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/High Torque/Add2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 147 , 0 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Low Torque/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 148 , 22 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Low Torque/Switch4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 149 , 29 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Divide"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 150 , 29 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Sum of Elements"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 151 , 29 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Sum of Elements1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 152 , 29 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 153 , 29 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 154 , 29 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Switch3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 155 , 0 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/High Torque/1-D Lookup Table2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 156 , 0 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Low Torque/ICE Trq"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 157 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Clarke Transform/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 158 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Clarke Transform/Add1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 159 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Inverse Clarke Transform/Subtract1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 160 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Inverse Park Transform/Add1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 161 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 162 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Gain2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 163 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 164 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 165 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Park Transform/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 166 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Park Transform/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 167 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Park Transform/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 168 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Park Transform/Product3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 169 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Park Transform/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 170 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Park Transform/Add1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 171 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 172 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 173 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/Merge1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 174 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Inverse Clarke Transform/Subtract1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 175 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Inverse Clarke Transform/Subtract2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 176 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Inverse Park Transform/Add1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 177 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Subsystem/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 178 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Subsystem/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 179 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 180 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 181 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 182 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 183 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 184 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 185 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 186 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 187 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/Base Speed/MinMax"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 188 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/Base Speed1/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 189 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem/iq_tmp"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 190 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/FW Torque Higher"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 191 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/FW Torque Lower"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 192 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/Merge4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 193 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 194 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator1/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 195 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 196 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 197 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 198 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Index Vector2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 199 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 200 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 201 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 202 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 203 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 204 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 205 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Index Vector1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 206 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 207 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 208 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 209 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3/Index Vector"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 210 , 0 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 211 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/FW Torque Higher/iq"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 212 , 12 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/FW Torque Lower/iq"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 213 , 11 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/Salient Machine/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 214 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery" ) , TARGET_STRING ( "Em" ) , 0 , 6 , 0
} , { 215 , TARGET_STRING ( "ParallelTestBench/Datasheet Battery" ) ,
TARGET_STRING ( "CapLUTBp" ) , 0 , 6 , 0 } , { 216 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery" ) , TARGET_STRING ( "RInt" ) , 0 , 7 ,
0 } , { 217 , TARGET_STRING ( "ParallelTestBench/Datasheet Battery" ) ,
TARGET_STRING ( "BattTempBp" ) , 0 , 8 , 0 } , { 218 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery" ) , TARGET_STRING ( "CapSOCBp" ) , 0 ,
9 , 0 } , { 219 , TARGET_STRING ( "ParallelTestBench/Datasheet Battery" ) ,
TARGET_STRING ( "Tc" ) , 0 , 0 , 0 } , { 220 , TARGET_STRING (
"ParallelTestBench/Datasheet Battery" ) , TARGET_STRING ( "Vinit" ) , 0 , 0 ,
0 } , { 221 , TARGET_STRING ( "ParallelTestBench/SKP 6485" ) , TARGET_STRING
( "idq0" ) , 0 , 10 , 0 } , { 222 , TARGET_STRING (
"ParallelTestBench/SKP 6485" ) , TARGET_STRING ( "theta_init" ) , 0 , 0 , 0 }
, { 223 , TARGET_STRING ( "ParallelTestBench/SKP 6485" ) , TARGET_STRING (
"omega_init" ) , 0 , 0 , 0 } , { 224 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING (
"idq_limits" ) , 0 , 0 , 0 } , { 225 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Kp_d" )
, 0 , 0 , 0 } , { 226 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Kp_q" )
, 0 , 0 , 0 } , { 227 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Ki" ) ,
0 , 0 , 0 } , { 228 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "ba" ) ,
0 , 0 , 0 } , { 229 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Ksa" )
, 0 , 0 , 0 } , { 230 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Kisa" )
, 0 , 0 , 0 } , { 231 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Ksf" )
, 0 , 0 , 0 } , { 232 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Jcomp"
) , 0 , 0 , 0 } , { 233 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Fv" ) ,
0 , 0 , 0 } , { 234 , TARGET_STRING (
"ParallelTestBench/Surface Mount PM Controller1" ) , TARGET_STRING ( "Fs" ) ,
0 , 0 , 0 } , { 235 , TARGET_STRING ( "ParallelTestBench/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 236 , TARGET_STRING (
"ParallelTestBench/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
237 , TARGET_STRING ( "ParallelTestBench/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 238 , TARGET_STRING (
"ParallelTestBench/Constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
239 , TARGET_STRING ( "ParallelTestBench/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 240 , TARGET_STRING ( "ParallelTestBench/Gain1" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 241 , TARGET_STRING (
"ParallelTestBench/kg//s to g//min" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 242 , TARGET_STRING ( "ParallelTestBench/Integrator" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 243 , TARGET_STRING (
"ParallelTestBench/DA50 Power Map" ) , TARGET_STRING ( "Table" ) , 0 , 11 , 0
} , { 244 , TARGET_STRING ( "ParallelTestBench/DA50 Power Map" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 12 , 0 } , { 245 ,
TARGET_STRING ( "ParallelTestBench/DA50 Power Map" ) , TARGET_STRING (
"BreakpointsForDimension2" ) , 0 , 13 , 0 } , { 246 , TARGET_STRING (
"ParallelTestBench/DA50 Power Map" ) , TARGET_STRING ( "maxIndex" ) , 2 , 2 ,
0 } , { 247 , TARGET_STRING ( "ParallelTestBench/DA50 Torque Map" ) ,
TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 248 , TARGET_STRING (
"ParallelTestBench/DA50 Torque Map" ) , TARGET_STRING (
"BreakpointsForDimension1" ) , 0 , 12 , 0 } , { 249 , TARGET_STRING (
"ParallelTestBench/DA50 Torque Map" ) , TARGET_STRING (
"BreakpointsForDimension2" ) , 0 , 13 , 0 } , { 250 , TARGET_STRING (
"ParallelTestBench/DA50 Torque Map" ) , TARGET_STRING ( "maxIndex" ) , 2 , 2
, 0 } , { 251 , TARGET_STRING ( "ParallelTestBench/Step" ) , TARGET_STRING (
"Time" ) , 0 , 0 , 0 } , { 252 , TARGET_STRING ( "ParallelTestBench/Step" ) ,
TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 253 , TARGET_STRING (
"ParallelTestBench/Step" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 254
, TARGET_STRING ( "ParallelTestBench/Manual Switch" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 255 , TARGET_STRING (
"ParallelTestBench/Manual Switch1" ) , TARGET_STRING ( "CurrentSetting" ) , 1
, 0 , 0 } , { 256 , TARGET_STRING ( "ParallelTestBench/Manual Switch2" ) ,
TARGET_STRING ( "CurrentSetting" ) , 1 , 0 , 0 } , { 257 , TARGET_STRING (
"ParallelTestBench/Manual Switch3" ) , TARGET_STRING ( "CurrentSetting" ) , 1
, 0 , 0 } , { 258 , TARGET_STRING (
"ParallelTestBench/BLDC Speed/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" )
, 0 , 5 , 0 } , { 259 , TARGET_STRING (
"ParallelTestBench/BLDC Speed/fromWS_Signal 1" ) , TARGET_STRING ( "Data0" )
, 0 , 5 , 0 } , { 260 , TARGET_STRING ( "ParallelTestBench/Clutch/Merge" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 261 , TARGET_STRING (
"ParallelTestBench/Clutch/Merge1" ) , TARGET_STRING ( "InitialOutput" ) , 0 ,
0 , 0 } , { 262 , TARGET_STRING ( "ParallelTestBench/Clutch/Merge2" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 263 , TARGET_STRING (
"ParallelTestBench/Clutch/Merge3" ) , TARGET_STRING ( "InitialOutput" ) , 0 ,
0 , 0 } , { 264 , TARGET_STRING (
"ParallelTestBench/Ice Speed/fromWS_Signal 1" ) , TARGET_STRING ( "Time0" ) ,
0 , 14 , 0 } , { 265 , TARGET_STRING (
"ParallelTestBench/Ice Speed/fromWS_Signal 1" ) , TARGET_STRING ( "Data0" ) ,
0 , 14 , 0 } , { 266 , TARGET_STRING (
"ParallelTestBench/Signal Editor2/fromWS_Signal 1" ) , TARGET_STRING (
"Time0" ) , 0 , 15 , 0 } , { 267 , TARGET_STRING (
"ParallelTestBench/Signal Editor2/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 15 , 0 } , { 268 , TARGET_STRING (
"ParallelTestBench/Signal Editor3/fromWS_Signal 1" ) , TARGET_STRING (
"Time0" ) , 0 , 16 , 0 } , { 269 , TARGET_STRING (
"ParallelTestBench/Signal Editor3/fromWS_Signal 1" ) , TARGET_STRING (
"Data0" ) , 0 , 16 , 0 } , { 270 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Disengaged/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 271 , TARGET_STRING (
"ParallelTestBench/Clutch/Clutch Disengaged/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 272 , TARGET_STRING (
"ParallelTestBench/Corvid-50/Engine Crank Angle Calculation/RPM to deg//s" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 273 , TARGET_STRING (
"ParallelTestBench/Corvid-50/Engine Crank Angle Calculation/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 274 , TARGET_STRING (
"ParallelTestBench/Corvid-50/Engine Crank Angle Calculation/Integrator" ) ,
TARGET_STRING ( "WrappedStateUpperValue" ) , 0 , 0 , 0 } , { 275 ,
TARGET_STRING (
"ParallelTestBench/Corvid-50/Engine Crank Angle Calculation/Integrator" ) ,
TARGET_STRING ( "WrappedStateLowerValue" ) , 0 , 0 , 0 } , { 276 ,
TARGET_STRING (
"ParallelTestBench/Corvid-50/Mapped Engine Power Info/rpm to rad//s" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 277 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Merge" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 278 , TARGET_STRING (
"ParallelTestBench/Subsystem/Clutch Engaged/Merge1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 279 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 280 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem/1-D Lookup Table" )
, TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 12 , 0 } , { 281 ,
TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem/1-D Lookup Table" )
, TARGET_STRING ( "BreakpointsForDimension2" ) , 0 , 9 , 0 } , { 282 ,
TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem/1-D Lookup Table" )
, TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 283 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem/1-D Lookup Table1" )
, TARGET_STRING ( "Table" ) , 0 , 12 , 0 } , { 284 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem/Switch" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 285 , TARGET_STRING (
"ParallelTestBench/Throttle Selector/If Action Subsystem1/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 286 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/System Stationary/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 287 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Merge" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 288 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/No Dyno Load/1-D Lookup Table2"
) , TARGET_STRING ( "Table" ) , 0 , 17 , 0 } , { 289 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/No Dyno Load/1-D Lookup Table2"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 18 , 0 } , { 290 ,
TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/No Dyno Load/1-D Lookup Table2"
) , TARGET_STRING ( "BreakpointsForDimension2" ) , 0 , 9 , 0 } , { 291 ,
TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/No Dyno Load/1-D Lookup Table2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 292 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only BLDC/Constant1" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 293 , TARGET_STRING (
"ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 294 , TARGET_STRING (
 "ParallelTestBench/Corvid-50/Mapped Core Engine/Without Temperature Input/Mapped Core Engine/EngTrq Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 295 , TARGET_STRING (
 "ParallelTestBench/Corvid-50/Mapped Core Engine/Without Temperature Input/Mapped Core Engine/FuelMassFlw Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 296 , TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Charge Model/Integrator Limited"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 297 ,
TARGET_STRING (
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Voltage and Power Calculation/R"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 298 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 299 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 300 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 301 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Gain5"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 302 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Int"
) , TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 303 ,
TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Int"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 304 ,
TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Int1"
) , TARGET_STRING ( "WrappedStateUpperValue" ) , 0 , 0 , 0 } , { 305 ,
TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Int1"
) , TARGET_STRING ( "WrappedStateLowerValue" ) , 0 , 0 , 0 } , { 306 ,
TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Motion control/Discrete-Time Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 307 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Motion control/Discrete-Time Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 308 ,
TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Motion control/Discrete-Time Integrator1"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 309 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Motion control/Discrete-Time Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 310 ,
TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/State Filter/Discrete-Time Integrator"
) , TARGET_STRING ( "gainval" ) , 0 , 0 , 0 } , { 311 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/State Filter/Discrete-Time Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 312 ,
TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 313 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 314 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 315 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 316 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/1-D Lookup Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 317 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/1-D Lookup Table2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 318 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 319 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 320 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Fuel Efficient/Switch3"
) , TARGET_STRING ( "Threshold" ) , 1 , 0 , 0 } , { 321 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/High Torque/1-D Lookup Table2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 322 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Low Torque/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 323 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Low Torque/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 324 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Both Spinning/Dyno Loaded/Low Torque/Switch4"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 325 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 326 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 327 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 328 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 329 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/1-D Lookup Table"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 330 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/1-D Lookup Table2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 331 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 332 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 333 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/Fuel Efficient/Switch3"
) , TARGET_STRING ( "Threshold" ) , 1 , 0 , 0 } , { 334 , TARGET_STRING (
 "ParallelTestBench/Torque Split Logic/Either Spinning/Only ICE/High Torque/1-D Lookup Table2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 2 , 0 } , { 335 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Clarke Transform/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 336 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Clarke Transform/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 337 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Clarke Transform/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 338 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Clarke Transform/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 339 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Clarke Transform/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 340 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Inverse Clarke Transform/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 341 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Inverse Clarke Transform/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 342 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Inverse Clarke Transform/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 343 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Inverse Clarke Transform/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 344 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Clarke Transform/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 345 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Clarke Transform/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 346 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Clarke Transform/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 347 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Clarke Transform/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 348 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Clarke Transform/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 349 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Clarke Transform/Gain5"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 350 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 351 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 352 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/Merge1"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 353 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Proportional_Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 354 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Proportional_Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 355 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Inverse Clarke Transform/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 356 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Inverse Clarke Transform/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 357 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Inverse Clarke Transform/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 358 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Inverse Clarke Transform/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 359 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Subsystem/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 360 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Subsystem/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 361 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/Machine Torque/Subsystem/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 362 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 363 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Integrator"
) , TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 364 ,
TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Integrator"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 365 ,
TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 366 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Integrator"
) , TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 367 ,
TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Integrator"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 368 ,
TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/Base Speed/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 369 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/Base Speed/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 370 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 371 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator/Saturation"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 372 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator/Saturation"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 373 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator/Unit Delay"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 374 ,
TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator1/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 375 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator1/Saturation"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 376 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator1/Saturation"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 377 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator1/Unit Delay"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 378 ,
TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 379 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 380 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 381 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 382 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 383 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 384 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 385 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 386 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 387 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 388 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 389 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 390 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 391 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 392 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 393 , TARGET_STRING (
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 394 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/Salient Machine/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 395 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/Salient Machine/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 396 , TARGET_STRING (
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/Current_Generation/If Action Subsystem1/Salient Machine/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 397 , TARGET_STRING (
"Batt_Cap" ) , 0 , 0 , 0 } , { 398 , TARGET_STRING ( "Batt_Parr" ) , 0 , 0 ,
0 } , { 399 , TARGET_STRING ( "Batt_Series" ) , 0 , 0 , 0 } , { 400 ,
TARGET_STRING ( "Dyno_Ke" ) , 0 , 0 , 0 } , { 401 , TARGET_STRING ( "Dyno_Kt"
) , 0 , 0 , 0 } , { 402 , TARGET_STRING ( "Dyno_Ratio" ) , 0 , 0 , 0 } , {
403 , TARGET_STRING ( "Fuel_Map" ) , 0 , 19 , 0 } , { 404 , TARGET_STRING (
"Fuel_MapE" ) , 0 , 19 , 0 } , { 405 , TARGET_STRING ( "Power_Map" ) , 0 , 19
, 0 } , { 406 , TARGET_STRING ( "Power_Thr_Map" ) , 0 , 11 , 0 } , { 407 ,
TARGET_STRING ( "SideA_N" ) , 0 , 0 , 0 } , { 408 , TARGET_STRING (
"SideA_Physical_Param" ) , 0 , 20 , 0 } , { 409 , TARGET_STRING (
"SideA_RatedTrq" ) , 0 , 0 , 0 } , { 410 , TARGET_STRING ( "SideA_Rs" ) , 0 ,
0 , 0 } , { 411 , TARGET_STRING ( "SideA_lambda" ) , 0 , 0 , 0 } , { 412 ,
TARGET_STRING ( "Spd_BP" ) , 0 , 8 , 0 } , { 413 , TARGET_STRING ( "Trq_BP" )
, 0 , 21 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ck20ozhunb , & rtB . a5w4q3xmqj ,
& rtB . kgbpab1bft , & rtB . csh2m1cgxy , & rtB . nt4pl2mpy0 , & rtB .
ka3c0rpnqg , & rtB . cftqthzuab , & rtB . gmqd0r1s5n , & rtB . ivfnl2doo0 , &
rtB . ix0ijjsadq , & rtB . c210qvuzpq , & rtB . cvfcfkbbot , & rtB .
nlnobuqb4t , & rtB . dnk2tludg2 , & rtB . i32tsyahbh , & rtB . cq2d2pwdt4 , &
rtB . beedf1ybtr , & rtB . hq4mhr11mq , & rtB . mqvpg31jlu , & rtB .
a4b4l1echj , & rtB . beedf1ybtr , & rtB . hq4mhr11mq , & rtB . mqvpg31jlu , &
rtB . a4b4l1echj , & rtB . a4b4l1echj , & rtB . beedf1ybtr , & rtB .
hq4mhr11mq , & rtB . mqvpg31jlu , & rtB . m3wbmdk01n , & rtB . cxcy4qomm3 , &
rtB . lxakjhp4ut , & rtB . cxcy4qomm3 , & rtB . lxakjhp4ut , & rtB .
cxcy4qomm3 , & rtB . lxakjhp4ut , & rtB . iavmf0c0td , & rtB . h1yvg3hrrj , &
rtB . mpbv3fozuy , & rtB . e4wlihh0yp , & rtB . fdtuj3yfv3 , & rtB .
fdtuj3yfv3 , & rtB . fdtuj3yfv3 , & rtB . obpp1l4vac , & rtB . eqqz4ci0tv , &
rtB . obpp1l4vac , & rtB . eqqz4ci0tv , & rtB . obpp1l4vac , & rtB .
eqqz4ci0tv , & rtB . obpp1l4vac , & rtB . eqqz4ci0tv , & rtB . beedf1ybtr , &
rtB . hq4mhr11mq , & rtB . fxbpkblr2q , & rtB . a4b4l1echj , & rtB .
k21i5spcnm , & rtB . ahrdefsall , & rtB . au0ix1q5sj , & rtB . irttg002ix , &
rtB . h4fmwxdtzw , & rtB . m3te3eovpd , & rtB . lxakjhp4ut , & rtB .
cxcy4qomm3 , & rtB . olw4ikbxkg , & rtB . mxxpbb3p2w , & rtB . olw4ikbxkg , &
rtB . mxxpbb3p2w , & rtB . olw4ikbxkg , & rtB . mxxpbb3p2w , & rtB .
jjopdzn0py , & rtB . hbxfzslsut , & rtB . enyymmluck , & rtB . fdtuj3yfv3 , &
rtB . ctnwpqizmx , & rtB . eqqz4ci0tv , & rtB . eqqz4ci0tv , & rtB .
eqqz4ci0tv , & rtB . obpp1l4vac , & rtB . eqqz4ci0tv , & rtB . obpp1l4vac , &
rtB . eqqz4ci0tv , & rtB . eqqz4ci0tv , & rtB . obpp1l4vac , & rtB .
mxgpxbyfng [ 0 ] , & rtB . m12o31k1vs [ 0 ] , & rtB . kyvpkfkfuw [ 0 ] , &
rtB . jhai0ek5up [ 0 ] , & rtB . ea1x0lvxve , & rtB . nwoetve5i4 [ 0 ] , &
rtB . j14q1l0ljs [ 0 ] , & rtB . jhwxdwr1el , & rtB . itamdryrgl , & rtB .
jjopdzn0py , & rtB . hbxfzslsut , & rtB . enyymmluck , & rtB . gg2bbcdrrw , &
rtB . g1be22q2ab [ 0 ] , & rtB . a51hahehmm [ 0 ] , & rtB . akjx0hsfge [ 0 ]
, & rtB . ctnwpqizmx , & rtB . eqqz4ci0tv , & rtB . ctnwpqizmx , & rtB .
eqqz4ci0tv , & rtB . ctnwpqizmx , & rtB . eqqz4ci0tv , & rtB . eqqz4ci0tv , &
rtB . obpp1l4vac , & rtB . eqqz4ci0tv , & rtB . eqqz4ci0tv , & rtB .
eqqz4ci0tv , & rtB . m4c5zvfilf [ 0 ] , & rtB . otltqoc5al , & rtB .
ev0c2l5p3p , & rtB . hg3boogiog , & rtB . k2emjlyzxk , & rtB . chctnrcvr3 , &
rtB . kvxxl1simd , & rtB . max0cti2zd , & rtB . fcdzod43fw , & rtB .
aarbwzwmur , & rtB . d44xfr2uxh , & rtB . ksa4mls0wk , & rtB . fkufe2dwcc , &
rtB . lh5ejoytai , & rtB . prxcefcei5 , & rtB . baetrfr4r5 , & rtB .
i4tiig10qa , & rtB . ii512bfhkj , & rtB . ct0fhunmet , & rtB . ludaotrnqc , &
rtB . fyijl5q30k , & rtB . gvb04ezgus , & rtB . k2zygd0izr , & rtB .
em2j1rtzfx , & rtB . m4hxih4mk4 , & rtB . mkzwwcawji , & rtB . gssztf5fdg , &
rtB . m5zlrndttj , & rtB . gg2bbcdrrw , & rtB . lthpnqg4ps , & rtB .
n3yzlaao40 , & rtB . pomgrq4ofk , & rtB . oudpsgugrl , & rtB . ennxpj0tru [ 0
] , & rtB . m4bwkc5hnn , & rtB . frdjc0ipbc , & rtB . o1uhppc0j4 , & rtB .
ctnwpqizmx , & rtB . eqqz4ci0tv , & rtB . ctnwpqizmx , & rtB . ml5chi14gx , &
rtB . bykovcr4gn , & rtB . kt4qdvgqqh , & rtB . fjud52gekg [ 0 ] , & rtB .
favitckluv , & rtB . lo0fmxamwn , & rtB . eqqz4ci0tv , & rtB . eqqz4ci0tv , &
rtB . bvlzron2lo , & rtB . bdpeazbcik , & rtB . nfsnsrxlvr , & rtB .
ht0sdc4e2n , & rtB . krguxydvse , & rtB . ivjcnxt5l0 , & rtB . fpnl3wyn4z , &
rtB . lufxmyxbr0 , & rtB . lg5bmspaoy , & rtB . mi1n1xzbri , & rtB .
ddcgg2bx0n , & rtB . dbu1cph3qd , & rtB . ph0oqajh3o , & rtB . gx1mbhkzzf , &
rtB . hzgfvz42dk , & rtB . hzgfvz42dk , & rtB . hzgfvz42dk , & rtB .
hbxfzslsut , & rtB . enyymmluck , & rtB . jjopdzn0py , & rtB . krukbv1au2 , &
rtB . dmu1xpyaah , & rtB . nufjeirxpo , & rtB . jem0p5cmwo , & rtB .
jtkb23rkw2 , & rtB . enjx00pe1u , & rtB . ocvt3xrn00 , & rtB . btuvjnvywk , &
rtB . foeysnqrik , & rtB . fkz44ny3ao , & rtB . nhto33wndj , & rtB .
cguxiwph41 , & rtB . hzgfvz42dk , & rtB . hzgfvz42dk , & rtB . hzgfvz42dk , &
rtB . hzgfvz42dk , & rtB . h2k2rk41bt , & rtB . gnyyc12ptg , & rtB .
h1oufun4jj , & rtB . kkagvopgxv , & rtB . ary5hhvnmx , & rtB . obnipod5vd , &
rtB . k2zpu1crq0 , & rtB . hcl3f2ypn0 , & rtB . ceua4sozts , & rtB .
ja5xj0z1cg , & rtB . feuebfqypv , & rtB . kumjwk2t03 , & rtB . g122wtg0el , &
rtB . cgtnywjknf , & rtB . fhuegjob4p , & rtB . il1hhqxhtq , & rtB .
avg1hsnek4 , & rtB . gxy0dk5ecd , & rtB . hzgfvz42dk , & rtB . hzgfvz42dk , &
rtB . d0ddtqwuj5 , & rtP . DatasheetBattery_Em [ 0 ] , & rtP .
DatasheetBattery_CapLUTBp [ 0 ] , & rtP . DatasheetBattery_RInt [ 0 ] , & rtP
. DatasheetBattery_BattTempBp [ 0 ] , & rtP . DatasheetBattery_CapSOCBp [ 0 ]
, & rtP . DatasheetBattery_Tc , & rtP . DatasheetBattery_Vinit , & rtP .
SKP6485_idq0 [ 0 ] , & rtP . SKP6485_theta_init , & rtP . SKP6485_omega_init
, & rtP . SurfaceMountPMController1_idq_limits , & rtP .
SurfaceMountPMController1_Kp_d , & rtP . SurfaceMountPMController1_Kp_q , &
rtP . SurfaceMountPMController1_Ki , & rtP . SurfaceMountPMController1_ba , &
rtP . SurfaceMountPMController1_Ksa , & rtP . SurfaceMountPMController1_Kisa
, & rtP . SurfaceMountPMController1_Ksf , & rtP .
SurfaceMountPMController1_Jcomp , & rtP . SurfaceMountPMController1_Fv , &
rtP . SurfaceMountPMController1_Fs , & rtP . Constant_Value_in3f0w41r2 , &
rtP . Constant1_Value_bpuwj1x24m , & rtP . Constant2_Value_iswfbqmgg0 , & rtP
. Constant3_Value_clw2lo3chi , & rtP . Constant4_Value_o2jsgu5bg0 , & rtP .
Gain1_Gain_nd3h1ot2bp , & rtP . kgstogmin_Gain , & rtP . Integrator_IC , &
rtP . DA50PowerMap_tableData [ 0 ] , & rtP . DA50PowerMap_bp01Data [ 0 ] , &
rtP . DA50PowerMap_bp02Data [ 0 ] , & rtP . DA50PowerMap_maxIndex [ 0 ] , &
rtP . DA50TorqueMap_tableData [ 0 ] , & rtP . DA50TorqueMap_bp01Data [ 0 ] ,
& rtP . DA50TorqueMap_bp02Data [ 0 ] , & rtP . DA50TorqueMap_maxIndex [ 0 ] ,
& rtP . Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal , & rtP .
ManualSwitch_CurrentSetting , & rtP . ManualSwitch1_CurrentSetting , & rtP .
ManualSwitch2_CurrentSetting , & rtP . ManualSwitch3_CurrentSetting , & rtP .
fromWS_Signal1_Time0_eamifk5xcs [ 0 ] , & rtP .
fromWS_Signal1_Data0_prwgobmyi3 [ 0 ] , & rtP .
Merge_InitialOutput_htptbem0s2 , & rtP . Merge1_InitialOutput_ngwc5befhy , &
rtP . Merge2_InitialOutput , & rtP . Merge3_InitialOutput , & rtP .
fromWS_Signal1_Time0_pgpp53252z [ 0 ] , & rtP .
fromWS_Signal1_Data0_n4yqnlgdbj [ 0 ] , & rtP . fromWS_Signal1_Time0 [ 0 ] ,
& rtP . fromWS_Signal1_Data0 [ 0 ] , & rtP . fromWS_Signal1_Time0_ommwt43mku
[ 0 ] , & rtP . fromWS_Signal1_Data0_lxog1ybljy [ 0 ] , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . RPMtodegs_Gain , & rtP .
Integrator_IC_ahzk3fe0wi , & rtP . Integrator_WrappedStateUpperValue , & rtP
. Integrator_WrappedStateLowerValue , & rtP . rpmtorads_Gain , & rtP .
Merge_InitialOutput , & rtP . Merge1_InitialOutput , & rtP .
Constant2_Value_nzc55mhdyv , & rtP . uDLookupTable_bp01Data [ 0 ] , & rtP .
uDLookupTable_bp02Data [ 0 ] , & rtP . uDLookupTable_maxIndex [ 0 ] , & rtP .
uDLookupTable1_tableData [ 0 ] , & rtP . Switch_Threshold , & rtP .
Constant_Value_kkku1dkpit , & rtP . Constant_Value_ea5wuf1vfl , & rtP .
Merge_InitialOutput_l2wioipoqf , & rtP . uDLookupTable2_tableData [ 0 ] , &
rtP . uDLookupTable2_bp01Data [ 0 ] , & rtP . uDLookupTable2_bp02Data [ 0 ] ,
& rtP . uDLookupTable2_maxIndex [ 0 ] , & rtP . Constant1_Value_eafxkgr2qu ,
& rtP . Constant_Value_m22jzxcnam , & rtP . EngTrqTable_maxIndex [ 0 ] , &
rtP . FuelMassFlwTable_maxIndex [ 0 ] , & rtP . IntegratorLimited_LowerSat ,
& rtP . R_maxIndex [ 0 ] , & rtP . Constant1_Value_ohpunqj1gy , & rtP .
Constant3_Value_otox1iiiva , & rtP . Constant5_Value_n1ykd3pjvs , & rtP .
Gain5_Gain_ofpzj4djyh , & rtP . Int_UpperSat , & rtP . Int_LowerSat , & rtP .
Int1_WrappedStateUpperValue , & rtP . Int1_WrappedStateLowerValue , & rtP .
DiscreteTimeIntegrator_gainval , & rtP . DiscreteTimeIntegrator_IC , & rtP .
DiscreteTimeIntegrator1_gainval , & rtP . DiscreteTimeIntegrator1_IC , & rtP
. DiscreteTimeIntegrator_gainval_p43vz5tnpd , & rtP .
DiscreteTimeIntegrator_IC_nipgxr4w4m , & rtP . Constant2_Value_ibttoaofbk , &
rtP . Constant3_Value_hvfq5alqlg [ 0 ] , & rtP . Constant4_Value_fecgcw2rtb ,
& rtP . Constant5_Value_axuapffnub , & rtP .
uDLookupTable_maxIndex_amrotqgr0w [ 0 ] , & rtP .
uDLookupTable2_maxIndex_ebipil2bvy [ 0 ] , & rtP .
Switch1_Threshold_er3fpts1xb , & rtP . Switch2_Threshold , & rtP .
Switch3_Threshold , & rtP . uDLookupTable2_maxIndex_pobosuq2zq [ 0 ] , & rtP
. Constant_Value_lsistt0yxv , & rtP . Switch1_Threshold , & rtP .
Switch4_Threshold , & rtP . Constant2_Value_fkd3f5524d , & rtP .
Constant3_Value_mwesjrmlpm [ 0 ] , & rtP . Constant4_Value_mph0ksevah , & rtP
. Constant5_Value_p2jqkjofwo , & rtP . uDLookupTable_maxIndex_c0gevfgaga [ 0
] , & rtP . uDLookupTable2_maxIndex_ljaygbg3k3 [ 0 ] , & rtP .
Switch1_Threshold_n1hoa2ckzb , & rtP . Switch2_Threshold_bn224qmpbp , & rtP .
Switch3_Threshold_ff0k22oeft , & rtP . uDLookupTable2_maxIndex_iu5fpwg5m1 [ 0
] , & rtP . Gain_Gain_a2pdrz3qwa , & rtP . Gain1_Gain_p2f3paaf35 , & rtP .
Gain2_Gain_f3g2yr2rkw , & rtP . Gain3_Gain_kigulbfrzl , & rtP .
Gain4_Gain_a3qhxjwm2o , & rtP . Gain1_Gain_heyv1n0f4a , & rtP .
Gain2_Gain_hwyq1kurck , & rtP . Gain3_Gain_lvn3xsxcbg , & rtP .
Gain4_Gain_c032xsbfri , & rtP . Gain_Gain , & rtP . Gain1_Gain , & rtP .
Gain2_Gain , & rtP . Gain3_Gain , & rtP . Gain4_Gain , & rtP . Gain5_Gain , &
rtP . Constant4_Value , & rtP . Gain1_Gain_j1b2wfl0wo , & rtP .
Merge1_InitialOutput_j4un0hwehg , & rtP . Proportional_Gain2_Gain , & rtP .
Proportional_Gain3_Gain , & rtP . Gain1_Gain_fvtzit2ppk , & rtP .
Gain2_Gain_en3fcdxiec , & rtP . Gain3_Gain_h5v1k1sppn , & rtP .
Gain4_Gain_ne1f41rvzn , & rtP . Constant_Value_c45tuyaygc [ 0 ] , & rtP .
Constant1_Value_mj3ya5njvu , & rtP . Constant2_Value_m2kdydkjx0 , & rtP .
Constant1_Value_bg0rrb32ed , & rtP . Integrator_UpperSat , & rtP .
Integrator_LowerSat , & rtP . Constant1_Value_nwflgkncxk , & rtP .
Integrator_UpperSat_dip02x0ffl , & rtP . Integrator_LowerSat_bbrmas44s3 , &
rtP . Constant1_Value_brfyntmkio , & rtP . Gain1_Gain_c2kuo5vmhc , & rtP .
Gain1_Gain_he3uzhz5qz , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . UnitDelay_InitialCondition , & rtP .
Gain1_Gain_nnzhsn1hyd , & rtP . Saturation_UpperSat_phs0dpqpzg , & rtP .
Saturation_LowerSat_gdduvb3oo2 , & rtP .
UnitDelay_InitialCondition_cpl50tg2hx , & rtP . Constant_Value_go40v4ie0s [ 0
] , & rtP . Constant1_Value_kozehzplrf , & rtP . Constant_Value_dm14eym3wc [
0 ] , & rtP . Constant1_Value_k5ndhlm4pr , & rtP . Constant2_Value_fw4dwfnqy4
, & rtP . Constant1_Value_om5j34o2qt [ 0 ] , & rtP .
Constant2_Value_kk042enjt5 , & rtP . Constant_Value_aqptyhwws5 [ 0 ] , & rtP
. Constant1_Value_il2awj2dhq , & rtP . Constant_Value_pf0letx30a [ 0 ] , &
rtP . Constant1_Value_na2pva40rs , & rtP . Constant2_Value_nligrrj1ds , & rtP
. Constant1_Value_b2jt3bjlb1 [ 0 ] , & rtP . Constant2_Value_e34qlb3i30 , &
rtP . Constant1_Value_igomjraxnc [ 0 ] , & rtP . Constant2_Value_hsqnj2ufwi ,
& rtP . Constant2_Value , & rtP . Constant3_Value , & rtP . Constant5_Value ,
& rtP . Batt_Cap , & rtP . Batt_Parr , & rtP . Batt_Series , & rtP . Dyno_Ke
, & rtP . Dyno_Kt , & rtP . Dyno_Ratio , & rtP . Fuel_Map [ 0 ] , & rtP .
Fuel_MapE [ 0 ] , & rtP . Power_Map [ 0 ] , & rtP . Power_Thr_Map [ 0 ] , &
rtP . SideA_N , & rtP . SideA_Physical_Param [ 0 ] , & rtP . SideA_RatedTrq ,
& rtP . SideA_Rs , & rtP . SideA_lambda , & rtP . Spd_BP [ 0 ] , & rtP .
Trq_BP [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof (
uint32_T ) , ( uint8_T ) SS_UINT32 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } , { rtwCAPI_VECTOR , 18 , 2 , 0 } , {
rtwCAPI_VECTOR , 20 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 22 , 2 , 0 } , {
rtwCAPI_VECTOR , 24 , 2 , 0 } , { rtwCAPI_VECTOR , 26 , 2 , 0 } , {
rtwCAPI_VECTOR , 28 , 2 , 0 } , { rtwCAPI_VECTOR , 30 , 2 , 0 } , {
rtwCAPI_VECTOR , 32 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 34 , 2 , 0 } , {
rtwCAPI_VECTOR , 36 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 38 , 2 , 0 } , {
rtwCAPI_VECTOR , 40 , 2 , 0 } , { rtwCAPI_VECTOR , 42 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 4 , 1 , 2 , 1 , 5 , 1 , 3 , 1 ,
12 , 1 , 1 , 101 , 7 , 6 , 1 , 7 , 1 , 6 , 1 , 2 , 11 , 6 , 1 , 11 , 6 , 1 ,
8 , 1 , 15 , 1 , 11 , 1 , 10 , 6 , 1 , 10 , 12 , 7 , 1 , 3 , 1 , 12 } ;
static const real_T rtcapiStoredFloats [ ] = { 0.0 , 5.0E-5 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( NULL ) , ( NULL ) , 2 , 0 } , { ( const
void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [
0 ] , ( int8_T ) 1 , ( uint8_T ) 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 214 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 183 ,
rtModelParameters , 17 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 3064774813U , 227680994U , 1504209091U ,
2416809870U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * ParallelTestBench_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
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
