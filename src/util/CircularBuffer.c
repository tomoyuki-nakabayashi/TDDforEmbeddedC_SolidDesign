#include "CircularBuffer.h"
#include "Utils.h"
#include <stdlib.h>

typedef struct CircularBufferStruct
{
  int *values;
  int count;
  int capacity;
  int index;
  int outdex;
} CircularBufferStruct;

enum {BUFFER_GUARD = -1};

CircularBuffer CircularBuffer_Create(int capacity)
{
  CircularBuffer self = calloc(1, sizeof(CircularBufferStruct));
  self->values = calloc(capacity, sizeof(int));
  self->count = 0;
  self->capacity = capacity;
  self->index = 0;
  self->outdex = 0;
  return self;
}

void CircularBuffer_Destroy(CircularBuffer self)
{
  free(self->values);
  free(self);
}

void CircularBuffer_Print(CircularBuffer self)
{
  FormatOutput("Circular buffer content:\n<");
  int currentValue = self->outdex;
  for(int i=0; i<self->count; i++)
  {
    if(i != 0)
      FormatOutput(", ");

    FormatOutput("%d", self->values[currentValue++]);
    if(currentValue >= self->capacity)
      currentValue = 0;
  }
  FormatOutput(">\n");
}

void CircularBuffer_Put(CircularBuffer self, int value)
{
  if(self == NULL) return;
  if(self->values == NULL) return;

  self->values[self->index++] = value;
  if(self->index >= self->capacity)
    self->index = 0;
  self->count++;
}

int CircularBuffer_Get(CircularBuffer self)
{
  self->count--;
  return self->values[self->outdex++];
}