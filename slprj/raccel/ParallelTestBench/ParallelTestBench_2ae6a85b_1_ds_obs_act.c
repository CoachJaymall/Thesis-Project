#include "ne_ds.h"
#include "ParallelTestBench_2ae6a85b_1_ds_sys_struct.h"
#include "ParallelTestBench_2ae6a85b_1_ds_obs_act.h"
#include "ParallelTestBench_2ae6a85b_1_ds.h"
#include "ParallelTestBench_2ae6a85b_1_ds_externals.h"
#include "ParallelTestBench_2ae6a85b_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T ParallelTestBench_2ae6a85b_1_ds_obs_act ( const NeDynamicSystem * sys
, const NeDynamicSystemInput * t5 , NeDsMethodOutput * t6 ) { PmRealVector
out ; real_T t0 [ 49 ] ; real_T TMotorU15_Flexible_Shaft1_Fsupports [ 4 ] ;
real_T TMotorU15_Flexible_Shaft1_torsional_damper_t ; real_T
TMotorU15_Ideal_Angular_Velocity_Source_t ; real_T U_idx_0 ; real_T X_idx_0 ;
real_T X_idx_1 ; real_T X_idx_2 ; real_T X_idx_3 ; size_t t4 ; U_idx_0 = t5
-> mU . mX [ 0 ] ; X_idx_0 = t5 -> mX . mX [ 0 ] ; X_idx_1 = t5 -> mX . mX [
1 ] ; X_idx_2 = t5 -> mX . mX [ 2 ] ; X_idx_3 = t5 -> mX . mX [ 3 ] ; out =
t6 -> mOBS_ACT ; TMotorU15_Flexible_Shaft1_Fsupports [ 0 ] = 0.0 ;
TMotorU15_Flexible_Shaft1_Fsupports [ 1 ] = 0.0 ;
TMotorU15_Flexible_Shaft1_Fsupports [ 2 ] = 0.0 ;
TMotorU15_Flexible_Shaft1_Fsupports [ 3 ] = 0.0 ;
TMotorU15_Flexible_Shaft1_torsional_damper_t = X_idx_1 *
0.00046599999999999994 ; TMotorU15_Ideal_Angular_Velocity_Source_t = X_idx_1
* - 0.00046599999999999994 - X_idx_3 ; t0 [ 0ULL ] = X_idx_1 ; t0 [ 1ULL ] =
X_idx_1 ; for ( t4 = 0ULL ; t4 < 4ULL ; t4 ++ ) { t0 [ t4 + 2ULL ] =
TMotorU15_Flexible_Shaft1_Fsupports [ t4 ] ; } for ( t4 = 0ULL ; t4 < 4ULL ;
t4 ++ ) { t0 [ t4 + 6ULL ] = TMotorU15_Flexible_Shaft1_Fsupports [ t4 ] ; }
for ( t4 = 0ULL ; t4 < 4ULL ; t4 ++ ) { t0 [ t4 + 10ULL ] =
TMotorU15_Flexible_Shaft1_Fsupports [ t4 ] ; } for ( t4 = 0ULL ; t4 < 4ULL ;
t4 ++ ) { t0 [ t4 + 14ULL ] = TMotorU15_Flexible_Shaft1_Fsupports [ t4 ] ; }
out . mX [ 0 ] = t0 [ 0 ] ; out . mX [ 1 ] = t0 [ 1 ] ; out . mX [ 2 ] = t0 [
2 ] ; out . mX [ 3 ] = t0 [ 3 ] ; out . mX [ 4 ] = t0 [ 4 ] ; out . mX [ 5 ]
= t0 [ 5 ] ; out . mX [ 6 ] = t0 [ 6 ] ; out . mX [ 7 ] = t0 [ 7 ] ; out . mX
[ 8 ] = t0 [ 8 ] ; out . mX [ 9 ] = t0 [ 9 ] ; out . mX [ 10 ] = t0 [ 10 ] ;
out . mX [ 11 ] = t0 [ 11 ] ; out . mX [ 12 ] = t0 [ 12 ] ; out . mX [ 13 ] =
t0 [ 13 ] ; out . mX [ 14 ] = t0 [ 14 ] ; out . mX [ 15 ] = t0 [ 15 ] ; out .
mX [ 16 ] = t0 [ 16 ] ; out . mX [ 17 ] = t0 [ 17 ] ; out . mX [ 18 ] =
X_idx_0 ; out . mX [ 19 ] = 0.0 ; out . mX [ 20 ] = X_idx_1 ; out . mX [ 21 ]
= TMotorU15_Flexible_Shaft1_torsional_damper_t ; out . mX [ 22 ] =
TMotorU15_Flexible_Shaft1_torsional_damper_t * 2145.9227467811161 ; out . mX
[ 23 ] = X_idx_1 ; out . mX [ 24 ] = X_idx_1 ; out . mX [ 25 ] = X_idx_3 ;
out . mX [ 26 ] = X_idx_1 ; out . mX [ 27 ] = X_idx_1 ; out . mX [ 28 ] =
X_idx_3 * 382.99502106472613 ; out . mX [ 29 ] = 0.0 ; out . mX [ 30 ] =
X_idx_1 ; out . mX [ 31 ] = U_idx_0 ; out . mX [ 32 ] =
TMotorU15_Ideal_Angular_Velocity_Source_t ; out . mX [ 33 ] = X_idx_1 ; out .
mX [ 34 ] = X_idx_2 ; out . mX [ 35 ] = 0.0 ; out . mX [ 36 ] = X_idx_1 ; out
. mX [ 37 ] = X_idx_1 ; out . mX [ 38 ] = 0.0 ; out . mX [ 39 ] = X_idx_2 ;
out . mX [ 40 ] = X_idx_1 ; out . mX [ 41 ] = X_idx_1 ; out . mX [ 42 ] =
X_idx_1 ; out . mX [ 43 ] = - TMotorU15_Ideal_Angular_Velocity_Source_t ; out
. mX [ 44 ] = - TMotorU15_Ideal_Angular_Velocity_Source_t ; out . mX [ 45 ] =
- TMotorU15_Ideal_Angular_Velocity_Source_t ; out . mX [ 46 ] = 0.0 ; out .
mX [ 47 ] = X_idx_2 ; out . mX [ 48 ] = U_idx_0 ; ( void ) sys ; ( void ) t6
; return 0 ; }
