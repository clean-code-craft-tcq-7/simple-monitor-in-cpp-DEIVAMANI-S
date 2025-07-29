#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

// Vital Range limits
constexpr float max_temperature = 102.0f;
constexpr float min_temperature = 95.0f;
constexpr int max_pulse_rate = 100;
constexpr int min_pulse_rate = 60;
constexpr int min_spo2_level = 90;
constexpr int max_spo2_level = 200;//200 is user created upper-bound for reference 

// Blinking alert duration
constexpr int alertcount = 6;

// Function to display (or) issue alert
void DisplayAlert(){
    for (int i = 0; i < alertcount; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}

// Function to check a single vital parameter
bool CheckVitalsRange(const char* vitalsName, float readingValue, float minlimit, float maxlimit) {
    if (readingValue < minlimit || readingValue > maxlimit) {
        cout << vitalsName << " is Critical!!!\n";
        DisplayAlert();
        return false;
    }
    return true;
}

bool CheckTemperature(float readtemperature) {
    return !CheckVitalsRange("Temperature", readtemperature, min_temperature, max_temperature);
}
bool CheckPulse(float readpulse) {
    return !CheckVitalsRange("Pulse Rate", readpulse, min_pulse_rate, max_pulse_rate);
}
bool CheckSpO2(float readspo2) {
    return !CheckVitalsRange("Oxygen Saturation", readspo2, min_spo2_level, max_spo2_level);
}

int IsVitalsOk(float temperature, float pulseRate, float spo2) {
    if (!CheckTemperature(temperature)) return 0;
    if (!CheckPulse(pulseRate))       return 0;
    if (!CheckSpO2(spo2))        return 0;
    return 1;
}