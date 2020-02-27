#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <Arduino.h>

class PID
{

  public: 

    #define K_P 2
    #define K_D 1
    #define K_I 0
    
    float ComputePID(unsigned long delta_t, float error);
    float output;


  private:

    float errorSum = 0.0;
    float proportional=0.0;
    float derivative = 0.0 ;
    float integral = 0.0;
    float prev_error = 0.0;
   
    
}; //end class  

#endif