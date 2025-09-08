#pragma once
#include <string>

// Global language setting (enum instead of global string)
enum class Language {
  EN,
  DE
};
extern Language LANGUAGE;

// Temperature
constexpr float MAX_TEMPERATURE = 102.0f;
constexpr float MIN_TEMPERATURE = 95.0f;

// Pulse rate
constexpr float MAX_PULSE_RATE = 100.0f;
constexpr float MIN_PULSE_RATE = 60.0f;

// Blood Oxygen limits
constexpr float MIN_SPO2 = 90.0f;
constexpr float MAX_SPO2 = 200.0f;

// Blood Sugar limits
constexpr float LOWER_LIMIT_BLOOD_SUGAR = 70.0f;
constexpr float UPPER_LIMIT_BLOOD_SUGAR = 110.0f;

// Blood Pressure limits
constexpr float LOWER_LIMIT_BLOOD_PRESSURE = 90.0f;
constexpr float UPPER_LIMIT_BLOOD_PRESSURE = 150.0f;

// Respiratory rate limits
constexpr float LOWER_LIMIT_RESPIRATION_RATE = 12.0f;
constexpr float UPPER_LIMIT_RESPIRATION_RATE = 20.0f;

struct VitalsRange {
  float lower_limit;
  float upper_limit;
  std::string name_en;
  std::string name_de;  // German language
};

void displayAlert(const std::string& message);
bool isVitalsOk(float value, const VitalsRange& range);
bool areAllVitalsOk(float temperature, float pulseRate, float spo2,
                    float bloodSugar, float bloodPressure,
                    float respiratoryRate);
