#include <stdlib.h>
#include <Arduino.h>
#include <pid_controller.h>

float PID::ComputePID(unsigned long delta_t, float error) {
    // Serial.println("entered Compute PID");

    // theta_current = ReadTheta(0); //0 represents first motor


    //ProportionL Controller
    proportional = error * K_P;
    Serial.print("Proportional: ");
    Serial.println(proportional);
    
    // Derivative
    // derivative = (error - prev_error)/delta_t * K_D;
    // Serial.print("Derivative: ");
    // Serial.println(derivative);
    
    // errorSum += error * (float)delta_t;
    // integral = errorSum * K_I; 
    Serial.print("integral ");
    Serial.println(integral);
       
    prev_error = error;

    output = proportional + derivative + integral;
    Serial.print("output: ");
    Serial.println(output);
        
    return output;
    
}; //end