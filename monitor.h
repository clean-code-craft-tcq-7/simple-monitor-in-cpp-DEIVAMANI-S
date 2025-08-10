#pragma once

#define MAX_TEMPERATURE  102
#define MIN_TEMPERATURE  95
#define MAX_PULSE_RATE   100
#define MIN_PULSE_RATE   60
#define MIN_SPO2         90

void displayAlert(std::string message);
int isTemperatureOk(float temperature);
int isPulseRateOk(float pulseRate);
int isSpo2Ok(float spo2);
int isvitalsOk(float temperature, float pulseRate, float spo2);
