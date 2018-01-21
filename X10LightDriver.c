#include "X10LightDriver.h"

typedef struct X10LightDriverStruct *X10LightDriver;
typedef struct X10LightDriverStruct {
  LightDriverStruct base;
  X10_HouseCode house;
  uint32_t unit;
  char message[MAX_X10_MESSAGE_LENGTH];
} X10LightDriverStruct;

static void formatTurnOnMessage(X10LightDriver self)
{
  // Nothing to do in test environment
}

static void formatTurnOffMessage(X10LightDriver self)
{
  // Nothing to do in test environment
}

static void sendMessage(X10LightDriver self)
{
  // Nothing to do in test environment
}

LightDriver X10LightDriver_Create(int id, X10_HouseCode house, uint32_t unit) {
  X10LightDriver self = calloc(1, sizeof(X10LightDriverStruct));
  self->base.type = X10;
  self->base.id = id;
  self->house = house;
  self->unit = unit;
  return (LightDriver)self;
}

void X10LightDriver_TurnOn(LightDriver base) {
  X10LightDriver self = (X10LightDriver)base;
  formatTrunOnMessage(self);
  sendMessage(self);
}

void X10LightDriver_TurnOff(LightDriver base) {
  X10LightDriver self = (X10LightDriver)base;
  formatTurnOffMessage(self);
  sendMessage(self);
}