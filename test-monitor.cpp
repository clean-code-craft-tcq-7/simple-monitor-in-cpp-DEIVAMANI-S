#include <gtest/gtest.h>
#include "./monitor.h"

// Define constants for normal and abnormal values
constexpr float NORMAL_TEMP = 98.1f;
constexpr float HIGH_TEMP   = 104.0f;
constexpr float LOW_TEMP    = 95.0f;

constexpr int NORMAL_PULSE  = 72;
constexpr int HIGH_PULSE    = 102;
constexpr int LOW_PULSE     = 50;

constexpr int NORMAL_SPO2   = 95;
constexpr int LOW_SPO2      = 70;

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(isvitalsOk(HIGH_TEMP, HIGH_PULSE, LOW_SPO2));
  ASSERT_TRUE(isvitalsOk(NORMAL_TEMP, NORMAL_PULSE, NORMAL_SPO2));
}

// ----------- Tests for IsVitalsOk ------------
TEST(IsVitalsOkTest, AllVitalsNormal) {
    EXPECT_EQ(isvitalsOk(NORMAL_TEMP, NORMAL_PULSE, NORMAL_SPO2), 1);
}

TEST(IsVitalsOkTest, TemperatureTooHigh) {
    EXPECT_EQ(isvitalsOk(HIGH_TEMP, NORMAL_PULSE, NORMAL_SPO2), 0);
}

TEST(IsVitalsOkTest, PulseTooLow) {
    EXPECT_EQ(isvitalsOk(NORMAL_TEMP, HIGH_PULSE, NORMAL_SPO2), 0);
}

TEST(IsVitalsOkTest, Spo2TooLow) {
    EXPECT_EQ(isvitalsOk(NORMAL_TEMP, NORMAL_PULSE, LOW_SPO2), 0);
}
