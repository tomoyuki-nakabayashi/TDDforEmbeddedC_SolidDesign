#include "LightController.h"
#include <stdlib.h>
#include <memory.h>
#include "X10LightDriver.h"
#include "LightDriverSpy.h"

static LightDriver lightDrivers[MAX_LIGHTS] = {NULL};

/* void implementations. */
void LightController_Create()
{
  memset(lightDrivers, 0, sizeof lightDrivers);
}

static void destroy(LightDriver driver) {
  if (!driver) return;

  switch (driver->type) {
    case X10:
      X10LightDriver_Destroy(driver);
      break;
    case AcmeWireless:
      break;
    case MemoryMapped:
      break;
    case TestLightDriver:
      LightDriverSpy_Destroy(driver);
      break;
    default:
      break;
  }
}

void LightController_Destroy()
{
  for (int i = 0; i < MAX_LIGHTS; i++) {
    LightDriver driver = lightDrivers[i];
    destroy(driver);
    lightDrivers[i] = NULL;
  }
}

bool LightController_Add(int id, LightDriver lightDriver)
{
  if (id < 0 || id >= MAX_LIGHTS)
    return false;

  destroy(lightDrivers[id]);

  lightDrivers[id] = lightDriver;
  return true;
}

void LightController_TurnOn(int id)
{
  LightDriver driver = lightDrivers[id];
  if (driver == NULL) return;

  switch (driver->type) {
    case X10:
      X10LightDriver_TurnOn(driver);
      break;
    case AcmeWireless:
      break;
    case MemoryMapped:
      break;
    case TestLightDriver:
      LightDriverSpy_TurnOn(driver);
      break;
    default:
      break;
  }
}

void LightController_TurnOff(int id)
{
  LightDriver driver = lightDrivers[id];
  if (driver == NULL) return;

  switch (driver->type) {
    case X10:
      X10LightDriver_TurnOff(driver);
      break;
    case AcmeWireless:
      break;
    case MemoryMapped:
      break;
    case TestLightDriver:
      LightDriverSpy_TurnOff(driver);
      break;
    default:
      break;
  }
}
