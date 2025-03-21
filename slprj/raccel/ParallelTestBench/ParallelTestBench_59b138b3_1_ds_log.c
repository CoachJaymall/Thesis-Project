#include "ne_ds.h"
#include "ParallelTestBench_59b138b3_1_ds_sys_struct.h"
#include "ParallelTestBench_59b138b3_1_ds_log.h"
#include "ParallelTestBench_59b138b3_1_ds.h"
#include "ParallelTestBench_59b138b3_1_ds_externals.h"
#include "ParallelTestBench_59b138b3_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T ParallelTestBench_59b138b3_1_ds_log ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out
; real_T ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 ;
real_T U_idx_0 ; real_T X_idx_0 ; real_T X_idx_1 ; real_T X_idx_2 ; real_T
X_idx_3 ; U_idx_0 = t1 -> mU . mX [ 0 ] ; X_idx_0 = t1 -> mX . mX [ 0 ] ;
X_idx_1 = t1 -> mX . mX [ 1 ] ; X_idx_2 = t1 -> mX . mX [ 2 ] ; X_idx_3 = t1
-> mX . mX [ 3 ] ; out = t2 -> mLOG ;
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 = X_idx_0 *
0.003496 ; out . mX [ 0 ] = X_idx_0 ; out . mX [ 1 ] = U_idx_0 ; out . mX [ 2
] = X_idx_0 * - 0.003496 - X_idx_3 ; out . mX [ 3 ] = X_idx_0 ; out . mX [ 4
] = X_idx_1 ; out . mX [ 5 ] = X_idx_0 ; out . mX [ 6 ] = X_idx_0 ; out . mX
[ 7 ] = X_idx_1 ; out . mX [ 8 ] = X_idx_0 ; out . mX [ 9 ] = X_idx_0 ; out .
mX [ 10 ] = X_idx_0 ; out . mX [ 11 ] = X_idx_2 ; out . mX [ 12 ] = X_idx_0 ;
out . mX [ 13 ] =
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 ; out . mX [
14 ] = ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 *
286.04118993135012 ; out . mX [ 15 ] =
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 *
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 *
286.04118993135012 ; out . mX [ 16 ] = X_idx_0 ; out . mX [ 17 ] = X_idx_0 ;
out . mX [ 18 ] = X_idx_3 ; out . mX [ 19 ] = X_idx_0 ; out . mX [ 20 ] =
X_idx_0 ; out . mX [ 21 ] = X_idx_3 * 14.274702372455533 ; out . mX [ 22 ] =
X_idx_1 ; out . mX [ 23 ] = U_idx_0 ; ( void ) sys ; ( void ) t2 ; return 0 ;
}
