#include "WProgram.h"
#include "MotionSensor.h"
#include "DigitalLed.h"

  MotionSensor::MotionSensor() {
  }
  
  MotionSensor::MotionSensor(byte inputPin, byte ledPin) {
    inputPin_ = inputPin;
    motionLed_ = DigitalLed(ledPin);
    lastMotionDetected_ = 0;
    motionDetected_ = false;
  }  
  
  void MotionSensor::printPin() {
    Serial.print("Motion pin: ");
    Serial.println(inputPin_);
}
  
  void MotionSensor::refresh() {
    motionReading_ = digitalRead(inputPin_);
    if (motionReading_ == HIGH) {
      lastMotionDetected_ = millis();
      motionLed_.on();
    } else {
      motionLed_.off();
    }
  }
  
  boolean MotionSensor:: detectionStateChanged() {
    foo
    
  }

  void MotionSensor::serialDebug() {
    Serial.print(" Motion: ");
    Serial.print(motionReading_);
    Serial.print("Last motion: ");
    Serial.print(lastMotionDetected_ + MOTION_GRACE_PERIOD_MS);
    Serial.print(" ");
    Serial.print(millis());
  }
  
  boolean MotionSensor::motionDetected() {
    return lastMotionDetected_ + MOTION_GRACE_PERIOD_MS > millis() || motionReading_;
  }
  

