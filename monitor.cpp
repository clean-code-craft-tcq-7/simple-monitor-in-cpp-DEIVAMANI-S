#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

//Vital Range limits
constexpr float max_temperature = 102.0f;
constexpr float min_temperature = 95.0f;
constexpr int max_pulse_rate = 100;
constexpr int min_pulse_rate = 60;
constexpr int min_spo2_level = 90;

// Blinking alert duration
constexpr int alertcount = 6;

// Function to display (or) issue alert
void DisplayAlert()
{
    for (int i = 0; i < alertcount; i++) 
    {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}

// Function to check a single vital parameter
bool CheckVitalsRange(const char* vitalsName, float readingValue, float minlimit, float maxlimit)
{
    if (readingValue < minlimit || readingValue > maxlimit) 
    {
        cout << vitalsName << " is Critical!!!\n";
        DisplayAlert();
        return false;
    }
    return true;
}


int IsVitalsOk(float temperature, float pulseRate, float spo2) 
{
    bool tempOk = CheckVitalsRange("Temperature", temperature, min_temperature, max_temperature);
    bool pulseOk = CheckVitalsRange("Pulse Rate", pulseRate, min_pulse_rate, max_pulse_rate);
    bool spo2Ok = CheckVitalsRange("Oxygen Saturation", spo2, min_spo2_level, 100); // 100 is user creted upper-bound for reference 

    return (tempOk && pulseOk && spo2Ok) ? 1 : 0;
}