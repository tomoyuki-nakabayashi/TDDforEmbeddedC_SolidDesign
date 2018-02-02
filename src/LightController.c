#include "LightController.h"
#include <stdlib.h>
#include <memory.h>

static LightDriver lightDrivers[MAX_LIGHTS] = {NULL};

/* void implementations. */
void LightController_Create()
{
  memset(lightDrivers, 0, sizeof lightDrivers);
}

void LightController_Destroy()
{
  for (int i = 0; i < MAX_LIGHTS; i++) {
    LightDriver driver = lightDrivers[i];
    LightDriver_Destroy(driver);
    lightDrivers[i] = NULL;
  }
}

bool LightController_Add(int id, LightDriver lightDriver)
{
  if (id < 0 || id >= MAX_LIGHTS)
    return false;

  LightDriver_Destroy(lightDrivers[id]);

  lightDrivers[id] = lightDriver;
  return true;
}

void LightController_TurnOn(int id)
{
  LightDriver_TurnOn(lightDrivers[id]);
}

void LightController_TurnOff(int id)
{
  LightDriver_TurnOff(lightDrivers[id]);
}
