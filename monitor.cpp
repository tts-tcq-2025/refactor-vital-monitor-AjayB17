#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;
constexpr float TEMP_LOW = 95.0f;
constexpr float TEMP_HIGH = 102.0f;
constexpr float PULSE_LOW = 60.0f;
constexpr float PULSE_HIGH = 100.0f;
constexpr float SPO2_MIN = 90.0f;
constexpr int OK = 1;
constexpr int NOT_OK = 0;

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (temperature > TEMP_HIGH || temperature < TEMP_LOW) {
    cout << "Temperature is critical!\n";
    blinkAlert();
    return NOT_OK;
  } else if (pulseRate < PULSE_LOW || pulseRate > PULSE_HIGH) {
    cout << "Pulse Rate is out of range!\n";
    blinkAlert();
    return NOT_OK;
  } else if (spo2 < SPO2_MIN) {
    cout << "Oxygen Saturation out of range!\n";
    blinkAlert();
    return NOT_OK;
  }
  return OK;
}
void blinkAlert() {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
  cout << "\r  \r" << flush; // Clear line after alert
}
