#include "WProgram.h"
#include "MotionSensor.h"
#include "Dimmer.h"
#include "AmbientLightSensor.h"
#include "LcdDisplay.h"
#include "LightController.h"
#include "Utils.h"
//#include <LCD4Bit.h>

#define ambientLightSensorPin 2
#define ambientDaylightThreshold 100


LightController lightController;

int interval = 5000;

LCD4Bit lcd = LCD4Bit(2);


void setup () {
  AmbientLightSensor ambientAmbientLightSensor = AmbientLightSensor(ambientLightSensorPin, 50);
  Dimmer outputLight = Dimmer(11);
  MotionSensor motionSensor = MotionSensor(3, 13);
  LcdDisplay lcdDisplay = LcdDisplay(lcd);

  Serial.begin(9600);
  lcdDisplay.genericMessage("Initializing...", "");
  delay(2000);

  lightController = LightController(motionSensor, ambientAmbientLightSensor, outputLight, lcdDisplay);

}

void loop() {
  lightController.refresh();

  //delay(1000);
  serialDebug();
}

void serialDebug() {
  if (millis() % 1000 == 0) {
    //Serial.println();
    lightController.serialDebug();
  }
}




