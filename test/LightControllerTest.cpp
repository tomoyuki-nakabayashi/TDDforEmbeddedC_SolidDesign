#include "gtest/gtest.h"
extern "C" {
  #include "LightController.h"
  #include "LightDriver.h"
  #include "LightDriverSpy.h"
}

namespace light_controller_test{

class LightControllerTest : public ::testing::Test
{
 protected:
    virtual void SetUp()
    {
      LightController_Create();
      LightDriverSpy_AddSpiesToController();
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
  LightController_TurnOn(7);
  EXPECT_EQ(LIGHT_ON, LightDriverSpy_GetState(7));
}
}  // namespace light_controller_test