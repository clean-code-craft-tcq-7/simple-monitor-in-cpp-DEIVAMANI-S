#include <gtest/gtest.h>
#include "./monitor.h"

// Normal values
constexpr float NORMAL_TEMP   = 98.0f;
constexpr float NORMAL_PULSE  = 72;
constexpr float NORMAL_SPO2   = 95;
constexpr float NORMAL_SUGAR  = 90;
constexpr float NORMAL_BP     = 120;
constexpr float NORMAL_RESP   = 16;

TEST(VitalsTest, AllVitalsNormal) {
    EXPECT_TRUE(areAllVitalsOk(NORMAL_TEMP, NORMAL_PULSE, NORMAL_SPO2,
                               NORMAL_SUGAR, NORMAL_BP, NORMAL_RESP));
}

TEST(VitalsTest, BloodSugarTooLow) {
    EXPECT_FALSE(areAllVitalsOk(NORMAL_TEMP, NORMAL_PULSE, NORMAL_SPO2,
                                50.0f, NORMAL_BP, NORMAL_RESP));
}

TEST(VitalsTest, BloodPressureTooHigh) {
    EXPECT_FALSE(areAllVitalsOk(NORMAL_TEMP, NORMAL_PULSE, NORMAL_SPO2,
                                NORMAL_SUGAR, 180.0f, NORMAL_RESP));
}

TEST(VitalsTest, RespiratoryTooLow) {
    EXPECT_FALSE(areAllVitalsOk(NORMAL_TEMP, NORMAL_PULSE, NORMAL_SPO2,
                                NORMAL_SUGAR, NORMAL_BP, 8.0f));
}

TEST(VitalsTest, LanguageSwitchGerman) {
    LANGUAGE = Language::DE;
    EXPECT_FALSE(areAllVitalsOk(105.0f, NORMAL_PULSE, NORMAL_SPO2,
                                NORMAL_SUGAR, NORMAL_BP, NORMAL_RESP));
    LANGUAGE = Language::EN;  // reset
}

// ---------------- Additional branch coverage ----------------

TEST(VitalsBranchTest, IsVitalsOkWithinRange) {
  VitalsRange tempRange{95, 102, "Temperature", "Temperatur"};
  EXPECT_TRUE(isVitalsOk(98, tempRange));  // inside range
}

TEST(VitalsBranchTest, IsVitalsOkOutOfRangeEnglish) {
  LANGUAGE = Language::EN;
  VitalsRange pulseRange{60, 100, "Pulse Rate", "Pulsrate"};
  EXPECT_FALSE(isVitalsOk(120, pulseRange));  // outside range
}

TEST(VitalsBranchTest, IsVitalsOkOutOfRangeGerman) {
  LANGUAGE = Language::DE;
  VitalsRange pulseRange{60, 100, "Pulse Rate", "Pulsrate"};
  EXPECT_FALSE(isVitalsOk(40, pulseRange));  // outside range
  LANGUAGE = Language::EN;  // reset
}

TEST(VitalsBranchTest, AreAllVitalsOkOneBad) {
  EXPECT_FALSE(areAllVitalsOk(110.0f, NORMAL_PULSE, NORMAL_SPO2,
                              NORMAL_SUGAR, NORMAL_BP, NORMAL_RESP));  // temp too high
}
