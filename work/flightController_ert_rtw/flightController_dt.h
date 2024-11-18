/*
 * flightController_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightController".
 *
 * Model version              : 8.21
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Nov 18 12:50:03 2024
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
  sizeof(statesEstim_t),
  sizeof(struct_eAf0NJvzCY9HYTXF7bLNgB),
  sizeof(struct_XRMsui9C07VjBvdq1msujB),
  sizeof(struct_hxsmtt0xTZOLDNa2Rz7GAF),
  sizeof(struct_IZWOW0zYvpphl7qLgSfN7E),
  sizeof(struct_q6UUpnZ4gTjFvULFx6Rxa),
  sizeof(struct_OMRgDnJcZuQneKEj9vdTyD),
  sizeof(struct_p3FXZIgqtjF2uqDpmYjb6C),
  sizeof(struct_OSJpyIZcrpXqReVWwh9iuG),
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
  "statesEstim_t",
  "struct_eAf0NJvzCY9HYTXF7bLNgB",
  "struct_XRMsui9C07VjBvdq1msujB",
  "struct_hxsmtt0xTZOLDNa2Rz7GAF",
  "struct_IZWOW0zYvpphl7qLgSfN7E",
  "struct_q6UUpnZ4gTjFvULFx6Rxa",
  "struct_OMRgDnJcZuQneKEj9vdTyD",
  "struct_p3FXZIgqtjF2uqDpmYjb6C",
  "struct_OSJpyIZcrpXqReVWwh9iuG",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&flightController_DW.DiscreteTimeIntegrator_DSTATE[0]), 1, 0, 4 },

  { (char_T *)(&flightController_DW.Memory_PreviousInput), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  2U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&flightController_P.SRFlipFlop_initial_condition), 8, 0, 1 },

  { (char_T *)(&flightController_P.takeoff_gain_Gain), 1, 0, 51 },

  { (char_T *)(&flightController_P.Logic_table[0]), 8, 0, 16 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] flightController_dt.h */
