#include "X10LightDriver.h"
#include <stdint.h>

typedef struct X10LightDriverStruct *X10LightDriver;
typedef struct X10LightDriverStruct {
  LightDriverStruct base;
  X10_HouseCode house;
  uint32_t unit;
  char message[MAX_X10_MESSAGE_LENGTH];
} X10LightDriverStruct;