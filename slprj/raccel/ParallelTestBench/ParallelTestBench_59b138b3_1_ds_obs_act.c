#include "ne_ds.h"
#include "ParallelTestBench_59b138b3_1_ds_sys_struct.h"
#include "ParallelTestBench_59b138b3_1_ds_obs_act.h"
#include "ParallelTestBench_59b138b3_1_ds.h"
#include "ParallelTestBench_59b138b3_1_ds_externals.h"
#include "ParallelTestBench_59b138b3_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T ParallelTestBench_59b138b3_1_ds_obs_act ( const NeDynamicSystem * sys
, const NeDynamicSystemInput * t5 , NeDsMethodOutput * t6 ) { PmRealVector
out ; real_T t0 [ 44 ] ; real_T
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ 4 ] ;
real_T ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 ;
real_T U_idx_0 ; real_T X_idx_0 ; real_T X_idx_1 ; real_T X_idx_2 ; real_T
X_idx_3 ; size_t t4 ; U_idx_0 = t5 -> mU . mX [ 0 ] ; X_idx_0 = t5 -> mX . mX
[ 0 ] ; X_idx_1 = t5 -> mX . mX [ 1 ] ; X_idx_2 = t5 -> mX . mX [ 2 ] ;
X_idx_3 = t5 -> mX . mX [ 3 ] ; out = t6 -> mOBS_ACT ;
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ 0 ] = 0.0 ;
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ 1 ] = 0.0 ;
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ 2 ] = 0.0 ;
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ 3 ] = 0.0 ;
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 = X_idx_0 *
0.003496 ; t0 [ 0ULL ] = 0.0 ; t0 [ 1ULL ] = X_idx_0 ; t0 [ 2ULL ] = U_idx_0
; t0 [ 3ULL ] = X_idx_0 * - 0.003496 - X_idx_3 ; t0 [ 4ULL ] = X_idx_0 ; t0 [
5ULL ] = X_idx_1 ; t0 [ 6ULL ] = 0.0 ; t0 [ 7ULL ] = X_idx_0 ; t0 [ 8ULL ] =
X_idx_0 ; t0 [ 9ULL ] = 0.0 ; t0 [ 10ULL ] = X_idx_1 ; t0 [ 11ULL ] = X_idx_0
; t0 [ 12ULL ] = X_idx_0 ; t0 [ 13ULL ] = X_idx_0 ; for ( t4 = 0ULL ; t4 <
4ULL ; t4 ++ ) { t0 [ t4 + 14ULL ] =
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ t4 ] ; }
for ( t4 = 0ULL ; t4 < 4ULL ; t4 ++ ) { t0 [ t4 + 18ULL ] =
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ t4 ] ; }
for ( t4 = 0ULL ; t4 < 4ULL ; t4 ++ ) { t0 [ t4 + 22ULL ] =
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ t4 ] ; }
for ( t4 = 0ULL ; t4 < 4ULL ; t4 ++ ) { t0 [ t4 + 26ULL ] =
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_Fsupport [ t4 ] ; }
out . mX [ 0 ] = t0 [ 0 ] ; out . mX [ 1 ] = t0 [ 1 ] ; out . mX [ 2 ] = t0 [
2 ] ; out . mX [ 3 ] = t0 [ 3 ] ; out . mX [ 4 ] = t0 [ 4 ] ; out . mX [ 5 ]
= t0 [ 5 ] ; out . mX [ 6 ] = t0 [ 6 ] ; out . mX [ 7 ] = t0 [ 7 ] ; out . mX
[ 8 ] = t0 [ 8 ] ; out . mX [ 9 ] = t0 [ 9 ] ; out . mX [ 10 ] = t0 [ 10 ] ;
out . mX [ 11 ] = t0 [ 11 ] ; out . mX [ 12 ] = t0 [ 12 ] ; out . mX [ 13 ] =
t0 [ 13 ] ; out . mX [ 14 ] = t0 [ 14 ] ; out . mX [ 15 ] = t0 [ 15 ] ; out .
mX [ 16 ] = t0 [ 16 ] ; out . mX [ 17 ] = t0 [ 17 ] ; out . mX [ 18 ] = t0 [
18 ] ; out . mX [ 19 ] = t0 [ 19 ] ; out . mX [ 20 ] = t0 [ 20 ] ; out . mX [
21 ] = t0 [ 21 ] ; out . mX [ 22 ] = t0 [ 22 ] ; out . mX [ 23 ] = t0 [ 23 ]
; out . mX [ 24 ] = t0 [ 24 ] ; out . mX [ 25 ] = t0 [ 25 ] ; out . mX [ 26 ]
= t0 [ 26 ] ; out . mX [ 27 ] = t0 [ 27 ] ; out . mX [ 28 ] = t0 [ 28 ] ; out
. mX [ 29 ] = t0 [ 29 ] ; out . mX [ 30 ] = X_idx_2 ; out . mX [ 31 ] = 0.0 ;
out . mX [ 32 ] = X_idx_0 ; out . mX [ 33 ] =
ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 ; out . mX [
34 ] = ICE_Side_Inertias_Inertia_sum_of_Post_ICE_Rigid_Bodies_torsion1 *
286.04118993135012 ; out . mX [ 35 ] = X_idx_0 ; out . mX [ 36 ] = X_idx_0 ;
out . mX [ 37 ] = X_idx_3 ; out . mX [ 38 ] = X_idx_0 ; out . mX [ 39 ] =
X_idx_0 ; out . mX [ 40 ] = X_idx_3 * 14.274702372455533 ; out . mX [ 41 ] =
0.0 ; out . mX [ 42 ] = X_idx_1 ; out . mX [ 43 ] = U_idx_0 ; ( void ) sys ;
( void ) t6 ; return 0 ; }
