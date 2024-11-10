/*
 * Code generation for system model 'conversionYUV'
 * For more details, see corresponding source file conversionYUV.c
 *
 */

#ifndef RTW_HEADER_conversionYUV_h_
#define RTW_HEADER_conversionYUV_h_
#ifndef conversionYUV_COMMON_INCLUDES_
#define conversionYUV_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* conversionYUV_COMMON_INCLUDES_ */

#include "conversionYUV_types.h"

/* Block signals for model 'conversionYUV' */
typedef struct {
  uint8_T Assignment1[19200];          /* '<S1>/Assignment1' */
  uint8_T Assignment1_f[19200];        /* '<S2>/Assignment1' */
  uint8_T Assignment1_k[19200];        /* '<S3>/Assignment1' */
} B_conversionYUV_c_T;

/* Real-time Model Data Structure */
struct tag_RTM_conversionYUV_T {
  const char_T **errorStatus;
};

typedef struct {
  B_conversionYUV_c_T rtb;
  RT_MODEL_conversionYUV_T rtm;
} MdlrefDW_conversionYUV_T;

/* Model reference registration function */
extern void conversionYUV_initialize(const char_T **rt_errorStatus,
  RT_MODEL_conversionYUV_T *const conversionYUV_M);
extern void conversionYUV(const uint8_T rtu_ImageData[38400], uint8_T rty_Y
  [19200], uint8_T rty_Cb[19200], uint8_T rty_Cr[19200], B_conversionYUV_c_T
  *localB);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'conversionYUV'
 * '<S1>'   : 'conversionYUV/Cb select'
 * '<S2>'   : 'conversionYUV/Cr select'
 * '<S3>'   : 'conversionYUV/Y' select'
 */
#endif                                 /* RTW_HEADER_conversionYUV_h_ */
