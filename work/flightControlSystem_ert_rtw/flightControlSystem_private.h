/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControlSystem_private.h
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 8.52
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Nov 14 14:31:21 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightControlSystem_private_h_
#define RTW_HEADER_flightControlSystem_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "flightControlSystem.h"
#include "flightControlSystem_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

/* Imported (extern) pointer block signals */
extern uint8_T *imRGB;                 /* '<Root>/Image Data' */
extern void flightControlSystem_Geofencingerror(uint8_T *rty_Out1,
  P_Geofencingerror_flightControlSystem_T *localP);
extern void flightControlSystem_Logging_Init(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, DW_Logging_flightControlSystem_T *localDW);
extern void flightControlSystem_Logging(RT_MODEL_flightControlSystem_T * const
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
  *localB, DW_Logging_flightControlSystem_T *localDW);
extern void flightControlSystem_FlightControlSystem_Init
  (RT_MODEL_flightControlSystem_T * const flightControlSystem_M, uint8_T
   *rty_Flag, DW_FlightControlSystem_flightControlSystem_T *localDW,
   P_FlightControlSystem_flightControlSystem_T *localP);
extern void flightControlSystem_FlightControlSystem
  (RT_MODEL_flightControlSystem_T * const flightControlSystem_M, const
   CommandBus *rtu_ReferenceValueServerCmds, const SensorsBus
   *rtu_Sensors_Inport_2, real_T rtu_VisionbasedData, real_T
   rtu_VisionbasedData_p, real32_T rty_motorCmds[4], uint8_T *rty_Flag,
   B_FlightControlSystem_flightControlSystem_T *localB,
   DW_FlightControlSystem_flightControlSystem_T *localDW,
   P_FlightControlSystem_flightControlSystem_T *localP);

#endif                           /* RTW_HEADER_flightControlSystem_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
