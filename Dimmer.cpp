#include "WProgram.h"
#include "Dimmer.h"
#include "Utils.h"

Dimmer::Dimmer() {
}

Dimmer::Dimmer(int outputPin) {
  outputPin_ = outputPin;
  turnOffLight();
  lastChange_ = 0;
  setLightLevels(LIGHT_LEVEL_LOW_DEFAULT, LIGHT_LEVEL_HIGH_DEFAULT);    
  setTransitionTimes(LIGHT_UP_TRANSITION_TIME_MS_DEFAULT, LIGHT_DOWN_TRANSITION_TIME_MS_DEFAULT);
  calculateLightChangeIntervals();
  enable();
}

void Dimmer::setTransitionTimes(unsigned int transitionTimeForFullLightsMs, unsigned int transitionTimeForDimmedLightMs) {
  transitionTimeForFullLightMs_ = transitionTimeForFullLightsMs;
  transitionTimeForDimmedLightMs_ = transitionTimeForDimmedLightMs;
  calculateLightChangeIntervals();
}

void Dimmer::setLightLevels(byte lowestLightLevel, byte highestLightLevel) {
  highestLightLevel_ = highestLightLevel;
  lowestLightLevel_ = lowestLightLevel;
  calculateLightChangeIntervals();
}

void Dimmer::calculateLightChangeIntervals() {
  intervalForIncreaseMs_ = transitionTimeForFullLightMs_ / (highestLightLevel_ - lowestLightLevel_);
  intervalForDecreaseMs_ = transitionTimeForDimmedLightMs_ / (highestLightLevel_ - lowestLightLevel_);

}

void Dimmer::serialDebug() {
  Serial.print(" Target: ");
  Serial.print(targetLightLevel_, DEC);
  Serial.print(" Dimmer level: ");
  Serial.print(lightLevel_, DEC);
  Serial.print(" Lowest level: ");
  Serial.print(lowestLightLevel_, DEC);
  Serial.print(" Highest level: ");
  Serial.print(highestLightLevel_, DEC);
  Serial.print(" Enabled: ");
  Serial.print(enabled_ ? "TRUE" : "FALSE");
}

void Dimmer::updateLightOutput() {
  analogWrite(outputPin_, lightLevel_);
}

void Dimmer::timedLightLevelIncrement() {
  calculateLightChangeIntervals();
  if (intervalExceeded(&lastChange_, intervalForIncreaseMs_)) {
    lightLevel_++;
    updateLightOutput();
  }
}

void Dimmer::timedLightLevelDecrement() {
  calculateLightChangeIntervals();
  if (intervalExceeded(&lastChange_, intervalForDecreaseMs_)) {
    lightLevel_--;
    updateLightOutput();
  }
}

void Dimmer::refresh() {
  if (enabled_) {
    ajustLightIfTargetLevelIsDifferentFromCurrent();
  }
}

void Dimmer::ajustLightIfTargetLevelIsDifferentFromCurrent() {
  if (targetLightLevel_ > lightLevel_) {
    timedLightLevelIncrement();
  } 
  else if (targetLightLevel_ < lightLevel_) {
    timedLightLevelDecrement();
  }
}

void Dimmer::turnOffLight() {
  lightLevel_ = LIGHT_OFF;
  targetLightLevel_ = LIGHT_OFF;
  updateLightOutput();
}

void Dimmer::turnOnFullLight() {
  lightLevel_ = highestLightLevel_;
  targetLightLevel_ = highestLightLevel_;
  updateLightOutput();
}

void Dimmer::increaseLight() {
  if (enabled_) {
    targetLightLevel_ = highestLightLevel_;
  }
}

void Dimmer::decreaseLight() {
  if (enabled_) {
    targetLightLevel_ = lowestLightLevel_;
  }
}

void Dimmer::disable() {
  enabled_ = false;
  turnOffLight();
}

void Dimmer::enable() {
  enabled_ = true;
}


