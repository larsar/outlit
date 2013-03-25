#include "Arduino.h"
#include "MotionSensor.h"
#include "DigitalLed.h"

  MotionSensor::MotionSensor() {
  }
  
  MotionSensor::MotionSensor(int inputPin, int ledPin) {
    inputPin_ = inputPin;
    pinMode(inputPin_, INPUT);
    motionLed_ = DigitalLed(ledPin);
    lastMotionDetected_ = 0;
    motionDetected_ = false;
    recentMotionReading_ = false;
  }  
  
  void MotionSensor::printPin() {
    Serial.print("Motion pin: ");
    Serial.println(inputPin_);
}
  
  void MotionSensor::refresh() {
    if (digitalRead(inputPin_) == HIGH) {
      recentMotionReading_ = true;
      lastMotionDetected_ = millis();
      motionLed_.on();
    } else {
      recentMotionReading_ = false;
      motionLed_.off();
    }
  }
  
  boolean MotionSensor:: detectionStateChanged() {

  }

  void MotionSensor::serialDebug() {
    Serial.print(" Motion: ");
    if (recentMotionReading_) {
      Serial.print("Y ");
    } else {
      Serial.print("N ");
    }
    Serial.print("Last motion: ");
    Serial.print(lastMotionDetected_ + MOTION_GRACE_PERIOD_MS);
    Serial.print(" ");
    Serial.print(millis());
  }
  
  boolean MotionSensor::motionDetected() {
    boolean changed = lastMotionDetected_ + MOTION_GRACE_PERIOD_MS > millis() || recentMotionReading_;


    return changed;
  }
  

