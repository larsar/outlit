#include "WProgram.h"
#include "MotionSensor.h"
#include "Dimmer.h"
#include "AmbientLightSensor.h"
#include "LightController.h"
#include "Utils.h"

#define ambientLightSensorAnalogInputPin 0
#define ambientDaylightThresholdValue 300
#define outputLightDigitalOutputPin 11
#define motionSensorDigitalInputPin 2
#define motionSensorLedDigitalOutputPin 13


LightController lightController;

int interval = 5000;

void setup () {
  Serial.begin(9600);
  AmbientLightSensor ambientAmbientLightSensor = AmbientLightSensor(ambientLightSensorAnalogInputPin, ambientDaylightThresholdValue);
  Dimmer outputLight = Dimmer(outputLightDigitalOutputPin);
  MotionSensor motionSensor = MotionSensor(motionSensorDigitalInputPin, motionSensorLedDigitalOutputPin);

  lightController = LightController(motionSensor, ambientAmbientLightSensor, outputLight);
}

void loop() {
  lightController.refresh();
  serialDebug();
}

void serialDebug() {
  if (millis() % 1000 == 0) {
    Serial.println();
    lightController.serialDebug();
  }
}





