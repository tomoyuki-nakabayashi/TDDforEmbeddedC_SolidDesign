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

static void destroy(LightDriver base) {
  free(base);
}

static void update(int id, int state)
{
  states[id] = state;
  lastId = id;
  lastState = state;
}

static void turnOn(LightDriver base) {
  LightDriverSpy self = (LightDriverSpy)base;
  update(self->base.id, LIGHT_ON);
}

static void turnOff(LightDriver base) {
  LightDriverSpy self = (LightDriverSpy)base;
  update(self->base.id, LIGHT_OFF);
}

static LightDriverInterfaceStruct interface = {
  .Destroy = destroy,
  .TurnOn = turnOn,
  .TurnOff = turnOff
};

LightDriver LightDriverSpy_Create(int id) {
  LightDriverSpy self = calloc(1, sizeof(LightDriverSpyStruct));
  self->base.vtable = &interface;
  self->base.type = "Spy";
  self->base.id = id;
  return (LightDriver)self;
}

void LightDriverSpy_Reset() {
  for (int i = 0; i < MAX_LIGHTS; i++)
    states[i] = LIGHT_STATE_UNKNOWN;
  lastId = LIGHT_ID_UNKNOWN;
  lastState = LIGHT_STATE_UNKNOWN;
}

int LightDriverSpy_GetState(int id) {
  return states[id];
}

void LightDriverSpy_AddSpiesToController(void) {
  int i;
  for (i = 0; i < MAX_LIGHTS; i++)
  {
    LightDriver spy = (LightDriver)LightDriverSpy_Create(i);
    LightController_Add(i, spy);
  }
}

