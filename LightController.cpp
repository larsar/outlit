#include "Arduino.h"
#include "LightController.h"
#include "MotionSensor.h"
#include "AmbientLightSensor.h"
#include "Dimmer.h"

  LightController::LightController() {
  }
  
  LightController::LightController(MotionSensor &motionSens, AmbientLightSensor &ambientLightSensor, Dimmer &lightOutput) {
    motionSensor_ = motionSens;
    ambientLightSensor_ = ambientLightSensor;
    outputLight_ = lightOutput;
    daylightSetting();
  }
  
  void LightController::refresh() {
    motionSensor_.refresh();
    ambientLightSensor_.refresh();
    outputLight_.refresh();
    
    setLightAccordingToMotionDetection();
    setLightAccordingToAmbientLight();
  }
  
  void LightController::setLightAccordingToMotionDetection() {
    if (!ambientLightSensor_.isDaylight()) {
      if (motionSensor_.motionDetected()) {
        outputLight_.increaseLight();
      } else {
        outputLight_.decreaseLight();
      }
    }
  }
  
  
  void LightController::setLightAccordingToAmbientLight() {
    if (ambientLightSensor_.daylightStateChanged()) {
      if (ambientLightSensor_.isDaylight()) {
        daylightSetting();
      } else {
        nightSetting();
      }
    }
  }
  
  void LightController::daylightSetting() {
    outputLight_.disable();
  }
  
  void LightController::nightSetting() {
     outputLight_.enable();
  }
  
  
  void LightController::serialDebug() {
    motionSensor_.serialDebug();
    ambientLightSensor_.serialDebug();
    outputLight_.serialDebug();
    
    Serial.println("");
  }
  
