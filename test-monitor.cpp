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
                                50, NORMAL_BP, NORMAL_RESP));
}

TEST(VitalsTest, BloodPressureTooHigh) {
    EXPECT_FALSE(areAllVitalsOk(NORMAL_TEMP, NORMAL_PULSE, NORMAL_SPO2,
                                NORMAL_SUGAR, 180, NORMAL_RESP));
}

TEST(VitalsTest, RespiratoryTooLow) {
    EXPECT_FALSE(areAllVitalsOk(NORMAL_TEMP, NORMAL_PULSE, NORMAL_SPO2,
                                NORMAL_SUGAR, NORMAL_BP, 8));
}

TEST(VitalsTest, LanguageSwitchGerman) {
    LANGUAGE = "DE";
    EXPECT_FALSE(areAllVitalsOk(105, NORMAL_PULSE, NORMAL_SPO2,
                                NORMAL_SUGAR, NORMAL_BP, NORMAL_RESP));
    LANGUAGE = "EN"; // reset
}
