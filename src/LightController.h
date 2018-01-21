#ifndef SRC_LIGHT_CONTROLLER_H_
#define SRC_LIGHT_CONTROLLER_H_

#include "LightDriver.h"

enum {MAX_LIGHTS = 32};
void LightController_Create();
void LightController_Destroy();
bool LightController_Add(int id, LightDriver);
void LightController_TurnOn(int id);
void LightController_TurnOff(int id);

#endif //SRC_LIGHT_CONTROLLER_H_
