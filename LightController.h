#ifndef LightController_h
#define LightController_h

#include "Arduino.h"
#include "MotionSensor.h"
#include "AmbientLightSensor.h"
#include "Dimmer.h"

class LightController {
  public: 
    LightController();
    LightController(MotionSensor &motionSens, AmbientLightSensor &ambientLightSensor, Dimmer &lightOutput);
    void refresh();
    void serialDebug();
  
  private:  
    MotionSensor motionSensor_;
    AmbientLightSensor ambientLightSensor_;
    Dimmer outputLight_;
    
    void setLightAccordingToAmbientLight();
    void setLightAccordingToMotionDetection();
    void daylightSetting();
    void nightSetting();

};


#endif
