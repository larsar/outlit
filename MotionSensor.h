#ifndef MotionSensor_h
#define MotionSensor_h

#include "WProgram.h"
#include "DigitalLed.h"

#define MOTION_GRACE_PERIOD_MS 5000

class MotionSensor {
  public: 
    MotionSensor();
    MotionSensor(byte inputPin, byte ledPin);
    void printPin();
    void refresh();
    void serialDebug();
    boolean motionDetected();
    boolean detectionStateChanged();
  
  private: 
    byte inputPin_;              
    boolean motionReading_;     
    DigitalLed motionLed_;
    unsigned long lastMotionDetected_;
    boolean stateChangeSinceLastPoll_;
    boolean motionDetected_;
};

#endif
