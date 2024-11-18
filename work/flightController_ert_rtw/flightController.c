/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightController.c
 *
 * Code generated for Simulink model 'flightController'.
 *
 * Model version                  : 8.21
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Nov 18 12:50:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightController.h"
#include "flightController_types.h"
#include <math.h>
#include "rtwtypes.h"
#include "flightController_private.h"
#include "rt_nonfinite.h"
#include "flightController_dt.h"

/* Block states (default storage) */
DW_flightController_T flightController_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightController_T flightController_Y;

/* Real-time model */
static RT_MODEL_flightController_T flightController_M_;
RT_MODEL_flightController_T *const flightController_M = &flightController_M_;

/* Model step function */
void flightController_run(const CommandBus *arg_ReferenceValueServerBus, const
  statesEstim_t *arg_states_estim, real32_T arg_motors_refout[4], real32_T
  arg_pose_refout[8])
{
  int32_T i;
  real32_T rtb_DiscreteTimeIntegrator_idx_0;
  real32_T rtb_DiscreteTimeIntegrator_idx_1;
  real32_T rtb_P_pr_p_idx_1;
  real32_T rtb_Switch;
  real32_T rtb_Switch_idx_1;
  real32_T rtb_Switch_idx_2;
  real32_T rtb_Switch_refAtt_idx_0;
  real32_T rtb_Switch_refAtt_idx_1;
  real32_T rtb_TrigonometricFunction_o2;
  real32_T rtb_pitchrollerror_idx_0;
  real32_T u0;

  /* Switch: '<S1>/Switch' incorporates:
   *  CombinatorialLogic: '<S4>/Logic'
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Memory: '<S4>/Memory'
   */
  flightController_DW.Memory_PreviousInput = flightController_P.Logic_table
    [((((uint32_T)arg_ReferenceValueServerBus->takeoff_flag << 1) +
       arg_ReferenceValueServerBus->landing_flag) << 1) +
    flightController_DW.Memory_PreviousInput];
  if (flightController_DW.Memory_PreviousInput) {
    /* Switch: '<S7>/TakeoffOrControl_Switch' incorporates:
     *  Constant: '<S7>/w0'
     *  Gain: '<S7>/D_z'
     *  Gain: '<S7>/P_z'
     *  Gain: '<S7>/takeoff_gain'
     *  Inport: '<Root>/states_estim'
     *  Sum: '<S7>/Sum15'
     *  Sum: '<S7>/Sum3'
     */
    if (arg_ReferenceValueServerBus->takeoff_flag) {
      rtb_Switch = flightController_P.takeoff_gain_Gain *
        flightController_P.w0_Value;
    } else {
      rtb_Switch = (arg_ReferenceValueServerBus->pos_ref[2] -
                    arg_states_estim->Z) * flightController_P.P_z_Gain -
        flightController_P.D_z_Gain * arg_states_estim->dz;
    }

    /* Sum: '<S7>/Sum4' incorporates:
     *  Constant: '<S7>/w0'
     *  Switch: '<S7>/TakeoffOrControl_Switch'
     */
    rtb_Switch += flightController_P.w0_Value;

    /* Saturate: '<S7>/SaturationThrust' */
    if (rtb_Switch > flightController_P.SaturationThrust_UpperSat) {
      rtb_Switch = flightController_P.SaturationThrust_UpperSat;
    } else if (rtb_Switch < flightController_P.SaturationThrust_LowerSat) {
      rtb_Switch = flightController_P.SaturationThrust_LowerSat;
    }

    /* End of Saturate: '<S7>/SaturationThrust' */
  } else {
    rtb_Switch = flightController_P.Constant1_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Switch: '<S1>/Switch_refAtt' incorporates:
   *  Gain: '<S5>/D_xy'
   *  Gain: '<S5>/P_xy'
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Inport: '<Root>/states_estim'
   *  Saturate: '<S5>/Saturation'
   *  Sum: '<S5>/Sum18'
   */
  if (arg_ReferenceValueServerBus->controlModePosVSOrient) {
    /* Trigonometry: '<S5>/Trigonometric Function' incorporates:
     *  Inport: '<Root>/states_estim'
     */
    rtb_Switch_refAtt_idx_1 = (real32_T)sin(arg_states_estim->yaw);
    rtb_TrigonometricFunction_o2 = (real32_T)cos(arg_states_estim->yaw);

    /* Sum: '<S5>/Sum17' incorporates:
     *  Inport: '<Root>/states_estim'
     */
    rtb_DiscreteTimeIntegrator_idx_0 = arg_ReferenceValueServerBus->pos_ref[0] -
      arg_states_estim->X;
    rtb_DiscreteTimeIntegrator_idx_1 = arg_ReferenceValueServerBus->pos_ref[1] -
      arg_states_estim->Y;

    /* Product: '<S5>/Product' incorporates:
     *  SignalConversion generated from: '<S5>/Vector Concatenate1'
     *  SignalConversion generated from: '<S5>/Vector Concatenate'
     */
    rtb_pitchrollerror_idx_0 = rtb_TrigonometricFunction_o2 *
      rtb_DiscreteTimeIntegrator_idx_0 + rtb_Switch_refAtt_idx_1 *
      rtb_DiscreteTimeIntegrator_idx_1;

    /* Saturate: '<S5>/Saturation' incorporates:
     *  Product: '<S5>/Product'
     */
    if (rtb_pitchrollerror_idx_0 > flightController_P.Saturation_UpperSat) {
      rtb_pitchrollerror_idx_0 = flightController_P.Saturation_UpperSat;
    } else if (rtb_pitchrollerror_idx_0 < flightController_P.Saturation_LowerSat)
    {
      rtb_pitchrollerror_idx_0 = flightController_P.Saturation_LowerSat;
    }

    rtb_Switch_refAtt_idx_0 = flightController_P.P_xy_Gain[0] *
      rtb_pitchrollerror_idx_0 + flightController_P.D_xy_Gain[0] *
      arg_states_estim->dx;

    /* Product: '<S5>/Product' incorporates:
     *  Gain: '<S5>/D_xy'
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/P_xy'
     *  Inport: '<Root>/states_estim'
     *  Saturate: '<S5>/Saturation'
     *  SignalConversion generated from: '<S5>/Vector Concatenate1'
     *  Sum: '<S5>/Sum18'
     */
    rtb_pitchrollerror_idx_0 = flightController_P.Gain_Gain *
      rtb_Switch_refAtt_idx_1 * rtb_DiscreteTimeIntegrator_idx_0 +
      rtb_TrigonometricFunction_o2 * rtb_DiscreteTimeIntegrator_idx_1;

    /* Saturate: '<S5>/Saturation' incorporates:
     *  Product: '<S5>/Product'
     */
    if (rtb_pitchrollerror_idx_0 > flightController_P.Saturation_UpperSat) {
      rtb_pitchrollerror_idx_0 = flightController_P.Saturation_UpperSat;
    } else if (rtb_pitchrollerror_idx_0 < flightController_P.Saturation_LowerSat)
    {
      rtb_pitchrollerror_idx_0 = flightController_P.Saturation_LowerSat;
    }

    rtb_Switch_refAtt_idx_1 = flightController_P.P_xy_Gain[1] *
      rtb_pitchrollerror_idx_0 + flightController_P.D_xy_Gain[1] *
      arg_states_estim->dy;
  } else {
    rtb_Switch_refAtt_idx_0 = arg_ReferenceValueServerBus->orient_ref[1];
    rtb_Switch_refAtt_idx_1 = arg_ReferenceValueServerBus->orient_ref[2];
  }

  /* End of Switch: '<S1>/Switch_refAtt' */

  /* Sum: '<S2>/Sum19' incorporates:
   *  Inport: '<Root>/states_estim'
   */
  rtb_pitchrollerror_idx_0 = rtb_Switch_refAtt_idx_0 - arg_states_estim->pitch;
  rtb_TrigonometricFunction_o2 = rtb_Switch_refAtt_idx_1 -
    arg_states_estim->roll;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_idx_0 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0];
  rtb_DiscreteTimeIntegrator_idx_1 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Sum: '<S2>/Sum16' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<S2>/D_pr'
   *  Gain: '<S2>/I_pr'
   *  Gain: '<S2>/P_pr'
   *  Inport: '<Root>/states_estim'
   */
  rtb_P_pr_p_idx_1 = (flightController_P.P_pr_Gain[1] *
                      rtb_TrigonometricFunction_o2 +
                      flightController_P.I_pr_Gain *
                      flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) -
    flightController_P.D_pr_Gain[1] * arg_states_estim->p;

  /* SignalConversion generated from: '<S3>/Product' incorporates:
   *  Constant: '<S2>/Constant'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<S2>/D_pr'
   *  Gain: '<S2>/I_pr'
   *  Gain: '<S2>/P_pr'
   *  Gain: '<S6>/D_yaw'
   *  Gain: '<S6>/P_yaw'
   *  Inport: '<Root>/ReferenceValueServerBus'
   *  Inport: '<Root>/states_estim'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum16'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum2'
   */
  rtb_Switch_idx_1 = (arg_ReferenceValueServerBus->orient_ref[0] -
                      arg_states_estim->yaw) * flightController_P.P_yaw_Gain -
    flightController_P.D_yaw_Gain * arg_states_estim->r;
  rtb_Switch_idx_2 = ((flightController_P.P_pr_Gain[0] *
                       rtb_pitchrollerror_idx_0 + flightController_P.I_pr_Gain *
                       flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) -
                      flightController_P.D_pr_Gain[0] * arg_states_estim->q) +
    flightController_P.Constant_Value;
  for (i = 0; i < 4; i++) {
    /* Saturate: '<S8>/Saturation5' incorporates:
     *  Constant: '<S3>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S8>/ThrustToMotorCommand'
     *  Product: '<S3>/Product'
     *  SignalConversion generated from: '<S3>/Product'
     */
    u0 = (((flightController_P.TorqueTotalThrustToThrustPerMotor_Value[i + 4] *
            rtb_Switch_idx_1 +
            flightController_P.TorqueTotalThrustToThrustPerMotor_Value[i] *
            rtb_Switch) +
           flightController_P.TorqueTotalThrustToThrustPerMotor_Value[i + 8] *
           rtb_Switch_idx_2) +
          flightController_P.TorqueTotalThrustToThrustPerMotor_Value[i + 12] *
          rtb_P_pr_p_idx_1) * flightController_P.ThrustToMotorCommand_Gain;
    if (u0 > flightController_P.Saturation5_UpperSat) {
      u0 = flightController_P.Saturation5_UpperSat;
    } else if (u0 < flightController_P.Saturation5_LowerSat) {
      u0 = flightController_P.Saturation5_LowerSat;
    }

    /* Outport: '<Root>/motors_refout' incorporates:
     *  Gain: '<S8>/MotorDirections'
     *  Saturate: '<S8>/Saturation5'
     */
    flightController_Y.motors_refout[i] =
      flightController_P.MotorDirections_Gain[i] * u0;
  }

  /* Outport: '<Root>/pose_refout' incorporates:
   *  Inport: '<Root>/ReferenceValueServerBus'
   */
  flightController_Y.pose_refout[0] = arg_ReferenceValueServerBus->pos_ref[0];
  flightController_Y.pose_refout[3] = arg_ReferenceValueServerBus->orient_ref[0];
  flightController_Y.pose_refout[1] = arg_ReferenceValueServerBus->pos_ref[1];
  flightController_Y.pose_refout[4] = arg_ReferenceValueServerBus->orient_ref[1];
  flightController_Y.pose_refout[2] = arg_ReferenceValueServerBus->pos_ref[2];
  flightController_Y.pose_refout[5] = arg_ReferenceValueServerBus->orient_ref[2];
  flightController_Y.pose_refout[6] = rtb_Switch_refAtt_idx_0;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/antiWU_Gain'
   *  Sum: '<S2>/Add'
   */
  rtb_Switch = (rtb_pitchrollerror_idx_0 - flightController_P.antiWU_Gain_Gain *
                flightController_DW.Delay_DSTATE[0]) *
    flightController_P.DiscreteTimeIntegrator_gainval +
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0];
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = rtb_Switch;
  if (rtb_Switch >= flightController_P.DiscreteTimeIntegrator_UpperSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
      flightController_P.DiscreteTimeIntegrator_UpperSat;
  } else if (rtb_Switch <= flightController_P.DiscreteTimeIntegrator_LowerSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
      flightController_P.DiscreteTimeIntegrator_LowerSat;
  }

  /* Update for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[0] = rtb_DiscreteTimeIntegrator_idx_0;

  /* Outport: '<Root>/pose_refout' */
  flightController_Y.pose_refout[7] = rtb_Switch_refAtt_idx_1;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/antiWU_Gain'
   *  Sum: '<S2>/Add'
   */
  rtb_Switch = (rtb_TrigonometricFunction_o2 -
                flightController_P.antiWU_Gain_Gain *
                flightController_DW.Delay_DSTATE[1]) *
    flightController_P.DiscreteTimeIntegrator_gainval +
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1];
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = rtb_Switch;
  if (rtb_Switch >= flightController_P.DiscreteTimeIntegrator_UpperSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
      flightController_P.DiscreteTimeIntegrator_UpperSat;
  } else if (rtb_Switch <= flightController_P.DiscreteTimeIntegrator_LowerSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
      flightController_P.DiscreteTimeIntegrator_LowerSat;
  }

  /* Update for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[1] = rtb_DiscreteTimeIntegrator_idx_1;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightController_M->rtwLogInfo,
                      (&flightController_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.005s, 0.0s] */
    rtExtModeUpload(0, (real_T)flightController_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightController_M)!=-1) &&
        !((rtmGetTFinal(flightController_M)-flightController_M->Timing.taskTime0)
          > flightController_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightController_M, "Simulation finished");
    }

    if (rtmGetStopRequested(flightController_M)) {
      rtmSetErrorStatus(flightController_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  flightController_M->Timing.taskTime0 =
    ((time_T)(++flightController_M->Timing.clockTick0)) *
    flightController_M->Timing.stepSize0;

  /* Copy value for root outport '<Root>/motors_refout' since it is accessed globally */
  {
    int32_T i;
    for (i = 0; i < 4; i++)
      arg_motors_refout[i] = flightController_Y.motors_refout[i];
  }

  /* Copy value for root outport '<Root>/pose_refout' since it is accessed globally */
  {
    int32_T i;
    for (i = 0; i < 8; i++)
      arg_pose_refout[i] = flightController_Y.pose_refout[i];
  }
}

/* Model initialize function */
void flightController_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(flightController_M, 30.0);
  flightController_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    flightController_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightController_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightController_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightController_M->rtwLogInfo, "tout");
    rtliSetLogX(flightController_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightController_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightController_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightController_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(flightController_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightController_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &flightController_Y.motors_refout[0],
        &flightController_Y.pose_refout[0]
      };

      rtliSetLogYSignalPtrs(flightController_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        4,
        8
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        4,
        8
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
        SS_SINGLE
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
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "flightController/motors_refout",
        "flightController/pose_refout" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_SINGLE, SS_SINGLE, 0, 0, 0, 1.0, 0, 0.0 }
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

      rtliSetLogYSignalInfo(flightController_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(flightController_M->rtwLogInfo, "yout");
  }

  /* External mode info */
  flightController_M->Sizes.checksums[0] = (4194718196U);
  flightController_M->Sizes.checksums[1] = (1061061113U);
  flightController_M->Sizes.checksums[2] = (3971671900U);
  flightController_M->Sizes.checksums[3] = (690645091U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    flightController_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(flightController_M->extModeInfo,
      &flightController_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(flightController_M->extModeInfo,
                        flightController_M->Sizes.checksums);
    rteiSetTPtr(flightController_M->extModeInfo, rtmGetTPtr(flightController_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    flightController_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 29;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightController_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightController_M), flightController_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightController_M)));

  /* InitializeConditions for Switch: '<S1>/Switch' incorporates:
   *  Memory: '<S4>/Memory'
   */
  flightController_DW.Memory_PreviousInput =
    flightController_P.SRFlipFlop_initial_condition;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
    flightController_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[0] =
    flightController_P.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
    flightController_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[1] =
    flightController_P.Delay_InitialCondition;
}

/* Model terminate function */
void flightController_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
