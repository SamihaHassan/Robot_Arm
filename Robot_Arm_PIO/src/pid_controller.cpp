#include <stdlib.h>
#include <Arduino.h>
#include <pid_controller.h>

unsigned long delta_t = 0;

float PID::ComputePID(float theta_desired, float theta) {

    time = millis();
    delta_t = last_time - time;
    //theta_current = ReadTheta(0); //0 represents first motor
    error = theta_desired - theta;
    proportional = error * K_P;
    derivative = (error - prev_error) * K_D;
    errorSum += error * (float)delta_t;
    integral = errorSum * K_I; 
    
    prev_error = error;
    last_time = time;
    
    return proportional + derivative + integral;
    
    
    
}; //end