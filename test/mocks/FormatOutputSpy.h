#ifndef TEST_MOCKS_FORMAT_OUTPUT_SPY_H_
#define TEST_MOCKS_FORMAT_OUTPUT_SPY_H_

#include "util/Utils.h"

void FormatOutputSpy_Create(int len);
void FormatOutputSpy_Destroy(void);
char* FormatOutputSpy_GetOutput(void);
int FormatOutputSpy(const char *format, ...);

#endif //TEST_MOCKS_FORMAT_OUTPUT_SPY_H_