#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS 1000

PulseOximeter pox;
uint32_t tsLastReport = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Ini..");
   
  if (!pox.begin()) {
    Serial.println("FAILED");
    for(;;);
  } else {
    Serial.println("SUCCESS");
  }
}

void loop() {
  pox.update();
   
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
  Serial.print("BPM:");
  Serial.print(pox.getHeartRate());
  Serial.print(",");
  Serial.print("SpO2:");
  Serial.print(pox.getSpO2());
  Serial.println("\n");
  
  tsLastReport = millis();
  }
}
