#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(isvitalsOk(99, 102, 70));
  ASSERT_TRUE(isvitalsOk(98.1, 70, 98));
}