#include "ne_ds.h"
#include "ParallelTestBench_2ae6a85b_1_ds_sys_struct.h"
#include "ParallelTestBench_2ae6a85b_1_ds_obs_il.h"
#include "ParallelTestBench_2ae6a85b_1_ds.h"
#include "ParallelTestBench_2ae6a85b_1_ds_externals.h"
#include "ParallelTestBench_2ae6a85b_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T ParallelTestBench_2ae6a85b_1_ds_obs_il ( const NeDynamicSystem * sys
, const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector
out ; ( void ) t1 ; out = t2 -> mOBS_IL ; out . mX [ 0 ] = true ; out . mX [
1 ] = true ; out . mX [ 2 ] = true ; out . mX [ 3 ] = true ; out . mX [ 4 ] =
true ; out . mX [ 5 ] = true ; out . mX [ 6 ] = true ; out . mX [ 7 ] = true
; out . mX [ 8 ] = true ; out . mX [ 9 ] = true ; out . mX [ 10 ] = true ;
out . mX [ 11 ] = true ; out . mX [ 12 ] = true ; out . mX [ 13 ] = true ;
out . mX [ 14 ] = true ; out . mX [ 15 ] = true ; out . mX [ 16 ] = true ;
out . mX [ 17 ] = true ; out . mX [ 18 ] = true ; out . mX [ 19 ] = true ;
out . mX [ 20 ] = true ; out . mX [ 21 ] = true ; out . mX [ 22 ] = true ;
out . mX [ 23 ] = true ; out . mX [ 24 ] = true ; out . mX [ 25 ] = true ;
out . mX [ 26 ] = true ; out . mX [ 27 ] = true ; out . mX [ 28 ] = true ;
out . mX [ 29 ] = true ; out . mX [ 30 ] = true ; out . mX [ 31 ] = false ;
out . mX [ 32 ] = true ; out . mX [ 33 ] = true ; out . mX [ 34 ] = true ;
out . mX [ 35 ] = true ; out . mX [ 36 ] = true ; out . mX [ 37 ] = true ;
out . mX [ 38 ] = true ; out . mX [ 39 ] = true ; out . mX [ 40 ] = true ;
out . mX [ 41 ] = true ; out . mX [ 42 ] = true ; out . mX [ 43 ] = true ;
out . mX [ 44 ] = true ; out . mX [ 45 ] = true ; out . mX [ 46 ] = true ;
out . mX [ 47 ] = true ; out . mX [ 48 ] = false ; ( void ) sys ; ( void ) t2
; return 0 ; }
