#ifndef MotionSensor_h
#define MotionSensor_h

#include "Arduino.h"
#include "DigitalLed.h"

#define MOTION_GRACE_PERIOD_MS 5000

class MotionSensor {
  public: 
    MotionSensor();
    MotionSensor(int inputPin, int ledPin);
    void printPin();
    void refresh();
    void serialDebug();
    boolean motionDetected();
    boolean detectionStateChanged();
  
  private: 
    int inputPin_;              
    boolean motionDetected_;     
    DigitalLed motionLed_;
    unsigned long lastMotionDetected_;
    boolean stateChangeSinceLastPoll_;
    boolean recentMotionReading_;
};

#endif
