#include <stdlib.h>
#include <Arduino.h>
#include <pid_controller.h>

double delta_t = 0.0;
int K_P = 2; 

unsigned long time; 

float PID::ComputePID(float theta_desired, float theta) {
   // Serial.println("entered Compute PID");
    time = millis();
    Serial.print("time: ");
    Serial.println(time);
    delta_t = (last_time - time)/1000.0;
    Serial.print("delta_t: ");
    Serial.println(delta_t);
    //theta_current = ReadTheta(0); //0 represents first motor
    error = theta_desired - theta;
    Serial.print("error: ");
    Serial.println(error);
    
    //ProportionL Controller
    proportional = error * K_P;
    Serial.print("Proportional: ");
    Serial.print(proportional);
    Serial.print("    ");

    //Derivative
    derivative = (error - prev_error) * K_D;
    Serial.print("Derivative: ");
    Serial.print(derivative);
    Serial.print("    ");

    errorSum += error * (float)delta_t;
    integral = errorSum * K_I; 
    Serial.print("integral ");
    Serial.print(integral);
    Serial.print("    ");
    
    prev_error = error;
    last_time = time;

    output = float(proportional + derivative + integral);
    Serial.print("output: ");
    Serial.print(output);
    Serial.println("    ");
    
    return output;
    
    
    
}; //end