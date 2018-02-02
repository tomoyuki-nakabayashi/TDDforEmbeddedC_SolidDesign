#include "gtest/gtest.h"
extern "C" {
  #include "LightDriver.h"
}

namespace light_driver_test {
constexpr LightDriver kNonNullPointer = reinterpret_cast<LightDriver>(0xDEADBEEF);
static LightDriver savedDriver = kNonNullPointer;
// Helper function.
static void shouldNotBeCalled(LightDriver self) {
  savedDriver = self;
}

class LightDriverTest : public ::testing::Test
{
 public:
    LightDriverTest()
        : interface_ {shouldNotBeCalled, shouldNotBeCalled, shouldNotBeCalled}
        , test_driver_ {TestLightDriver, 13} {

    }
 protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
 protected:
    LightDriverInterfaceStruct interface_;
    LightDriverStruct test_driver_;
};

TEST_F(LightDriverTest, NullDriverDoesNotCrash) {
  LightDriver_SetInterface(&interface_);
  LightDriver_TurnOn(NULL);
  LightDriver_TurnOff(NULL);
  LightDriver_Destroy(NULL);
  EXPECT_EQ(kNonNullPointer, savedDriver);
}

TEST_F(LightDriverTest, NullInterfaceDoesNotCrash) {
  LightDriver_SetInterface(NULL);
  LightDriver_TurnOn(&test_driver_);
  LightDriver_TurnOff(&test_driver_);
  LightDriver_Destroy(&test_driver_);
  EXPECT_EQ(kNonNullPointer, savedDriver);
}
}  // namespace light_driver_test