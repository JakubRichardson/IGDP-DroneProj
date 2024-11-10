/*
 * flightControlSystem_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 8.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov  6 18:08:22 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightControlSystem_types_h_
#define RTW_HEADER_flightControlSystem_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CommandBus_
#define DEFINED_TYPEDEF_FOR_CommandBus_

typedef struct {
  boolean_T controlModePosVSOrient;
  real32_T pos_ref[3];
  boolean_T takeoff_flag;
  real32_T orient_ref[3];
  uint32_T live_time_ticks;
} CommandBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_extraSensorData_t_
#define DEFINED_TYPEDEF_FOR_extraSensorData_t_

typedef struct {
  real32_T opticalFlow_data[3];
  real32_T posVIS_data[4];
  real32_T usePosVIS_flag;
} extraSensorData_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_acc_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_acc_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T temperature;
} HAL_acc_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_gyro_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_gyro_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T temperature;
  int32_T temperature_lsb;
} HAL_gyro_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_fifo_gyro_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_fifo_gyro_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
} HAL_fifo_gyro_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_magn_mG_t_
#define DEFINED_TYPEDEF_FOR_HAL_magn_mG_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
} HAL_magn_mG_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_pressure_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_pressure_SI_t_

typedef struct {
  real_T temperature;
  real32_T pressure;
} HAL_pressure_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_echo_t_
#define DEFINED_TYPEDEF_FOR_HAL_echo_t_

typedef struct {
  uint16_T begin_echo_index;
  uint16_T end_echo_index;
  int16_T max_value_index;
  int32_T max_value;
  uint16_T precedent;
  int16_T d_echo;
  uint16_T pre_max_index;
} HAL_echo_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_list_echo_t_
#define DEFINED_TYPEDEF_FOR_HAL_list_echo_t_

typedef struct {
  HAL_echo_t tab_echo[30];
  uint8_T number_of_echoes;
} HAL_list_echo_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_ultrasound_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_ultrasound_SI_t_

typedef struct {
  real32_T altitude;
  real32_T raw_altitude;
  uint16_T nb_echo;
  int32_T measure_ref;
  int32_T measure_status;
  uint8_T new_data;
  HAL_list_echo_t HAL_list_echo;
  HAL_list_echo_t HAL_list_echo_p;
} HAL_ultrasound_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_vbat_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_vbat_SI_t_

typedef struct {
  real32_T vbat_V;
  uint32_T vbat_percentage;
} HAL_vbat_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_acquisition_t_
#define DEFINED_TYPEDEF_FOR_HAL_acquisition_t_

typedef struct {
  int32_T number_HAL_read_call;
  uint32_T timestamp;
  uint16_T status;
  uint8_T used;
  uint8_T count_user;
  HAL_acc_SI_t HAL_acc_SI;
  HAL_gyro_SI_t HAL_gyro_SI;
  uint16_T HAL_fifo_count;
  uint32_T fifo_timestamp;
  HAL_fifo_gyro_SI_t HAL_fifo_gyro_SI_TempCorr[5];
  HAL_fifo_gyro_SI_t HAL_fifo_acce_SI_TempCorr[5];
  HAL_fifo_gyro_SI_t HAL_fifo_gyro_SI[5];
  HAL_fifo_gyro_SI_t HAL_fifo_acce_SI[5];
  real32_T HAL_ref_IMU_temp;
  uint8_T HAL_fifo_fsync[5];
  int32_T HAL_fifo_size;
  HAL_magn_mG_t HAL_magn_mG;
  HAL_pressure_SI_t HAL_pressure_SI;
  HAL_ultrasound_SI_t HAL_ultrasound_SI;
  uint8_T padding[196];
  HAL_vbat_SI_t HAL_vbat_SI;
} HAL_acquisition_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SensorsBus_
#define DEFINED_TYPEDEF_FOR_SensorsBus_

typedef struct {
  extraSensorData_t VisionSensors;
  HAL_acquisition_t HALSensors;
  real32_T SensorCalibration[8];
} SensorsBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_statesEstim_t_
#define DEFINED_TYPEDEF_FOR_statesEstim_t_

typedef struct {
  real32_T X;
  real32_T Y;
  real32_T Z;
  real32_T yaw;
  real32_T pitch;
  real32_T roll;
  real32_T dx;
  real32_T dy;
  real32_T dz;
  real32_T p;
  real32_T q;
  real32_T r;
} statesEstim_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_sensordata_t_
#define DEFINED_TYPEDEF_FOR_sensordata_t_

typedef struct {
  real32_T ddx;
  real32_T ddy;
  real32_T ddz;
  real32_T p;
  real32_T q;
  real32_T r;
  real32_T altitude_sonar;
  real32_T prs;
  real32_T vbat_V;
  uint32_T vbat_percentage;
} sensordata_t;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_flightControlSystem_T RT_MODEL_flightControlSystem_T;

#endif                             /* RTW_HEADER_flightControlSystem_types_h_ */
