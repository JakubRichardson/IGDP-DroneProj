/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>
#include "rt_logging.h"
#include "MW_target_hardware_resources.h"
#ifndef SAVEFILE
#define MATFILE2(file)                 #file ".mat"
#define MATFILE1(file)                 MATFILE2(file)
#define MATFILE                        MATFILE1(MODEL)
#else
#define QUOTE1(name)                   #name
#define QUOTE(name)                    QUOTE1(name)              /* need to expand name */
#define MATFILE                        QUOTE(SAVEFILE)
#endif

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Global variables used by function prototype control */

  /* '<Root>/ReferenceValueServerBus' */
  static CommandBus arg_ReferenceValueServerBus = {
    false,                             /* controlModePosVSOrient */

    {
      0.0F, 0.0F, 0.0F }
    ,                                  /* pos_ref */
    false,                             /* takeoff_flag */

    {
      0.0F, 0.0F, 0.0F }
    ,                                  /* orient_ref */
    0U,                                /* live_time_ticks */
    false                              /* landing_flag */
  };

  /* '<Root>/states_estim' */
  static statesEstim_t arg_states_estim = {
    0.0F,                              /* X */
    0.0F,                              /* Y */
    0.0F,                              /* Z */
    0.0F,                              /* yaw */
    0.0F,                              /* pitch */
    0.0F,                              /* roll */
    0.0F,                              /* dx */
    0.0F,                              /* dy */
    0.0F,                              /* dz */
    0.0F,                              /* p */
    0.0F,                              /* q */
    0.0F                               /* r */
  };

  /* '<Root>/motors_refout' */
  static real32_T arg_motors_refout[4];

  /* '<Root>/pose_refout' */
  static real32_T arg_pose_refout[8];

  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  flightController_run(&arg_ReferenceValueServerBus, &arg_states_estim,
                       arg_motors_refout, arg_pose_refout);

  /* Get model outputs here */
  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

#define UNUSED(x)                      x = x

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.005;
  float systemClock = 416;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  UNUSED(modelBaseRate);
  UNUSED(systemClock);
  rtmSetErrorStatus(flightController_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  flightController_initialize();
  ;
  ;

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(flightController_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(flightController_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(flightController_M, true);
    }
  }

  rtERTExtModeStartMsg();
  ;
  runModel = (rtmGetErrorStatus(flightController_M) == (NULL)) &&
    !rtmGetStopRequested(flightController_M);
  ;
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(flightController_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(flightController_M, true);
      }
    }

    rt_OneStep();
    stopRequested = !((rtmGetErrorStatus(flightController_M) == (NULL)) &&
                      !rtmGetStopRequested(flightController_M));
    runModel = !(stopRequested);
  }

  rt_StopDataLogging(MATFILE, flightController_M->rtwLogInfo);

  /* Terminate model */
  flightController_terminate();

  /* External mode shutdown */
  rtExtModeShutdown(1);
  ;
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
