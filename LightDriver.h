#ifndef SRC_LIGHT_DRIVER_H_
#define SRC_LIGHT_DRIVER_H_

typedef struct LightDriverStruct *LightDriver;

typedef enum LightDriverType {
  TestLightDriver,
  X10,
  AcmeWireless,
  MemoryMapped
} LightDriverTyep;

typedef struct LightDriverStruct {
  LightDriverType type;
  int id;
} LightDriverStruct;

#endif  // SRC_LIGHT_DRIVER_H_