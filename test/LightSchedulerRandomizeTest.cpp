#include "gtest/gtest.h"
extern "C" {
  #include "FakeRandomMinute.h"
  #include "LightScheduler.h"
  #include "LightController.h"
  #include "LightControllerSpy.h"
  #include "FakeTimeService.h"
}

namespace light_scheduler_randomize_test{
  enum {BOUND=30};

  class LightSchedulerRandomize : public ::testing::Test
  {
    virtual void SetUp()
    {
      LightController_Create();
      LightScheduler_Create();
      savedRandomMinute_Get = RandomMinute_Get;
      RandomMinute_Get = FakeRandomMinute_Get;
    }
    virtual void TearDown()
    {
      LightScheduler_Destroy();
      LightController_Destroy();
      RandomMinute_Get = savedRandomMinute_Get;
    }
  protected:
    int (*savedRandomMinute_Get)();
    void setTimeTo(int day, int minuteOfDay)
    {
      FakeTimeService_SetDay(day);
      FakeTimeService_SetMinute(minuteOfDay);
    }

    void checkLightState(int id, int level)
    {
      if(id == LIGHT_ID_UNKNOWN)
      {
        EXPECT_EQ(id, LightControllerSpy_GetLastId());
        EXPECT_EQ(level, LightControllerSpy_GetLastState());
      }
      else
      {
        EXPECT_EQ(level, LightControllerSpy_GetLightState(id));
      }
    }
  };

  TEST_F(LightSchedulerRandomize, TurnsOnEarly)
  {
    FakeRandomMinute_SetFirstAndIncrement(-10, 5);
    LightScheduler_ScheduleTurnOn(4, EVERYDAY, 600);
    LightScheduler_Randomize(4, EVERYDAY, 600);
    setTimeTo(MONDAY, 600-10);
    LightScheduler_Wakeup();
    checkLightState(4, LIGHT_ON);
  }
} // namespace