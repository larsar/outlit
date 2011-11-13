#include "WProgram.h"
#include "AmbientLightSensor.h"

  AmbientLightSensor::AmbientLightSensor(int inputPin, int daylightThreshold) {
    Serial.print("AMBIENT ");
    Serial.println(inputPin);
    inputPin_ = inputPin;
    lightReading_ = 0;
    daylightThreshold_ = daylightThreshold;
    lastCandidateChange_ = 0;
    nominationGraceTimeMs_ = 5000;
    stateChangeSinceLastPoll_ = false;
    daylightState_ = true;
    candidateState_ = true;
  }
  
  AmbientLightSensor::AmbientLightSensor() {
  }
  
  void AmbientLightSensor::refresh() {
    lightReading_ = analogRead(inputPin_);
    updateCandidateState();
  }
  
  void AmbientLightSensor::serialDebug() {
    Serial.print(" Ambient: ");
    Serial.print(lightReading_);
  }
  
  void AmbientLightSensor::updateCandidateState() {
    if (daylightState_ == candidateState_) {
      if (daylightState_ != daylightAccordingToSensor()) {
        setNewCandidate();
      }
    } else {
      if (daylightState_ == daylightAccordingToSensor()) {
        resetCandidate();
    } else if (candidateState_ == daylightAccordingToSensor()) {
      electCandidateIfQuarantinedPeriodEnded();
    }
    }
  }
  
  void AmbientLightSensor::electCandidateIfQuarantinedPeriodEnded() {
      if (millis() > lastCandidateChange_ + nominationGraceTimeMs_) {
        daylightState_ = candidateState_;
        lastCandidateChange_ = millis();
        stateChangeSinceLastPoll_ = true;
      }
  }
  
  void AmbientLightSensor::resetCandidate() {
    candidateState_ = daylightState_;
    lastCandidateChange_ = millis();
  }
  
  void AmbientLightSensor::setNewCandidate() {
    lastCandidateChange_ = millis();
    candidateState_ = daylightAccordingToSensor();
  }
    
  boolean AmbientLightSensor::daylightAccordingToSensor() {
    return lightReading_ > daylightThreshold_;
  }
  
  boolean AmbientLightSensor::isDaylight() {
    return daylightState_;
  }
  
  boolean AmbientLightSensor::daylightStateChanged() {
    if (stateChangeSinceLastPoll_) {
      stateChangeSinceLastPoll_ = false;
      return true;
    } else {
      return false;
    } 
  }

