#include "gtest/gtest.h"
extern "C" {
  #include "LightController.h"
  #include "LightDriver.h"
  #include "LightDriverSpy.h"
  #include "CountingLightDriver.h"
}

namespace light_controller_test{

class LightControllerTest : public ::testing::Test
{
 protected:
    virtual void SetUp()
    {
      LightController_Create();
      LightDriverSpy_AddSpiesToController();
      LightDriverSpy_Reset();
    }
    virtual void TearDown()
    {
      LightController_Destroy();
    }
 protected:
    LightDriver spy_;
};

TEST_F(LightControllerTest, TurnOn)
{
  LightDriver spy = LightDriverSpy_Create(7);
  LightController_Add(7, spy);
  LightController_TurnOn(7);
  EXPECT_EQ(LIGHT_ON, LightDriverSpy_GetState(7));
}

TEST_F(LightControllerTest, TurnOnDifferentDriverTypes) {
  LightDriver otherDriver = CountingLightDriver_Create(5);
  LightController_Add(5, otherDriver);
  LightController_TurnOn(7);
  LightController_TurnOn(5);
  LightController_TurnOff(5);

  EXPECT_EQ(LIGHT_ON, LightDriverSpy_GetState(7));
  EXPECT_EQ(2, CountingLightDriver_GetCallCount(otherDriver));
}
}  // namespace light_controller_test
