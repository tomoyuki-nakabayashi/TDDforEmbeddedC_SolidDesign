#ifndef SRC_X10_LIGHT_DRIVER_H_
#define SRC_X10_LIGHT_DRIVER_H_

#include "LightDriver.h"

#define MAX_X10_MESSAGE_LENGTH 64

typedef enum X10_HouseCode {
  X10_A, X10_B, X10_C, X10_D, X10_E, X10_F,
  X10_G, X10_H, X10_I, X10_J, X10_K, X10_L,
  X10_M, X10_N, X10_O, X10_P
} X10_HouseCode;

#endif  // SRC_X10_LIGHT_DRIVER_H_