#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>

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
  // Single condition for range check
  bool is_ok = (value >= range.lower_limit && value <= range.upper_limit);
  
  // Language configuration to avoid branching
  struct LangConfig {
    std::string name;
    std::string message;
  };
  LangConfig config = (LANGUAGE == Language::DE) 
    ? LangConfig{range.name_de, " ist kritisch!\n"} 
    : LangConfig{range.name_en, " is critical!\n"};
  
  if (!is_ok) {
    std::cout << config.name << config.message;
    displayAlert(config.name + " out of range");
  }
  
  return is_ok;
}

bool areAllVitalsOk(float temperature, float pulseRate, float spo2,
                    float bloodSugar, float bloodPressure,
                    float respiratoryRate) {
  VitalsRange vitals[] = {
      {MIN_TEMPERATURE, MAX_TEMPERATURE, "Temperature", "Temperatur"},
      {MIN_PULSE_RATE, MAX_PULSE_RATE, "Pulse Rate", "Pulsrate"},
      {MIN_SPO2, MAX_SPO2, "Oxygen Saturation", "Sauerstoffsättigung"},  // only min matters
      {LOWER_LIMIT_BLOOD_SUGAR, UPPER_LIMIT_BLOOD_SUGAR,
       "Blood Sugar", "Blutzucker"},
      {LOWER_LIMIT_BLOOD_PRESSURE, UPPER_LIMIT_BLOOD_PRESSURE,
       "Blood Pressure", "Blutdruck"},
      {LOWER_LIMIT_RESPIRATION_RATE, UPPER_LIMIT_RESPIRATION_RATE,
       "Respiratory Rate", "Atemfrequenz"}};

  float values[] = {temperature, pulseRate, spo2,
                    bloodSugar, bloodPressure, respiratoryRate};

  for (size_t i = 0; i < std::size(values); i++) {
    if (!isVitalsOk(values[i], vitals[i])) {
      return false;
    }
  }
  return true;
}
