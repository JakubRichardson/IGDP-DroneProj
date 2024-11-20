/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControlSystem.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 8.177
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Nov 20 09:28:41 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightControlSystem.h"
#include "flightControlSystem_types.h"
#include "rtwtypes.h"
#include "flightControlSystem_private.h"
#include <math.h>
#include "rt_roundd_snf.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "flightControlSystem_dt.h"
#define flightController_MDLREF_HIDE_CHILD_
#include "flightController.h"
#define stateEstimator_MDLREF_HIDE_CHILD_
#include "stateEstimator.h"

/* Named constants for Chart: '<S3>/Chart' */
#define flightControlSystem_IN_A3      (1U)
#define flightControlSystem_IN_A4      (2U)
#define flightControlSystem_IN_CloseGrabber (1U)
#define flightControlSystem_IN_CutPower (2U)
#define flightControlSystem_IN_End     (3U)
#define flightControlSystem_IN_Hover   (4U)
#define flightControlSystem_IN_Land    (5U)
#define flightControlSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flightControlSystem_IN_ReleaseEgg (6U)
#define flightControlSystem_IN_Takeoff (7U)

/* Named constants for Chart: '<S3>/Chart1' */
#define flightControlSystem_IN_A       (1U)
#define flightControlSystem_IN_Start   (2U)

/* Named constants for Chart: '<S3>/Chart2' */
#define flightControlSystem_IN_Forward (1U)
#define flightControlSystem_IN_Forward1 (2U)
#define flightControlSystem_IN_Land_d  (3U)
#define flightControlSystem_IN_Left    (4U)
#define flightControlSystem_IN_Right   (5U)

/* Named constants for Chart: '<S3>/Chart3' */
#define flightControlSystem_IN_Left_f  (3U)

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/controller' */

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

/* Forward declaration for local functions */
static real_T flightControlSystem_mean_0sSgOgPG(const real_T x_data[], const
  int32_T *x_size);
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

/* System initialize for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem_Init
  (DW_FlightControlSystem_flightControlSystem_T *localDW,
   P_FlightControlSystem_flightControlSystem_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition;
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition;
  localDW->UnitDelay_DSTATE[2] = localP->UnitDelay_InitialCondition;

  /* InitializeConditions for Memory: '<S3>/Memory1' */
  localDW->Memory1_PreviousInput = localP->Memory1_InitialCondition;

  /* SystemInitialize for ModelReference: '<S1>/controller' */
  flightController_Init();

  /* SystemInitialize for ModelReference: '<S1>/estimator' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  stateEstimator_Init();
}

/* Output and update for atomic system: '<Root>/Flight Control System' */
void flightControlSystem_FlightControlSystem(const CommandBus
  *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors_Inport_2,
  real32_T rty_motorCmds[4], B_FlightControlSystem_flightControlSystem_T *localB,
  DW_FlightControlSystem_flightControlSystem_T *localDW,
  P_FlightControlSystem_flightControlSystem_T *localP)
{
  /* S-Function (sdspdmult2): '<S3>/Array-Vector Subtract' incorporates:
   *  Memory: '<S3>/Memory1'
   */
  localDW->UnitDelay_DSTATE[0] -= localDW->Memory1_PreviousInput.X;
  localDW->UnitDelay_DSTATE[1] -= localDW->Memory1_PreviousInput.Y;
  localDW->UnitDelay_DSTATE[2] -= localDW->Memory1_PreviousInput.Z;

  /* Abs: '<S3>/Abs' incorporates:
   *  S-Function (sdspdmult2): '<S3>/Array-Vector Subtract'
   */
  localB->Abs[0] = (real32_T)fabs(localDW->UnitDelay_DSTATE[0]);
  localB->Abs[1] = (real32_T)fabs(localDW->UnitDelay_DSTATE[1]);
  localB->Abs[2] = (real32_T)fabs(localDW->UnitDelay_DSTATE[2]);

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  localB->Compare = (localB->Abs[0] <= localP->CompareToConstant_const);

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  localB->Compare_d = (localB->Abs[1] <= localP->CompareToConstant1_const);

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  localB->Compare_dd = (localB->Abs[2] <= localP->CompareToConstant2_const);

  /* Logic: '<S3>/AND1' */
  localB->stable = (localB->Compare && localB->Compare_d && localB->Compare_dd);

  /* Chart: '<S3>/Chart' */
  if (localDW->temporalCounter_i1_pu < 1023U) {
    localDW->temporalCounter_i1_pu++;
  }

  if (localDW->temporalCounter_i2 < 511U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->is_active_c3_flightControlSystem == 0U) {
    localDW->is_active_c3_flightControlSystem = 1U;
    localB->x_g = 0.0F;
    localB->y_b = 0.0F;
    localB->z_g = -1.0F;
    localB->takeoff_flag = 0.0;
    localB->landing_flag = 0.0;
    localDW->is_c3_flightControlSystem = flightControlSystem_IN_CloseGrabber;
    localDW->temporalCounter_i1_pu = 0U;
    localB->grabber_c = 1.0;
  } else {
    switch (localDW->is_c3_flightControlSystem) {
     case flightControlSystem_IN_CloseGrabber:
      if (localDW->temporalCounter_i1_pu >= 200U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Takeoff;
        localDW->temporalCounter_i2 = 0U;
        localDW->is_Takeoff = flightControlSystem_IN_A3;
        localDW->temporalCounter_i1_pu = 0U;
        localB->takeoff_flag = 1.0;
      }
      break;

     case flightControlSystem_IN_CutPower:
      if (localDW->temporalCounter_i1_pu >= 400U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_ReleaseEgg;
        localDW->temporalCounter_i1_pu = 0U;
        localB->grabber_c = 0.0;
      }
      break;

     case flightControlSystem_IN_End:
      break;

     case flightControlSystem_IN_Hover:
      if (localDW->temporalCounter_i1_pu >= 1000U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Land;
      }
      break;

     case flightControlSystem_IN_Land:
      if (localB->z_g >= -0.7) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_CutPower;
        localDW->temporalCounter_i1_pu = 0U;
        localB->landing_flag = 1.0;
      } else {
        localB->z_g += 0.0005F;
      }
      break;

     case flightControlSystem_IN_ReleaseEgg:
      if (localDW->temporalCounter_i1_pu >= 800U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_End;
      }
      break;

     default:
      /* case IN_Takeoff: */
      if (localDW->temporalCounter_i2 >= 400U) {
        localDW->is_Takeoff = flightControlSystem_IN_NO_ACTIVE_CHILD;
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Hover;
        localDW->temporalCounter_i1_pu = 0U;
        localB->z_g = -1.0F;
      } else if ((localDW->is_Takeoff == flightControlSystem_IN_A3) &&
                 (localDW->temporalCounter_i1_pu >= 160U)) {
        localDW->is_Takeoff = flightControlSystem_IN_A4;
        localB->takeoff_flag = 0.0;
      } else {
        /* case IN_A4: */
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* BusCreator generated from: '<S1>/controller' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant3'
   *  DataTypeConversion: '<S3>/Cast To Boolean'
   *  DataTypeConversion: '<S3>/Cast To Boolean1'
   *  DataTypeConversion: '<S3>/Cast To Single'
   */
  localB->BusConversion_InsertedFor_controller_at_inport_0_BusCreator.controlModePosVSOrient
    = localP->Constant1_Value;
  localB->BusConversion_InsertedFor_controller_at_inport_0_BusCreator.pos_ref[0]
    = localB->x_g;
  localB->BusConversion_InsertedFor_controller_at_inport_0_BusCreator.pos_ref[1]
    = localB->y_b;
  localB->BusConversion_InsertedFor_controller_at_inport_0_BusCreator.pos_ref[2]
    = localB->z_g;
  localB->BusConversion_InsertedFor_controller_at_inport_0_BusCreator.takeoff_flag
    = (localB->takeoff_flag != 0.0);
  localB->
    BusConversion_InsertedFor_controller_at_inport_0_BusCreator.orient_ref[0] =
    localP->Constant3_Value[0];
  localB->
    BusConversion_InsertedFor_controller_at_inport_0_BusCreator.orient_ref[1] =
    localP->Constant3_Value[1];
  localB->
    BusConversion_InsertedFor_controller_at_inport_0_BusCreator.orient_ref[2] =
    localP->Constant3_Value[2];
  localB->BusConversion_InsertedFor_controller_at_inport_0_BusCreator.live_time_ticks
    = rtu_ReferenceValueServerCmds->live_time_ticks;
  localB->BusConversion_InsertedFor_controller_at_inport_0_BusCreator.landing_flag
    = (localB->landing_flag != 0.0);

  /* BusCreator generated from: '<S1>/estimator' */
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddx =
    rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.x;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddy =
    rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.y;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddz =
    rtu_Sensors_Inport_2->HALSensors.HAL_acc_SI.z;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.p =
    rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.x;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.q =
    rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.y;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.r =
    rtu_Sensors_Inport_2->HALSensors.HAL_gyro_SI.z;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.altitude_sonar
    = rtu_Sensors_Inport_2->HALSensors.HAL_ultrasound_SI.altitude;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.prs =
    rtu_Sensors_Inport_2->HALSensors.HAL_pressure_SI.pressure;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_V =
    rtu_Sensors_Inport_2->HALSensors.HAL_vbat_SI.vbat_V;
  localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_percentage
    = rtu_Sensors_Inport_2->HALSensors.HAL_vbat_SI.vbat_percentage;

  /* ModelReference: '<S1>/estimator' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  stateEstimator_run(localP->Constant1_Value,
                     &localB->BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1,
                     rtu_Sensors_Inport_2->VisionSensors.usePosVIS_flag,
                     &rtu_Sensors_Inport_2->VisionSensors.opticalFlow_data[0],
                     &rtu_Sensors_Inport_2->VisionSensors.posVIS_data[0],
                     &localB->estimator,
                     &rtu_Sensors_Inport_2->SensorCalibration[0]);

  /* ModelReference: '<S1>/controller' */
  flightController_run
    (&localB->BusConversion_InsertedFor_controller_at_inport_0_BusCreator,
     &localB->estimator, &rty_motorCmds[0], &localB->controller_o2[0]);

  /* MATLABSystem: '<S3>/Grabber' */
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

  /* MATLABSystem: '<S3>/Grabber' */
  localB->Grabber = localB->d;

  /* Chart: '<S3>/Chart1' */
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

  /* End of Chart: '<S3>/Chart1' */

  /* Chart: '<S3>/Chart2' */
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

  /* End of Chart: '<S3>/Chart2' */

  /* Chart: '<S3>/Chart3' */
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

  /* End of Chart: '<S3>/Chart3' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = localB->x_g;
  localDW->UnitDelay_DSTATE[1] = localB->y_b;
  localDW->UnitDelay_DSTATE[2] = localB->z_g;

  /* Update for Memory: '<S3>/Memory1' */
  localDW->Memory1_PreviousInput = localB->estimator;
}

/* Function for MATLAB Function: '<S2>/MATLAB Function1' */
static real_T flightControlSystem_mean_0sSgOgPG(const real_T x_data[], const
  int32_T *x_size)
{
  real_T bsum;
  int32_T b_k;
  int32_T firstBlockLength;
  int32_T hi;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T xblockoffset;
  if (*x_size <= 1024) {
    firstBlockLength = *x_size;
    lastBlockLength = 0;
    nblocks = 1;
  } else {
    firstBlockLength = 1024;
    nblocks = (int32_T)((uint32_T)*x_size >> 10);
    lastBlockLength = *x_size - (nblocks << 10);
    if (lastBlockLength > 0) {
      nblocks++;
    } else {
      lastBlockLength = 1024;
    }
  }

  flightControlSystem_B.b_y = x_data[0];
  for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
    flightControlSystem_B.b_y += x_data[xblockoffset - 1];
  }

  for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++) {
    xblockoffset = (firstBlockLength - 1) << 10;
    bsum = x_data[xblockoffset];
    if (firstBlockLength == nblocks) {
      hi = lastBlockLength;
    } else {
      hi = 1024;
    }

    for (b_k = 2; b_k <= hi; b_k++) {
      bsum += x_data[(xblockoffset + b_k) - 1];
    }

    flightControlSystem_B.b_y += bsum;
  }

  return flightControlSystem_B.b_y / (real_T)*x_size;
}

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_B.dy =
    flightControlSystem_DW.RateTransition_1_Buffer[flightControlSystem_DW.RateTransition_1_ActiveBufIdx];

  /* RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_B.dx =
    flightControlSystem_DW.RateTransition_2_Buffer[flightControlSystem_DW.RateTransition_2_ActiveBufIdx];

  /* RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_B.circle = flightControlSystem_DW.RateTransition_3_Buffer0;

  /* Outputs for Atomic SubSystem: '<Root>/Flight Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_FlightControlSystem(&cmd_inport, &sensor_inport,
    motors_outport, &flightControlSystem_B.FlightControlSystem,
    &flightControlSystem_DW.FlightControlSystem,
    &flightControlSystem_P.FlightControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Flight Control System' */

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

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
  int32_T Submatrix_tmp;
  int32_T colIdx;
  int32_T colIdx_size;
  int32_T loop;
  int32_T yIdx;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T y;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  MW_Build_RGB(&imRGB[0], &flightControlSystem_B.imageBuff_1[0],
               &flightControlSystem_B.imageBuff_2[0],
               &flightControlSystem_B.imageBuff_3[0]);
  for (yIdx = 0; yIdx < 19200; yIdx++) {
    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  MATLABSystem: '<S2>/PARROT Image Conversion'
     */
    y = ((flightControlSystem_B.imageBuff_1[yIdx] >= 80) &&
         (flightControlSystem_B.imageBuff_2[yIdx] <= 100) &&
         (flightControlSystem_B.imageBuff_3[yIdx] <= 80));
    flightControlSystem_B.y[yIdx] = y;

    /* MATLAB Function: '<S2>/MATLAB Function3' */
    flightControlSystem_B.y_m[yIdx] = y;
  }

  /* MATLAB Function: '<S2>/MATLAB Function3' */
  memset(&flightControlSystem_B.y_m[0], 0, 4320U * sizeof(boolean_T));
  memset(&flightControlSystem_B.y_m[16680], 0, 2520U * sizeof(boolean_T));

  /* MATLAB Function: '<S2>/MATLAB Function2' */
  memset(&flightControlSystem_B.y[0], 0, 4320U * sizeof(boolean_T));

  /* S-Function (sdspsubmtrx): '<S2>/Submatrix' */
  yIdx = 0;
  for (colIdx = 0; colIdx < 30; colIdx++) {
    /* S-Function (sdspsubmtrx): '<S2>/Submatrix1' incorporates:
     *  S-Function (sdspsubmtrx): '<S2>/Submatrix'
     */
    for (loop = 0; loop < 30; loop++) {
      Submatrix_tmp = loop + yIdx;
      flightControlSystem_B.Submatrix[Submatrix_tmp] = flightControlSystem_B.y
        [((colIdx + 40) * 120 + loop) + 50];
      flightControlSystem_B.Submatrix1[Submatrix_tmp] = flightControlSystem_B.y
        [((colIdx + 90) * 120 + loop) + 50];
    }

    /* End of S-Function (sdspsubmtrx): '<S2>/Submatrix1' */
    yIdx += 30;
  }

  /* End of S-Function (sdspsubmtrx): '<S2>/Submatrix' */

  /* Sum: '<S2>/Matrix Sum' incorporates:
   *  S-Function (sdspsubmtrx): '<S2>/Submatrix1'
   */
  colIdx = 0;
  for (yIdx = 0; yIdx < 900; yIdx++) {
    colIdx = (int32_T)((uint32_T)colIdx + flightControlSystem_B.Submatrix1[yIdx]);
  }

  /* Sum: '<S2>/Matrix Sum' */
  flightControlSystem_B.bottom = (uint8_T)colIdx;

  /* Sum: '<S2>/Matrix Sum1' incorporates:
   *  S-Function (sdspsubmtrx): '<S2>/Submatrix'
   */
  colIdx = 0;
  for (yIdx = 0; yIdx < 900; yIdx++) {
    colIdx = (int32_T)((uint32_T)colIdx + flightControlSystem_B.Submatrix[yIdx]);
  }

  /* Sum: '<S2>/Matrix Sum1' */
  flightControlSystem_B.top = (uint8_T)colIdx;

  /* Logic: '<S2>/Logical Operator' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   */
  flightControlSystem_B.circle_e = ((flightControlSystem_B.top >=
    flightControlSystem_P.CompareToConstant_const) &&
    (flightControlSystem_B.bottom >=
     flightControlSystem_P.CompareToConstant1_const));

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  yIdx = -1;
  colIdx = 1;
  loop = 1;
  exitg1 = false;
  while ((!exitg1) && (loop <= 160)) {
    guard1 = false;
    if (flightControlSystem_B.y_m[((loop - 1) * 120 + colIdx) + 13]) {
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

  Submatrix_tmp = loop + 1;
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
    flightControlSystem_B.avgX = flightControlSystem_mean_0sSgOgPG
      (flightControlSystem_B.colIdx_data, &colIdx_size);
    flightControlSystem_B.avgY = flightControlSystem_mean_0sSgOgPG
      (flightControlSystem_B.rowIdx_data, &Submatrix_tmp);
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

  /* RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_3_Buffer0 =
    flightControlSystem_B.circle_e;
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
        &flightControlSystem_Y.Actuators[0]
      };

      rtliSetLogYSignalPtrs(flightControlSystem_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_SINGLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "motors" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightControlSystem/Actuators" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
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
    }

    rtliSetLogY(flightControlSystem_M->rtwLogInfo, "yout");
  }

  /* External mode info */
  flightControlSystem_M->Sizes.checksums[0] = (1750311811U);
  flightControlSystem_M->Sizes.checksums[1] = (3089197967U);
  flightControlSystem_M->Sizes.checksums[2] = (4146967742U);
  flightControlSystem_M->Sizes.checksums[3] = (3666445511U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    flightControlSystem_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
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

  /* InitializeConditions for RateTransition generated from: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_3_Buffer0 =
    flightControlSystem_P.RateTransition_3_InitialCondition;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Flight Control System' */

  /* SystemInitialize for Inport: '<Root>/Sensors' */
  flightControlSystem_FlightControlSystem_Init
    (&flightControlSystem_DW.FlightControlSystem,
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
