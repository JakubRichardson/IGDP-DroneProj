/*
 * flightControlSystem_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 8.51
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov 13 17:46:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(CommandBus),
  sizeof(extraSensorData_t),
  sizeof(HAL_acc_SI_t),
  sizeof(HAL_gyro_SI_t),
  sizeof(HAL_fifo_gyro_SI_t),
  sizeof(HAL_magn_mG_t),
  sizeof(HAL_pressure_SI_t),
  sizeof(HAL_echo_t),
  sizeof(HAL_list_echo_t),
  sizeof(HAL_ultrasound_SI_t),
  sizeof(HAL_vbat_SI_t),
  sizeof(HAL_acquisition_t),
  sizeof(SensorsBus),
  sizeof(statesEstim_t),
  sizeof(sensordata_t),
  sizeof(struct_eF5OUT33sX0T9pzS8027m),
  sizeof(struct_FIfaVnupBjYAxo1EdNiDlF),
  sizeof(struct_eFnp8sKFNJLN84XLbLzaFF),
  sizeof(struct_pAcs5k38eV6MpgiqrKAV4),
  sizeof(parrot_Grabber_flightControlSystem_T),
  sizeof(parrot_ImageProcess_flightControlSystem_T),
  sizeof(struct_eAf0NJvzCY9HYTXF7bLNgB),
  sizeof(struct_XRMsui9C07VjBvdq1msujB),
  sizeof(struct_hxsmtt0xTZOLDNa2Rz7GAF),
  sizeof(struct_IZWOW0zYvpphl7qLgSfN7E),
  sizeof(struct_q6UUpnZ4gTjFvULFx6Rxa),
  sizeof(struct_OMRgDnJcZuQneKEj9vdTyD),
  sizeof(struct_p3FXZIgqtjF2uqDpmYjb6C),
  sizeof(struct_OSJpyIZcrpXqReVWwh9iuG),
  sizeof(struct_hE1099BMemg5OfzqcWAA6G),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "CommandBus",
  "extraSensorData_t",
  "HAL_acc_SI_t",
  "HAL_gyro_SI_t",
  "HAL_fifo_gyro_SI_t",
  "HAL_magn_mG_t",
  "HAL_pressure_SI_t",
  "HAL_echo_t",
  "HAL_list_echo_t",
  "HAL_ultrasound_SI_t",
  "HAL_vbat_SI_t",
  "HAL_acquisition_t",
  "SensorsBus",
  "statesEstim_t",
  "sensordata_t",
  "struct_eF5OUT33sX0T9pzS8027m",
  "struct_FIfaVnupBjYAxo1EdNiDlF",
  "struct_eFnp8sKFNJLN84XLbLzaFF",
  "struct_pAcs5k38eV6MpgiqrKAV4",
  "parrot_Grabber_flightControlSystem_T",
  "parrot_ImageProcess_flightControlSystem_T",
  "struct_eAf0NJvzCY9HYTXF7bLNgB",
  "struct_XRMsui9C07VjBvdq1msujB",
  "struct_hxsmtt0xTZOLDNa2Rz7GAF",
  "struct_IZWOW0zYvpphl7qLgSfN7E",
  "struct_q6UUpnZ4gTjFvULFx6Rxa",
  "struct_OMRgDnJcZuQneKEj9vdTyD",
  "struct_p3FXZIgqtjF2uqDpmYjb6C",
  "struct_OSJpyIZcrpXqReVWwh9iuG",
  "struct_hE1099BMemg5OfzqcWAA6G",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&flightControlSystem_B.dy), 0, 0, 5 },

  { (char_T *)(&flightControlSystem_B.Submatrix[0]), 8, 0, 19200 },

  { (char_T *)(&flightControlSystem_B.Compare), 8, 0, 19201 },

  { (char_T *)(&flightControlSystem_B.FlightControlSystem.Grabber), 0, 0, 6 },

  { (char_T *)(&flightControlSystem_B.FlightControlSystem.x_c), 1, 0, 16 },

  { (char_T *)(&flightControlSystem_B.FlightControlSystem.Logging.X), 1, 0, 78 }
  ,

  { (char_T *)(&motors_outport[0]), 1, 0, 4 }
  ,

  { (char_T *)(&flag_outport), 3, 0, 1 }
  ,

  { (char_T *)(&flightControlSystem_DW.RateTransition_1_Buffer[0]), 0, 0, 4 },

  { (char_T *)(&flightControlSystem_DW.Scope_PWORK.LoggedData[0]), 11, 0, 5 },

  { (char_T *)(&flightControlSystem_DW.RateTransition_1_ActiveBufIdx), 2, 0, 2 },

  { (char_T *)(&flightControlSystem_DW.is_active_c6_flightControlSystem), 3, 0,
    2 },

  { (char_T *)(&flightControlSystem_DW.doneDoubleBufferReInit), 8, 0, 2 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.Scope_PWORK.LoggedData), 11, 0,
    1 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.is_c4_flightControlSystem), 7,
    0, 5 },

  { (char_T *)(&flightControlSystem_DW.FlightControlSystem.temporalCounter_i1),
    5, 0, 5 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.is_active_c4_flightControlSystem),
    3, 0, 4 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.Logging.ToWorkspace2_PWORK.LoggedData),
    11, 0, 7 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.Normalcondition.Geofencingerror_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&flightControlSystem_DW.FlightControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  21U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&flightControlSystem_P.CompareToConstant2_const), 0, 0, 3 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.CompareToConstant_const), 1, 0,
    6 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.Memory_InitialCondition), 28, 0,
    1 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.landingOverrideLimit_Value), 0,
    0, 1 },

  { (char_T *)(&flightControlSystem_P.FlightControlSystem.Constant3_Value[0]), 1,
    0, 6 },

  { (char_T *)(&flightControlSystem_P.FlightControlSystem.Constant1_Value), 8, 0,
    1 },

  { (char_T *)(&flightControlSystem_P.FlightControlSystem.Merge_InitialOutput),
    3, 0, 1 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.Normalcondition.Constant_Value),
    3, 0, 1 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.estimatorOpticalflowerror.Constant_Value),
    3, 0, 1 },

  { (char_T *)
    (&flightControlSystem_P.FlightControlSystem.Geofencingerror.Constant_Value),
    3, 0, 1 }
  ,

  { (char_T *)(&rtP_Sensors), 33, 0, 1 }
  ,

  { (char_T *)(&rtP_enableLanding), 8, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  12U,
  rtPTransitions
};

/* [EOF] flightControlSystem_dt.h */
