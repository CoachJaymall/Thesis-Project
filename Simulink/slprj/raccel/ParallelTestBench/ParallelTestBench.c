#include "ParallelTestBench.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "ParallelTestBench_private.h"
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
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
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
rtPeriodicRngX ; static SimStruct model_S ; SimStruct * const rtS = & model_S
; real_T look1_binlcapw ( real_T u0 , const real_T bp0 [ ] , const real_T
table [ ] , uint32_T maxIndex ) { real_T frac ; real_T y ; real_T yL_0d0 ;
uint32_T bpIdx ; uint32_T iLeft ; uint32_T iRght ; if ( u0 <= bp0 [ 0U ] ) {
iLeft = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx =
maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U )
{ if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; }
bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [
iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex ; frac = 0.0 ; }
if ( iLeft == maxIndex ) { y = table [ iLeft ] ; } else { yL_0d0 = table [
iLeft ] ; y = ( table [ iLeft + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } return y
; } real_T look2_binlcapw ( real_T u0 , real_T u1 , const real_T bp0 [ ] ,
const real_T bp1 [ ] , const real_T table [ ] , const uint32_T maxIndex [ ] ,
uint32_T stride ) { real_T fractions [ 2 ] ; real_T frac ; real_T y ; real_T
yL_0d0 ; uint32_T bpIndices [ 2 ] ; uint32_T bpIdx ; uint32_T iLeft ;
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
y += ( yL_0d0 - y ) * frac ; } return y ; } real_T look2_binlcpw ( real_T u0
, real_T u1 , const real_T bp0 [ ] , const real_T bp1 [ ] , const real_T
table [ ] , const uint32_T maxIndex [ ] , uint32_T stride ) { real_T
fractions [ 2 ] ; real_T frac ; real_T yL_0d0 ; real_T yL_0d1 ; uint32_T
bpIndices [ 2 ] ; uint32_T bpIdx ; uint32_T iLeft ; uint32_T iRght ; if ( u0
<= bp0 [ 0U ] ) { iLeft = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [ maxIndex [
0U ] ] ) { bpIdx = maxIndex [ 0U ] >> 1U ; iLeft = 0U ; iRght = maxIndex [ 0U
] ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx
; } else { iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0
- bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft =
maxIndex [ 0U ] - 1U ; frac = 1.0 ; } fractions [ 0U ] = frac ; bpIndices [
0U ] = iLeft ; if ( u1 <= bp1 [ 0U ] ) { iLeft = 0U ; frac = 0.0 ; } else if
( u1 < bp1 [ maxIndex [ 1U ] ] ) { bpIdx = maxIndex [ 1U ] >> 1U ; iLeft = 0U
; iRght = maxIndex [ 1U ] ; while ( iRght - iLeft > 1U ) { if ( u1 < bp1 [
bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght +
iLeft ) >> 1U ; } frac = ( u1 - bp1 [ iLeft ] ) / ( bp1 [ iLeft + 1U ] - bp1
[ iLeft ] ) ; } else { iLeft = maxIndex [ 1U ] - 1U ; frac = 1.0 ; } bpIdx =
iLeft * stride + bpIndices [ 0U ] ; yL_0d0 = table [ bpIdx ] ; yL_0d0 += (
table [ bpIdx + 1U ] - yL_0d0 ) * fractions [ 0U ] ; bpIdx += stride ; yL_0d1
= table [ bpIdx ] ; return ( ( ( table [ bpIdx + 1U ] - yL_0d1 ) * fractions
[ 0U ] + yL_0d1 ) - yL_0d0 ) * frac + yL_0d0 ; } void MdlInitialize ( void )
{ boolean_T tmp ; rtDW . i3v3y1llki = 1 ; if ( ssIsFirstInitCond ( rtS ) ) {
rtX . hn3bvj4yke = 0.0 ; tmp = slIsRapidAcceleratorSimulating ( ) ; if ( tmp
) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . i3v3y1llki = !
tmp ; } else { rtDW . i3v3y1llki = 1 ; } rtX . fj24d5zbvw = 0.0 ; } rtDW .
dokiorwuv5 = 1 ; if ( ssIsFirstInitCond ( rtS ) ) { tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . dokiorwuv5 = ! tmp ; }
else { rtDW . dokiorwuv5 = 1 ; } rtX . kaplaxkjn0 = 0.0 ; } rtDW . jlyvcbibun
= 1 ; if ( ssIsFirstInitCond ( rtS ) ) { tmp = slIsRapidAcceleratorSimulating
( ) ; if ( tmp ) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW .
jlyvcbibun = ! tmp ; } else { rtDW . jlyvcbibun = 1 ; } rtX . fipmzwg11t =
0.0 ; } rtDW . njopz31ksb = 1 ; if ( ssIsFirstInitCond ( rtS ) ) { tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . njopz31ksb = ! tmp ; }
else { rtDW . njopz31ksb = 1 ; } rtX . nk053321hc = 0.0 ; } rtDW . le5se2ckp5
= 1 ; if ( ssIsFirstInitCond ( rtS ) ) { tmp = slIsRapidAcceleratorSimulating
( ) ; if ( tmp ) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW .
le5se2ckp5 = ! tmp ; } else { rtDW . le5se2ckp5 = 1 ; } } rtX . c4ef21aibh =
rtP . Integrator_IC ; rtX . mwc2guobfc = rtP . Integrator_IC_lrmnxeinqj ; {
int_T rootPeriodicContStateIndices [ 1 ] = { 6 } ; real_T
rootPeriodicContStateRanges [ 2 ] = { 0.0 , 720.0 } ; ( void ) memcpy ( (
void * ) rtPeriodicIndX , rootPeriodicContStateIndices , 1 * sizeof ( int_T )
) ; ( void ) memcpy ( ( void * ) rtPeriodicRngX , rootPeriodicContStateRanges
, 2 * sizeof ( real_T ) ) ; } } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtB . nfowuituae = rtP . BLDC_Id_init ; rtB . aijej34sel = rtP .
BLDC_Th_init ; rtB . cfptusc1o2 = rtP . BLDC_Iq_init ; rtB . jhspkh2pnv = rtP
. BLDC_Omega_init ; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) {
real_T j0xjhwkbwm [ 9 ] ; real_T n1i1cg25dg [ 3 ] ; real_T cunhphcmit ;
real_T e2zgigtlb2 ; real_T eyzb0jsp5f ; real_T frjn33kjtr_idx_0 ; real_T
frjn33kjtr_idx_1 ; real_T frjn33kjtr_idx_2 ; real_T ku440utps3 ; real_T
nrr2pzozjj ; real_T o1pfazzsdy ; real_T pmfzxtedhi ; int32_T i ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtDW . i3v3y1llki != 0 ) { rtX .
hn3bvj4yke = rtB . pxpvevgrie ; } if ( rtX . hn3bvj4yke >= rtP .
DatasheetBattery_BattChargeMax ) { if ( rtX . hn3bvj4yke != rtP .
DatasheetBattery_BattChargeMax ) { rtX . hn3bvj4yke = rtP .
DatasheetBattery_BattChargeMax ; ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; } } else if ( ( rtX . hn3bvj4yke <= rtP . IntegratorLimited_LowerSat
) && ( rtX . hn3bvj4yke != rtP . IntegratorLimited_LowerSat ) ) { rtX .
hn3bvj4yke = rtP . IntegratorLimited_LowerSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } e2zgigtlb2 = rtX .
hn3bvj4yke ; } else if ( rtX . hn3bvj4yke >= rtP .
DatasheetBattery_BattChargeMax ) { e2zgigtlb2 = rtP .
DatasheetBattery_BattChargeMax ; } else if ( rtX . hn3bvj4yke <= rtP .
IntegratorLimited_LowerSat ) { e2zgigtlb2 = rtP . IntegratorLimited_LowerSat
; } else { e2zgigtlb2 = rtX . hn3bvj4yke ; } rtB . fdyvfxa4tp = e2zgigtlb2 /
rtP . DatasheetBattery_BattChargeMax ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . nfowuituae = rtP . BLDC_Id_init ; } if ( ssIsModeUpdateTimeStep ( rtS )
) { if ( rtDW . dokiorwuv5 != 0 ) { rtX . fj24d5zbvw = rtB . nfowuituae ; }
e2zgigtlb2 = rtX . fj24d5zbvw ; } else { e2zgigtlb2 = rtX . fj24d5zbvw ; }
rtB . kvdqpvhzmq = ( look1_binlcapw ( rtB . fdyvfxa4tp , rtP .
DatasheetBattery_CapLUTBp , rtP . DatasheetBattery_Em , 100U ) - 1.0 / rtP .
DatasheetBattery_Np * e2zgigtlb2 * look2_binlcapw ( rtP .
Constant3_Value_clw2lo3chi , rtB . fdyvfxa4tp , rtP .
DatasheetBattery_BattTempBp , rtP . DatasheetBattery_CapSOCBp , rtP .
DatasheetBattery_RInt , rtP . R_maxIndex , 7U ) ) * rtP . DatasheetBattery_Ns
; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . fyb11a0byc = rtP . BLDC_p ;
rtB . aijej34sel = rtP . BLDC_Th_init ; rtB . oi4vt50rct = rtP . BLDC_p ; rtB
. ojrenqmhg3 = rtP . Constant_Value ; } if ( ssIsModeUpdateTimeStep ( rtS ) )
{ if ( rtDW . jlyvcbibun != 0 ) { rtX . kaplaxkjn0 = rtB . aijej34sel ; }
o1pfazzsdy = rtX . kaplaxkjn0 ; } else { o1pfazzsdy = rtX . kaplaxkjn0 ; }
ku440utps3 = muDoubleScalarMod ( o1pfazzsdy * rtB . oi4vt50rct , rtB .
ojrenqmhg3 ) ; muDoubleScalarSinCos ( ku440utps3 , & eyzb0jsp5f , &
cunhphcmit ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . eefe1liyby [ 0 ]
= rtP . Minus120_Value [ 0 ] ; rtB . eefe1liyby [ 1 ] = rtP . Minus120_Value
[ 1 ] ; rtB . eefe1liyby [ 2 ] = rtP . Minus120_Value [ 2 ] ; rtB .
eefe1liyby [ 3 ] = rtP . Minus120_Value [ 3 ] ; rtB . fv0duehogi [ 0 ] = rtP
. Plus120_Value [ 0 ] ; rtB . fv0duehogi [ 1 ] = rtP . Plus120_Value [ 1 ] ;
rtB . fv0duehogi [ 2 ] = rtP . Plus120_Value [ 2 ] ; rtB . fv0duehogi [ 3 ] =
rtP . Plus120_Value [ 3 ] ; rtB . i3rjdtbo1x = rtP . Constant2_Value ; }
j0xjhwkbwm [ 0 ] = cunhphcmit ; j0xjhwkbwm [ 1 ] = rtB . eefe1liyby [ 1 ] *
eyzb0jsp5f + rtB . eefe1liyby [ 3 ] * cunhphcmit ; j0xjhwkbwm [ 2 ] = rtB .
fv0duehogi [ 1 ] * eyzb0jsp5f + rtB . fv0duehogi [ 3 ] * cunhphcmit ;
j0xjhwkbwm [ 3 ] = rtP . Gain2_Gain_jlslrcmtdv * eyzb0jsp5f ; j0xjhwkbwm [ 4
] = ( rtB . eefe1liyby [ 0 ] * eyzb0jsp5f + rtB . eefe1liyby [ 2 ] *
cunhphcmit ) * rtP . Gain2_Gain_jlslrcmtdv ; j0xjhwkbwm [ 5 ] = ( rtB .
fv0duehogi [ 0 ] * eyzb0jsp5f + rtB . fv0duehogi [ 2 ] * cunhphcmit ) * rtP .
Gain2_Gain_jlslrcmtdv ; j0xjhwkbwm [ 6 ] = rtB . i3rjdtbo1x ; j0xjhwkbwm [ 7
] = rtB . i3rjdtbo1x ; j0xjhwkbwm [ 8 ] = rtB . i3rjdtbo1x ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . cfptusc1o2 = rtP . BLDC_Iq_init ; rtB
. iek4fstubw = rtP . Constant_Value_ijz5z22oj1 ; } if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtDW . njopz31ksb != 0 ) { rtX .
fipmzwg11t = rtB . cfptusc1o2 ; } eyzb0jsp5f = rtX . fipmzwg11t ; } else {
eyzb0jsp5f = rtX . fipmzwg11t ; } for ( i = 0 ; i < 3 ; i ++ ) { n1i1cg25dg [
i ] = ( j0xjhwkbwm [ i + 3 ] * eyzb0jsp5f + j0xjhwkbwm [ i ] * e2zgigtlb2 ) +
j0xjhwkbwm [ i + 6 ] * rtB . iek4fstubw ; } if ( ssIsSampleHit ( rtS , 1 , 0
) ) { rtB . a0ayb25qmj = rtP . BLDC_Lambda ; rtB . djbr2nwlhy = rtP .
Constant7_Value ; } rtB . km0bbxs3pg = muDoubleScalarMod ( ku440utps3 + rtP .
Bias3_Bias , rtB . djbr2nwlhy ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . kwqc3w5qsd = ( rtB . km0bbxs3pg <=
rtP . Constant9_Value ) ; rtDW . l5ccmkoqga = ( rtB . km0bbxs3pg > rtP .
Constant9_Value ) ; rtDW . lggybcog5h = ( rtB . km0bbxs3pg <= rtP .
Constant10_Value ) ; } rtB . bvn1smh1wj = rtDW . kwqc3w5qsd ; rtB .
p4snq0ykvj = rtP . Constant8_Value ; if ( rtDW . l5ccmkoqga && rtDW .
lggybcog5h ) { rtB . gg1iibxtko = rtP . Constant1_Value ; } else { rtB .
gg1iibxtko = rtP . Constant3_Value ; } if ( ssIsModeUpdateTimeStep ( rtS ) )
{ rtDW . e4yp0ut4l1 = ( rtB . km0bbxs3pg > rtP . Constant10_Value ) ; rtDW .
ljyxtoiaxn = ( rtB . km0bbxs3pg <= rtP . Constant11_Value ) ; rtDW .
huibxjzrlf = ( rtB . km0bbxs3pg > rtP . Constant11_Value ) ; rtDW .
jqtcbyvb4q = ( rtB . km0bbxs3pg <= rtP . Constant12_Value ) ; } rtB .
ljru5rp5pg = ( rtDW . e4yp0ut4l1 && rtDW . ljyxtoiaxn ) ; rtB . fzpbd0kwko =
rtP . Constant2_Value_je4lnbr020 ; if ( rtDW . huibxjzrlf && rtDW .
jqtcbyvb4q ) { rtB . hj0n4eqkhc = rtP . Constant4_Value ; } else { rtB .
hj0n4eqkhc = rtP . Constant5_Value ; } if ( ssIsModeUpdateTimeStep ( rtS ) )
{ rtDW . pnompecjp4 = ( rtB . km0bbxs3pg > rtP . Constant12_Value ) ; } rtB .
dqvtfxq5pg = rtDW . pnompecjp4 ; rtB . o4pbpbusow = rtP . Constant6_Value ;
rtB . a2bgnx52ge = rtP . Constant7_Value_hf0hbvewrl ; } rtB . bhs0z1a4bq =
muDoubleScalarMod ( ku440utps3 + rtP . Bias3_Bias_pumqr42kho , rtB .
a2bgnx52ge ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . lgvgb0bfiz = ( rtB . bhs0z1a4bq <=
rtP . Constant9_Value_ovatguv1cd ) ; rtDW . gxqjpzrbio = ( rtB . bhs0z1a4bq >
rtP . Constant9_Value_ovatguv1cd ) ; rtDW . cblqvhc4lg = ( rtB . bhs0z1a4bq
<= rtP . Constant10_Value_j1wyywihpk ) ; } rtB . fylseu1fes = rtDW .
lgvgb0bfiz ; rtB . dj0lrq0jz3 = rtP . Constant8_Value_g0i1o1mso3 ; if ( rtDW
. gxqjpzrbio && rtDW . cblqvhc4lg ) { rtB . e2kxzmdksw = rtP .
Constant1_Value_kimdzexz1x ; } else { rtB . e2kxzmdksw = rtP .
Constant3_Value_ag4er51bcj ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW .
fwyecslys2 = ( rtB . bhs0z1a4bq > rtP . Constant10_Value_j1wyywihpk ) ; rtDW
. jzfmqldcwd = ( rtB . bhs0z1a4bq <= rtP . Constant11_Value_nlg4rxjaav ) ;
rtDW . fmiwrydvs2 = ( rtB . bhs0z1a4bq > rtP . Constant11_Value_nlg4rxjaav )
; rtDW . n0up5wu5m1 = ( rtB . bhs0z1a4bq <= rtP . Constant12_Value_asogurrks4
) ; } rtB . akfaoup2b2 = ( rtDW . fwyecslys2 && rtDW . jzfmqldcwd ) ; rtB .
agj32u24vd = rtP . Constant2_Value_k1svmewxmc ; if ( rtDW . fmiwrydvs2 &&
rtDW . n0up5wu5m1 ) { rtB . lv12rd3q40 = rtP . Constant4_Value_j0el1tqerf ; }
else { rtB . lv12rd3q40 = rtP . Constant5_Value_hivcl12fft ; } if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . ducvjjg20z = ( rtB . bhs0z1a4bq >
rtP . Constant12_Value_asogurrks4 ) ; } rtB . cmqpjmrsw2 = rtDW . ducvjjg20z
; rtB . dzznc5n5ya = rtP . Constant6_Value_atr0rui2nv ; rtB . authoigqah =
rtP . Constant7_Value_ckjsmfweco ; } rtB . a2tckjiuqf = muDoubleScalarMod (
ku440utps3 + rtP . Bias3_Bias_dlzcduozuu , rtB . authoigqah ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsModeUpdateTimeStep ( rtS ) ) {
rtDW . mntjd4rtyd = ( rtB . a2tckjiuqf <= rtP . Constant9_Value_b1dkmlfthl )
; rtDW . mxuiebor3g = ( rtB . a2tckjiuqf > rtP . Constant9_Value_b1dkmlfthl )
; rtDW . gsaioffcba = ( rtB . a2tckjiuqf <= rtP . Constant10_Value_gft3qlqgqh
) ; } rtB . duszlmyn0l = rtDW . mntjd4rtyd ; rtB . ix4azagznh = rtP .
Constant8_Value_pnqqtlv3vz ; if ( rtDW . mxuiebor3g && rtDW . gsaioffcba ) {
rtB . jc2b3utact = rtP . Constant1_Value_atqbaqyuhn ; } else { rtB .
jc2b3utact = rtP . Constant3_Value_bkypk4xhrd ; } if ( ssIsModeUpdateTimeStep
( rtS ) ) { rtDW . bivwyexrzk = ( rtB . a2tckjiuqf > rtP .
Constant10_Value_gft3qlqgqh ) ; rtDW . in45u4qlpg = ( rtB . a2tckjiuqf <= rtP
. Constant11_Value_ei54wtxug1 ) ; rtDW . oq2tlyjoxk = ( rtB . a2tckjiuqf >
rtP . Constant11_Value_ei54wtxug1 ) ; rtDW . osvc52zbdn = ( rtB . a2tckjiuqf
<= rtP . Constant12_Value_eihaiasqnb ) ; } rtB . pduf40h0yn = ( rtDW .
bivwyexrzk && rtDW . in45u4qlpg ) ; rtB . eyst12stjo = rtP .
Constant2_Value_pdtwrvtyzr ; if ( rtDW . oq2tlyjoxk && rtDW . osvc52zbdn ) {
rtB . oo4kaggwwm = rtP . Constant4_Value_bwrt5oukhm ; } else { rtB .
oo4kaggwwm = rtP . Constant5_Value_abvqtbsmbe ; } if ( ssIsModeUpdateTimeStep
( rtS ) ) { rtDW . glckwxkpxy = ( rtB . a2tckjiuqf > rtP .
Constant12_Value_eihaiasqnb ) ; } rtB . jfvfvv3giv = rtDW . glckwxkpxy ; rtB
. em4keqr4uy = rtP . Constant6_Value_d2i3udqljx ; } if ( rtB . bvn1smh1wj ) {
pmfzxtedhi = rtP . Gain_Gain * rtB . km0bbxs3pg + rtP . Bias1_Bias ; } else {
pmfzxtedhi = rtB . p4snq0ykvj ; } if ( rtB . ljru5rp5pg ) { frjn33kjtr_idx_2
= rtP . Gain1_Gain * rtB . km0bbxs3pg + rtP . Bias_Bias ; } else {
frjn33kjtr_idx_2 = rtB . fzpbd0kwko ; } if ( rtB . dqvtfxq5pg ) { cunhphcmit
= rtP . Gain2_Gain * rtB . km0bbxs3pg + rtP . Bias2_Bias ; } else {
cunhphcmit = rtB . o4pbpbusow ; } frjn33kjtr_idx_0 = ( ( ( ( pmfzxtedhi + rtB
. gg1iibxtko ) + frjn33kjtr_idx_2 ) + rtB . hj0n4eqkhc ) + cunhphcmit ) * rtP
. Max_Lampda_PM_rate_Gain * rtB . a0ayb25qmj ; if ( rtB . fylseu1fes ) {
pmfzxtedhi = rtP . Gain_Gain_f4q2bv4ant * rtB . bhs0z1a4bq + rtP .
Bias1_Bias_gcbxjqy1ag ; } else { pmfzxtedhi = rtB . dj0lrq0jz3 ; } if ( rtB .
akfaoup2b2 ) { frjn33kjtr_idx_2 = rtP . Gain1_Gain_kc23apyjss * rtB .
bhs0z1a4bq + rtP . Bias_Bias_pvrcayevr1 ; } else { frjn33kjtr_idx_2 = rtB .
agj32u24vd ; } if ( rtB . cmqpjmrsw2 ) { cunhphcmit = rtP .
Gain2_Gain_cskldqighc * rtB . bhs0z1a4bq + rtP . Bias2_Bias_ajzwnv2cpb ; }
else { cunhphcmit = rtB . dzznc5n5ya ; } frjn33kjtr_idx_1 = ( ( ( (
pmfzxtedhi + rtB . e2kxzmdksw ) + frjn33kjtr_idx_2 ) + rtB . lv12rd3q40 ) +
cunhphcmit ) * rtP . Max_Lampda_PM_rate_Gain * rtB . a0ayb25qmj ; if ( rtB .
duszlmyn0l ) { pmfzxtedhi = rtP . Gain_Gain_aj4jewynfg * rtB . a2tckjiuqf +
rtP . Bias1_Bias_bpnnrv2g4v ; } else { pmfzxtedhi = rtB . ix4azagznh ; } if (
rtB . pduf40h0yn ) { frjn33kjtr_idx_2 = rtP . Gain1_Gain_agqevzoajc * rtB .
a2tckjiuqf + rtP . Bias_Bias_kp4pcovegv ; } else { frjn33kjtr_idx_2 = rtB .
eyst12stjo ; } if ( rtB . jfvfvv3giv ) { cunhphcmit = rtP .
Gain2_Gain_dfafj4yf5d * rtB . a2tckjiuqf + rtP . Bias2_Bias_iyf2mr5qig ; }
else { cunhphcmit = rtB . em4keqr4uy ; } frjn33kjtr_idx_2 = ( ( ( (
pmfzxtedhi + rtB . jc2b3utact ) + frjn33kjtr_idx_2 ) + rtB . oo4kaggwwm ) +
cunhphcmit ) * rtP . Max_Lampda_PM_rate_Gain * rtB . a0ayb25qmj ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . kx0hemlyld = rtP . BLDC_Ld - rtP .
BLDC_Lq ; rtB . pt45h5hjge = rtP . BLDC_MechInput ; rtB . hmxy34r3a0 = rtP .
BLDC_MechInput ; rtB . jhspkh2pnv = rtP . BLDC_Omega_init ; } pmfzxtedhi = (
( ( n1i1cg25dg [ 0 ] * frjn33kjtr_idx_0 + n1i1cg25dg [ 1 ] * frjn33kjtr_idx_1
) + n1i1cg25dg [ 2 ] * frjn33kjtr_idx_2 ) * rtP . Gain1_Gain_kogsiikotf +
e2zgigtlb2 * eyzb0jsp5f * rtB . kx0hemlyld * rtP . Gain3_Gain ) * rtB .
fyb11a0byc ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtDW . le5se2ckp5
!= 0 ) { rtX . nk053321hc = rtB . jhspkh2pnv ; } cunhphcmit = rtX .
nk053321hc ; } else { cunhphcmit = rtX . nk053321hc ; } if ( rtB . hmxy34r3a0
> rtP . Trq_Or_Spd_Threshold ) { rtB . egogztggip = rtB . kvdqpvhzmq ; } else
{ rtB . egogztggip = cunhphcmit ; } if ( rtB . pt45h5hjge > rtP .
Trq_Or_Spd_Threshold_bv5qvwcnkb ) { rtB . gy0z0zpdto = pmfzxtedhi ; } else {
rtB . gy0z0zpdto = rtB . egogztggip ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ rtB . p3wvq04dag = rtP . BLDC_Rs ; rtB . iwc3kjrmco = rtP . BLDC_p ; rtB .
fi1fzzmmw5 = rtP . Constant2_Value_ozzuwkqilp ; } muDoubleScalarSinCos (
ku440utps3 , & cunhphcmit , & nrr2pzozjj ) ; j0xjhwkbwm [ 0 ] = nrr2pzozjj ;
j0xjhwkbwm [ 1 ] = rtP . Gain_Gain_an2ok5irfz * cunhphcmit ; j0xjhwkbwm [ 2 ]
= rtB . fi1fzzmmw5 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . oqrehzq1rd
[ 0 ] = rtP . Minus120_Value_micf4v4hxs [ 0 ] ; rtB . oqrehzq1rd [ 1 ] = rtP
. Minus120_Value_micf4v4hxs [ 1 ] ; rtB . oqrehzq1rd [ 2 ] = rtP .
Minus120_Value_micf4v4hxs [ 2 ] ; rtB . oqrehzq1rd [ 3 ] = rtP .
Minus120_Value_micf4v4hxs [ 3 ] ; rtB . lpydzdrxfc [ 0 ] = rtP .
Plus120_Value_hunie3hozg [ 0 ] ; rtB . lpydzdrxfc [ 1 ] = rtP .
Plus120_Value_hunie3hozg [ 1 ] ; rtB . lpydzdrxfc [ 2 ] = rtP .
Plus120_Value_hunie3hozg [ 2 ] ; rtB . lpydzdrxfc [ 3 ] = rtP .
Plus120_Value_hunie3hozg [ 3 ] ; } j0xjhwkbwm [ 3 ] = rtB . oqrehzq1rd [ 1 ]
* cunhphcmit + rtB . oqrehzq1rd [ 3 ] * nrr2pzozjj ; j0xjhwkbwm [ 4 ] = ( rtB
. oqrehzq1rd [ 0 ] * cunhphcmit + rtB . oqrehzq1rd [ 2 ] * nrr2pzozjj ) * rtP
. Gain2_Gain_lhlkdqm0ee ; j0xjhwkbwm [ 5 ] = rtB . fi1fzzmmw5 ; j0xjhwkbwm [
6 ] = rtB . lpydzdrxfc [ 1 ] * cunhphcmit + rtB . lpydzdrxfc [ 3 ] *
nrr2pzozjj ; j0xjhwkbwm [ 7 ] = ( rtB . lpydzdrxfc [ 0 ] * cunhphcmit + rtB .
lpydzdrxfc [ 2 ] * nrr2pzozjj ) * rtP . Gain3_Gain_oeu1akxnfz ; j0xjhwkbwm [
8 ] = rtB . fi1fzzmmw5 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
aqf34w05ez [ 0 ] = rtP . Constant_Value_dpuy0h0ihd [ 0 ] ; rtB . aqf34w05ez [
1 ] = rtP . Constant_Value_dpuy0h0ihd [ 1 ] ; rtB . aqf34w05ez [ 2 ] = rtP .
Constant_Value_dpuy0h0ihd [ 2 ] ; } ku440utps3 = rtP . toRad_Gain * rtP .
Constant2_Value_amvyq0ozrf ; cunhphcmit = rtB . egogztggip * rtB . iwc3kjrmco
; frjn33kjtr_idx_0 = ( muDoubleScalarSin ( ( rtX . c4ef21aibh + rtB .
aqf34w05ez [ 0 ] ) + ku440utps3 ) * rtB . kvdqpvhzmq - n1i1cg25dg [ 0 ] * rtB
. p3wvq04dag ) - frjn33kjtr_idx_0 * cunhphcmit ; frjn33kjtr_idx_1 = (
muDoubleScalarSin ( ( rtX . c4ef21aibh + rtB . aqf34w05ez [ 1 ] ) +
ku440utps3 ) * rtB . kvdqpvhzmq - n1i1cg25dg [ 1 ] * rtB . p3wvq04dag ) -
frjn33kjtr_idx_1 * cunhphcmit ; ku440utps3 = ( muDoubleScalarSin ( ( rtX .
c4ef21aibh + rtB . aqf34w05ez [ 2 ] ) + ku440utps3 ) * rtB . kvdqpvhzmq -
n1i1cg25dg [ 2 ] * rtB . p3wvq04dag ) - frjn33kjtr_idx_2 * cunhphcmit ; for (
i = 0 ; i < 3 ; i ++ ) { n1i1cg25dg [ i ] = ( j0xjhwkbwm [ i + 3 ] * rtP .
Gain1_Gain_ovhavq0wpo * frjn33kjtr_idx_1 + rtP . Gain1_Gain_ovhavq0wpo *
j0xjhwkbwm [ i ] * frjn33kjtr_idx_0 ) + j0xjhwkbwm [ i + 6 ] * rtP .
Gain1_Gain_ovhavq0wpo * ku440utps3 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
if ( rtB . egogztggip > 0.0 ) { rtDW . lve2pwc1qx = 1 ; } else if ( rtB .
egogztggip < 0.0 ) { rtDW . lve2pwc1qx = - 1 ; } else { rtDW . lve2pwc1qx = 0
; } rtB . khomf1duv0 = rtP . BLDC_F * ( real_T ) rtDW . lve2pwc1qx ; rtB .
efzov3ezec = rtP . BLDC_B ; rtB . fv5d2sh2lx = rtP . BLDC_J ; rtB .
bjvr10i1xh = rtP . BLDC_Lq ; rtB . pntpgyacqb = rtP . BLDC_Ld ; } rtB .
nveuw3rqtc = ( ( ( pmfzxtedhi - rtB . kvdqpvhzmq ) - rtB . khomf1duv0 ) - rtB
. efzov3ezec * rtB . egogztggip ) / rtB . fv5d2sh2lx ; rtB . b2k2rf0t1o = (
cunhphcmit * rtB . bjvr10i1xh * eyzb0jsp5f + n1i1cg25dg [ 0 ] ) / rtB .
pntpgyacqb ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . j1gs3wlbyf = rtP .
BLDC_Ld ; rtB . jwqy5kjnca = rtP . BLDC_Lq ; rtB . g52te4dnv1 = rtP . BLDC_Rs
; } rtB . lyvzolqnf4 = ( n1i1cg25dg [ 1 ] - cunhphcmit * rtB . j1gs3wlbyf *
e2zgigtlb2 ) / rtB . jwqy5kjnca ; muDoubleScalarSinCos ( o1pfazzsdy * rtB .
g52te4dnv1 , & ku440utps3 , & eyzb0jsp5f ) ; rtB . j5bvpiinqj = rtP .
raddeg_Gain * muDoubleScalarAtan2 ( ku440utps3 , eyzb0jsp5f ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) && ssIsModeUpdateTimeStep ( rtS ) ) { rtDW .
oo4t3xcua2 = ( rtB . j5bvpiinqj <= rtP . Constant1_Value_n213dknlmm ) ; rtDW
. eva4ztbj44 = ( rtB . j5bvpiinqj >= rtP . Constant_Value_jcoszycr0r ) ; rtDW
. lryrlbazgx = ( rtB . j5bvpiinqj <= rtP . Constant3_Value_jfxy4qopdq ) ;
rtDW . htsaf52tj2 = ( rtB . j5bvpiinqj >= rtP . Constant2_Value_ntrun4mqdf )
; rtDW . gt354wtaj0 = ( rtB . j5bvpiinqj <= rtP . Constant5_Value_m54jfbbmbh
) ; rtDW . a0nir1pp1r = ( rtB . j5bvpiinqj >= rtP .
Constant4_Value_jg1qmih3ue ) ; } rtB . hygy1qilge = - 1.0 / ( rtP .
DatasheetBattery_Np * 3600.0 ) * e2zgigtlb2 ; rtB . parcfkhsio = rtP .
Amplitude1_Gain * rtP . Constant4_Value_nmxg2ourug ; e2zgigtlb2 = rtP .
SignalGenerator_Frequency * ssGetT ( rtS ) ; if ( e2zgigtlb2 -
muDoubleScalarFloor ( e2zgigtlb2 ) >= 0.5 ) { pmfzxtedhi = rtP .
SignalGenerator_Amplitude ; } else { pmfzxtedhi = - rtP .
SignalGenerator_Amplitude ; } rtB . hkoqt4keho = pmfzxtedhi + rtP .
Constant1_Value_dsqxhplhg3 ; rtB . pairspzuzs = look2_binlcpw ( 0.0 , rtB .
hkoqt4keho , rtP . MappedCIEngine_f_tbrake_t_bpt , rtP .
MappedCIEngine_f_tbrake_n_bpt , rtP . MappedCIEngine_f_hc , rtP .
EoHcTable_maxIndex , 20U ) ; rtB . defj4le0qu = look2_binlcpw ( 0.0 , rtB .
hkoqt4keho , rtP . MappedCIEngine_f_tbrake_t_bpt , rtP .
MappedCIEngine_f_tbrake_n_bpt , rtP . MappedCIEngine_f_co , rtP .
EoCoTable_maxIndex , 20U ) ; rtB . jujtr2tg5z = look2_binlcpw ( 0.0 , rtB .
hkoqt4keho , rtP . MappedCIEngine_f_tbrake_t_bpt , rtP .
MappedCIEngine_f_tbrake_n_bpt , rtP . MappedCIEngine_f_nox , rtP .
EoNOxTable_maxIndex , 20U ) ; rtB . l1nh51d3ja = look2_binlcpw ( 0.0 , rtB .
hkoqt4keho , rtP . MappedCIEngine_f_tbrake_t_bpt , rtP .
MappedCIEngine_f_tbrake_n_bpt , rtP . MappedCIEngine_f_co2 , rtP .
EoCO2Table_maxIndex , 20U ) ; rtB . jmwba0ymud = look2_binlcpw ( 0.0 , rtB .
hkoqt4keho , rtP . MappedCIEngine_f_tbrake_t_bpt , rtP .
MappedCIEngine_f_tbrake_n_bpt , rtP . MappedCIEngine_f_tbrake , rtP .
EngTrqTable_maxIndex , 20U ) ; rtB . hapipevwha = look2_binlcpw ( 0.0 , rtB .
hkoqt4keho , rtP . MappedCIEngine_f_tbrake_t_bpt , rtP .
MappedCIEngine_f_tbrake_n_bpt , rtP . MappedCIEngine_f_fuel , rtP .
FuelMassFlwTable_maxIndex , 20U ) ; rtB . pdiw5iqass = look2_binlcpw ( 0.0 ,
rtB . hkoqt4keho , rtP . MappedCIEngine_f_tbrake_t_bpt , rtP .
MappedCIEngine_f_tbrake_n_bpt , rtP . MappedCIEngine_f_air , rtP .
AirFlowTable_maxIndex , 20U ) ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW
. pkr1zun1m3 = ( rtB . hapipevwha >= rtP . Switch1_Threshold ) ; rtDW .
phu2ogaeea = ( rtB . pdiw5iqass >= rtP . Switch1_Threshold_hyh3yfwgbh ) ; }
rtB . hkg2tchhax = rtP . RPMtodegs_Gain * rtB . hkoqt4keho ; UNUSED_PARAMETER
( tid ) ; } void MdlOutputsTID2 ( int_T tid ) { if ( rtP .
DatasheetBattery_BattCapInit > rtP . DatasheetBattery_BattChargeMax ) { rtB .
pxpvevgrie = rtP . DatasheetBattery_BattChargeMax ; } else { rtB . pxpvevgrie
= rtP . DatasheetBattery_BattCapInit ; } rtB . ktnbcplp2i = - rtP .
Constant_Value_cu2gsqbnxd ; rtB . gjnfdmbcjm = - rtP .
Constant_Value_oboowpiodw ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { rtDW . i3v3y1llki = 0 ; rtDW . dokiorwuv5 = 0 ; rtDW .
jlyvcbibun = 0 ; rtDW . njopz31ksb = 0 ; rtDW . le5se2ckp5 = 0 ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; if ( ( ( rtX . hn3bvj4yke > rtP .
IntegratorLimited_LowerSat ) && ( rtX . hn3bvj4yke < rtP .
DatasheetBattery_BattChargeMax ) ) || ( ( rtX . hn3bvj4yke <= rtP .
IntegratorLimited_LowerSat ) && ( rtB . hygy1qilge > 0.0 ) ) || ( ( rtX .
hn3bvj4yke >= rtP . DatasheetBattery_BattChargeMax ) && ( rtB . hygy1qilge <
0.0 ) ) ) { _rtXdot -> hn3bvj4yke = rtB . hygy1qilge ; } else { _rtXdot ->
hn3bvj4yke = 0.0 ; } _rtXdot -> fj24d5zbvw = rtB . b2k2rf0t1o ; _rtXdot ->
kaplaxkjn0 = rtB . egogztggip ; _rtXdot -> fipmzwg11t = rtB . lyvzolqnf4 ;
_rtXdot -> nk053321hc = rtB . nveuw3rqtc ; _rtXdot -> c4ef21aibh = rtB .
parcfkhsio ; _rtXdot -> mwc2guobfc = rtB . hkg2tchhax ; } void MdlProjection
( void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> mdtvnzv3wk = rtB .
km0bbxs3pg - rtP . Constant9_Value ; _rtZCSV -> dz32tolass = rtB . km0bbxs3pg
- rtP . Constant9_Value ; _rtZCSV -> eia3q4cf0h = rtB . km0bbxs3pg - rtP .
Constant10_Value ; _rtZCSV -> k5bbac1ls5 = rtB . km0bbxs3pg - rtP .
Constant10_Value ; _rtZCSV -> itvrboi0bx = rtB . km0bbxs3pg - rtP .
Constant11_Value ; _rtZCSV -> irhnpuyeyz = rtB . km0bbxs3pg - rtP .
Constant11_Value ; _rtZCSV -> bnq4sydqjk = rtB . km0bbxs3pg - rtP .
Constant12_Value ; _rtZCSV -> cpfq3yjr4k = rtB . km0bbxs3pg - rtP .
Constant12_Value ; _rtZCSV -> pciywyec4z = rtB . bhs0z1a4bq - rtP .
Constant9_Value_ovatguv1cd ; _rtZCSV -> doglmjvqsg = rtB . bhs0z1a4bq - rtP .
Constant9_Value_ovatguv1cd ; _rtZCSV -> hwkx2ettqo = rtB . bhs0z1a4bq - rtP .
Constant10_Value_j1wyywihpk ; _rtZCSV -> kcyhhduklj = rtB . bhs0z1a4bq - rtP
. Constant10_Value_j1wyywihpk ; _rtZCSV -> c3vfp4uwh5 = rtB . bhs0z1a4bq -
rtP . Constant11_Value_nlg4rxjaav ; _rtZCSV -> lrlal1cogn = rtB . bhs0z1a4bq
- rtP . Constant11_Value_nlg4rxjaav ; _rtZCSV -> hdiigri1u4 = rtB .
bhs0z1a4bq - rtP . Constant12_Value_asogurrks4 ; _rtZCSV -> b5d4dckzje = rtB
. bhs0z1a4bq - rtP . Constant12_Value_asogurrks4 ; _rtZCSV -> lebwgudhqf =
rtB . a2tckjiuqf - rtP . Constant9_Value_b1dkmlfthl ; _rtZCSV -> bq3owdnncc =
rtB . a2tckjiuqf - rtP . Constant9_Value_b1dkmlfthl ; _rtZCSV -> cmewj3vxtb =
rtB . a2tckjiuqf - rtP . Constant10_Value_gft3qlqgqh ; _rtZCSV -> p4t0x5io30
= rtB . a2tckjiuqf - rtP . Constant10_Value_gft3qlqgqh ; _rtZCSV ->
jbq5saxtsl = rtB . a2tckjiuqf - rtP . Constant11_Value_ei54wtxug1 ; _rtZCSV
-> awb0dceprw = rtB . a2tckjiuqf - rtP . Constant11_Value_ei54wtxug1 ;
_rtZCSV -> bzddub2lpx = rtB . a2tckjiuqf - rtP . Constant12_Value_eihaiasqnb
; _rtZCSV -> esihukjsr5 = rtB . a2tckjiuqf - rtP .
Constant12_Value_eihaiasqnb ; _rtZCSV -> ppdk3h1t3c = rtB . egogztggip ;
_rtZCSV -> kand4coevr = rtB . j5bvpiinqj - rtP . Constant1_Value_n213dknlmm ;
_rtZCSV -> kxftccu0v5 = rtB . j5bvpiinqj - rtP . Constant_Value_jcoszycr0r ;
_rtZCSV -> grcccujmsw = rtB . j5bvpiinqj - rtP . Constant3_Value_jfxy4qopdq ;
_rtZCSV -> mxuqiix2te = rtB . j5bvpiinqj - rtP . Constant2_Value_ntrun4mqdf ;
_rtZCSV -> pn40gqzw21 = rtB . j5bvpiinqj - rtP . Constant5_Value_m54jfbbmbh ;
_rtZCSV -> ic2ylcej3a = rtB . j5bvpiinqj - rtP . Constant4_Value_jg1qmih3ue ;
_rtZCSV -> dnfaasops5 = rtB . hapipevwha - rtP . Switch1_Threshold ; _rtZCSV
-> grm4oknroc = rtB . pdiw5iqass - rtP . Switch1_Threshold_hyh3yfwgbh ; }
void MdlTerminate ( void ) { } static void
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
rtdwDataFieldNames [ 38 ] = { "rtDW.i3v3y1llki" , "rtDW.dokiorwuv5" ,
"rtDW.jlyvcbibun" , "rtDW.njopz31ksb" , "rtDW.le5se2ckp5" , "rtDW.lve2pwc1qx"
, "rtDW.kwqc3w5qsd" , "rtDW.l5ccmkoqga" , "rtDW.lggybcog5h" ,
"rtDW.e4yp0ut4l1" , "rtDW.ljyxtoiaxn" , "rtDW.huibxjzrlf" , "rtDW.jqtcbyvb4q"
, "rtDW.pnompecjp4" , "rtDW.lgvgb0bfiz" , "rtDW.gxqjpzrbio" ,
"rtDW.cblqvhc4lg" , "rtDW.fwyecslys2" , "rtDW.jzfmqldcwd" , "rtDW.fmiwrydvs2"
, "rtDW.n0up5wu5m1" , "rtDW.ducvjjg20z" , "rtDW.mntjd4rtyd" ,
"rtDW.mxuiebor3g" , "rtDW.gsaioffcba" , "rtDW.bivwyexrzk" , "rtDW.in45u4qlpg"
, "rtDW.oq2tlyjoxk" , "rtDW.osvc52zbdn" , "rtDW.glckwxkpxy" ,
"rtDW.oo4t3xcua2" , "rtDW.eva4ztbj44" , "rtDW.lryrlbazgx" , "rtDW.htsaf52tj2"
, "rtDW.gt354wtaj0" , "rtDW.a0nir1pp1r" , "rtDW.pkr1zun1m3" ,
"rtDW.phu2ogaeea" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 ,
38 , rtdwDataFieldNames ) ; mr_ParallelTestBench_cacheDataAsMxArray (
rtdwData , 0 , 0 , ( const void * ) & ( rtDW . i3v3y1llki ) , sizeof ( rtDW .
i3v3y1llki ) ) ; mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 1 ,
( const void * ) & ( rtDW . dokiorwuv5 ) , sizeof ( rtDW . dokiorwuv5 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * )
& ( rtDW . jlyvcbibun ) , sizeof ( rtDW . jlyvcbibun ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * )
& ( rtDW . njopz31ksb ) , sizeof ( rtDW . njopz31ksb ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * )
& ( rtDW . le5se2ckp5 ) , sizeof ( rtDW . le5se2ckp5 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * )
& ( rtDW . lve2pwc1qx ) , sizeof ( rtDW . lve2pwc1qx ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * )
& ( rtDW . kwqc3w5qsd ) , sizeof ( rtDW . kwqc3w5qsd ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * )
& ( rtDW . l5ccmkoqga ) , sizeof ( rtDW . l5ccmkoqga ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * )
& ( rtDW . lggybcog5h ) , sizeof ( rtDW . lggybcog5h ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * )
& ( rtDW . e4yp0ut4l1 ) , sizeof ( rtDW . e4yp0ut4l1 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void *
) & ( rtDW . ljyxtoiaxn ) , sizeof ( rtDW . ljyxtoiaxn ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void *
) & ( rtDW . huibxjzrlf ) , sizeof ( rtDW . huibxjzrlf ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void *
) & ( rtDW . jqtcbyvb4q ) , sizeof ( rtDW . jqtcbyvb4q ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void *
) & ( rtDW . pnompecjp4 ) , sizeof ( rtDW . pnompecjp4 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void *
) & ( rtDW . lgvgb0bfiz ) , sizeof ( rtDW . lgvgb0bfiz ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void *
) & ( rtDW . gxqjpzrbio ) , sizeof ( rtDW . gxqjpzrbio ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void *
) & ( rtDW . cblqvhc4lg ) , sizeof ( rtDW . cblqvhc4lg ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void *
) & ( rtDW . fwyecslys2 ) , sizeof ( rtDW . fwyecslys2 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void *
) & ( rtDW . jzfmqldcwd ) , sizeof ( rtDW . jzfmqldcwd ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void *
) & ( rtDW . fmiwrydvs2 ) , sizeof ( rtDW . fmiwrydvs2 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void *
) & ( rtDW . n0up5wu5m1 ) , sizeof ( rtDW . n0up5wu5m1 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void *
) & ( rtDW . ducvjjg20z ) , sizeof ( rtDW . ducvjjg20z ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void *
) & ( rtDW . mntjd4rtyd ) , sizeof ( rtDW . mntjd4rtyd ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void *
) & ( rtDW . mxuiebor3g ) , sizeof ( rtDW . mxuiebor3g ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void *
) & ( rtDW . gsaioffcba ) , sizeof ( rtDW . gsaioffcba ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void *
) & ( rtDW . bivwyexrzk ) , sizeof ( rtDW . bivwyexrzk ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void *
) & ( rtDW . in45u4qlpg ) , sizeof ( rtDW . in45u4qlpg ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void *
) & ( rtDW . oq2tlyjoxk ) , sizeof ( rtDW . oq2tlyjoxk ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void *
) & ( rtDW . osvc52zbdn ) , sizeof ( rtDW . osvc52zbdn ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void *
) & ( rtDW . glckwxkpxy ) , sizeof ( rtDW . glckwxkpxy ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void *
) & ( rtDW . oo4t3xcua2 ) , sizeof ( rtDW . oo4t3xcua2 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void *
) & ( rtDW . eva4ztbj44 ) , sizeof ( rtDW . eva4ztbj44 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void *
) & ( rtDW . lryrlbazgx ) , sizeof ( rtDW . lryrlbazgx ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void *
) & ( rtDW . htsaf52tj2 ) , sizeof ( rtDW . htsaf52tj2 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void *
) & ( rtDW . gt354wtaj0 ) , sizeof ( rtDW . gt354wtaj0 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void *
) & ( rtDW . a0nir1pp1r ) , sizeof ( rtDW . a0nir1pp1r ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void *
) & ( rtDW . pkr1zun1m3 ) , sizeof ( rtDW . pkr1zun1m3 ) ) ;
mr_ParallelTestBench_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void *
) & ( rtDW . phu2ogaeea ) , sizeof ( rtDW . phu2ogaeea ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_ParallelTestBench_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0
, 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber (
ssDW , 0 , 1 ) ; mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & (
rtDW . i3v3y1llki ) , rtdwData , 0 , 0 , sizeof ( rtDW . i3v3y1llki ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dokiorwuv5 ) , rtdwData , 0 , 1 , sizeof ( rtDW . dokiorwuv5 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jlyvcbibun ) , rtdwData , 0 , 2 , sizeof ( rtDW . jlyvcbibun ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
njopz31ksb ) , rtdwData , 0 , 3 , sizeof ( rtDW . njopz31ksb ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
le5se2ckp5 ) , rtdwData , 0 , 4 , sizeof ( rtDW . le5se2ckp5 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lve2pwc1qx ) , rtdwData , 0 , 5 , sizeof ( rtDW . lve2pwc1qx ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
kwqc3w5qsd ) , rtdwData , 0 , 6 , sizeof ( rtDW . kwqc3w5qsd ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
l5ccmkoqga ) , rtdwData , 0 , 7 , sizeof ( rtDW . l5ccmkoqga ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lggybcog5h ) , rtdwData , 0 , 8 , sizeof ( rtDW . lggybcog5h ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
e4yp0ut4l1 ) , rtdwData , 0 , 9 , sizeof ( rtDW . e4yp0ut4l1 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ljyxtoiaxn ) , rtdwData , 0 , 10 , sizeof ( rtDW . ljyxtoiaxn ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
huibxjzrlf ) , rtdwData , 0 , 11 , sizeof ( rtDW . huibxjzrlf ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jqtcbyvb4q ) , rtdwData , 0 , 12 , sizeof ( rtDW . jqtcbyvb4q ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pnompecjp4 ) , rtdwData , 0 , 13 , sizeof ( rtDW . pnompecjp4 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lgvgb0bfiz ) , rtdwData , 0 , 14 , sizeof ( rtDW . lgvgb0bfiz ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gxqjpzrbio ) , rtdwData , 0 , 15 , sizeof ( rtDW . gxqjpzrbio ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cblqvhc4lg ) , rtdwData , 0 , 16 , sizeof ( rtDW . cblqvhc4lg ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
fwyecslys2 ) , rtdwData , 0 , 17 , sizeof ( rtDW . fwyecslys2 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jzfmqldcwd ) , rtdwData , 0 , 18 , sizeof ( rtDW . jzfmqldcwd ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
fmiwrydvs2 ) , rtdwData , 0 , 19 , sizeof ( rtDW . fmiwrydvs2 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
n0up5wu5m1 ) , rtdwData , 0 , 20 , sizeof ( rtDW . n0up5wu5m1 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ducvjjg20z ) , rtdwData , 0 , 21 , sizeof ( rtDW . ducvjjg20z ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mntjd4rtyd ) , rtdwData , 0 , 22 , sizeof ( rtDW . mntjd4rtyd ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mxuiebor3g ) , rtdwData , 0 , 23 , sizeof ( rtDW . mxuiebor3g ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gsaioffcba ) , rtdwData , 0 , 24 , sizeof ( rtDW . gsaioffcba ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bivwyexrzk ) , rtdwData , 0 , 25 , sizeof ( rtDW . bivwyexrzk ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
in45u4qlpg ) , rtdwData , 0 , 26 , sizeof ( rtDW . in45u4qlpg ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
oq2tlyjoxk ) , rtdwData , 0 , 27 , sizeof ( rtDW . oq2tlyjoxk ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
osvc52zbdn ) , rtdwData , 0 , 28 , sizeof ( rtDW . osvc52zbdn ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
glckwxkpxy ) , rtdwData , 0 , 29 , sizeof ( rtDW . glckwxkpxy ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
oo4t3xcua2 ) , rtdwData , 0 , 30 , sizeof ( rtDW . oo4t3xcua2 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
eva4ztbj44 ) , rtdwData , 0 , 31 , sizeof ( rtDW . eva4ztbj44 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lryrlbazgx ) , rtdwData , 0 , 32 , sizeof ( rtDW . lryrlbazgx ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
htsaf52tj2 ) , rtdwData , 0 , 33 , sizeof ( rtDW . htsaf52tj2 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gt354wtaj0 ) , rtdwData , 0 , 34 , sizeof ( rtDW . gt354wtaj0 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
a0nir1pp1r ) , rtdwData , 0 , 35 , sizeof ( rtDW . a0nir1pp1r ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pkr1zun1m3 ) , rtdwData , 0 , 36 , sizeof ( rtDW . pkr1zun1m3 ) ) ;
mr_ParallelTestBench_restoreDataFromMxArray ( ( void * ) & ( rtDW .
phu2ogaeea ) , rtdwData , 0 , 37 , sizeof ( rtDW . phu2ogaeea ) ) ; } }
mxArray * mr_ParallelTestBench_GetSimStateDisallowedBlocks ( ) { mxArray *
data = mxCreateCellMatrix ( 6 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static
const char_T * blockType [ 6 ] = { "Scope" , "Scope" , "Scope" , "Scope" ,
"Scope" , "Scope" , } ; static const char_T * blockPath [ 6 ] = {
"ParallelTestBench/Scope1" , "ParallelTestBench/Scope2" ,
"ParallelTestBench/Scope3" , "ParallelTestBench/Emissions" ,
"ParallelTestBench/Engine Speed//Torque" , "ParallelTestBench/Scope" , } ;
static const int reason [ 6 ] = { 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0
] = 0 ; subs [ 0 ] < 6 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 7 ) ;
ssSetNumPeriodicContStates ( rtS , 1 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 282 ) ; ssSetNumBlockIO ( rtS , 81 ) ;
ssSetNumBlockParams ( rtS , 2681 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1731618281U ) ;
ssSetChecksumVal ( rtS , 1 , 510667600U ) ; ssSetChecksumVal ( rtS , 2 ,
3146656349U ) ; ssSetChecksumVal ( rtS , 3 , 3818291459U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 0 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
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
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
ParallelTestBench_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "ParallelTestBench" ) ;
ssSetPath ( rtS , "ParallelTestBench" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 60.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 ,
1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1
, 1 , 1 , 1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 ,
0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ]
= { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
 "ParallelTestBench/Datasheet Battery/Datasheet Battery Internal/Datasheet Battery/Charge Model/Integrator\nLimited"
,
 "ParallelTestBench/BLDC/Motor Equation/D-axis/Integration/Continuous Integration/Integrator"
,
 "ParallelTestBench/BLDC/Mechanical Equation/Integration2/Continuous Integration/Integrator"
,
 "ParallelTestBench/BLDC/Motor Equation/Q-axis/Integration/Continuous Integration/Integrator"
,
 "ParallelTestBench/BLDC/Mechanical Equation/Integration1/Continuous Integration/Integrator"
, "ParallelTestBench/Three-Phase\nSine Generator/Model/Integrator" ,
"ParallelTestBench/Mapped CI Engine/Engine Crank Angle Calculation/Integrator"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] =
{ { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 7 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 7 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . hn3bvj4yke ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . fj24d5zbvw ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . kaplaxkjn0 ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . fipmzwg11t ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . nk053321hc ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . c4ef21aibh ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . mwc2guobfc ; }
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
void * ) rtPeriodicIndX , 0 , 1 * sizeof ( int_T ) ) ;
ssSetPeriodicContStateRanges ( rtS , rtPeriodicRngX ) ; ( void ) memset ( (
void * ) rtPeriodicRngX , 0 , 2 * sizeof ( real_T ) ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 7 ] ;
static real_T absTol [ 7 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 7 ] = { 0U , 0U , 0U , 0U
, 0U , 0U , 0U } ; static real_T contStateJacPerturbBoundMinVec [ 7 ] ;
static real_T contStateJacPerturbBoundMaxVec [ 7 ] ; static uint8_T
zcAttributes [ 33 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL
) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 17 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
khomf1duv0 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
kx0hemlyld ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
jfvfvv3giv ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
oo4kaggwwm ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
pduf40h0yn ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
jc2b3utact ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
duszlmyn0l ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
cmqpjmrsw2 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
lv12rd3q40 ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
akfaoup2b2 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
e2kxzmdksw ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
fylseu1fes ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
dqvtfxq5pg ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
hj0n4eqkhc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
ljru5rp5pg ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
gg1iibxtko ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
bvn1smh1wj ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 7 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS ,
0.6741573033707865 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
17 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode45" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 33 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 33 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1731618281U ) ; ssSetChecksumVal ( rtS , 1 ,
510667600U ) ; ssSetChecksumVal ( rtS , 2 , 3146656349U ) ; ssSetChecksumVal
( rtS , 3 , 3818291459U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 22 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ;
systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ;
systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ;
systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ;
systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ;
systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ;
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
