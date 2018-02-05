#ifndef SRC_LIGHT_DRIVER_H_
#define SRC_LIGHT_DRIVER_H_

typedef struct LightDriverInterfaceStruct* LightDriverInterface;
typedef struct LightDriverStruct *LightDriver;

typedef enum LightDriverType {
  TestLightDriver,
  X10,
  AcmeWireless,
  MemoryMapped
} LightDriverType;

typedef struct LightDriverStruct {
  char *type;
  int id;
} LightDriverStruct;

void LightDriver_SetInterface(LightDriverInterface i);
void LightDriver_TurnOn(LightDriver self);
void LightDriver_TurnOff(LightDriver self);
void LightDriver_Destroy(LightDriver self);

#include "LightDriverPrivate.h"

#endif  // SRC_LIGHT_DRIVER_H_