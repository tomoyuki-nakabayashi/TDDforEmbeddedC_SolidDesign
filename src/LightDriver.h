#ifndef SRC_LIGHT_DRIVER_H_
#define SRC_LIGHT_DRIVER_H_

typedef struct LightDriverInterfaceStruct* LightDriverInterface;
typedef struct LightDriverStruct *LightDriver;

typedef struct LightDriverStruct {
  LightDriverInterface vtable;
  const char *type;
  int id;
} LightDriverStruct;

void LightDriver_TurnOn(LightDriver self);
void LightDriver_TurnOff(LightDriver self);
void LightDriver_Destroy(LightDriver self);

#include "LightDriverPrivate.h"

#endif  // SRC_LIGHT_DRIVER_H_