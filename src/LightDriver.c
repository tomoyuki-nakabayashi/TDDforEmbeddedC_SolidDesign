#include "LightDriver.h"
#include "LightDriverPrivate.h"
#include <stdlib.h>
#include <stdbool.h>

void LightDriver_TurnOn(LightDriver self) {
  if (self && self->vtable && self->vtable->TurnOn)
    self->vtable->TurnOn(self);
}

void LightDriver_TurnOff(LightDriver self) {
  if (self && self->vtable && self->vtable->TurnOff)
    self->vtable->TurnOff(self);
}

void LightDriver_Destroy(LightDriver self) {
  if (self && self->vtable && self->vtable->Destroy)
    self->vtable->Destroy(self);
}
