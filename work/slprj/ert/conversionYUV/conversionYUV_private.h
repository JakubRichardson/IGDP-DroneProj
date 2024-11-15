/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: conversionYUV_private.h
 *
 * Code generated for Simulink model 'conversionYUV'.
 *
 * Model version                  : 8.1
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Nov  6 18:10:37 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_conversionYUV_private_h_
#define RTW_HEADER_conversionYUV_private_h_
#include "rtwtypes.h"
#include "conversionYUV.h"
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

extern P_conversionYUV_T conversionYUV_P;

#endif                                 /* RTW_HEADER_conversionYUV_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
