#ifndef SRC_LIGHT_DRIVER_PRIVATE_H_
#define SRC_LIGHT_DRIVER_PRIVATE_H_

#include "LightDriver.h"

typedef struct LightDriverInterfaceStruct {
  void (*TurnOn)(LightDriver);
  void (*TurnOff)(LightDriver);
  void (*Destroy)(LightDriver);
} LightDriverInterfaceStruct;

#endif  // SRC_LIGHT_DRIVER_PRIVATE_H_