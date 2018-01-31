#include "gtest/gtest.h"
extern "C" {
  #include "LightDriverSpy.h"
}

namespace light_driver_spy_test{
class LightDriverSpyTest : public ::testing::Test
{
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_F(LightDriverSpyTest, FirstTest)
{
  EXPECT_TRUE(true);
}
}  // namespace light_driver_spy_test