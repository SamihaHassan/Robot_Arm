#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <Arduino.h>

class PID
{
  

  private:
    float proportional; 
    float derivative;
    float integral;
    float errorSum;
    float prev_error;   
    float output; 
    
  public:
    #define K_P 2
    #define K_D 0
    #define K_I 0
    
    PID();
    float ComputePID(unsigned long delta_t, float error);
    //PID() : proportional(0.0), derivative(5.0), integral(0.0), errorSum(0.0), prev_error(0.0), output(0.0) {}
    //  Box(double l = 2.0, double b = 2.0, double h = 2.0) {
    
    
  
   
    
}; //end class  

#endif