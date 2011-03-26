#ifndef LcdDisplay_h
#define LcdDisplay_h

#include "WProgram.h"
#include "LCD4Bit.h"


#define LCD_BACKLIGHT_PIN 6

class LcdDisplay {
  
  public: 
    LcdDisplay();
    LcdDisplay(LCD4Bit &lcd);
    void refresh();
    void serialDebug();
    void turnOnBacklight();
    void turnOffBacklight();
    void ambientLightDay();
    void ambientLightNight();
    void outputHigh();
    void outputLow();
    void outputOff();
    void genericMessage(char *messageLine1, char *messageLine2);
    
    private: 
      boolean genericMessage_;
      char outputLight_[6];
      char ambientLight_[6];
      
      void updateLine1();
      void updateLine2();

};

#endif
