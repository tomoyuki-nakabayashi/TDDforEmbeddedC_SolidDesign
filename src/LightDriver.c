#include "LightDriver.h"
#include "LightDriverPrivate.h"
#include <stdlib.h>

static LightDriverInterface interface = NULL;

void LightDriver_SetInterface(LightDriverInterface i) {
  interface = i;
}

void LightDriver_TurnOn(LightDriver self) {
  interface->TurnOn(self);
}

void LightDriver_TurnOff(LightDriver self) {
  interface->TurnOff(self);
}
