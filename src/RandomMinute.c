#include "RandomMinute.h"
#include <stdlib.h>

static int bound = 0;

void RandomMinute_Create(int b)
{
  bound = b;
  srand(10);
}

int RandomMinute_GetImpl(void)
{
    return bound - rand() % (bound * 2 + 1);
}

int (*RandomMinute_Get)(void) = RandomMinute_GetImpl;