/*
 * flightController_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightController".
 *
 * Model version              : 8.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov  6 18:07:40 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightController_private_h_
#define RTW_HEADER_flightController_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "flightController_types.h"

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

extern const real32_T rtCP_pooled_2wNFT1ZWttsk[16];
extern const real32_T rtCP_pooled_QHST6j4mFBPy[4];

#define rtCP_TorqueTotalThrustToThrustPerMotor_Value rtCP_pooled_2wNFT1ZWttsk/* Computed Parameter: rtCP_TorqueTotalThrustToThrustPerMotor_Value
                                                                      * Referenced by: '<S3>/TorqueTotalThrustToThrustPerMotor'
                                                                      */
#define rtCP_MotorDirections_Gain      rtCP_pooled_QHST6j4mFBPy  /* Computed Parameter: rtCP_MotorDirections_Gain
                                                                  * Referenced by: '<S7>/MotorDirections'
                                                                  */
#endif                              /* RTW_HEADER_flightController_private_h_ */
