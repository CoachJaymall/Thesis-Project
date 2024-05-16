#ifndef RTW_HEADER_ParallelTestBench_private_h_
#define RTW_HEADER_ParallelTestBench_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "ParallelTestBench_types.h"
#include "ParallelTestBench.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
    }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
#else
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
#endif
#endif
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)     (((v1)==(v2))?((double)(v1)):    (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?     muDoubleScalarFloor((v) + 0.5) :     muDoubleScalarCeil((v) - 0.5) )
#endif
extern real_T look2_binlxpw ( real_T u0 , real_T u1 , const real_T bp0 [ ] ,
const real_T bp1 [ ] , const real_T table [ ] , const uint32_T maxIndex [ ] ,
uint32_T stride ) ; extern real_T look2_binlcpw ( real_T u0 , real_T u1 ,
const real_T bp0 [ ] , const real_T bp1 [ ] , const real_T table [ ] , const
uint32_T maxIndex [ ] , uint32_T stride ) ; extern real_T look1_binlcapw (
real_T u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex
) ; extern real_T look2_binlcapw ( real_T u0 , real_T u1 , const real_T bp0 [
] , const real_T bp1 [ ] , const real_T table [ ] , const uint32_T maxIndex [
] , uint32_T stride ) ; extern uint32_T plook_binca ( real_T u , const real_T
bp [ ] , uint32_T maxIndex , real_T * fraction ) ; extern real_T
intrp2d_la_pw ( const uint32_T bpIndex [ ] , const real_T frac [ ] , const
real_T table [ ] , const uint32_T stride , const uint32_T maxIndex [ ] ) ;
extern uint32_T binsearch_u32d ( real_T u , const real_T bp [ ] , uint32_T
startIndex , uint32_T maxIndex ) ; extern void l55fduec5s ( real_T dyeje5qv3b
, real_T * fin2uqwxpj ) ;
#if defined(MULTITASKING)
#error Model (ParallelTestBench) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
