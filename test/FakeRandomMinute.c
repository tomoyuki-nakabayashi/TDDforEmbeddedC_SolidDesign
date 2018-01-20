#include "FakeRandomMinute.h"

static int randomValue;
static int inc;

void FakeRandomMinute_SetFirstAndIncrement(int value, int i)
{
  randomValue = value;
  inc = i;
}

int FakeRandomMinute_Get(void)
{
  int ret = randomValue;
  randomValue += inc;
  return ret;
}