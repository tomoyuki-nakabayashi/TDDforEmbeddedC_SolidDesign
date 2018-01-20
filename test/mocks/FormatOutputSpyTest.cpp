#include "gtest/gtest.h"
extern "C" {
  #include "FormatOutputSpy.h"
}

namespace format_output_spy_test {
  class FormatOutputSpyTest : public ::testing::Test
  {
    virtual void SetUp()
    {
      savedFormatOutput = FormatOutput;
      FormatOutput = FormatOutputSpy;
    }
    virtual void TearDown()
    {
      FormatOutput = savedFormatOutput;
      FormatOutputSpy_Destroy();
    }
    protected:
      int (*savedFormatOutput)(const char* format, ...);
  };

  TEST_F(FormatOutputSpyTest, HelloWorld)
  {
    FormatOutputSpy_Create(20);
    FormatOutput("Hello, World\n");
    EXPECT_STREQ("Hello, World\n", FormatOutputSpy_GetOutput());
  }

  TEST_F(FormatOutputSpyTest, LimitTheOutputBufferSize)
  {
    FormatOutputSpy_Create(4);
    FormatOutput("Hello, World\n");
    EXPECT_STREQ("Hell", FormatOutputSpy_GetOutput());
  }

  TEST_F(FormatOutputSpyTest, PrintMultipleTimes)
  {
    FormatOutputSpy_Create(25);
    FormatOutput("Hello");
    FormatOutput(", World\n");
    EXPECT_STREQ("Hello, World\n", FormatOutputSpy_GetOutput());
  }

  TEST_F(FormatOutputSpyTest, PrintMultipleOutputsPastFull)
  {
    FormatOutputSpy_Create(12);
    FormatOutput("12345");
    FormatOutput("67890");
    FormatOutput("ABCDEF");
    EXPECT_STREQ("1234567890AB", FormatOutputSpy_GetOutput());
  }
}