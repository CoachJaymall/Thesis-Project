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
#include "ParallelTestBench_62883109_1_ic_fcn.h"
#include "nesl_rtw_lti.h"
#include "nesl_rtw.h"
#include "ParallelTestBench_1d80934b_1_gateway.h"
#include "ParallelTestBench_2ae6a85b_1_gateway.h"
#include "ParallelTestBench_59b138b3_1_gateway.h"
#endif
#include "ParallelTestBench_types.h"
#include "mwmathutil.h"
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rt_matrixlib.h"
#include "rt_nonfinite.h"
#define MODEL_NAME ParallelTestBench
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (145) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (26)   
#elif NCSTATES != 26
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
typedef struct { int8_T iibbwx5nxu ; } fy52y54vao ; typedef struct { real_T
irttg002ix ; real_T au0ix1q5sj ; real_T ix0ijjsadq ; real_T i4tiig10qa ;
real_T mxgpxbyfng [ 4 ] ; real_T kyvpkfkfuw [ 5 ] ; real_T m12o31k1vs [ 2 ] ;
real_T iavmf0c0td ; real_T g1be22q2ab [ 4 ] ; real_T akjx0hsfge [ 4 ] ;
real_T a51hahehmm [ 2 ] ; real_T ivfnl2doo0 ; real_T cftqthzuab ; real_T
e4wlihh0yp ; real_T m3wbmdk01n ; real_T cq2d2pwdt4 ; real_T cxcy4qomm3 ;
real_T gmqd0r1s5n ; real_T dnk2tludg2 ; real_T jhai0ek5up [ 4 ] ; real_T
nwoetve5i4 [ 4 ] ; real_T ea1x0lvxve ; real_T beedf1ybtr ; real_T hq4mhr11mq
; real_T mqvpg31jlu ; real_T a4b4l1echj ; real_T eqqz4ci0tv ; real_T
fdtuj3yfv3 ; real_T ka3c0rpnqg ; real_T nt4pl2mpy0 ; real_T mpbv3fozuy ;
real_T k2emjlyzxk ; real_T ahrdefsall ; real_T csh2m1cgxy ; real_T a5w4q3xmqj
; real_T kgbpab1bft ; real_T nufjeirxpo ; real_T ii512bfhkj ; real_T
prxcefcei5 ; real_T ocvt3xrn00 ; real_T ht0sdc4e2n ; real_T nfsnsrxlvr ;
real_T j14q1l0ljs [ 3 ] ; real_T fpnl3wyn4z ; real_T krukbv1au2 ; real_T
krguxydvse ; real_T lufxmyxbr0 ; real_T ivjcnxt5l0 ; real_T lxakjhp4ut ;
real_T cvfcfkbbot ; real_T ck20ozhunb ; real_T mkzwwcawji ; real_T kvxxl1simd
; real_T fcdzod43fw ; real_T h1yvg3hrrj ; real_T i32tsyahbh ; real_T
c210qvuzpq ; real_T nlnobuqb4t ; real_T obpp1l4vac ; real_T k21i5spcnm ;
real_T chctnrcvr3 ; real_T d44xfr2uxh ; real_T ksa4mls0wk ; real_T fkufe2dwcc
; real_T aarbwzwmur ; real_T m3te3eovpd ; real_T em2j1rtzfx ; real_T
baetrfr4r5 ; real_T k2zygd0izr ; real_T m4hxih4mk4 ; real_T gvb04ezgus ;
real_T lh5ejoytai ; real_T bvlzron2lo ; real_T bdpeazbcik ; real_T ddcgg2bx0n
; real_T dbu1cph3qd ; real_T gx1mbhkzzf ; real_T kkagvopgxv ; real_T
jtkb23rkw2 ; real_T k2zpu1crq0 ; real_T ceua4sozts ; real_T enjx00pe1u ;
real_T lg5bmspaoy ; real_T mi1n1xzbri ; real_T ph0oqajh3o ; real_T feuebfqypv
; real_T foeysnqrik ; real_T cgtnywjknf ; real_T il1hhqxhtq ; real_T
gxy0dk5ecd ; real_T fkz44ny3ao ; real_T max0cti2zd ; real_T h4fmwxdtzw ;
real_T ct0fhunmet ; real_T ludaotrnqc ; real_T fyijl5q30k ; real_T dmu1xpyaah
; real_T jem0p5cmwo ; real_T h1oufun4jj ; real_T ary5hhvnmx ; real_T
obnipod5vd ; real_T hcl3f2ypn0 ; real_T btuvjnvywk ; real_T ja5xj0z1cg ;
real_T kumjwk2t03 ; real_T g122wtg0el ; real_T fhuegjob4p ; real_T avg1hsnek4
; real_T lo0fmxamwn ; real_T bykovcr4gn ; real_T ml5chi14gx ; real_T
favitckluv ; real_T fjud52gekg [ 12 ] ; real_T frdjc0ipbc ; real_T pomgrq4ofk
; real_T lthpnqg4ps ; real_T m4bwkc5hnn ; real_T ennxpj0tru [ 12 ] ; real_T
n3yzlaao40 ; real_T ctnwpqizmx ; real_T o1uhppc0j4 ; real_T gg2bbcdrrw ;
real_T gssztf5fdg ; real_T m5zlrndttj ; real_T hzgfvz42dk ; real_T h2k2rk41bt
; real_T gnyyc12ptg ; real_T jjopdzn0py ; real_T hbxfzslsut ; real_T
enyymmluck ; real_T nhto33wndj ; real_T cguxiwph41 ; real_T d0ddtqwuj5 ;
real_T olw4ikbxkg ; real_T mxxpbb3p2w ; real_T jhwxdwr1el ; real_T itamdryrgl
; real_T fxbpkblr2q ; real_T m4c5zvfilf [ 4 ] ; real_T otltqoc5al ; real_T
ev0c2l5p3p ; real_T hg3boogiog ; uint8_T kt4qdvgqqh ; uint8_T oudpsgugrl ; }
B ; typedef struct { real_T hjhhmazifh ; real_T oudbjq0hed ; real_T
m4v13avdck ; real_T a0ptfrtioc ; real_T g3lob33pj5 ; real_T pyb4n2kdpt ;
real_T e3d0a5oz4x ; real_T pgf331hvhc ; real_T bxrcqiwwif ; real_T hbjtppjnxc
; real_T oajcj2f1f5 ; real_T jny3tr51z3 ; real_T hvgg13kj3s ; real_T
k1fhodjxic ; real_T l5far1dd5s ; real_T dgpg4jadhr ; real_T aij0ldcei4 ;
real_T cfefmj5zwg ; real_T cern2voaws ; real_T htxaynbdci ; struct { void *
LoggedData ; } etki2a0fmr ; struct { void * TimePtr ; void * DataPtr ; void *
RSimInfoPtr ; } bw5y0i4p2l ; void * j5biz3l2tk ; void * i1wgzi3jpe ; void *
bob4xgg01l ; void * mpzxqeukhd ; void * fcg0ekphtg ; void * mvpr3sjc4r ; void
* bakhwucptv ; void * fzbhykh1xq ; void * jhafhymz3x ; void * j5cfxvshqy ;
void * jeli2jkiuj ; void * pzexosznjb ; void * j1r4xwoi0i ; void * fsqmnkfwyn
; void * gn0zhdovru ; void * boku4grpzp ; void * iakvzasvoq ; void *
hrke45uylg ; void * f5g5n2hoel ; void * kt3tl4tehf ; struct { void * TimePtr
; void * DataPtr ; void * RSimInfoPtr ; } jhtpgte2wi ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } hvxajhbgno ; struct { void
* TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } fr1mfxzf32 ; void *
p2ezmuppnc ; void * hedrhiezbd ; void * d21wvb0imp ; void * oyqqlrp3de ; void
* mmqzqkgwoq ; void * dfna2oq4ag ; void * llxxjvefz5 ; void * ayv1jfdv3n ;
void * dg2tvdaeix ; void * mdrultrm3a ; struct { void * LoggedData [ 3 ] ; }
cvkblbg5ng ; struct { void * LoggedData ; } pd5drfuyof ; struct { void *
LoggedData ; } d3le14d3cp ; struct { void * LoggedData ; } kjvolenzbx ;
struct { void * LoggedData ; } pene5pwpkv ; struct { void * LoggedData ; }
jo5onp05oj ; struct { void * LoggedData [ 3 ] ; } jsi4xupntz ; struct { void
* LoggedData ; } pbrgjp3hqd ; struct { void * LoggedData ; } gnxi5omu0q ;
struct { void * LoggedData ; } ay2vulzcxm ; struct { void * LoggedData ; }
n0zwk3f2xj ; struct { void * LoggedData [ 4 ] ; } dwk0spdowz ; struct { void
* LoggedData [ 4 ] ; } ppi2an01a4 ; struct { void * LoggedData [ 2 ] ; }
k5h4rh0ide ; struct { void * LoggedData ; } coy5zsehq2 ; struct { void *
LoggedData ; } bslxcnpnbe ; struct { void * LoggedData [ 2 ] ; } oudcefeijx ;
struct { void * LoggedData [ 2 ] ; } ngauttml0y ; struct { void * LoggedData
[ 2 ] ; } aruc1k5fox ; int_T jclc1m30fx ; struct { int_T PrevIndex ; }
d05f353xni ; int_T bmyjja4qwv ; int_T dorteqrwse ; int_T n0n2vuipdf ; int_T
ke0t5lasbz ; struct { int_T PrevIndex ; } jcqddiyhqh ; struct { int_T
PrevIndex ; } eixvkodrjc ; struct { int_T PrevIndex ; } dtpp4iwgtx ; int_T
k5a5eyevvp ; int_T l4dxiaonqg ; int_T b2vnrg1jny ; int_T ewedjye3z0 ; int_T
d24a3iy2yr ; int32_T nr541hf2w4 ; int32_T jueswsqa1v ; int32_T cndm4gb520 ;
int8_T g5r1yktyf0 ; int8_T pitowdgxye ; int8_T fxz4zvrdnk ; int8_T efurz0y3yi
; int8_T pii1ltmep3 ; int8_T jsvlghnnou ; int8_T mwn40uclws ; int8_T
bnrzbkqovy ; int8_T hsbxk4y5en ; int8_T fs2zaamasz ; int8_T apx4aufauy ;
int8_T i0u0wqsccx ; int8_T bomurwpyov ; int8_T mjf1zdwwpb ; int8_T aeu2i4j0ln
; int8_T dd5lqxkqw1 ; int8_T pkdoeu3vac ; int8_T iuutt5gbfx ; int8_T
ifu2rmppxs ; int8_T fe1jlxthwc ; int8_T jbdxmczt2f ; int8_T lpzxn11asy ;
int8_T miza0bwslu ; int8_T okv3jznoxf ; int8_T ns1xtz2b4p ; int8_T k11uca0ow3
; int8_T byziukqaaz ; int8_T fn0wimupx0 ; int8_T cgq2mdkand ; int8_T
auskljzuj1 ; boolean_T gnqj1fyav2 ; boolean_T hembao2eny ; boolean_T
lbv1klntc2 ; boolean_T a2nmjrkqqq ; boolean_T jnjyibka5j ; boolean_T
kkz3bigo3a ; boolean_T iy5ftg1sqh ; fy52y54vao n0kqgy2htn ; fy52y54vao
l55fduec5sc ; } DW ; typedef struct { real_T hjvfmqrotz ; real_T hterznv3np ;
real_T eap5trepgw ; real_T dinj2vqkhf [ 5 ] ; real_T fpxoom5wcz ; real_T
cmzleelpyc [ 4 ] ; real_T itgqcjsbx5 ; real_T o3f51d5jei [ 4 ] ; real_T
it0jfj1ga4 ; real_T almmbag3ud ; real_T pntygaqlkb ; real_T ju22bzmclv ;
real_T k0f2ivlpoh ; real_T lcxpannrra ; real_T hlra0g33ul ; real_T mw03mcasf2
; } X ; typedef int_T PeriodicIndX [ 2 ] ; typedef real_T PeriodicRngX [ 4 ]
; typedef struct { real_T hjvfmqrotz ; real_T hterznv3np ; real_T eap5trepgw
; real_T dinj2vqkhf [ 5 ] ; real_T fpxoom5wcz ; real_T cmzleelpyc [ 4 ] ;
real_T itgqcjsbx5 ; real_T o3f51d5jei [ 4 ] ; real_T it0jfj1ga4 ; real_T
almmbag3ud ; real_T pntygaqlkb ; real_T ju22bzmclv ; real_T k0f2ivlpoh ;
real_T lcxpannrra ; real_T hlra0g33ul ; real_T mw03mcasf2 ; } XDot ; typedef
struct { boolean_T hjvfmqrotz ; boolean_T hterznv3np ; boolean_T eap5trepgw ;
boolean_T dinj2vqkhf [ 5 ] ; boolean_T fpxoom5wcz ; boolean_T cmzleelpyc [ 4
] ; boolean_T itgqcjsbx5 ; boolean_T o3f51d5jei [ 4 ] ; boolean_T it0jfj1ga4
; boolean_T almmbag3ud ; boolean_T pntygaqlkb ; boolean_T ju22bzmclv ;
boolean_T k0f2ivlpoh ; boolean_T lcxpannrra ; boolean_T hlra0g33ul ;
boolean_T mw03mcasf2 ; } XDis ; typedef struct { int_T ir [ 26 ] ; int_T jc [
27 ] ; real_T pr [ 26 ] ; } MassMatrix ; typedef struct { real_T
rtw_collapsed_sub_expr_8KZy8ZUC4h5CT21RYTS0zD_1 [ 11 ] ; real_T
rtw_collapsed_sub_expr_FucNF5IedxlzbnilUMUgVH_1 [ 12 ] ; } ConstP ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
Batt_Cap ; real_T Batt_Parr ; real_T Batt_Series ; real_T Dyno_Ke ; real_T
Dyno_Kt ; real_T Dyno_Ratio ; real_T Fuel_Map [ 84 ] ; real_T Fuel_MapE [ 84
] ; real_T Power_Map [ 84 ] ; real_T Power_Thr_Map [ 66 ] ; real_T SideA_N ;
real_T SideA_Physical_Param [ 3 ] ; real_T SideA_RatedTrq ; real_T SideA_Rs ;
real_T SideA_lambda ; real_T Spd_BP [ 7 ] ; real_T Trq_BP [ 12 ] ; real_T
DatasheetBattery_BattTempBp [ 7 ] ; real_T DatasheetBattery_CapLUTBp [ 101 ]
; real_T DatasheetBattery_CapSOCBp [ 6 ] ; real_T DatasheetBattery_Em [ 101 ]
; real_T SurfaceMountPMController1_Fs ; real_T SurfaceMountPMController1_Fv ;
real_T SurfaceMountPMController1_Jcomp ; real_T SurfaceMountPMController1_Ki
; real_T SurfaceMountPMController1_Kisa ; real_T
SurfaceMountPMController1_Kp_d ; real_T SurfaceMountPMController1_Kp_q ;
real_T SurfaceMountPMController1_Ksa ; real_T SurfaceMountPMController1_Ksf ;
real_T DatasheetBattery_RInt [ 42 ] ; real_T DatasheetBattery_Tc ; real_T
DatasheetBattery_Vinit ; real_T SurfaceMountPMController1_ba ; real_T
SKP6485_idq0 [ 2 ] ; real_T SurfaceMountPMController1_idq_limits ; real_T
SKP6485_omega_init ; real_T SKP6485_theta_init ; real_T Constant_Value ;
real_T Constant1_Value ; real_T Merge_InitialOutput ; real_T
Merge1_InitialOutput ; real_T Constant2_Value ; real_T Constant3_Value ;
real_T Constant5_Value ; real_T Gain_Gain ; real_T Gain1_Gain ; real_T
Gain5_Gain ; real_T Gain4_Gain ; real_T Gain2_Gain ; real_T Gain3_Gain ;
real_T Gain1_Gain_j1b2wfl0wo ; real_T Merge1_InitialOutput_j4un0hwehg ;
real_T Proportional_Gain3_Gain ; real_T UnitDelay_InitialCondition ; real_T
Gain1_Gain_he3uzhz5qz ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T UnitDelay_InitialCondition_cpl50tg2hx ; real_T
Gain1_Gain_nnzhsn1hyd ; real_T Saturation_UpperSat_phs0dpqpzg ; real_T
Saturation_LowerSat_gdduvb3oo2 ; real_T Proportional_Gain2_Gain ; real_T
Gain1_Gain_fvtzit2ppk ; real_T Gain2_Gain_en3fcdxiec ; real_T
Gain3_Gain_h5v1k1sppn ; real_T Gain4_Gain_ne1f41rvzn ; real_T Constant4_Value
; real_T Gain1_Gain_c2kuo5vmhc ; real_T Constant1_Value_brfyntmkio ; real_T
DiscreteTimeIntegrator_gainval ; real_T DiscreteTimeIntegrator_IC ; real_T
DiscreteTimeIntegrator1_gainval ; real_T DiscreteTimeIntegrator1_IC ; real_T
DiscreteTimeIntegrator_gainval_p43vz5tnpd ; real_T
DiscreteTimeIntegrator_IC_nipgxr4w4m ; real_T uDLookupTable_bp01Data [ 11 ] ;
real_T uDLookupTable_bp02Data [ 6 ] ; real_T uDLookupTable1_tableData [ 11 ]
; real_T Switch_Threshold ; real_T Constant2_Value_nzc55mhdyv ; real_T
Constant_Value_kkku1dkpit ; real_T uDLookupTable2_tableData [ 60 ] ; real_T
uDLookupTable2_bp01Data [ 10 ] ; real_T uDLookupTable2_bp02Data [ 6 ] ;
real_T Switch1_Threshold ; real_T Switch4_Threshold ; real_T
Constant_Value_lsistt0yxv ; real_T Switch2_Threshold ; real_T
Switch1_Threshold_er3fpts1xb ; real_T Merge_InitialOutput_l2wioipoqf ; real_T
Constant2_Value_ibttoaofbk ; real_T Constant3_Value_hvfq5alqlg [ 12 ] ;
real_T Constant4_Value_fecgcw2rtb ; real_T Constant5_Value_axuapffnub ;
real_T Constant_Value_ea5wuf1vfl ; real_T Switch2_Threshold_bn224qmpbp ;
real_T Switch1_Threshold_n1hoa2ckzb ; real_T Constant_Value_m22jzxcnam ;
real_T Constant2_Value_fkd3f5524d ; real_T Constant3_Value_mwesjrmlpm [ 12 ]
; real_T Constant4_Value_mph0ksevah ; real_T Constant5_Value_p2jqkjofwo ;
real_T Constant1_Value_eafxkgr2qu ; real_T Step_Time ; real_T Step_Y0 ;
real_T Step_YFinal ; real_T fromWS_Signal1_Time0 [ 15 ] ; real_T
fromWS_Signal1_Data0 [ 15 ] ; real_T Int_UpperSat ; real_T Int_LowerSat ;
real_T fromWS_Signal1_Time0_ommwt43mku [ 11 ] ; real_T
fromWS_Signal1_Data0_lxog1ybljy [ 11 ] ; real_T
fromWS_Signal1_Time0_pgpp53252z [ 8 ] ; real_T
fromWS_Signal1_Data0_n4yqnlgdbj [ 8 ] ; real_T
fromWS_Signal1_Time0_eamifk5xcs [ 12 ] ; real_T
fromWS_Signal1_Data0_prwgobmyi3 [ 12 ] ; real_T
Merge1_InitialOutput_ngwc5befhy ; real_T Merge2_InitialOutput ; real_T
Merge3_InitialOutput ; real_T Merge_InitialOutput_htptbem0s2 ; real_T
DA50TorqueMap_tableData [ 66 ] ; real_T DA50TorqueMap_bp01Data [ 11 ] ;
real_T DA50TorqueMap_bp02Data [ 6 ] ; real_T DA50PowerMap_tableData [ 66 ] ;
real_T DA50PowerMap_bp01Data [ 11 ] ; real_T DA50PowerMap_bp02Data [ 6 ] ;
real_T rpmtorads_Gain ; real_T Integrator_IC ; real_T Gain1_Gain_nd3h1ot2bp ;
real_T kgstogmin_Gain ; real_T Integrator_UpperSat ; real_T
Integrator_LowerSat ; real_T Int1_WrappedStateUpperValue ; real_T
Int1_WrappedStateLowerValue ; real_T Integrator_UpperSat_dip02x0ffl ; real_T
Integrator_LowerSat_bbrmas44s3 ; real_T Gain2_Gain_hwyq1kurck ; real_T
Gain3_Gain_lvn3xsxcbg ; real_T Gain1_Gain_heyv1n0f4a ; real_T
Gain4_Gain_c032xsbfri ; real_T IntegratorLimited_LowerSat ; real_T
Integrator_IC_ahzk3fe0wi ; real_T Integrator_WrappedStateUpperValue ; real_T
Integrator_WrappedStateLowerValue ; real_T RPMtodegs_Gain ; real_T
Gain5_Gain_ofpzj4djyh ; real_T Gain_Gain_a2pdrz3qwa ; real_T
Gain1_Gain_p2f3paaf35 ; real_T Gain4_Gain_a3qhxjwm2o ; real_T
Gain2_Gain_f3g2yr2rkw ; real_T Gain3_Gain_kigulbfrzl ; real_T
Constant_Value_in3f0w41r2 ; real_T Constant1_Value_bpuwj1x24m ; real_T
Constant2_Value_iswfbqmgg0 ; real_T Constant3_Value_clw2lo3chi ; real_T
Constant4_Value_o2jsgu5bg0 ; real_T Constant1_Value_ohpunqj1gy ; real_T
Constant3_Value_otox1iiiva ; real_T Constant5_Value_n1ykd3pjvs ; real_T
Constant1_Value_mj3ya5njvu ; real_T Constant_Value_c45tuyaygc [ 2 ] ; real_T
Constant2_Value_m2kdydkjx0 ; real_T Constant1_Value_bg0rrb32ed ; real_T
Constant_Value_go40v4ie0s [ 2 ] ; real_T Constant1_Value_kozehzplrf ; real_T
Constant_Value_dm14eym3wc [ 2 ] ; real_T Constant1_Value_k5ndhlm4pr ; real_T
Constant2_Value_fw4dwfnqy4 ; real_T Constant1_Value_om5j34o2qt [ 2 ] ; real_T
Constant2_Value_kk042enjt5 ; real_T Constant1_Value_nwflgkncxk ; real_T
Constant_Value_aqptyhwws5 [ 2 ] ; real_T Constant1_Value_il2awj2dhq ; real_T
Constant_Value_pf0letx30a [ 2 ] ; real_T Constant1_Value_na2pva40rs ; real_T
Constant2_Value_nligrrj1ds ; real_T Constant1_Value_b2jt3bjlb1 [ 2 ] ; real_T
Constant2_Value_e34qlb3i30 ; real_T Constant1_Value_igomjraxnc [ 2 ] ; real_T
Constant2_Value_hsqnj2ufwi ; uint32_T uDLookupTable_maxIndex [ 2 ] ; uint32_T
uDLookupTable2_maxIndex [ 2 ] ; uint32_T uDLookupTable2_maxIndex_ebipil2bvy [
2 ] ; uint32_T uDLookupTable2_maxIndex_pobosuq2zq [ 2 ] ; uint32_T
uDLookupTable_maxIndex_amrotqgr0w [ 2 ] ; uint32_T
uDLookupTable2_maxIndex_ljaygbg3k3 [ 2 ] ; uint32_T
uDLookupTable2_maxIndex_iu5fpwg5m1 [ 2 ] ; uint32_T
uDLookupTable_maxIndex_c0gevfgaga [ 2 ] ; uint32_T DA50TorqueMap_maxIndex [ 2
] ; uint32_T DA50PowerMap_maxIndex [ 2 ] ; uint32_T EngTrqTable_maxIndex [ 2
] ; uint32_T FuelMassFlwTable_maxIndex [ 2 ] ; uint32_T R_maxIndex [ 2 ] ;
uint8_T Switch3_Threshold ; uint8_T Switch3_Threshold_ff0k22oeft ; uint8_T
ManualSwitch3_CurrentSetting ; uint8_T ManualSwitch2_CurrentSetting ; uint8_T
ManualSwitch_CurrentSetting ; uint8_T ManualSwitch1_CurrentSetting ; } ;
extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X
rtX ; extern DW rtDW ; extern MassMatrix rtMassMatrix ; extern P rtP ; extern
const ConstP rtConstP ; extern mxArray * mr_ParallelTestBench_GetDWork ( ) ;
extern void mr_ParallelTestBench_SetDWork ( const mxArray * ssDW ) ; extern
mxArray * mr_ParallelTestBench_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * ParallelTestBench_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
