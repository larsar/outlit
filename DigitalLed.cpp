#include "WProgram.h"
#include "DigitalLed.h"

  DigitalLed::DigitalLed() {
  }
  
  DigitalLed::DigitalLed(int outputPin) {
    outputPin_ = outputPin;
    pinMode(outputPin_, OUTPUT);
  }
  
  void DigitalLed::on() {
    digitalWrite(outputPin_, HIGH);
  }
  
  void DigitalLed::off() {
    digitalWrite(outputPin_, LOW);
  }
  
