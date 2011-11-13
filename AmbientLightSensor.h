#ifndef AmbientLightSensor_h
#define AmbientLightSensor_h

#include "WProgram.h"

#define nominationGraceTimeMsDefault_  5000

class AmbientLightSensor {
  public: 
    AmbientLightSensor();
    AmbientLightSensor(int inputPin, int daylightThreshold);
    void refresh();
    void serialDebug();
    boolean isDaylight();
    boolean daylightStateChanged();

  private:
    byte inputPin_;
    int lightReading_;   
    int daylightThreshold_;
    boolean daylightState_;
    boolean candidateState_;
    unsigned long lastCandidateChange_;
    unsigned int nominationGraceTimeMs_;
    boolean stateChangeSinceLastPoll_;
    boolean isDaylightAccordingToSensor();
    void updateCandidateState();
    void electCandidateIfQuarantinedPeriodEnded();
    void resetCandidate();
    void setNewCandidate();
    
  };

#endif
