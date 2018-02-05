#include "CountingLightDriver.h"
#include <stdlib.h>

typedef struct CountingLightDriverStruct *CountingLightDriver;
typedef struct CountingLightDriverStruct {
  LightDriverStruct base;
  int counter;
} CountingLightDriverStruct;

static void count(LightDriver base) {
  CountingLightDriver self = (CountingLightDriver)base;
  self->counter++;
}

LightDriver CountingLightDriver_Create(int id) {
  CountingLightDriver self = calloc(1, sizeof(CountingLightDriverStruct));
  self->base.type = "CountingLightDriver";
  self->base.id = id;
  return (LightDriver)self;
}

static void destroy(LightDriver base) {
  free(base);
}

static void turnOn(LightDriver base) {
  count(base);
}

static void turnOff(LightDriver base) {
  count(base);
}

static LightDriverInterfaceStruct interface = {
  .Destroy = destroy,
  .TurnOn = turnOn,
  .TurnOff = turnOff
};

int CountingLightDriver_GetCallCount(LightDriver base) {
  CountingLightDriver self = (CountingLightDriver)base;
  return self->counter;
}
