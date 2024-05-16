#include "ne_ds.h"
#include "ParallelTestBench_2ae6a85b_1_ds_sys_struct.h"
#include "ParallelTestBench_2ae6a85b_1_ds_log.h"
#include "ParallelTestBench_2ae6a85b_1_ds.h"
#include "ParallelTestBench_2ae6a85b_1_ds_externals.h"
#include "ParallelTestBench_2ae6a85b_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T ParallelTestBench_2ae6a85b_1_ds_log ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out
; real_T TMotorU15_Flexible_Shaft1_torsional_damper_t ; real_T
TMotorU15_Ideal_Angular_Velocity_Source_t ; real_T U_idx_0 ; real_T X_idx_0 ;
real_T X_idx_1 ; real_T X_idx_2 ; real_T X_idx_3 ; U_idx_0 = t1 -> mU . mX [
0 ] ; X_idx_0 = t1 -> mX . mX [ 0 ] ; X_idx_1 = t1 -> mX . mX [ 1 ] ; X_idx_2
= t1 -> mX . mX [ 2 ] ; X_idx_3 = t1 -> mX . mX [ 3 ] ; out = t2 -> mLOG ;
TMotorU15_Flexible_Shaft1_torsional_damper_t = X_idx_1 *
0.00046599999999999994 ; TMotorU15_Ideal_Angular_Velocity_Source_t = X_idx_1
* - 0.00046599999999999994 - X_idx_3 ; out . mX [ 0 ] = X_idx_1 ; out . mX [
1 ] = X_idx_1 ; out . mX [ 2 ] = X_idx_0 ; out . mX [ 3 ] = X_idx_1 ; out .
mX [ 4 ] = TMotorU15_Flexible_Shaft1_torsional_damper_t ; out . mX [ 5 ] =
TMotorU15_Flexible_Shaft1_torsional_damper_t * 2145.9227467811161 ; out . mX
[ 6 ] = TMotorU15_Flexible_Shaft1_torsional_damper_t *
TMotorU15_Flexible_Shaft1_torsional_damper_t * 2145.9227467811161 ; out . mX
[ 7 ] = X_idx_1 ; out . mX [ 8 ] = X_idx_1 ; out . mX [ 9 ] = X_idx_3 ; out .
mX [ 10 ] = X_idx_1 ; out . mX [ 11 ] = X_idx_1 ; out . mX [ 12 ] = X_idx_3 *
382.99502106472613 ; out . mX [ 13 ] = X_idx_1 ; out . mX [ 14 ] = U_idx_0 ;
out . mX [ 15 ] = TMotorU15_Ideal_Angular_Velocity_Source_t ; out . mX [ 16 ]
= X_idx_1 ; out . mX [ 17 ] = X_idx_2 ; out . mX [ 18 ] = X_idx_1 ; out . mX
[ 19 ] = X_idx_1 ; out . mX [ 20 ] = X_idx_2 ; out . mX [ 21 ] = X_idx_1 ;
out . mX [ 22 ] = X_idx_1 ; out . mX [ 23 ] = X_idx_1 ; out . mX [ 24 ] = -
TMotorU15_Ideal_Angular_Velocity_Source_t ; out . mX [ 25 ] = -
TMotorU15_Ideal_Angular_Velocity_Source_t ; out . mX [ 26 ] = -
TMotorU15_Ideal_Angular_Velocity_Source_t ; out . mX [ 27 ] = X_idx_2 ; out .
mX [ 28 ] = U_idx_0 ; ( void ) sys ; ( void ) t2 ; return 0 ; }
