#include "FormatOutputSpy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *buffer = NULL;
static int buffer_size = 0;
static int buffer_offset = 0;
static int buffer_used = 0;

void FormatOutputSpy_Create(int len)
{
  FormatOutputSpy_Destroy();
  buffer_size = len+1;
  buffer = (char *)malloc(buffer_size);
  memset(buffer, '\0', buffer_size);
  buffer_offset = 0;
  buffer_used = 0;
}

void FormatOutputSpy_Destroy(void)
{
  if(buffer == NULL) 
    return;

  free(buffer);
  buffer = NULL;
}

char* FormatOutputSpy_GetOutput(void)
{
  return buffer;
}

int FormatOutputSpy(const char *format, ...)
{
  va_list arguments;
  va_start(arguments, format);
  int written_size = vsnprintf(buffer + buffer_offset,
    buffer_size - buffer_used, format, arguments);
  va_end(arguments);

  buffer_offset += written_size;
  buffer_used += written_size;

  return written_size;
}