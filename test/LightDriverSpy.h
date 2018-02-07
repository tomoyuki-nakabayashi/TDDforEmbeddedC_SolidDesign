#ifndef TEST_LIGHT_DRIVER_SPY_H_
#define TEST_LIGHT_DRIVER_SPY_H_
#include "LightDriverPrivate.h"
#include "LightController.h"

LightDriver LightDriverSpy_Create(int id);
void LightDriverSpy_Destroy(LightDriver);
void LightDriverSpy_TurnOn(LightDriver);
void LightDriverSpy_TurnOff(LightDriver);

// Only for spy
void LightDriverSpy_Reset(void);
int LightDriverSpy_GetState(int id);
void LightDriverSpy_AddSpiesToController(void);

enum {
  LIGHT_ID_UNKNOWN = -1,
  LIGHT_STATE_UNKNOWN = -1,
  LIGHT_OFF = 0,
  LIGHT_ON = 1
};

#endif  // TEST_LIGHT_DRIVER_SPY_H_