#pragma once
#include <string>

// Global language setting
extern std::string LANGUAGE;

// Temperature
#define MAX_TEMPERATURE  102
#define MIN_TEMPERATURE  95

// Pulse rate
#define MAX_PULSE_RATE   100
#define MIN_PULSE_RATE   60

// Blood Oxygen limits
#define MIN_SPO2         90
#define MAX_SPO2         200

// Blood Sugar limits
#define LOWER_LIMIT_BLOOD_SUGAR     70
#define UPPER_LIMIT_BLOOD_SUGAR     110

// Blood Pressure limits
#define LOWER_LIMIT_BLOOD_PRESSURE      90
#define UPPER_LIMIT_BLOOD_PRESSURE      150

// Respiratory rate limits
#define LOWER_LIMIT_RESPIRATION_RATE    12
#define UPPER_LIMIT_RESPIRATION_RATE    20

struct VitalsRange {
    float lower_limit;
    float upper_limit;
    std::string name_en;
    std::string name_de;  // German language
};

void displayAlert();
bool isVitalsOk(float value, const VitalsRange& range);
bool areAllVitalsOk(float temperature, float pulseRate, float spo2,
                    float bloodSugar, float bloodPressure, float respiratoryRate);
