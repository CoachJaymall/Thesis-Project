#include "ne_ds.h"
#include "ParallelTestBench_1d80934b_1_ds_sys_struct.h"
#include "ParallelTestBench_1d80934b_1_ds_log.h"
#include "ParallelTestBench_1d80934b_1_ds.h"
#include "ParallelTestBench_1d80934b_1_ds_externals.h"
#include "ParallelTestBench_1d80934b_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T ParallelTestBench_1d80934b_1_ds_log ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out
; real_T BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t ; real_T
BLDC_Side_Inertias_BLDC_Shaft_torsional_inertia_t ; real_T
BLDC_Side_Inertias_BLDC_Shaft_wDer ; real_T
BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t ; real_T
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; real_T U_idx_0 ; real_T
X_idx_0 ; real_T X_idx_1 ; real_T X_idx_2 ; real_T X_idx_3 ; real_T X_idx_4 ;
U_idx_0 = t1 -> mU . mX [ 0 ] ; X_idx_0 = t1 -> mX . mX [ 0 ] ; X_idx_1 = t1
-> mX . mX [ 1 ] ; X_idx_2 = t1 -> mX . mX [ 2 ] ; X_idx_3 = t1 -> mX . mX [
3 ] ; X_idx_4 = t1 -> mX . mX [ 4 ] ; out = t2 -> mLOG ;
BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t = X_idx_1 *
0.00035999999999999997 ; BLDC_Side_Inertias_BLDC_Shaft_torsional_inertia_t =
X_idx_4 * 0.24940476190476191 ; BLDC_Side_Inertias_BLDC_Shaft_wDer = X_idx_4
* 297.61904761904759 ; BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t =
X_idx_1 * 0.0034 ; BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t = (
X_idx_1 * - 0.00376 - BLDC_Side_Inertias_BLDC_Shaft_torsional_inertia_t ) -
X_idx_4 ; out . mX [ 0 ] = X_idx_1 ; out . mX [ 1 ] = X_idx_1 ; out . mX [ 2
] = X_idx_0 ; out . mX [ 3 ] = X_idx_1 ; out . mX [ 4 ] =
BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t ; out . mX [ 5 ] =
BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t * 2777.7777777777778 ; out .
mX [ 6 ] = BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t *
BLDC_Side_Inertias_BLDC_Shaft_torsional_damper_t * 2777.7777777777778 ; out .
mX [ 7 ] = X_idx_1 ; out . mX [ 8 ] = X_idx_1 ; out . mX [ 9 ] =
BLDC_Side_Inertias_BLDC_Shaft_torsional_inertia_t ; out . mX [ 10 ] = X_idx_1
; out . mX [ 11 ] = X_idx_1 ; out . mX [ 12 ] =
BLDC_Side_Inertias_BLDC_Shaft_wDer ; out . mX [ 13 ] = X_idx_1 ; out . mX [
14 ] = X_idx_1 ; out . mX [ 15 ] = X_idx_2 ; out . mX [ 16 ] = X_idx_1 ; out
. mX [ 17 ] = BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t ; out . mX [
18 ] = BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t *
294.11764705882354 ; out . mX [ 19 ] =
BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t *
BLDC_Side_Inertias_Clutch_Rotor_torsional_damper_t * 294.11764705882354 ; out
. mX [ 20 ] = X_idx_1 ; out . mX [ 21 ] = X_idx_1 ; out . mX [ 22 ] = X_idx_4
; out . mX [ 23 ] = X_idx_1 ; out . mX [ 24 ] = X_idx_1 ; out . mX [ 25 ] =
BLDC_Side_Inertias_BLDC_Shaft_wDer ; out . mX [ 26 ] = X_idx_1 ; out . mX [
27 ] = U_idx_0 ; out . mX [ 28 ] =
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; out . mX [ 29 ] =
X_idx_1 ; out . mX [ 30 ] = X_idx_3 ; out . mX [ 31 ] = X_idx_1 ; out . mX [
32 ] = X_idx_1 ; out . mX [ 33 ] = X_idx_3 ; out . mX [ 34 ] = X_idx_1 ; out
. mX [ 35 ] = X_idx_1 ; out . mX [ 36 ] = X_idx_1 ; out . mX [ 37 ] = -
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; out . mX [ 38 ] = -
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; out . mX [ 39 ] = -
BLDC_Side_Inertias_Ideal_Angular_Velocity_Source_t ; out . mX [ 40 ] =
X_idx_3 ; out . mX [ 41 ] = U_idx_0 ; ( void ) sys ; ( void ) t2 ; return 0 ;
}
