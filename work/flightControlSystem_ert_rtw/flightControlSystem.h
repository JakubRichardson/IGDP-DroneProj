/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flightControlSystem.h
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 8.51
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Nov 13 17:46:32 2024
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
#include <stdlib.h>
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
#include <stddef.h>
#include <float.h>
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

/* Block states (default storage) for system '<S3>/Geofencing error' */
typedef struct {
  int8_T Geofencingerror_SubsysRanBC;  /* '<S3>/Geofencing error' */
} DW_Geofencingerror_flightControlSystem_T;

/* Block signals for system '<S1>/Logging' */
typedef struct {
  real32_T X;                          /* '<S4>/states_estim_BusSelector' */
  real32_T Y;                          /* '<S4>/states_estim_BusSelector' */
  real32_T Z;                          /* '<S4>/states_estim_BusSelector' */
  real32_T yaw;                        /* '<S4>/states_estim_BusSelector' */
  real32_T pitch;                      /* '<S4>/states_estim_BusSelector' */
  real32_T roll;                       /* '<S4>/states_estim_BusSelector' */
  real32_T dx;                         /* '<S4>/states_estim_BusSelector' */
  real32_T dy;                         /* '<S4>/states_estim_BusSelector' */
  real32_T dz;                         /* '<S4>/states_estim_BusSelector' */
  real32_T p;                          /* '<S4>/states_estim_BusSelector' */
  real32_T q;                          /* '<S4>/states_estim_BusSelector' */
  real32_T r;                          /* '<S4>/states_estim_BusSelector' */
  real32_T TmpSignalConversionAtToWorkspace2Inport1[12];
  real32_T DataTypeConversion1;        /* '<S4>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<S4>/Data Type Conversion2' */
  real32_T TmpSignalConversionAtToWorkspace6Inport1[10];
  real32_T DataTypeConversion3;        /* '<S4>/Data Type Conversion3' */
  real32_T pos_ref[3];          /* '<S4>/ReferenceValueServerBus_BusSelector' */
  real32_T DataTypeConversion7;        /* '<S4>/Data Type Conversion7' */
  real32_T orient_ref[3];       /* '<S4>/ReferenceValueServerBus_BusSelector' */
  real32_T DataTypeConversion9;        /* '<S4>/Data Type Conversion9' */
  real32_T TmpSignalConversionAtToWorkspace3Inport1[9];
  real32_T DataTypeConversion11;       /* '<S4>/Data Type Conversion11' */
  real32_T opticalFlow_data[3];        /* '<S4>/Sensors_BusSelector' */
  real32_T posVIS_data[4];             /* '<S4>/Sensors_BusSelector' */
  real32_T TmpSignalConversionAtToWorkspace4Inport1[8];
  real32_T SensorCalibration[8];       /* '<S4>/Sensors_BusSelector' */
} B_Logging_flightControlSystem_T;

/* Block states (default storage) for system '<S1>/Logging' */
typedef struct {
  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S4>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace6_PWORK;                /* '<S4>/To Workspace6' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S4>/To Workspace3' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<S4>/To Workspace4' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<S4>/To Workspace5' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S4>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S4>/To Workspace1' */
} DW_Logging_flightControlSystem_T;

/* Block signals for system '<Root>/Flight Control System' */
typedef struct {
  statesEstim_t estimator;             /* '<S1>/estimator' */
  sensordata_t BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1;
  CommandBus BusCreator;               /* '<S5>/Bus Creator' */
  real_T Grabber;                      /* '<S5>/Grabber' */
  real_T x_g;                          /* '<S5>/Chart' */
  real_T y_b;                          /* '<S5>/Chart' */
  real_T z_g;                          /* '<S5>/Chart' */
  real_T grabber_c;                    /* '<S5>/Chart' */
  real_T takeoff_flag;                 /* '<S5>/Chart' */
  real_T d;
  real32_T x_c;
  real32_T y_n;
  real32_T z_p;
  real32_T x_cd;
  real32_T y_nb;
  real32_T z_p1;
  real32_T altitude;
  real32_T pressure;
  real32_T controller_o2[8];           /* '<S1>/controller' */
  real32_T Max;                        /* '<S5>/Max' */
  real32_T rtb_vbat_V_m;
  uint32_T rtb_vbat_percentage_c;
  uint8_T u;
  boolean_T Compare_h;                 /* '<S9>/Compare' */
  boolean_T Compare_l;                 /* '<S12>/Compare' */
  boolean_T Compare_mb;                /* '<S10>/Compare' */
  B_Logging_flightControlSystem_T Logging;/* '<S1>/Logging' */
} B_FlightControlSystem_flightControlSystem_T;

/* Block states (default storage) for system '<Root>/Flight Control System' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S5>/Scope' */

  uint32_T is_c4_flightControlSystem;  /* '<S5>/Chart3' */
  uint32_T is_c2_flightControlSystem;  /* '<S5>/Chart2' */
  uint32_T is_c1_flightControlSystem;  /* '<S5>/Chart1' */
  uint32_T is_c3_flightControlSystem;  /* '<S5>/Chart' */
  uint32_T is_Takeoff;                 /* '<S5>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S5>/Chart3' */
  uint16_T temporalCounter_i1_d;       /* '<S5>/Chart2' */
  uint16_T temporalCounter_i1_p;       /* '<S5>/Chart1' */
  uint16_T temporalCounter_i1_g;       /* '<S5>/Chart' */
  uint16_T temporalCounter_i2;         /* '<S5>/Chart' */
  uint8_T is_active_c4_flightControlSystem;/* '<S5>/Chart3' */
  uint8_T is_active_c2_flightControlSystem;/* '<S5>/Chart2' */
  uint8_T is_active_c1_flightControlSystem;/* '<S5>/Chart1' */
  uint8_T is_active_c3_flightControlSystem;/* '<S5>/Chart' */
  DW_Logging_flightControlSystem_T Logging;/* '<S1>/Logging' */
  DW_Geofencingerror_flightControlSystem_T Normalcondition;/* '<S3>/Normal condition' */
  DW_Geofencingerror_flightControlSystem_T estimatorOpticalflowerror;
                                      /* '<S3>/estimator//Optical flow error' */
  DW_Geofencingerror_flightControlSystem_T Geofencingerror;/* '<S3>/Geofencing error' */
} DW_FlightControlSystem_flightControlSystem_T;

/* Block signals (default storage) */
typedef struct {
  real_T rowIdx_data[4960];
  real_T colIdx_data[4960];
  int32_T i_data[4960];
  uint8_T imageBuff_1[19200];
  uint8_T imageBuff_2[19200];
  uint8_T imageBuff_3[19200];
  uint8_T j_data[4960];
  real_T dy;                           /* '<Root>/Rate Transition' */
  real_T dx;                           /* '<Root>/Rate Transition' */
  real_T CastToDouble;                 /* '<S2>/Cast To Double' */
  real_T deltaX;                       /* '<S2>/MATLAB Function1' */
  real_T deltaY;                       /* '<S2>/MATLAB Function1' */
  boolean_T Submatrix[19200];          /* '<S2>/Submatrix' */
  real_T avgX;
  real_T avgY;
  boolean_T Compare;                   /* '<S20>/Compare' */
  boolean_T BW[19200];                 /* '<S2>/MATLAB Function' */
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
  uint8_T is_active_c6_flightControlSystem;/* '<S2>/MATLAB Function1' */
  uint8_T is_active_c5_flightControlSystem;/* '<S2>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S2>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S2>/MATLAB Function' */
  DW_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} DW_flightControlSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Actuators[4];               /* '<Root>/Actuators' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_flightControlSystem_T;

/* Parameters for system: '<S3>/Geofencing error' */
struct P_Geofencingerror_flightControlSystem_T_ {
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S13>/Constant'
                                        */
};

/* Parameters for system: '<Root>/Flight Control System' */
struct P_FlightControlSystem_flightControlSystem_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S7>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S8>/Constant'
                                      */
  real32_T CompareToConstant2_const; /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S9>/Constant'
                                      */
  real32_T CompareToConstant6_const; /* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S12>/Constant'
                                      */
  real32_T CompareToConstant3_const; /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S10>/Constant'
                                      */
  real32_T CompareToConstant5_const; /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S11>/Constant'
                                      */
  statesEstim_t Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S5>/Memory'
                                   */
  real_T landingOverrideLimit_Value;
                             /* Expression: landingAltitude-measurementTolerance
                              * Referenced by: '<S5>/landingOverrideLimit'
                              */
  real32_T Constant3_Value[3];         /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real32_T Constant2_Value;            /* Expression: landingAltitude
                                        * Referenced by: '<S5>/Constant2'
                                        */
  boolean_T Constant1_Value;           /* Expression: true
                                        * Referenced by: '<S5>/Constant1'
                                        */
  uint8_T Merge_InitialOutput;        /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S3>/Merge'
                                       */
  P_Geofencingerror_flightControlSystem_T Normalcondition;/* '<S3>/Normal condition' */
  P_Geofencingerror_flightControlSystem_T estimatorOpticalflowerror;
                                      /* '<S3>/estimator//Optical flow error' */
  P_Geofencingerror_flightControlSystem_T Geofencingerror;/* '<S3>/Geofencing error' */
};

/* Parameters (default storage) */
struct P_flightControlSystem_T_ {
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S20>/Constant'
                                      */
  real_T RateTransition_1_InitialCondition;/* Expression: 0
                                            * Referenced by: '<Root>/Rate Transition'
                                            */
  real_T RateTransition_2_InitialCondition;/* Expression: 0
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
extern boolean_T rtP_enableLanding;    /* Variable: enableLanding
                                        * Referenced by: '<S5>/Constant'
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
extern uint8_T flag_outport;           /* '<S3>/Merge' */

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
 * '<S3>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags'
 * '<S4>'   : 'flightControlSystem/Flight Control System/Logging'
 * '<S5>'   : 'flightControlSystem/Flight Control System/landing logic'
 * '<S6>'   : 'flightControlSystem/Flight Control System/sensordata_group'
 * '<S7>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant'
 * '<S8>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant1'
 * '<S9>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant2'
 * '<S10>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant3'
 * '<S11>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant5'
 * '<S12>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant6'
 * '<S13>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Geofencing error'
 * '<S14>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Normal condition'
 * '<S15>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/estimator//Optical flow error'
 * '<S16>'  : 'flightControlSystem/Flight Control System/landing logic/Chart'
 * '<S17>'  : 'flightControlSystem/Flight Control System/landing logic/Chart1'
 * '<S18>'  : 'flightControlSystem/Flight Control System/landing logic/Chart2'
 * '<S19>'  : 'flightControlSystem/Flight Control System/landing logic/Chart3'
 * '<S20>'  : 'flightControlSystem/Image Processing System/Compare To Constant2'
 * '<S21>'  : 'flightControlSystem/Image Processing System/MATLAB Function'
 * '<S22>'  : 'flightControlSystem/Image Processing System/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_flightControlSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
