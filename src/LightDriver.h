#ifndef SRC_LIGHT_DRIVER_H_
#define SRC_LIGHT_DRIVER_H_

struct LightDriverInterfaceStruct;
typedef struct LightDriverInterfaceStruct* LightDriverInterface;
typedef struct LightDriverStruct *LightDriver;

typedef enum LightDriverType {
  TestLightDriver,
  X10,
  AcmeWireless,
  MemoryMapped
} LightDriverType;

typedef struct LightDriverStruct {
  LightDriverType type;
  int id;
} LightDriverStruct;

void LightDriver_SetInterface(LightDriverInterface i);
void LightDriver_TurnOn(LightDriver self);

#endif  // SRC_LIGHT_DRIVER_H_