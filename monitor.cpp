#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;


void displayAlert(std::string message) {
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}

int isTemperatureOk(float temperature) {
  if (temperature > MAX_TEMPERATURE || temperature < MIN_TEMPERATURE) {
    cout << "Temperature is critical!\n";
    displayAlert("Temperature is out of Range");
    return 0;
  }
  return 1;
}

int isPulseRateOk(float pulseRate) {
  if (pulseRate < MIN_PULSE_RATE || pulseRate > MAX_PULSE_RATE) {
    cout << "Pulse Rate is critical!\n";
    displayAlert("Pulse Rate is out of Range");
    return 0;
  }
  return 1;
}

int isSpo2Ok(float spo2) {
  if (spo2 < MIN_PULSE_RATE) {
    cout << "Oxygen level is critical!\n";
    displayAlert("Oxygen Saturation is out of Range");
    return 0;
  }
  return 1;
}

int isvitalsOk(float temperature, float pulseRate, float spo2) {
  return isTemperatureOk(temperature) && isPulseRateOk(pulseRate) && isSpo2Ok(spo2);
}
