#include "ParallelTestBench.h"
#include "rtwtypes.h"
#include "ParallelTestBench_private.h"
#include "ParallelTestBench_types.h"
#include "mwmathutil.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rt_logging_mmi.h"
#include "ParallelTestBench_capi.h"
#include "ParallelTestBench_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , &
stopRequested ) ; } rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "23.2 (R2023b) 01-Aug-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const
char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; PeriodicIndX rtPeriodicIndX ; PeriodicRngX
rtPeriodicRngX ; MassMatrix rtMassMatrix ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; real_T look2_binlxpw ( real_T u0 , real_T
u1 , const real_T bp0 [ ] , const real_T bp1 [ ] , const real_T table [ ] ,
const uint32_T maxIndex [ ] , uint32_T stride ) { real_T fractions [ 2 ] ;
real_T frac ; real_T yL_0d0 ; real_T yL_0d1 ; uint32_T bpIndices [ 2 ] ;
uint32_T bpIdx ; uint32_T iLeft ; uint32_T iRght ; if ( u0 <= bp0 [ 0U ] ) {
iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; }
else if ( u0 < bp0 [ maxIndex [ 0U ] ] ) { bpIdx = maxIndex [ 0U ] >> 1U ;
iLeft = 0U ; iRght = maxIndex [ 0U ] ; while ( iRght - iLeft > 1U ) { if ( u0
< bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = (
iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U
] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex [ 0U ] - 1U ; frac = ( u0 -
bp0 [ maxIndex [ 0U ] - 1U ] ) / ( bp0 [ maxIndex [ 0U ] ] - bp0 [ maxIndex [
0U ] - 1U ] ) ; } fractions [ 0U ] = frac ; bpIndices [ 0U ] = iLeft ; if (
u1 <= bp1 [ 0U ] ) { iLeft = 0U ; frac = ( u1 - bp1 [ 0U ] ) / ( bp1 [ 1U ] -
bp1 [ 0U ] ) ; } else if ( u1 < bp1 [ maxIndex [ 1U ] ] ) { bpIdx = maxIndex
[ 1U ] >> 1U ; iLeft = 0U ; iRght = maxIndex [ 1U ] ; while ( iRght - iLeft >
1U ) { if ( u1 < bp1 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; }
bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u1 - bp1 [ iLeft ] ) / ( bp1 [
iLeft + 1U ] - bp1 [ iLeft ] ) ; } else { iLeft = maxIndex [ 1U ] - 1U ; frac
= ( u1 - bp1 [ maxIndex [ 1U ] - 1U ] ) / ( bp1 [ maxIndex [ 1U ] ] - bp1 [
maxIndex [ 1U ] - 1U ] ) ; } bpIdx = iLeft * stride + bpIndices [ 0U ] ;
yL_0d0 = table [ bpIdx ] ; yL_0d0 += ( table [ bpIdx + 1U ] - yL_0d0 ) *
fractions [ 0U ] ; bpIdx += stride ; yL_0d1 = table [ bpIdx ] ; return ( ( (
table [ bpIdx + 1U ] - yL_0d1 ) * fractions [ 0U ] + yL_0d1 ) - yL_0d0 ) *
frac + yL_0d0 ; } real_T look2_binlcpw ( real_T u0 , real_T u1 , const real_T
bp0 [ ] , const real_T bp1 [ ] , const real_T table [ ] , const uint32_T
maxIndex [ ] , uint32_T stride ) { real_T fractions [ 2 ] ; real_T frac ;
real_T yL_0d0 ; real_T yL_0d1 ; uint32_T bpIndices [ 2 ] ; uint32_T bpIdx ;
uint32_T iLeft ; uint32_T iRght ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac
= 0.0 ; } else if ( u0 < bp0 [ maxIndex [ 0U ] ] ) { bpIdx = maxIndex [ 0U ]
>> 1U ; iLeft = 0U ; iRght = maxIndex [ 0U ] ; while ( iRght - iLeft > 1U ) {
if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx
= ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft +
1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex [ 0U ] - 1U ; frac = 1.0 ;
} fractions [ 0U ] = frac ; bpIndices [ 0U ] = iLeft ; if ( u1 <= bp1 [ 0U ]
) { iLeft = 0U ; frac = 0.0 ; } else if ( u1 < bp1 [ maxIndex [ 1U ] ] ) {
bpIdx = maxIndex [ 1U ] >> 1U ; iLeft = 0U ; iRght = maxIndex [ 1U ] ; while
( iRght - iLeft > 1U ) { if ( u1 < bp1 [ bpIdx ] ) { iRght = bpIdx ; } else {
iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u1 - bp1 [
iLeft ] ) / ( bp1 [ iLeft + 1U ] - bp1 [ iLeft ] ) ; } else { iLeft =
maxIndex [ 1U ] - 1U ; frac = 1.0 ; } bpIdx = iLeft * stride + bpIndices [ 0U
] ; yL_0d0 = table [ bpIdx ] ; yL_0d0 += ( table [ bpIdx + 1U ] - yL_0d0 ) *
fractions [ 0U ] ; bpIdx += stride ; yL_0d1 = table [ bpIdx ] ; return ( ( (
table [ bpIdx + 1U ] - yL_0d1 ) * fractions [ 0U ] + yL_0d1 ) - yL_0d0 ) *
frac + yL_0d0 ; } real_T look1_binlcapw ( real_T u0 , const real_T bp0 [ ] ,
const real_T table [ ] , uint32_T maxIndex ) { real_T frac ; real_T y ;
real_T yL_0d0 ; uint32_T bpIdx ; uint32_T iLeft ; uint32_T iRght ; if ( u0 <=
bp0 [ 0U ] ) { iLeft = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [ maxIndex ] )
{ bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght -
iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex ; frac =
0.0 ; } if ( iLeft == maxIndex ) { y = table [ iLeft ] ; } else { yL_0d0 =
table [ iLeft ] ; y = ( table [ iLeft + 1U ] - yL_0d0 ) * frac + yL_0d0 ; }
return y ; } real_T look2_binlcapw ( real_T u0 , real_T u1 , const real_T bp0
[ ] , const real_T bp1 [ ] , const real_T table [ ] , const uint32_T maxIndex
[ ] , uint32_T stride ) { real_T fractions [ 2 ] ; real_T frac ; real_T y ;
real_T yL_0d0 ; uint32_T bpIndices [ 2 ] ; uint32_T bpIdx ; uint32_T iLeft ;
uint32_T iRght ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = 0.0 ; } else
if ( u0 < bp0 [ maxIndex [ 0U ] ] ) { bpIdx = maxIndex [ 0U ] >> 1U ; iLeft =
0U ; iRght = maxIndex [ 0U ] ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [
bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght +
iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0
[ iLeft ] ) ; } else { iLeft = maxIndex [ 0U ] ; frac = 0.0 ; } fractions [
0U ] = frac ; bpIndices [ 0U ] = iLeft ; if ( u1 <= bp1 [ 0U ] ) { iLeft = 0U
; frac = 0.0 ; } else if ( u1 < bp1 [ maxIndex [ 1U ] ] ) { bpIdx = maxIndex
[ 1U ] >> 1U ; iLeft = 0U ; iRght = maxIndex [ 1U ] ; while ( iRght - iLeft >
1U ) { if ( u1 < bp1 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; }
bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u1 - bp1 [ iLeft ] ) / ( bp1 [
iLeft + 1U ] - bp1 [ iLeft ] ) ; } else { iLeft = maxIndex [ 1U ] ; frac =
0.0 ; } bpIdx = iLeft * stride + bpIndices [ 0U ] ; if ( bpIndices [ 0U ] ==
maxIndex [ 0U ] ) { y = table [ bpIdx ] ; } else { yL_0d0 = table [ bpIdx ] ;
y = ( table [ bpIdx + 1U ] - yL_0d0 ) * fractions [ 0U ] + yL_0d0 ; } if (
iLeft == maxIndex [ 1U ] ) { } else { bpIdx += stride ; if ( bpIndices [ 0U ]
== maxIndex [ 0U ] ) { yL_0d0 = table [ bpIdx ] ; } else { yL_0d0 = table [
bpIdx ] ; yL_0d0 += ( table [ bpIdx + 1U ] - yL_0d0 ) * fractions [ 0U ] ; }
y += ( yL_0d0 - y ) * frac ; } return y ; } uint32_T plook_binca ( real_T u ,
const real_T bp [ ] , uint32_T maxIndex , real_T * fraction ) { uint32_T
bpIndex ; if ( u <= bp [ 0U ] ) { bpIndex = 0U ; * fraction = 0.0 ; } else if
( u < bp [ maxIndex ] ) { bpIndex = binsearch_u32d ( u , bp , maxIndex >> 1U
, maxIndex ) ; * fraction = ( u - bp [ bpIndex ] ) / ( bp [ bpIndex + 1U ] -
bp [ bpIndex ] ) ; } else { bpIndex = maxIndex ; * fraction = 0.0 ; } return
bpIndex ; } real_T intrp2d_la_pw ( const uint32_T bpIndex [ ] , const real_T
frac [ ] , const real_T table [ ] , const uint32_T stride , const uint32_T
maxIndex [ ] ) { real_T y ; real_T yL_0d0 ; uint32_T offset_1d ; offset_1d =
bpIndex [ 1U ] * stride + bpIndex [ 0U ] ; if ( bpIndex [ 0U ] == maxIndex [
0U ] ) { y = table [ offset_1d ] ; } else { yL_0d0 = table [ offset_1d ] ; y
= ( table [ offset_1d + 1U ] - yL_0d0 ) * frac [ 0U ] + yL_0d0 ; } if (
bpIndex [ 1U ] == maxIndex [ 1U ] ) { } else { offset_1d += stride ; if (
bpIndex [ 0U ] == maxIndex [ 0U ] ) { yL_0d0 = table [ offset_1d ] ; } else {
yL_0d0 = table [ offset_1d ] ; yL_0d0 += ( table [ offset_1d + 1U ] - yL_0d0
) * frac [ 0U ] ; } y += ( yL_0d0 - y ) * frac [ 1U ] ; } return y ; }
uint32_T binsearch_u32d ( real_T u , const real_T bp [ ] , uint32_T
startIndex , uint32_T maxIndex ) { uint32_T bpIdx ; uint32_T bpIndex ;
uint32_T iRght ; bpIdx = startIndex ; bpIndex = 0U ; iRght = maxIndex ; while
( iRght - bpIndex > 1U ) { if ( u < bp [ bpIdx ] ) { iRght = bpIdx ; } else {
bpIndex = bpIdx ; } bpIdx = ( iRght + bpIndex ) >> 1U ; } return bpIndex ; }
void l55fduec5s ( real_T dyeje5qv3b , real_T * fin2uqwxpj ) { * fin2uqwxpj =
dyeje5qv3b ; } void MdlInitialize ( void ) { int_T tmp_e ; int_T tmp_f ;
int_T tmp_g ; int_T tmp_i ; int_T tmp_j ; int_T tmp_m ; boolean_T tmp ;
boolean_T tmp_p ; SimStruct * S ; void * diag ; rtDW . jclc1m30fx = 1 ; if (
ssIsFirstInitCond ( rtS ) ) { rtX . hjvfmqrotz = 0.0 ; tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . jclc1m30fx = ! tmp ; }
else { rtDW . jclc1m30fx = 1 ; } } rtX . hterznv3np = rtP .
SKP6485_omega_init ; tmp = false ; tmp_p = false ; if ( tmp_p || tmp ) {
tmp_e = strcmp ( ssGetSolverName ( rtS ) , "daessc" ) ; tmp_i = strcmp (
ssGetSolverName ( rtS ) , "ode14x" ) ; tmp_m = strcmp ( ssGetSolverName ( rtS
) , "ode15s" ) ; tmp_g = strcmp ( ssGetSolverName ( rtS ) , "ode1be" ) ;
tmp_j = strcmp ( ssGetSolverName ( rtS ) , "ode23t" ) ; tmp_f = strcmp (
ssGetSolverName ( rtS ) , "odeN" ) ; if ( ( boolean_T ) ( ( tmp_e != 0 ) & (
tmp_i != 0 ) & ( tmp_m != 0 ) & ( tmp_g != 0 ) & ( tmp_j != 0 ) & ( tmp_f !=
0 ) ) ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
 "physmod:simscape:engine:sli:SimscapeExecutionBlock:InconsistentSolversInModelRef"
, 2 , 3 , "ode14x" , 3 , "{daessc, ode14x, ode15s, ode1be, ode23t, odeN}" ) ;
rt_ssSet_slErrMsg ( S , diag ) ; } } tmp = false ; tmp_p = false ; if ( tmp_p
|| tmp ) { tmp_e = strcmp ( ssGetSolverName ( rtS ) , "daessc" ) ; tmp_i =
strcmp ( ssGetSolverName ( rtS ) , "ode14x" ) ; tmp_m = strcmp (
ssGetSolverName ( rtS ) , "ode15s" ) ; tmp_g = strcmp ( ssGetSolverName ( rtS
) , "ode1be" ) ; tmp_j = strcmp ( ssGetSolverName ( rtS ) , "ode23t" ) ;
tmp_f = strcmp ( ssGetSolverName ( rtS ) , "odeN" ) ; if ( ( boolean_T ) ( (
tmp_e != 0 ) & ( tmp_i != 0 ) & ( tmp_m != 0 ) & ( tmp_g != 0 ) & ( tmp_j !=
0 ) & ( tmp_f != 0 ) ) ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
 "physmod:simscape:engine:sli:SimscapeExecutionBlock:InconsistentSolversInModelRef"
, 2 , 3 , "ode14x" , 3 , "{daessc, ode14x, ode15s, ode1be, ode23t, odeN}" ) ;
rt_ssSet_slErrMsg ( S , diag ) ; } } tmp = false ; tmp_p = false ; if ( tmp_p
|| tmp ) { tmp_e = strcmp ( ssGetSolverName ( rtS ) , "daessc" ) ; tmp_i =
strcmp ( ssGetSolverName ( rtS ) , "ode14x" ) ; tmp_m = strcmp (
ssGetSolverName ( rtS ) , "ode15s" ) ; tmp_g = strcmp ( ssGetSolverName ( rtS
) , "ode1be" ) ; tmp_j = strcmp ( ssGetSolverName ( rtS ) , "ode23t" ) ;
tmp_f = strcmp ( ssGetSolverName ( rtS ) , "odeN" ) ; if ( ( boolean_T ) ( (
tmp_e != 0 ) & ( tmp_i != 0 ) & ( tmp_m != 0 ) & ( tmp_g != 0 ) & ( tmp_j !=
0 ) & ( tmp_f != 0 ) ) ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
 "physmod:simscape:engine:sli:SimscapeExecutionBlock:InconsistentSolversInModelRef"
, 2 , 3 , "ode14x" , 3 , "{daessc, ode14x, ode15s, ode1be, ode23t, odeN}" ) ;
rt_ssSet_slErrMsg ( S , diag ) ; } } rtX . it0jfj1ga4 = rtP . Integrator_IC ;
rtDW . b2vnrg1jny = 1 ; if ( ssIsFirstInitCond ( rtS ) ) { rtX . almmbag3ud =
0.0 ; tmp = slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . b2vnrg1jny = ! tmp ; }
else { rtDW . b2vnrg1jny = 1 ; } rtX . ju22bzmclv = 0.0 ; } rtX . pntygaqlkb
= rtP . SKP6485_theta_init ; rtDW . ewedjye3z0 = 1 ; if ( ssIsFirstInitCond (
rtS ) ) { tmp = slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . ewedjye3z0 = ! tmp ; }
else { rtDW . ewedjye3z0 = 1 ; } rtX . k0f2ivlpoh = 0.0 ; } rtDW . d24a3iy2yr
= 1 ; if ( ssIsFirstInitCond ( rtS ) ) { tmp = slIsRapidAcceleratorSimulating
( ) ; if ( tmp ) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW .
d24a3iy2yr = ! tmp ; } else { rtDW . d24a3iy2yr = 1 ; } } rtX . lcxpannrra =
rtP . Integrator_IC_ahzk3fe0wi ; rtB . olw4ikbxkg = rtP . Merge_InitialOutput
; rtB . mxxpbb3p2w = rtP . Merge1_InitialOutput ; rtB . beedf1ybtr = rtP .
Merge1_InitialOutput_ngwc5befhy ; rtB . hq4mhr11mq = rtP .
Merge2_InitialOutput ; rtB . mqvpg31jlu = rtP . Merge3_InitialOutput ; rtB .
a4b4l1echj = rtP . Merge_InitialOutput_htptbem0s2 ; rtB . ctnwpqizmx = rtP .
Merge_InitialOutput_l2wioipoqf ; rtDW . e3d0a5oz4x = rtP .
DiscreteTimeIntegrator_IC_nipgxr4w4m ; rtDW . pgf331hvhc = rtP .
DiscreteTimeIntegrator_IC ; rtDW . bxrcqiwwif = rtP .
DiscreteTimeIntegrator1_IC ; rtDW . hbjtppjnxc = rtP .
UnitDelay_InitialCondition ; rtDW . oajcj2f1f5 = rtP .
UnitDelay_InitialCondition_cpl50tg2hx ; rtB . hzgfvz42dk = rtP .
Merge1_InitialOutput_j4un0hwehg ; { int_T rootPeriodicContStateIndices [ 2 ]
= { 20 , 23 } ; real_T rootPeriodicContStateRanges [ 4 ] = { -
3.1415926535897931 , 3.1415926535897931 , 0.0 , 720.0 } ; ( void ) memcpy ( (
void * ) rtPeriodicIndX , rootPeriodicContStateIndices , 2 * sizeof ( int_T )
) ; ( void ) memcpy ( ( void * ) rtPeriodicRngX , rootPeriodicContStateRanges
, 4 * sizeof ( real_T ) ) ; } { static int_T modelMassMatrixIr [ 26 ] = { 0 ,
1 , 2 , 4 , 3 , 7 , 5 , 6 , 8 , 10 , 9 , 12 , 11 , 13 , 15 , 17 , 14 , 16 ,
18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 } ; static int_T modelMassMatrixJc [ 27
] = { 0 , 1 , 2 , 3 , 4 , 6 , 7 , 8 , 8 , 9 , 10 , 12 , 13 , 13 , 14 , 16 ,
17 , 18 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 } ; static real_T
modelMassMatrixPr [ 26 ] = { 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 ,
1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 ,
1.0 , 1.0 , 1.0 , 1.0 , 1.0 } ; ( void ) memcpy ( rtMassMatrix . ir ,
modelMassMatrixIr , 26 * sizeof ( int_T ) ) ; ( void ) memcpy ( rtMassMatrix
. jc , modelMassMatrixJc , 27 * sizeof ( int_T ) ) ; ( void ) memcpy (
rtMassMatrix . pr , modelMassMatrixPr , 26 * sizeof ( real_T ) ) ; } } void
MdlStart ( void ) { NeModelParameters modelParameters ; NeModelParameters
modelParameters_e ; NeModelParameters modelParameters_g ; NeModelParameters
modelParameters_i ; NeModelParameters modelParameters_m ; NeModelParameters
modelParameters_p ; NeslSimulationData * tmp_e ; NeslSimulator * tmp ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; NeuDiagnosticTree * diagnosticTree_e ; NeuDiagnosticTree * diagnosticTree_g
; NeuDiagnosticTree * diagnosticTree_i ; NeuDiagnosticTree * diagnosticTree_m
; NeuDiagnosticTree * diagnosticTree_p ; char * msg ; char * msg_e ; char *
msg_g ; char * msg_i ; char * msg_m ; char * msg_p ; real_T tmp_i ; int32_T
tmp_m ; boolean_T tmp_p ; boolean_T val ; { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtDW . dd5lqxkqw1 = - 1 ; rtDW . mjf1zdwwpb = - 1 ; rtDW . hsbxk4y5en = - 1
; rtDW . jsvlghnnou = - 1 ; { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = (
FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) {
ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
 "Simulink.signaleditorblock.SimulationData.getData('UGFyYWxsZWxUZXN0QmVuY2gvU2lnbmFsIEVkaXRvcjI=','1')"
; fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0 ; fromwksInfo
-> nDataPoints = 8 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0 ; rtDW . bw5y0i4p2l . TimePtr = fromwksInfo -> time ;
rtDW . bw5y0i4p2l . DataPtr = fromwksInfo -> data ; rtDW . bw5y0i4p2l .
RSimInfoPtr = fromwksInfo ; } rtDW . d05f353xni . PrevIndex = 0 ; } tmp =
nesl_lease_simulator (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration_1" , 0 , 0 ) ;
rtDW . j5biz3l2tk = ( void * ) tmp ; tmp_p = pointer_is_null ( rtDW .
j5biz3l2tk ) ; if ( tmp_p ) { ParallelTestBench_1d80934b_1_gateway ( ) ; tmp
= nesl_lease_simulator (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration_1" , 0 , 0 ) ;
rtDW . j5biz3l2tk = ( void * ) tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS
, "ParallelTestBench/BLDC Side Inertias/Solver Configuration_100" , ( void *
* ) ( & rtDW . j5biz3l2tk ) , 0U * sizeof ( real_T ) , nesl_save_simdata ,
nesl_restore_simdata ) ; tmp_e = nesl_create_simulation_data ( ) ; rtDW .
i1wgzi3jpe = ( void * ) tmp_e ; diagnosticManager = rtw_create_diagnostics (
) ; rtDW . bob4xgg01l = ( void * ) diagnosticManager ; modelParameters .
mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters . mSolverAbsTol = 0.001 ;
modelParameters . mSolverRelTol = 0.001 ; modelParameters .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO ; modelParameters . mStartTime =
0.0 ; modelParameters . mLoadInitialState = false ; modelParameters .
mUseSimState = false ; modelParameters . mLinTrimCompile = false ;
modelParameters . mLoggingMode = SSC_LOGGING_OFF ; modelParameters .
mRTWModifiedTimeStamp = 6.37797667E+8 ; modelParameters . mZcDisabled = true
; modelParameters . mUseModelRefSolver = false ; modelParameters .
mTargetFPGAHIL = false ; tmp_i = 0.001 ; modelParameters . mSolverTolerance =
tmp_i ; tmp_i = 5.0E-5 ; modelParameters . mFixedStepSize = tmp_i ; tmp_p =
false ; modelParameters . mVariableStepSolver = tmp_p ; tmp_p = false ;
modelParameters . mIsUsingODEN = tmp_p ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; val = ssGetGlobalInitialStatesAvailable
( rtS ) ; if ( tmp_p ) { val = ( val && ssIsFirstInitCond ( rtS ) ) ; }
modelParameters . mLoadInitialState = val ; modelParameters . mZcDisabled =
true ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . bob4xgg01l ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_m = nesl_initialize_simulator ( ( NeslSimulator * ) rtDW . j5biz3l2tk
, & modelParameters , diagnosticManager ) ; if ( tmp_m != 0 ) { tmp_p =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
tmp = nesl_lease_simulator (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration_1" , 1 , 0 ) ;
rtDW . mvpr3sjc4r = ( void * ) tmp ; tmp_p = pointer_is_null ( rtDW .
mvpr3sjc4r ) ; if ( tmp_p ) { ParallelTestBench_1d80934b_1_gateway ( ) ; tmp
= nesl_lease_simulator (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration_1" , 1 , 0 ) ;
rtDW . mvpr3sjc4r = ( void * ) tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS
, "ParallelTestBench/BLDC Side Inertias/Solver Configuration_110" , ( void *
* ) ( & rtDW . mvpr3sjc4r ) , 0U * sizeof ( real_T ) , nesl_save_simdata ,
nesl_restore_simdata ) ; tmp_e = nesl_create_simulation_data ( ) ; rtDW .
bakhwucptv = ( void * ) tmp_e ; diagnosticManager = rtw_create_diagnostics (
) ; rtDW . fzbhykh1xq = ( void * ) diagnosticManager ; modelParameters_p .
mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters_p . mSolverAbsTol = 0.001
; modelParameters_p . mSolverRelTol = 0.001 ; modelParameters_p .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO ; modelParameters_p . mStartTime =
0.0 ; modelParameters_p . mLoadInitialState = false ; modelParameters_p .
mUseSimState = false ; modelParameters_p . mLinTrimCompile = false ;
modelParameters_p . mLoggingMode = SSC_LOGGING_OFF ; modelParameters_p .
mRTWModifiedTimeStamp = 6.37797667E+8 ; modelParameters_p . mZcDisabled =
true ; modelParameters_p . mUseModelRefSolver = false ; modelParameters_p .
mTargetFPGAHIL = false ; tmp_i = 0.001 ; modelParameters_p . mSolverTolerance
= tmp_i ; tmp_i = 5.0E-5 ; modelParameters_p . mFixedStepSize = tmp_i ; tmp_p
= false ; modelParameters_p . mVariableStepSolver = tmp_p ; tmp_p = false ;
modelParameters_p . mIsUsingODEN = tmp_p ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; val = ssGetGlobalInitialStatesAvailable
( rtS ) ; if ( tmp_p ) { val = ( val && ssIsFirstInitCond ( rtS ) ) ; }
modelParameters_p . mLoadInitialState = val ; modelParameters_p . mZcDisabled
= true ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . fzbhykh1xq ;
diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_m = nesl_initialize_simulator ( ( NeslSimulator * )
rtDW . mvpr3sjc4r , & modelParameters_p , diagnosticManager ) ; if ( tmp_m !=
0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p
) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS
, msg_p ) ; } } tmp = nesl_lease_simulator (
"ParallelTestBench/TMotorU15/Solver Configuration_1" , 0 , 0 ) ; rtDW .
jeli2jkiuj = ( void * ) tmp ; tmp_p = pointer_is_null ( rtDW . jeli2jkiuj ) ;
if ( tmp_p ) { ParallelTestBench_2ae6a85b_1_gateway ( ) ; tmp =
nesl_lease_simulator ( "ParallelTestBench/TMotorU15/Solver Configuration_1" ,
0 , 0 ) ; rtDW . jeli2jkiuj = ( void * ) tmp ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"ParallelTestBench/TMotorU15/Solver Configuration_100" , ( void * * ) ( &
rtDW . jeli2jkiuj ) , 0U * sizeof ( real_T ) , nesl_save_simdata ,
nesl_restore_simdata ) ; tmp_e = nesl_create_simulation_data ( ) ; rtDW .
pzexosznjb = ( void * ) tmp_e ; diagnosticManager = rtw_create_diagnostics (
) ; rtDW . j1r4xwoi0i = ( void * ) diagnosticManager ; modelParameters_e .
mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters_e . mSolverAbsTol = 0.001
; modelParameters_e . mSolverRelTol = 0.001 ; modelParameters_e .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO ; modelParameters_e . mStartTime =
0.0 ; modelParameters_e . mLoadInitialState = false ; modelParameters_e .
mUseSimState = false ; modelParameters_e . mLinTrimCompile = false ;
modelParameters_e . mLoggingMode = SSC_LOGGING_OFF ; modelParameters_e .
mRTWModifiedTimeStamp = 6.37782416E+8 ; modelParameters_e . mZcDisabled =
true ; modelParameters_e . mUseModelRefSolver = false ; modelParameters_e .
mTargetFPGAHIL = false ; tmp_i = 0.001 ; modelParameters_e . mSolverTolerance
= tmp_i ; tmp_i = 5.0E-5 ; modelParameters_e . mFixedStepSize = tmp_i ; tmp_p
= false ; modelParameters_e . mVariableStepSolver = tmp_p ; tmp_p = false ;
modelParameters_e . mIsUsingODEN = tmp_p ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; val = ssGetGlobalInitialStatesAvailable
( rtS ) ; if ( tmp_p ) { val = ( val && ssIsFirstInitCond ( rtS ) ) ; }
modelParameters_e . mLoadInitialState = val ; modelParameters_e . mZcDisabled
= true ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . j1r4xwoi0i ;
diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_m = nesl_initialize_simulator ( ( NeslSimulator * )
rtDW . jeli2jkiuj , & modelParameters_e , diagnosticManager ) ; if ( tmp_m !=
0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p
) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ; ssSetErrorStatus ( rtS
, msg_e ) ; } } tmp = nesl_lease_simulator (
"ParallelTestBench/TMotorU15/Solver Configuration_1" , 1 , 0 ) ; rtDW .
boku4grpzp = ( void * ) tmp ; tmp_p = pointer_is_null ( rtDW . boku4grpzp ) ;
if ( tmp_p ) { ParallelTestBench_2ae6a85b_1_gateway ( ) ; tmp =
nesl_lease_simulator ( "ParallelTestBench/TMotorU15/Solver Configuration_1" ,
1 , 0 ) ; rtDW . boku4grpzp = ( void * ) tmp ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"ParallelTestBench/TMotorU15/Solver Configuration_110" , ( void * * ) ( &
rtDW . boku4grpzp ) , 0U * sizeof ( real_T ) , nesl_save_simdata ,
nesl_restore_simdata ) ; tmp_e = nesl_create_simulation_data ( ) ; rtDW .
iakvzasvoq = ( void * ) tmp_e ; diagnosticManager = rtw_create_diagnostics (
) ; rtDW . hrke45uylg = ( void * ) diagnosticManager ; modelParameters_i .
mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters_i . mSolverAbsTol = 0.001
; modelParameters_i . mSolverRelTol = 0.001 ; modelParameters_i .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO ; modelParameters_i . mStartTime =
0.0 ; modelParameters_i . mLoadInitialState = false ; modelParameters_i .
mUseSimState = false ; modelParameters_i . mLinTrimCompile = false ;
modelParameters_i . mLoggingMode = SSC_LOGGING_OFF ; modelParameters_i .
mRTWModifiedTimeStamp = 6.37782416E+8 ; modelParameters_i . mZcDisabled =
true ; modelParameters_i . mUseModelRefSolver = false ; modelParameters_i .
mTargetFPGAHIL = false ; tmp_i = 0.001 ; modelParameters_i . mSolverTolerance
= tmp_i ; tmp_i = 5.0E-5 ; modelParameters_i . mFixedStepSize = tmp_i ; tmp_p
= false ; modelParameters_i . mVariableStepSolver = tmp_p ; tmp_p = false ;
modelParameters_i . mIsUsingODEN = tmp_p ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; val = ssGetGlobalInitialStatesAvailable
( rtS ) ; if ( tmp_p ) { val = ( val && ssIsFirstInitCond ( rtS ) ) ; }
modelParameters_i . mLoadInitialState = val ; modelParameters_i . mZcDisabled
= true ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . hrke45uylg ;
diagnosticTree_i = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_m = nesl_initialize_simulator ( ( NeslSimulator * )
rtDW . boku4grpzp , & modelParameters_i , diagnosticManager ) ; if ( tmp_m !=
0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p
) { msg_i = rtw_diagnostics_msg ( diagnosticTree_i ) ; ssSetErrorStatus ( rtS
, msg_i ) ; } } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo *
) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS
, "from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
 "Simulink.signaleditorblock.SimulationData.getData('UGFyYWxsZWxUZXN0QmVuY2gvU2lnbmFsIEVkaXRvcjM=','1')"
; fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_lxog1ybljy ;
fromwksInfo -> nDataPoints = 11 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_ommwt43mku ; rtDW . jhtpgte2wi . TimePtr = fromwksInfo
-> time ; rtDW . jhtpgte2wi . DataPtr = fromwksInfo -> data ; rtDW .
jhtpgte2wi . RSimInfoPtr = fromwksInfo ; } rtDW . jcqddiyhqh . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
 "Simulink.signaleditorblock.SimulationData.getData('UGFyYWxsZWxUZXN0QmVuY2gvSWNlIFNwZWVk','1')"
; fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_n4yqnlgdbj ;
fromwksInfo -> nDataPoints = 13 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_pgpp53252z ; rtDW . hvxajhbgno . TimePtr = fromwksInfo
-> time ; rtDW . hvxajhbgno . DataPtr = fromwksInfo -> data ; rtDW .
hvxajhbgno . RSimInfoPtr = fromwksInfo ; } rtDW . eixvkodrjc . PrevIndex = 0
; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1
, sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName =
 "Simulink.signaleditorblock.SimulationData.getData('UGFyYWxsZWxUZXN0QmVuY2gvQkxEQyBTcGVlZA==','1')"
; fromwksInfo -> origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ;
fromwksInfo -> origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T )
; fromwksInfo -> data = ( void * ) rtP . fromWS_Signal1_Data0_prwgobmyi3 ;
fromwksInfo -> nDataPoints = 10 ; fromwksInfo -> time = ( double * ) rtP .
fromWS_Signal1_Time0_eamifk5xcs ; rtDW . fr1mfxzf32 . TimePtr = fromwksInfo
-> time ; rtDW . fr1mfxzf32 . DataPtr = fromwksInfo -> data ; rtDW .
fr1mfxzf32 . RSimInfoPtr = fromwksInfo ; } rtDW . dtpp4iwgtx . PrevIndex = 0
; } rtDW . g5r1yktyf0 = - 1 ; rtDW . k11uca0ow3 = - 1 ; tmp =
nesl_lease_simulator (
"ParallelTestBench/ICE Side Inertias/Solver Configuration_1" , 0 , 0 ) ; rtDW
. p2ezmuppnc = ( void * ) tmp ; tmp_p = pointer_is_null ( rtDW . p2ezmuppnc )
; if ( tmp_p ) { ParallelTestBench_59b138b3_1_gateway ( ) ; tmp =
nesl_lease_simulator (
"ParallelTestBench/ICE Side Inertias/Solver Configuration_1" , 0 , 0 ) ; rtDW
. p2ezmuppnc = ( void * ) tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS ,
"ParallelTestBench/ICE Side Inertias/Solver Configuration_100" , ( void * * )
( & rtDW . p2ezmuppnc ) , 0U * sizeof ( real_T ) , nesl_save_simdata ,
nesl_restore_simdata ) ; tmp_e = nesl_create_simulation_data ( ) ; rtDW .
hedrhiezbd = ( void * ) tmp_e ; diagnosticManager = rtw_create_diagnostics (
) ; rtDW . d21wvb0imp = ( void * ) diagnosticManager ; modelParameters_m .
mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters_m . mSolverAbsTol = 0.001
; modelParameters_m . mSolverRelTol = 0.001 ; modelParameters_m .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO ; modelParameters_m . mStartTime =
0.0 ; modelParameters_m . mLoadInitialState = false ; modelParameters_m .
mUseSimState = false ; modelParameters_m . mLinTrimCompile = false ;
modelParameters_m . mLoggingMode = SSC_LOGGING_OFF ; modelParameters_m .
mRTWModifiedTimeStamp = 6.37713896E+8 ; modelParameters_m . mZcDisabled =
true ; modelParameters_m . mUseModelRefSolver = false ; modelParameters_m .
mTargetFPGAHIL = false ; tmp_i = 0.001 ; modelParameters_m . mSolverTolerance
= tmp_i ; tmp_i = 5.0E-5 ; modelParameters_m . mFixedStepSize = tmp_i ; tmp_p
= false ; modelParameters_m . mVariableStepSolver = tmp_p ; tmp_p = false ;
modelParameters_m . mIsUsingODEN = tmp_p ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; val = ssGetGlobalInitialStatesAvailable
( rtS ) ; if ( tmp_p ) { val = ( val && ssIsFirstInitCond ( rtS ) ) ; }
modelParameters_m . mLoadInitialState = val ; modelParameters_m . mZcDisabled
= true ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . d21wvb0imp ;
diagnosticTree_m = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_m = nesl_initialize_simulator ( ( NeslSimulator * )
rtDW . p2ezmuppnc , & modelParameters_m , diagnosticManager ) ; if ( tmp_m !=
0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p
) { msg_m = rtw_diagnostics_msg ( diagnosticTree_m ) ; ssSetErrorStatus ( rtS
, msg_m ) ; } } tmp = nesl_lease_simulator (
"ParallelTestBench/ICE Side Inertias/Solver Configuration_1" , 1 , 0 ) ; rtDW
. dfna2oq4ag = ( void * ) tmp ; tmp_p = pointer_is_null ( rtDW . dfna2oq4ag )
; if ( tmp_p ) { ParallelTestBench_59b138b3_1_gateway ( ) ; tmp =
nesl_lease_simulator (
"ParallelTestBench/ICE Side Inertias/Solver Configuration_1" , 1 , 0 ) ; rtDW
. dfna2oq4ag = ( void * ) tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS ,
"ParallelTestBench/ICE Side Inertias/Solver Configuration_110" , ( void * * )
( & rtDW . dfna2oq4ag ) , 0U * sizeof ( real_T ) , nesl_save_simdata ,
nesl_restore_simdata ) ; tmp_e = nesl_create_simulation_data ( ) ; rtDW .
llxxjvefz5 = ( void * ) tmp_e ; diagnosticManager = rtw_create_diagnostics (
) ; rtDW . ayv1jfdv3n = ( void * ) diagnosticManager ; modelParameters_g .
mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters_g . mSolverAbsTol = 0.001
; modelParameters_g . mSolverRelTol = 0.001 ; modelParameters_g .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO ; modelParameters_g . mStartTime =
0.0 ; modelParameters_g . mLoadInitialState = false ; modelParameters_g .
mUseSimState = false ; modelParameters_g . mLinTrimCompile = false ;
modelParameters_g . mLoggingMode = SSC_LOGGING_OFF ; modelParameters_g .
mRTWModifiedTimeStamp = 6.37713896E+8 ; modelParameters_g . mZcDisabled =
true ; modelParameters_g . mUseModelRefSolver = false ; modelParameters_g .
mTargetFPGAHIL = false ; tmp_i = 0.001 ; modelParameters_g . mSolverTolerance
= tmp_i ; tmp_i = 5.0E-5 ; modelParameters_g . mFixedStepSize = tmp_i ; tmp_p
= false ; modelParameters_g . mVariableStepSolver = tmp_p ; tmp_p = false ;
modelParameters_g . mIsUsingODEN = tmp_p ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; val = ssGetGlobalInitialStatesAvailable
( rtS ) ; if ( tmp_p ) { val = ( val && ssIsFirstInitCond ( rtS ) ) ; }
modelParameters_g . mLoadInitialState = val ; modelParameters_g . mZcDisabled
= true ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ayv1jfdv3n ;
diagnosticTree_g = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_m = nesl_initialize_simulator ( ( NeslSimulator * )
rtDW . dfna2oq4ag , & modelParameters_g , diagnosticManager ) ; if ( tmp_m !=
0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p
) { msg_g = rtw_diagnostics_msg ( diagnosticTree_g ) ; ssSetErrorStatus ( rtS
, msg_g ) ; } } ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( void )
memset ( & ( ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> hlra0g33ul ) ,
1 , 2 * sizeof ( boolean_T ) ) ; rtDW . pitowdgxye = - 1 ; rtDW . fxz4zvrdnk
= - 1 ; rtDW . efurz0y3yi = - 1 ; MdlInitialize ( ) ; } void MdlOutputs (
int_T tid ) { real_T ob0w4htruw ; real_T flmahp1yqf ; real_T a1liohfrsm ;
real_T nxw4bomkqu ; LtiIcParams icParams ; NeslSimulationData *
simulationData ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree
* diagnosticTree ; NeuDiagnosticTree * diagnosticTree_e ; NeuDiagnosticTree *
diagnosticTree_g ; NeuDiagnosticTree * diagnosticTree_i ; NeuDiagnosticTree *
diagnosticTree_j ; NeuDiagnosticTree * diagnosticTree_m ; NeuDiagnosticTree *
diagnosticTree_p ; PmRealVector uPr ; PmRealVector xPr ; char * msg ; char *
msg_e ; char * msg_g ; char * msg_i ; char * msg_j ; char * msg_m ; char *
msg_p ; real_T hdsvmy35zz [ 12 ] ; real_T ncdbowaevb [ 11 ] ; real_T tmp_e [
9 ] ; real_T tmp_b [ 8 ] ; real_T tmp_j [ 8 ] ; real_T icVectorsStore [ 4 ] ;
real_T tmp [ 4 ] ; real_T tmp_c [ 4 ] ; real_T tmp_m [ 4 ] ; real_T fractions
[ 2 ] ; real_T fractions_e [ 2 ] ; real_T fractions_p [ 2 ] ; real_T mX [ 2 ]
; real_T bdhw0fpgj2 ; real_T c5xy34bpvg ; real_T e5n5p5jwen ; real_T
enkodslmzh ; real_T ha2dpbznfc ; real_T jjcpw4yqmp ; real_T kapenr40ft ;
real_T mX_e ; real_T mX_i ; real_T mX_p ; real_T mcm3lpg1nv ; real_T
nycml4qlmt ; real_T time ; real_T time_b ; real_T time_c ; real_T time_e ;
real_T time_f ; real_T time_g ; real_T time_i ; real_T time_j ; real_T time_k
; real_T time_m ; real_T time_n ; real_T time_p ; real_T u ; real_T u0 ;
real_T x ; real_T * icStorePtr ; int32_T i ; int32_T i_p ; int_T jc [ 3 ] ;
int_T tmp_f [ 3 ] ; int_T tmp_i [ 3 ] ; int_T tmp_n [ 3 ] ; int_T ir [ 2 ] ;
int_T jc_e [ 2 ] ; int_T jc_g [ 2 ] ; int_T jc_i [ 2 ] ; int_T jc_m [ 2 ] ;
int_T jc_p [ 2 ] ; int_T tmp_g [ 2 ] ; int_T tmp_k [ 2 ] ; int_T tmp_p [ 2 ]
; int_T ir_e ; int_T ir_p ; uint32_T bpIndices [ 2 ] ; uint32_T bpIndices_e [
2 ] ; uint32_T bpIndices_p [ 2 ] ; int8_T rtAction ; int8_T rtPrevAction ;
boolean_T first_output ; srClearBC ( rtDW . auskljzuj1 ) ; srClearBC ( rtDW .
cgq2mdkand ) ; srClearBC ( rtDW . fn0wimupx0 ) ; srClearBC ( rtDW .
byziukqaaz ) ; srClearBC ( rtDW . ns1xtz2b4p ) ; srClearBC ( rtDW .
okv3jznoxf ) ; srClearBC ( rtDW . miza0bwslu ) ; srClearBC ( rtDW .
l55fduec5sc . iibbwx5nxu ) ; srClearBC ( rtDW . lpzxn11asy ) ; srClearBC (
rtDW . jbdxmczt2f ) ; srClearBC ( rtDW . fe1jlxthwc ) ; srClearBC ( rtDW .
ifu2rmppxs ) ; srClearBC ( rtDW . iuutt5gbfx ) ; srClearBC ( rtDW .
pkdoeu3vac ) ; srClearBC ( rtDW . aeu2i4j0ln ) ; srClearBC ( rtDW .
bomurwpyov ) ; srClearBC ( rtDW . i0u0wqsccx ) ; srClearBC ( rtDW .
apx4aufauy ) ; srClearBC ( rtDW . fs2zaamasz ) ; srClearBC ( rtDW .
bnrzbkqovy ) ; srClearBC ( rtDW . mwn40uclws ) ; srClearBC ( rtDW .
pii1ltmep3 ) ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtDW . jclc1m30fx
!= 0 ) { rtX . hjvfmqrotz = rtB . h4fmwxdtzw ; } rtB . irttg002ix = rtX .
hjvfmqrotz ; } else { rtB . irttg002ix = rtX . hjvfmqrotz ; } rtB .
au0ix1q5sj = 1.0 / rtP . DatasheetBattery_Tc * rtB . irttg002ix ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } { real_T * pDataValues = ( real_T * )
rtDW . bw5y0i4p2l . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW .
bw5y0i4p2l . TimePtr ; int_T currTimeIndex = rtDW . d05f353xni . PrevIndex ;
real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t > pTimeValues [ 7 ] ) {
ob0w4htruw = 0.0 ; } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . bw5y0i4p2l . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . d05f353xni . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { ob0w4htruw =
pDataValues [ currTimeIndex ] ; } else { ob0w4htruw = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; ob0w4htruw = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } } if ( rtP . ManualSwitch3_CurrentSetting ==
1 ) { if ( ssGetTaskTime ( rtS , 0 ) < rtP . Step_Time ) { rtB . ix0ijjsadq =
rtP . Step_Y0 ; } else { rtB . ix0ijjsadq = rtP . Step_YFinal ; } } else {
rtB . ix0ijjsadq = ob0w4htruw ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) { if
( rtX . hterznv3np >= rtP . Int_UpperSat ) { if ( rtX . hterznv3np != rtP .
Int_UpperSat ) { rtX . hterznv3np = rtP . Int_UpperSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } else if ( ( rtX .
hterznv3np <= rtP . Int_LowerSat ) && ( rtX . hterznv3np != rtP .
Int_LowerSat ) ) { rtX . hterznv3np = rtP . Int_LowerSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . i4tiig10qa = rtX
. hterznv3np ; } else if ( rtX . hterznv3np >= rtP . Int_UpperSat ) { rtB .
i4tiig10qa = rtP . Int_UpperSat ; } else if ( rtX . hterznv3np <= rtP .
Int_LowerSat ) { rtB . i4tiig10qa = rtP . Int_LowerSat ; } else { rtB .
i4tiig10qa = rtX . hterznv3np ; } if ( rtDW . oudbjq0hed == 0.0 ) { rtDW .
oudbjq0hed = 1.0 ; rtX . eap5trepgw = rtB . i4tiig10qa ; } rtB . mxgpxbyfng [
0 ] = rtX . eap5trepgw ; rtB . mxgpxbyfng [ 1 ] = ( rtB . i4tiig10qa - rtX .
eap5trepgw ) * 1000.0 ; rtB . mxgpxbyfng [ 2 ] = 0.0 ; rtB . mxgpxbyfng [ 3 ]
= 0.0 ; simulationData = ( NeslSimulationData * ) rtDW . i1wgzi3jpe ; time =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time ; simulationData -> mData -> mContStates . mN
= 5 ; simulationData -> mData -> mContStates . mX = & rtX . dinj2vqkhf [ 0 ]
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = & rtDW . l5far1dd5s ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
bmyjja4qwv ; first_output = false ; simulationData -> mData -> mFoundZcEvents
= first_output ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; first_output = ( ssGetMdlInfoPtr ( rtS ) ->
mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = first_output ; simulationData -> mData ->
mIsSolverCheckingCIC = false ; first_output = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = first_output ;
simulationData -> mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian (
rtS ) != 0 ) ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_p [ 0 ] = 0 ; tmp [ 0 ] = rtB . mxgpxbyfng [ 0 ] ; tmp [ 1 ] =
rtB . mxgpxbyfng [ 1 ] ; tmp [ 2 ] = rtB . mxgpxbyfng [ 2 ] ; tmp [ 3 ] = rtB
. mxgpxbyfng [ 3 ] ; tmp_p [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = & tmp
[ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ; simulationData ->
mData -> mInputOffsets . mX = & tmp_p [ 0 ] ; simulationData -> mData ->
mOutputs . mN = 5 ; simulationData -> mData -> mOutputs . mX = & rtB .
kyvpkfkfuw [ 0 ] ; simulationData -> mData -> mTolerances . mN = 0 ;
simulationData -> mData -> mTolerances . mX = NULL ; simulationData -> mData
-> mCstateHasChanged = false ; time_p = ssGetTaskTime ( rtS , 0 ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_p ; simulationData -> mData -> mSampleHits . mN = 0 ;
simulationData -> mData -> mSampleHits . mX = NULL ; simulationData -> mData
-> mIsFundamentalSampleHit = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . bob4xgg01l ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . j5biz3l2tk ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) {
first_output = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if (
first_output ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } if ( ssIsMajorTimeStep ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } simulationData = (
NeslSimulationData * ) rtDW . bakhwucptv ; time_e = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_e ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . dgpg4jadhr ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = & rtDW . dorteqrwse ;
first_output = false ; simulationData -> mData -> mFoundZcEvents =
first_output ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; first_output = ( ssGetMdlInfoPtr ( rtS ) ->
mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = first_output ; simulationData -> mData ->
mIsSolverCheckingCIC = false ; simulationData -> mData ->
mIsComputingJacobian = false ; simulationData -> mData -> mIsEvaluatingF0 =
false ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_i [ 0 ] = 0 ; tmp_e [ 0 ] = rtB . mxgpxbyfng [ 0 ] ; tmp_e [ 1 ]
= rtB . mxgpxbyfng [ 1 ] ; tmp_e [ 2 ] = rtB . mxgpxbyfng [ 2 ] ; tmp_e [ 3 ]
= rtB . mxgpxbyfng [ 3 ] ; tmp_i [ 1 ] = 4 ; tmp_e [ 4 ] = rtB . kyvpkfkfuw [
0 ] ; tmp_e [ 5 ] = rtB . kyvpkfkfuw [ 1 ] ; tmp_e [ 6 ] = rtB . kyvpkfkfuw [
2 ] ; tmp_e [ 7 ] = rtB . kyvpkfkfuw [ 3 ] ; tmp_e [ 8 ] = rtB . kyvpkfkfuw [
4 ] ; tmp_i [ 2 ] = 9 ; simulationData -> mData -> mInputValues . mN = 9 ;
simulationData -> mData -> mInputValues . mX = & tmp_e [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 3 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_i [ 0 ] ; simulationData -> mData -> mOutputs . mN = 2 ;
simulationData -> mData -> mOutputs . mX = & rtB . m12o31k1vs [ 0 ] ;
simulationData -> mData -> mTolerances . mN = 0 ; simulationData -> mData ->
mTolerances . mX = NULL ; simulationData -> mData -> mCstateHasChanged =
false ; time_i = ssGetTaskTime ( rtS , 0 ) ; simulationData -> mData -> mTime
. mN = 1 ; simulationData -> mData -> mTime . mX = & time_i ; simulationData
-> mData -> mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits .
mX = NULL ; simulationData -> mData -> mIsFundamentalSampleHit = false ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . fzbhykh1xq ;
diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; i = ne_simulator_method ( ( NeslSimulator * ) rtDW .
mvpr3sjc4r , NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i
!= 0 ) { first_output = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ;
if ( first_output ) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ;
ssSetErrorStatus ( rtS , msg_p ) ; } } if ( ssIsMajorTimeStep ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . iavmf0c0td = rtP
. Dyno_Ratio * rtB . m12o31k1vs [ 0 ] ; if ( rtDW . a0ptfrtioc == 0.0 ) {
rtDW . a0ptfrtioc = 1.0 ; rtX . fpxoom5wcz = rtB . iavmf0c0td ; } rtB .
g1be22q2ab [ 0 ] = rtX . fpxoom5wcz ; rtB . g1be22q2ab [ 1 ] = ( rtB .
iavmf0c0td - rtX . fpxoom5wcz ) * 1000.0 ; rtB . g1be22q2ab [ 2 ] = 0.0 ; rtB
. g1be22q2ab [ 3 ] = 0.0 ; simulationData = ( NeslSimulationData * ) rtDW .
pzexosznjb ; time_m = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN
= 1 ; simulationData -> mData -> mTime . mX = & time_m ; simulationData ->
mData -> mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX =
& rtX . cmzleelpyc [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . aij0ldcei4 ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . n0n2vuipdf ; first_output = false ;
simulationData -> mData -> mFoundZcEvents = first_output ; simulationData ->
mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; first_output = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = first_output ;
simulationData -> mData -> mIsSolverCheckingCIC = false ; first_output =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = first_output ; simulationData -> mData ->
mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
simulationData -> mData -> mIsSolverRequestingReset = false ; simulationData
-> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_g [
0 ] = 0 ; tmp_m [ 0 ] = rtB . g1be22q2ab [ 0 ] ; tmp_m [ 1 ] = rtB .
g1be22q2ab [ 1 ] ; tmp_m [ 2 ] = rtB . g1be22q2ab [ 2 ] ; tmp_m [ 3 ] = rtB .
g1be22q2ab [ 3 ] ; tmp_g [ 1 ] = 4 ; simulationData -> mData -> mInputValues
. mN = 4 ; simulationData -> mData -> mInputValues . mX = & tmp_m [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 2 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_g [ 0 ] ; simulationData -> mData -> mOutputs .
mN = 4 ; simulationData -> mData -> mOutputs . mX = & rtB . akjx0hsfge [ 0 ]
; simulationData -> mData -> mTolerances . mN = 0 ; simulationData -> mData
-> mTolerances . mX = NULL ; simulationData -> mData -> mCstateHasChanged =
false ; time_g = ssGetTaskTime ( rtS , 0 ) ; simulationData -> mData -> mTime
. mN = 1 ; simulationData -> mData -> mTime . mX = & time_g ; simulationData
-> mData -> mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits .
mX = NULL ; simulationData -> mData -> mIsFundamentalSampleHit = false ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . j1r4xwoi0i ;
diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; i = ne_simulator_method ( ( NeslSimulator * ) rtDW .
jeli2jkiuj , NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i
!= 0 ) { first_output = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ;
if ( first_output ) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ;
ssSetErrorStatus ( rtS , msg_e ) ; } } if ( ssIsMajorTimeStep ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } simulationData = (
NeslSimulationData * ) rtDW . iakvzasvoq ; time_j = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_j ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . cfefmj5zwg ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = & rtDW . ke0t5lasbz ;
first_output = false ; simulationData -> mData -> mFoundZcEvents =
first_output ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; first_output = ( ssGetMdlInfoPtr ( rtS ) ->
mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = first_output ; simulationData -> mData ->
mIsSolverCheckingCIC = false ; simulationData -> mData ->
mIsComputingJacobian = false ; simulationData -> mData -> mIsEvaluatingF0 =
false ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_f [ 0 ] = 0 ; tmp_j [ 0 ] = rtB . g1be22q2ab [ 0 ] ; tmp_j [ 1 ]
= rtB . g1be22q2ab [ 1 ] ; tmp_j [ 2 ] = rtB . g1be22q2ab [ 2 ] ; tmp_j [ 3 ]
= rtB . g1be22q2ab [ 3 ] ; tmp_f [ 1 ] = 4 ; tmp_j [ 4 ] = rtB . akjx0hsfge [
0 ] ; tmp_j [ 5 ] = rtB . akjx0hsfge [ 1 ] ; tmp_j [ 6 ] = rtB . akjx0hsfge [
2 ] ; tmp_j [ 7 ] = rtB . akjx0hsfge [ 3 ] ; tmp_f [ 2 ] = 8 ; simulationData
-> mData -> mInputValues . mN = 8 ; simulationData -> mData -> mInputValues .
mX = & tmp_j [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 3 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_f [ 0 ] ;
simulationData -> mData -> mOutputs . mN = 2 ; simulationData -> mData ->
mOutputs . mX = & rtB . a51hahehmm [ 0 ] ; simulationData -> mData ->
mTolerances . mN = 0 ; simulationData -> mData -> mTolerances . mX = NULL ;
simulationData -> mData -> mCstateHasChanged = false ; time_f = ssGetTaskTime
( rtS , 0 ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData ->
mData -> mTime . mX = & time_f ; simulationData -> mData -> mSampleHits . mN
= 0 ; simulationData -> mData -> mSampleHits . mX = NULL ; simulationData ->
mData -> mIsFundamentalSampleHit = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . hrke45uylg ; diagnosticTree_i =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . boku4grpzp ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) {
first_output = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if (
first_output ) { msg_i = rtw_diagnostics_msg ( diagnosticTree_i ) ;
ssSetErrorStatus ( rtS , msg_i ) ; } } if ( ssIsMajorTimeStep ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } { real_T * pDataValues
= ( real_T * ) rtDW . jhtpgte2wi . DataPtr ; real_T * pTimeValues = ( real_T
* ) rtDW . jhtpgte2wi . TimePtr ; int_T currTimeIndex = rtDW . jcqddiyhqh .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t > pTimeValues [ 10
] ) { flmahp1yqf = 0.0 ; } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . jhtpgte2wi . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . jcqddiyhqh . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { flmahp1yqf =
pDataValues [ currTimeIndex ] ; } else { flmahp1yqf = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; flmahp1yqf = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } } if ( rtP . ManualSwitch2_CurrentSetting ==
1 ) { rtB . ivfnl2doo0 = flmahp1yqf ; } else { rtB . ivfnl2doo0 = rtP .
Constant4_Value_o2jsgu5bg0 ; } rtB . cftqthzuab = rtB . m12o31k1vs [ 1 ] +
rtB . ivfnl2doo0 ; rtB . e4wlihh0yp = rtB . a51hahehmm [ 1 ] + rtB .
cftqthzuab ; { real_T * pDataValues = ( real_T * ) rtDW . hvxajhbgno .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . hvxajhbgno . TimePtr ;
int_T currTimeIndex = rtDW . eixvkodrjc . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t > pTimeValues [ 12 ] ) { rtB . m3wbmdk01n
= 0.0 ; } else { int numPoints , lastPoint ; FWksInfo * fromwksInfo = (
FWksInfo * ) rtDW . hvxajhbgno . RSimInfoPtr ; numPoints = fromwksInfo ->
nDataPoints ; lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) {
currTimeIndex = 0 ; } else if ( t >= pTimeValues [ lastPoint ] ) {
currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues [ currTimeIndex
] ) { while ( t < pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } }
else { while ( t >= pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ;
} } } rtDW . eixvkodrjc . PrevIndex = currTimeIndex ; { real_T t1 =
pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ]
; if ( t1 == t2 ) { if ( t < t1 ) { rtB . m3wbmdk01n = pDataValues [
currTimeIndex ] ; } else { rtB . m3wbmdk01n = pDataValues [ currTimeIndex + 1
] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ;
real_T d1 ; real_T d2 ; int_T TimeIndex = currTimeIndex ; d1 = pDataValues [
TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; rtB . m3wbmdk01n = (
real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } }
} } { real_T * pDataValues = ( real_T * ) rtDW . fr1mfxzf32 . DataPtr ;
real_T * pTimeValues = ( real_T * ) rtDW . fr1mfxzf32 . TimePtr ; int_T
currTimeIndex = rtDW . dtpp4iwgtx . PrevIndex ; real_T t = ssGetTaskTime (
rtS , 0 ) ; if ( t > pTimeValues [ 9 ] ) { rtB . cq2d2pwdt4 = 0.0 ; } else {
int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
fr1mfxzf32 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . dtpp4iwgtx .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { rtB . cq2d2pwdt4 = pDataValues [ currTimeIndex ] ; } else { rtB .
cq2d2pwdt4 = pDataValues [ currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2
- t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T
TimeIndex = currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues
[ TimeIndex + 1 ] ; rtB . cq2d2pwdt4 = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } rtPrevAction = rtDW .
g5r1yktyf0 ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtAction = ( int8_T ) !
( rtB . ix0ijjsadq > 0.0 ) ; rtDW . g5r1yktyf0 = rtAction ; } else { rtAction
= rtDW . g5r1yktyf0 ; } if ( rtPrevAction != rtAction ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtPrevAction == 0 )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . k11uca0ow3 = -
1 ; } } if ( rtAction == 0 ) { rtPrevAction = rtDW . k11uca0ow3 ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB . m3wbmdk01n
> rtB . cq2d2pwdt4 ) ; rtDW . k11uca0ow3 = rtAction ; } else { rtAction =
rtDW . k11uca0ow3 ; } if ( rtPrevAction != rtAction ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } if ( rtAction == 0 ) {
rtB . itamdryrgl = rtB . m3wbmdk01n ; rtB . mxxpbb3p2w = rtB . itamdryrgl ;
rtB . olw4ikbxkg = rtB . itamdryrgl ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . fn0wimupx0 ) ; } } else { rtB . jhwxdwr1el = rtB .
cq2d2pwdt4 ; rtB . mxxpbb3p2w = rtB . jhwxdwr1el ; rtB . olw4ikbxkg = rtB .
jhwxdwr1el ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
byziukqaaz ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . lxakjhp4ut
= rtB . mxxpbb3p2w ; rtB . cxcy4qomm3 = rtB . olw4ikbxkg ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . ns1xtz2b4p ) ; } }
else { rtB . cxcy4qomm3 = rtB . m3wbmdk01n ; rtB . lxakjhp4ut = rtB .
cq2d2pwdt4 ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
okv3jznoxf ) ; } } if ( rtP . ManualSwitch_CurrentSetting == 1 ) { rtB .
gmqd0r1s5n = rtP . Constant1_Value_bpuwj1x24m ; } else { rtB . gmqd0r1s5n =
rtB . cxcy4qomm3 ; } rtB . dnk2tludg2 = 0.10471975511965977 * rtB .
gmqd0r1s5n ; if ( rtDW . pyb4n2kdpt == 0.0 ) { rtDW . pyb4n2kdpt = 1.0 ; rtX
. itgqcjsbx5 = rtB . dnk2tludg2 ; } rtB . jhai0ek5up [ 0 ] = rtX . itgqcjsbx5
; rtB . jhai0ek5up [ 1 ] = ( rtB . dnk2tludg2 - rtX . itgqcjsbx5 ) * 1000.0 ;
rtB . jhai0ek5up [ 2 ] = 0.0 ; rtB . jhai0ek5up [ 3 ] = 0.0 ; simulationData
= ( NeslSimulationData * ) rtDW . hedrhiezbd ; time_c = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_c ; simulationData -> mData -> mContStates . mN = 4 ;
simulationData -> mData -> mContStates . mX = & rtX . o3f51d5jei [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . cern2voaws ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
k5a5eyevvp ; first_output = false ; simulationData -> mData -> mFoundZcEvents
= first_output ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; first_output = ( ssGetMdlInfoPtr ( rtS ) ->
mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = first_output ; simulationData -> mData ->
mIsSolverCheckingCIC = false ; first_output = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = first_output ;
simulationData -> mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian (
rtS ) != 0 ) ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_k [ 0 ] = 0 ; tmp_c [ 0 ] = rtB . jhai0ek5up [ 0 ] ; tmp_c [ 1 ]
= rtB . jhai0ek5up [ 1 ] ; tmp_c [ 2 ] = rtB . jhai0ek5up [ 2 ] ; tmp_c [ 3 ]
= rtB . jhai0ek5up [ 3 ] ; tmp_k [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_c [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_k [ 0 ] ;
simulationData -> mData -> mOutputs . mN = 4 ; simulationData -> mData ->
mOutputs . mX = & rtB . nwoetve5i4 [ 0 ] ; simulationData -> mData ->
mTolerances . mN = 0 ; simulationData -> mData -> mTolerances . mX = NULL ;
simulationData -> mData -> mCstateHasChanged = false ; time_k = ssGetTaskTime
( rtS , 0 ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData ->
mData -> mTime . mX = & time_k ; simulationData -> mData -> mSampleHits . mN
= 0 ; simulationData -> mData -> mSampleHits . mX = NULL ; simulationData ->
mData -> mIsFundamentalSampleHit = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . d21wvb0imp ; diagnosticTree_m =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . p2ezmuppnc ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) {
first_output = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if (
first_output ) { msg_m = rtw_diagnostics_msg ( diagnosticTree_m ) ;
ssSetErrorStatus ( rtS , msg_m ) ; } } if ( ssIsMajorTimeStep ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } simulationData = (
NeslSimulationData * ) rtDW . llxxjvefz5 ; time_b = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_b ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . htxaynbdci ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = & rtDW . l4dxiaonqg ;
first_output = false ; simulationData -> mData -> mFoundZcEvents =
first_output ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; first_output = ( ssGetMdlInfoPtr ( rtS ) ->
mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = first_output ; simulationData -> mData ->
mIsSolverCheckingCIC = false ; simulationData -> mData ->
mIsComputingJacobian = false ; simulationData -> mData -> mIsEvaluatingF0 =
false ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_n [ 0 ] = 0 ; tmp_b [ 0 ] = rtB . jhai0ek5up [ 0 ] ; tmp_b [ 1 ]
= rtB . jhai0ek5up [ 1 ] ; tmp_b [ 2 ] = rtB . jhai0ek5up [ 2 ] ; tmp_b [ 3 ]
= rtB . jhai0ek5up [ 3 ] ; tmp_n [ 1 ] = 4 ; tmp_b [ 4 ] = rtB . nwoetve5i4 [
0 ] ; tmp_b [ 5 ] = rtB . nwoetve5i4 [ 1 ] ; tmp_b [ 6 ] = rtB . nwoetve5i4 [
2 ] ; tmp_b [ 7 ] = rtB . nwoetve5i4 [ 3 ] ; tmp_n [ 2 ] = 8 ; simulationData
-> mData -> mInputValues . mN = 8 ; simulationData -> mData -> mInputValues .
mX = & tmp_b [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 3 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_n [ 0 ] ;
simulationData -> mData -> mOutputs . mN = 1 ; simulationData -> mData ->
mOutputs . mX = & rtB . ea1x0lvxve ; simulationData -> mData -> mTolerances .
mN = 0 ; simulationData -> mData -> mTolerances . mX = NULL ; simulationData
-> mData -> mCstateHasChanged = false ; time_n = ssGetTaskTime ( rtS , 0 ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_n ; simulationData -> mData -> mSampleHits . mN = 0 ;
simulationData -> mData -> mSampleHits . mX = NULL ; simulationData -> mData
-> mIsFundamentalSampleHit = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ayv1jfdv3n ; diagnosticTree_g =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . dfna2oq4ag ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( i != 0 ) {
first_output = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if (
first_output ) { msg_g = rtw_diagnostics_msg ( diagnosticTree_g ) ;
ssSetErrorStatus ( rtS , msg_g ) ; } } if ( ssIsMajorTimeStep ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtPrevAction = rtDW .
pitowdgxye ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { if ( ( rtB . ix0ijjsadq
== 1.0 ) && ( rtB . e4wlihh0yp < 40.0 ) ) { rtAction = 0 ; } else if ( ( rtB
. ix0ijjsadq == 1.0 ) && ( rtB . e4wlihh0yp > 40.0 ) ) { rtAction = 1 ; }
else { rtAction = 2 ; } rtDW . pitowdgxye = rtAction ; } else { rtAction =
rtDW . pitowdgxye ; } if ( rtPrevAction != rtAction ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( ssGetTaskTime ( rtS
, 0 ) == ssGetTStart ( rtS ) ) { ( void ) memset ( & ( ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> hlra0g33ul ) , 1 , 2 * sizeof ( boolean_T
) ) ; } if ( rtPrevAction == 0 ) { ( void ) memset ( & ( ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> hlra0g33ul ) , 1 , 2 * sizeof ( boolean_T
) ) ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { if
( ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } ( void ) memset ( & (
( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> hlra0g33ul ) , 0 , 2 *
sizeof ( boolean_T ) ) ; } rtB . fxbpkblr2q = muDoubleScalarMax ( rtB .
ea1x0lvxve , rtB . m12o31k1vs [ 0 ] ) ; if ( rtDW . hvgg13kj3s == 0.0 ) {
rtDW . hvgg13kj3s = 1.0 ; rtX . hlra0g33ul = rtB . fxbpkblr2q ; } rtB .
m4c5zvfilf [ 0 ] = rtX . hlra0g33ul ; rtB . m4c5zvfilf [ 1 ] = ( rtB .
fxbpkblr2q - rtX . hlra0g33ul ) * 1000.0 ; rtB . m4c5zvfilf [ 2 ] = 0.0 ; rtB
. m4c5zvfilf [ 3 ] = 0.0 ; rtB . otltqoc5al = 0.0 ; rtB . otltqoc5al += rtB .
m4c5zvfilf [ 0 ] ; rtB . beedf1ybtr = rtB . otltqoc5al ; rtB . hq4mhr11mq =
rtB . otltqoc5al ; rtB . mqvpg31jlu = rtB . otltqoc5al ; rtB . ev0c2l5p3p =
0.0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . a4b4l1echj = rtB .
ev0c2l5p3p + rtB . e4wlihh0yp ; x = rtX . mw03mcasf2 ; first_output = false ;
if ( rtDW . k1fhodjxic == 0.0 ) { rtDW . k1fhodjxic = 1.0 ; first_output =
true ; } if ( ( boolean_T ) ( first_output | rtDW . iy5ftg1sqh ) ) { xPr . mN
= 1 ; xPr . mX = & x ; rtDW . iy5ftg1sqh = false ; u = rtB . m4c5zvfilf [ 0 ]
; uPr . mN = 1 ; uPr . mX = & u ; icParams . mFirstSolve . mStatesPattern .
mNumCol = 2 ; icParams . mFirstSolve . mStatesPattern . mNumRow = 2 ; ir [ 0
] = 1 ; ir [ 1 ] = 0 ; icParams . mFirstSolve . mStatesPattern . mIr = & ir [
0 ] ; jc [ 0 ] = 0 ; jc [ 1 ] = 1 ; jc [ 2 ] = 2 ; icParams . mFirstSolve .
mStatesPattern . mJc = & jc [ 0 ] ; icParams . mFirstSolve . mStatesPr . mN =
2 ; mX [ 0 ] = 1.0 ; mX [ 1 ] = 1.0 ; icParams . mFirstSolve . mStatesPr . mX
= & mX [ 0 ] ; icParams . mFirstSolve . mInputsPattern . mNumCol = 1 ;
icParams . mFirstSolve . mInputsPattern . mNumRow = 2 ; jc_p [ 0 ] = 0 ; jc_p
[ 1 ] = 0 ; icParams . mFirstSolve . mInputsPattern . mJc = & jc_p [ 0 ] ;
icParams . mFirstSolve . mInputsPr . mN = 0 ; icParams . mSecondSolve .
mStatesPattern . mNumCol = 1 ; icParams . mSecondSolve . mStatesPattern .
mNumRow = 1 ; ir_p = 0 ; icParams . mSecondSolve . mStatesPattern . mIr = &
ir_p ; jc_e [ 0 ] = 0 ; jc_e [ 1 ] = 1 ; icParams . mSecondSolve .
mStatesPattern . mJc = & jc_e [ 0 ] ; icParams . mSecondSolve . mStatesPr .
mN = 1 ; mX_p = 1.0 ; icParams . mSecondSolve . mStatesPr . mX = & mX_p ;
icParams . mSecondSolve . mInputsPattern . mNumCol = 1 ; icParams .
mSecondSolve . mInputsPattern . mNumRow = 1 ; jc_i [ 0 ] = 0 ; jc_i [ 1 ] = 0
; icParams . mSecondSolve . mInputsPattern . mJc = & jc_i [ 0 ] ; icParams .
mSecondSolve . mInputsPr . mN = 0 ; icParams . mDcSolve . mAPattern . mNumCol
= 1 ; icParams . mDcSolve . mAPattern . mNumRow = 1 ; jc_m [ 0 ] = 0 ; jc_m [
1 ] = 0 ; icParams . mDcSolve . mAPattern . mJc = & jc_m [ 0 ] ; icParams .
mDcSolve . mAPr . mN = 0 ; icParams . mDcSolve . mBPattern . mNumCol = 1 ;
icParams . mDcSolve . mBPattern . mNumRow = 1 ; ir_e = 0 ; icParams .
mDcSolve . mBPattern . mIr = & ir_e ; jc_g [ 0 ] = 0 ; jc_g [ 1 ] = 1 ;
icParams . mDcSolve . mBPattern . mJc = & jc_g [ 0 ] ; icParams . mDcSolve .
mBPr . mN = 1 ; mX_e = 1.0 ; icParams . mDcSolve . mBPr . mX = & mX_e ;
icParams . mDcSolve . mFa . mN = 1 ; mX_i = 0.0 ; icParams . mDcSolve . mFa .
mX = & mX_i ; icParams . mResTol = 1.0E-9 ; icParams . mDoDC = false ;
icStorePtr = & icVectorsStore [ 0 ] ; ParallelTestBench_62883109_1_ic_fcn (
icStorePtr ) ; icParams . mGuess . mN = 1 ; icParams . mGuess . mX = &
icVectorsStore [ 0 ] ; icParams . mFirstSolve . mConsts . mN = 2 ; icParams .
mFirstSolve . mConsts . mX = & icVectorsStore [ 1 ] ; icParams . mSecondSolve
. mConsts . mN = 1 ; icParams . mSecondSolve . mConsts . mX = &
icVectorsStore [ 3 ] ; diagnosticManager = rtw_create_diagnostics ( ) ;
diagnosticTree_j = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; first_output = cgIcSolve ( & xPr , & uPr , & icParams ,
diagnosticManager ) ; if ( ! first_output ) { first_output =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( first_output ) {
msg_j = rtw_diagnostics_msg ( diagnosticTree_j ) ; ssSetErrorStatus ( rtS ,
msg_j ) ; } } neu_destroy_diagnostic_manager ( diagnosticManager ) ; rtB .
hg3boogiog = x ; rtX . mw03mcasf2 = x ; } else { rtB . hg3boogiog = rtX .
mw03mcasf2 ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
auskljzuj1 ) ; } break ; case 1 : break ; default : rtB . beedf1ybtr = rtB .
ea1x0lvxve ; rtB . hq4mhr11mq = rtB . m12o31k1vs [ 0 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . mqvpg31jlu = rtP . Constant_Value ; rtB . a4b4l1echj
= rtP . Constant1_Value ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . cgq2mdkand ) ; } break ; } if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { } jjcpw4yqmp = trunc ( rtB . gmqd0r1s5n ) ; e5n5p5jwen = trunc ( rtB
. m12o31k1vs [ 0 ] ) ; rtPrevAction = rtDW . fxz4zvrdnk ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( ( jjcpw4yqmp != 0.0 ) && ( e5n5p5jwen
!= 0.0 ) ) { rtAction = 0 ; } else if ( ( jjcpw4yqmp == 0.0 ) && ( e5n5p5jwen
== 0.0 ) ) { rtAction = 1 ; } else { rtAction = 2 ; } rtDW . fxz4zvrdnk =
rtAction ; } else { rtAction = rtDW . fxz4zvrdnk ; } if ( rtPrevAction !=
rtAction ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } switch (
rtAction ) { case 0 : rtPrevAction = rtDW . mjf1zdwwpb ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtB . a4b4l1echj
== 0.0 ) ; rtDW . mjf1zdwwpb = rtAction ; } else { rtAction = rtDW .
mjf1zdwwpb ; } if ( rtPrevAction != rtAction ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } if ( rtAction == 0 ) {
bpIndices [ 1U ] = plook_binca ( jjcpw4yqmp , rtP . uDLookupTable2_bp02Data ,
5U , & e5n5p5jwen ) ; fractions [ 1U ] = e5n5p5jwen ; for ( i = 0 ; i < 12 ;
i ++ ) { bpIndices [ 0U ] = plook_binca ( rtP . Trq_BP [ ( int32_T ) rtConstP
. rtw_collapsed_sub_expr_FucNF5IedxlzbnilUMUgVH_1 [ i ] - 1 ] , rtP .
uDLookupTable2_bp01Data , 9U , & e5n5p5jwen ) ; fractions [ 0U ] = e5n5p5jwen
; hdsvmy35zz [ i ] = intrp2d_la_pw ( bpIndices , fractions , rtP .
uDLookupTable2_tableData , 10U , rtP . uDLookupTable2_maxIndex ) ; }
jjcpw4yqmp = hdsvmy35zz [ 0 ] ; for ( i = 0 ; i < 11 ; i ++ ) { jjcpw4yqmp =
muDoubleScalarMin ( jjcpw4yqmp , hdsvmy35zz [ i + 1 ] ) ; } rtB . eqqz4ci0tv
= jjcpw4yqmp ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ifu2rmppxs ) ; } } else { bpIndices [ 1U ] = plook_binca ( jjcpw4yqmp , rtP .
Spd_BP , 6U , & e5n5p5jwen ) ; fractions [ 1U ] = e5n5p5jwen ; for ( i = 0 ;
i < 12 ; i ++ ) { bpIndices [ 0U ] = plook_binca ( rtP . Trq_BP [ ( int32_T )
rtConstP . rtw_collapsed_sub_expr_FucNF5IedxlzbnilUMUgVH_1 [ i ] - 1 ] , rtP
. Trq_BP , 11U , & e5n5p5jwen ) ; fractions [ 0U ] = e5n5p5jwen ; hdsvmy35zz
[ i ] = intrp2d_la_pw ( bpIndices , fractions , rtP . Fuel_MapE , 12U , rtP .
uDLookupTable_maxIndex_amrotqgr0w ) ; } i = 0 ; for ( i_p = 0 ; i_p < 12 ;
i_p ++ ) { i = ( int32_T ) ( ( uint32_T ) ( hdsvmy35zz [ i_p ] > rtP .
Constant4_Value_fecgcw2rtb ) + ( uint32_T ) i ) ; } rtB . oudpsgugrl = (
uint8_T ) i ; if ( rtB . oudpsgugrl > rtP . Switch3_Threshold ) { rtB .
frdjc0ipbc = rtB . oudpsgugrl ; } else { rtB . frdjc0ipbc = rtP .
Constant5_Value_axuapffnub ; } e5n5p5jwen = - 0.0 ; for ( i = 0 ; i < 12 ; i
++ ) { e5n5p5jwen += hdsvmy35zz [ i ] ; } rtB . pomgrq4ofk = e5n5p5jwen ; rtB
. lthpnqg4ps = 1.0 / rtB . frdjc0ipbc * rtB . pomgrq4ofk ; if ( rtB .
lthpnqg4ps > rtP . Switch2_Threshold ) { rtB . m4bwkc5hnn = rtB . lthpnqg4ps
; } else { rtB . m4bwkc5hnn = rtP . Constant2_Value_ibttoaofbk ; } if ( rtB .
lthpnqg4ps > rtP . Switch1_Threshold_er3fpts1xb ) { bpIndices_e [ 1U ] =
plook_binca ( jjcpw4yqmp , rtP . Spd_BP , 6U , & e5n5p5jwen ) ; fractions_e [
1U ] = e5n5p5jwen ; for ( i = 0 ; i < 12 ; i ++ ) { bpIndices_e [ 0U ] =
plook_binca ( rtP . Trq_BP [ ( int32_T ) rtConstP .
rtw_collapsed_sub_expr_FucNF5IedxlzbnilUMUgVH_1 [ i ] - 1 ] , rtP . Trq_BP ,
11U , & e5n5p5jwen ) ; fractions_e [ 0U ] = e5n5p5jwen ; hdsvmy35zz [ i ] =
intrp2d_la_pw ( bpIndices_e , fractions_e , rtP . Fuel_Map , 12U , rtP .
uDLookupTable2_maxIndex_ebipil2bvy ) ; } memcpy ( & rtB . ennxpj0tru [ 0 ] ,
& hdsvmy35zz [ 0 ] , 12U * sizeof ( real_T ) ) ; } else { memcpy ( & rtB .
ennxpj0tru [ 0 ] , & rtP . Constant3_Value_hvfq5alqlg [ 0 ] , 12U * sizeof (
real_T ) ) ; } e5n5p5jwen = look1_binlcapw ( rtB . m4bwkc5hnn , rtB .
ennxpj0tru , rtP . Trq_BP , 11U ) ; rtB . n3yzlaao40 = rtB . a4b4l1echj -
e5n5p5jwen ; rtPrevAction = rtDW . dd5lqxkqw1 ; if ( ssIsModeUpdateTimeStep (
rtS ) ) { rtAction = ( int8_T ) ! ( rtB . n3yzlaao40 <= rtP . SideA_RatedTrq
) ; rtDW . dd5lqxkqw1 = rtAction ; } else { rtAction = rtDW . dd5lqxkqw1 ; }
if ( rtPrevAction != rtAction ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; } if ( rtAction == 0 ) { if ( e5n5p5jwen > rtP . Switch1_Threshold
) { rtB . eqqz4ci0tv = e5n5p5jwen ; } else { rtB . eqqz4ci0tv = rtP .
Constant_Value_lsistt0yxv ; } if ( rtB . n3yzlaao40 > rtP . Switch4_Threshold
) { rtB . ctnwpqizmx = rtB . n3yzlaao40 ; } else { rtB . ctnwpqizmx = rtP .
Constant_Value_lsistt0yxv ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . iuutt5gbfx ) ; } } else { rtB . o1uhppc0j4 = rtB .
a4b4l1echj - rtP . SideA_RatedTrq ; jjcpw4yqmp = look2_binlcapw ( rtB .
o1uhppc0j4 , jjcpw4yqmp , rtP . Trq_BP , rtP . Spd_BP , rtP . Power_Map , rtP
. uDLookupTable2_maxIndex_pobosuq2zq , 12U ) ; rtB . ctnwpqizmx = rtB .
a4b4l1echj - jjcpw4yqmp ; rtB . eqqz4ci0tv = jjcpw4yqmp ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . pkdoeu3vac ) ; } } if
( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . aeu2i4j0ln ) ; } }
rtB . obpp1l4vac = rtB . ctnwpqizmx ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . bomurwpyov ) ; } break ; case 1 : if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . obpp1l4vac = rtP . Constant_Value_ea5wuf1vfl ; rtB .
eqqz4ci0tv = rtP . Constant_Value_ea5wuf1vfl ; } if ( ssIsModeUpdateTimeStep
( rtS ) ) { srUpdateBC ( rtDW . i0u0wqsccx ) ; } break ; default :
rtPrevAction = rtDW . jsvlghnnou ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { if
( ( jjcpw4yqmp != 0.0 ) && ( e5n5p5jwen == 0.0 ) ) { rtAction = 0 ; } else if
( ( jjcpw4yqmp == 0.0 ) && ( e5n5p5jwen != 0.0 ) ) { rtAction = 1 ; } else {
rtAction = 2 ; } rtDW . jsvlghnnou = rtAction ; } else { rtAction = rtDW .
jsvlghnnou ; } if ( rtPrevAction != rtAction ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } switch ( rtAction ) {
case 0 : if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . obpp1l4vac = rtP .
Constant_Value_m22jzxcnam ; } bpIndices [ 1U ] = plook_binca ( jjcpw4yqmp ,
rtP . Spd_BP , 6U , & e5n5p5jwen ) ; fractions [ 1U ] = e5n5p5jwen ; for ( i
= 0 ; i < 12 ; i ++ ) { bpIndices [ 0U ] = plook_binca ( rtP . Trq_BP [ (
int32_T ) rtConstP . rtw_collapsed_sub_expr_FucNF5IedxlzbnilUMUgVH_1 [ i ] -
1 ] , rtP . Trq_BP , 11U , & e5n5p5jwen ) ; fractions [ 0U ] = e5n5p5jwen ;
hdsvmy35zz [ i ] = intrp2d_la_pw ( bpIndices , fractions , rtP . Fuel_MapE ,
12U , rtP . uDLookupTable_maxIndex_c0gevfgaga ) ; } i = 0 ; for ( i_p = 0 ;
i_p < 12 ; i_p ++ ) { i = ( int32_T ) ( ( uint32_T ) ( hdsvmy35zz [ i_p ] >
rtP . Constant4_Value_mph0ksevah ) + ( uint32_T ) i ) ; } rtB . kt4qdvgqqh =
( uint8_T ) i ; if ( rtB . kt4qdvgqqh > rtP . Switch3_Threshold_ff0k22oeft )
{ rtB . lo0fmxamwn = rtB . kt4qdvgqqh ; } else { rtB . lo0fmxamwn = rtP .
Constant5_Value_p2jqkjofwo ; } e5n5p5jwen = - 0.0 ; for ( i = 0 ; i < 12 ; i
++ ) { e5n5p5jwen += hdsvmy35zz [ i ] ; } rtB . bykovcr4gn = e5n5p5jwen ; rtB
. ml5chi14gx = 1.0 / rtB . lo0fmxamwn * rtB . bykovcr4gn ; if ( rtB .
ml5chi14gx > rtP . Switch2_Threshold_bn224qmpbp ) { rtB . favitckluv = rtB .
ml5chi14gx ; } else { rtB . favitckluv = rtP . Constant2_Value_fkd3f5524d ; }
if ( rtB . ml5chi14gx > rtP . Switch1_Threshold_n1hoa2ckzb ) { bpIndices_e [
1U ] = plook_binca ( jjcpw4yqmp , rtP . Spd_BP , 6U , & e5n5p5jwen ) ;
fractions_e [ 1U ] = e5n5p5jwen ; for ( i = 0 ; i < 12 ; i ++ ) { bpIndices_e
[ 0U ] = plook_binca ( rtP . Trq_BP [ ( int32_T ) rtConstP .
rtw_collapsed_sub_expr_FucNF5IedxlzbnilUMUgVH_1 [ i ] - 1 ] , rtP . Trq_BP ,
11U , & e5n5p5jwen ) ; fractions_e [ 0U ] = e5n5p5jwen ; hdsvmy35zz [ i ] =
intrp2d_la_pw ( bpIndices_e , fractions_e , rtP . Fuel_Map , 12U , rtP .
uDLookupTable2_maxIndex_ljaygbg3k3 ) ; } memcpy ( & rtB . fjud52gekg [ 0 ] ,
& hdsvmy35zz [ 0 ] , 12U * sizeof ( real_T ) ) ; } else { memcpy ( & rtB .
fjud52gekg [ 0 ] , & rtP . Constant3_Value_mwesjrmlpm [ 0 ] , 12U * sizeof (
real_T ) ) ; } e5n5p5jwen = look1_binlcapw ( rtB . favitckluv , rtB .
fjud52gekg , rtP . Trq_BP , 11U ) ; rtPrevAction = rtDW . hsbxk4y5en ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( e5n5p5jwen >=
rtB . a4b4l1echj ) ; rtDW . hsbxk4y5en = rtAction ; } else { rtAction = rtDW
. hsbxk4y5en ; } if ( rtPrevAction != rtAction ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } if ( rtAction == 0 ) {
rtB . eqqz4ci0tv = e5n5p5jwen ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . apx4aufauy ) ; } } else { rtB . eqqz4ci0tv =
look2_binlcapw ( rtB . a4b4l1echj , jjcpw4yqmp , rtP . Trq_BP , rtP . Spd_BP
, rtP . Power_Map , rtP . uDLookupTable2_maxIndex_iu5fpwg5m1 , 12U ) ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . fs2zaamasz ) ; } } if
( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . bnrzbkqovy ) ; }
break ; case 1 : break ; default : rtB . obpp1l4vac = muDoubleScalarMin ( rtB
. a4b4l1echj , rtP . SideA_RatedTrq ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ rtB . eqqz4ci0tv = rtP . Constant1_Value_eafxkgr2qu ; } if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . mwn40uclws ) ; } break
; } if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . pii1ltmep3 )
; } break ; } rtPrevAction = rtDW . efurz0y3yi ; if ( ssIsModeUpdateTimeStep
( rtS ) ) { rtAction = ( int8_T ) ! ( rtB . gmqd0r1s5n > 0.0 ) ; rtDW .
efurz0y3yi = rtAction ; } else { rtAction = rtDW . efurz0y3yi ; } if (
rtPrevAction != rtAction ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; } if ( rtAction == 0 ) { if ( rtB . a4b4l1echj > rtP . Switch_Threshold )
{ bpIndices_p [ 1U ] = plook_binca ( rtB . gmqd0r1s5n , rtP .
uDLookupTable_bp02Data , 5U , & e5n5p5jwen ) ; fractions_p [ 1U ] =
e5n5p5jwen ; for ( i = 0 ; i < 11 ; i ++ ) { bpIndices_p [ 0U ] = plook_binca
( rtP . Trq_BP [ ( int32_T ) rtConstP .
rtw_collapsed_sub_expr_8KZy8ZUC4h5CT21RYTS0zD_1 [ i ] - 1 ] , rtP .
uDLookupTable_bp01Data , 10U , & e5n5p5jwen ) ; fractions_p [ 0U ] =
e5n5p5jwen ; ncdbowaevb [ i ] = intrp2d_la_pw ( bpIndices_p , fractions_p ,
rtP . Power_Thr_Map , 11U , rtP . uDLookupTable_maxIndex ) ; } rtB .
fdtuj3yfv3 = look1_binlcapw ( rtB . eqqz4ci0tv , ncdbowaevb , rtP .
uDLookupTable1_tableData , 10U ) ; } else { rtB . fdtuj3yfv3 = rtP .
Constant2_Value_nzc55mhdyv ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . jbdxmczt2f ) ; } } else { if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { rtB . fdtuj3yfv3 = rtP . Constant_Value_kkku1dkpit ; } if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . fe1jlxthwc ) ; } } rtB
. ka3c0rpnqg = look2_binlxpw ( rtB . fdtuj3yfv3 , rtB . gmqd0r1s5n , rtP .
DA50TorqueMap_bp01Data , rtP . DA50TorqueMap_bp02Data , rtP .
DA50TorqueMap_tableData , rtP . DA50TorqueMap_maxIndex , 11U ) ; rtB .
nt4pl2mpy0 = look2_binlxpw ( rtB . fdtuj3yfv3 , rtB . gmqd0r1s5n , rtP .
DA50PowerMap_bp01Data , rtP . DA50PowerMap_bp02Data , rtP .
DA50PowerMap_tableData , rtP . DA50PowerMap_maxIndex , 11U ) ; rtB .
mpbv3fozuy = rtP . Dyno_Ke * rtB . iavmf0c0td ; if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { } rtB . k2emjlyzxk = look2_binlcpw ( rtB . eqqz4ci0tv , rtB .
gmqd0r1s5n , rtP . Trq_BP , rtP . Spd_BP , rtP . Power_Map , rtP .
EngTrqTable_maxIndex , 12U ) ; rtB . ahrdefsall = rtP . rpmtorads_Gain * rtB
. gmqd0r1s5n * rtB . k2emjlyzxk ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { }
rtB . csh2m1cgxy = rtX . it0jfj1ga4 ; rtB . a5w4q3xmqj = rtP .
Gain1_Gain_nd3h1ot2bp * rtB . csh2m1cgxy ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { } rtB . kgbpab1bft = rtP . kgstogmin_Gain * look2_binlcpw ( rtB .
eqqz4ci0tv , rtB . gmqd0r1s5n , rtP . Trq_BP , rtP . Spd_BP , rtP . Fuel_Map
, rtP . FuelMassFlwTable_maxIndex , 12U ) ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { } if ( ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtDW . b2vnrg1jny != 0 )
{ rtX . almmbag3ud = rtB . jem0p5cmwo ; } if ( rtX . almmbag3ud >= rtP .
Integrator_UpperSat ) { if ( rtX . almmbag3ud != rtP . Integrator_UpperSat )
{ rtX . almmbag3ud = rtP . Integrator_UpperSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } else if ( ( rtX .
almmbag3ud <= rtP . Integrator_LowerSat ) && ( rtX . almmbag3ud != rtP .
Integrator_LowerSat ) ) { rtX . almmbag3ud = rtP . Integrator_LowerSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . nufjeirxpo = rtX
. almmbag3ud ; } else if ( rtX . almmbag3ud >= rtP . Integrator_UpperSat ) {
rtB . nufjeirxpo = rtP . Integrator_UpperSat ; } else if ( rtX . almmbag3ud
<= rtP . Integrator_LowerSat ) { rtB . nufjeirxpo = rtP . Integrator_LowerSat
; } else { rtB . nufjeirxpo = rtX . almmbag3ud ; } rtB . ii512bfhkj = rtX .
pntygaqlkb ; rtB . prxcefcei5 = rtP . SideA_N * rtB . ii512bfhkj ;
muDoubleScalarSinCos ( rtB . prxcefcei5 , & jjcpw4yqmp , & e5n5p5jwen ) ;
bdhw0fpgj2 = rtB . nufjeirxpo * e5n5p5jwen ; if ( ssIsModeUpdateTimeStep (
rtS ) ) { if ( rtDW . ewedjye3z0 != 0 ) { rtX . ju22bzmclv = rtB . btuvjnvywk
; } if ( rtX . ju22bzmclv >= rtP . Integrator_UpperSat_dip02x0ffl ) { if (
rtX . ju22bzmclv != rtP . Integrator_UpperSat_dip02x0ffl ) { rtX . ju22bzmclv
= rtP . Integrator_UpperSat_dip02x0ffl ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } else if ( ( rtX .
ju22bzmclv <= rtP . Integrator_LowerSat_bbrmas44s3 ) && ( rtX . ju22bzmclv !=
rtP . Integrator_LowerSat_bbrmas44s3 ) ) { rtX . ju22bzmclv = rtP .
Integrator_LowerSat_bbrmas44s3 ; ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; } rtB . ocvt3xrn00 = rtX . ju22bzmclv ; } else if ( rtX . ju22bzmclv
>= rtP . Integrator_UpperSat_dip02x0ffl ) { rtB . ocvt3xrn00 = rtP .
Integrator_UpperSat_dip02x0ffl ; } else if ( rtX . ju22bzmclv <= rtP .
Integrator_LowerSat_bbrmas44s3 ) { rtB . ocvt3xrn00 = rtP .
Integrator_LowerSat_bbrmas44s3 ; } else { rtB . ocvt3xrn00 = rtX . ju22bzmclv
; } rtB . ht0sdc4e2n = bdhw0fpgj2 - rtB . ocvt3xrn00 * jjcpw4yqmp ; rtB .
j14q1l0ljs [ 0 ] = rtB . ht0sdc4e2n ; bdhw0fpgj2 = rtB . nufjeirxpo *
jjcpw4yqmp + rtB . ocvt3xrn00 * e5n5p5jwen ; rtB . nfsnsrxlvr = rtP .
Gain2_Gain_hwyq1kurck * rtB . ht0sdc4e2n + rtP . Gain3_Gain_lvn3xsxcbg *
bdhw0fpgj2 ; rtB . j14q1l0ljs [ 1 ] = rtB . nfsnsrxlvr ; rtB . j14q1l0ljs [ 2
] = rtP . Gain1_Gain_heyv1n0f4a * rtB . ht0sdc4e2n + rtP .
Gain4_Gain_c032xsbfri * bdhw0fpgj2 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { }
rtB . fpnl3wyn4z = rtB . nufjeirxpo * rtB . ocvt3xrn00 ; rtB . krukbv1au2 =
rtB . fpnl3wyn4z * rtB . dmu1xpyaah ; rtB . krguxydvse = rtP . SideA_lambda *
rtB . ocvt3xrn00 ; rtB . lufxmyxbr0 = rtB . krukbv1au2 + rtB . krguxydvse ;
rtB . ivjcnxt5l0 = 1.5 * rtP . SideA_N * rtB . lufxmyxbr0 ; rtB . dwin0lk10m
= rtB . i4tiig10qa * rtB . ivjcnxt5l0 * rtP . Gain_Gain_bcxpylev1y ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } if ( ssIsModeUpdateTimeStep ( rtS ) ) {
if ( rtDW . d24a3iy2yr != 0 ) { rtX . k0f2ivlpoh = rtB . max0cti2zd ; } if (
rtX . k0f2ivlpoh >= rtP . Batt_Cap ) { if ( rtX . k0f2ivlpoh != rtP .
Batt_Cap ) { rtX . k0f2ivlpoh = rtP . Batt_Cap ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } else if ( ( rtX .
k0f2ivlpoh <= rtP . IntegratorLimited_LowerSat ) && ( rtX . k0f2ivlpoh != rtP
. IntegratorLimited_LowerSat ) ) { rtX . k0f2ivlpoh = rtP .
IntegratorLimited_LowerSat ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; } rtB . kvxxl1simd = rtX . k0f2ivlpoh ; } else if ( rtX . k0f2ivlpoh >=
rtP . Batt_Cap ) { rtB . kvxxl1simd = rtP . Batt_Cap ; } else if ( rtX .
k0f2ivlpoh <= rtP . IntegratorLimited_LowerSat ) { rtB . kvxxl1simd = rtP .
IntegratorLimited_LowerSat ; } else { rtB . kvxxl1simd = rtX . k0f2ivlpoh ; }
rtB . fcdzod43fw = rtB . kvxxl1simd / rtP . Batt_Cap ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { } rtB . h1yvg3hrrj = 1.0 / rtP . Dyno_Kt * rtB . cftqthzuab
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . i32tsyahbh =
9.5492965855137211 * rtB . ea1x0lvxve ; rtB . c210qvuzpq = 9.5492965855137211
* rtB . m12o31k1vs [ 0 ] ; rtB . nlnobuqb4t = 9.5492965855137211 * rtB .
a51hahehmm [ 0 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } if ( rtP .
ManualSwitch1_CurrentSetting == 1 ) { bdhw0fpgj2 = rtB . lxakjhp4ut ; } else
{ bdhw0fpgj2 = rtP . Constant2_Value_iswfbqmgg0 ; } rtB . cvfcfkbbot =
0.10471975511965977 * bdhw0fpgj2 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { }
rtB . k21i5spcnm = rtP . RPMtodegs_Gain * rtB . gmqd0r1s5n ; rtB . chctnrcvr3
= - 1.0 / ( rtP . Batt_Parr * 3600.0 ) * rtB . ocvt3xrn00 ; rtB . d44xfr2uxh
= 1.0 / rtP . Batt_Parr * rtB . ocvt3xrn00 ; rtB . ksa4mls0wk =
look2_binlcapw ( rtP . Constant3_Value_clw2lo3chi , rtB . fcdzod43fw , rtP .
DatasheetBattery_BattTempBp , rtP . DatasheetBattery_CapSOCBp , rtP .
DatasheetBattery_RInt , rtP . R_maxIndex , 7U ) * rtB . d44xfr2uxh ; rtB .
fkufe2dwcc = look1_binlcapw ( rtB . fcdzod43fw , rtP .
DatasheetBattery_CapLUTBp , rtP . DatasheetBattery_Em , 100U ) - rtB .
ksa4mls0wk ; rtB . aarbwzwmur = rtP . Batt_Series * rtB . fkufe2dwcc ; rtB .
m3te3eovpd = rtB . aarbwzwmur - rtB . au0ix1q5sj ; rtB . ck20ozhunb = 1.0 /
rtP . Dyno_Ratio * rtB . a51hahehmm [ 0 ] ; rtB . em2j1rtzfx = rtB .
i4tiig10qa * rtB . fyijl5q30k ; rtB . baetrfr4r5 = rtP .
Gain5_Gain_ofpzj4djyh * rtB . i4tiig10qa ; rtB . k2zygd0izr = rtB .
ludaotrnqc * muDoubleScalarTanh ( rtB . baetrfr4r5 ) ; rtB . m4hxih4mk4 = ( (
rtB . ivjcnxt5l0 - rtB . obpp1l4vac ) - rtB . em2j1rtzfx ) - rtB . k2zygd0izr
; rtB . gvb04ezgus = rtB . m4hxih4mk4 / rtB . ct0fhunmet ; rtB . lh5ejoytai =
rtP . SideA_N * rtB . i4tiig10qa ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB
. gg2bbcdrrw = ( rtB . cvfcfkbbot - rtDW . e3d0a5oz4x ) * rtP .
SurfaceMountPMController1_Ksf ; bdhw0fpgj2 = rtDW . e3d0a5oz4x - rtB .
ck20ozhunb ; rtB . gssztf5fdg = rtP . DiscreteTimeIntegrator_gainval *
bdhw0fpgj2 + rtDW . pgf331hvhc ; rtB . m5zlrndttj = rtP .
DiscreteTimeIntegrator1_gainval * rtB . gssztf5fdg + rtDW . bxrcqiwwif ;
ha2dpbznfc = ( ( rtP . SurfaceMountPMController1_Jcomp * rtB . gg2bbcdrrw +
rtP . SurfaceMountPMController1_Fv * rtDW . e3d0a5oz4x ) + rtP .
SurfaceMountPMController1_Fs * muDoubleScalarSign ( rtDW . e3d0a5oz4x ) ) + (
( rtP . SurfaceMountPMController1_Kisa * rtB . m5zlrndttj + rtP .
SurfaceMountPMController1_Ksa * rtB . gssztf5fdg ) + rtP .
SurfaceMountPMController1_ba * bdhw0fpgj2 ) ; bdhw0fpgj2 = ( rtB . ht0sdc4e2n
+ rtB . nfsnsrxlvr ) * rtP . Gain5_Gain ; kapenr40ft = ( rtP . Gain_Gain *
rtB . ht0sdc4e2n + rtP . Gain1_Gain * rtB . nfsnsrxlvr ) + rtP . Gain4_Gain *
bdhw0fpgj2 ; nycml4qlmt = rtP . Gain2_Gain * rtB . nfsnsrxlvr + rtP .
Gain3_Gain * bdhw0fpgj2 ; bdhw0fpgj2 = rtP . Gain1_Gain_j1b2wfl0wo * rtB .
au0ix1q5sj ; a1liohfrsm = muDoubleScalarMin ( muDoubleScalarAbs ( ha2dpbznfc
) / rtB . cguxiwph41 , rtP . SurfaceMountPMController1_idq_limits ) ;
mcm3lpg1nv = rtP . SideA_N * muDoubleScalarAbs ( rtB . ck20ozhunb ) ; if (
mcm3lpg1nv <= bdhw0fpgj2 / rtB . nhto33wndj ) { rtB . hzgfvz42dk = a1liohfrsm
; srUpdateBC ( rtDW . miza0bwslu ) ; } else { bdhw0fpgj2 /= muDoubleScalarMax
( mcm3lpg1nv , rtP . Constant2_Value ) ; nxw4bomkqu = muDoubleScalarSqrt (
muDoubleScalarMax ( bdhw0fpgj2 * bdhw0fpgj2 - rtB . d0ddtqwuj5 , rtP .
Constant3_Value ) ) / rtP . Constant5_Value ; if ( a1liohfrsm < nxw4bomkqu )
{ l55fduec5s ( a1liohfrsm , & rtB . hzgfvz42dk ) ; } else { l55fduec5s (
nxw4bomkqu , & rtB . hzgfvz42dk ) ; } srUpdateBC ( rtDW . lpzxn11asy ) ; }
muDoubleScalarSinCos ( rtP . SideA_N * rtB . ii512bfhkj , & bdhw0fpgj2 , &
mcm3lpg1nv ) ; enkodslmzh = kapenr40ft * mcm3lpg1nv + nycml4qlmt * bdhw0fpgj2
; c5xy34bpvg = rtP . SideA_N * rtB . ck20ozhunb ; kapenr40ft = nycml4qlmt *
mcm3lpg1nv - kapenr40ft * bdhw0fpgj2 ; ha2dpbznfc = rtB . hzgfvz42dk *
muDoubleScalarSign ( ha2dpbznfc ) - kapenr40ft ; nycml4qlmt = rtP .
Constant4_Value - enkodslmzh ; u0 = rtP . SurfaceMountPMController1_Ki *
nycml4qlmt * rtP . Gain1_Gain_he3uzhz5qz + rtDW . hbjtppjnxc ; if ( u0 > rtP
. Saturation_UpperSat ) { rtB . h2k2rk41bt = rtP . Saturation_UpperSat ; }
else if ( u0 < rtP . Saturation_LowerSat ) { rtB . h2k2rk41bt = rtP .
Saturation_LowerSat ; } else { rtB . h2k2rk41bt = u0 ; } u0 = rtP .
SurfaceMountPMController1_Ki * ha2dpbznfc * rtP . Gain1_Gain_nnzhsn1hyd +
rtDW . oajcj2f1f5 ; if ( u0 > rtP . Saturation_UpperSat_phs0dpqpzg ) { rtB .
gnyyc12ptg = rtP . Saturation_UpperSat_phs0dpqpzg ; } else if ( u0 < rtP .
Saturation_LowerSat_gdduvb3oo2 ) { rtB . gnyyc12ptg = rtP .
Saturation_LowerSat_gdduvb3oo2 ; } else { rtB . gnyyc12ptg = u0 ; }
kapenr40ft = ( rtP . SurfaceMountPMController1_Kp_d * nycml4qlmt + rtDW .
hbjtppjnxc ) - rtP . Proportional_Gain2_Gain * kapenr40ft * c5xy34bpvg ;
enkodslmzh = ( rtP . Proportional_Gain3_Gain * enkodslmzh + rtP .
SideA_lambda ) * c5xy34bpvg + ( rtP . SurfaceMountPMController1_Kp_q *
ha2dpbznfc + rtDW . oajcj2f1f5 ) ; ha2dpbznfc = kapenr40ft * mcm3lpg1nv -
enkodslmzh * bdhw0fpgj2 ; mcm3lpg1nv = kapenr40ft * bdhw0fpgj2 + enkodslmzh *
mcm3lpg1nv ; bdhw0fpgj2 = rtP . Gain2_Gain_en3fcdxiec * ha2dpbznfc + rtP .
Gain3_Gain_h5v1k1sppn * mcm3lpg1nv ; mcm3lpg1nv = rtP . Gain1_Gain_fvtzit2ppk
* ha2dpbznfc + rtP . Gain4_Gain_ne1f41rvzn * mcm3lpg1nv ; rtB . bvlzron2lo =
( rtP . Gain_Gain_a2pdrz3qwa * ha2dpbznfc + rtP . Gain1_Gain_p2f3paaf35 *
bdhw0fpgj2 ) + rtP . Gain4_Gain_a3qhxjwm2o * mcm3lpg1nv ; rtB . bdpeazbcik =
rtP . Gain2_Gain_f3g2yr2rkw * bdhw0fpgj2 + rtP . Gain3_Gain_kigulbfrzl *
mcm3lpg1nv ; } rtB . ddcgg2bx0n = rtB . bvlzron2lo * e5n5p5jwen ; rtB .
dbu1cph3qd = rtB . bdpeazbcik * jjcpw4yqmp ; rtB . gx1mbhkzzf = rtB .
ddcgg2bx0n + rtB . dbu1cph3qd ; rtB . kkagvopgxv = rtB . gx1mbhkzzf / rtB .
h1oufun4jj ; rtB . jtkb23rkw2 = rtB . lh5ejoytai * rtB . ocvt3xrn00 ; rtB .
k2zpu1crq0 = rtB . jtkb23rkw2 * rtB . ary5hhvnmx / rtB . obnipod5vd ; rtB .
ceua4sozts = rtB . nufjeirxpo * rtP . SideA_Rs / rtB . hcl3f2ypn0 ; rtB .
enjx00pe1u = ( rtB . kkagvopgxv + rtB . k2zpu1crq0 ) - rtB . ceua4sozts ; rtB
. lg5bmspaoy = rtB . bvlzron2lo * jjcpw4yqmp ; rtB . mi1n1xzbri = rtB .
bdpeazbcik * e5n5p5jwen ; rtB . ph0oqajh3o = rtB . mi1n1xzbri - rtB .
lg5bmspaoy ; rtB . feuebfqypv = rtB . ph0oqajh3o / rtB . ja5xj0z1cg ; rtB .
foeysnqrik = rtB . nufjeirxpo * rtB . lh5ejoytai ; rtB . cgtnywjknf = rtB .
foeysnqrik * rtB . kumjwk2t03 / rtB . g122wtg0el ; rtB . il1hhqxhtq = rtB .
lh5ejoytai * rtP . SideA_lambda / rtB . fhuegjob4p ; rtB . gxy0dk5ecd = rtB .
ocvt3xrn00 * rtP . SideA_Rs / rtB . avg1hsnek4 ; rtB . fkz44ny3ao = ( ( rtB .
feuebfqypv - rtB . cgtnywjknf ) - rtB . il1hhqxhtq ) - rtB . gxy0dk5ecd ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { real_T lz4fhxmtfn ; if ( rtP .
Constant_Value_in3f0w41r2 > rtP . Batt_Cap ) { rtB . max0cti2zd = rtP .
Batt_Cap ; } else { rtB . max0cti2zd = rtP . Constant_Value_in3f0w41r2 ; }
rtB . h4fmwxdtzw = rtP . DatasheetBattery_Vinit * rtP . DatasheetBattery_Tc ;
rtB . ct0fhunmet = rtP . SideA_Physical_Param [ ( int32_T ) rtP .
Constant1_Value_ohpunqj1gy - 1 ] ; rtB . ludaotrnqc = rtP .
SideA_Physical_Param [ ( int32_T ) rtP . Constant3_Value_otox1iiiva - 1 ] ;
rtB . fyijl5q30k = rtP . SideA_Physical_Param [ ( int32_T ) rtP .
Constant5_Value_n1ykd3pjvs - 1 ] ; rtB . dmu1xpyaah = rtP .
Constant_Value_c45tuyaygc [ ( int32_T ) rtP . Constant1_Value_mj3ya5njvu - 1
] - rtP . Constant_Value_c45tuyaygc [ ( int32_T ) rtP .
Constant2_Value_m2kdydkjx0 - 1 ] ; rtB . jem0p5cmwo = rtP . SKP6485_idq0 [ (
int32_T ) rtP . Constant1_Value_bg0rrb32ed - 1 ] ; rtB . h1oufun4jj = rtP .
Constant_Value_go40v4ie0s [ ( int32_T ) rtP . Constant1_Value_kozehzplrf - 1
] ; rtB . ary5hhvnmx = rtP . Constant_Value_dm14eym3wc [ ( int32_T ) rtP .
Constant1_Value_k5ndhlm4pr - 1 ] ; rtB . obnipod5vd = rtP .
Constant_Value_dm14eym3wc [ ( int32_T ) rtP . Constant2_Value_fw4dwfnqy4 - 1
] ; rtB . hcl3f2ypn0 = rtP . Constant1_Value_om5j34o2qt [ ( int32_T ) rtP .
Constant2_Value_kk042enjt5 - 1 ] ; rtB . btuvjnvywk = rtP . SKP6485_idq0 [ (
int32_T ) rtP . Constant1_Value_nwflgkncxk - 1 ] ; rtB . ja5xj0z1cg = rtP .
Constant_Value_aqptyhwws5 [ ( int32_T ) rtP . Constant1_Value_il2awj2dhq - 1
] ; rtB . kumjwk2t03 = rtP . Constant_Value_pf0letx30a [ ( int32_T ) rtP .
Constant1_Value_na2pva40rs - 1 ] ; rtB . g122wtg0el = rtP .
Constant_Value_pf0letx30a [ ( int32_T ) rtP . Constant2_Value_nligrrj1ds - 1
] ; rtB . fhuegjob4p = rtP . Constant1_Value_b2jt3bjlb1 [ ( int32_T ) rtP .
Constant2_Value_e34qlb3i30 - 1 ] ; rtB . avg1hsnek4 = rtP .
Constant1_Value_igomjraxnc [ ( int32_T ) rtP . Constant2_Value_hsqnj2ufwi - 1
] ; lz4fhxmtfn = rtP . Gain1_Gain_c2kuo5vmhc * rtP .
SurfaceMountPMController1_idq_limits ; rtB . nhto33wndj = muDoubleScalarMax (
muDoubleScalarSqrt ( rtP . SideA_lambda * rtP . SideA_lambda + lz4fhxmtfn *
lz4fhxmtfn ) , rtP . Constant1_Value_brfyntmkio ) ; rtB . cguxiwph41 = 1.5 *
rtP . SideA_N * rtP . SideA_lambda ; rtB . d0ddtqwuj5 = rtP . SideA_lambda *
rtP . SideA_lambda ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid
) { NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; NeuDiagnosticTree *
diagnosticTree_e ; NeuDiagnosticTree * diagnosticTree_p ; char * msg ; char *
msg_e ; char * msg_p ; real_T tmp_j [ 4 ] ; real_T tmp_m [ 4 ] ; real_T tmp_p
[ 4 ] ; real_T time ; real_T time_e ; real_T time_p ; int32_T tmp_i ; int_T
tmp_e [ 2 ] ; int_T tmp_f [ 2 ] ; int_T tmp_g [ 2 ] ; boolean_T tmp ; rtDW .
jclc1m30fx = 0 ; simulationData = ( NeslSimulationData * ) rtDW . i1wgzi3jpe
; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ;
simulationData -> mData -> mTime . mX = & time ; simulationData -> mData ->
mContStates . mN = 5 ; simulationData -> mData -> mContStates . mX = & rtX .
dinj2vqkhf [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . l5far1dd5s ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . bmyjja4qwv ; tmp = false ; simulationData ->
mData -> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . mxgpxbyfng [ 0 ] ; tmp_p [ 1 ] = rtB . mxgpxbyfng [ 1 ] ;
tmp_p [ 2 ] = rtB . mxgpxbyfng [ 2 ] ; tmp_p [ 3 ] = rtB . mxgpxbyfng [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
bob4xgg01l ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. j5biz3l2tk , NESL_SIM_UPDATE , simulationData , diagnosticManager ) ; if (
tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if
( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus (
rtS , msg ) ; } } simulationData = ( NeslSimulationData * ) rtDW . pzexosznjb
; time_p = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ;
simulationData -> mData -> mTime . mX = & time_p ; simulationData -> mData ->
mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX = & rtX .
cmzleelpyc [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . aij0ldcei4 ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . n0n2vuipdf ; tmp = false ; simulationData ->
mData -> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_g [ 0 ] = 0 ;
tmp_m [ 0 ] = rtB . g1be22q2ab [ 0 ] ; tmp_m [ 1 ] = rtB . g1be22q2ab [ 1 ] ;
tmp_m [ 2 ] = rtB . g1be22q2ab [ 2 ] ; tmp_m [ 3 ] = rtB . g1be22q2ab [ 3 ] ;
tmp_g [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_m [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_g [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
j1r4xwoi0i ; diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. jeli2jkiuj , NESL_SIM_UPDATE , simulationData , diagnosticManager ) ; if (
tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if
( tmp ) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus
( rtS , msg_p ) ; } } simulationData = ( NeslSimulationData * ) rtDW .
hedrhiezbd ; time_e = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN
= 1 ; simulationData -> mData -> mTime . mX = & time_e ; simulationData ->
mData -> mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX =
& rtX . o3f51d5jei [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . cern2voaws ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . k5a5eyevvp ; tmp = false ; simulationData ->
mData -> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_f [ 0 ] = 0 ;
tmp_j [ 0 ] = rtB . jhai0ek5up [ 0 ] ; tmp_j [ 1 ] = rtB . jhai0ek5up [ 1 ] ;
tmp_j [ 2 ] = rtB . jhai0ek5up [ 2 ] ; tmp_j [ 3 ] = rtB . jhai0ek5up [ 3 ] ;
tmp_f [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_j [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_f [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
d21wvb0imp ; diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. p2ezmuppnc , NESL_SIM_UPDATE , simulationData , diagnosticManager ) ; if (
tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if
( tmp ) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ; ssSetErrorStatus
( rtS , msg_e ) ; } } rtDW . b2vnrg1jny = 0 ; rtDW . ewedjye3z0 = 0 ; rtDW .
d24a3iy2yr = 0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . e3d0a5oz4x +=
rtP . DiscreteTimeIntegrator_gainval_p43vz5tnpd * rtB . gg2bbcdrrw ; rtDW .
pgf331hvhc = rtB . gssztf5fdg ; rtDW . bxrcqiwwif = rtB . m5zlrndttj ; rtDW .
hbjtppjnxc = rtB . h2k2rk41bt ; rtDW . oajcj2f1f5 = rtB . gnyyc12ptg ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; NeuDiagnosticTree *
diagnosticTree_e ; NeuDiagnosticTree * diagnosticTree_p ; XDot * _rtXdot ;
char * msg ; char * msg_e ; char * msg_p ; real_T tmp_g [ 4 ] ; real_T tmp_i
[ 4 ] ; real_T tmp_p [ 4 ] ; real_T time ; real_T time_e ; real_T time_p ;
int_T tmp_e [ 2 ] ; int_T tmp_j [ 2 ] ; int_T tmp_m [ 2 ] ; int_T iS ;
boolean_T tmp ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot ->
hjvfmqrotz = rtB . m3te3eovpd ; if ( ( ( rtX . hterznv3np > rtP .
Int_LowerSat ) && ( rtX . hterznv3np < rtP . Int_UpperSat ) ) || ( ( rtX .
hterznv3np <= rtP . Int_LowerSat ) && ( rtB . gvb04ezgus > 0.0 ) ) || ( ( rtX
. hterznv3np >= rtP . Int_UpperSat ) && ( rtB . gvb04ezgus < 0.0 ) ) ) {
_rtXdot -> hterznv3np = rtB . gvb04ezgus ; } else { _rtXdot -> hterznv3np =
0.0 ; } _rtXdot -> eap5trepgw = ( rtB . i4tiig10qa - rtX . eap5trepgw ) *
1000.0 ; simulationData = ( NeslSimulationData * ) rtDW . i1wgzi3jpe ; time =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time ; simulationData -> mData -> mContStates . mN
= 5 ; simulationData -> mData -> mContStates . mX = & rtX . dinj2vqkhf [ 0 ]
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = & rtDW . l5far1dd5s ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
bmyjja4qwv ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian (
rtS ) != 0 ) ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB . mxgpxbyfng [ 0 ] ; tmp_p [ 1 ]
= rtB . mxgpxbyfng [ 1 ] ; tmp_p [ 2 ] = rtB . mxgpxbyfng [ 2 ] ; tmp_p [ 3 ]
= rtB . mxgpxbyfng [ 3 ] ; tmp_e [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
simulationData -> mData -> mDx . mN = 5 ; simulationData -> mData -> mDx . mX
= & _rtXdot -> dinj2vqkhf [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager
* ) rtDW . bob4xgg01l ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; iS =
ne_simulator_method ( ( NeslSimulator * ) rtDW . j5biz3l2tk ,
NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if ( iS != 0 )
{ tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg
= rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; }
} _rtXdot -> fpxoom5wcz = ( rtB . iavmf0c0td - rtX . fpxoom5wcz ) * 1000.0 ;
simulationData = ( NeslSimulationData * ) rtDW . pzexosznjb ; time_p = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_p ; simulationData -> mData -> mContStates . mN = 4 ;
simulationData -> mData -> mContStates . mX = & rtX . cmzleelpyc [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . aij0ldcei4 ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
n0n2vuipdf ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian (
rtS ) != 0 ) ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_m [ 0 ] = 0 ; tmp_i [ 0 ] = rtB . g1be22q2ab [ 0 ] ; tmp_i [ 1 ]
= rtB . g1be22q2ab [ 1 ] ; tmp_i [ 2 ] = rtB . g1be22q2ab [ 2 ] ; tmp_i [ 3 ]
= rtB . g1be22q2ab [ 3 ] ; tmp_m [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_i [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_m [ 0 ] ;
simulationData -> mData -> mDx . mN = 4 ; simulationData -> mData -> mDx . mX
= & _rtXdot -> cmzleelpyc [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager
* ) rtDW . j1r4xwoi0i ; diagnosticTree_p =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; iS =
ne_simulator_method ( ( NeslSimulator * ) rtDW . jeli2jkiuj ,
NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if ( iS != 0 )
{ tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS ,
msg_p ) ; } } _rtXdot -> itgqcjsbx5 = ( rtB . dnk2tludg2 - rtX . itgqcjsbx5 )
* 1000.0 ; simulationData = ( NeslSimulationData * ) rtDW . hedrhiezbd ;
time_e = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ;
simulationData -> mData -> mTime . mX = & time_e ; simulationData -> mData ->
mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX = & rtX .
o3f51d5jei [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . cern2voaws ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . k5a5eyevvp ; tmp = false ; simulationData ->
mData -> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_j [ 0 ] = 0 ;
tmp_g [ 0 ] = rtB . jhai0ek5up [ 0 ] ; tmp_g [ 1 ] = rtB . jhai0ek5up [ 1 ] ;
tmp_g [ 2 ] = rtB . jhai0ek5up [ 2 ] ; tmp_g [ 3 ] = rtB . jhai0ek5up [ 3 ] ;
tmp_j [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_g [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_j [ 0 ] ; simulationData -> mData -> mDx . mN = 4 ;
simulationData -> mData -> mDx . mX = & _rtXdot -> o3f51d5jei [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . d21wvb0imp ;
diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; iS = ne_simulator_method ( ( NeslSimulator * ) rtDW .
p2ezmuppnc , NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if
( iS != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if (
tmp ) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ; ssSetErrorStatus (
rtS , msg_e ) ; } } { real_T * dx ; int_T i ; dx = & ( ( ( XDot * ) ssGetdX (
rtS ) ) -> hlra0g33ul ) ; for ( i = 0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } }
if ( rtDW . pitowdgxye == 0 ) { _rtXdot -> hlra0g33ul = ( rtB . fxbpkblr2q -
rtX . hlra0g33ul ) * 1000.0 ; _rtXdot -> mw03mcasf2 = 0.0 ; _rtXdot ->
mw03mcasf2 += rtB . m4c5zvfilf [ 0 ] ; } _rtXdot -> it0jfj1ga4 = rtB .
kgbpab1bft ; if ( ( ( rtX . almmbag3ud > rtP . Integrator_LowerSat ) && ( rtX
. almmbag3ud < rtP . Integrator_UpperSat ) ) || ( ( rtX . almmbag3ud <= rtP .
Integrator_LowerSat ) && ( rtB . enjx00pe1u > 0.0 ) ) || ( ( rtX . almmbag3ud
>= rtP . Integrator_UpperSat ) && ( rtB . enjx00pe1u < 0.0 ) ) ) { _rtXdot ->
almmbag3ud = rtB . enjx00pe1u ; } else { _rtXdot -> almmbag3ud = 0.0 ; }
_rtXdot -> pntygaqlkb = rtB . i4tiig10qa ; if ( ( ( rtX . ju22bzmclv > rtP .
Integrator_LowerSat_bbrmas44s3 ) && ( rtX . ju22bzmclv < rtP .
Integrator_UpperSat_dip02x0ffl ) ) || ( ( rtX . ju22bzmclv <= rtP .
Integrator_LowerSat_bbrmas44s3 ) && ( rtB . fkz44ny3ao > 0.0 ) ) || ( ( rtX .
ju22bzmclv >= rtP . Integrator_UpperSat_dip02x0ffl ) && ( rtB . fkz44ny3ao <
0.0 ) ) ) { _rtXdot -> ju22bzmclv = rtB . fkz44ny3ao ; } else { _rtXdot ->
ju22bzmclv = 0.0 ; } if ( ( ( rtX . k0f2ivlpoh > rtP .
IntegratorLimited_LowerSat ) && ( rtX . k0f2ivlpoh < rtP . Batt_Cap ) ) || (
( rtX . k0f2ivlpoh <= rtP . IntegratorLimited_LowerSat ) && ( rtB .
chctnrcvr3 > 0.0 ) ) || ( ( rtX . k0f2ivlpoh >= rtP . Batt_Cap ) && ( rtB .
chctnrcvr3 < 0.0 ) ) ) { _rtXdot -> k0f2ivlpoh = rtB . chctnrcvr3 ; } else {
_rtXdot -> k0f2ivlpoh = 0.0 ; } _rtXdot -> lcxpannrra = rtB . k21i5spcnm ; }
void MdlProjection ( void ) { NeslSimulationData * simulationData ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; NeuDiagnosticTree * diagnosticTree_e ; NeuDiagnosticTree * diagnosticTree_p
; char * msg ; char * msg_e ; char * msg_p ; real_T tmp_j [ 4 ] ; real_T
tmp_m [ 4 ] ; real_T tmp_p [ 4 ] ; real_T time ; real_T time_e ; real_T
time_p ; int32_T tmp_i ; int_T tmp_e [ 2 ] ; int_T tmp_f [ 2 ] ; int_T tmp_g
[ 2 ] ; boolean_T tmp ; simulationData = ( NeslSimulationData * ) rtDW .
i1wgzi3jpe ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 5 ; simulationData -> mData -> mContStates . mX = & rtX
. dinj2vqkhf [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . l5far1dd5s ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . bmyjja4qwv ; tmp = false ; simulationData ->
mData -> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . mxgpxbyfng [ 0 ] ; tmp_p [ 1 ] = rtB . mxgpxbyfng [ 1 ] ;
tmp_p [ 2 ] = rtB . mxgpxbyfng [ 2 ] ; tmp_p [ 3 ] = rtB . mxgpxbyfng [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
bob4xgg01l ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. j5biz3l2tk , NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ;
if ( tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) )
; if ( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } simulationData = ( NeslSimulationData *
) rtDW . pzexosznjb ; time_p = ssGetT ( rtS ) ; simulationData -> mData ->
mTime . mN = 1 ; simulationData -> mData -> mTime . mX = & time_p ;
simulationData -> mData -> mContStates . mN = 4 ; simulationData -> mData ->
mContStates . mX = & rtX . cmzleelpyc [ 0 ] ; simulationData -> mData ->
mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = & rtDW .
aij0ldcei4 ; simulationData -> mData -> mModeVector . mN = 0 ; simulationData
-> mData -> mModeVector . mX = & rtDW . n0n2vuipdf ; tmp = false ;
simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; simulationData -> mData -> mIsSolverCheckingCIC
= false ; tmp = ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData
-> mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 =
( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_g [ 0 ] = 0 ;
tmp_m [ 0 ] = rtB . g1be22q2ab [ 0 ] ; tmp_m [ 1 ] = rtB . g1be22q2ab [ 1 ] ;
tmp_m [ 2 ] = rtB . g1be22q2ab [ 2 ] ; tmp_m [ 3 ] = rtB . g1be22q2ab [ 3 ] ;
tmp_g [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_m [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_g [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
j1r4xwoi0i ; diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. jeli2jkiuj , NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ;
if ( tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) )
; if ( tmp ) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ;
ssSetErrorStatus ( rtS , msg_p ) ; } } simulationData = ( NeslSimulationData
* ) rtDW . hedrhiezbd ; time_e = ssGetT ( rtS ) ; simulationData -> mData ->
mTime . mN = 1 ; simulationData -> mData -> mTime . mX = & time_e ;
simulationData -> mData -> mContStates . mN = 4 ; simulationData -> mData ->
mContStates . mX = & rtX . o3f51d5jei [ 0 ] ; simulationData -> mData ->
mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = & rtDW .
cern2voaws ; simulationData -> mData -> mModeVector . mN = 0 ; simulationData
-> mData -> mModeVector . mX = & rtDW . k5a5eyevvp ; tmp = false ;
simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; simulationData -> mData -> mIsSolverCheckingCIC
= false ; tmp = ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData
-> mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 =
( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_f [ 0 ] = 0 ;
tmp_j [ 0 ] = rtB . jhai0ek5up [ 0 ] ; tmp_j [ 1 ] = rtB . jhai0ek5up [ 1 ] ;
tmp_j [ 2 ] = rtB . jhai0ek5up [ 2 ] ; tmp_j [ 3 ] = rtB . jhai0ek5up [ 3 ] ;
tmp_f [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_j [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_f [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
d21wvb0imp ; diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. p2ezmuppnc , NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ;
if ( tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) )
; if ( tmp ) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ;
ssSetErrorStatus ( rtS , msg_e ) ; } } } void MdlForcingFunction ( void ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; NeuDiagnosticTree *
diagnosticTree_e ; NeuDiagnosticTree * diagnosticTree_p ; XDot * _rtXdot ;
char * msg ; char * msg_e ; char * msg_p ; real_T tmp_g [ 4 ] ; real_T tmp_i
[ 4 ] ; real_T tmp_p [ 4 ] ; real_T time ; real_T time_e ; real_T time_p ;
int_T tmp_e [ 2 ] ; int_T tmp_j [ 2 ] ; int_T tmp_m [ 2 ] ; int_T iS ;
boolean_T tmp ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot ->
hjvfmqrotz = rtB . m3te3eovpd ; if ( ( ( rtX . hterznv3np > rtP .
Int_LowerSat ) && ( rtX . hterznv3np < rtP . Int_UpperSat ) ) || ( ( rtX .
hterznv3np <= rtP . Int_LowerSat ) && ( rtB . gvb04ezgus > 0.0 ) ) || ( ( rtX
. hterznv3np >= rtP . Int_UpperSat ) && ( rtB . gvb04ezgus < 0.0 ) ) ) {
_rtXdot -> hterznv3np = rtB . gvb04ezgus ; } else { _rtXdot -> hterznv3np =
0.0 ; } _rtXdot -> eap5trepgw = ( rtB . i4tiig10qa - rtX . eap5trepgw ) *
1000.0 ; simulationData = ( NeslSimulationData * ) rtDW . i1wgzi3jpe ; time =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time ; simulationData -> mData -> mContStates . mN
= 5 ; simulationData -> mData -> mContStates . mX = & rtX . dinj2vqkhf [ 0 ]
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = & rtDW . l5far1dd5s ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
bmyjja4qwv ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian (
rtS ) != 0 ) ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB . mxgpxbyfng [ 0 ] ; tmp_p [ 1 ]
= rtB . mxgpxbyfng [ 1 ] ; tmp_p [ 2 ] = rtB . mxgpxbyfng [ 2 ] ; tmp_p [ 3 ]
= rtB . mxgpxbyfng [ 3 ] ; tmp_e [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
simulationData -> mData -> mDx . mN = 5 ; simulationData -> mData -> mDx . mX
= & _rtXdot -> dinj2vqkhf [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager
* ) rtDW . bob4xgg01l ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; iS =
ne_simulator_method ( ( NeslSimulator * ) rtDW . j5biz3l2tk ,
NESL_SIM_FORCINGFUNCTION , simulationData , diagnosticManager ) ; if ( iS !=
0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } _rtXdot -> fpxoom5wcz = ( rtB . iavmf0c0td - rtX . fpxoom5wcz ) *
1000.0 ; simulationData = ( NeslSimulationData * ) rtDW . pzexosznjb ; time_p
= ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time_p ; simulationData -> mData -> mContStates .
mN = 4 ; simulationData -> mData -> mContStates . mX = & rtX . cmzleelpyc [ 0
] ; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = & rtDW . aij0ldcei4 ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
n0n2vuipdf ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian (
rtS ) != 0 ) ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_m [ 0 ] = 0 ; tmp_i [ 0 ] = rtB . g1be22q2ab [ 0 ] ; tmp_i [ 1 ]
= rtB . g1be22q2ab [ 1 ] ; tmp_i [ 2 ] = rtB . g1be22q2ab [ 2 ] ; tmp_i [ 3 ]
= rtB . g1be22q2ab [ 3 ] ; tmp_m [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_i [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_m [ 0 ] ;
simulationData -> mData -> mDx . mN = 4 ; simulationData -> mData -> mDx . mX
= & _rtXdot -> cmzleelpyc [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager
* ) rtDW . j1r4xwoi0i ; diagnosticTree_p =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; iS =
ne_simulator_method ( ( NeslSimulator * ) rtDW . jeli2jkiuj ,
NESL_SIM_FORCINGFUNCTION , simulationData , diagnosticManager ) ; if ( iS !=
0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS ,
msg_p ) ; } } _rtXdot -> itgqcjsbx5 = ( rtB . dnk2tludg2 - rtX . itgqcjsbx5 )
* 1000.0 ; simulationData = ( NeslSimulationData * ) rtDW . hedrhiezbd ;
time_e = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ;
simulationData -> mData -> mTime . mX = & time_e ; simulationData -> mData ->
mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX = & rtX .
o3f51d5jei [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . cern2voaws ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . k5a5eyevvp ; tmp = false ; simulationData ->
mData -> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_j [ 0 ] = 0 ;
tmp_g [ 0 ] = rtB . jhai0ek5up [ 0 ] ; tmp_g [ 1 ] = rtB . jhai0ek5up [ 1 ] ;
tmp_g [ 2 ] = rtB . jhai0ek5up [ 2 ] ; tmp_g [ 3 ] = rtB . jhai0ek5up [ 3 ] ;
tmp_j [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_g [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_j [ 0 ] ; simulationData -> mData -> mDx . mN = 4 ;
simulationData -> mData -> mDx . mX = & _rtXdot -> o3f51d5jei [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . d21wvb0imp ;
diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; iS = ne_simulator_method ( ( NeslSimulator * ) rtDW .
p2ezmuppnc , NESL_SIM_FORCINGFUNCTION , simulationData , diagnosticManager )
; if ( iS != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ;
if ( tmp ) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ;
ssSetErrorStatus ( rtS , msg_e ) ; } } { real_T * dx ; int_T i ; dx = & ( ( (
XDot * ) ssGetdX ( rtS ) ) -> hlra0g33ul ) ; for ( i = 0 ; i < 2 ; i ++ ) {
dx [ i ] = 0.0 ; } } if ( rtDW . pitowdgxye == 0 ) { _rtXdot -> hlra0g33ul =
( rtB . fxbpkblr2q - rtX . hlra0g33ul ) * 1000.0 ; _rtXdot -> mw03mcasf2 =
0.0 ; _rtXdot -> mw03mcasf2 += rtB . m4c5zvfilf [ 0 ] ; } _rtXdot ->
it0jfj1ga4 = rtB . kgbpab1bft ; if ( ( ( rtX . almmbag3ud > rtP .
Integrator_LowerSat ) && ( rtX . almmbag3ud < rtP . Integrator_UpperSat ) )
|| ( ( rtX . almmbag3ud <= rtP . Integrator_LowerSat ) && ( rtB . enjx00pe1u
> 0.0 ) ) || ( ( rtX . almmbag3ud >= rtP . Integrator_UpperSat ) && ( rtB .
enjx00pe1u < 0.0 ) ) ) { _rtXdot -> almmbag3ud = rtB . enjx00pe1u ; } else {
_rtXdot -> almmbag3ud = 0.0 ; } _rtXdot -> pntygaqlkb = rtB . i4tiig10qa ; if
( ( ( rtX . ju22bzmclv > rtP . Integrator_LowerSat_bbrmas44s3 ) && ( rtX .
ju22bzmclv < rtP . Integrator_UpperSat_dip02x0ffl ) ) || ( ( rtX . ju22bzmclv
<= rtP . Integrator_LowerSat_bbrmas44s3 ) && ( rtB . fkz44ny3ao > 0.0 ) ) ||
( ( rtX . ju22bzmclv >= rtP . Integrator_UpperSat_dip02x0ffl ) && ( rtB .
fkz44ny3ao < 0.0 ) ) ) { _rtXdot -> ju22bzmclv = rtB . fkz44ny3ao ; } else {
_rtXdot -> ju22bzmclv = 0.0 ; } if ( ( ( rtX . k0f2ivlpoh > rtP .
IntegratorLimited_LowerSat ) && ( rtX . k0f2ivlpoh < rtP . Batt_Cap ) ) || (
( rtX . k0f2ivlpoh <= rtP . IntegratorLimited_LowerSat ) && ( rtB .
chctnrcvr3 > 0.0 ) ) || ( ( rtX . k0f2ivlpoh >= rtP . Batt_Cap ) && ( rtB .
chctnrcvr3 < 0.0 ) ) ) { _rtXdot -> k0f2ivlpoh = rtB . chctnrcvr3 ; } else {
_rtXdot -> k0f2ivlpoh = 0.0 ; } _rtXdot -> lcxpannrra = rtB . k21i5spcnm ; }
void MdlMassMatrix ( void ) { NeslSimulationData * simulationData ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; NeuDiagnosticTree * diagnosticTree_e ; NeuDiagnosticTree * diagnosticTree_p
; char * msg ; char * msg_e ; char * msg_p ; real_T tmp_j [ 4 ] ; real_T
tmp_k [ 4 ] ; real_T tmp_p [ 4 ] ; real_T time ; real_T time_e ; real_T
time_p ; real_T * tmp_c ; real_T * tmp_i ; real_T * tmp_m ; real_T * tmp_n ;
int32_T tmp_g ; int_T tmp_b [ 2 ] ; int_T tmp_e [ 2 ] ; int_T tmp_f [ 2 ] ;
boolean_T tmp ; simulationData = ( NeslSimulationData * ) rtDW . i1wgzi3jpe ;
time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ;
simulationData -> mData -> mTime . mX = & time ; simulationData -> mData ->
mContStates . mN = 5 ; simulationData -> mData -> mContStates . mX = & rtX .
dinj2vqkhf [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . l5far1dd5s ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . bmyjja4qwv ; tmp = false ; simulationData ->
mData -> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . mxgpxbyfng [ 0 ] ; tmp_p [ 1 ] = rtB . mxgpxbyfng [ 1 ] ;
tmp_p [ 2 ] = rtB . mxgpxbyfng [ 2 ] ; tmp_p [ 3 ] = rtB . mxgpxbyfng [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; tmp_i = ssGetMassMatrixPr ( rtS ) ; tmp_m =
double_pointer_shift ( tmp_i , rtDW . nr541hf2w4 ) ; simulationData -> mData
-> mMassMatrixPr . mN = 5 ; simulationData -> mData -> mMassMatrixPr . mX =
tmp_m ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . bob4xgg01l ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_g = ne_simulator_method ( ( NeslSimulator * ) rtDW . j5biz3l2tk ,
NESL_SIM_MASSMATRIX , simulationData , diagnosticManager ) ; if ( tmp_g != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } simulationData = ( NeslSimulationData * ) rtDW . pzexosznjb ; time_p =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time_p ; simulationData -> mData -> mContStates .
mN = 4 ; simulationData -> mData -> mContStates . mX = & rtX . cmzleelpyc [ 0
] ; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = & rtDW . aij0ldcei4 ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
n0n2vuipdf ; tmp = false ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; simulationData ->
mData -> mIsSolverCheckingCIC = false ; tmp = ssIsSolverComputingJacobian (
rtS ) ; simulationData -> mData -> mIsComputingJacobian = tmp ;
simulationData -> mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian (
rtS ) != 0 ) ; simulationData -> mData -> mIsSolverRequestingReset = false ;
simulationData -> mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep (
rtS ) ; tmp_f [ 0 ] = 0 ; tmp_j [ 0 ] = rtB . g1be22q2ab [ 0 ] ; tmp_j [ 1 ]
= rtB . g1be22q2ab [ 1 ] ; tmp_j [ 2 ] = rtB . g1be22q2ab [ 2 ] ; tmp_j [ 3 ]
= rtB . g1be22q2ab [ 3 ] ; tmp_f [ 1 ] = 4 ; simulationData -> mData ->
mInputValues . mN = 4 ; simulationData -> mData -> mInputValues . mX = &
tmp_j [ 0 ] ; simulationData -> mData -> mInputOffsets . mN = 2 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_f [ 0 ] ; tmp_c =
ssGetMassMatrixPr ( rtS ) ; tmp_m = double_pointer_shift ( tmp_c , rtDW .
jueswsqa1v ) ; simulationData -> mData -> mMassMatrixPr . mN = 4 ;
simulationData -> mData -> mMassMatrixPr . mX = tmp_m ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . j1r4xwoi0i ; diagnosticTree_p =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_g =
ne_simulator_method ( ( NeslSimulator * ) rtDW . jeli2jkiuj ,
NESL_SIM_MASSMATRIX , simulationData , diagnosticManager ) ; if ( tmp_g != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS ,
msg_p ) ; } } simulationData = ( NeslSimulationData * ) rtDW . hedrhiezbd ;
time_e = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ;
simulationData -> mData -> mTime . mX = & time_e ; simulationData -> mData ->
mContStates . mN = 4 ; simulationData -> mData -> mContStates . mX = & rtX .
o3f51d5jei [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . cern2voaws ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . k5a5eyevvp ; tmp = false ; simulationData ->
mData -> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; simulationData -> mData -> mIsSolverCheckingCIC = false ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; simulationData -> mData ->
mIsSolverRequestingReset = false ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_b [ 0 ] = 0 ;
tmp_k [ 0 ] = rtB . jhai0ek5up [ 0 ] ; tmp_k [ 1 ] = rtB . jhai0ek5up [ 1 ] ;
tmp_k [ 2 ] = rtB . jhai0ek5up [ 2 ] ; tmp_k [ 3 ] = rtB . jhai0ek5up [ 3 ] ;
tmp_b [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_k [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_b [ 0 ] ; tmp_n = ssGetMassMatrixPr ( rtS ) ; tmp_m =
double_pointer_shift ( tmp_n , rtDW . cndm4gb520 ) ; simulationData -> mData
-> mMassMatrixPr . mN = 4 ; simulationData -> mData -> mMassMatrixPr . mX =
tmp_m ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . d21wvb0imp ;
diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_g = ne_simulator_method ( ( NeslSimulator * ) rtDW
. p2ezmuppnc , NESL_SIM_MASSMATRIX , simulationData , diagnosticManager ) ;
if ( tmp_g != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) )
; if ( tmp ) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ;
ssSetErrorStatus ( rtS , msg_e ) ; } } } void MdlTerminate ( void ) { rt_FREE
( rtDW . bw5y0i4p2l . RSimInfoPtr ) ; neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . bob4xgg01l ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . i1wgzi3jpe ) ; nesl_erase_simulator (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . fzbhykh1xq ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . bakhwucptv ) ; nesl_erase_simulator (
"ParallelTestBench/BLDC Side Inertias/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . j1r4xwoi0i ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . pzexosznjb ) ; nesl_erase_simulator (
"ParallelTestBench/TMotorU15/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . hrke45uylg ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . iakvzasvoq ) ; nesl_erase_simulator (
"ParallelTestBench/TMotorU15/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; rt_FREE ( rtDW . jhtpgte2wi . RSimInfoPtr ) ;
rt_FREE ( rtDW . hvxajhbgno . RSimInfoPtr ) ; rt_FREE ( rtDW . fr1mfxzf32 .
RSimInfoPtr ) ; neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * )
rtDW . d21wvb0imp ) ; nesl_destroy_simulation_data ( ( NeslSimulationData * )
rtDW . hedrhiezbd ) ; nesl_erase_simulator (
"ParallelTestBench/ICE Side Inertias/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . ayv1jfdv3n ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . llxxjvefz5 ) ; nesl_erase_simulator (
"ParallelTestBench/ICE Side Inertias/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; } static void
mr_ParallelTestBench_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_ParallelTestBench_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_ParallelTestBench_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_ParallelTestBench_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_ParallelTestBench_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) ; static void
mr_ParallelTestBench_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_ParallelTestBench_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_ParallelTestBench_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_ParallelTestBench_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_ParallelTestBench_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_ParallelTestBench_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_ParallelTestBench_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_ParallelTestBench_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_ParallelTestBench_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_ParallelTestBench_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_ParallelTestBench_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_ParallelTestBench_GetDWork ( ) {
static const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" ,
"NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 ,
ssDWFieldNames ) ; mr_ParallelTestBench_cacheDataAsMxArray ( ssDW , 0 , 0 , (
const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char_T *
rtdwDataFieldNames [ 76 ] = { "rtDW.hjhhmazifh" , "rtDW.oudbjq0hed" ,
"rtDW.m4v13avdck" , "rtDW.a0ptfrtioc" , "rtDW.g3lob33pj5" , "rtDW.pyb4n2kdpt"
, "rtDW.e3d0a5oz4x" , "rtDW.pgf331hvhc" , "rtDW.bxrcqiwwif" ,
"rtDW.hbjtppjnxc" , "rtDW.oajcj2f1f5" , "rtDW.jny3tr51z3" , "rtDW.hvgg13kj3s"
, "rtDW.k1fhodjxic" , "rtDW.l5far1dd5s" , "rtDW.dgpg4jadhr" ,
"rtDW.aij0ldcei4" , "rtDW.cfefmj5zwg" , "rtDW.cern2voaws" , "rtDW.htxaynbdci"
, "rtDW.jclc1m30fx" , "rtDW.d05f353xni" , "rtDW.bmyjja4qwv" ,
"rtDW.dorteqrwse" , "rtDW.n0n2vuipdf" , "rtDW.ke0t5lasbz" , "rtDW.jcqddiyhqh"
, "rtDW.eixvkodrjc" , "rtDW.dtpp4iwgtx" , "rtDW.k5a5eyevvp" ,
"rtDW.l4dxiaonqg" , "rtDW.b2vnrg1jny" , "rtDW.ewedjye3z0" , "rtDW.d24a3iy2yr"
, "rtDW.nr541hf2w4" , "rtDW.jueswsqa1v" , "rtDW.cndm4gb520" ,
"rtDW.g5r1yktyf0" , "rtDW.pitowdgxye" , "rtDW.fxz4zvrdnk" , "rtDW.efurz0y3yi"
, "rtDW.pii1ltmep3" , "rtDW.jsvlghnnou" , "rtDW.mwn40uclws" ,
"rtDW.bnrzbkqovy" , "rtDW.hsbxk4y5en" , "rtDW.fs2zaamasz" , "rtDW.apx4aufauy"
, "rtDW.i0u0wqsccx" , "rtDW.bomurwpyov" , "rtDW.mjf1zdwwpb" ,
"rtDW.aeu2i4j0ln" , "rtDW.dd5lqxkqw1" , "rtDW.pkdoeu3vac" , "rtDW.iuutt5gbfx"
, "rtDW.ifu2rmppxs" , "rtDW.fe1jlxthwc" , "rtDW.jbdxmczt2f" ,
"rtDW.lpzxn11asy" , "rtDW.miza0bwslu" , "rtDW.okv3jznoxf" , "rtDW.ns1xtz2b4p"
, "rtDW.k11uca0ow3" , "rtDW.byziukqaaz" , "rtDW.fn0wimupx0" ,
"rtDW.cgq2mdkand" , "rtDW.auskljzuj1" , "rtDW.gnqj1fyav2" , "rtDW.hembao2eny"
, "rtDW.lbv1klntc2" , "rtDW.a2nmjrkqqq" , "rtDW.jnjyibka5j" ,
"rtDW.kkz3bigo3a" , "rtDW.iy5ftg1sqh" , "rtDW.n0kqgy2htn.iibbwx5nxu" ,
"rtDW.l55fduec5sc.iibbwx5nxu" , } ; mxArray * rtdwData = mxCreateStructMatrix
( 1 , 1 , 76 , rtdwDataFieldNames ) ; mr_ParallelTestBench_cacheDataAsMxArray
( rtdwData , 0 , 0 , ( const void * ) & ( rtDW . hjhhmazifh ) , sizeof ( rtDW
. hjhhmazifh ) ) ; mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 1
, ( const void * ) & ( rtDW . oudbjq0hed ) , sizeof ( rtDW . oudbjq0hed ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * )
& ( rtDW . m4v13avdck ) , sizeof ( rtDW . m4v13avdck ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * )
& ( rtDW . a0ptfrtioc ) , sizeof ( rtDW . a0ptfrtioc ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * )
& ( rtDW . g3lob33pj5 ) , sizeof ( rtDW . g3lob33pj5 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * )
& ( rtDW . pyb4n2kdpt ) , sizeof ( rtDW . pyb4n2kdpt ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * )
& ( rtDW . e3d0a5oz4x ) , sizeof ( rtDW . e3d0a5oz4x ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * )
& ( rtDW . pgf331hvhc ) , sizeof ( rtDW . pgf331hvhc ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * )
& ( rtDW . bxrcqiwwif ) , sizeof ( rtDW . bxrcqiwwif ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * )
& ( rtDW . hbjtppjnxc ) , sizeof ( rtDW . hbjtppjnxc ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void *
) & ( rtDW . oajcj2f1f5 ) , sizeof ( rtDW . oajcj2f1f5 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void *
) & ( rtDW . jny3tr51z3 ) , sizeof ( rtDW . jny3tr51z3 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void *
) & ( rtDW . hvgg13kj3s ) , sizeof ( rtDW . hvgg13kj3s ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void *
) & ( rtDW . k1fhodjxic ) , sizeof ( rtDW . k1fhodjxic ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void *
) & ( rtDW . l5far1dd5s ) , sizeof ( rtDW . l5far1dd5s ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void *
) & ( rtDW . dgpg4jadhr ) , sizeof ( rtDW . dgpg4jadhr ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void *
) & ( rtDW . aij0ldcei4 ) , sizeof ( rtDW . aij0ldcei4 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void *
) & ( rtDW . cfefmj5zwg ) , sizeof ( rtDW . cfefmj5zwg ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void *
) & ( rtDW . cern2voaws ) , sizeof ( rtDW . cern2voaws ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void *
) & ( rtDW . htxaynbdci ) , sizeof ( rtDW . htxaynbdci ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void *
) & ( rtDW . jclc1m30fx ) , sizeof ( rtDW . jclc1m30fx ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void *
) & ( rtDW . d05f353xni ) , sizeof ( rtDW . d05f353xni ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void *
) & ( rtDW . bmyjja4qwv ) , sizeof ( rtDW . bmyjja4qwv ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void *
) & ( rtDW . dorteqrwse ) , sizeof ( rtDW . dorteqrwse ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void *
) & ( rtDW . n0n2vuipdf ) , sizeof ( rtDW . n0n2vuipdf ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void *
) & ( rtDW . ke0t5lasbz ) , sizeof ( rtDW . ke0t5lasbz ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void *
) & ( rtDW . jcqddiyhqh ) , sizeof ( rtDW . jcqddiyhqh ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void *
) & ( rtDW . eixvkodrjc ) , sizeof ( rtDW . eixvkodrjc ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void *
) & ( rtDW . dtpp4iwgtx ) , sizeof ( rtDW . dtpp4iwgtx ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void *
) & ( rtDW . k5a5eyevvp ) , sizeof ( rtDW . k5a5eyevvp ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void *
) & ( rtDW . l4dxiaonqg ) , sizeof ( rtDW . l4dxiaonqg ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void *
) & ( rtDW . b2vnrg1jny ) , sizeof ( rtDW . b2vnrg1jny ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void *
) & ( rtDW . ewedjye3z0 ) , sizeof ( rtDW . ewedjye3z0 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void *
) & ( rtDW . d24a3iy2yr ) , sizeof ( rtDW . d24a3iy2yr ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void *
) & ( rtDW . nr541hf2w4 ) , sizeof ( rtDW . nr541hf2w4 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void *
) & ( rtDW . jueswsqa1v ) , sizeof ( rtDW . jueswsqa1v ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void *
) & ( rtDW . cndm4gb520 ) , sizeof ( rtDW . cndm4gb520 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void *
) & ( rtDW . g5r1yktyf0 ) , sizeof ( rtDW . g5r1yktyf0 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void *
) & ( rtDW . pitowdgxye ) , sizeof ( rtDW . pitowdgxye ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void *
) & ( rtDW . fxz4zvrdnk ) , sizeof ( rtDW . fxz4zvrdnk ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const void *
) & ( rtDW . efurz0y3yi ) , sizeof ( rtDW . efurz0y3yi ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void *
) & ( rtDW . pii1ltmep3 ) , sizeof ( rtDW . pii1ltmep3 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 42 , ( const void *
) & ( rtDW . jsvlghnnou ) , sizeof ( rtDW . jsvlghnnou ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const void *
) & ( rtDW . mwn40uclws ) , sizeof ( rtDW . mwn40uclws ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void *
) & ( rtDW . bnrzbkqovy ) , sizeof ( rtDW . bnrzbkqovy ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 45 , ( const void *
) & ( rtDW . hsbxk4y5en ) , sizeof ( rtDW . hsbxk4y5en ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const void *
) & ( rtDW . fs2zaamasz ) , sizeof ( rtDW . fs2zaamasz ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void *
) & ( rtDW . apx4aufauy ) , sizeof ( rtDW . apx4aufauy ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 48 , ( const void *
) & ( rtDW . i0u0wqsccx ) , sizeof ( rtDW . i0u0wqsccx ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 49 , ( const void *
) & ( rtDW . bomurwpyov ) , sizeof ( rtDW . bomurwpyov ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 50 , ( const void *
) & ( rtDW . mjf1zdwwpb ) , sizeof ( rtDW . mjf1zdwwpb ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 51 , ( const void *
) & ( rtDW . aeu2i4j0ln ) , sizeof ( rtDW . aeu2i4j0ln ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 52 , ( const void *
) & ( rtDW . dd5lqxkqw1 ) , sizeof ( rtDW . dd5lqxkqw1 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 53 , ( const void *
) & ( rtDW . pkdoeu3vac ) , sizeof ( rtDW . pkdoeu3vac ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 54 , ( const void *
) & ( rtDW . iuutt5gbfx ) , sizeof ( rtDW . iuutt5gbfx ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 55 , ( const void *
) & ( rtDW . ifu2rmppxs ) , sizeof ( rtDW . ifu2rmppxs ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 56 , ( const void *
) & ( rtDW . fe1jlxthwc ) , sizeof ( rtDW . fe1jlxthwc ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 57 , ( const void *
) & ( rtDW . jbdxmczt2f ) , sizeof ( rtDW . jbdxmczt2f ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 58 , ( const void *
) & ( rtDW . lpzxn11asy ) , sizeof ( rtDW . lpzxn11asy ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 59 , ( const void *
) & ( rtDW . miza0bwslu ) , sizeof ( rtDW . miza0bwslu ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 60 , ( const void *
) & ( rtDW . okv3jznoxf ) , sizeof ( rtDW . okv3jznoxf ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 61 , ( const void *
) & ( rtDW . ns1xtz2b4p ) , sizeof ( rtDW . ns1xtz2b4p ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 62 , ( const void *
) & ( rtDW . k11uca0ow3 ) , sizeof ( rtDW . k11uca0ow3 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 63 , ( const void *
) & ( rtDW . byziukqaaz ) , sizeof ( rtDW . byziukqaaz ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 64 , ( const void *
) & ( rtDW . fn0wimupx0 ) , sizeof ( rtDW . fn0wimupx0 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 65 , ( const void *
) & ( rtDW . cgq2mdkand ) , sizeof ( rtDW . cgq2mdkand ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 66 , ( const void *
) & ( rtDW . auskljzuj1 ) , sizeof ( rtDW . auskljzuj1 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 67 , ( const void *
) & ( rtDW . gnqj1fyav2 ) , sizeof ( rtDW . gnqj1fyav2 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 68 , ( const void *
) & ( rtDW . hembao2eny ) , sizeof ( rtDW . hembao2eny ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 69 , ( const void *
) & ( rtDW . lbv1klntc2 ) , sizeof ( rtDW . lbv1klntc2 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 70 , ( const void *
) & ( rtDW . a2nmjrkqqq ) , sizeof ( rtDW . a2nmjrkqqq ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 71 , ( const void *
) & ( rtDW . jnjyibka5j ) , sizeof ( rtDW . jnjyibka5j ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 72 , ( const void *
) & ( rtDW . kkz3bigo3a ) , sizeof ( rtDW . kkz3bigo3a ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 73 , ( const void *
) & ( rtDW . iy5ftg1sqh ) , sizeof ( rtDW . iy5ftg1sqh ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 74 , ( const void *
) & ( rtDW . n0kqgy2htn . iibbwx5nxu ) , sizeof ( rtDW . n0kqgy2htn .
iibbwx5nxu ) ) ; mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 75
, ( const void * ) & ( rtDW . l55fduec5sc . iibbwx5nxu ) , sizeof ( rtDW .
l55fduec5sc . iibbwx5nxu ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData )
; } return ssDW ; } void mr_ParallelTestBench_SetDWork ( const mxArray * ssDW
) { ( void ) ssDW ; mr_ParallelTestBench_restoreDataFromMxArray ( ( void * )
& ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hjhhmazifh ) , rtdwData , 0 , 0 , sizeof ( rtDW . hjhhmazifh ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
oudbjq0hed ) , rtdwData , 0 , 1 , sizeof ( rtDW . oudbjq0hed ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
m4v13avdck ) , rtdwData , 0 , 2 , sizeof ( rtDW . m4v13avdck ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
a0ptfrtioc ) , rtdwData , 0 , 3 , sizeof ( rtDW . a0ptfrtioc ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
g3lob33pj5 ) , rtdwData , 0 , 4 , sizeof ( rtDW . g3lob33pj5 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pyb4n2kdpt ) , rtdwData , 0 , 5 , sizeof ( rtDW . pyb4n2kdpt ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
e3d0a5oz4x ) , rtdwData , 0 , 6 , sizeof ( rtDW . e3d0a5oz4x ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pgf331hvhc ) , rtdwData , 0 , 7 , sizeof ( rtDW . pgf331hvhc ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bxrcqiwwif ) , rtdwData , 0 , 8 , sizeof ( rtDW . bxrcqiwwif ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hbjtppjnxc ) , rtdwData , 0 , 9 , sizeof ( rtDW . hbjtppjnxc ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
oajcj2f1f5 ) , rtdwData , 0 , 10 , sizeof ( rtDW . oajcj2f1f5 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jny3tr51z3 ) , rtdwData , 0 , 11 , sizeof ( rtDW . jny3tr51z3 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hvgg13kj3s ) , rtdwData , 0 , 12 , sizeof ( rtDW . hvgg13kj3s ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
k1fhodjxic ) , rtdwData , 0 , 13 , sizeof ( rtDW . k1fhodjxic ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
l5far1dd5s ) , rtdwData , 0 , 14 , sizeof ( rtDW . l5far1dd5s ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dgpg4jadhr ) , rtdwData , 0 , 15 , sizeof ( rtDW . dgpg4jadhr ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
aij0ldcei4 ) , rtdwData , 0 , 16 , sizeof ( rtDW . aij0ldcei4 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cfefmj5zwg ) , rtdwData , 0 , 17 , sizeof ( rtDW . cfefmj5zwg ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cern2voaws ) , rtdwData , 0 , 18 , sizeof ( rtDW . cern2voaws ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
htxaynbdci ) , rtdwData , 0 , 19 , sizeof ( rtDW . htxaynbdci ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jclc1m30fx ) , rtdwData , 0 , 20 , sizeof ( rtDW . jclc1m30fx ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
d05f353xni ) , rtdwData , 0 , 21 , sizeof ( rtDW . d05f353xni ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bmyjja4qwv ) , rtdwData , 0 , 22 , sizeof ( rtDW . bmyjja4qwv ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dorteqrwse ) , rtdwData , 0 , 23 , sizeof ( rtDW . dorteqrwse ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
n0n2vuipdf ) , rtdwData , 0 , 24 , sizeof ( rtDW . n0n2vuipdf ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ke0t5lasbz ) , rtdwData , 0 , 25 , sizeof ( rtDW . ke0t5lasbz ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jcqddiyhqh ) , rtdwData , 0 , 26 , sizeof ( rtDW . jcqddiyhqh ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
eixvkodrjc ) , rtdwData , 0 , 27 , sizeof ( rtDW . eixvkodrjc ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dtpp4iwgtx ) , rtdwData , 0 , 28 , sizeof ( rtDW . dtpp4iwgtx ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
k5a5eyevvp ) , rtdwData , 0 , 29 , sizeof ( rtDW . k5a5eyevvp ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
l4dxiaonqg ) , rtdwData , 0 , 30 , sizeof ( rtDW . l4dxiaonqg ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
b2vnrg1jny ) , rtdwData , 0 , 31 , sizeof ( rtDW . b2vnrg1jny ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ewedjye3z0 ) , rtdwData , 0 , 32 , sizeof ( rtDW . ewedjye3z0 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
d24a3iy2yr ) , rtdwData , 0 , 33 , sizeof ( rtDW . d24a3iy2yr ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nr541hf2w4 ) , rtdwData , 0 , 34 , sizeof ( rtDW . nr541hf2w4 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jueswsqa1v ) , rtdwData , 0 , 35 , sizeof ( rtDW . jueswsqa1v ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cndm4gb520 ) , rtdwData , 0 , 36 , sizeof ( rtDW . cndm4gb520 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
g5r1yktyf0 ) , rtdwData , 0 , 37 , sizeof ( rtDW . g5r1yktyf0 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pitowdgxye ) , rtdwData , 0 , 38 , sizeof ( rtDW . pitowdgxye ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
fxz4zvrdnk ) , rtdwData , 0 , 39 , sizeof ( rtDW . fxz4zvrdnk ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
efurz0y3yi ) , rtdwData , 0 , 40 , sizeof ( rtDW . efurz0y3yi ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pii1ltmep3 ) , rtdwData , 0 , 41 , sizeof ( rtDW . pii1ltmep3 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jsvlghnnou ) , rtdwData , 0 , 42 , sizeof ( rtDW . jsvlghnnou ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mwn40uclws ) , rtdwData , 0 , 43 , sizeof ( rtDW . mwn40uclws ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bnrzbkqovy ) , rtdwData , 0 , 44 , sizeof ( rtDW . bnrzbkqovy ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hsbxk4y5en ) , rtdwData , 0 , 45 , sizeof ( rtDW . hsbxk4y5en ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
fs2zaamasz ) , rtdwData , 0 , 46 , sizeof ( rtDW . fs2zaamasz ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
apx4aufauy ) , rtdwData , 0 , 47 , sizeof ( rtDW . apx4aufauy ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
i0u0wqsccx ) , rtdwData , 0 , 48 , sizeof ( rtDW . i0u0wqsccx ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bomurwpyov ) , rtdwData , 0 , 49 , sizeof ( rtDW . bomurwpyov ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mjf1zdwwpb ) , rtdwData , 0 , 50 , sizeof ( rtDW . mjf1zdwwpb ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
aeu2i4j0ln ) , rtdwData , 0 , 51 , sizeof ( rtDW . aeu2i4j0ln ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dd5lqxkqw1 ) , rtdwData , 0 , 52 , sizeof ( rtDW . dd5lqxkqw1 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pkdoeu3vac ) , rtdwData , 0 , 53 , sizeof ( rtDW . pkdoeu3vac ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
iuutt5gbfx ) , rtdwData , 0 , 54 , sizeof ( rtDW . iuutt5gbfx ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ifu2rmppxs ) , rtdwData , 0 , 55 , sizeof ( rtDW . ifu2rmppxs ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
fe1jlxthwc ) , rtdwData , 0 , 56 , sizeof ( rtDW . fe1jlxthwc ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jbdxmczt2f ) , rtdwData , 0 , 57 , sizeof ( rtDW . jbdxmczt2f ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lpzxn11asy ) , rtdwData , 0 , 58 , sizeof ( rtDW . lpzxn11asy ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
miza0bwslu ) , rtdwData , 0 , 59 , sizeof ( rtDW . miza0bwslu ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
okv3jznoxf ) , rtdwData , 0 , 60 , sizeof ( rtDW . okv3jznoxf ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ns1xtz2b4p ) , rtdwData , 0 , 61 , sizeof ( rtDW . ns1xtz2b4p ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
k11uca0ow3 ) , rtdwData , 0 , 62 , sizeof ( rtDW . k11uca0ow3 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
byziukqaaz ) , rtdwData , 0 , 63 , sizeof ( rtDW . byziukqaaz ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
fn0wimupx0 ) , rtdwData , 0 , 64 , sizeof ( rtDW . fn0wimupx0 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cgq2mdkand ) , rtdwData , 0 , 65 , sizeof ( rtDW . cgq2mdkand ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
auskljzuj1 ) , rtdwData , 0 , 66 , sizeof ( rtDW . auskljzuj1 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gnqj1fyav2 ) , rtdwData , 0 , 67 , sizeof ( rtDW . gnqj1fyav2 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hembao2eny ) , rtdwData , 0 , 68 , sizeof ( rtDW . hembao2eny ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lbv1klntc2 ) , rtdwData , 0 , 69 , sizeof ( rtDW . lbv1klntc2 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
a2nmjrkqqq ) , rtdwData , 0 , 70 , sizeof ( rtDW . a2nmjrkqqq ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jnjyibka5j ) , rtdwData , 0 , 71 , sizeof ( rtDW . jnjyibka5j ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
kkz3bigo3a ) , rtdwData , 0 , 72 , sizeof ( rtDW . kkz3bigo3a ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
iy5ftg1sqh ) , rtdwData , 0 , 73 , sizeof ( rtDW . iy5ftg1sqh ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
n0kqgy2htn . iibbwx5nxu ) , rtdwData , 0 , 74 , sizeof ( rtDW . n0kqgy2htn .
iibbwx5nxu ) ) ; mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & (
rtDW . l55fduec5sc . iibbwx5nxu ) , rtdwData , 0 , 75 , sizeof ( rtDW .
l55fduec5sc . iibbwx5nxu ) ) ; } } mxArray *
mr_ParallelTestBench_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 10 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 10 ] = { "Scope" , "SimscapeExecutionBlock" ,
"SimscapeExecutionBlock" , "SimscapeExecutionBlock" ,
"SimscapeExecutionBlock" , "SimscapeExecutionBlock" ,
"SimscapeExecutionBlock" , "Scope" , "Scope" , "Scope" , } ; static const
char_T * blockPath [ 10 ] = { "ParallelTestBench/Battery Voltage" ,
"ParallelTestBench/BLDC Side Inertias/Solver Configuration/EVAL_KEY/STATE_1"
,
"ParallelTestBench/BLDC Side Inertias/Solver Configuration/EVAL_KEY/OUTPUT_1_0"
, "ParallelTestBench/TMotorU15/Solver Configuration/EVAL_KEY/STATE_1" ,
"ParallelTestBench/TMotorU15/Solver Configuration/EVAL_KEY/OUTPUT_1_0" ,
"ParallelTestBench/ICE Side Inertias/Solver Configuration/EVAL_KEY/STATE_1" ,
"ParallelTestBench/ICE Side Inertias/Solver Configuration/EVAL_KEY/OUTPUT_1_0"
, "ParallelTestBench/Clutch Speeds" , "ParallelTestBench/Dyno Voltage" ,
"ParallelTestBench/Engine Power" , } ; static const int reason [ 10 ] = { 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] <
10 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript (
data , 2 , subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [
subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2
, subs ) ; mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0
] ] ) ) ; subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs
[ 0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 26 ) ; ssSetNumPeriodicContStates ( rtS , 2 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 489 ) ;
ssSetNumBlockIO ( rtS , 142 ) ; ssSetNumBlockParams ( rtS , 1164 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 5.0E-5 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2006713274U ) ; ssSetChecksumVal ( rtS , 1 ,
243113040U ) ; ssSetChecksumVal ( rtS , 2 , 2648925310U ) ; ssSetChecksumVal
( rtS , 3 , 2781112266U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 4 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { rtDW . nr541hf2w4 = 3 ; rtDW . jueswsqa1v = 9 ;
rtDW . cndm4gb520 = 14 ; } { static DataTypeTransInfo dtInfo ; ( void )
memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 23 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } ParallelTestBench_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"ParallelTestBench" ) ; ssSetPath ( rtS , "ParallelTestBench" ) ; ssSetTStart
( rtS , 0.0 ) ; ssSetTFinal ( rtS , 300.0 ) ; ssSetStepSize ( rtS , 5.0E-5 )
; ssSetFixedStepSize ( rtS , 5.0E-5 ) ; ssSetSolverExtrapolationOrder ( rtS ,
4 ) ; ssSetSolverNumberNewtonIterations ( rtS , 1 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions
[ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "Discrete" , "FirstOutput" , "Discrete" , "FirstOutput" ,
"Discrete" , "FirstOutput" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "Discrete" , "FirstOutput" , "FirstOutput" } ; static const char_T
* rt_LoggedStateBlockNames [ ] = {
"ParallelTestBench/Datasheet Battery/Output Filter/Integrator" ,
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Int"
, "ParallelTestBench/BLDC Side Inertias/Simulink-PS\nConverter2" ,
"ParallelTestBench/BLDC Side Inertias/BLDC Shaft" ,
"ParallelTestBench/BLDC Side Inertias/BLDC Shaft" ,
"ParallelTestBench/BLDC Side Inertias/Clutch Rotor" ,
"ParallelTestBench/BLDC Side Inertias/Ideal Rotational Motion Sensor" ,
"ParallelTestBench/BLDC Side Inertias/Clutch Rotor" ,
"ParallelTestBench/TMotorU15/Simulink-PS\nConverter2" ,
"ParallelTestBench/TMotorU15/Flexible Shaft1" ,
"ParallelTestBench/TMotorU15/Flexible Shaft1" ,
"ParallelTestBench/TMotorU15/Ideal Rotational Motion Sensor" ,
"ParallelTestBench/TMotorU15/Flexible Shaft1" ,
"ParallelTestBench/ICE Side Inertias/Simulink-PS\nConverter2" ,
"ParallelTestBench/ICE Side Inertias/Inertia sum of Post ICE Rigid Bodies" ,
"ParallelTestBench/ICE Side Inertias/Ideal Rotational Motion Sensor" ,
"ParallelTestBench/ICE Side Inertias/Inertia sum of Post ICE Rigid Bodies" ,
"ParallelTestBench/ICE Side Inertias/Inertia sum of Post ICE Rigid Bodies" ,
"ParallelTestBench/Integrator" ,
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Integrator"
,
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/Mechanical and Angle/Int1"
,
 "ParallelTestBench/SKP 6485/PMSM Torque Input Exterior Continuous/PMSM Torque Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Integrator"
,
 "ParallelTestBench/Datasheet Battery/Datasheet Battery External/Datasheet Battery/Charge Model/Integrator\nLimited"
, "ParallelTestBench/Corvid-50/Engine Crank Angle Calculation/Integrator" ,
"ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Simulink-PS\nConverter2"
,
 "ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Ideal Rotational Motion Sensor"
,
 "ParallelTestBench/BLDC Side Inertias/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1"
,
 "ParallelTestBench/BLDC Side Inertias/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1"
, "ParallelTestBench/TMotorU15/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1" ,
"ParallelTestBench/TMotorU15/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1" ,
"ParallelTestBench/ICE Side Inertias/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1"
,
"ParallelTestBench/ICE Side Inertias/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1"
,
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/State Filter/Discrete-Time\nIntegrator"
,
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Motion control/Discrete-Time\nIntegrator"
,
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Motion control/Discrete-Time\nIntegrator1"
,
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator/Unit Delay"
,
 "ParallelTestBench/Surface Mount PM Controller1/Exterior PMSM Speed Control Drive CE/PMSM Speed Control Exterior/Current Controller External/DQ Current Control and Decouple/Integrator1/Unit Delay"
,
 "ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1"
,
 "ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1"
,
 "ParallelTestBench/Clutch/Clutch Engaged, Rated Torque/Solver\nConfiguration/EVAL_KEY/LTI_STATE_1"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" ,
 "ParallelTestBench.BLDC_Side_Inertias.Simulink_PS_Converter2.outputFiltered_2660058252_0"
, "ParallelTestBench.BLDC_Side_Inertias.BLDC_Shaft.phi" ,
"ParallelTestBench.BLDC_Side_Inertias.BLDC_Shaft.torsional_inertia.w" ,
"ParallelTestBench.BLDC_Side_Inertias.Clutch_Rotor.phi" ,
"ParallelTestBench.BLDC_Side_Inertias.Ideal_Rotational_Motion_Sensor.phi" ,
"ParallelTestBench.BLDC_Side_Inertias.Clutch_Rotor.torsional_inertia.t" ,
"ParallelTestBench.TMotorU15.Simulink_PS_Converter2.outputFiltered_2829007336_0"
, "ParallelTestBench.TMotorU15.Flexible_Shaft1.phi" ,
"ParallelTestBench.TMotorU15.Flexible_Shaft1.torsional_inertia.w" ,
"ParallelTestBench.TMotorU15.Ideal_Rotational_Motion_Sensor.phi" ,
"ParallelTestBench.TMotorU15.Flexible_Shaft1.torsional_inertia.t" ,
 "ParallelTestBench.ICE_Side_Inertias.Simulink_PS_Converter2.outputFiltered_3597062310_0"
,
 "ParallelTestBench.ICE_Side_Inertias.Inertia_sum_of_Post_ICE_Rigid_Bodies.torsional_inertia.w"
, "ParallelTestBench.ICE_Side_Inertias.Ideal_Rotational_Motion_Sensor.phi" ,
"ParallelTestBench.ICE_Side_Inertias.Inertia_sum_of_Post_ICE_Rigid_Bodies.phi"
,
 "ParallelTestBench.ICE_Side_Inertias.Inertia_sum_of_Post_ICE_Rigid_Bodies.torsional_inertia.t"
, "" , "" , "" , "" , "" , "" ,
 "ParallelTestBench.Clutch.Clutch_Engaged_Rated_Torque.Simulink_PS_Converter2.outputFiltered_3153367073_0"
,
 "ParallelTestBench.Clutch.Clutch_Engaged_Rated_Torque.Ideal_Rotational_Motion_Sensor.phi"
, "Discrete" , "FirstOutput" , "Discrete" , "FirstOutput" , "Discrete" ,
"FirstOutput" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"Discrete" , "FirstOutput" , "FirstOutput" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 ,
2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 0 , 1 , 2 , 3 ,
4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 40 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 40 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . hjvfmqrotz ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . hterznv3np ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . eap5trepgw ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . dinj2vqkhf [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . dinj2vqkhf [ 1 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . dinj2vqkhf [ 2 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . dinj2vqkhf [ 3 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . dinj2vqkhf [ 4 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . fpxoom5wcz ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . cmzleelpyc [ 0 ] ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . cmzleelpyc [ 1 ] ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . cmzleelpyc [ 2 ] ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . cmzleelpyc [ 3 ] ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . itgqcjsbx5 ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . o3f51d5jei [ 0 ] ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . o3f51d5jei [ 1 ] ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . o3f51d5jei [ 2 ] ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . o3f51d5jei [ 3 ] ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . it0jfj1ga4 ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . almmbag3ud ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtX . pntygaqlkb ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtX . ju22bzmclv ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) & rtX . k0f2ivlpoh ;
rt_LoggedStateSignalPtrs [ 23 ] = ( void * ) & rtX . lcxpannrra ;
rt_LoggedStateSignalPtrs [ 24 ] = ( void * ) & rtX . hlra0g33ul ;
rt_LoggedStateSignalPtrs [ 25 ] = ( void * ) & rtX . mw03mcasf2 ;
rt_LoggedStateSignalPtrs [ 26 ] = ( void * ) & rtDW . hjhhmazifh ;
rt_LoggedStateSignalPtrs [ 27 ] = ( void * ) & rtDW . oudbjq0hed ;
rt_LoggedStateSignalPtrs [ 28 ] = ( void * ) & rtDW . m4v13avdck ;
rt_LoggedStateSignalPtrs [ 29 ] = ( void * ) & rtDW . a0ptfrtioc ;
rt_LoggedStateSignalPtrs [ 30 ] = ( void * ) & rtDW . g3lob33pj5 ;
rt_LoggedStateSignalPtrs [ 31 ] = ( void * ) & rtDW . pyb4n2kdpt ;
rt_LoggedStateSignalPtrs [ 32 ] = ( void * ) & rtDW . e3d0a5oz4x ;
rt_LoggedStateSignalPtrs [ 33 ] = ( void * ) & rtDW . pgf331hvhc ;
rt_LoggedStateSignalPtrs [ 34 ] = ( void * ) & rtDW . bxrcqiwwif ;
rt_LoggedStateSignalPtrs [ 35 ] = ( void * ) & rtDW . hbjtppjnxc ;
rt_LoggedStateSignalPtrs [ 36 ] = ( void * ) & rtDW . oajcj2f1f5 ;
rt_LoggedStateSignalPtrs [ 37 ] = ( void * ) & rtDW . jny3tr51z3 ;
rt_LoggedStateSignalPtrs [ 38 ] = ( void * ) & rtDW . hvgg13kj3s ;
rt_LoggedStateSignalPtrs [ 39 ] = ( void * ) & rtDW . k1fhodjxic ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ;
ssSetPeriodicContStateIndices ( rtS , rtPeriodicIndX ) ; ( void ) memset ( (
void * ) rtPeriodicIndX , 0 , 2 * sizeof ( int_T ) ) ;
ssSetPeriodicContStateRanges ( rtS , rtPeriodicRngX ) ; ( void ) memset ( (
void * ) rtPeriodicRngX , 0 , 4 * sizeof ( real_T ) ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3
; static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 26 ] ; static ssNonContDerivSigInfo nonContDerivSigInfo
[ 2 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . bdpeazbcik ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . bvlzron2lo ) , (
NULL ) } } ; ssSetNumNonContDerivSigInfos ( rtS , 2 ) ;
ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ; ssSetSolverInfo (
rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode14x" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
1 ) ; ( void ) memset ( ( void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 )
) ; ssSetModelMethods2 ( rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * )
& mdlMethods3 , 0 , sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , &
mdlMethods3 ) ; ssSetModelProjection ( rtS , MdlProjection ) ;
ssSetMassMatrixType ( rtS , ( ssMatrixType ) 1 ) ; ssSetMassMatrixNzMax ( rtS
, 26 ) ; ssSetModelMassMatrix ( rtS , MdlMassMatrix ) ;
ssSetModelForcingFunction ( rtS , MdlForcingFunction ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 1 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 26 ) ; ssSetModelOutputs ( rtS ,
MdlOutputs ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives (
rtS , MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; { int_T * ir =
rtMassMatrix . ir ; int_T * jc = rtMassMatrix . jc ; real_T * pr =
rtMassMatrix . pr ; ssSetMassMatrixIr ( rtS , ir ) ; ssSetMassMatrixJc ( rtS
, jc ) ; ssSetMassMatrixPr ( rtS , pr ) ; ( void ) memset ( ( void * ) ir , 0
, 26 * sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) jc , 0 , ( 26 + 1 )
* sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) pr , 0 , 26 * sizeof (
real_T ) ) ; } } ssSetChecksumVal ( rtS , 0 , 2006713274U ) ;
ssSetChecksumVal ( rtS , 1 , 243113040U ) ; ssSetChecksumVal ( rtS , 2 ,
2648925310U ) ; ssSetChecksumVal ( rtS , 3 , 2781112266U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 32 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . cgq2mdkand ; systemRan [ 2 ] = ( sysRanDType * ) &
rtDW . auskljzuj1 ; systemRan [ 3 ] = ( sysRanDType * ) & rtDW . okv3jznoxf ;
systemRan [ 4 ] = ( sysRanDType * ) & rtDW . byziukqaaz ; systemRan [ 5 ] = (
sysRanDType * ) & rtDW . fn0wimupx0 ; systemRan [ 6 ] = ( sysRanDType * ) &
rtDW . ns1xtz2b4p ; systemRan [ 7 ] = & rtAlwaysEnabled ; systemRan [ 8 ] = (
sysRanDType * ) & rtDW . miza0bwslu ; systemRan [ 9 ] = ( sysRanDType * ) &
rtDW . n0kqgy2htn . iibbwx5nxu ; systemRan [ 10 ] = ( sysRanDType * ) & rtDW
. l55fduec5sc . iibbwx5nxu ; systemRan [ 11 ] = ( sysRanDType * ) & rtDW .
lpzxn11asy ; systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = &
rtAlwaysEnabled ; systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = &
rtAlwaysEnabled ; systemRan [ 16 ] = ( sysRanDType * ) & rtDW . jbdxmczt2f ;
systemRan [ 17 ] = ( sysRanDType * ) & rtDW . jbdxmczt2f ; systemRan [ 18 ] =
( sysRanDType * ) & rtDW . fe1jlxthwc ; systemRan [ 19 ] = ( sysRanDType * )
& rtDW . aeu2i4j0ln ; systemRan [ 20 ] = ( sysRanDType * ) & rtDW .
pkdoeu3vac ; systemRan [ 21 ] = ( sysRanDType * ) & rtDW . iuutt5gbfx ;
systemRan [ 22 ] = ( sysRanDType * ) & rtDW . aeu2i4j0ln ; systemRan [ 23 ] =
( sysRanDType * ) & rtDW . ifu2rmppxs ; systemRan [ 24 ] = ( sysRanDType * )
& rtDW . bomurwpyov ; systemRan [ 25 ] = ( sysRanDType * ) & rtDW .
mwn40uclws ; systemRan [ 26 ] = ( sysRanDType * ) & rtDW . bnrzbkqovy ;
systemRan [ 27 ] = ( sysRanDType * ) & rtDW . fs2zaamasz ; systemRan [ 28 ] =
( sysRanDType * ) & rtDW . apx4aufauy ; systemRan [ 29 ] = ( sysRanDType * )
& rtDW . bnrzbkqovy ; systemRan [ 30 ] = ( sysRanDType * ) & rtDW .
pii1ltmep3 ; systemRan [ 31 ] = ( sysRanDType * ) & rtDW . i0u0wqsccx ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_ParallelTestBench_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_ParallelTestBench_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_ParallelTestBench_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID2 ( tid ) ; }
