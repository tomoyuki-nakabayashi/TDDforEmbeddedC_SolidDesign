#include "LightDriver.h"
#include "LightDriverPrivate.h"
#include <stdlib.h>
#include <stdbool.h>

static LightDriverInterface interface = NULL;

void LightDriver_SetInterface(LightDriverInterface i) {
  interface = i;
}

static bool isValid(LightDriver self)
{
    return interface && self;
}

void LightDriver_TurnOn(LightDriver self) {
  if (isValid(self))
    interface->TurnOn(self);
}

void LightDriver_TurnOff(LightDriver self) {
  if (isValid(self))
    interface->TurnOff(self);
}

void LightDriver_Destroy(LightDriver self) {
  if (isValid(self))
    interface->Destroy(self);
}
