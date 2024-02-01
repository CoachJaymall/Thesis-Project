#ifndef RTW_HEADER_ParallelTestBench_h_
#define RTW_HEADER_ParallelTestBench_h_
#ifndef ParallelTestBench_COMMON_INCLUDES_
#define ParallelTestBench_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "ParallelTestBench_types.h"
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME ParallelTestBench
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (81) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (7)   
#elif NCSTATES != 7
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T fdyvfxa4tp ; real_T nfowuituae ; real_T kvdqpvhzmq ;
real_T fyb11a0byc ; real_T aijej34sel ; real_T oi4vt50rct ; real_T ojrenqmhg3
; real_T eefe1liyby [ 4 ] ; real_T fv0duehogi [ 4 ] ; real_T i3rjdtbo1x ;
real_T cfptusc1o2 ; real_T iek4fstubw ; real_T a0ayb25qmj ; real_T djbr2nwlhy
; real_T km0bbxs3pg ; real_T p4snq0ykvj ; real_T gg1iibxtko ; real_T
fzpbd0kwko ; real_T hj0n4eqkhc ; real_T o4pbpbusow ; real_T a2bgnx52ge ;
real_T bhs0z1a4bq ; real_T dj0lrq0jz3 ; real_T e2kxzmdksw ; real_T agj32u24vd
; real_T lv12rd3q40 ; real_T dzznc5n5ya ; real_T authoigqah ; real_T
a2tckjiuqf ; real_T ix4azagznh ; real_T jc2b3utact ; real_T eyst12stjo ;
real_T oo4kaggwwm ; real_T em4keqr4uy ; real_T kx0hemlyld ; real_T pt45h5hjge
; real_T hmxy34r3a0 ; real_T jhspkh2pnv ; real_T egogztggip ; real_T
gy0z0zpdto ; real_T p3wvq04dag ; real_T iwc3kjrmco ; real_T fi1fzzmmw5 ;
real_T oqrehzq1rd [ 4 ] ; real_T lpydzdrxfc [ 4 ] ; real_T aqf34w05ez [ 3 ] ;
real_T khomf1duv0 ; real_T efzov3ezec ; real_T fv5d2sh2lx ; real_T nveuw3rqtc
; real_T bjvr10i1xh ; real_T pntpgyacqb ; real_T b2k2rf0t1o ; real_T
j1gs3wlbyf ; real_T jwqy5kjnca ; real_T lyvzolqnf4 ; real_T g52te4dnv1 ;
real_T j5bvpiinqj ; real_T hygy1qilge ; real_T parcfkhsio ; real_T hkoqt4keho
; real_T pairspzuzs ; real_T defj4le0qu ; real_T jujtr2tg5z ; real_T
l1nh51d3ja ; real_T jmwba0ymud ; real_T hapipevwha ; real_T pdiw5iqass ;
real_T hkg2tchhax ; real_T pxpvevgrie ; real_T ktnbcplp2i ; real_T gjnfdmbcjm
; boolean_T bvn1smh1wj ; boolean_T ljru5rp5pg ; boolean_T dqvtfxq5pg ;
boolean_T fylseu1fes ; boolean_T akfaoup2b2 ; boolean_T cmqpjmrsw2 ;
boolean_T duszlmyn0l ; boolean_T pduf40h0yn ; boolean_T jfvfvv3giv ; } B ;
typedef struct { struct { void * LoggedData ; } avkff5cs3v ; struct { void *
LoggedData ; } mzdo32klye ; struct { void * LoggedData ; } gjyqt1hwd3 ;
struct { void * LoggedData ; } cqvoje5ho5 ; struct { void * LoggedData ; }
a44i1qtvtw ; struct { void * LoggedData [ 2 ] ; } ih5pmp5chi ; int_T
i3v3y1llki ; int_T dokiorwuv5 ; int_T jlyvcbibun ; int_T njopz31ksb ; int_T
le5se2ckp5 ; int_T lve2pwc1qx ; boolean_T kwqc3w5qsd ; boolean_T l5ccmkoqga ;
boolean_T lggybcog5h ; boolean_T e4yp0ut4l1 ; boolean_T ljyxtoiaxn ;
boolean_T huibxjzrlf ; boolean_T jqtcbyvb4q ; boolean_T pnompecjp4 ;
boolean_T lgvgb0bfiz ; boolean_T gxqjpzrbio ; boolean_T cblqvhc4lg ;
boolean_T fwyecslys2 ; boolean_T jzfmqldcwd ; boolean_T fmiwrydvs2 ;
boolean_T n0up5wu5m1 ; boolean_T ducvjjg20z ; boolean_T mntjd4rtyd ;
boolean_T mxuiebor3g ; boolean_T gsaioffcba ; boolean_T bivwyexrzk ;
boolean_T in45u4qlpg ; boolean_T oq2tlyjoxk ; boolean_T osvc52zbdn ;
boolean_T glckwxkpxy ; boolean_T oo4t3xcua2 ; boolean_T eva4ztbj44 ;
boolean_T lryrlbazgx ; boolean_T htsaf52tj2 ; boolean_T gt354wtaj0 ;
boolean_T a0nir1pp1r ; boolean_T pkr1zun1m3 ; boolean_T phu2ogaeea ; } DW ;
typedef struct { real_T hn3bvj4yke ; real_T fj24d5zbvw ; real_T kaplaxkjn0 ;
real_T fipmzwg11t ; real_T nk053321hc ; real_T c4ef21aibh ; real_T mwc2guobfc
; } X ; typedef int_T PeriodicIndX [ 1 ] ; typedef real_T PeriodicRngX [ 2 ]
; typedef struct { real_T hn3bvj4yke ; real_T fj24d5zbvw ; real_T kaplaxkjn0
; real_T fipmzwg11t ; real_T nk053321hc ; real_T c4ef21aibh ; real_T
mwc2guobfc ; } XDot ; typedef struct { boolean_T hn3bvj4yke ; boolean_T
fj24d5zbvw ; boolean_T kaplaxkjn0 ; boolean_T fipmzwg11t ; boolean_T
nk053321hc ; boolean_T c4ef21aibh ; boolean_T mwc2guobfc ; } XDis ; typedef
struct { real_T hn3bvj4yke ; real_T fj24d5zbvw ; real_T kaplaxkjn0 ; real_T
fipmzwg11t ; real_T nk053321hc ; real_T c4ef21aibh ; real_T mwc2guobfc ; }
CStateAbsTol ; typedef struct { real_T hn3bvj4yke ; real_T fj24d5zbvw ;
real_T kaplaxkjn0 ; real_T fipmzwg11t ; real_T nk053321hc ; real_T c4ef21aibh
; real_T mwc2guobfc ; } CXPtMin ; typedef struct { real_T hn3bvj4yke ; real_T
fj24d5zbvw ; real_T kaplaxkjn0 ; real_T fipmzwg11t ; real_T nk053321hc ;
real_T c4ef21aibh ; real_T mwc2guobfc ; } CXPtMax ; typedef struct { real_T
mdtvnzv3wk ; real_T dz32tolass ; real_T eia3q4cf0h ; real_T k5bbac1ls5 ;
real_T itvrboi0bx ; real_T irhnpuyeyz ; real_T bnq4sydqjk ; real_T cpfq3yjr4k
; real_T pciywyec4z ; real_T doglmjvqsg ; real_T hwkx2ettqo ; real_T
kcyhhduklj ; real_T c3vfp4uwh5 ; real_T lrlal1cogn ; real_T hdiigri1u4 ;
real_T b5d4dckzje ; real_T lebwgudhqf ; real_T bq3owdnncc ; real_T cmewj3vxtb
; real_T p4t0x5io30 ; real_T jbq5saxtsl ; real_T awb0dceprw ; real_T
bzddub2lpx ; real_T esihukjsr5 ; real_T ppdk3h1t3c ; real_T kand4coevr ;
real_T kxftccu0v5 ; real_T grcccujmsw ; real_T mxuqiix2te ; real_T pn40gqzw21
; real_T ic2ylcej3a ; real_T dnfaasops5 ; real_T grm4oknroc ; } ZCV ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
BLDC_B ; real_T DatasheetBattery_BattCapInit ; real_T
DatasheetBattery_BattChargeMax ; real_T DatasheetBattery_BattTempBp [ 7 ] ;
real_T DatasheetBattery_CapLUTBp [ 101 ] ; real_T DatasheetBattery_CapSOCBp [
6 ] ; real_T DatasheetBattery_Em [ 101 ] ; real_T BLDC_F ; real_T
BLDC_Id_init ; real_T BLDC_Iq_init ; real_T BLDC_J ; real_T BLDC_Lambda ;
real_T BLDC_Ld ; real_T BLDC_Lq ; real_T BLDC_MechInput ; real_T
DatasheetBattery_Np ; real_T DatasheetBattery_Ns ; real_T BLDC_Omega_init ;
real_T DatasheetBattery_RInt [ 42 ] ; real_T BLDC_Rs ; real_T BLDC_Th_init ;
real_T MappedCIEngine_f_air [ 320 ] ; real_T MappedCIEngine_f_co [ 320 ] ;
real_T MappedCIEngine_f_co2 [ 320 ] ; real_T MappedCIEngine_f_fuel [ 320 ] ;
real_T MappedCIEngine_f_hc [ 320 ] ; real_T MappedCIEngine_f_nox [ 320 ] ;
real_T MappedCIEngine_f_tbrake [ 320 ] ; real_T MappedCIEngine_f_tbrake_n_bpt
[ 16 ] ; real_T MappedCIEngine_f_tbrake_t_bpt [ 20 ] ; real_T BLDC_p ; real_T
Constant1_Value ; real_T Constant3_Value ; real_T Gain1_Gain ; real_T
Bias_Bias ; real_T Constant4_Value ; real_T Constant5_Value ; real_T
Gain2_Gain ; real_T Bias2_Bias ; real_T Gain_Gain ; real_T Bias1_Bias ;
real_T Constant1_Value_kimdzexz1x ; real_T Constant3_Value_ag4er51bcj ;
real_T Gain1_Gain_kc23apyjss ; real_T Bias_Bias_pvrcayevr1 ; real_T
Constant4_Value_j0el1tqerf ; real_T Constant5_Value_hivcl12fft ; real_T
Gain2_Gain_cskldqighc ; real_T Bias2_Bias_ajzwnv2cpb ; real_T
Gain_Gain_f4q2bv4ant ; real_T Bias1_Bias_gcbxjqy1ag ; real_T
Constant1_Value_atqbaqyuhn ; real_T Constant3_Value_bkypk4xhrd ; real_T
Gain1_Gain_agqevzoajc ; real_T Bias_Bias_kp4pcovegv ; real_T
Constant4_Value_bwrt5oukhm ; real_T Constant5_Value_abvqtbsmbe ; real_T
Gain2_Gain_dfafj4yf5d ; real_T Bias2_Bias_iyf2mr5qig ; real_T
Gain_Gain_aj4jewynfg ; real_T Bias1_Bias_bpnnrv2g4v ; real_T
IntegratorLimited_LowerSat ; real_T Constant_Value ; real_T Minus120_Value [
4 ] ; real_T Plus120_Value [ 4 ] ; real_T Gain2_Gain_jlslrcmtdv ; real_T
Constant2_Value ; real_T Constant_Value_ijz5z22oj1 ; real_T Bias3_Bias ;
real_T Constant7_Value ; real_T Constant9_Value ; real_T Constant8_Value ;
real_T Constant10_Value ; real_T Constant11_Value ; real_T
Constant2_Value_je4lnbr020 ; real_T Constant12_Value ; real_T Constant6_Value
; real_T Bias3_Bias_pumqr42kho ; real_T Constant7_Value_hf0hbvewrl ; real_T
Constant9_Value_ovatguv1cd ; real_T Constant8_Value_g0i1o1mso3 ; real_T
Constant10_Value_j1wyywihpk ; real_T Constant11_Value_nlg4rxjaav ; real_T
Constant2_Value_k1svmewxmc ; real_T Constant12_Value_asogurrks4 ; real_T
Constant6_Value_atr0rui2nv ; real_T Bias3_Bias_dlzcduozuu ; real_T
Constant7_Value_ckjsmfweco ; real_T Constant9_Value_b1dkmlfthl ; real_T
Constant8_Value_pnqqtlv3vz ; real_T Constant10_Value_gft3qlqgqh ; real_T
Constant11_Value_ei54wtxug1 ; real_T Constant2_Value_pdtwrvtyzr ; real_T
Constant12_Value_eihaiasqnb ; real_T Constant6_Value_d2i3udqljx ; real_T
Max_Lampda_PM_rate_Gain ; real_T Gain1_Gain_kogsiikotf ; real_T Gain3_Gain ;
real_T Trq_Or_Spd_Threshold ; real_T Trq_Or_Spd_Threshold_bv5qvwcnkb ; real_T
Gain_Gain_an2ok5irfz ; real_T Constant2_Value_ozzuwkqilp ; real_T
Minus120_Value_micf4v4hxs [ 4 ] ; real_T Gain2_Gain_lhlkdqm0ee ; real_T
Plus120_Value_hunie3hozg [ 4 ] ; real_T Gain3_Gain_oeu1akxnfz ; real_T
Gain1_Gain_ovhavq0wpo ; real_T Integrator_IC ; real_T
Constant_Value_dpuy0h0ihd [ 3 ] ; real_T toRad_Gain ; real_T
Constant_Value_jcoszycr0r ; real_T Constant1_Value_n213dknlmm ; real_T
Constant2_Value_ntrun4mqdf ; real_T Constant3_Value_jfxy4qopdq ; real_T
Constant4_Value_jg1qmih3ue ; real_T Constant5_Value_m54jfbbmbh ; real_T
raddeg_Gain ; real_T Amplitude1_Gain ; real_T SignalGenerator_Amplitude ;
real_T SignalGenerator_Frequency ; real_T Switch1_Threshold ; real_T
Switch1_Threshold_hyh3yfwgbh ; real_T Integrator_IC_lrmnxeinqj ; real_T
Integrator_WrappedStateUpperValue ; real_T Integrator_WrappedStateLowerValue
; real_T RPMtodegs_Gain ; real_T Constant2_Value_amvyq0ozrf ; real_T
Constant3_Value_clw2lo3chi ; real_T Constant4_Value_nmxg2ourug ; real_T
Constant1_Value_dsqxhplhg3 ; real_T Constant_Value_cu2gsqbnxd ; real_T
Constant_Value_oboowpiodw ; uint32_T R_maxIndex [ 2 ] ; uint32_T
EoHcTable_maxIndex [ 2 ] ; uint32_T EoCoTable_maxIndex [ 2 ] ; uint32_T
EoNOxTable_maxIndex [ 2 ] ; uint32_T EoCO2Table_maxIndex [ 2 ] ; uint32_T
EngTrqTable_maxIndex [ 2 ] ; uint32_T FuelMassFlwTable_maxIndex [ 2 ] ;
uint32_T AirFlowTable_maxIndex [ 2 ] ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_ParallelTestBench_GetDWork ( ) ; extern
void mr_ParallelTestBench_SetDWork ( const mxArray * ssDW ) ; extern mxArray
* mr_ParallelTestBench_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * ParallelTestBench_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
