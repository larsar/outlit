#include "WProgram.h"
#include "LightController.h"
#include "MotionSensor.h"
#include "AmbientLightSensor.h"
#include "LcdDisplay.h"
#include "Dimmer.h"

  LightController::LightController() {
  }
  
  LightController::LightController(MotionSensor &motionSens, AmbientLightSensor &ambientLightSensor, Dimmer &lightOutput, LcdDisplay &lcdDisp) {
    motionSensor_ = motionSens;
    ambientLightSensor_ = ambientLightSensor;
    outputLight_ = lightOutput;
    lcdDisplay_ = lcdDisp;
    daylightSetting();
  }
  
  void LightController::refresh() {
    motionSensor_.refresh();
    ambientLightSensor_.refresh();
    outputLight_.refresh();
    lcdDisplay_.refresh();
    
    setLightAccordingToMotionDetection();
    setLightAccordingToAmbientLight();
  }
  
  void LightController::setLightAccordingToMotionDetection() {
    if (!ambientLightSensor_.isDaylight()) {
      if (motionSensor_.motionDetected()) {
        outputLight_.increaseLight();
        lcdDisplay_.outputHigh();
      } else {
        outputLight_.decreaseLight();
        lcdDisplay_.outputLow();
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
    lcdDisplay_.outputOff();
    lcdDisplay_.ambientLightDay();
  }
  
  void LightController::nightSetting() {
     outputLight_.enable();
     lcdDisplay_.outputLow();
     lcdDisplay_.ambientLightNight();
  }
  
  
  void LightController::serialDebug() {
    motionSensor_.serialDebug();
    ambientLightSensor_.serialDebug();
    outputLight_.serialDebug();
    
    Serial.println("");
  }
  
