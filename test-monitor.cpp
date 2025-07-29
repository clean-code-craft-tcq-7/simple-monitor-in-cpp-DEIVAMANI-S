#include "gtest/gtest.h"
#include "./monitor.h"

void DisplayAlert()
{
    // Do nothing for tests - Override
}

// ----------- Tests for CheckVitalsRange ------------


TEST(CheckVitalsRangeTest, ReturnsTrueForValidReading) {
    EXPECT_TRUE(CheckVitalsRange("Temperature", 98.6, 95.0, 102.0));
}

TEST(CheckVitalsRangeTest, ReturnsFalseForLowReading) {
    EXPECT_FALSE(CheckVitalsRange("Temperature", 90.0, 95.0, 102.0));
}

TEST(CheckVitalsRangeTest, ReturnsFalseForHighReading) {
    EXPECT_FALSE(CheckVitalsRange("Temperature", 105.0, 95.0, 102.0));
}

// ----------- Tests for IsVitalsOk ------------

TEST(IsVitalsOkTest, AllVitalsNormal) {
    EXPECT_EQ(IsVitalsOk(98.6, 72, 95), 1);
}

TEST(IsVitalsOkTest, TemperatureTooHigh) {
    EXPECT_EQ(IsVitalsOk(103.0, 72, 95), 0);
}

TEST(IsVitalsOkTest, PulseTooLow) {
    EXPECT_EQ(IsVitalsOk(98.6, 50, 95), 0);
}

TEST(IsVitalsOkTest, Spo2TooLow) {
    EXPECT_EQ(IsVitalsOk(98.6, 72, 85), 0);
}

TEST(IsVitalsOkTest, MultipleVitalsOutOfRange) {
    EXPECT_EQ(IsVitalsOk(104.0, 50, 85), 0);
}