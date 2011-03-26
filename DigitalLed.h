#ifndef DigitalLed_h
#define DigitalLed_h

#include "WProgram.h"

class DigitalLed {
  
  public: 
    DigitalLed();
    DigitalLed(int outputPin);
    void on();
    void off();
  
  private:
    byte outputPin_;
};

#endif
