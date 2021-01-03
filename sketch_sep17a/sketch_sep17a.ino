#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS 1000

PulseOximeter pox;
uint32_t tsLastReport = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing...");
   
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
  Serial.println(pox.getHeartRate());
  Serial.println(pox.getSpO2());  
  tsLastReport = millis();
  
  }
}
