#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <Arduino.h>

class PID
{

  public: 

   // #define K_P 2
   
    #define K_D 3
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
    unsigned long last_time = millis();
    //unsigned long time = 0;
    float thetaPID;
    float output;
    
    //float theta; //this should be in main
}; //end class  

#endif