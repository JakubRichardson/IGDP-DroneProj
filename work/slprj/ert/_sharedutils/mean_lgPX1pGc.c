/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mean_lgPX1pGc.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 8.52
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Nov 14 16:47:04 2024
 */

#include "rtwtypes.h"
#include "mean_lgPX1pGc.h"

/* Function for MATLAB Function: '<S2>/MATLAB Function1' */
real_T mean_lgPX1pGc(const real_T x_data[], const int32_T *x_size)
{
  real_T b_y;
  real_T bsum;
  int32_T b_k;
  int32_T firstBlockLength;
  int32_T hi;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T xblockoffset;
  if (*x_size <= 1024) {
    firstBlockLength = *x_size;
    lastBlockLength = 0;
    nblocks = 1;
  } else {
    firstBlockLength = 1024;
    nblocks = (int32_T)((uint32_T)*x_size >> 10);
    lastBlockLength = *x_size - (nblocks << 10);
    if (lastBlockLength > 0) {
      nblocks++;
    } else {
      lastBlockLength = 1024;
    }
  }

  b_y = x_data[0];
  for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
    b_y += x_data[xblockoffset - 1];
  }

  for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++) {
    xblockoffset = (firstBlockLength - 1) << 10;
    bsum = x_data[xblockoffset];
    if (firstBlockLength == nblocks) {
      hi = lastBlockLength;
    } else {
      hi = 1024;
    }

    for (b_k = 2; b_k <= hi; b_k++) {
      bsum += x_data[(xblockoffset + b_k) - 1];
    }

    b_y += bsum;
  }

  return b_y / (real_T)*x_size;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
