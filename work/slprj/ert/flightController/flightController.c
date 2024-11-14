/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightController.c
 *
 * Code generated for Simulink model 'flightController'.
 *
 * Model version                  : 8.11
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Nov 14 14:29:57 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightController.h"
#include "flightController_types.h"
#include "rtwtypes.h"
#include "flightController_private.h"
#include <math.h>

P_flightController_T flightController_P_g = {
  /* Mask Parameter: SRFlipFlop_initial_condition
   * Referenced by: '<S4>/Memory'
   */
  false,

  /* Expression: Controller.takeoffGain
   * Referenced by: '<S7>/takeoff_gain'
   */
  0.45F,

  /* Computed Parameter: D_z_Gain
   * Referenced by: '<S7>/D_z'
   */
  0.3F,

  /* Computed Parameter: P_z_Gain
   * Referenced by: '<S7>/P_z'
   */
  0.8F,

  /* Computed Parameter: SaturationThrust_UpperSat
   * Referenced by: '<S7>/SaturationThrust'
   */
  1.20204329F,

  /* Computed Parameter: SaturationThrust_LowerSat
   * Referenced by: '<S7>/SaturationThrust'
   */
  -1.20204329F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S1>/Constant1'
   */
  0.0F,

  /* Computed Parameter: D_xy_Gain
   * Referenced by: '<S5>/D_xy'
   */
  { 0.1F, -0.1F },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S5>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S5>/Saturation'
   */
  3.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S5>/Saturation'
   */
  -3.0F,

  /* Computed Parameter: P_xy_Gain
   * Referenced by: '<S5>/P_xy'
   */
  { -0.24F, 0.24F },

  /* Expression: Controller.Q2Ts
   * Referenced by: '<S3>/TorqueTotalThrustToThrustPerMotor'
   */
  { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
    -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F, 5.66592F,
    5.66592F, -5.66592F },

  /* Computed Parameter: D_pr_Gain
   * Referenced by: '<S2>/D_pr'
   */
  { 0.002F, 0.0028F },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.005F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  2.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  -2.0F,

  /* Computed Parameter: I_pr_Gain
   * Referenced by: '<S2>/I_pr'
   */
  0.01F,

  /* Computed Parameter: P_pr_Gain
   * Referenced by: '<S2>/P_pr'
   */
  { 0.013F, 0.01F },

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S2>/Constant'
   */
  0.0F,

  /* Computed Parameter: w0_Value
   * Referenced by: '<S7>/w0'
   */
  -0.61803F,

  /* Computed Parameter: P_yaw_Gain
   * Referenced by: '<S6>/P_yaw'
   */
  0.004F,

  /* Computed Parameter: D_yaw_Gain
   * Referenced by: '<S6>/D_yaw'
   */
  0.0012F,

  /* Computed Parameter: ThrustToMotorCommand_Gain
   * Referenced by: '<S8>/ThrustToMotorCommand'
   */
  -1530.72681F,

  /* Expression: Vehicle.Motor.maxLimit
   * Referenced by: '<S8>/Saturation5'
   */
  500.0F,

  /* Expression: Vehicle.Motor.minLimit
   * Referenced by: '<S8>/Saturation5'
   */
  10.0F,

  /* Computed Parameter: MotorDirections_Gain
   * Referenced by: '<S8>/MotorDirections'
   */
  { 1.0F, -1.0F, 1.0F, -1.0F },

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S2>/Delay'
   */
  0.0F,

  /* Computed Parameter: antiWU_Gain_Gain
   * Referenced by: '<S2>/antiWU_Gain'
   */
  0.001F,

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S1>/Constant'
   */
  false,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S4>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false }
};

MdlrefDW_flightController_T flightController_MdlrefDW;

/* Block states (default storage) */
DW_flightController_f_T flightController_DW;

/* System initialize for referenced model: 'flightController' */
void flightController_Init(void)
{
  /* InitializeConditions for Switch: '<S1>/Switch' incorporates:
   *  Memory: '<S4>/Memory'
   */
  flightController_DW.Memory_PreviousInput =
    flightController_P_g.SRFlipFlop_initial_condition;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
    flightController_P_g.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[0] =
    flightController_P_g.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
    flightController_P_g.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[1] =
    flightController_P_g.Delay_InitialCondition;
}

/* Output and update for referenced model: 'flightController' */
void flightController_run(const CommandBus *arg_ReferenceValueServerBus, const
  statesEstim_t *arg_states_estim, real32_T arg_motors_refout[4], real32_T
  arg_pose_refout[8])
{
  /* local block i/o variables */
  boolean_T rtb_Memory;
  int32_T i;
  real32_T rtb_Delay_idx_1;
  real32_T rtb_DiscreteTimeIntegrator_idx_1;
  real32_T rtb_Switch;
  real32_T rtb_Switch_idx_1;
  real32_T rtb_Switch_idx_2;
  real32_T rtb_TrigonometricFunction_o2;
  real32_T rtb_pitchrollerror_idx_0;
  real32_T rtb_pitchrollerror_idx_1;
  real32_T u0;

  /* Switch: '<S1>/Switch_refAtt' incorporates:
   *  Gain: '<S5>/D_xy'
   *  Gain: '<S5>/P_xy'
   *  Saturate: '<S5>/Saturation'
   *  Sum: '<S5>/Sum18'
   */
  if (arg_ReferenceValueServerBus->controlModePosVSOrient) {
    /* Trigonometry: '<S5>/Trigonometric Function' */
    rtb_pitchrollerror_idx_1 = (real32_T)sin(arg_states_estim->yaw);
    rtb_TrigonometricFunction_o2 = (real32_T)cos(arg_states_estim->yaw);

    /* Sum: '<S5>/Sum17' */
    rtb_DiscreteTimeIntegrator_idx_1 = arg_ReferenceValueServerBus->pos_ref[0] -
      arg_states_estim->X;
    rtb_Delay_idx_1 = arg_ReferenceValueServerBus->pos_ref[1] -
      arg_states_estim->Y;

    /* Product: '<S5>/Product' incorporates:
     *  SignalConversion generated from: '<S5>/Vector Concatenate1'
     *  SignalConversion generated from: '<S5>/Vector Concatenate'
     */
    rtb_Switch = rtb_TrigonometricFunction_o2 * rtb_DiscreteTimeIntegrator_idx_1
      + rtb_pitchrollerror_idx_1 * rtb_Delay_idx_1;

    /* Saturate: '<S5>/Saturation' incorporates:
     *  Product: '<S5>/Product'
     */
    if (rtb_Switch > flightController_P_g.Saturation_UpperSat) {
      rtb_Switch = flightController_P_g.Saturation_UpperSat;
    } else if (rtb_Switch < flightController_P_g.Saturation_LowerSat) {
      rtb_Switch = flightController_P_g.Saturation_LowerSat;
    }

    rtb_pitchrollerror_idx_0 = flightController_P_g.P_xy_Gain[0] * rtb_Switch +
      flightController_P_g.D_xy_Gain[0] * arg_states_estim->dx;

    /* Product: '<S5>/Product' incorporates:
     *  Gain: '<S5>/D_xy'
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/P_xy'
     *  Saturate: '<S5>/Saturation'
     *  SignalConversion generated from: '<S5>/Vector Concatenate1'
     *  Sum: '<S5>/Sum18'
     */
    rtb_Switch = flightController_P_g.Gain_Gain * rtb_pitchrollerror_idx_1 *
      rtb_DiscreteTimeIntegrator_idx_1 + rtb_TrigonometricFunction_o2 *
      rtb_Delay_idx_1;

    /* Saturate: '<S5>/Saturation' incorporates:
     *  Product: '<S5>/Product'
     */
    if (rtb_Switch > flightController_P_g.Saturation_UpperSat) {
      rtb_Switch = flightController_P_g.Saturation_UpperSat;
    } else if (rtb_Switch < flightController_P_g.Saturation_LowerSat) {
      rtb_Switch = flightController_P_g.Saturation_LowerSat;
    }

    rtb_pitchrollerror_idx_1 = flightController_P_g.P_xy_Gain[1] * rtb_Switch +
      flightController_P_g.D_xy_Gain[1] * arg_states_estim->dy;
  } else {
    rtb_pitchrollerror_idx_0 = arg_ReferenceValueServerBus->orient_ref[1];
    rtb_pitchrollerror_idx_1 = arg_ReferenceValueServerBus->orient_ref[2];
  }

  /* End of Switch: '<S1>/Switch_refAtt' */

  /* SignalConversion generated from: '<Root>/pose_refout' incorporates:
   *  SignalConversion generated from: '<S1>/ReferenceValueServerBus_BusSelector'
   */
  arg_pose_refout[0] = arg_ReferenceValueServerBus->pos_ref[0];
  arg_pose_refout[3] = arg_ReferenceValueServerBus->orient_ref[0];
  arg_pose_refout[1] = arg_ReferenceValueServerBus->pos_ref[1];
  arg_pose_refout[4] = arg_ReferenceValueServerBus->orient_ref[1];
  arg_pose_refout[2] = arg_ReferenceValueServerBus->pos_ref[2];
  arg_pose_refout[5] = arg_ReferenceValueServerBus->orient_ref[2];
  arg_pose_refout[6] = rtb_pitchrollerror_idx_0;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  rtb_TrigonometricFunction_o2 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* SignalConversion generated from: '<Root>/pose_refout' */
  arg_pose_refout[7] = rtb_pitchrollerror_idx_1;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_idx_1 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Sum: '<S2>/Sum19' */
  rtb_pitchrollerror_idx_0 -= arg_states_estim->pitch;
  rtb_pitchrollerror_idx_1 -= arg_states_estim->roll;

  /* Sum: '<S2>/Sum16' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<S2>/D_pr'
   *  Gain: '<S2>/I_pr'
   *  Gain: '<S2>/P_pr'
   */
  rtb_Delay_idx_1 = (flightController_P_g.P_pr_Gain[1] *
                     rtb_pitchrollerror_idx_1 + flightController_P_g.I_pr_Gain *
                     flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) -
    flightController_P_g.D_pr_Gain[1] * arg_states_estim->p;

  /* Memory: '<S4>/Memory' */
  rtb_Memory = flightController_DW.Memory_PreviousInput;

  /* Switch: '<S1>/Switch' incorporates:
   *  CombinatorialLogic: '<S4>/Logic'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   */
  flightController_DW.Memory_PreviousInput = flightController_P_g.Logic_table
    [((((uint32_T)arg_ReferenceValueServerBus->takeoff_flag << 1) +
       flightController_P_g.Constant_Value_p) << 1) + rtb_Memory];
  if (flightController_DW.Memory_PreviousInput) {
    /* Switch: '<S7>/TakeoffOrControl_Switch' incorporates:
     *  Constant: '<S7>/w0'
     *  Gain: '<S7>/D_z'
     *  Gain: '<S7>/P_z'
     *  Gain: '<S7>/takeoff_gain'
     *  Sum: '<S7>/Sum15'
     *  Sum: '<S7>/Sum3'
     */
    if (arg_ReferenceValueServerBus->takeoff_flag) {
      rtb_Switch = flightController_P_g.takeoff_gain_Gain *
        flightController_P_g.w0_Value;
    } else {
      rtb_Switch = (arg_ReferenceValueServerBus->pos_ref[2] -
                    arg_states_estim->Z) * flightController_P_g.P_z_Gain -
        flightController_P_g.D_z_Gain * arg_states_estim->dz;
    }

    /* Sum: '<S7>/Sum4' incorporates:
     *  Constant: '<S7>/w0'
     *  Switch: '<S7>/TakeoffOrControl_Switch'
     */
    rtb_Switch += flightController_P_g.w0_Value;

    /* Saturate: '<S7>/SaturationThrust' */
    if (rtb_Switch > flightController_P_g.SaturationThrust_UpperSat) {
      rtb_Switch = flightController_P_g.SaturationThrust_UpperSat;
    } else if (rtb_Switch < flightController_P_g.SaturationThrust_LowerSat) {
      rtb_Switch = flightController_P_g.SaturationThrust_LowerSat;
    }

    /* End of Saturate: '<S7>/SaturationThrust' */
  } else {
    rtb_Switch = flightController_P_g.Constant1_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* SignalConversion generated from: '<S3>/Product' incorporates:
   *  Constant: '<S2>/Constant'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<S2>/D_pr'
   *  Gain: '<S2>/I_pr'
   *  Gain: '<S2>/P_pr'
   *  Gain: '<S6>/D_yaw'
   *  Gain: '<S6>/P_yaw'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum16'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum2'
   */
  rtb_Switch_idx_1 = (arg_ReferenceValueServerBus->orient_ref[0] -
                      arg_states_estim->yaw) * flightController_P_g.P_yaw_Gain -
    flightController_P_g.D_yaw_Gain * arg_states_estim->r;
  rtb_Switch_idx_2 = ((flightController_P_g.P_pr_Gain[0] *
                       rtb_pitchrollerror_idx_0 + flightController_P_g.I_pr_Gain
                       * flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) -
                      flightController_P_g.D_pr_Gain[0] * arg_states_estim->q) +
    flightController_P_g.Constant_Value;
  for (i = 0; i < 4; i++) {
    /* Saturate: '<S8>/Saturation5' incorporates:
     *  Constant: '<S3>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S8>/ThrustToMotorCommand'
     *  Product: '<S3>/Product'
     *  SignalConversion generated from: '<S3>/Product'
     */
    u0 = (((flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i + 4] *
            rtb_Switch_idx_1 +
            flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i] *
            rtb_Switch) +
           flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i + 8] *
           rtb_Switch_idx_2) +
          flightController_P_g.TorqueTotalThrustToThrustPerMotor_Value[i + 12] *
          rtb_Delay_idx_1) * flightController_P_g.ThrustToMotorCommand_Gain;
    if (u0 > flightController_P_g.Saturation5_UpperSat) {
      u0 = flightController_P_g.Saturation5_UpperSat;
    } else if (u0 < flightController_P_g.Saturation5_LowerSat) {
      u0 = flightController_P_g.Saturation5_LowerSat;
    }

    /* Gain: '<S8>/MotorDirections' incorporates:
     *  Saturate: '<S8>/Saturation5'
     */
    arg_motors_refout[i] = flightController_P_g.MotorDirections_Gain[i] * u0;
  }

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/antiWU_Gain'
   *  Sum: '<S2>/Add'
   */
  rtb_pitchrollerror_idx_0 = (rtb_pitchrollerror_idx_0 -
    flightController_P_g.antiWU_Gain_Gain * flightController_DW.Delay_DSTATE[0])
    * flightController_P_g.DiscreteTimeIntegrator_gainval +
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0];
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
    rtb_pitchrollerror_idx_0;
  if (rtb_pitchrollerror_idx_0 >=
      flightController_P_g.DiscreteTimeIntegrator_UpperSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
      flightController_P_g.DiscreteTimeIntegrator_UpperSat;
  } else if (rtb_pitchrollerror_idx_0 <=
             flightController_P_g.DiscreteTimeIntegrator_LowerSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] =
      flightController_P_g.DiscreteTimeIntegrator_LowerSat;
  }

  /* Update for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[0] = rtb_TrigonometricFunction_o2;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/antiWU_Gain'
   *  Sum: '<S2>/Add'
   */
  rtb_pitchrollerror_idx_0 = (rtb_pitchrollerror_idx_1 -
    flightController_P_g.antiWU_Gain_Gain * flightController_DW.Delay_DSTATE[1])
    * flightController_P_g.DiscreteTimeIntegrator_gainval +
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1];
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
    rtb_pitchrollerror_idx_0;
  if (rtb_pitchrollerror_idx_0 >=
      flightController_P_g.DiscreteTimeIntegrator_UpperSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
      flightController_P_g.DiscreteTimeIntegrator_UpperSat;
  } else if (rtb_pitchrollerror_idx_0 <=
             flightController_P_g.DiscreteTimeIntegrator_LowerSat) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] =
      flightController_P_g.DiscreteTimeIntegrator_LowerSat;
  }

  /* Update for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[1] = rtb_DiscreteTimeIntegrator_idx_1;
}

/* Model initialize function */
void flightController_g_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_flightController_T *const flightController_M =
    &(flightController_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(flightController_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
