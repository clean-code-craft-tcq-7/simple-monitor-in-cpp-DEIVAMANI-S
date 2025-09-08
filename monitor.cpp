#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

// Default language: English
Language LANGUAGE = Language::EN;

void displayAlert(const std::string& message) {
  cout << message << "\n";
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
  cout << "\n";
}

bool isVitalsOk(float value, const VitalsRange& range) {
  const std::string names[] = {range.name_en, range.name_de};
  const std::string messages[] = {" is critical!\n", " ist kritisch!\n"};
  int lang_index = static_cast<int>(LANGUAGE);
  std::string name = names[lang_index];
  std::string message = messages[lang_index];

  if (value < range.lower_limit) {
    std::cout << name << message;
    displayAlert(name + " out of range");
    return false;
  }
  if (value > range.upper_limit) {
    std::cout << name << message;
    displayAlert(name + " out of range");
    return false;
  }
  return true;
}

bool areAllVitalsOk(float temperature, float pulseRate, float spo2,
                    float bloodSugar, float bloodPressure,
                    float respiratoryRate) {
  const VitalsRange vitals[] = {
      {MIN_TEMPERATURE, MAX_TEMPERATURE, "Temperature", "Temperatur"},
      {MIN_PULSE_RATE, MAX_PULSE_RATE, "Pulse Rate", "Pulsrate"},
      {MIN_SPO2, MAX_SPO2, "Oxygen Saturation", "Sauerstoffsättigung"},
      {LOWER_LIMIT_BLOOD_SUGAR, UPPER_LIMIT_BLOOD_SUGAR,
       "Blood Sugar", "Blutzucker"},
      {LOWER_LIMIT_BLOOD_PRESSURE, UPPER_LIMIT_BLOOD_PRESSURE,
       "Blood Pressure", "Blutdruck"},
      {LOWER_LIMIT_RESPIRATION_RATE, UPPER_LIMIT_RESPIRATION_RATE,
       "Respiratory Rate", "Atemfrequenz"}};
  const float values[] = {temperature, pulseRate, spo2,
                    bloodSugar, bloodPressure, respiratoryRate};
  for (size_t i = 0; i < std::size(values); i++) {
    if (!isVitalsOk(values[i], vitals[i])) {
      return false;
    }
  }
  return true;
}
