/*
 * Code generation for system model 'stateEstimator'
 *
 * Model                      : stateEstimator
 * Model version              : 8.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov  6 18:08:04 2024
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "stateEstimator.h"
#include "rtwtypes.h"
#include "stateEstimator_types.h"
#include <math.h>
#include "rt_powf_snf.h"
#include "rt_nonfinite.h"
#include "stateEstimator_private.h"
#include <string.h>

MdlrefDW_stateEstimator_T stateEstimator_MdlrefDW;

/* Block signals (default storage) */
B_stateEstimator_c_T stateEstimator_B;

/* Block states (default storage) */
DW_stateEstimator_f_T stateEstimator_DW;

/*
 * Output and update for atomic system:
 *    '<S144>/SqrtUsedFcn'
 *    '<S200>/SqrtUsedFcn'
 */
void stateEstimator_SqrtUsedFcn(const real32_T rtu_u[4], boolean_T
  rtu_isSqrtUsed)
{
  /* local block i/o variables */
  real32_T rtb_P_b[4];
  int32_T i;
  real32_T rtb_P_b_tmp;

  /* MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S145>:1' */
  /* '<S145>:1:4' if isSqrtUsed */
  if (rtu_isSqrtUsed) {
    /* '<S145>:1:5' P = u*u.'; */
    for (i = 0; i < 2; i++) {
      rtb_P_b_tmp = rtu_u[i + 2];
      rtb_P_b[i] = rtb_P_b_tmp * rtu_u[2] + rtu_u[i] * rtu_u[0];
      rtb_P_b[i + 2] = rtb_P_b_tmp * rtu_u[3] + rtu_u[i] * rtu_u[1];
    }
  } else {
    /* '<S145>:1:6' else */
    /* '<S145>:1:7' P = u; */
    rtb_P_b[0] = rtu_u[0];
    rtb_P_b[1] = rtu_u[1];
    rtb_P_b[2] = rtu_u[2];
    rtb_P_b[3] = rtu_u[3];
  }
}

/*
 * System initialize for enable system:
 *    '<S115>/MeasurementUpdate'
 *    '<S171>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate_Init(B_MeasurementUpdate_stateEstimator_T *
  localB)
{
  /* SystemInitialize for Product: '<S146>/Product3' incorporates:
   *  Outport: '<S146>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = 0.0F;
  localB->Product3[1] = 0.0F;
}

/*
 * Disable for enable system:
 *    '<S115>/MeasurementUpdate'
 *    '<S171>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate_Disable
  (B_MeasurementUpdate_stateEstimator_T *localB,
   DW_MeasurementUpdate_stateEstimator_T *localDW)
{
  /* Disable for Product: '<S146>/Product3' incorporates:
   *  Outport: '<S146>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = 0.0F;
  localB->Product3[1] = 0.0F;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S115>/MeasurementUpdate'
 *    '<S171>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[4], const real32_T rtu_yk[2], const real32_T rtu_Ck[4], const real32_T
  rtu_xhatkk1[2], const real32_T rtu_Dk[4], const real32_T rtu_uk[2],
  B_MeasurementUpdate_stateEstimator_T *localB,
  DW_MeasurementUpdate_stateEstimator_T *localDW)
{
  real32_T rtu_yk_idx_0;
  real32_T rtu_yk_idx_1;

  /* Outputs for Enabled SubSystem: '<S115>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S146>/Enable'
   */
  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;

    /* Sum: '<S146>/Sum' incorporates:
     *  Product: '<S146>/C[k]*xhat[k|k-1]'
     *  Product: '<S146>/D[k]*u[k]'
     *  Sum: '<S146>/Add1'
     */
    rtu_yk_idx_0 = rtu_yk[0] - ((rtu_Ck[0] * rtu_xhatkk1[0] + rtu_xhatkk1[1] *
      rtu_Ck[2]) + (rtu_Dk[0] * rtu_uk[0] + rtu_uk[1] * rtu_Dk[2]));
    rtu_yk_idx_1 = rtu_yk[1] - ((rtu_xhatkk1[0] * rtu_Ck[1] + rtu_xhatkk1[1] *
      rtu_Ck[3]) + (rtu_uk[0] * rtu_Dk[1] + rtu_uk[1] * rtu_Dk[3]));

    /* Product: '<S146>/Product3' */
    localB->Product3[0] = rtu_Lk[0] * rtu_yk_idx_0 + rtu_Lk[2] * rtu_yk_idx_1;
    localB->Product3[1] = rtu_Lk[1] * rtu_yk_idx_0 + rtu_Lk[3] * rtu_yk_idx_1;
  } else if (localDW->MeasurementUpdate_MODE) {
    stateEstimator_MeasurementUpdate_Disable(localB, localDW);
  }

  /* End of Outputs for SubSystem: '<S115>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S122>/Enabled Subsystem'
 *    '<S178>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem_Init(B_EnabledSubsystem_stateEstimator_T
  *localB)
{
  /* SystemInitialize for Product: '<S148>/Product2' incorporates:
   *  Outport: '<S148>/deltax'
   */
  localB->Product2[0] = 0.0F;
  localB->Product2[1] = 0.0F;
}

/*
 * Disable for enable system:
 *    '<S122>/Enabled Subsystem'
 *    '<S178>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem_Disable(B_EnabledSubsystem_stateEstimator_T
  *localB, DW_EnabledSubsystem_stateEstimator_T *localDW)
{
  /* Disable for Product: '<S148>/Product2' incorporates:
   *  Outport: '<S148>/deltax'
   */
  localB->Product2[0] = 0.0F;
  localB->Product2[1] = 0.0F;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S122>/Enabled Subsystem'
 *    '<S178>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[4], const real32_T rtu_Ck[4], const real32_T rtu_yk[2], const real32_T
  rtu_xhatkk1[2], B_EnabledSubsystem_stateEstimator_T *localB,
  DW_EnabledSubsystem_stateEstimator_T *localDW)
{
  real32_T rtu_yk_idx_0;
  real32_T rtu_yk_idx_1;

  /* Outputs for Enabled SubSystem: '<S122>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S148>/Enable'
   */
  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S148>/Add1' incorporates:
     *  Product: '<S148>/Product'
     */
    rtu_yk_idx_0 = rtu_yk[0] - (rtu_Ck[0] * rtu_xhatkk1[0] + rtu_xhatkk1[1] *
      rtu_Ck[2]);
    rtu_yk_idx_1 = rtu_yk[1] - (rtu_xhatkk1[0] * rtu_Ck[1] + rtu_xhatkk1[1] *
      rtu_Ck[3]);

    /* Product: '<S148>/Product2' */
    localB->Product2[0] = rtu_Mk[0] * rtu_yk_idx_0 + rtu_Mk[2] * rtu_yk_idx_1;
    localB->Product2[1] = rtu_Mk[1] * rtu_yk_idx_0 + rtu_Mk[3] * rtu_yk_idx_1;
  } else if (localDW->EnabledSubsystem_MODE) {
    stateEstimator_EnabledSubsystem_Disable(localB, localDW);
  }

  /* End of Outputs for SubSystem: '<S122>/Enabled Subsystem' */
}

/* System initialize for referenced model: 'stateEstimator' */
void stateEstimator_Init(void)
{
  int32_T i;

  /* InitializeConditions for Delay: '<S149>/MemoryX' */
  stateEstimator_DW.icLoad = true;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  stateEstimator_DW.Memory_PreviousInput[0] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[1] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    stateEstimator_DW.IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */

  /* InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */
  stateEstimator_DW.FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    stateEstimator_DW.FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S75>/Delay' */
  stateEstimator_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Integrator' */
  stateEstimator_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S75>/Delay' */
  stateEstimator_DW.Delay_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Integrator' */
  stateEstimator_DW.Integrator_DSTATE[1] = 0.0F;
  stateEstimator_DW.Integrator_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  stateEstimator_DW.Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = true;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[0] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[0] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[1] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[2] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[2] = 0.0F;

  /* InitializeConditions for Delay: '<S78>/MemoryX' */
  stateEstimator_DW.icLoad_i = true;

  /* InitializeConditions for DiscreteFilter: '<S77>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    stateEstimator_DW.IIRgyroz_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S77>/IIRgyroz' */

  /* InitializeConditions for UnitDelay: '<S84>/UD' */
  stateEstimator_DW.UD_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S74>/Delay' */
  stateEstimator_DW.Delay_DSTATE_g[0] = 0.0F;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  stateEstimator_DW.Delay_DSTATE_p[0] = 0.0F;

  /* SystemInitialize for Merge: '<S2>/Merge' */
  stateEstimator_B.Merge[0] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S84>/UD' */
  stateEstimator_DW.UD_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S74>/Delay' */
  stateEstimator_DW.Delay_DSTATE_g[1] = 0.0F;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  stateEstimator_DW.Delay_DSTATE_p[1] = 0.0F;

  /* SystemInitialize for Merge: '<S2>/Merge' */
  stateEstimator_B.Merge[1] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S178>/Enabled Subsystem' */
  stateEstimator_EnabledSubsystem_Init(&stateEstimator_B.EnabledSubsystem_m);

  /* End of SystemInitialize for SubSystem: '<S178>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S42>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S68>/Product2' incorporates:
   *  Outport: '<S68>/deltax'
   */
  stateEstimator_B.Product2[0] = 0.0;
  stateEstimator_B.Product2[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S42>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S122>/Enabled Subsystem' */
  stateEstimator_EnabledSubsystem_Init(&stateEstimator_B.EnabledSubsystem_f);

  /* End of SystemInitialize for SubSystem: '<S122>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S36>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S66>/Product3' incorporates:
   *  Outport: '<S66>/L*(y[k]-yhat[k|k-1])'
   */
  stateEstimator_B.Product3[0] = 0.0;
  stateEstimator_B.Product3[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S36>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S115>/MeasurementUpdate' */
  stateEstimator_MeasurementUpdate_Init(&stateEstimator_B.MeasurementUpdate_e);

  /* End of SystemInitialize for SubSystem: '<S115>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S171>/MeasurementUpdate' */
  stateEstimator_MeasurementUpdate_Init(&stateEstimator_B.MeasurementUpdate_b);

  /* End of SystemInitialize for SubSystem: '<S171>/MeasurementUpdate' */
}

/* System reset for referenced model: 'stateEstimator' */
void stateEstimator_Reset(void)
{
  int32_T i;

  /* InitializeConditions for Delay: '<S149>/MemoryX' */
  stateEstimator_DW.icLoad = true;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  stateEstimator_DW.Memory_PreviousInput[0] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[1] = 0.0F;
  stateEstimator_DW.Memory_PreviousInput[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    stateEstimator_DW.IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */

  /* InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */
  stateEstimator_DW.FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    stateEstimator_DW.FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S5>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S75>/Delay' */
  stateEstimator_DW.Delay_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Integrator' */
  stateEstimator_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S75>/Delay' */
  stateEstimator_DW.Delay_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Integrator' */
  stateEstimator_DW.Integrator_DSTATE[1] = 0.0F;
  stateEstimator_DW.Integrator_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  stateEstimator_DW.Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = true;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[0] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[0] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[1] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[2] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[2] = 0.0F;

  /* InitializeConditions for Delay: '<S78>/MemoryX' */
  stateEstimator_DW.icLoad_i = true;

  /* InitializeConditions for DiscreteFilter: '<S77>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    stateEstimator_DW.IIRgyroz_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S77>/IIRgyroz' */

  /* InitializeConditions for UnitDelay: '<S84>/UD' */
  stateEstimator_DW.UD_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S74>/Delay' */
  stateEstimator_DW.Delay_DSTATE_g[0] = 0.0F;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  stateEstimator_DW.Delay_DSTATE_p[0] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S84>/UD' */
  stateEstimator_DW.UD_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S74>/Delay' */
  stateEstimator_DW.Delay_DSTATE_g[1] = 0.0F;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  stateEstimator_DW.Delay_DSTATE_p[1] = 0.0F;
}

/* Disable for referenced model: 'stateEstimator' */
void stateEstimator_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S178>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_m.EnabledSubsystem_MODE) {
    stateEstimator_EnabledSubsystem_Disable(&stateEstimator_B.EnabledSubsystem_m,
      &stateEstimator_DW.EnabledSubsystem_m);
  }

  /* End of Disable for SubSystem: '<S178>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S42>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_MODE) {
    /* Disable for Product: '<S68>/Product2' incorporates:
     *  Outport: '<S68>/deltax'
     */
    stateEstimator_B.Product2[0] = 0.0;
    stateEstimator_B.Product2[1] = 0.0;
    stateEstimator_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Disable for SubSystem: '<S42>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S122>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_f.EnabledSubsystem_MODE) {
    stateEstimator_EnabledSubsystem_Disable(&stateEstimator_B.EnabledSubsystem_f,
      &stateEstimator_DW.EnabledSubsystem_f);
  }

  /* End of Disable for SubSystem: '<S122>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S36>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S66>/Product3' incorporates:
     *  Outport: '<S66>/L*(y[k]-yhat[k|k-1])'
     */
    stateEstimator_B.Product3[0] = 0.0;
    stateEstimator_B.Product3[1] = 0.0;
    stateEstimator_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Disable for SubSystem: '<S36>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S115>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_e.MeasurementUpdate_MODE) {
    stateEstimator_MeasurementUpdate_Disable
      (&stateEstimator_B.MeasurementUpdate_e,
       &stateEstimator_DW.MeasurementUpdate_e);
  }

  /* End of Disable for SubSystem: '<S115>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S171>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_b.MeasurementUpdate_MODE) {
    stateEstimator_MeasurementUpdate_Disable
      (&stateEstimator_B.MeasurementUpdate_b,
       &stateEstimator_DW.MeasurementUpdate_b);
  }

  /* End of Disable for SubSystem: '<S171>/MeasurementUpdate' */
}

/* Output and update for referenced model: 'stateEstimator' */
void stateEstimator(const boolean_T *rtu_controlModePosVSOrient_flagin, const
                    sensordata_t *rtu_sensordata_datin, const real32_T
                    *rtu_usePosVIS_flagin, const real32_T rtu_opticalFlow_datin
                    [3], const real32_T rtu_posVIS_datin[4], const real32_T
                    rtu_sensorCalibration_datin[8], statesEstim_t
                    *rty_states_estimout)
{
  /* local block i/o variables */
  real_T rtb_P[4];
  real32_T rtb_Reshapey_a[2];
  real32_T rtb_MemoryX_f[2];
  real32_T rtb_Reshapey_o[2];
  real32_T rtb_MemoryX_m[2];
  real32_T rtb_Conversion_j[2];
  real32_T rtb_Reshapeu_h[2];
  real32_T rtb_Conversion_p[2];
  real32_T rtb_Reshapeu_i[2];
  boolean_T rtb_DataTypeConversionEnable;
  boolean_T rtb_DataTypeConversionEnable_i;
  real_T rtb_VectorConcatenate_h_0[3];
  real_T rtb_VectorConcatenate_h_1[3];
  real_T rtb_Add1_g;
  real_T rtb_Add_a_idx_0;
  real_T rtb_Add_a_idx_1;
  real_T rtb_Sum;
  real_T rtb_VectorConcatenate_h_tmp_1;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  int32_T denIdx;
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_VectorConcatenate_3[9];
  real32_T rtb_VectorConcatenate_h[9];
  real32_T rtb_VectorConcatenate_i[9];
  real32_T rtb_VectorConcatenate_p[9];
  real32_T rtb_Bias[6];
  real32_T rtb_FIR_IMUaccel[3];
  real32_T rtb_Product_n[3];
  real32_T rtb_Add_hi[2];
  real32_T rtb_Add_m[2];
  real32_T rtb_Diff[2];
  real32_T rtb_TSamp[2];
  real32_T LogicalOperator3_a_tmp;
  real32_T denAccum;
  real32_T rtb_DataTypeConversion2_i;
  real32_T rtb_MathFunction_idx_1;
  real32_T rtb_Merge1;
  real32_T rtb_Sqrt;
  real32_T rtb_TrigonometricFunction_o1_idx_0;
  real32_T rtb_TrigonometricFunction_o1_idx_1;
  real32_T rtb_TrigonometricFunction_o2_idx_0;
  real32_T rtb_TrigonometricFunction_o2_idx_1;
  real32_T rtb_UseIPPosSwitch_idx_1;
  real32_T rtb_VectorConcatenate_h_tmp;
  real32_T rtb_VectorConcatenate_h_tmp_0;
  real32_T rtb_sincos_o1_idx_2_tmp_tmp;
  real32_T rtb_sincos_o2_idx_2_tmp_tmp;
  boolean_T rtb_Compare_i;
  boolean_T rtb_LogicalOperator_cg;

  /* Reshape: '<S149>/Reshapey' */
  rtb_Reshapey_a[0] = rtu_posVIS_datin[0];
  rtb_Reshapey_a[1] = rtu_posVIS_datin[1];

  /* Delay: '<S149>/MemoryX' */
  if (stateEstimator_DW.icLoad) {
    stateEstimator_DW.MemoryX_DSTATE_d[0] = stateEstimator_ConstB.ReshapeX0_b[0];
    stateEstimator_DW.MemoryX_DSTATE_d[1] = stateEstimator_ConstB.ReshapeX0_b[1];
  }

  /* Delay: '<S149>/MemoryX' */
  rtb_MemoryX_f[0] = stateEstimator_DW.MemoryX_DSTATE_d[0];
  rtb_MemoryX_f[1] = stateEstimator_DW.MemoryX_DSTATE_d[1];

  /* SignalConversion generated from: '<S13>/Vector Concatenate' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_VectorConcatenate[0] = 0.0F;

  /* SignalConversion generated from: '<S13>/Vector Concatenate' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_VectorConcatenate[1] = 0.0F;

  /* Trigonometry: '<S12>/Trigonometric Function' incorporates:
   *  Memory: '<S2>/Memory'
   *  SignalConversion generated from: '<S12>/Trigonometric Function'
   */
  rtb_TrigonometricFunction_o1_idx_0 = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_TrigonometricFunction_o2_idx_0 = (real32_T)cos
    (stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_TrigonometricFunction_o1_idx_1 = (real32_T)sin
    (stateEstimator_DW.Memory_PreviousInput[1]);
  rtb_TrigonometricFunction_o2_idx_1 = (real32_T)cos
    (stateEstimator_DW.Memory_PreviousInput[1]);

  /* SignalConversion generated from: '<S13>/Vector Concatenate' */
  rtb_VectorConcatenate[2] = rtb_TrigonometricFunction_o2_idx_1;

  /* SignalConversion generated from: '<S13>/Vector Concatenate' */
  rtb_VectorConcatenate[3] = rtb_TrigonometricFunction_o1_idx_0;

  /* Product: '<S12>/Product1' */
  rtb_VectorConcatenate[4] = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_TrigonometricFunction_o2_idx_1;

  /* Product: '<S12>/Product3' */
  rtb_VectorConcatenate[5] = rtb_TrigonometricFunction_o1_idx_0 *
    rtb_TrigonometricFunction_o1_idx_1;

  /* SignalConversion generated from: '<S13>/Vector Concatenate' */
  rtb_VectorConcatenate[6] = rtb_TrigonometricFunction_o2_idx_0;

  /* Product: '<S12>/Product2' incorporates:
   *  Gain: '<S12>/Gain'
   */
  rtb_VectorConcatenate[7] = (-1.0F) * rtb_TrigonometricFunction_o1_idx_0 *
    rtb_TrigonometricFunction_o2_idx_1;

  /* Product: '<S12>/Product4' */
  rtb_VectorConcatenate[8] = rtb_TrigonometricFunction_o2_idx_0 *
    rtb_TrigonometricFunction_o1_idx_1;

  /* Bias: '<S5>/Bias' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  for (i_0 = 0; i_0 < 6; i_0++) {
    rtb_Bias[i_0] = rtu_sensorCalibration_datin[i_0] + rtCP_Bias_Bias[i_0];
  }

  /* End of Bias: '<S5>/Bias' */

  /* Gain: '<S5>/inverseIMU_gain' incorporates:
   *  Sum: '<S5>/Sum1'
   */
  stateEstimator_B.inverseIMU_gain[0] = (rtu_sensordata_datin->ddx - rtb_Bias[0])
    * 0.994075298F;
  stateEstimator_B.inverseIMU_gain[1] = (rtu_sensordata_datin->ddy - rtb_Bias[1])
    * 0.996184587F;
  stateEstimator_B.inverseIMU_gain[2] = (rtu_sensordata_datin->ddz - rtb_Bias[2])
    * 1.00549F;
  stateEstimator_B.inverseIMU_gain[3] = (rtu_sensordata_datin->p - rtb_Bias[3]) *
    1.00139189F;
  stateEstimator_B.inverseIMU_gain[4] = (rtu_sensordata_datin->q - rtb_Bias[4]) *
    0.993601203F;
  stateEstimator_B.inverseIMU_gain[5] = (rtu_sensordata_datin->r - rtb_Bias[5]) *
    1.00003F;

  /* DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  denAccum = stateEstimator_B.inverseIMU_gain[5];
  denIdx = 1;
  for (i = 0; i < 5; i++) {
    denAccum -= rtCP_IIR_IMUgyro_r_DenCoef[denIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[i];
    denIdx++;
  }

  stateEstimator_DW.IIR_IMUgyro_r_tmp = denAccum / 1.0F;
  denAccum = 0.282124132F * stateEstimator_DW.IIR_IMUgyro_r_tmp;
  denIdx = 1;
  for (i = 0; i < 5; i++) {
    denAccum += rtCP_IIR_IMUgyro_r_NumCoef[denIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[i];
    denIdx++;
  }

  /* SignalConversion generated from: '<S2>/Product' incorporates:
   *  DiscreteFilter: '<S5>/IIR_IMUgyro_r'
   */
  rtb_TrigonometricFunction_o1_idx_0 = stateEstimator_B.inverseIMU_gain[3];
  rtb_TrigonometricFunction_o1_idx_1 = stateEstimator_B.inverseIMU_gain[4];
  rtb_TrigonometricFunction_o2_idx_0 = denAccum;

  /* Product: '<S12>/Divide' incorporates:
   *  Reshape: '<S13>/Reshape (9) to [3x3] column-major'
   */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_3[i] = rtb_VectorConcatenate[i] /
      rtb_TrigonometricFunction_o2_idx_1;
  }

  /* End of Product: '<S12>/Divide' */

  /* Product: '<S2>/Product' incorporates:
   *  DiscreteFilter: '<S5>/IIR_IMUgyro_r'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product_n[i] = (rtb_VectorConcatenate_3[i + 3] *
                        rtb_TrigonometricFunction_o1_idx_1 +
                        rtb_VectorConcatenate_3[i] *
                        rtb_TrigonometricFunction_o1_idx_0) +
      rtb_VectorConcatenate_3[i + 6] * denAccum;
  }

  /* End of Product: '<S2>/Product' */

  /* If: '<S2>/If1' incorporates:
   *  Constant: '<S210>/Constant'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S210>/Compare'
   */
  if ((*rtu_usePosVIS_flagin != 0.0F) && (rtu_posVIS_datin[0] != (-99.0F))) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Sum: '<S9>/Sum' incorporates:
     *  Gain: '<S2>/gyro_sensitivity'
     *  Gain: '<S9>/Gain'
     *  Gain: '<S9>/Gain1'
     *  Memory: '<S2>/Memory'
     *  SignalConversion generated from: '<S12>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     */
    rtb_Merge1 = (0.005F * rtb_Product_n[0] +
                  stateEstimator_DW.Memory_PreviousInput[0]) * 0.8F + 0.2F *
      rtu_posVIS_datin[3];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* SignalConversion generated from: '<S11>/yawin' incorporates:
     *  Gain: '<S2>/gyro_sensitivity'
     *  Memory: '<S2>/Memory'
     *  SignalConversion generated from: '<S12>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     */
    rtb_Merge1 = 0.005F * rtb_Product_n[0] +
      stateEstimator_DW.Memory_PreviousInput[0];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
  }

  /* End of If: '<S2>/If1' */

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_TrigonometricFunction_o1_idx_1 = stateEstimator_B.inverseIMU_gain[0] *
    0.0264077242F;
  i_0 = 1;
  for (i = stateEstimator_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    rtb_TrigonometricFunction_o1_idx_1 +=
      stateEstimator_DW.FIR_IMUaccel_states[i] *
      rtCP_FIR_IMUaccel_Coefficients[i_0];
    i_0++;
  }

  for (i = 0; i < stateEstimator_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_TrigonometricFunction_o1_idx_1 +=
      stateEstimator_DW.FIR_IMUaccel_states[i] *
      rtCP_FIR_IMUaccel_Coefficients[i_0];
    i_0++;
  }

  rtb_FIR_IMUaccel[0] = rtb_TrigonometricFunction_o1_idx_1;

  /* Math: '<S2>/Math Function' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  rtb_TrigonometricFunction_o2_idx_1 = (real32_T)floor(2.0F);
  if ((rtb_TrigonometricFunction_o1_idx_1 < 0.0F) && (2.0F >
       rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_TrigonometricFunction_o1_idx_0 = -rt_powf_snf
      (-rtb_TrigonometricFunction_o1_idx_1, 2.0F);
  } else {
    rtb_TrigonometricFunction_o1_idx_0 = rt_powf_snf
      (rtb_TrigonometricFunction_o1_idx_1, 2.0F);
  }

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_TrigonometricFunction_o1_idx_1 = 0.0264077242F *
    stateEstimator_B.inverseIMU_gain[1];
  i_0 = 1;
  for (i = stateEstimator_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    rtb_TrigonometricFunction_o1_idx_1 +=
      stateEstimator_DW.FIR_IMUaccel_states[i + 5] *
      rtCP_FIR_IMUaccel_Coefficients[i_0];
    i_0++;
  }

  for (i = 0; i < stateEstimator_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_TrigonometricFunction_o1_idx_1 +=
      stateEstimator_DW.FIR_IMUaccel_states[i + 5] *
      rtCP_FIR_IMUaccel_Coefficients[i_0];
    i_0++;
  }

  rtb_FIR_IMUaccel[1] = rtb_TrigonometricFunction_o1_idx_1;

  /* Math: '<S2>/Math Function' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  if ((rtb_TrigonometricFunction_o1_idx_1 < 0.0F) && (2.0F >
       rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_MathFunction_idx_1 = -rt_powf_snf(-rtb_TrigonometricFunction_o1_idx_1,
      2.0F);
  } else {
    rtb_MathFunction_idx_1 = rt_powf_snf(rtb_TrigonometricFunction_o1_idx_1,
      2.0F);
  }

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_TrigonometricFunction_o1_idx_1 = 0.0264077242F *
    stateEstimator_B.inverseIMU_gain[2];
  i_0 = 1;
  for (i = stateEstimator_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    rtb_TrigonometricFunction_o1_idx_1 +=
      stateEstimator_DW.FIR_IMUaccel_states[i + 10] *
      rtCP_FIR_IMUaccel_Coefficients[i_0];
    i_0++;
  }

  for (i = 0; i < stateEstimator_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_TrigonometricFunction_o1_idx_1 +=
      stateEstimator_DW.FIR_IMUaccel_states[i + 10] *
      rtCP_FIR_IMUaccel_Coefficients[i_0];
    i_0++;
  }

  rtb_FIR_IMUaccel[2] = rtb_TrigonometricFunction_o1_idx_1;

  /* Math: '<S2>/Math Function' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  if ((rtb_TrigonometricFunction_o1_idx_1 < 0.0F) && (2.0F >
       rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_TrigonometricFunction_o2_idx_1 = -rt_powf_snf
      (-rtb_TrigonometricFunction_o1_idx_1, 2.0F);
  } else {
    rtb_TrigonometricFunction_o2_idx_1 = rt_powf_snf
      (rtb_TrigonometricFunction_o1_idx_1, 2.0F);
  }

  /* Sqrt: '<S2>/Sqrt' incorporates:
   *  Math: '<S2>/Math Function'
   *  Sum: '<S2>/Sum of Elements'
   */
  rtb_Sqrt = (real32_T)sqrt((rtb_TrigonometricFunction_o1_idx_0 +
    rtb_MathFunction_idx_1) + rtb_TrigonometricFunction_o2_idx_1);

  /* If: '<S2>/If' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Logic: '<S2>/Logical Operator'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  if ((rtb_Sqrt > 9.79038F) && (rtb_Sqrt < 9.82962F)) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  DiscreteFir: '<S5>/FIR_IMUaccel'
     *  Gain: '<S2>/gyro_sensitivity'
     *  Gain: '<S8>/Gain'
     *  Gain: '<S8>/Gain1'
     *  Memory: '<S2>/Memory'
     *  Merge: '<S2>/Merge'
     *  Product: '<S8>/Divide'
     *  SignalConversion generated from: '<S12>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function'
     */
    stateEstimator_B.Merge[1] = (0.005F * rtb_Product_n[2] +
      stateEstimator_DW.Memory_PreviousInput[2]) * 0.999F + (real32_T)atan
      (rtb_FIR_IMUaccel[1] / rtb_TrigonometricFunction_o1_idx_1) * 0.001F;

    /* Gain: '<S8>/Gain2' */
    rtb_UseIPPosSwitch_idx_1 = 0.101936802F * rtb_FIR_IMUaccel[0];

    /* Trigonometry: '<S8>/Trigonometric Function1' */
    if (rtb_UseIPPosSwitch_idx_1 > 1.0F) {
      rtb_UseIPPosSwitch_idx_1 = 1.0F;
    } else if (rtb_UseIPPosSwitch_idx_1 < -1.0F) {
      rtb_UseIPPosSwitch_idx_1 = -1.0F;
    }

    /* Sum: '<S8>/Sum1' incorporates:
     *  Gain: '<S2>/gyro_sensitivity'
     *  Gain: '<S8>/Gain3'
     *  Gain: '<S8>/Gain4'
     *  Memory: '<S2>/Memory'
     *  Merge: '<S2>/Merge'
     *  SignalConversion generated from: '<S12>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function1'
     */
    stateEstimator_B.Merge[0] = (0.005F * rtb_Product_n[1] +
      stateEstimator_DW.Memory_PreviousInput[1]) * 0.999F + 0.001F * (real32_T)
      asin(rtb_UseIPPosSwitch_idx_1);

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Gain: '<S2>/gyro_sensitivity'
     *  Memory: '<S2>/Memory'
     *  SignalConversion generated from: '<S10>/prin'
     *  SignalConversion generated from: '<S12>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     */
    stateEstimator_B.Merge[0] = 0.005F * rtb_Product_n[1] +
      stateEstimator_DW.Memory_PreviousInput[1];
    stateEstimator_B.Merge[1] = 0.005F * rtb_Product_n[2] +
      stateEstimator_DW.Memory_PreviousInput[2];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
  }

  /* End of If: '<S2>/If' */

  /* Sum: '<S150>/Add1' incorporates:
   *  Delay: '<S75>/Delay'
   */
  rtb_UseIPPosSwitch_idx_1 = rtu_posVIS_datin[0] -
    stateEstimator_DW.Delay_DSTATE[0];
  rtb_TrigonometricFunction_o1_idx_0 = rtu_posVIS_datin[1] -
    stateEstimator_DW.Delay_DSTATE[1];

  /* Abs: '<S150>/Abs' incorporates:
   *  Abs: '<S77>/Abs2'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  rtb_TrigonometricFunction_o1_idx_1 = (real32_T)fabs(stateEstimator_B.Merge[0]);

  /* Abs: '<S150>/Abs1' incorporates:
   *  Abs: '<S77>/Abs3'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  rtb_MathFunction_idx_1 = (real32_T)fabs(stateEstimator_B.Merge[1]);

  /* Math: '<S150>/Math Function' */
  rtb_TrigonometricFunction_o2_idx_1 = (real32_T)floor(2.0F);
  if ((rtb_UseIPPosSwitch_idx_1 < 0.0F) && (2.0F >
       rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_UseIPPosSwitch_idx_1 = -rt_powf_snf(-rtb_UseIPPosSwitch_idx_1, 2.0F);
  } else {
    rtb_UseIPPosSwitch_idx_1 = rt_powf_snf(rtb_UseIPPosSwitch_idx_1, 2.0F);
  }

  if ((rtb_TrigonometricFunction_o1_idx_0 < 0.0F) && (2.0F >
       rtb_TrigonometricFunction_o2_idx_1)) {
    rtb_TrigonometricFunction_o2_idx_1 = -rt_powf_snf
      (-rtb_TrigonometricFunction_o1_idx_0, 2.0F);
  } else {
    rtb_TrigonometricFunction_o2_idx_1 = rt_powf_snf
      (rtb_TrigonometricFunction_o1_idx_0, 2.0F);
  }

  /* Logic: '<S150>/Logical Operator3' incorporates:
   *  Abs: '<S150>/Abs'
   *  Abs: '<S150>/Abs1'
   *  Constant: '<S205>/Constant'
   *  Constant: '<S206>/Constant'
   *  Constant: '<S207>/Constant'
   *  Constant: '<S208>/Constant'
   *  Math: '<S150>/Math Function'
   *  RelationalOperator: '<S205>/Compare'
   *  RelationalOperator: '<S206>/Compare'
   *  RelationalOperator: '<S207>/Compare'
   *  RelationalOperator: '<S208>/Compare'
   *  Sqrt: '<S150>/Sqrt'
   *  Sum: '<S150>/Sum of Elements'
   */
  stateEstimator_B.LogicalOperator3 = ((rtb_TrigonometricFunction_o1_idx_1 <=
    0.18F) && (rtb_MathFunction_idx_1 <= 0.18F) && (rtu_posVIS_datin[0] !=
    (-99.0F)) && ((real32_T)sqrt(rtb_UseIPPosSwitch_idx_1 +
    rtb_TrigonometricFunction_o2_idx_1) < 1.0F));

  /* DataTypeConversion: '<S149>/DataTypeConversionEnable' */
  rtb_DataTypeConversionEnable = stateEstimator_B.LogicalOperator3;

  /* Outputs for Enabled SubSystem: '<S178>/Enabled Subsystem' */
  /* Constant: '<S149>/C' */
  stateEstimator_EnabledSubsystem(rtb_DataTypeConversionEnable,
    stateEstimator_ConstB.Conversion_g, rtCP_C_Value_p, rtb_Reshapey_a,
    rtb_MemoryX_f, &stateEstimator_B.EnabledSubsystem_m,
    &stateEstimator_DW.EnabledSubsystem_m);

  /* End of Outputs for SubSystem: '<S178>/Enabled Subsystem' */

  /* Sum: '<S178>/Add' */
  rtb_TrigonometricFunction_o2_idx_1 =
    stateEstimator_B.EnabledSubsystem_m.Product2[0] + rtb_MemoryX_f[0];
  rtb_TrigonometricFunction_o1_idx_0 =
    stateEstimator_B.EnabledSubsystem_m.Product2[1] + rtb_MemoryX_f[1];

  /* DiscreteIntegrator: '<S75>/Integrator' */
  if ((*rtu_controlModePosVSOrient_flagin) &&
      (stateEstimator_DW.Integrator_PrevResetState <= 0)) {
    stateEstimator_DW.Integrator_DSTATE[0] = 0.0F;
    stateEstimator_DW.Integrator_DSTATE[1] = 0.0F;
  }

  /* Switch: '<S75>/UseIPPosSwitch' incorporates:
   *  DiscreteIntegrator: '<S75>/Integrator'
   *  Reshape: '<S149>/Reshapexhat'
   */
  if (*rtu_usePosVIS_flagin > 0.0F) {
    /* BusCreator generated from: '<Root>/states_estimout' incorporates:
     *  Reshape: '<S149>/Reshapexhat'
     */
    rty_states_estimout->X = rtb_TrigonometricFunction_o2_idx_1;
    rtb_UseIPPosSwitch_idx_1 = rtb_TrigonometricFunction_o1_idx_0;
  } else {
    /* BusCreator generated from: '<Root>/states_estimout' incorporates:
     *  DiscreteIntegrator: '<S75>/Integrator'
     */
    rty_states_estimout->X = stateEstimator_DW.Integrator_DSTATE[0];
    rtb_UseIPPosSwitch_idx_1 = stateEstimator_DW.Integrator_DSTATE[1];
  }

  /* End of Switch: '<S75>/UseIPPosSwitch' */

  /* Gain: '<S3>/invertzaxisGain' */
  stateEstimator_B.invertzaxisGain = (real_T)(-1.0F) *
    rtu_sensordata_datin->altitude_sonar;

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  Constant: '<S17>/Constant'
   *  Delay: '<S3>/Delay2'
   */
  stateEstimator_B.Compare = (stateEstimator_DW.Delay2_DSTATE > 0.0);

  /* Delay: '<S14>/MemoryX' incorporates:
   *  DataTypeConversion: '<S14>/DataTypeConversionReset'
   */
  stateEstimator_DW.icLoad_p = (stateEstimator_B.Compare ||
    stateEstimator_DW.icLoad_p);
  if (stateEstimator_DW.icLoad_p) {
    stateEstimator_DW.MemoryX_DSTATE[0] = stateEstimator_ConstB.ReshapeX0[0];
    stateEstimator_DW.MemoryX_DSTATE[1] = stateEstimator_ConstB.ReshapeX0[1];
  }

  /* DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_tmp = (((stateEstimator_B.invertzaxisGain -
    stateEstimator_DW.soonarFilter_IIR_states[0] * (-2.9371707284498907)) -
    stateEstimator_DW.soonarFilter_IIR_states[1] * 2.8762997234793319) -
    stateEstimator_DW.soonarFilter_IIR_states[2] * (-0.939098940325283)) / 1.0;

  /* DiscreteFilter: '<S15>/pressureFilter_IIR' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S3>/prsToAltGain'
   *  Sum: '<S5>/Sum2'
   */
  stateEstimator_DW.pressureFilter_IIR_tmp = ((((rtu_sensordata_datin->prs -
    rtu_sensorCalibration_datin[6]) * 0.0832137167F -
    stateEstimator_DW.pressureFilter_IIR_states[0] * (-2.93717074F)) -
    stateEstimator_DW.pressureFilter_IIR_states[1] * 2.87629962F) -
    stateEstimator_DW.pressureFilter_IIR_states[2] * (-0.939098954F)) / 1.0F;

  /* Saturate: '<S15>/SaturationSonar' */
  if ((stateEstimator_B.invertzaxisGain >= (-0.44)) || rtIsNaN(-0.44)) {
    rtb_Add_a_idx_0 = (-0.44);
  } else {
    rtb_Add_a_idx_0 = stateEstimator_B.invertzaxisGain;
  }

  /* Logic: '<S15>/nicemeasurementor newupdateneeded' incorporates:
   *  Abs: '<S15>/Absestdiff'
   *  Abs: '<S15>/Absestdiff1'
   *  Abs: '<S15>/Absestdiff2'
   *  Constant: '<S69>/Constant'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S71>/Constant'
   *  Constant: '<S72>/Constant'
   *  Delay: '<S3>/Delay2'
   *  DiscreteFilter: '<S15>/pressureFilter_IIR'
   *  DiscreteFilter: '<S15>/soonarFilter_IIR'
   *  Logic: '<S15>/findingoutliers'
   *  Logic: '<S15>/newupdateneeded'
   *  RelationalOperator: '<S69>/Compare'
   *  RelationalOperator: '<S70>/Compare'
   *  RelationalOperator: '<S71>/Compare'
   *  RelationalOperator: '<S72>/Compare'
   *  Saturate: '<S15>/SaturationSonar'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Add1'
   *  Sum: '<S15>/Add2'
   */
  stateEstimator_B.nicemeasurementornewupdateneeded = (((fabs
    (stateEstimator_DW.Delay2_DSTATE - rtb_Add_a_idx_0) <= 0.3) &&
    (stateEstimator_B.invertzaxisGain < (-0.44))) || ((fabs
    ((((3.7568380197512489E-6 * stateEstimator_DW.soonarFilter_IIR_tmp +
        stateEstimator_DW.soonarFilter_IIR_states[0] * 1.1270514059253748E-5) +
       stateEstimator_DW.soonarFilter_IIR_states[1] * 1.1270514059253748E-5) +
      stateEstimator_DW.soonarFilter_IIR_states[2] * 3.7568380197512489E-6) -
     stateEstimator_DW.Delay2_DSTATE) >= 0.4) && (fabs((((3.75683794E-6F *
    stateEstimator_DW.pressureFilter_IIR_tmp +
    stateEstimator_DW.pressureFilter_IIR_states[0] * 1.12705138E-5F) +
    stateEstimator_DW.pressureFilter_IIR_states[1] * 1.12705138E-5F) +
    stateEstimator_DW.pressureFilter_IIR_states[2] * 3.75683794E-6F) -
    stateEstimator_DW.Delay2_DSTATE) >= 0.8)));

  /* Outputs for Enabled SubSystem: '<S42>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S68>/Enable'
   */
  /* DataTypeConversion: '<S14>/DataTypeConversionEnable' */
  if (stateEstimator_B.nicemeasurementornewupdateneeded) {
    stateEstimator_DW.EnabledSubsystem_MODE = true;

    /* Sum: '<S68>/Add1' incorporates:
     *  Constant: '<S14>/C'
     *  Delay: '<S14>/MemoryX'
     *  Product: '<S68>/Product'
     *  Reshape: '<S14>/Reshapey'
     */
    rtb_Add1_g = stateEstimator_B.invertzaxisGain - (1.0 *
      stateEstimator_DW.MemoryX_DSTATE[0] + 0.0 *
      stateEstimator_DW.MemoryX_DSTATE[1]);

    /* Product: '<S68>/Product2' incorporates:
     *  DataTypeConversion: '<S59>/Conversion'
     */
    stateEstimator_B.Product2[0] = stateEstimator_ConstB.Conversion_i[0] *
      rtb_Add1_g;
    stateEstimator_B.Product2[1] = stateEstimator_ConstB.Conversion_i[1] *
      rtb_Add1_g;
  } else if (stateEstimator_DW.EnabledSubsystem_MODE) {
    /* Disable for Product: '<S68>/Product2' incorporates:
     *  Outport: '<S68>/deltax'
     */
    stateEstimator_B.Product2[0] = 0.0;
    stateEstimator_B.Product2[1] = 0.0;
    stateEstimator_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S42>/Enabled Subsystem' */

  /* Sum: '<S42>/Add' incorporates:
   *  Delay: '<S14>/MemoryX'
   */
  rtb_Add_a_idx_0 = stateEstimator_B.Product2[0] +
    stateEstimator_DW.MemoryX_DSTATE[0];
  rtb_Add_a_idx_1 = stateEstimator_B.Product2[1] +
    stateEstimator_DW.MemoryX_DSTATE[1];

  /* Gain: '<S74>/opticalFlowToVelocity_gain' */
  stateEstimator_B.opticalFlowToVelocity_gain[0] = 1.0F * rtu_opticalFlow_datin
    [0];
  stateEstimator_B.opticalFlowToVelocity_gain[1] = 1.0F * rtu_opticalFlow_datin
    [1];
  stateEstimator_B.opticalFlowToVelocity_gain[2] = 1.0F * rtu_opticalFlow_datin
    [2];

  /* Reshape: '<S78>/Reshapey' */
  rtb_Reshapey_o[0] = stateEstimator_B.opticalFlowToVelocity_gain[0];
  rtb_Reshapey_o[1] = stateEstimator_B.opticalFlowToVelocity_gain[1];

  /* Delay: '<S78>/MemoryX' */
  if (stateEstimator_DW.icLoad_i) {
    stateEstimator_DW.MemoryX_DSTATE_d5[0] = stateEstimator_ConstB.ReshapeX0_k[0];
    stateEstimator_DW.MemoryX_DSTATE_d5[1] = stateEstimator_ConstB.ReshapeX0_k[1];
  }

  /* Delay: '<S78>/MemoryX' */
  rtb_MemoryX_m[0] = stateEstimator_DW.MemoryX_DSTATE_d5[0];
  rtb_MemoryX_m[1] = stateEstimator_DW.MemoryX_DSTATE_d5[1];
  for (i_0 = 0; i_0 < 2; i_0++) {
    /* DiscreteFilter: '<S77>/IIRgyroz' */
    tmp = i_0 * 5;
    denAccum = stateEstimator_B.inverseIMU_gain[i_0 + 3];
    denIdx = 1;
    for (i = 0; i < 5; i++) {
      denAccum -= stateEstimator_DW.IIRgyroz_states[tmp + i] *
        rtCP_IIRgyroz_DenCoef[denIdx];
      denIdx++;
    }

    denAccum /= 1.0F;
    stateEstimator_DW.IIRgyroz_tmp[i_0] = denAccum;
    denAccum *= 0.282124132F;
    denIdx = 1;
    for (i = 0; i < 5; i++) {
      denAccum += stateEstimator_DW.IIRgyroz_states[tmp + i] *
        rtCP_IIRgyroz_NumCoef[denIdx];
      denIdx++;
    }

    /* SampleTimeMath: '<S84>/TSamp' incorporates:
     *  DiscreteFilter: '<S77>/IIRgyroz'
     *
     * About '<S84>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    denAccum *= 200.0F;
    rtb_TSamp[i_0] = denAccum;

    /* Sum: '<S84>/Diff' incorporates:
     *  UnitDelay: '<S84>/UD'
     */
    rtb_Diff[i_0] = denAccum - stateEstimator_DW.UD_DSTATE[i_0];

    /* Sum: '<S77>/Add' incorporates:
     *  Delay: '<S74>/Delay'
     */
    rtb_Add_hi[i_0] = stateEstimator_B.opticalFlowToVelocity_gain[i_0] -
      stateEstimator_DW.Delay_DSTATE_g[i_0];
  }

  /* Abs: '<S77>/Abs' incorporates:
   *  Abs: '<S77>/Abs4'
   */
  denAccum = (real32_T)fabs(stateEstimator_B.inverseIMU_gain[3]);

  /* Abs: '<S77>/Abs1' incorporates:
   *  Abs: '<S77>/Abs5'
   */
  LogicalOperator3_a_tmp = (real32_T)fabs(stateEstimator_B.inverseIMU_gain[4]);

  /* Logic: '<S77>/Logical Operator3' incorporates:
   *  Abs: '<S77>/Abs'
   *  Abs: '<S77>/Abs1'
   *  Abs: '<S77>/Abs6'
   *  Abs: '<S77>/Abs7'
   *  Abs: '<S77>/Abs8'
   *  Abs: '<S77>/Abs9'
   *  Constant: '<S85>/Constant'
   *  Constant: '<S86>/Constant'
   *  Constant: '<S87>/Constant'
   *  Constant: '<S88>/Constant'
   *  Constant: '<S89>/Constant'
   *  Constant: '<S90>/Constant'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Constant'
   *  Constant: '<S95>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Logic: '<S77>/Logical Operator'
   *  Logic: '<S77>/Logical Operator1'
   *  Logic: '<S77>/Logical Operator2'
   *  RelationalOperator: '<S85>/Compare'
   *  RelationalOperator: '<S86>/Compare'
   *  RelationalOperator: '<S87>/Compare'
   *  RelationalOperator: '<S88>/Compare'
   *  RelationalOperator: '<S89>/Compare'
   *  RelationalOperator: '<S90>/Compare'
   *  RelationalOperator: '<S91>/Compare'
   *  RelationalOperator: '<S92>/Compare'
   *  RelationalOperator: '<S93>/Compare'
   *  RelationalOperator: '<S94>/Compare'
   *  RelationalOperator: '<S95>/Compare'
   *  Reshape: '<S14>/Reshapexhat'
   */
  stateEstimator_B.LogicalOperator3_a = ((((rtb_TrigonometricFunction_o1_idx_1 <=
    0.6F) && (rtb_MathFunction_idx_1 <= 0.6F) && (denAccum <= 7.0F) &&
    (LogicalOperator3_a_tmp <= 7.0F) && ((real32_T)fabs(rtb_Diff[0]) <= 80.0F) &&
    ((real32_T)fabs(rtb_Diff[1]) <= 80.0F)) || ((denAccum <= 0.5F) &&
    (LogicalOperator3_a_tmp <= 0.5F))) && ((real32_T)fabs(rtb_Add_hi[0]) <= 5.0F)
    && ((real32_T)fabs(rtb_Add_hi[1]) <= 5.0F) && ((real32_T)rtb_Add_a_idx_0 <=
    (-0.4F)));

  /* DataTypeConversion: '<S78>/DataTypeConversionEnable' */
  rtb_DataTypeConversionEnable_i = stateEstimator_B.LogicalOperator3_a;

  /* Outputs for Enabled SubSystem: '<S122>/Enabled Subsystem' */
  /* Constant: '<S78>/C' */
  stateEstimator_EnabledSubsystem(rtb_DataTypeConversionEnable_i,
    stateEstimator_ConstB.Conversion_p, rtCP_C_Value_f, rtb_Reshapey_o,
    rtb_MemoryX_m, &stateEstimator_B.EnabledSubsystem_f,
    &stateEstimator_DW.EnabledSubsystem_f);

  /* End of Outputs for SubSystem: '<S122>/Enabled Subsystem' */

  /* Sum: '<S122>/Add' */
  rtb_Add_m[0] = stateEstimator_B.EnabledSubsystem_f.Product2[0] +
    rtb_MemoryX_m[0];
  rtb_Add_m[1] = stateEstimator_B.EnabledSubsystem_f.Product2[1] +
    rtb_MemoryX_m[1];

  /* Trigonometry: '<S16>/sincos' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  Trigonometry: '<S151>/sincos'
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_TrigonometricFunction_o1_idx_1 = (real32_T)sin(rtb_Merge1);
  rtb_MathFunction_idx_1 = (real32_T)cos(rtb_Merge1);
  denAccum = (real32_T)sin(stateEstimator_B.Merge[0]);
  LogicalOperator3_a_tmp = (real32_T)cos(stateEstimator_B.Merge[0]);
  rtb_sincos_o1_idx_2_tmp_tmp = (real32_T)sin(stateEstimator_B.Merge[1]);
  rtb_sincos_o2_idx_2_tmp_tmp = (real32_T)cos(stateEstimator_B.Merge[1]);

  /* Fcn: '<S16>/Fcn11' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[0] = rtb_MathFunction_idx_1 * LogicalOperator3_a_tmp;

  /* Fcn: '<S16>/Fcn21' incorporates:
   *  Fcn: '<S16>/Fcn22'
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_h_tmp = denAccum * rtb_sincos_o1_idx_2_tmp_tmp;
  rtb_VectorConcatenate_i[1] = rtb_VectorConcatenate_h_tmp *
    rtb_MathFunction_idx_1 - rtb_TrigonometricFunction_o1_idx_1 *
    rtb_sincos_o2_idx_2_tmp_tmp;

  /* Fcn: '<S16>/Fcn31' incorporates:
   *  Fcn: '<S16>/Fcn32'
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_h_tmp_0 = denAccum * rtb_sincos_o2_idx_2_tmp_tmp;
  rtb_VectorConcatenate_i[2] = rtb_VectorConcatenate_h_tmp_0 *
    rtb_MathFunction_idx_1 + rtb_TrigonometricFunction_o1_idx_1 *
    rtb_sincos_o1_idx_2_tmp_tmp;

  /* Fcn: '<S16>/Fcn12' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[3] = rtb_TrigonometricFunction_o1_idx_1 *
    LogicalOperator3_a_tmp;

  /* Fcn: '<S16>/Fcn22' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[4] = rtb_VectorConcatenate_h_tmp *
    rtb_TrigonometricFunction_o1_idx_1 + rtb_MathFunction_idx_1 *
    rtb_sincos_o2_idx_2_tmp_tmp;

  /* Fcn: '<S16>/Fcn32' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[5] = rtb_VectorConcatenate_h_tmp_0 *
    rtb_TrigonometricFunction_o1_idx_1 - rtb_MathFunction_idx_1 *
    rtb_sincos_o1_idx_2_tmp_tmp;

  /* Fcn: '<S16>/Fcn13' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[6] = -denAccum;

  /* Fcn: '<S16>/Fcn23' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[7] = LogicalOperator3_a_tmp *
    rtb_sincos_o1_idx_2_tmp_tmp;

  /* Fcn: '<S16>/Fcn33' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_i[8] = LogicalOperator3_a_tmp *
    rtb_sincos_o2_idx_2_tmp_tmp;

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Delay: '<S1>/Delay'
   */
  tmp_0 = stateEstimator_DW.Delay_DSTATE_p[0];
  tmp_2 = stateEstimator_DW.Delay_DSTATE_p[1];

  /* BusCreator generated from: '<Root>/states_estimout' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Reshape: '<S14>/Reshapexhat'
   *  Reshape: '<S78>/Reshapexhat'
   */
  rty_states_estimout->Y = rtb_UseIPPosSwitch_idx_1;
  rty_states_estimout->Z = (real32_T)rtb_Add_a_idx_0;
  rty_states_estimout->yaw = rtb_Merge1;
  rty_states_estimout->pitch = stateEstimator_B.Merge[0];
  rty_states_estimout->roll = stateEstimator_B.Merge[1];
  rty_states_estimout->dx = rtb_Add_m[0];
  rty_states_estimout->dy = rtb_Add_m[1];

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Delay: '<S1>/Delay'
   */
  tmp_1 = stateEstimator_DW.Delay_DSTATE_p[0];
  tmp_3 = stateEstimator_DW.Delay_DSTATE_p[1];

  /* Product: '<S3>/Product1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Reshape: '<S14>/Reshapexhat'
   *  Reshape: '<S73>/Reshape (9) to [3x3] column-major'
   *  SignalConversion generated from: '<S3>/Product1'
   */
  for (i = 0; i < 3; i++) {
    rtb_UseIPPosSwitch_idx_1 = rtb_VectorConcatenate_i[i + 3];
    denAccum = rtb_VectorConcatenate_i[i];
    rtb_VectorConcatenate_h_tmp_1 = rtb_VectorConcatenate_i[i + 6] *
      rtb_Add_a_idx_1;
    rtb_VectorConcatenate_h_0[i] = (rtb_UseIPPosSwitch_idx_1 * tmp_2 + denAccum *
      tmp_0) + rtb_VectorConcatenate_h_tmp_1;
    rtb_VectorConcatenate_h_1[i] = (rtb_UseIPPosSwitch_idx_1 * tmp_3 + denAccum *
      tmp_1) + rtb_VectorConcatenate_h_tmp_1;
  }

  /* End of Product: '<S3>/Product1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  rtb_DataTypeConversion2_i = (real32_T)rtb_VectorConcatenate_h_0[2];

  /* BusCreator generated from: '<Root>/states_estimout' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  SignalConversion generated from: '<S2>/Product'
   */
  rty_states_estimout->dz = (real32_T)rtb_VectorConcatenate_h_1[2];
  rty_states_estimout->p = stateEstimator_B.inverseIMU_gain[3];
  rty_states_estimout->q = stateEstimator_B.inverseIMU_gain[4];
  rty_states_estimout->r = rtb_TrigonometricFunction_o2_idx_0;

  /* MATLAB Function: '<S64>/SqrtUsedFcn' incorporates:
   *  Constant: '<S64>/isSqrtUsed'
   *  DataTypeConversion: '<S61>/Conversion'
   */
  /* MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S65>:1' */
  /* '<S65>:1:4' if isSqrtUsed */
  if (false) {
    /* '<S65>:1:5' P = u*u.'; */
    for (i = 0; i < 2; i++) {
      rtb_Add_a_idx_1 = stateEstimator_ConstB.Conversion_c[i + 2];
      rtb_P[i] = rtb_Add_a_idx_1 * stateEstimator_ConstB.Conversion_c[2] +
        stateEstimator_ConstB.Conversion_c[i] *
        stateEstimator_ConstB.Conversion_c[0];
      rtb_P[i + 2] = rtb_Add_a_idx_1 * stateEstimator_ConstB.Conversion_c[3] +
        stateEstimator_ConstB.Conversion_c[i] *
        stateEstimator_ConstB.Conversion_c[1];
    }
  } else {
    /* '<S65>:1:6' else */
    /* '<S65>:1:7' P = u; */
    rtb_P[0] = stateEstimator_ConstB.Conversion_c[0];
    rtb_P[1] = stateEstimator_ConstB.Conversion_c[1];
    rtb_P[2] = stateEstimator_ConstB.Conversion_c[2];
    rtb_P[3] = stateEstimator_ConstB.Conversion_c[3];
  }

  /* End of MATLAB Function: '<S64>/SqrtUsedFcn' */

  /* Product: '<S3>/Product' incorporates:
   *  Math: '<S3>/Math Function'
   */
  rtb_TrigonometricFunction_o2_idx_0 = rtb_FIR_IMUaccel[1];
  rtb_UseIPPosSwitch_idx_1 = rtb_FIR_IMUaccel[0];
  denAccum = rtb_FIR_IMUaccel[2];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     *  Math: '<S3>/Math Function'
     *  Product: '<S3>/Product'
     *  Reshape: '<S73>/Reshape (9) to [3x3] column-major'
     */
    stateEstimator_B.Sum[i] = ((rtb_VectorConcatenate_i[3 * i + 1] *
      rtb_TrigonometricFunction_o2_idx_0 + rtb_VectorConcatenate_i[3 * i] *
      rtb_UseIPPosSwitch_idx_1) + rtb_VectorConcatenate_i[3 * i + 2] * denAccum)
      + rtCP_Constant_Value[i];
  }

  /* Outputs for Enabled SubSystem: '<S36>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S66>/Enable'
   */
  /* DataTypeConversion: '<S14>/DataTypeConversionEnable' */
  if (stateEstimator_B.nicemeasurementornewupdateneeded) {
    stateEstimator_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S66>/Sum' incorporates:
     *  Constant: '<S14>/C'
     *  Constant: '<S14>/D'
     *  Delay: '<S14>/MemoryX'
     *  Product: '<S66>/C[k]*xhat[k|k-1]'
     *  Product: '<S66>/D[k]*u[k]'
     *  Reshape: '<S14>/Reshapeu'
     *  Reshape: '<S14>/Reshapey'
     *  Sum: '<S66>/Add1'
     */
    rtb_Sum = stateEstimator_B.invertzaxisGain - ((1.0 *
      stateEstimator_DW.MemoryX_DSTATE[0] + 0.0 *
      stateEstimator_DW.MemoryX_DSTATE[1]) + 0.0 * stateEstimator_B.Sum[2]);

    /* Product: '<S66>/Product3' incorporates:
     *  DataTypeConversion: '<S58>/Conversion'
     */
    stateEstimator_B.Product3[0] = stateEstimator_ConstB.Conversion[0] * rtb_Sum;
    stateEstimator_B.Product3[1] = stateEstimator_ConstB.Conversion[1] * rtb_Sum;
  } else if (stateEstimator_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S66>/Product3' incorporates:
     *  Outport: '<S66>/L*(y[k]-yhat[k|k-1])'
     */
    stateEstimator_B.Product3[0] = 0.0;
    stateEstimator_B.Product3[1] = 0.0;
    stateEstimator_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S36>/MeasurementUpdate' */

  /* Trigonometry: '<S80>/sincos' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  rtb_TrigonometricFunction_o2_idx_0 = (real32_T)sin(stateEstimator_B.Merge[0]);
  rtb_UseIPPosSwitch_idx_1 = (real32_T)cos(stateEstimator_B.Merge[0]);
  denAccum = (real32_T)sin(stateEstimator_B.Merge[1]);
  LogicalOperator3_a_tmp = (real32_T)cos(stateEstimator_B.Merge[1]);

  /* Fcn: '<S80>/Fcn11' incorporates:
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_VectorConcatenate_h[0] = rtb_MathFunction_idx_1 * rtb_UseIPPosSwitch_idx_1;

  /* Fcn: '<S80>/Fcn21' incorporates:
   *  Fcn: '<S80>/Fcn22'
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_sincos_o1_idx_2_tmp_tmp = rtb_TrigonometricFunction_o2_idx_0 * denAccum;
  rtb_VectorConcatenate_h[1] = rtb_sincos_o1_idx_2_tmp_tmp *
    rtb_MathFunction_idx_1 - rtb_TrigonometricFunction_o1_idx_1 *
    LogicalOperator3_a_tmp;

  /* Fcn: '<S80>/Fcn31' incorporates:
   *  Fcn: '<S80>/Fcn32'
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_sincos_o2_idx_2_tmp_tmp = rtb_TrigonometricFunction_o2_idx_0 *
    LogicalOperator3_a_tmp;
  rtb_VectorConcatenate_h[2] = rtb_sincos_o2_idx_2_tmp_tmp *
    rtb_MathFunction_idx_1 + rtb_TrigonometricFunction_o1_idx_1 * denAccum;

  /* Fcn: '<S80>/Fcn12' incorporates:
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_VectorConcatenate_h[3] = rtb_TrigonometricFunction_o1_idx_1 *
    rtb_UseIPPosSwitch_idx_1;

  /* Fcn: '<S80>/Fcn22' incorporates:
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_VectorConcatenate_h[4] = rtb_sincos_o1_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o1_idx_1 + rtb_MathFunction_idx_1 *
    LogicalOperator3_a_tmp;

  /* Fcn: '<S80>/Fcn32' incorporates:
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_VectorConcatenate_h[5] = rtb_sincos_o2_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o1_idx_1 - rtb_MathFunction_idx_1 * denAccum;

  /* Fcn: '<S80>/Fcn13' incorporates:
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_VectorConcatenate_h[6] = -rtb_TrigonometricFunction_o2_idx_0;

  /* Fcn: '<S80>/Fcn23' incorporates:
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_VectorConcatenate_h[7] = rtb_UseIPPosSwitch_idx_1 * denAccum;

  /* Fcn: '<S80>/Fcn33' incorporates:
   *  Trigonometry: '<S80>/sincos'
   */
  rtb_VectorConcatenate_h[8] = rtb_UseIPPosSwitch_idx_1 * LogicalOperator3_a_tmp;

  /* RelationalOperator: '<S79>/Compare' incorporates:
   *  Constant: '<S79>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Reshape: '<S14>/Reshapexhat'
   */
  rtb_Compare_i = ((real32_T)rtb_Add_a_idx_0 <= (-0.4F));

  /* Logic: '<S76>/Logical Operator' incorporates:
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  RelationalOperator: '<S81>/Compare'
   *  RelationalOperator: '<S82>/Compare'
   */
  rtb_LogicalOperator_cg = ((stateEstimator_B.opticalFlowToVelocity_gain[0] !=
    0.0F) || (stateEstimator_B.opticalFlowToVelocity_gain[1] != 0.0F));

  /* Product: '<S76>/Product1' incorporates:
   *  Constant: '<S76>/gravity'
   */
  rtb_Add_a_idx_1 = 0.0;
  tmp_0 = 0.0;
  tmp_2 = (-9.81);

  /* Sum: '<S76>/Add' incorporates:
   *  Constant: '<S76>/gravity'
   *  Product: '<S76>/Product1'
   *  Reshape: '<S83>/Reshape (9) to [3x3] column-major'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_h_0[i] = rtb_FIR_IMUaccel[i] -
      ((rtb_VectorConcatenate_h[i + 3] * rtb_Add_a_idx_1 +
        rtb_VectorConcatenate_h[i] * tmp_0) + rtb_VectorConcatenate_h[i + 6] *
       tmp_2);
  }

  /* End of Sum: '<S76>/Add' */

  /* Product: '<S76>/Product' incorporates:
   *  Gain: '<S76>/gainaccinput'
   */
  stateEstimator_B.Product[0] = (real32_T)(0.2 * rtb_VectorConcatenate_h_0[0]) *
    (real32_T)rtb_LogicalOperator_cg * (real32_T)rtb_Compare_i;
  stateEstimator_B.Product[1] = (real32_T)(0.2 * rtb_VectorConcatenate_h_0[1]) *
    (real32_T)rtb_LogicalOperator_cg * (real32_T)rtb_Compare_i;

  /* MATLAB Function: '<S144>/SqrtUsedFcn' incorporates:
   *  Constant: '<S144>/isSqrtUsed'
   */
  stateEstimator_SqrtUsedFcn(stateEstimator_ConstB.Conversion_i2, false);

  /* DataTypeConversion: '<S111>/Conversion' */
  rtb_Conversion_j[0] = rtb_MemoryX_m[0];
  rtb_Conversion_j[1] = rtb_MemoryX_m[1];

  /* Reshape: '<S78>/Reshapeu' */
  rtb_Reshapeu_h[0] = stateEstimator_B.Product[0];
  rtb_Reshapeu_h[1] = stateEstimator_B.Product[1];

  /* Outputs for Enabled SubSystem: '<S115>/MeasurementUpdate' */
  /* Constant: '<S78>/C' incorporates:
   *  Constant: '<S78>/D'
   */
  stateEstimator_MeasurementUpdate(rtb_DataTypeConversionEnable_i,
    stateEstimator_ConstB.Conversion_n, rtb_Reshapey_o, rtCP_C_Value_f,
    rtb_Conversion_j, rtCP_D_Value_f, rtb_Reshapeu_h,
    &stateEstimator_B.MeasurementUpdate_e,
    &stateEstimator_DW.MeasurementUpdate_e);

  /* End of Outputs for SubSystem: '<S115>/MeasurementUpdate' */

  /* MATLAB Function: '<S200>/SqrtUsedFcn' incorporates:
   *  Constant: '<S200>/isSqrtUsed'
   */
  stateEstimator_SqrtUsedFcn(stateEstimator_ConstB.Conversion_ao, false);

  /* DataTypeConversion: '<S167>/Conversion' */
  rtb_Conversion_p[0] = rtb_MemoryX_f[0];
  rtb_Conversion_p[1] = rtb_MemoryX_f[1];

  /* Trigonometry: '<S151>/sincos' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  rtb_TrigonometricFunction_o2_idx_0 = (real32_T)sin(stateEstimator_B.Merge[0]);
  rtb_UseIPPosSwitch_idx_1 = (real32_T)cos(stateEstimator_B.Merge[0]);
  denAccum = (real32_T)sin(stateEstimator_B.Merge[1]);
  LogicalOperator3_a_tmp = (real32_T)cos(stateEstimator_B.Merge[1]);

  /* Fcn: '<S151>/Fcn11' incorporates:
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_VectorConcatenate_p[0] = rtb_MathFunction_idx_1 * rtb_UseIPPosSwitch_idx_1;

  /* Fcn: '<S151>/Fcn21' incorporates:
   *  Fcn: '<S151>/Fcn22'
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_sincos_o1_idx_2_tmp_tmp = rtb_TrigonometricFunction_o2_idx_0 * denAccum;
  rtb_VectorConcatenate_p[1] = rtb_sincos_o1_idx_2_tmp_tmp *
    rtb_MathFunction_idx_1 - rtb_TrigonometricFunction_o1_idx_1 *
    LogicalOperator3_a_tmp;

  /* Fcn: '<S151>/Fcn31' incorporates:
   *  Fcn: '<S151>/Fcn32'
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_sincos_o2_idx_2_tmp_tmp = rtb_TrigonometricFunction_o2_idx_0 *
    LogicalOperator3_a_tmp;
  rtb_VectorConcatenate_p[2] = rtb_sincos_o2_idx_2_tmp_tmp *
    rtb_MathFunction_idx_1 + rtb_TrigonometricFunction_o1_idx_1 * denAccum;

  /* Fcn: '<S151>/Fcn12' incorporates:
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_VectorConcatenate_p[3] = rtb_TrigonometricFunction_o1_idx_1 *
    rtb_UseIPPosSwitch_idx_1;

  /* Fcn: '<S151>/Fcn22' incorporates:
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_VectorConcatenate_p[4] = rtb_sincos_o1_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o1_idx_1 + rtb_MathFunction_idx_1 *
    LogicalOperator3_a_tmp;

  /* Fcn: '<S151>/Fcn32' incorporates:
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_VectorConcatenate_p[5] = rtb_sincos_o2_idx_2_tmp_tmp *
    rtb_TrigonometricFunction_o1_idx_1 - rtb_MathFunction_idx_1 * denAccum;

  /* Fcn: '<S151>/Fcn13' incorporates:
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_VectorConcatenate_p[6] = -rtb_TrigonometricFunction_o2_idx_0;

  /* Fcn: '<S151>/Fcn23' incorporates:
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_VectorConcatenate_p[7] = rtb_UseIPPosSwitch_idx_1 * denAccum;

  /* Fcn: '<S151>/Fcn33' incorporates:
   *  Trigonometry: '<S151>/sincos'
   */
  rtb_VectorConcatenate_p[8] = rtb_UseIPPosSwitch_idx_1 * LogicalOperator3_a_tmp;

  /* SignalConversion generated from: '<S75>/Product' incorporates:
   *  Reshape: '<S78>/Reshapexhat'
   */
  rtb_TrigonometricFunction_o2_idx_0 = rtb_Add_m[0];
  rtb_TrigonometricFunction_o1_idx_1 = rtb_Add_m[1];
  for (i = 0; i < 3; i++) {
    /* Product: '<S75>/Product' incorporates:
     *  Math: '<S75>/Math Function'
     *  Reshape: '<S209>/Reshape (9) to [3x3] column-major'
     *  SignalConversion generated from: '<S75>/Product'
     */
    stateEstimator_B.Product_l[i] = (rtb_VectorConcatenate_p[3 * i + 1] *
      rtb_TrigonometricFunction_o1_idx_1 + rtb_VectorConcatenate_p[3 * i] *
      rtb_TrigonometricFunction_o2_idx_0) + rtb_VectorConcatenate_p[3 * i + 2] *
      rtb_DataTypeConversion2_i;
  }

  /* Reshape: '<S149>/Reshapeu' */
  rtb_Reshapeu_i[0] = stateEstimator_B.Product_l[0];
  rtb_Reshapeu_i[1] = stateEstimator_B.Product_l[1];

  /* Outputs for Enabled SubSystem: '<S171>/MeasurementUpdate' */
  /* Constant: '<S149>/C' incorporates:
   *  Constant: '<S149>/D'
   */
  stateEstimator_MeasurementUpdate(rtb_DataTypeConversionEnable,
    stateEstimator_ConstB.Conversion_a, rtb_Reshapey_a, rtCP_C_Value_p,
    rtb_Conversion_p, rtCP_D_Value_b, rtb_Reshapeu_i,
    &stateEstimator_B.MeasurementUpdate_b,
    &stateEstimator_DW.MeasurementUpdate_b);

  /* End of Outputs for SubSystem: '<S171>/MeasurementUpdate' */

  /* Update for Delay: '<S149>/MemoryX' incorporates:
   *  Constant: '<S149>/A'
   *  Constant: '<S149>/B'
   *  Product: '<S171>/A[k]*xhat[k|k-1]'
   *  Product: '<S171>/B[k]*u[k]'
   *  Sum: '<S171>/Add'
   */
  stateEstimator_DW.icLoad = false;
  stateEstimator_DW.MemoryX_DSTATE_d[0] = ((0.005F * rtb_Reshapeu_i[0] +
    rtb_Reshapeu_i[1] * 0.0F) + (1.0F * rtb_Conversion_p[0] + rtb_Conversion_p[1]
    * 0.0F)) + stateEstimator_B.MeasurementUpdate_b.Product3[0];
  stateEstimator_DW.MemoryX_DSTATE_d[1] = ((rtb_Reshapeu_i[0] * 0.0F +
    rtb_Reshapeu_i[1] * 0.005F) + (rtb_Conversion_p[0] * 0.0F +
    rtb_Conversion_p[1] * 1.0F)) +
    stateEstimator_B.MeasurementUpdate_b.Product3[1];

  /* Update for Memory: '<S2>/Memory' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  stateEstimator_DW.Memory_PreviousInput[0] = rtb_Merge1;
  stateEstimator_DW.Memory_PreviousInput[1] = stateEstimator_B.Merge[0];
  stateEstimator_DW.Memory_PreviousInput[2] = stateEstimator_B.Merge[1];

  /* Update for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  stateEstimator_DW.IIR_IMUgyro_r_states[4] =
    stateEstimator_DW.IIR_IMUgyro_r_states[3];
  stateEstimator_DW.IIR_IMUgyro_r_states[3] =
    stateEstimator_DW.IIR_IMUgyro_r_states[2];
  stateEstimator_DW.IIR_IMUgyro_r_states[2] =
    stateEstimator_DW.IIR_IMUgyro_r_states[1];
  stateEstimator_DW.IIR_IMUgyro_r_states[1] =
    stateEstimator_DW.IIR_IMUgyro_r_states[0];
  stateEstimator_DW.IIR_IMUgyro_r_states[0] =
    stateEstimator_DW.IIR_IMUgyro_r_tmp;

  /* Update for DiscreteFir: '<S5>/FIR_IMUaccel' */
  /* Update circular buffer index */
  stateEstimator_DW.FIR_IMUaccel_circBuf--;
  if (stateEstimator_DW.FIR_IMUaccel_circBuf < 0) {
    stateEstimator_DW.FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf] =
    stateEstimator_B.inverseIMU_gain[0];
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf +
    5] = stateEstimator_B.inverseIMU_gain[1];
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf +
    10] = stateEstimator_B.inverseIMU_gain[2];

  /* End of Update for DiscreteFir: '<S5>/FIR_IMUaccel' */

  /* Update for DiscreteIntegrator: '<S75>/Integrator' */
  stateEstimator_DW.Integrator_PrevResetState = (int8_T)
    *rtu_controlModePosVSOrient_flagin;

  /* Update for Delay: '<S3>/Delay2' incorporates:
   *  Reshape: '<S14>/Reshapexhat'
   */
  stateEstimator_DW.Delay2_DSTATE = rtb_Add_a_idx_0;

  /* Update for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = false;

  /* Update for Delay: '<S75>/Delay' incorporates:
   *  Reshape: '<S149>/Reshapexhat'
   */
  stateEstimator_DW.Delay_DSTATE[0] = rtb_TrigonometricFunction_o2_idx_1;

  /* Update for DiscreteIntegrator: '<S75>/Integrator' */
  stateEstimator_DW.Integrator_DSTATE[0] += 0.005F * stateEstimator_B.Product_l
    [0];

  /* Product: '<S36>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S14>/A'
   *  Delay: '<S14>/MemoryX'
   */
  tmp_1 = 1.0 * stateEstimator_DW.MemoryX_DSTATE[0] +
    stateEstimator_DW.MemoryX_DSTATE[1] * 0.005;

  /* Update for Delay: '<S75>/Delay' incorporates:
   *  Reshape: '<S149>/Reshapexhat'
   */
  stateEstimator_DW.Delay_DSTATE[1] = rtb_TrigonometricFunction_o1_idx_0;

  /* Update for DiscreteIntegrator: '<S75>/Integrator' */
  stateEstimator_DW.Integrator_DSTATE[1] += 0.005F * stateEstimator_B.Product_l
    [1];

  /* Product: '<S36>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S14>/A'
   *  Delay: '<S14>/MemoryX'
   */
  tmp_3 = stateEstimator_DW.MemoryX_DSTATE[0] * 0.0 +
    stateEstimator_DW.MemoryX_DSTATE[1] * 1.0;

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/B'
   *  Product: '<S36>/A[k]*xhat[k|k-1]'
   *  Product: '<S36>/B[k]*u[k]'
   *  Product: '<S66>/Product3'
   *  Reshape: '<S14>/Reshapeu'
   *  Sum: '<S36>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE[0] = (0.0 * stateEstimator_B.Sum[2] + tmp_1)
    + stateEstimator_B.Product3[0];

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[2] =
    stateEstimator_DW.soonarFilter_IIR_states[1];

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/B'
   *  Product: '<S36>/A[k]*xhat[k|k-1]'
   *  Product: '<S36>/B[k]*u[k]'
   *  Product: '<S66>/Product3'
   *  Reshape: '<S14>/Reshapeu'
   *  Sum: '<S36>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE[1] = (0.005 * stateEstimator_B.Sum[2] + tmp_3)
    + stateEstimator_B.Product3[1];

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[1] =
    stateEstimator_DW.soonarFilter_IIR_states[0];
  stateEstimator_DW.soonarFilter_IIR_states[0] =
    stateEstimator_DW.soonarFilter_IIR_tmp;

  /* Update for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[2] =
    stateEstimator_DW.pressureFilter_IIR_states[1];
  stateEstimator_DW.pressureFilter_IIR_states[1] =
    stateEstimator_DW.pressureFilter_IIR_states[0];
  stateEstimator_DW.pressureFilter_IIR_states[0] =
    stateEstimator_DW.pressureFilter_IIR_tmp;

  /* Update for Delay: '<S78>/MemoryX' incorporates:
   *  Constant: '<S78>/A'
   *  Constant: '<S78>/B'
   *  Product: '<S115>/A[k]*xhat[k|k-1]'
   *  Product: '<S115>/B[k]*u[k]'
   *  Sum: '<S115>/Add'
   */
  stateEstimator_DW.icLoad_i = false;
  stateEstimator_DW.MemoryX_DSTATE_d5[0] = ((0.005F * rtb_Reshapeu_h[0] +
    rtb_Reshapeu_h[1] * 0.0F) + (1.0F * rtb_Conversion_j[0] + rtb_Conversion_j[1]
    * 0.0F)) + stateEstimator_B.MeasurementUpdate_e.Product3[0];
  stateEstimator_DW.MemoryX_DSTATE_d5[1] = ((rtb_Reshapeu_h[0] * 0.0F +
    rtb_Reshapeu_h[1] * 0.005F) + (rtb_Conversion_j[0] * 0.0F +
    rtb_Conversion_j[1] * 1.0F)) +
    stateEstimator_B.MeasurementUpdate_e.Product3[1];
  for (i_0 = 0; i_0 < 2; i_0++) {
    /* Update for DiscreteFilter: '<S77>/IIRgyroz' */
    tmp = i_0 * 5;
    stateEstimator_DW.IIRgyroz_states[tmp + 4] =
      stateEstimator_DW.IIRgyroz_states[tmp + 3];
    stateEstimator_DW.IIRgyroz_states[tmp + 3] =
      stateEstimator_DW.IIRgyroz_states[tmp + 2];
    stateEstimator_DW.IIRgyroz_states[tmp + 2] =
      stateEstimator_DW.IIRgyroz_states[tmp + 1];
    stateEstimator_DW.IIRgyroz_states[tmp + 1] =
      stateEstimator_DW.IIRgyroz_states[tmp];
    stateEstimator_DW.IIRgyroz_states[tmp] = stateEstimator_DW.IIRgyroz_tmp[i_0];

    /* Update for UnitDelay: '<S84>/UD' */
    stateEstimator_DW.UD_DSTATE[i_0] = rtb_TSamp[i_0];

    /* Reshape: '<S78>/Reshapexhat' */
    rtb_TrigonometricFunction_o2_idx_1 = rtb_Add_m[i_0];

    /* Update for Delay: '<S74>/Delay' incorporates:
     *  Reshape: '<S78>/Reshapexhat'
     */
    stateEstimator_DW.Delay_DSTATE_g[i_0] = rtb_TrigonometricFunction_o2_idx_1;

    /* Update for Delay: '<S1>/Delay' incorporates:
     *  Reshape: '<S78>/Reshapexhat'
     */
    stateEstimator_DW.Delay_DSTATE_p[i_0] = rtb_TrigonometricFunction_o2_idx_1;
  }
}

/* Model initialize function */
void stateEstimator_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_stateEstimator_T *const stateEstimator_M =
    &(stateEstimator_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(stateEstimator_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) &stateEstimator_B), 0,
                sizeof(B_stateEstimator_c_T));

  /* states (dwork) */
  (void) memset((void *)&stateEstimator_DW, 0,
                sizeof(DW_stateEstimator_f_T));
}
