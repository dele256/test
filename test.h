/*
  MIT License

  Copyright (c) 2021 dele256

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  ==============================================================================

  test - v1.01

  REVISION HISTORY:
    1.01 (2021-12-05) remove inline keyword
    1.00 (2021-07-13) first version

  ==============================================================================
*/

#ifndef TEST_H
#define TEST_H

#include <stdio.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"

typedef struct
{
  int passed;
  int failed;
} summary_t;

static void print_summary(summary_t *sum)
{
  printf(
      "\n%s[SUM] %d/%d passed.%s\n",
      sum->failed == 0 ? KGRN : KRED,
      sum->passed,
      sum->passed + sum->failed,
      KNRM);
}

#define BEGIN_TEST(name) \
  static void test_##name(const char *test_name, int *tested, int *passed, int *failed)

#define REQUIRE(required)                                \
  do {                                                   \
    ++(*tested);                                         \
    if (required) {                                      \
      ++(*passed);                                       \
    } else {                                             \
      printf(                                            \
          "%s[FAIL]%s %s#%d -- %s:%d\n",                 \
          KRED,                                          \
          KNRM,                                          \
          test_name,                                     \
          *tested,                                       \
          __FILE__,                                      \
          __LINE__);                                     \
      printf("  %s[EXP]%s %s\n", KRED, KNRM, #required); \
      ++(*failed);                                       \
    }                                                    \
  } while (0)

#define RUN_TEST(sum, name)                                \
  do {                                                     \
    int tested = 0;                                        \
    int pre_next = sum.failed;                             \
    test_##name(#name, &tested, &sum.passed, &sum.failed); \
    if (pre_next == sum.failed) {                          \
      printf("%s[PASS]%s %s\n", KGRN, KNRM, #name);        \
    }                                                      \
  } while (0)

#endif /* TEST_H */
