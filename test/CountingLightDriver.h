#ifndef TEST_COUNTING_LIGHT_DRIVER_H_
#define TEST_COUNTING_LIGHT_DRIVER_H_
#include "LightDriverPrivate.h"
#include "LightController.h"

LightDriver CountingLightDriver_Create(int id);
void CountingLightDriver_Destroy(LightDriver);
void CountingLightDriver_TurnOn(LightDriver);
void CountingLightDriver_TurnOff(LightDriver);

int CountingLightDriver_GetCallCount(LightDriver);
#endif  // TEST_COUNTING_LIGHT_DRIVER_H_