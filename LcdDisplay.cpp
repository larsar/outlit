#include "LcdDisplay.h"
#include "LCD4Bit.h"

LCD4Bit lcd_;
   LcdDisplay::LcdDisplay() {
   }
  LcdDisplay::LcdDisplay(LCD4Bit &lcd) {
    pinMode(LCD_BACKLIGHT_PIN, OUTPUT);
    turnOnBacklight();
    lcd_ = lcd;
    lcd_.init();
    lcd_.clear();
    strcpy(outputLight_, "     ");
    strcpy(ambientLight_, "     ");
    genericMessage_ = false;
  }
  
  void LcdDisplay::turnOnBacklight() {
    digitalWrite(LCD_BACKLIGHT_PIN, HIGH);
  }
  
  void LcdDisplay::turnOffBacklight() {
    digitalWrite(LCD_BACKLIGHT_PIN, LOW);
  }
  
  void LcdDisplay::refresh() {
  }
  
  void LcdDisplay::serialDebug() {
  }
  
  void LcdDisplay::ambientLightDay() {
    strcpy(ambientLight_,"Day");
    updateLine1();
  }
  
  void LcdDisplay::ambientLightNight() {
    strcpy(ambientLight_,"Night");
    updateLine1();
  }
  
  void LcdDisplay::outputHigh() {
    strcpy(outputLight_,"Bright");
    updateLine2();
  }
  
  void LcdDisplay::outputLow() {
    strcpy(outputLight_,"Dim");
    updateLine2();
  }
  
  void LcdDisplay::outputOff() {
    strcpy(outputLight_,"Off");
    updateLine2();
  }
  
  void LcdDisplay::genericMessage(char *messageLine1, char *messageLine2) {
    lcd_.clear();
    lcd_.cursorTo(1, 0);
    lcd_.printIn(messageLine1);
    lcd_.cursorTo(2, 0);
    lcd_.printIn(messageLine2);
    
    genericMessage_ = true;
  }
  
  void LcdDisplay::updateLine1() {
    if (genericMessage_) {
      lcd_.clear();
      genericMessage_ = false;
    }
    char line1[17];    
    sprintf(line1, "Mode: %10s", ambientLight_);
    lcd_.cursorTo(1, 0);
    lcd_.printIn(line1);

  }
  
  void LcdDisplay::updateLine2() {      
    if (genericMessage_) {
      lcd_.clear();
      genericMessage_ = false;
    }
    char line2[17]; 
    sprintf(line2, "Lights: %8s", outputLight_);
    lcd_.cursorTo(2, 0); 
    lcd_.printIn(line2); 
  }


