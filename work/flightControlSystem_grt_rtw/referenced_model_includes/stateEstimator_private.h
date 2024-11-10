/*
 * stateEstimator_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "stateEstimator".
 *
 * Model version              : 8.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov  6 18:08:04 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stateEstimator_private_h_
#define RTW_HEADER_stateEstimator_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "stateEstimator.h"
#include "stateEstimator_types.h"

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

extern const real_T rtCP_pooled_Qcj6ValmO9nO[3];
extern const real32_T rtCP_pooled_sCgdBDVjfNCf[4];
extern const real32_T rtCP_pooled_RcJHO0wrFbYK[4];
extern const real32_T rtCP_pooled_vGHRQ3wRE5s5[6];
extern const real32_T rtCP_pooled_TabNjHtdBtbW[6];
extern const real32_T rtCP_pooled_WYSLTACcacHZ[6];
extern const real32_T rtCP_pooled_EKScAA9U4nU0[6];

#define rtCP_Constant_Value            rtCP_pooled_Qcj6ValmO9nO  /* Expression: [0 0 g]
                                                                  * Referenced by: '<S3>/Constant'
                                                                  */
#define rtCP_C_Value_f                 rtCP_pooled_sCgdBDVjfNCf  /* Computed Parameter: rtCP_C_Value_f
                                                                  * Referenced by: '<S78>/C'
                                                                  */
#define rtCP_D_Value_f                 rtCP_pooled_RcJHO0wrFbYK  /* Computed Parameter: rtCP_D_Value_f
                                                                  * Referenced by: '<S78>/D'
                                                                  */
#define rtCP_C_Value_p                 rtCP_pooled_sCgdBDVjfNCf  /* Computed Parameter: rtCP_C_Value_p
                                                                  * Referenced by: '<S149>/C'
                                                                  */
#define rtCP_D_Value_b                 rtCP_pooled_RcJHO0wrFbYK  /* Computed Parameter: rtCP_D_Value_b
                                                                  * Referenced by: '<S149>/D'
                                                                  */
#define rtCP_Bias_Bias                 rtCP_pooled_vGHRQ3wRE5s5  /* Computed Parameter: rtCP_Bias_Bias
                                                                  * Referenced by: '<S5>/Bias'
                                                                  */
#define rtCP_IIR_IMUgyro_r_NumCoef     rtCP_pooled_TabNjHtdBtbW  /* Computed Parameter: rtCP_IIR_IMUgyro_r_NumCoef
                                                                  * Referenced by: '<S5>/IIR_IMUgyro_r'
                                                                  */
#define rtCP_IIR_IMUgyro_r_DenCoef     rtCP_pooled_WYSLTACcacHZ  /* Computed Parameter: rtCP_IIR_IMUgyro_r_DenCoef
                                                                  * Referenced by: '<S5>/IIR_IMUgyro_r'
                                                                  */
#define rtCP_FIR_IMUaccel_Coefficients rtCP_pooled_EKScAA9U4nU0  /* Computed Parameter: rtCP_FIR_IMUaccel_Coefficients
                                                                  * Referenced by: '<S5>/FIR_IMUaccel'
                                                                  */
#define rtCP_IIRgyroz_NumCoef          rtCP_pooled_TabNjHtdBtbW  /* Computed Parameter: rtCP_IIRgyroz_NumCoef
                                                                  * Referenced by: '<S77>/IIRgyroz'
                                                                  */
#define rtCP_IIRgyroz_DenCoef          rtCP_pooled_WYSLTACcacHZ  /* Computed Parameter: rtCP_IIRgyroz_DenCoef
                                                                  * Referenced by: '<S77>/IIRgyroz'
                                                                  */

/* Invariant block signals (default storage) */
extern const ConstB_stateEstimator_h_T stateEstimator_ConstB;

#endif                                /* RTW_HEADER_stateEstimator_private_h_ */
