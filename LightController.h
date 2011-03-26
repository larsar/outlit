#ifndef LightController_h
#define LightController_h

#include "WProgram.h"
#include "MotionSensor.h"
#include "AmbientLightSensor.h"
#include "LcdDisplay.h"
#include "Dimmer.h"

class LightController {
  public: 
    LightController();
    LightController(MotionSensor &motionSens, AmbientLightSensor &ambientLightSensor, Dimmer &lightOutput, LcdDisplay &lcdDisp);
    void refresh();
    void serialDebug();
  
  private:  
    MotionSensor motionSensor_;
    AmbientLightSensor ambientLightSensor_;
    Dimmer outputLight_;
    LcdDisplay lcdDisplay_;
    
    void setLightAccordingToAmbientLight();
    void setLightAccordingToMotionDetection();
    void daylightSetting();
    void nightSetting();

};


#endif
