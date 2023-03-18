#include "test.h"

BEGIN_TEST(single)
{
  REQUIRE(1 == 1);
}

BEGIN_TEST(multiple)
{
  REQUIRE(2 == 2);
  REQUIRE(3 != 4);
}

int main(void)
{
#ifdef __cplusplus
  summary_t sum = {};
#else
  summary_t sum = { 0 };
#endif
  RUN_TEST(sum, single);
  RUN_TEST(sum, multiple);
  print_summary(&sum);
  return sum.failed != 0;
}
