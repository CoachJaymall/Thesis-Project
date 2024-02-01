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
extern real_T look1_binlcapw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T maxIndex ) ; extern real_T look2_binlcapw (
real_T u0 , real_T u1 , const real_T bp0 [ ] , const real_T bp1 [ ] , const
real_T table [ ] , const uint32_T maxIndex [ ] , uint32_T stride ) ; extern
real_T look2_binlcpw ( real_T u0 , real_T u1 , const real_T bp0 [ ] , const
real_T bp1 [ ] , const real_T table [ ] , const uint32_T maxIndex [ ] ,
uint32_T stride ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
