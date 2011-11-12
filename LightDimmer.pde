#include "WProgram.h"
#include "MotionSensor.h"
#include "Dimmer.h"
#include "AmbientLightSensor.h"
#include "LightController.h"
#include "Utils.h"

#define ambientLightSensorPin 0
#define ambientDaylightThreshold 500


LightController lightController;

int interval = 5000;

void setup () {
    Serial.begin(9600);
  AmbientLightSensor ambientAmbientLightSensor = AmbientLightSensor(ambientLightSensorPin, ambientDaylightThreshold);
  Dimmer outputLight = Dimmer(11);
  MotionSensor motionSensor = MotionSensor(2, 13);


  lightController = LightController(motionSensor, ambientAmbientLightSensor, outputLight);

}

void loop() {
  lightController.refresh();

  //delay(1000);
  serialDebug();
}

void serialDebug() {
  if (millis() % 1000 == 0) {
    Serial.println();
    lightController.serialDebug();
  }
}




