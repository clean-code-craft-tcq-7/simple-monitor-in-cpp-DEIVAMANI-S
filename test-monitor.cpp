#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(isvitalsOk(99, 102, 70));
  ASSERT_TRUE(isvitalsOk(98.1, 70, 98));
}

// ----------- Tests for IsVitalsOk ------------

TEST(IsVitalsOkTest, AllVitalsNormal) {
    EXPECT_EQ(isvitalsOk(98.6, 72, 95), 1);
}

TEST(IsVitalsOkTest, TemperatureTooHigh) {
    EXPECT_EQ(isvitalsOk(103.0, 72, 95), 0);
}

TEST(IsVitalsOkTest, PulseTooLow) {
    EXPECT_EQ(isvitalsOk(98.6, 50, 95), 0);
}

TEST(IsVitalsOkTest, Spo2TooLow) {
    EXPECT_EQ(isvitalsOk(98.6, 72, 85), 0);
}

TEST(IsVitalsOkTest, MultipleVitalsOutOfRange) {
    EXPECT_EQ(isvitalsOk(104.0, 50, 85), 0);
}