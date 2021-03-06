#include "gtest/gtest.h"
extern "C" {
  #include "LightDriver.h"
  #include "LightDriverSpy.h"
}

namespace light_driver_spy_test{
class LightDriverSpyTest : public ::testing::Test
{
 protected:
    virtual void SetUp()
    {
      LightDriverSpy_Reset();
      spy_ = LightDriverSpy_Create(1);
    }
    virtual void TearDown()
    {
      LightDriver_Destroy(spy_);
    }

 protected:
    LightDriver spy_;
};

TEST_F(LightDriverSpyTest, Create) {
  EXPECT_EQ(LIGHT_STATE_UNKNOWN, LightDriverSpy_GetState(1));
}

TEST_F(LightDriverSpyTest, On) {
  LightDriver_TurnOn(spy_);
  EXPECT_EQ(LIGHT_ON, LightDriverSpy_GetState(1));
}

TEST_F(LightDriverSpyTest, Off) {
  LightDriver_TurnOff(spy_);
  EXPECT_EQ(LIGHT_OFF, LightDriverSpy_GetState(1));
}
}  // namespace light_driver_spy_test