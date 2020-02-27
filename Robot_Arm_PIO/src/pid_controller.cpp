#include <stdlib.h>
#include <Arduino.h>
#include <pid_controller.h>

PID::PID() {
    this->proportional = 0.0; 
    this->derivative = 2.0;
    this->integral = 3.0;
    this->errorSum = 0.0;
    this->prev_error = 0.0;
}

float PID::ComputePID(unsigned long delta_t, float error) {
    // Serial.println("entered Compute PID");

    // theta_current = ReadTheta(0); //0 represents first motor

    //proportional = error * K_P; 
    //derivative = (error - prev_error)/delta_t * K_D;
    
    
    // errorSum += error * (float)delta_t;
    // integral = errorSum * K_I; 
    Serial.print("proportional: ");
    Serial.println(this->proportional);
    Serial.print("derivative: ");
    Serial.println(this->derivative);
    Serial.print("integral: ");
    Serial.println(this->integral);
       
    // prev_error = error;

    output = this->proportional + this->derivative + this->integral;
    Serial.print("output: ");
    Serial.println(output);
        
    return output;
    
}; //end