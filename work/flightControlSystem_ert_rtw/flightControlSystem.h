/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControlSystem.h
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

#ifndef RTW_HEADER_flightControlSystem_h_
#define RTW_HEADER_flightControlSystem_h_
#ifndef flightControlSystem_COMMON_INCLUDES_
#define flightControlSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "grabberCannon.h"
#include "rsedu_image.h"
#endif                                /* flightControlSystem_COMMON_INCLUDES_ */

#include "flightControlSystem_types.h"
#include <float.h>
#include <stddef.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals for system '<Root>/Flight Control System' */
typedef struct {
  statesEstim_t estimator;             /* '<S1>/estimator' */
  sensordata_t BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1;
  real32_T controller_o2[8];           /* '<S1>/controller' */
  CommandBus BusConversion_InsertedFor_controller_at_inport_0_BusCreator;
  real_T Grabber;                      /* '<S3>/Grabber' */
  real_T grabber_c;                    /* '<S3>/Chart' */
  real_T landing_flag;                 /* '<S3>/Chart' */
  real_T takeoff_flag;                 /* '<S3>/Chart' */
  real32_T Abs[3];                     /* '<S3>/Abs' */
  real_T d;
  real32_T x_g;                        /* '<S3>/Chart' */
  real32_T y_b;                        /* '<S3>/Chart' */
  real32_T z_g;                        /* '<S3>/Chart' */
  uint8_T u;
  boolean_T Compare;                   /* '<S9>/Compare' */
  boolean_T Compare_d;                 /* '<S10>/Compare' */
  boolean_T Compare_dd;                /* '<S11>/Compare' */
  boolean_T stable;                    /* '<S3>/AND1' */
} B_FlightControlSystem_flightControlSystem_T;

/* Block states (default storage) for system '<Root>/Flight Control System' */
typedef struct {
  statesEstim_t Memory1_PreviousInput; /* '<S3>/Memory1' */
  struct {
    void *LoggedData[5];
  } Scope1_PWORK;                      /* '<S3>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S3>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<S3>/Scope2' */

  real32_T UnitDelay_DSTATE[3];        /* '<S3>/Unit Delay' */
  uint32_T is_c4_flightControlSystem;  /* '<S3>/Chart3' */
  uint32_T is_c2_flightControlSystem;  /* '<S3>/Chart2' */
  uint32_T is_c1_flightControlSystem;  /* '<S3>/Chart1' */
  uint32_T is_c3_flightControlSystem;  /* '<S3>/Chart' */
  uint32_T is_Takeoff;                 /* '<S3>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S3>/Chart3' */
  uint16_T temporalCounter_i1_d;       /* '<S3>/Chart2' */
  uint16_T temporalCounter_i1_p;       /* '<S3>/Chart1' */
  uint16_T temporalCounter_i1_pu;      /* '<S3>/Chart' */
  uint16_T temporalCounter_i2;         /* '<S3>/Chart' */
  uint8_T is_active_c4_flightControlSystem;/* '<S3>/Chart3' */
  uint8_T is_active_c2_flightControlSystem;/* '<S3>/Chart2' */
  uint8_T is_active_c1_flightControlSystem;/* '<S3>/Chart1' */
  uint8_T is_active_c3_flightControlSystem;/* '<S3>/Chart' */
} DW_FlightControlSystem_flightControlSystem_T;

/* Block signals (default storage) */
typedef struct {
  real_T rowIdx_data[4960];
  real_T colIdx_data[4960];
  int32_T i_data[4960];
  uint8_T imageBuff_1[19200];
  uint8_T imageBuff_2[19200];
  uint8_T imageBuff_3[19200];
  boolean_T y_m[19200];                /* '<S2>/MATLAB Function3' */
  uint8_T j_data[4960];
  real_T dy;                           /* '<Root>/Rate Transition' */
  real_T dx;                           /* '<Root>/Rate Transition' */
  real_T deltaX;                       /* '<S2>/MATLAB Function1' */
  real_T deltaY;                       /* '<S2>/MATLAB Function1' */
  real_T avgX;
  real_T avgY;
  real_T b_y;
  uint8_T bottom;                      /* '<S2>/Matrix Sum' */
  uint8_T top;                         /* '<S2>/Matrix Sum1' */
  boolean_T circle;                    /* '<Root>/Rate Transition' */
  boolean_T Submatrix[900];            /* '<S2>/Submatrix' */
  boolean_T Submatrix1[900];           /* '<S2>/Submatrix1' */
  boolean_T circle_e;                  /* '<S2>/Logical Operator' */
  boolean_T y[19200];                  /* '<S2>/MATLAB Function2' */
  B_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} B_flightControlSystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  volatile real_T RateTransition_1_Buffer[2];/* '<Root>/Rate Transition' */
  volatile real_T RateTransition_2_Buffer[2];/* '<Root>/Rate Transition' */
  struct {
    void *LoggedData[5];
  } Scope_PWORK;                       /* '<S2>/Scope' */

  volatile int8_T RateTransition_1_ActiveBufIdx;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition_2_ActiveBufIdx;/* '<Root>/Rate Transition' */
  uint8_T is_active_c8_flightControlSystem;/* '<S2>/MATLAB Function3' */
  uint8_T is_active_c7_flightControlSystem;/* '<S2>/MATLAB Function2' */
  uint8_T is_active_c6_flightControlSystem;/* '<S2>/MATLAB Function1' */
  uint8_T is_active_c5_flightControlSystem;/* '<S2>/MATLAB Function' */
  volatile boolean_T RateTransition_3_Buffer0;/* '<Root>/Rate Transition' */
  boolean_T doneDoubleBufferReInit;    /* '<S2>/MATLAB Function3' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S2>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S2>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S2>/MATLAB Function' */
  DW_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} DW_flightControlSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Actuators[4];               /* '<Root>/Actuators' */
} ExtY_flightControlSystem_T;

/* Parameters for system: '<Root>/Flight Control System' */
struct P_FlightControlSystem_flightControlSystem_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S9>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S10>/Constant'
                                      */
  real32_T CompareToConstant2_const; /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S11>/Constant'
                                      */
  statesEstim_t Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S3>/Memory1'
                                  */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  real32_T Constant3_Value[3];         /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S3>/Constant3'
                                        */
  boolean_T Constant1_Value;           /* Expression: true
                                        * Referenced by: '<S3>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_flightControlSystem_T_ {
  uint8_T CompareToConstant1_const;  /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S13>/Constant'
                                      */
  uint8_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S12>/Constant'
                                       */
  real_T RateTransition_1_InitialCondition;/* Expression: 0
                                            * Referenced by: '<Root>/Rate Transition'
                                            */
  real_T RateTransition_2_InitialCondition;/* Expression: 0
                                            * Referenced by: '<Root>/Rate Transition'
                                            */
  boolean_T RateTransition_3_InitialCondition;
                        /* Computed Parameter: RateTransition_3_InitialCondition
                         * Referenced by: '<Root>/Rate Transition'
                         */
  P_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
};

/* Real-time Model Data Structure */
struct tag_RTM_flightControlSystem_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint32_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_flightControlSystem_T flightControlSystem_P;

/* Block signals (default storage) */
extern B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
extern DW_flightControlSystem_T flightControlSystem_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightControlSystem_T flightControlSystem_Y;

/* Model block global parameters (default storage) */
extern struct_pAcs5k38eV6MpgiqrKAV4 rtP_Sensors;/* Variable: Sensors
                                                 * Referenced by: '<S1>/estimator'
                                                 */
extern real_T rtP_landingAltitude;     /* Variable: landingAltitude
                                        * Referenced by: '<S3>/landingOverrideLimit'
                                        */
extern real_T rtP_measurementTolerance;/* Variable: measurementTolerance
                                        * Referenced by: '<S3>/landingOverrideLimit'
                                        */
extern boolean_T rtP_enableLanding;    /* Variable: enableLanding
                                        * Referenced by: '<S3>/Constant'
                                        */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<Root>/AC cmd' */
extern SensorsBus sensor_inport;       /* '<Root>/Sensors' */
extern real32_T motors_outport[4];     /* '<S1>/controller' */

/* External function called from main */
extern void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void flightControlSystem_initialize(void);
extern void flightControlSystem_step0(void);
extern void flightControlSystem_step1(void);
extern void flightControlSystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flightControlSystem_T *const flightControlSystem_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'flightControlSystem'
 * '<S1>'   : 'flightControlSystem/Flight Control System'
 * '<S2>'   : 'flightControlSystem/Image Processing System'
 * '<S3>'   : 'flightControlSystem/Flight Control System/landing logic'
 * '<S4>'   : 'flightControlSystem/Flight Control System/sensordata_group'
 * '<S5>'   : 'flightControlSystem/Flight Control System/landing logic/Chart'
 * '<S6>'   : 'flightControlSystem/Flight Control System/landing logic/Chart1'
 * '<S7>'   : 'flightControlSystem/Flight Control System/landing logic/Chart2'
 * '<S8>'   : 'flightControlSystem/Flight Control System/landing logic/Chart3'
 * '<S9>'   : 'flightControlSystem/Flight Control System/landing logic/Compare To Constant'
 * '<S10>'  : 'flightControlSystem/Flight Control System/landing logic/Compare To Constant1'
 * '<S11>'  : 'flightControlSystem/Flight Control System/landing logic/Compare To Constant2'
 * '<S12>'  : 'flightControlSystem/Image Processing System/Compare To Constant'
 * '<S13>'  : 'flightControlSystem/Image Processing System/Compare To Constant1'
 * '<S14>'  : 'flightControlSystem/Image Processing System/MATLAB Function'
 * '<S15>'  : 'flightControlSystem/Image Processing System/MATLAB Function1'
 * '<S16>'  : 'flightControlSystem/Image Processing System/MATLAB Function2'
 * '<S17>'  : 'flightControlSystem/Image Processing System/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_flightControlSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
