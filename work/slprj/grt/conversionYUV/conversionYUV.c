/*
 * Code generation for system model 'conversionYUV'
 *
 * Model                      : conversionYUV
 * Model version              : 8.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov  6 18:07:04 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "conversionYUV.h"
#include "rtwtypes.h"
#include <string.h>
#include "conversionYUV_private.h"

/* Output and update for referenced model: 'conversionYUV' */
void conversionYUV(const uint8_T rtu_ImageData[38400], uint8_T rty_Y[19200],
                   uint8_T rty_Cb[19200], uint8_T rty_Cr[19200],
                   B_conversionYUV_c_T *localB)
{
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  int32_T tmp_0;

  /* Assignment: '<S1>/Assignment1' incorporates:
   *  Assignment: '<S1>/Assignment'
   *  Constant: '<S1>/Constant'
   */
  memcpy(&localB->Assignment1[0], rtCP_Constant_Value, 19200U * sizeof(uint8_T));

  /* Assignment: '<S1>/Assignment' incorporates:
   *  Assignment: '<S1>/Assignment1'
   *  Constant: '<S1>/Constant1'
   *  Selector: '<Root>/u'
   */
  for (i = 0; i < 9600; i++) {
    localB->Assignment1[(int32_T)rtCP_Constant1_Value[i] - 1] = rtu_ImageData[(i
      << 2) + 1];
  }

  /* Assignment: '<S1>/Assignment1' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Selector: '<Root>/u'
   */
  for (i = 0; i < 9600; i++) {
    localB->Assignment1[(int32_T)rtCP_Constant2_Value[i] - 1] = rtu_ImageData[(i
      << 2) + 1];
  }

  /* Assignment: '<S2>/Assignment1' incorporates:
   *  Assignment: '<S2>/Assignment'
   *  Constant: '<S2>/Constant'
   */
  memcpy(&localB->Assignment1_f[0], rtCP_Constant_Value_d, 19200U * sizeof
         (uint8_T));

  /* Assignment: '<S2>/Assignment' incorporates:
   *  Assignment: '<S2>/Assignment1'
   *  Constant: '<S2>/Constant1'
   *  Selector: '<Root>/v'
   */
  for (i = 0; i < 9600; i++) {
    localB->Assignment1_f[(int32_T)rtCP_Constant1_Value_l[i] - 1] =
      rtu_ImageData[(i << 2) + 3];
  }

  /* Assignment: '<S2>/Assignment1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Selector: '<Root>/v'
   */
  for (i = 0; i < 9600; i++) {
    localB->Assignment1_f[(int32_T)rtCP_Constant2_Value_l[i] - 1] =
      rtu_ImageData[(i << 2) + 3];
  }

  /* Assignment: '<S3>/Assignment1' incorporates:
   *  Assignment: '<S3>/Assignment'
   *  Constant: '<S3>/Constant'
   */
  memcpy(&localB->Assignment1_k[0], rtCP_Constant_Value_i, 19200U * sizeof
         (uint8_T));

  /* Assignment: '<S3>/Assignment' incorporates:
   *  Assignment: '<S3>/Assignment1'
   *  Constant: '<S3>/Constant1'
   *  Selector: '<Root>/y1'
   */
  for (i = 0; i < 9600; i++) {
    localB->Assignment1_k[(int32_T)rtCP_Constant1_Value_i[i] - 1] =
      rtu_ImageData[i << 2];
  }

  /* Assignment: '<S3>/Assignment1' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Selector: '<Root>/y2'
   */
  for (i = 0; i < 9600; i++) {
    localB->Assignment1_k[(int32_T)rtCP_Constant2_Value_g[i] - 1] =
      rtu_ImageData[(i << 2) + 2];
  }

  for (i = 0; i < 160; i++) {
    for (i_0 = 0; i_0 < 120; i_0++) {
      /* Math: '<Root>/Transpose' incorporates:
       *  Math: '<Root>/Transpose1'
       *  Math: '<Root>/Transpose2'
       *  Reshape: '<Root>/Reshape'
       */
      tmp = 160 * i_0 + i;
      tmp_0 = 120 * i + i_0;
      rty_Y[tmp_0] = localB->Assignment1_k[tmp];

      /* Math: '<Root>/Transpose1' incorporates:
       *  Reshape: '<Root>/Reshape1'
       */
      rty_Cb[tmp_0] = localB->Assignment1[tmp];

      /* Math: '<Root>/Transpose2' incorporates:
       *  Reshape: '<Root>/Reshape2'
       */
      rty_Cr[tmp_0] = localB->Assignment1_f[tmp];
    }
  }
}

/* Model initialize function */
void conversionYUV_initialize(const char_T **rt_errorStatus,
  RT_MODEL_conversionYUV_T *const conversionYUV_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(conversionYUV_M, rt_errorStatus);
}
