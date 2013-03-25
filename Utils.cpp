#include "Arduino.h"

boolean intervalExceeded(unsigned long *last, int intervalMs) {
  unsigned long now = millis();
  
  if (millis() > *last + intervalMs) {
    *last = now;
    return true;
  } else {
    return false; 
  }
}

