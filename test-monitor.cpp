#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(IsVitalsOk(99, 102, 70));
  ASSERT_TRUE(IsVitalsOk(98.1, 70, 98));
}