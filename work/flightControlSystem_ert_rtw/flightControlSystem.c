/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControlSystem.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 8.51
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Nov 13 17:46:32 2024
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
#include "mean_0sSgOgPG.h"
#include "rt_nonfinite.h"
#include "flightControlSystem_dt.h"
#define flightController_MDLREF_HIDE_CHILD_
#include "flightController.h"
#define stateEstimator_MDLREF_HIDE_CHILD_
#include "stateEstimator.h"

/* Named constants for Chart: '<S5>/Chart' */
#define flightControlSystem_IN_A3      (1U)
#define flightControlSystem_IN_A4      (2U)
#define flightControlSystem_IN_CloseGrabber (1U)
#define flightControlSystem_IN_FollowPath (2U)
#define flightControlSystem_IN_Hover   (3U)
#define flightControlSystem_IN_Land    (4U)
#define flightControlSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flightControlSystem_IN_Takeoff (5U)

/* Named constants for Chart: '<S5>/Chart1' */
#define flightControlSystem_IN_A       (1U)
#define flightControlSystem_IN_Start   (2U)

/* Named constants for Chart: '<S5>/Chart2' */
#define flightControlSystem_IN_Forward (1U)
#define flightControlSystem_IN_Forward1 (2U)
#define flightControlSystem_IN_Land_d  (3U)
#define flightControlSystem_IN_Left    (4U)
#define flightControlSystem_IN_Right   (5U)

/* Named constants for Chart: '<S5>/Chart3' */
#define flightControlSystem_IN_Left_f  (3U)

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

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->X = rtu_states_estim_Inport_3->X;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->Y = rtu_states_estim_Inport_3->Y;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->Z = rtu_states_estim_Inport_3->Z;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->yaw = rtu_states_estim_Inport_3->yaw;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->pitch = rtu_states_estim_Inport_3->pitch;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->roll = rtu_states_estim_Inport_3->roll;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->dx = rtu_states_estim_Inport_3->dx;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->dy = rtu_states_estim_Inport_3->dy;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->dz = rtu_states_estim_Inport_3->dz;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->p = rtu_states_estim_Inport_3->p;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->q = rtu_states_estim_Inport_3->q;

  /* SignalConversion generated from: '<S4>/states_estim_BusSelector' */
  localB->r = rtu_states_estim_Inport_3->r;

  /* SignalConversion generated from: '<S4>/To Workspace2' */
  localB->TmpSignalConversionAtToWorkspace2Inport1[0] = localB->X;
  localB->TmpSignalConversionAtToWorkspace2Inport1[1] = localB->Y;
  localB->TmpSignalConversionAtToWorkspace2Inport1[2] = localB->Z;
  localB->TmpSignalConversionAtToWorkspace2Inport1[3] = localB->yaw;
  localB->TmpSignalConversionAtToWorkspace2Inport1[4] = localB->pitch;
  localB->TmpSignalConversionAtToWorkspace2Inport1[5] = localB->roll;
  localB->TmpSignalConversionAtToWorkspace2Inport1[6] = localB->dx;
  localB->TmpSignalConversionAtToWorkspace2Inport1[7] = localB->dy;
  localB->TmpSignalConversionAtToWorkspace2Inport1[8] = localB->dz;
  localB->TmpSignalConversionAtToWorkspace2Inport1[9] = localB->p;
  localB->TmpSignalConversionAtToWorkspace2Inport1[10] = localB->q;
  localB->TmpSignalConversionAtToWorkspace2Inport1[11] = localB->r;

  /* ToWorkspace: '<S4>/To Workspace2' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace2_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace2Inport1[0]);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  localB->DataTypeConversion1 = rtu_sensordata_datin_Inport_6;

  /* DataTypeConversion: '<S4>/Data Type Conversion2' */
  localB->DataTypeConversion2 = (real32_T)rtu_sensordata_datin_Inport_6_d;

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
  localB->TmpSignalConversionAtToWorkspace6Inport1[8] =
    localB->DataTypeConversion1;
  localB->TmpSignalConversionAtToWorkspace6Inport1[9] =
    localB->DataTypeConversion2;

  /* ToWorkspace: '<S4>/To Workspace6' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace6_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace6Inport1[0]);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion3' */
  localB->DataTypeConversion3 =
    rtu_ReferenceValueServerBus_Inport_4->controlModePosVSOrient;

  /* SignalConversion generated from: '<S4>/ReferenceValueServerBus_BusSelector' */
  localB->pos_ref[0] = rtu_ReferenceValueServerBus_Inport_4->pos_ref[0];
  localB->pos_ref[1] = rtu_ReferenceValueServerBus_Inport_4->pos_ref[1];
  localB->pos_ref[2] = rtu_ReferenceValueServerBus_Inport_4->pos_ref[2];

  /* DataTypeConversion: '<S4>/Data Type Conversion7' */
  localB->DataTypeConversion7 =
    rtu_ReferenceValueServerBus_Inport_4->takeoff_flag;

  /* SignalConversion generated from: '<S4>/ReferenceValueServerBus_BusSelector' */
  localB->orient_ref[0] = rtu_ReferenceValueServerBus_Inport_4->orient_ref[0];
  localB->orient_ref[1] = rtu_ReferenceValueServerBus_Inport_4->orient_ref[1];
  localB->orient_ref[2] = rtu_ReferenceValueServerBus_Inport_4->orient_ref[2];

  /* DataTypeConversion: '<S4>/Data Type Conversion9' */
  localB->DataTypeConversion9 = (real32_T)
    rtu_ReferenceValueServerBus_Inport_4->live_time_ticks;

  /* SignalConversion generated from: '<S4>/To Workspace3' */
  localB->TmpSignalConversionAtToWorkspace3Inport1[0] =
    localB->DataTypeConversion3;
  localB->TmpSignalConversionAtToWorkspace3Inport1[1] = localB->pos_ref[0];
  localB->TmpSignalConversionAtToWorkspace3Inport1[2] = localB->pos_ref[1];
  localB->TmpSignalConversionAtToWorkspace3Inport1[3] = localB->pos_ref[2];
  localB->TmpSignalConversionAtToWorkspace3Inport1[4] =
    localB->DataTypeConversion7;
  localB->TmpSignalConversionAtToWorkspace3Inport1[5] = localB->orient_ref[0];
  localB->TmpSignalConversionAtToWorkspace3Inport1[6] = localB->orient_ref[1];
  localB->TmpSignalConversionAtToWorkspace3Inport1[7] = localB->orient_ref[2];
  localB->TmpSignalConversionAtToWorkspace3Inport1[8] =
    localB->DataTypeConversion9;

  /* ToWorkspace: '<S4>/To Workspace3' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace3_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace3Inport1[0]);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion11' */
  localB->DataTypeConversion11 =
    rtu_Sensors_Inport_5->VisionSensors.usePosVIS_flag;

  /* SignalConversion generated from: '<S4>/Sensors_BusSelector' */
  localB->opticalFlow_data[0] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[0];
  localB->opticalFlow_data[1] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[1];
  localB->opticalFlow_data[2] =
    rtu_Sensors_Inport_5->VisionSensors.opticalFlow_data[2];

  /* SignalConversion generated from: '<S4>/Sensors_BusSelector' */
  localB->posVIS_data[0] = rtu_Sensors_Inport_5->VisionSensors.posVIS_data[0];
  localB->posVIS_data[1] = rtu_Sensors_Inport_5->VisionSensors.posVIS_data[1];
  localB->posVIS_data[2] = rtu_Sensors_Inport_5->VisionSensors.posVIS_data[2];
  localB->posVIS_data[3] = rtu_Sensors_Inport_5->VisionSensors.posVIS_data[3];

  /* SignalConversion generated from: '<S4>/To Workspace4' */
  localB->TmpSignalConversionAtToWorkspace4Inport1[0] =
    localB->DataTypeConversion11;
  localB->TmpSignalConversionAtToWorkspace4Inport1[1] = localB->
    opticalFlow_data[0];
  localB->TmpSignalConversionAtToWorkspace4Inport1[2] = localB->
    opticalFlow_data[1];
  localB->TmpSignalConversionAtToWorkspace4Inport1[3] = localB->
    opticalFlow_data[2];
  localB->TmpSignalConversionAtToWorkspace4Inport1[4] = localB->posVIS_data[0];
  localB->TmpSignalConversionAtToWorkspace4Inport1[5] = localB->posVIS_data[1];
  localB->TmpSignalConversionAtToWorkspace4Inport1[6] = localB->posVIS_data[2];
  localB->TmpSignalConversionAtToWorkspace4Inport1[7] = localB->posVIS_data[3];

  /* ToWorkspace: '<S4>/To Workspace4' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace4_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspace4Inport1[0]);
  }

  for (i = 0; i < 8; i++) {
    /* SignalConversion generated from: '<S4>/Sensors_BusSelector' */
    localB->SensorCalibration[i] = rtu_Sensors_Inport_5->SensorCalibration[i];
  }

  /* ToWorkspace: '<S4>/To Workspace5' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0
      ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace5_PWORK.LoggedData,
                          &locTime, &localB->SensorCalibration[0]);
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
  const SensorsBus *rtu_Sensors_Inport_2, real_T rtu_VisionbasedData, real_T
  rtu_VisionbasedData_p, real32_T rty_motorCmds[4], uint8_T *rty_Flag,
  B_FlightControlSystem_flightControlSystem_T *localB,
  DW_FlightControlSystem_flightControlSystem_T *localDW,
  P_FlightControlSystem_flightControlSystem_T *localP)
{
  /* Chart: '<S5>/Chart' */
  if (localDW->temporalCounter_i1_g < 4095U) {
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
      if (localDW->temporalCounter_i1_g >= 4000U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Land;
        localB->z_g = -0.4;
      } else {
        localB->x_g -= rtu_VisionbasedData / 50000.0;
        localB->y_b += rtu_VisionbasedData_p / 50000.0;
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
  localB->x_c = rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.x;

  /* SignalConversion generated from: '<S6>/Bus Selector3' */
  localB->y_n = rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.y;

  /* SignalConversion generated from: '<S6>/Bus Selector3' */
  localB->z_p = rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.z;

  /* SignalConversion generated from: '<S6>/Bus Selector4' */
  localB->x_cd = rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.x;

  /* SignalConversion generated from: '<S6>/Bus Selector4' */
  localB->y_nb = rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.y;

  /* SignalConversion generated from: '<S6>/Bus Selector4' */
  localB->z_p1 = rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.z;

  /* SignalConversion generated from: '<S6>/Bus Selector5' */
  localB->altitude = rtu_Sensors_Inport_2->HALSensors.HAL_ultrasound_SI.altitude;

  /* SignalConversion generated from: '<S6>/Bus Selector6' */
  localB->pressure = rtu_Sensors_Inport_2->HALSensors.HAL_pressure_SI.pressure;

  /* SignalConversion generated from: '<S6>/Bus Selector1' */
  localB->rtb_vbat_V_m = rtu_Sensors_Inport_2->HALSensors.HAL_vbat_SI.vbat_V;

  /* SignalConversion generated from: '<S6>/Bus Selector1' */
  localB->rtb_vbat_percentage_c =
    rtu_Sensors_Inport_2->HALSensors.HAL_vbat_SI.vbat_percentage;

  /* BusCreator generated from: '<S1>/estimator' */
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddx =
    localB->x_c;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddy =
    localB->y_n;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddz =
    localB->z_p;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.p =
    localB->x_cd;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.q =
    localB->y_nb;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.r =
    localB->z_p1;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.altitude_sonar
    = localB->altitude;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.prs =
    localB->pressure;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_V =
    localB->rtb_vbat_V_m;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_percentage
    = localB->rtb_vbat_percentage_c;

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
    rtu_Sensors_Inport_2, localB->rtb_vbat_V_m, localB->rtb_vbat_percentage_c,
    localB->x_c, localB->y_n, localB->z_p, localB->x_cd, localB->y_nb,
    localB->z_p1, localB->altitude, localB->pressure, &localB->Logging,
    &localDW->Logging);

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
  localB->d = rt_roundd_snf(localB->grabber_c);
  if (localB->d < 256.0) {
    if (localB->d >= 0.0) {
      localB->u = (uint8_T)localB->d;
    } else {
      localB->u = 0U;
    }
  } else {
    localB->u = MAX_uint8_T;
  }

  localB->d = MW_PARROT_Grabber(localB->u);

  /* MATLABSystem: '<S5>/Grabber' */
  localB->Grabber = localB->d;

  /* Chart: '<S5>/Chart1' */
  if (localDW->temporalCounter_i1_p < 1023U) {
    localDW->temporalCounter_i1_p++;
  }

  if (localDW->is_active_c1_flightControlSystem == 0U) {
    localDW->is_active_c1_flightControlSystem = 1U;
    localDW->is_c1_flightControlSystem = flightControlSystem_IN_Start;
    localDW->temporalCounter_i1_p = 0U;
  } else {
    switch (localDW->is_c1_flightControlSystem) {
     case flightControlSystem_IN_A:
      break;

     default:
      /* case IN_Start: */
      if (localDW->temporalCounter_i1_p >= 1000U) {
        localDW->is_c1_flightControlSystem = flightControlSystem_IN_A;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart1' */

  /* Chart: '<S5>/Chart2' */
  if (localDW->temporalCounter_i1_d < 2047U) {
    localDW->temporalCounter_i1_d++;
  }

  if (localDW->is_active_c2_flightControlSystem == 0U) {
    localDW->is_active_c2_flightControlSystem = 1U;
    localDW->is_c2_flightControlSystem = flightControlSystem_IN_Forward;
    localDW->temporalCounter_i1_d = 0U;
  } else {
    switch (localDW->is_c2_flightControlSystem) {
     case flightControlSystem_IN_Forward:
      if (localDW->temporalCounter_i1_d >= 1400U) {
        localDW->is_c2_flightControlSystem = flightControlSystem_IN_Forward1;
        localDW->temporalCounter_i1_d = 0U;
      }
      break;

     case flightControlSystem_IN_Forward1:
      if (localDW->temporalCounter_i1_d >= 1000U) {
        localDW->is_c2_flightControlSystem = flightControlSystem_IN_Left;
        localDW->temporalCounter_i1_d = 0U;
      }
      break;

     case flightControlSystem_IN_Land_d:
      break;

     case flightControlSystem_IN_Left:
      if (localDW->temporalCounter_i1_d >= 1000U) {
        localDW->is_c2_flightControlSystem = flightControlSystem_IN_Right;
        localDW->temporalCounter_i1_d = 0U;
      }
      break;

     default:
      /* case IN_Right: */
      if (localDW->temporalCounter_i1_d >= 1000U) {
        localDW->is_c2_flightControlSystem = flightControlSystem_IN_Land_d;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart2' */

  /* Chart: '<S5>/Chart3' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c4_flightControlSystem == 0U) {
    localDW->is_active_c4_flightControlSystem = 1U;
    localDW->is_c4_flightControlSystem = flightControlSystem_IN_Forward;
    localDW->temporalCounter_i1 = 0U;
  } else {
    switch (localDW->is_c4_flightControlSystem) {
     case flightControlSystem_IN_Forward:
      if (localDW->temporalCounter_i1 >= 1000U) {
        localDW->is_c4_flightControlSystem = flightControlSystem_IN_Forward1;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case flightControlSystem_IN_Forward1:
      if (localDW->temporalCounter_i1 >= 1000U) {
        localDW->is_c4_flightControlSystem = flightControlSystem_IN_Left_f;
      }
      break;

     default:
      /* case IN_Left: */
      break;
    }
  }

  /* End of Chart: '<S5>/Chart3' */
}

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.FlightControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC);

  /* RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_B.dy =
    flightControlSystem_DW.RateTransition_1_Buffer[flightControlSystem_DW.RateTransition_1_ActiveBufIdx];

  /* RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_B.dx =
    flightControlSystem_DW.RateTransition_2_Buffer[flightControlSystem_DW.RateTransition_2_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<Root>/Flight Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_FlightControlSystem(flightControlSystem_M, &cmd_inport,
    &sensor_inport, flightControlSystem_B.dx, flightControlSystem_B.dy,
    motors_outport, &flag_outport, &flightControlSystem_B.FlightControlSystem,
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

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)flightControlSystem_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }

    if (rtmGetStopRequested(flightControlSystem_M)) {
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
  int32_T colIdx;
  int32_T colIdx_size;
  int32_T loop;
  int32_T rowIdx_size;
  int32_T yIdx;
  boolean_T exitg1;
  boolean_T guard1;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  MW_Build_RGB(&imRGB[0], &flightControlSystem_B.imageBuff_1[0],
               &flightControlSystem_B.imageBuff_2[0],
               &flightControlSystem_B.imageBuff_3[0]);

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  MATLABSystem: '<S2>/PARROT Image Conversion'
   */
  for (colIdx = 0; colIdx < 19200; colIdx++) {
    flightControlSystem_B.BW[colIdx] =
      ((flightControlSystem_B.imageBuff_1[colIdx] >= 80) &&
       (flightControlSystem_B.imageBuff_2[colIdx] <= 100) &&
       (flightControlSystem_B.imageBuff_3[colIdx] <= 80));
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* S-Function (sdspsubmtrx): '<S2>/Submatrix' */
  yIdx = 0;
  for (colIdx = 0; colIdx < 160; colIdx++) {
    memcpy(&flightControlSystem_B.Submatrix[yIdx],
           &flightControlSystem_B.BW[colIdx * 120], 120U * sizeof(boolean_T));
    yIdx += 120;
  }

  /* End of S-Function (sdspsubmtrx): '<S2>/Submatrix' */

  /* Sum: '<S2>/Matrix Sum2' incorporates:
   *  S-Function (sdspsubmtrx): '<S2>/Submatrix'
   */
  colIdx = 0;
  for (yIdx = 0; yIdx < 19200; yIdx++) {
    colIdx = (int32_T)((uint32_T)colIdx + flightControlSystem_B.Submatrix[yIdx]);
  }

  /* DataTypeConversion: '<S2>/Cast To Double' incorporates:
   *  Sum: '<S2>/Matrix Sum2'
   */
  flightControlSystem_B.CastToDouble = (uint8_T)colIdx;

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   */
  flightControlSystem_B.Compare = (flightControlSystem_B.CastToDouble >=
    flightControlSystem_P.CompareToConstant2_const);

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  yIdx = -1;
  colIdx = 1;
  loop = 1;
  exitg1 = false;
  while ((!exitg1) && (loop <= 160)) {
    guard1 = false;
    if (flightControlSystem_B.BW[((loop - 1) * 120 + colIdx) + 13]) {
      yIdx++;
      flightControlSystem_B.i_data[yIdx] = colIdx;
      flightControlSystem_B.j_data[yIdx] = (uint8_T)loop;
      if (yIdx + 1 >= 4960) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      colIdx++;
      if (colIdx > 31) {
        colIdx = 1;
        loop++;
      }
    }
  }

  if (yIdx + 1 < 1) {
    loop = -1;
  } else {
    loop = yIdx;
  }

  rowIdx_size = loop + 1;
  for (colIdx = 0; colIdx <= loop; colIdx++) {
    flightControlSystem_B.rowIdx_data[colIdx] =
      flightControlSystem_B.i_data[colIdx];
  }

  if (yIdx + 1 < 1) {
    yIdx = -1;
  }

  colIdx_size = yIdx + 1;
  for (colIdx = 0; colIdx <= yIdx; colIdx++) {
    flightControlSystem_B.colIdx_data[colIdx] =
      flightControlSystem_B.j_data[colIdx];
  }

  if ((loop + 1 == 0) || (yIdx + 1 == 0)) {
    flightControlSystem_B.avgX = 80.0;
    flightControlSystem_B.avgY = 60.0;
  } else {
    flightControlSystem_B.avgX = mean_0sSgOgPG(flightControlSystem_B.colIdx_data,
      &colIdx_size);
    flightControlSystem_B.avgY = mean_0sSgOgPG(flightControlSystem_B.rowIdx_data,
      &rowIdx_size);
  }

  flightControlSystem_B.deltaX = flightControlSystem_B.avgX - 80.0;
  flightControlSystem_B.deltaY = flightControlSystem_B.avgY - 60.0;

  /* End of MATLAB Function: '<S2>/MATLAB Function1' */
  /* RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_1_Buffer[flightControlSystem_DW.RateTransition_1_ActiveBufIdx
    == 0] = flightControlSystem_B.deltaX;
  flightControlSystem_DW.RateTransition_1_ActiveBufIdx = (int8_T)
    (flightControlSystem_DW.RateTransition_1_ActiveBufIdx == 0);

  /* RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_2_Buffer[flightControlSystem_DW.RateTransition_2_ActiveBufIdx
    == 0] = flightControlSystem_B.deltaY;
  flightControlSystem_DW.RateTransition_2_ActiveBufIdx = (int8_T)
    (flightControlSystem_DW.RateTransition_2_ActiveBufIdx == 0);
  rtExtModeUpload(1, (real_T)((flightControlSystem_M->Timing.clockTick1) * 0.2));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  flightControlSystem_M->Timing.clockTick1++;
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

  /* External mode info */
  flightControlSystem_M->Sizes.checksums[0] = (1191579305U);
  flightControlSystem_M->Sizes.checksums[1] = (3338200727U);
  flightControlSystem_M->Sizes.checksums[2] = (1210126136U);
  flightControlSystem_M->Sizes.checksums[3] = (858923583U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    flightControlSystem_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.Normalcondition.Geofencingerror_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &flightControlSystem_DW.FlightControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(flightControlSystem_M->extModeInfo,
      &flightControlSystem_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(flightControlSystem_M->extModeInfo,
                        flightControlSystem_M->Sizes.checksums);
    rteiSetTPtr(flightControlSystem_M->extModeInfo, rtmGetTPtr
                (flightControlSystem_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    flightControlSystem_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 49;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Model Initialize function for ModelReference Block: '<S1>/controller' */
  flightController_g_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Model Initialize function for ModelReference Block: '<S1>/estimator' */
  stateEstimator_o_initialize(rtmGetErrorStatusPointer(flightControlSystem_M));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));

  /* InitializeConditions for RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_1_Buffer[0] =
    flightControlSystem_P.RateTransition_1_InitialCondition;

  /* InitializeConditions for RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_2_Buffer[0] =
    flightControlSystem_P.RateTransition_2_InitialCondition;

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
