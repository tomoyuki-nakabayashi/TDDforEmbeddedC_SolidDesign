#include "gtest/gtest.h"
extern "C" {
  #include "LightController.h"
  #include "LightDriver.h"
}

namespace light_controller_test{

class LightControllerTest : public ::testing::Test
{
  virtual void SetUp()
  {
  }
  virtual void TearDown()
  {
  }
};

TEST_F(LightControllerTest, FirstTest)
{
  EXPECT_TRUE(true);
}
}  // namespace light_controller_test