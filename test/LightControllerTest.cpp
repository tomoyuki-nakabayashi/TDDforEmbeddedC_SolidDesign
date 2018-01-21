#include "gtest/gtest.h"
extern "C" {
  #include "LightController.h"
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
  EXPECT_EQ(true);
}
}  // namespace light_controller_test