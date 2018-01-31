#include <stdlib.h>
#include <memory.h>
#include "LightDriverSpy.h"

typedef struct LightDriverSpyStruct *LightDriverSpy;
typedef struct LightDriverSpyStruct {
  LightDriverStruct base;
} LightDriverSpyStruct;

static int states[MAX_LIGHTS];
static int lastId;
static int lastState;

LightDriver LightDriverSpy_Create(int id) {
  LightDriverSpy self = calloc(1, sizeof(LightDriverSpyStruct));
  self->base.type = TestLightDriver;
  self->base.id = id;
  return (LightDriver)self;
}

void LightDriverSpy_Destroy(LightDriver super) {
  LightDriverSpy self = (LightDriverSpy)super;
  states[self->base.id] = LIGHT_STATE_UNKNOWN;
  free(self);
}

static void save(int id, int state)
{
  states[id] = state;
  lastId = id;
  lastState = state;
}

void LightDriverSpy_TurnOn(LightDriver super) {
  LightDriverSpy self = (LightDriverSpy)super;
  save(self->base.id, LIGHT_ON);
}

void LightDriverSpy_TurnOff(LightDriver super) {
  LightDriverSpy self = (LightDriverSpy)super;
  save(self->base.id, LIGHT_OFF);
}