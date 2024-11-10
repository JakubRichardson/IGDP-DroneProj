/*
 * conversionYUV_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "conversionYUV".
 *
 * Model version              : 8.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov  6 18:07:04 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_conversionYUV_private_h_
#define RTW_HEADER_conversionYUV_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "conversionYUV_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real_T rtCP_pooled_7Q915ANeRrrp[9600];
extern const real_T rtCP_pooled_j3RVgm1swIbn[9600];
extern const uint8_T rtCP_pooled_k6SsflapTWml[19200];

#define rtCP_Constant1_Value           rtCP_pooled_7Q915ANeRrrp  /* Expression: 1:2:120*160
                                                                  * Referenced by: '<S1>/Constant1'
                                                                  */
#define rtCP_Constant2_Value           rtCP_pooled_j3RVgm1swIbn  /* Expression: 2:2:120*160
                                                                  * Referenced by: '<S1>/Constant2'
                                                                  */
#define rtCP_Constant1_Value_l         rtCP_pooled_7Q915ANeRrrp  /* Expression: 1:2:120*160
                                                                  * Referenced by: '<S2>/Constant1'
                                                                  */
#define rtCP_Constant2_Value_l         rtCP_pooled_j3RVgm1swIbn  /* Expression: 2:2:120*160
                                                                  * Referenced by: '<S2>/Constant2'
                                                                  */
#define rtCP_Constant1_Value_i         rtCP_pooled_7Q915ANeRrrp  /* Expression: 1:2:120*160
                                                                  * Referenced by: '<S3>/Constant1'
                                                                  */
#define rtCP_Constant2_Value_g         rtCP_pooled_j3RVgm1swIbn  /* Expression: 2:2:120*160
                                                                  * Referenced by: '<S3>/Constant2'
                                                                  */
#define rtCP_Constant_Value            rtCP_pooled_k6SsflapTWml  /* Computed Parameter: rtCP_Constant_Value
                                                                  * Referenced by: '<S1>/Constant'
                                                                  */
#define rtCP_Constant_Value_d          rtCP_pooled_k6SsflapTWml  /* Computed Parameter: rtCP_Constant_Value_d
                                                                  * Referenced by: '<S2>/Constant'
                                                                  */
#define rtCP_Constant_Value_i          rtCP_pooled_k6SsflapTWml  /* Computed Parameter: rtCP_Constant_Value_i
                                                                  * Referenced by: '<S3>/Constant'
                                                                  */
#endif                                 /* RTW_HEADER_conversionYUV_private_h_ */
