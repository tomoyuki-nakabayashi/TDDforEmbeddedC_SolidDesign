#include "gtest/gtest.h"
extern "C" {
  #include "LightDriverSpy.h"
}

namespace light_driver_spy_test{
constexpr int kTestId = 3;

class LightDriverSpyTest : public ::testing::Test
{
 protected:
    virtual void SetUp()
    {
      LightDriverSpy_Reset();
      LightDriver spy_ = LightDriverSpy_Create(kTestId);
    }
    virtual void TearDown()
    {
      LightDriverSpy_Destroy(spy_);
    }

 protected:
    LightDriver spy_;
};

TEST_F(LightDriverSpyTest, On)
{
  LightDriverSpy_TurnOn(spy_);
  EXPECT_EQ(LIGHT_ON, LightDriverSpy_GetState(kTestId));
}
}  // namespace light_driver_spy_test