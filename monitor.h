#pragma once

void DisplayAlert();
bool CheckVitalsRange(const char* vitalsName, float readingValue, float minlimit, float maxlimit);
int IsVitalsOk(float temperature, float pulseRate, float spo2);