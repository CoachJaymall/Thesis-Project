#include "ne_ds.h"
#include "ParallelTestBench_1d80934b_1_ds_sys_struct.h"
#include "ParallelTestBench_1d80934b_1_ds_obs_act.h"
#include "ParallelTestBench_1d80934b_1_ds.h"
#include "ParallelTestBench_1d80934b_1_ds_externals.h"
#include "ParallelTestBench_1d80934b_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T ParallelTestBench_1d80934b_1_ds_obs_act ( const NeDynamicSystem * sys
, const NeDynamicSystemInput * t9 , NeDsMethodOutput * t10 ) { PmRealVector
out ; real_T t0 [ 78 ] ; real_T BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ 4 ]
; real_T BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t ; real_T
BLDC_Side_Inertias_BLDC_Shaft_torsional_inertia_t ; real_T
BLDC_Side_Inertias_BLDC_Shaft_wDer ; real_T
BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t ; real_T
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; real_T U_idx_0 ; real_T
X_idx_0 ; real_T X_idx_1 ; real_T X_idx_2 ; real_T X_idx_3 ; real_T X_idx_4 ;
size_t t8 ; U_idx_0 = t9 -> mU . mX [ 0 ] ; X_idx_0 = t9 -> mX . mX [ 0 ] ;
X_idx_1 = t9 -> mX . mX [ 1 ] ; X_idx_2 = t9 -> mX . mX [ 2 ] ; X_idx_3 = t9
-> mX . mX [ 3 ] ; X_idx_4 = t9 -> mX . mX [ 4 ] ; out = t10 -> mOBS_ACT ;
BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ 0 ] = 0.0 ;
BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ 1 ] = 0.0 ;
BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ 2 ] = 0.0 ;
BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ 3 ] = 0.0 ;
BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t = X_idx_1 *
0.00035999999999999997 ; BLDC_Side_Inertias_BLDC_Shaft_torsional_inertia_t =
X_idx_4 * 0.24940476190476191 ; BLDC_Side_Inertias_BLDC_Shaft_wDer = X_idx_4
* 297.61904761904759 ; BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t =
X_idx_1 * 0.0034 ; BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t = (
X_idx_1 * - 0.00376 - BLDC_Side_Inertias_BLDC_Shaft_torsional_inertia_t ) -
X_idx_4 ; t0 [ 0ULL ] = X_idx_1 ; t0 [ 1ULL ] = X_idx_1 ; for ( t8 = 0ULL ;
t8 < 4ULL ; t8 ++ ) { t0 [ t8 + 2ULL ] =
BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ t8 ] ; } for ( t8 = 0ULL ; t8 <
4ULL ; t8 ++ ) { t0 [ t8 + 6ULL ] = BLDC_Side_Inertias_BLDC_Shaft_Fsupports [
t8 ] ; } for ( t8 = 0ULL ; t8 < 4ULL ; t8 ++ ) { t0 [ t8 + 10ULL ] =
BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ t8 ] ; } for ( t8 = 0ULL ; t8 <
4ULL ; t8 ++ ) { t0 [ t8 + 14ULL ] = BLDC_Side_Inertias_BLDC_Shaft_Fsupports
[ t8 ] ; } t0 [ 18ULL ] = X_idx_0 ; t0 [ 19ULL ] = 0.0 ; t0 [ 20ULL ] =
X_idx_1 ; t0 [ 21ULL ] = BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t ;
t0 [ 22ULL ] = BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t *
2777.7777777777778 ; t0 [ 23ULL ] = X_idx_1 ; t0 [ 24ULL ] = X_idx_1 ; t0 [
25ULL ] = BLDC_Side_Inertias_BLDC_Shaft_torsional_inertia_t ; t0 [ 26ULL ] =
X_idx_1 ; t0 [ 27ULL ] = X_idx_1 ; t0 [ 28ULL ] =
BLDC_Side_Inertias_BLDC_Shaft_wDer ; t0 [ 29ULL ] = X_idx_1 ; t0 [ 30ULL ] =
X_idx_1 ; for ( t8 = 0ULL ; t8 < 4ULL ; t8 ++ ) { t0 [ t8 + 31ULL ] =
BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ t8 ] ; } for ( t8 = 0ULL ; t8 <
4ULL ; t8 ++ ) { t0 [ t8 + 35ULL ] = BLDC_Side_Inertias_BLDC_Shaft_Fsupports
[ t8 ] ; } for ( t8 = 0ULL ; t8 < 4ULL ; t8 ++ ) { t0 [ t8 + 39ULL ] =
BLDC_Side_Inertias_BLDC_Shaft_Fsupports [ t8 ] ; } for ( t8 = 0ULL ; t8 <
4ULL ; t8 ++ ) { t0 [ t8 + 43ULL ] = BLDC_Side_Inertias_BLDC_Shaft_Fsupports
[ t8 ] ; } out . mX [ 0 ] = t0 [ 0 ] ; out . mX [ 1 ] = t0 [ 1 ] ; out . mX [
2 ] = t0 [ 2 ] ; out . mX [ 3 ] = t0 [ 3 ] ; out . mX [ 4 ] = t0 [ 4 ] ; out
. mX [ 5 ] = t0 [ 5 ] ; out . mX [ 6 ] = t0 [ 6 ] ; out . mX [ 7 ] = t0 [ 7 ]
; out . mX [ 8 ] = t0 [ 8 ] ; out . mX [ 9 ] = t0 [ 9 ] ; out . mX [ 10 ] =
t0 [ 10 ] ; out . mX [ 11 ] = t0 [ 11 ] ; out . mX [ 12 ] = t0 [ 12 ] ; out .
mX [ 13 ] = t0 [ 13 ] ; out . mX [ 14 ] = t0 [ 14 ] ; out . mX [ 15 ] = t0 [
15 ] ; out . mX [ 16 ] = t0 [ 16 ] ; out . mX [ 17 ] = t0 [ 17 ] ; out . mX [
18 ] = t0 [ 18 ] ; out . mX [ 19 ] = t0 [ 19 ] ; out . mX [ 20 ] = t0 [ 20 ]
; out . mX [ 21 ] = t0 [ 21 ] ; out . mX [ 22 ] = t0 [ 22 ] ; out . mX [ 23 ]
= t0 [ 23 ] ; out . mX [ 24 ] = t0 [ 24 ] ; out . mX [ 25 ] = t0 [ 25 ] ; out
. mX [ 26 ] = t0 [ 26 ] ; out . mX [ 27 ] = t0 [ 27 ] ; out . mX [ 28 ] = t0
[ 28 ] ; out . mX [ 29 ] = t0 [ 29 ] ; out . mX [ 30 ] = t0 [ 30 ] ; out . mX
[ 31 ] = t0 [ 31 ] ; out . mX [ 32 ] = t0 [ 32 ] ; out . mX [ 33 ] = t0 [ 33
] ; out . mX [ 34 ] = t0 [ 34 ] ; out . mX [ 35 ] = t0 [ 35 ] ; out . mX [ 36
] = t0 [ 36 ] ; out . mX [ 37 ] = t0 [ 37 ] ; out . mX [ 38 ] = t0 [ 38 ] ;
out . mX [ 39 ] = t0 [ 39 ] ; out . mX [ 40 ] = t0 [ 40 ] ; out . mX [ 41 ] =
t0 [ 41 ] ; out . mX [ 42 ] = t0 [ 42 ] ; out . mX [ 43 ] = t0 [ 43 ] ; out .
mX [ 44 ] = t0 [ 44 ] ; out . mX [ 45 ] = t0 [ 45 ] ; out . mX [ 46 ] = t0 [
46 ] ; out . mX [ 47 ] = X_idx_2 ; out . mX [ 48 ] = 0.0 ; out . mX [ 49 ] =
X_idx_1 ; out . mX [ 50 ] =
BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t ; out . mX [ 51 ] =
BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t * 294.11764705882354 ; out
. mX [ 52 ] = X_idx_1 ; out . mX [ 53 ] = X_idx_1 ; out . mX [ 54 ] = X_idx_4
; out . mX [ 55 ] = X_idx_1 ; out . mX [ 56 ] = X_idx_1 ; out . mX [ 57 ] =
BLDC_Side_Inertias_BLDC_Shaft_wDer ; out . mX [ 58 ] = 0.0 ; out . mX [ 59 ]
= X_idx_1 ; out . mX [ 60 ] = U_idx_0 ; out . mX [ 61 ] =
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; out . mX [ 62 ] =
X_idx_1 ; out . mX [ 63 ] = X_idx_3 ; out . mX [ 64 ] = 0.0 ; out . mX [ 65 ]
= X_idx_1 ; out . mX [ 66 ] = X_idx_1 ; out . mX [ 67 ] = 0.0 ; out . mX [ 68
] = X_idx_3 ; out . mX [ 69 ] = X_idx_1 ; out . mX [ 70 ] = X_idx_1 ; out .
mX [ 71 ] = X_idx_1 ; out . mX [ 72 ] = -
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; out . mX [ 73 ] = -
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; out . mX [ 74 ] = -
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; out . mX [ 75 ] = 0.0 ;
out . mX [ 76 ] = X_idx_3 ; out . mX [ 77 ] = U_idx_0 ; ( void ) sys ; ( void
) t10 ; return 0 ; }
