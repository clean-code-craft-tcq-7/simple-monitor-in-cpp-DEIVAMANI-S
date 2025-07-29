#pragma once

void DisplayAlert();
bool CheckTemperature(float readtemperature);
bool CheckPulse(float readpulse);
bool CheckSpO2(float readspo2);
bool CheckVitalsRange(const char* vitalsName, float readingValue, float minlimit, float maxlimit);
int IsVitalsOk(float temperature, float pulseRate, float spo2);