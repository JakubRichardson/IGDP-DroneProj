/*
 * Code generation for system model 'flightController'
 *
 * Model                      : flightController
 * Model version              : 8.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov  6 18:07:40 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "flightController.h"
#include "flightController_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "flightController_private.h"
#include <string.h>

MdlrefDW_flightController_T flightController_MdlrefDW;

/* Block states (default storage) */
DW_flightController_f_T flightController_DW;

/* System initialize for referenced model: 'flightController' */
void flightController_Init(void)
{
  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0F;
}

/* System reset for referenced model: 'flightController' */
void flightController_Reset(void)
{
  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0F;
}

/* Output and update for referenced model: 'flightController' */
void flightController(const CommandBus *rtu_ReferenceValueServerBus, const
                      statesEstim_t *rtu_states_estim, real32_T
                      rty_motors_refout[4], real32_T rty_pose_refout[8])
{
  int32_T i;
  real32_T rtb_SaturationThrust;
  real32_T rtb_SaturationThrust_idx_2;
  real32_T rtb_SaturationThrust_idx_3;
  real32_T rtb_Sum2;
  real32_T rtb_Switch_refAtt_idx_0;
  real32_T rtb_Switch_refAtt_idx_1;
  real32_T rtb_TrigonometricFunction_o1;
  real32_T rtb_TrigonometricFunction_o2;
  real32_T rtb_antiWU_Gain_idx_0;
  real32_T rtb_antiWU_Gain_idx_1;
  real32_T rtb_pitchrollerror_idx_0;
  real32_T rtb_pitchrollerror_idx_1;
  real32_T u0;

  /* Switch: '<S1>/Switch_refAtt' incorporates:
   *  Gain: '<S4>/D_xy'
   *  Gain: '<S4>/P_xy'
   *  Saturate: '<S4>/Saturation'
   *  Sum: '<S4>/Sum18'
   */
  if (rtu_ReferenceValueServerBus->controlModePosVSOrient) {
    /* Trigonometry: '<S4>/Trigonometric Function' */
    rtb_TrigonometricFunction_o1 = (real32_T)sin(rtu_states_estim->yaw);
    rtb_TrigonometricFunction_o2 = (real32_T)cos(rtu_states_estim->yaw);

    /* Sum: '<S4>/Sum17' */
    rtb_Switch_refAtt_idx_1 = rtu_ReferenceValueServerBus->pos_ref[0] -
      rtu_states_estim->X;
    rtb_pitchrollerror_idx_1 = rtu_ReferenceValueServerBus->pos_ref[1] -
      rtu_states_estim->Y;

    /* Product: '<S4>/Product' incorporates:
     *  SignalConversion generated from: '<S4>/Vector Concatenate1'
     *  SignalConversion generated from: '<S4>/Vector Concatenate'
     */
    rtb_antiWU_Gain_idx_1 = rtb_TrigonometricFunction_o2 *
      rtb_Switch_refAtt_idx_1 + rtb_TrigonometricFunction_o1 *
      rtb_pitchrollerror_idx_1;

    /* Saturate: '<S4>/Saturation' incorporates:
     *  Product: '<S4>/Product'
     */
    if (rtb_antiWU_Gain_idx_1 > 3.0F) {
      rtb_antiWU_Gain_idx_1 = 3.0F;
    } else if (rtb_antiWU_Gain_idx_1 < (-3.0F)) {
      rtb_antiWU_Gain_idx_1 = (-3.0F);
    }

    rtb_Switch_refAtt_idx_0 = (-0.24F) * rtb_antiWU_Gain_idx_1 + 0.1F *
      rtu_states_estim->dx;

    /* Product: '<S4>/Product' incorporates:
     *  Gain: '<S4>/D_xy'
     *  Gain: '<S4>/Gain'
     *  Gain: '<S4>/P_xy'
     *  Saturate: '<S4>/Saturation'
     *  SignalConversion generated from: '<S4>/Vector Concatenate1'
     *  Sum: '<S4>/Sum18'
     */
    rtb_antiWU_Gain_idx_1 = (-1.0F) * rtb_TrigonometricFunction_o1 *
      rtb_Switch_refAtt_idx_1 + rtb_TrigonometricFunction_o2 *
      rtb_pitchrollerror_idx_1;

    /* Saturate: '<S4>/Saturation' incorporates:
     *  Product: '<S4>/Product'
     */
    if (rtb_antiWU_Gain_idx_1 > 3.0F) {
      rtb_antiWU_Gain_idx_1 = 3.0F;
    } else if (rtb_antiWU_Gain_idx_1 < (-3.0F)) {
      rtb_antiWU_Gain_idx_1 = (-3.0F);
    }

    rtb_Switch_refAtt_idx_1 = 0.24F * rtb_antiWU_Gain_idx_1 + (-0.1F) *
      rtu_states_estim->dy;
  } else {
    rtb_Switch_refAtt_idx_0 = rtu_ReferenceValueServerBus->orient_ref[1];
    rtb_Switch_refAtt_idx_1 = rtu_ReferenceValueServerBus->orient_ref[2];
  }

  /* End of Switch: '<S1>/Switch_refAtt' */

  /* Sum: '<S2>/Sum19' */
  rtb_pitchrollerror_idx_0 = rtb_Switch_refAtt_idx_0 - rtu_states_estim->pitch;
  rtb_pitchrollerror_idx_1 = rtb_Switch_refAtt_idx_1 - rtu_states_estim->roll;

  /* Gain: '<S2>/antiWU_Gain' incorporates:
   *  Delay: '<S2>/Delay'
   */
  rtb_antiWU_Gain_idx_0 = 0.001F * flightController_DW.Delay_DSTATE[0];
  rtb_antiWU_Gain_idx_1 = 0.001F * flightController_DW.Delay_DSTATE[1];

  /* Switch: '<S6>/TakeoffOrControl_Switch' incorporates:
   *  Constant: '<S6>/w0'
   *  Gain: '<S6>/D_z'
   *  Gain: '<S6>/P_z'
   *  Gain: '<S6>/takeoff_gain'
   *  Sum: '<S6>/Sum15'
   *  Sum: '<S6>/Sum3'
   */
  if (rtu_ReferenceValueServerBus->takeoff_flag) {
    u0 = 0.45F * (-0.61803F);
  } else {
    u0 = (rtu_ReferenceValueServerBus->pos_ref[2] - rtu_states_estim->Z) * 0.8F
      - 0.3F * rtu_states_estim->dz;
  }

  /* Sum: '<S6>/Sum4' incorporates:
   *  Constant: '<S6>/w0'
   *  Switch: '<S6>/TakeoffOrControl_Switch'
   */
  u0 += (-0.61803F);

  /* Saturate: '<S6>/SaturationThrust' */
  if (u0 > 1.20204329F) {
    rtb_SaturationThrust = 1.20204329F;
  } else if (u0 < (-1.20204329F)) {
    rtb_SaturationThrust = (-1.20204329F);
  } else {
    rtb_SaturationThrust = u0;
  }

  /* End of Saturate: '<S6>/SaturationThrust' */

  /* Sum: '<S5>/Sum2' incorporates:
   *  Gain: '<S5>/D_yaw'
   *  Gain: '<S5>/P_yaw'
   *  Sum: '<S5>/Sum1'
   */
  rtb_Sum2 = (rtu_ReferenceValueServerBus->orient_ref[0] - rtu_states_estim->yaw)
    * 0.004F - 0.0012F * rtu_states_estim->r;

  /* SignalConversion generated from: '<S3>/Product' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<S2>/D_pr'
   *  Gain: '<S2>/I_pr'
   *  Gain: '<S2>/P_pr'
   *  Sum: '<S2>/Sum16'
   */
  rtb_SaturationThrust_idx_2 = (0.013F * rtb_pitchrollerror_idx_0 + 0.01F *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) - 0.002F *
    rtu_states_estim->q;
  rtb_SaturationThrust_idx_3 = (0.01F * rtb_pitchrollerror_idx_1 + 0.01F *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) - 0.0028F *
    rtu_states_estim->p;
  for (i = 0; i < 4; i++) {
    /* Saturate: '<S7>/Saturation5' incorporates:
     *  Constant: '<S3>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S7>/ThrustToMotorCommand'
     *  Product: '<S3>/Product'
     *  SignalConversion generated from: '<S3>/Product'
     */
    u0 = (((rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 4] * rtb_Sum2 +
            rtCP_TorqueTotalThrustToThrustPerMotor_Value[i] *
            rtb_SaturationThrust) +
           rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 8] *
           rtb_SaturationThrust_idx_2) +
          rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 12] *
          rtb_SaturationThrust_idx_3) * (-1530.72681F);
    if (u0 > 500.0F) {
      u0 = 500.0F;
    } else if (u0 < 10.0F) {
      u0 = 10.0F;
    }

    /* Gain: '<S7>/MotorDirections' incorporates:
     *  Saturate: '<S7>/Saturation5'
     */
    rty_motors_refout[i] = rtCP_MotorDirections_Gain[i] * u0;
  }

  /* SignalConversion generated from: '<Root>/pose_refout' incorporates:
   *  SignalConversion generated from: '<S1>/ReferenceValueServerBus_BusSelector'
   */
  rty_pose_refout[0] = rtu_ReferenceValueServerBus->pos_ref[0];
  rty_pose_refout[3] = rtu_ReferenceValueServerBus->orient_ref[0];
  rty_pose_refout[1] = rtu_ReferenceValueServerBus->pos_ref[1];
  rty_pose_refout[4] = rtu_ReferenceValueServerBus->orient_ref[1];
  rty_pose_refout[2] = rtu_ReferenceValueServerBus->pos_ref[2];
  rty_pose_refout[5] = rtu_ReferenceValueServerBus->orient_ref[2];
  rty_pose_refout[6] = rtb_Switch_refAtt_idx_0;

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   */
  flightController_DW.Delay_DSTATE[0] =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S2>/Add'
   */
  rtb_Switch_refAtt_idx_0 = (rtb_pitchrollerror_idx_0 - rtb_antiWU_Gain_idx_0) *
    0.005F + flightController_DW.DiscreteTimeIntegrator_DSTATE[0];
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = rtb_Switch_refAtt_idx_0;
  if (rtb_Switch_refAtt_idx_0 >= 2.0F) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 2.0F;
  } else if (rtb_Switch_refAtt_idx_0 <= (-2.0F)) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = (-2.0F);
  }

  /* SignalConversion generated from: '<Root>/pose_refout' */
  rty_pose_refout[7] = rtb_Switch_refAtt_idx_1;

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   */
  flightController_DW.Delay_DSTATE[1] =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Sum: '<S2>/Add'
   */
  rtb_Switch_refAtt_idx_0 = (rtb_pitchrollerror_idx_1 - rtb_antiWU_Gain_idx_1) *
    0.005F + flightController_DW.DiscreteTimeIntegrator_DSTATE[1];
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = rtb_Switch_refAtt_idx_0;
  if (rtb_Switch_refAtt_idx_0 >= 2.0F) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 2.0F;
  } else if (rtb_Switch_refAtt_idx_0 <= (-2.0F)) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = (-2.0F);
  }
}

/* Model initialize function */
void flightController_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_flightController_T *const flightController_M =
    &(flightController_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(flightController_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)&flightController_DW, 0,
                sizeof(DW_flightController_f_T));
}
