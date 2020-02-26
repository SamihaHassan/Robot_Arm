#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <Arduino.h>

class PID
{

  public: 

    #define K_P 0
    #define K_D 0
    #define K_I 0

    float ComputePID(float theta_desired, float theta);
    //float ApplyPID(float thetaPID, int dir, float theta);

  private:

    float error;
    float errorSum = 0;
    float proportional=0;
    float derivative;
    float integral;
    float prev_error = 0;
    float last_time = millis();
    float time = 0;
    float thetaPID;
    
    //float theta; //this should be in main
}; //end class  

#endif