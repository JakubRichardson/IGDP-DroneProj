/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControlSystem.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 8.25
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Nov 11 12:24:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightControlSystem.h"
#include "rtwtypes.h"
#include "flightControlSystem_types.h"
#include "flightControlSystem_private.h"
#include <math.h>
#include "rt_roundd_snf.h"
#include <string.h>
#include "conversionYUV.h"
#include "rt_nonfinite.h"
#define flightController_MDLREF_HIDE_CHILD_
#include "flightController.h"
#define stateEstimator_MDLREF_HIDE_CHILD_
#include "stateEstimator.h"

/* Named constants for Chart: '<S5>/Chart' */
#define flightControlSystem_IN_A3      ((uint8_T)1U)
#define flightControlSystem_IN_A4      ((uint8_T)2U)
#define flightControlSystem_IN_CloseGrabber ((uint8_T)1U)
#define flightControlSystem_IN_FollowPath ((uint8_T)2U)
#define flightControlSystem_IN_Hover   ((uint8_T)3U)
#define flightControlSystem_IN_Land    ((uint8_T)4U)
#define flightControlSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flightControlSystem_IN_Takeoff ((uint8_T)5U)

/* Named constants for Chart: '<S5>/Chart1' */
#define flightControlSystem_IN_A       ((uint8_T)1U)
#define flightControlSystem_IN_Start   ((uint8_T)2U)

/* Named constants for Chart: '<S5>/Chart2' */
#define flightControlSystem_IN_Forward ((uint8_T)1U)
#define flightControlSystem_IN_Forward1 ((uint8_T)2U)
#define flightControlSystem_IN_Land_d  ((uint8_T)3U)
#define flightControlSystem_IN_Left    ((uint8_T)4U)
#define flightControlSystem_IN_Right   ((uint8_T)5U)

/* Named constants for Chart: '<S5>/Chart3' */
#define flightControlSystem_IN_Left_f  ((uint8_T)3U)

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/controller' */
uint8_T flag_outport;                  /* '<S3>/Merge' */

/* Block signals (default storage) */
B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
DW_flightControlSystem_T flightControlSystem_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightControlSystem_T flightControlSystem_Y;

/* Real-time model */
static RT_MODEL_flightControlSystem_T flightControlSystem_M_;
RT_MODEL_flightControlSystem_T *const flightControlSystem_M =
  &flightControlSystem_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(flightControlSystem_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (flightControlSystem_M->Timing.TaskCounters.TID[1])++;
  if ((flightControlSystem_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.2s, 0.0s] */
    flightControlSystem_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S3>/Geofencing error'
 *    '<S3>/estimator//Optical flow error'
 *    '<S3>/Normal condition'
 */
void flightControlSystem_Geofencingerror(uint8_T *rty_Out1,
  P_Geofencingerror_flightControlSystem_T *localP)
{
  /* SignalConversion generated from: '<S13>/Out1' incorporates:
   *  Constant: '<S13>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/* System initialize for atomic system: '<S1>/Logging' */
void flightControlSystem_Logging_Init(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, DW_Logging_flightControlSystem_T *localDW)
{
  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace2' */
  {
    static int_T rt_ToWksWidths[] = { 12 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 12 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace2";
    localDW->ToWorkspace2_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "estim",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace6' */
  {
    static int_T rt_ToWksWidths[] = { 10 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 10 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace6";
    localDW->ToWorkspace6_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "sensor",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace6_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace3' */
  {
    static int_T rt_ToWksWidths[] = { 9 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 9 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace3";
    localDW->ToWorkspace3_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "cmd",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace4' */
  {
    static int_T rt_ToWksWidths[] = { 8 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 8 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace4";
    localDW->ToWorkspace4_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "optical",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace4_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace5' */
  {
    static int_T rt_ToWksWidths[] = { 8 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 8 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "SensorCalibration" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace5";
    localDW->ToWorkspace5_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "calib",
      1,
      0,
      100,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace5_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 4 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 4 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace";
    localDW->ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "motor",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<S4>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 8 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 8 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Flight Control System/Logging/To Workspace1";
    localDW->ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "posref",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }
}

/* Output and update for atomic system: '<S1>/Logging' */
void flightControlSystem_Logging(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const real32_T rtu_motorCmds[4], const real32_T
  rtu_posRef[8], const statesEstim_t *rtu_states_estim_Inport_3, const
  CommandBus *rtu_ReferenceValueServerBus_Inport_4, const SensorsBus
  *rtu_Sensors_Inport_5, real32_T rtu_sensordata_datin_Inport_6, uint32_T
  rtu_sensordata_datin_Inport_6_d, real32_T rtu_sensordata_datin_Inport_6_e,
  real32_T rtu_sensordata_datin_Inport_6_c, real32_T
  rtu_sensordata_datin_Inport_6_cg, real32_T rtu_sensordata_datin_Inport_6_i,
  real32_T rtu_sensordata_datin_Inport_6_h, real32_T
  rtu_sensordata_datin_Inport_6_b, real32_T rtu_sensordata_datin_Inport_6_dz,
  real32_T rtu_sensordata_datin_Inport_6_n, B_Logging_flightControlSystem_T
  *localB, DW_Logging_flightControlSystem_T *localDW)
{
  int32_T i;
  real32_T rtb_TmpSignalConversionAtToWorkspace4Inport1[8];
  real32_T rtb_DataTypeConversion11;
  real32_T rtb_DataTypeConversion7;

  /* SignalConversion generated from: '<S4>/To Workspace2' incorporates:
   *  SignalConversion generated from: '<S4>/states_estim_BusSelector'
   */
  localB->TmpSignalConversionAtToWorkspace2Inport1[0] =
    rtu_states_estim_Inport_3->X;
  localB->TmpSignalConversionAtToWorkspace2Inport1[1] =
    rtu_states_estim_Inport_3->Y;
  localB->TmpSignalConversionAtToWorkspace2Inport1[2] =
    rtu_states_estim_Inport_3->Z;
  localB->TmpSignalConversionAtToWorkspace2Inport1[3] =
    rtu_states_estim_Inport_3->yaw;
  localB->TmpSignalConversionAtToWorkspace2Inport1[4] =
    rtu_states_estim_Inport_3->pitch;
  localB->TmpSignalConversionAtToWorkspace2Inport1[5] =
    rtu_states_estim_Inport_3->roll;
  localB->TmpSignalConversionAtToWorkspace2Inport1[6] =
    rtu_states_estim_Inport_3->dx;
  localB->TmpSignalConversionAtToWorkspace2Inport1[7] =
    rtu_states_estim_Inport_3->dy;
  localB->TmpSignalConversionAtToWorkspace2Inport1[8] =
    rtu_states_estim_Inport_3->dz;
  localB->TmpSignalConversionAtToWorkspace2Inport1[9] =
    rtu_states_estim_Inport_3->p;

  /* DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
   *  SignalConversion generated from: '<S4>/states_estim_BusSelector'
   */
  rtb_DataTypeConversion7 = rtu_states_estim_Inport_3->q;

  /* DataTypeConversion: '<S4>/Data Type Conversion11' incorporates:
   *  SignalConversion generated from: '<S4>/states_estim_BusSelector'
   */
  rtb_DataTypeConversion11 = rtu_states_estim_Inport_3->r;

  /* SignalConversion generated from: '<S4>/To Workspace2' */
  localB->TmpSignalConversionAtToWorkspace2Inport1[10] = rtb_DataTypeConversion7;
  localB->TmpSignalConversionAtToWorkspace2Inport1[11] =
    rtb_DataTypeConversion11;

  /* ToWorkspace: '<S4>/To Workspace2' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace2_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace2Inport1[0]);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion11' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion1'
   */
  rtb_DataTypeConversion11 = rtu_sensordata_datin_Inport_6;

  /* DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   */
  rtb_DataTypeConversion7 = (real32_T)rtu_sensordata_datin_Inport_6_d;

  /* SignalConversion generated from: '<S4>/To Workspace6' */
  localB->TmpSignalConversionAtToWorkspace6Inport1[0] =
    rtu_sensordata_datin_Inport_6_e;
  localB->TmpSignalConversionAtToWorkspace6Inport1[1] =
    rtu_sensordata_datin_Inport_6_c;
  localB->TmpSignalConversionAtToWorkspace6Inport1[2] =
    rtu_sensordata_datin_Inport_6_cg;
  localB->TmpSignalConversionAtToWorkspace6Inport1[3] =
    rtu_sensordata_datin_Inport_6_i;
  localB->TmpSignalConversionAtToWorkspace6Inport1[4] =
    rtu_sensordata_datin_Inport_6_h;
  localB->TmpSignalConversionAtToWorkspace6Inport1[5] =
    rtu_sensordata_datin_Inport_6_b;
  localB->TmpSignalConversionAtToWorkspace6Inport1[6] =
    rtu_sensordata_datin_Inport_6_dz;
  localB->TmpSignalConversionAtToWorkspace6Inport1[7] =
    rtu_sensordata_datin_Inport_6_n;
  localB->TmpSignalConversionAtToWorkspace6Inport1[8] = rtb_DataTypeConversion11;
  localB->TmpSignalConversionAtToWorkspace6Inport1[9] = rtb_DataTypeConversion7;

  /* ToWorkspace: '<S4>/To Workspace6' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace6_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace6Inport1[0]);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion11' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   */
  rtb_DataTypeConversion11 =
    rtu_ReferenceValueServerBus_Inport_4->controlModePosVSOrient;

  /* SignalConversion generated from: '<S4>/To Workspace3' incorporates:
   *  SignalConversion generated from: '<S4>/ReferenceValueServerBus_BusSelector'
   */
  localB->TmpSignalConversionAtToWorkspace3Inport1[1] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[0];
  localB->TmpSignalConversionAtToWorkspace3Inport1[2] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[1];
  localB->TmpSignalConversionAtToWorkspace3Inport1[3] =
    rtu_ReferenceValueServerBus_Inport_4->pos_ref[2];

  /* DataTypeConversion: '<S4>/Data Type Conversion7' */
  rtb_DataTypeConversion7 = rtu_ReferenceValueServerBus_Inport_4->takeoff_flag;

  /* SignalConversion generated from: '<S4>/To Workspace3' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion9'
   *  SignalConversion generated from: '<S4>/ReferenceValueServerBus_BusSelector'
   */
  localB->TmpSignalConversionAtToWorkspace3Inport1[5] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[0];
  localB->TmpSignalConversionAtToWorkspace3Inport1[6] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[1];
  localB->TmpSignalConversionAtToWorkspace3Inport1[7] =
    rtu_ReferenceValueServerBus_Inport_4->orient_ref[2];
  localB->TmpSignalConversionAtToWorkspace3Inport1[8] = (real32_T)
    rtu_ReferenceValueServerBus_Inport_4->live_time_ticks;
  localB->TmpSignalConversionAtToWorkspace3Inport1[0] = rtb_DataTypeConversion11;
  localB->TmpSignalConversionAtToWorkspace3Inport1[4] = rtb_DataTypeConversion7;

  /* ToWorkspace: '<S4>/To Workspace3' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace3_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace3Inport1[0]);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion11' */
  rtb_DataTypeConversion11 = rtu_Sensors_Inport_5->VisionSensors.usePosVIS_flag;

  /* SignalConversion generated from: '<S4>/To Workspace4' incorporates:
   *  SignalConversion generated from: '<S4>/Sensors_BusSelector'
   */
  rtb_TmpSignalConversionAtToWorkspace4Inport1[1] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[0];
  rtb_TmpSignalConversionAtToWorkspace4Inport1[2] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[1];
  rtb_TmpSignalConversionAtToWorkspace4Inport1[3] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[2];
  rtb_TmpSignalConversionAtToWorkspace4Inport1[4] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[0];
  rtb_TmpSignalConversionAtToWorkspace4Inport1[5] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[1];
  rtb_TmpSignalConversionAtToWorkspace4Inport1[6] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[2];
  rtb_TmpSignalConversionAtToWorkspace4Inport1[7] =
    rtu_Sensors_Inport_5->VisionSensors.posVIS_data[3];
  rtb_TmpSignalConversionAtToWorkspace4Inport1[0] = rtb_DataTypeConversion11;

  /* ToWorkspace: '<S4>/To Workspace4' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace4_PWORK.LoggedData,
                          &locTime,
                          &rtb_TmpSignalConversionAtToWorkspace4Inport1[0]);
  }

  /* SignalConversion generated from: '<S4>/Sensors_BusSelector' */
  for (i = 0; i < 8; i++) {
    rtb_TmpSignalConversionAtToWorkspace4Inport1[i] =
      rtu_Sensors_Inport_5->SensorCalibration[i];
  }

  /* ToWorkspace: '<S4>/To Workspace5' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace5_PWORK.LoggedData,
                          &locTime,
                          &rtb_TmpSignalConversionAtToWorkspace4Inport1[0]);
  }

  /* ToWorkspace: '<S4>/To Workspace' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace_PWORK.LoggedData,
                          &locTime, &rtu_motorCmds[0]);
  }

  /* ToWorkspace: '<S4>/To Workspace1' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace1_PWORK.LoggedData,
                          &locTime, &rtu_posRef[0]);
  }
}

/* System initialize for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem_Init(RT_MODEL_flightControlSystem_T
  * const flightControlSystem_M, uint8_T *rty_Flag,
  DW_FlightControlSystem_flightControlSystem_T *localDW,
  P_FlightControlSystem_flightControlSystem_T *localP)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/Logging' */
  flightControlSystem_Logging_Init(flightControlSystem_M, &localDW->Logging);

  /* End of SystemInitialize for SubSystem: '<S1>/Logging' */

  /* SystemInitialize for Merge: '<S3>/Merge' */
  *rty_Flag = localP->Merge_InitialOutput;

  /* SystemInitialize for ModelReference: '<S1>/controller' */
  flightController_Init();

  /* SystemInitialize for ModelReference: '<S1>/estimator' */
  stateEstimator_Init();
}

/* Output and update for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds,
  const SensorsBus *rtu_Sensors_Inport_2, real32_T rty_motorCmds[4], uint8_T
  *rty_Flag, B_FlightControlSystem_flightControlSystem_T *localB,
  DW_FlightControlSystem_flightControlSystem_T *localDW,
  P_FlightControlSystem_flightControlSystem_T *localP)
{
  /* Chart: '<S5>/Chart3' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c4_flightControlSystem == 0U) {
    localDW->is_active_c4_flightControlSystem = 1U;
    localDW->is_c4_flightControlSystem = flightControlSystem_IN_Forward;
    localDW->temporalCounter_i1 = 0U;
    localB->dx = 0.0;
    localB->dy = 0.0;
  } else {
    switch (localDW->is_c4_flightControlSystem) {
     case flightControlSystem_IN_Forward:
      localB->dy = 0.0;
      if (localDW->temporalCounter_i1 >= 1000U) {
        localDW->is_c4_flightControlSystem = flightControlSystem_IN_Forward1;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case flightControlSystem_IN_Forward1:
      if (localDW->temporalCounter_i1 >= 1000U) {
        localDW->is_c4_flightControlSystem = flightControlSystem_IN_Left_f;
      } else {
        localB->dx = 0.001;
      }
      break;

     default:
      /* case IN_Left: */
      localB->dx = -0.001;
      break;
    }
  }

  /* End of Chart: '<S5>/Chart3' */

  /* Chart: '<S5>/Chart' */
  if (localDW->temporalCounter_i1_g < 2047U) {
    localDW->temporalCounter_i1_g++;
  }

  if (localDW->temporalCounter_i2 < 511U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->is_active_c3_flightControlSystem == 0U) {
    localDW->is_active_c3_flightControlSystem = 1U;
    localB->x_g = 0.0;
    localB->y_b = 0.0;
    localB->z_g = -1.0;
    localB->grabber_c = 1.0;
    localDW->is_c3_flightControlSystem = flightControlSystem_IN_Takeoff;
    localDW->temporalCounter_i2 = 0U;
    localDW->is_Takeoff = flightControlSystem_IN_A3;
    localDW->temporalCounter_i1_g = 0U;
    localB->takeoff_flag = 1.0;
  } else {
    switch (localDW->is_c3_flightControlSystem) {
     case flightControlSystem_IN_CloseGrabber:
      if (localDW->temporalCounter_i1_g >= 200U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Takeoff;
        localDW->temporalCounter_i2 = 0U;
        localDW->is_Takeoff = flightControlSystem_IN_A3;
        localDW->temporalCounter_i1_g = 0U;
        localB->takeoff_flag = 1.0;
      }
      break;

     case flightControlSystem_IN_FollowPath:
      if (localDW->temporalCounter_i1_g >= 2000U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Land;
        localB->z_g = -0.4;
      } else {
        localB->x_g += localB->dx;
        localB->y_b += localB->dy;
      }
      break;

     case flightControlSystem_IN_Hover:
      if (localDW->temporalCounter_i1_g >= 400U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_FollowPath;
        localDW->temporalCounter_i1_g = 0U;
      }
      break;

     case flightControlSystem_IN_Land:
      break;

     default:
      /* case IN_Takeoff: */
      if (localDW->temporalCounter_i2 >= 400U) {
        localDW->is_Takeoff = flightControlSystem_IN_NO_ACTIVE_CHILD;
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Hover;
        localDW->temporalCounter_i1_g = 0U;
        localB->z_g = -1.0;
      } else if ((localDW->is_Takeoff == flightControlSystem_IN_A3) &&
                 (localDW->temporalCounter_i1_g >= 160U)) {
        localDW->is_Takeoff = flightControlSystem_IN_A4;
        localB->takeoff_flag = 0.0;
      } else {
        /* case IN_A4: */
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* BusCreator: '<S5>/Bus Creator' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant3'
   *  DataTypeConversion: '<S5>/Cast To Boolean'
   *  DataTypeConversion: '<S5>/Cast To Single'
   */
  localB->BusCreator.controlModePosVSOrient = localP->Constant1_Value;
  localB->BusCreator.pos_ref[0] = (real32_T)localB->x_g;
  localB->BusCreator.pos_ref[1] = (real32_T)localB->y_b;
  localB->BusCreator.pos_ref[2] = (real32_T)localB->z_g;
  localB->BusCreator.takeoff_flag = (localB->takeoff_flag != 0.0);
  localB->BusCreator.orient_ref[0] = localP->Constant3_Value[0];
  localB->BusCreator.orient_ref[1] = localP->Constant3_Value[1];
  localB->BusCreator.orient_ref[2] = localP->Constant3_Value[2];
  localB->BusCreator.live_time_ticks =
    rtu_ReferenceValueServerCmds->live_time_ticks;

  /* SignalConversion generated from: '<S6>/Bus Selector3' */
  localB->rtb_x_f = rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.x;

  /* SignalConversion generated from: '<S6>/Bus Selector3' */
  localB->rtb_y_c = rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.y;

  /* SignalConversion generated from: '<S6>/Bus Selector3' */
  localB->rtb_z_pb = rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.z;

  /* SignalConversion generated from: '<S6>/Bus Selector4' */
  localB->rtb_x_c_b = rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.x;

  /* SignalConversion generated from: '<S6>/Bus Selector4' */
  localB->rtb_y_n_c = rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.y;

  /* SignalConversion generated from: '<S6>/Bus Selector4' */
  localB->rtb_z_p_k = rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.z;

  /* SignalConversion generated from: '<S6>/Bus Selector5' */
  localB->rtb_altitude_c =
    rtu_Sensors_Inport_2->HALSensors.HAL_ultrasound_SI.altitude;

  /* SignalConversion generated from: '<S6>/Bus Selector6' */
  localB->rtb_pressure_m =
    rtu_Sensors_Inport_2->HALSensors.HAL_pressure_SI.pressure;

  /* SignalConversion generated from: '<S6>/Bus Selector1' */
  localB->rtb_vbat_V_g = rtu_Sensors_Inport_2->HALSensors.HAL_vbat_SI.vbat_V;

  /* SignalConversion generated from: '<S6>/Bus Selector1' */
  localB->rtb_vbat_percentage_g =
    rtu_Sensors_Inport_2->HALSensors.HAL_vbat_SI.vbat_percentage;

  /* BusCreator generated from: '<S1>/estimator' */
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddx =
    localB->rtb_x_f;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddy =
    localB->rtb_y_c;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddz =
    localB->rtb_z_pb;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.p =
    localB->rtb_x_c_b;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.q =
    localB->rtb_y_n_c;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.r =
    localB->rtb_z_p_k;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.altitude_sonar
    = localB->rtb_altitude_c;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.prs =
    localB->rtb_pressure_m;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_V =
    localB->rtb_vbat_V_g;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_percentage
    = localB->rtb_vbat_percentage_g;

  /* ModelReference: '<S1>/estimator' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  stateEstimator_run(localP->Constant1_Value,
                     &localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1,
                     rtu_Sensors_Inport_2->VisionSensors.usePosVIS_flag,
                     &rtu_Sensors_Inport_2->VisionSensors.opticalFlow_data[0],
                     &rtu_Sensors_Inport_2->VisionSensors.posVIS_data[0],
                     &localB->estimator,
                     &rtu_Sensors_Inport_2->SensorCalibration[0]);

  /* ModelReference: '<S1>/controller' */
  flightController_run(&localB->BusCreator, &localB->estimator, &rty_motorCmds[0],
                       &localB->controller_o2[0]);

  /* Outputs for Atomic SubSystem: '<S1>/Logging' */
  flightControlSystem_Logging(flightControlSystem_M, rty_motorCmds,
    localB->controller_o2, &localB->estimator, rtu_ReferenceValueServerCmds,
    rtu_Sensors_Inport_2, localB->rtb_vbat_V_g, localB->rtb_vbat_percentage_g,
    localB->rtb_x_f, localB->rtb_y_c, localB->rtb_z_pb, localB->rtb_x_c_b,
    localB->rtb_y_n_c, localB->rtb_z_p_k, localB->rtb_altitude_c,
    localB->rtb_pressure_m, &localB->Logging, &localDW->Logging);

  /* End of Outputs for SubSystem: '<S1>/Logging' */

  /* Abs: '<S3>/Abs2' */
  localB->Max = (real32_T)fabs
    (rtu_Sensors_Inport_2->VisionSensors.opticalFlow_data[0]);

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  localB->Compare_h = (localB->Max > localP->CompareToConstant2_const);

  /* Gain: '<S3>/Gain2' */
  localB->Max = localP->Gain2_Gain *
    rtu_Sensors_Inport_2->VisionSensors.opticalFlow_data[0];

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Abs: '<S3>/Abs6'
   *  Constant: '<S12>/Constant'
   *  Sum: '<S3>/Add1'
   */
  localB->Compare_l = ((real32_T)fabs(localB->Max - localB->estimator.dx) >
                       localP->CompareToConstant6_const);

  /* Gain: '<S3>/Gain1' */
  localB->Max = localP->Gain1_Gain *
    rtu_Sensors_Inport_2->VisionSensors.opticalFlow_data[1];

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Abs: '<S3>/Abs3'
   *  Constant: '<S10>/Constant'
   *  Sum: '<S3>/Add'
   */
  localB->Compare_mb = ((real32_T)fabs(localB->Max - localB->estimator.dy) >
                        localP->CompareToConstant3_const);

  /* Abs: '<S3>/Abs5' */
  localB->Max = (real32_T)fabs
    (rtu_Sensors_Inport_2->VisionSensors.opticalFlow_data[1]);

  /* If: '<S3>/If' incorporates:
   *  Abs: '<S3>/Abs'
   *  Abs: '<S3>/Abs1'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator1'
   *  Logic: '<S3>/Logical Operator2'
   *  Logic: '<S3>/Logical Operator3'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   */
  if (((real32_T)fabs(localB->estimator.X) > localP->CompareToConstant_const) ||
      ((real32_T)fabs(localB->estimator.Y) > localP->CompareToConstant1_const))
  {
    /* Outputs for IfAction SubSystem: '<S3>/Geofencing error' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    flightControlSystem_Geofencingerror(rty_Flag, &localP->Geofencingerror);

    /* End of Outputs for SubSystem: '<S3>/Geofencing error' */
  } else if ((localB->Compare_h && localB->Compare_l) || (localB->Compare_mb &&
              (localB->Max > localP->CompareToConstant5_const))) {
    /* Outputs for IfAction SubSystem: '<S3>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    flightControlSystem_Geofencingerror(rty_Flag,
      &localP->estimatorOpticalflowerror);

    /* End of Outputs for SubSystem: '<S3>/estimator//Optical flow error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/Normal condition' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    flightControlSystem_Geofencingerror(rty_Flag, &localP->Normalcondition);

    /* End of Outputs for SubSystem: '<S3>/Normal condition' */
  }

  /* End of If: '<S3>/If' */

  /* MATLABSystem: '<S5>/Grabber' */
  localB->Grabber = rt_roundd_snf(localB->grabber_c);
  if (localB->Grabber < 256.0) {
    if (localB->Grabber >= 0.0) {
      localB->u = (uint8_T)localB->Grabber;
    } else {
      localB->u = 0U;
    }
  } else {
    localB->u = MAX_uint8_T;
  }

  localB->Grabber = MW_PARROT_Grabber(localB->u);

  /* End of MATLABSystem: '<S5>/Grabber' */
  /* Chart: '<S5>/Chart1' */
  if (localDW->temporalCounter_i1_l < 1023U) {
    localDW->temporalCounter_i1_l++;
  }

  if (localDW->is_active_c1_flightControlSystem == 0U) {
    localDW->is_active_c1_flightControlSystem = 1U;
    localDW->is_c1_flightControlSystem = flightControlSystem_IN_Start;
    localDW->temporalCounter_i1_l = 0U;
  } else {
    switch (localDW->is_c1_flightControlSystem) {
     case flightControlSystem_IN_A:
      break;

     default:
      /* case IN_Start: */
      if (localDW->temporalCounter_i1_l >= 1000U) {
        localDW->is_c1_flightControlSystem = flightControlSystem_IN_A;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart1' */

  /* Chart: '<S5>/Chart2' */
  if (localDW->temporalCounter_i1_o < 2047U) {
    localDW->temporalCounter_i1_o++;
  }

  if (localDW->is_active_c2_flightControlSystem == 0U) {
    localDW->is_active_c2_flightControlSystem = 1U;
    localDW->is_c2_flightControlSystem = flightControlSystem_IN_Forward;
    localDW->temporalCounter_i1_o = 0U;
  } else {
    switch (localDW->is_c2_flightControlSystem) {
     case flightControlSystem_IN_Forward:
      if (localDW->temporalCounter_i1_o >= 1400U) {
        localDW->is_c2_flightControlSystem = flightControlSystem_IN_Forward1;
        localDW->temporalCounter_i1_o = 0U;
      }
      break;

     case flightControlSystem_IN_Forward1:
      if (localDW->temporalCounter_i1_o >= 1000U) {
        localDW->is_c2_flightControlSystem = flightControlSystem_IN_Left;
        localDW->temporalCounter_i1_o = 0U;
      }
      break;

     case flightControlSystem_IN_Land_d:
      break;

     case flightControlSystem_IN_Left:
      if (localDW->temporalCounter_i1_o >= 1000U) {
        localDW->is_c2_flightControlSystem = flightControlSystem_IN_Right;
        localDW->temporalCounter_i1_o = 0U;
      }
      break;

     default:
      /* case IN_Right: */
      if (localDW->temporalCounter_i1_o >= 1000U) {
        localDW->is_c2_flightControlSystem = flightControlSystem_IN_Land_d;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart2' */
}

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Outputs for Atomic SubSystem: '<Root>/Flight Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_FlightControlSystem(flightControlSystem_M, &cmd_inport,
    &sensor_inport, motors_outport, &flag_outport,
    &flightControlSystem_B.FlightControlSystem,
    &flightControlSystem_DW.FlightControlSystem,
    &flightControlSystem_P.FlightControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Flight Control System' */

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  flightControlSystem_M->Timing.taskTime0 =
    ((time_T)(++flightControlSystem_M->Timing.clockTick0)) *
    flightControlSystem_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void flightControlSystem_step1(void)   /* Sample time: [0.2s, 0.0s] */
{
  int32_T idx;
  int32_T loop;
  int32_T m;
  int32_T mm;
  int32_T n;
  int32_T nnPadRows;
  uint32_T centerIdx;
  uint32_T padIdx;
  uint32_T walkerIdx;
  uint16_T rtCP_ColorSpaceConversion_COEFF_RTP_0;
  uint16_T rtCP_ColorSpaceConversion_COEFF_RTP_1;
  uint16_T rtCP_ColorSpaceConversion_COEFF_RTP_2;
  uint16_T rtCP_ColorSpaceConversion_COEFF_RTP_3;
  uint16_T rtCP_ColorSpaceConversion_COEFF_RTP_4;
  uint16_T rtCP_ColorSpaceConversion_COEFF_RTP_5;
  uint16_T rtCP_ColorSpaceConversion_COEFF_RTP_6;
  uint8_T currentLabel;
  uint8_T rtb_Y1UY2VtoYUV_o2_0;
  boolean_T maxNumBlobsReached;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* ModelReference: '<S2>/Y1UY2V to YUV' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  conversionYUV(&imRGB[0], &flightControlSystem_B.Y1UY2VtoYUV_o1[0],
                &flightControlSystem_B.Y1UY2VtoYUV_o2[0],
                &flightControlSystem_B.Sum[0],
                &(flightControlSystem_DW.Y1UY2VtoYUV_InstanceData.rtb));

  /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion' incorporates:
   *  ModelReference: '<S2>/Y1UY2V to YUV'
   *  Sum: '<S2>/Sum'
   */
  /* Precompute constants */
  padIdx = ((uint16_T)26149U) * 128U;
  centerIdx = (((uint16_T)6419U) * 128U + ((uint16_T)13320U) * 128U) + 8192U;
  walkerIdx = ((uint16_T)33050U) * 128U;
  rtCP_ColorSpaceConversion_COEFF_RTP_0 = ((uint16_T)19077U);
  rtCP_ColorSpaceConversion_COEFF_RTP_1 = ((uint16_T)26149U);
  rtCP_ColorSpaceConversion_COEFF_RTP_2 = ((uint16_T)19077U);
  rtCP_ColorSpaceConversion_COEFF_RTP_3 = ((uint16_T)6419U);
  rtCP_ColorSpaceConversion_COEFF_RTP_4 = ((uint16_T)13320U);
  rtCP_ColorSpaceConversion_COEFF_RTP_5 = ((uint16_T)19077U);
  rtCP_ColorSpaceConversion_COEFF_RTP_6 = ((uint16_T)33050U);
  for (loop = 0; loop < 19200; loop++) {
    /* Convert YcbCr to RGB; apply coefficients and offsets */
    /* derived from the ITU BT.601-5 recommendation; all of the */
    /* coefficients and offsets are scaled (by 2^14) such that */
    /* the conversion can be done using integer arithmetic; this */
    /* routine relies on the user supplying the data in proper */
    /* ranges: Y [16..235], Cb & Cr [16..240] */
    /* Note that all of the operations are grouped in such a way */
    /* that the arithmetic can be done using unsigned integers */
    /* Given that Y is in the proper range, yDiff should */
    /* always be positive */
    flightControlSystem_B.yDiff = flightControlSystem_B.Y1UY2VtoYUV_o1[loop] -
      16U;

    /* Red; 8192 in this equations is 0.5*2^14 or 2^13; adding 0.5  */
    /* before truncation will result in rounding */
    currentLabel = flightControlSystem_B.Sum[loop];
    flightControlSystem_B.pos = (flightControlSystem_B.yDiff *
      rtCP_ColorSpaceConversion_COEFF_RTP_0 + (uint32_T)currentLabel *
      rtCP_ColorSpaceConversion_COEFF_RTP_1) + 8192U;
    if (flightControlSystem_B.pos > padIdx) {
      flightControlSystem_B.pos -= padIdx;
    } else {
      flightControlSystem_B.pos = 0U;
    }

    flightControlSystem_B.cc1 = flightControlSystem_B.pos >> 14;

    /* limit to avoid wrapping */
    if (flightControlSystem_B.cc1 > 255U) {
      flightControlSystem_B.cc1 = 255U;
    }

    /* Compute green channel */
    flightControlSystem_B.pos = flightControlSystem_B.yDiff *
      rtCP_ColorSpaceConversion_COEFF_RTP_2 + centerIdx;
    rtb_Y1UY2VtoYUV_o2_0 = flightControlSystem_B.Y1UY2VtoYUV_o2[loop];
    flightControlSystem_B.neg = (uint32_T)rtb_Y1UY2VtoYUV_o2_0 *
      rtCP_ColorSpaceConversion_COEFF_RTP_3 + (uint32_T)currentLabel *
      rtCP_ColorSpaceConversion_COEFF_RTP_4;

    /* scale back */
    if (flightControlSystem_B.pos > flightControlSystem_B.neg) {
      flightControlSystem_B.pos -= flightControlSystem_B.neg;
    } else {
      flightControlSystem_B.pos = 0U;
    }

    flightControlSystem_B.neg = flightControlSystem_B.pos >> 14;
    if (flightControlSystem_B.neg > 255U) {
      flightControlSystem_B.neg = 255U;
    }

    /* Compute blue channel */
    flightControlSystem_B.pos = (flightControlSystem_B.yDiff *
      rtCP_ColorSpaceConversion_COEFF_RTP_5 + (uint32_T)rtb_Y1UY2VtoYUV_o2_0 *
      rtCP_ColorSpaceConversion_COEFF_RTP_6) + 8192U;

    /* scale back */
    if (flightControlSystem_B.pos > walkerIdx) {
      flightControlSystem_B.pos -= walkerIdx;
    } else {
      flightControlSystem_B.pos = 0U;
    }

    flightControlSystem_B.yDiff = flightControlSystem_B.pos >> 14;
    if (flightControlSystem_B.yDiff > 255U) {
      flightControlSystem_B.yDiff = 255U;
    }

    /* Sum: '<S2>/Sum' incorporates:
     *  ModelReference: '<S2>/Y1UY2V to YUV'
     */
    /* assign back the results */
    n = ((uint8_T)flightControlSystem_B.cc1 - (uint8_T)flightControlSystem_B.neg)
      - (uint8_T)flightControlSystem_B.yDiff;
    if (n < 0) {
      n = 0;
    }

    /* RelationalOperator: '<S2>/Relational Operator1' incorporates:
     *  Constant: '<S2>/Constant'
     *  Sum: '<S2>/Sum'
     */
    flightControlSystem_B.RelationalOperator1[loop] = (n >
      flightControlSystem_P.Constant_Value);
  }

  /* End of S-Function (svipcolorconv): '<S2>/Color Space  Conversion' */

  /* S-Function (svipblob): '<S2>/Blob Analysis' incorporates:
   *  RelationalOperator: '<S2>/Relational Operator1'
   */
  maxNumBlobsReached = false;
  memset(&flightControlSystem_DW.BlobAnalysis_PAD_DW[0], 0, 123U * sizeof
         (uint8_T));
  currentLabel = 1U;
  loop = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (m = 0; m < 120; m++) {
      flightControlSystem_DW.BlobAnalysis_PAD_DW[idx] = (uint8_T)
        (flightControlSystem_B.RelationalOperator1[loop] ? 255 : 0);
      loop++;
      idx++;
    }

    flightControlSystem_DW.BlobAnalysis_PAD_DW[idx] = 0U;
    flightControlSystem_DW.BlobAnalysis_PAD_DW[idx + 1] = 0U;
    idx += 2;
  }

  memset(&flightControlSystem_DW.BlobAnalysis_PAD_DW[idx], 0, 121U * sizeof
         (uint8_T));
  idx = 0;
  n = 0;
  while (n < 160) {
    mm = 0;
    nnPadRows = (idx + 1) * 122;
    m = 0;
    while (m < 120) {
      padIdx = (uint32_T)((nnPadRows + mm) + 1);
      if (flightControlSystem_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
        flightControlSystem_DW.BlobAnalysis_PAD_DW[padIdx] = currentLabel;
        flightControlSystem_DW.BlobAnalysis_STACK_DW[0U] = padIdx;
        padIdx = 1U;
        while (padIdx != 0U) {
          padIdx--;
          centerIdx = flightControlSystem_DW.BlobAnalysis_STACK_DW[padIdx];
          for (loop = 0; loop < 8; loop++) {
            walkerIdx = (uint32_T)((int32_T)centerIdx +
              rtCP_BlobAnalysis_WALKER_RTP[loop]);
            if (flightControlSystem_DW.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
              flightControlSystem_DW.BlobAnalysis_PAD_DW[walkerIdx] =
                currentLabel;
              flightControlSystem_DW.BlobAnalysis_STACK_DW[padIdx] = walkerIdx;
              padIdx++;
            }
          }
        }

        if (currentLabel == 50) {
          maxNumBlobsReached = true;
          n = 160;
          m = 120;
        } else {
          currentLabel++;
        }
      }

      mm++;
      m++;
    }

    idx++;
    n++;
  }

  /* Switch: '<S2>/Landing Flag switch' incorporates:
   *  Constant: '<S2>/One'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  S-Function (svipblob): '<S2>/Blob Analysis'
   */
  if ((maxNumBlobsReached ? (int32_T)currentLabel : (int32_T)(uint8_T)
       (currentLabel - 1U)) >= flightControlSystem_P.One_Value) {
    /* Switch: '<S2>/Landing Flag switch' incorporates:
     *  Constant: '<S2>/One1'
     */
    flightControlSystem_B.LandingFlagswitch = flightControlSystem_P.One1_Value;
  } else {
    /* Switch: '<S2>/Landing Flag switch' incorporates:
     *  Constant: '<S2>/One2'
     */
    flightControlSystem_B.LandingFlagswitch = flightControlSystem_P.One2_Value;
  }

  /* End of Switch: '<S2>/Landing Flag switch' */
  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(flightControlSystem_M, 30.0);
  flightControlSystem_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    flightControlSystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightControlSystem_M->rtwLogInfo, "tout");
    rtliSetLogX(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightControlSystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightControlSystem_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(flightControlSystem_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightControlSystem_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightControlSystem_Y.Actuators[0],
        &flightControlSystem_Y.Flag
      };

      rtliSetLogYSignalPtrs(flightControlSystem_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE,
        SS_UINT8
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "motors",
        "flag" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightControlSystem/Actuators",
        "flightControlSystem/Flag" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(flightControlSystem_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(flightControlSystem_M->rtwLogInfo, "yout");
  }

  /* Model Initialize function for ModelReference Block: '<S1>/controller' */
  flightController_g_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Model Initialize function for ModelReference Block: '<S1>/estimator' */
  stateEstimator_o_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Model Initialize function for ModelReference Block: '<S2>/Y1UY2V to YUV' */
  conversionYUV_initialize(rtmGetErrorStatusPointer(flightControlSystem_M),
    &(flightControlSystem_DW.Y1UY2VtoYUV_InstanceData.rtm));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));

  /* SystemInitialize for Atomic SubSystem: '<Root>/Flight Control System' */

  /* SystemInitialize for Inport: '<Root>/Sensors' */
  flightControlSystem_FlightControlSystem_Init(flightControlSystem_M,
    &flag_outport, &flightControlSystem_DW.FlightControlSystem,
    &flightControlSystem_P.FlightControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Flight Control System' */
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
