#ifndef Dimmer_h
#define Dimmer_h

#include "WProgram.h"

#define LIGHT_OFF 0
#define LIGHT_ON_FULL 255

class Dimmer {
  public: 
    Dimmer();
    Dimmer(int outputPin);
    void serialDebug();
    void refresh();
    void turnOffLight();
    void turnOnFullLight();
    void increaseLight();
    void decreaseLight();
    void setLightLevels(byte highestLightLevel, byte lowestLightLevel);
    void setTransitionTimes(unsigned int transitionTimeForFullLightsMs, unsigned int transitionTimeForDimmedLightMs);
    void disable();
    void enable();
       
  private:
    byte lowestLightLevel_;
    byte highestLightLevel_;
    byte outputPin_;
    byte lightLevel_;
    unsigned int lightLevelChangeIntervalMs_;
    unsigned long lastChange_;
    byte targetLightLevel_;
    unsigned int transitionTimeForFullLightMs_;
    unsigned int transitionTimeForDimmedLightMs_;
    unsigned int intervalForIncreaseMs_;
    unsigned int intervalForDecreaseMs_;
    boolean enabled_;
    
    boolean changeLightLevelNow();
    void timedLightLevelIncrement();
    void timedLightLevelDecrement();
    void calculateLightChangeIntervals();
    void ajustLightIfTargetLevelIsDifferentFromCurrent();
    void updateLightOutput();


  
};

#endif
