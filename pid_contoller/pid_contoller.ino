#include <stdlib.h>
#include <Arduino.h>

//Header file:
struct PIDVariables{
    int error;
    float proportional;
    float derivative;
    float integral;
    float prev_error = 0;
    long long int last_time = millis();
};

K_P = 0;
K_D = 0;
K_I = 0;


//c file

   void PID() {

    PIDVariables motorPID; 
    
    int theta_current = ReadAngle(0); //0 represents first motor
    motorPID.error = theta_desired - theta_current;
    motorPID.proportional = motorPID.error * K_P;
    motorPID.derivative = (motorPID.error - motorPID.prev_error) * K_D;
    motorPID.integral += motorPID.error * delta_t * K_I;
    
    motorPID.prev_error = motorPID.error;

    motorPID.last_time = millis();

    // If we are turning more than 180 degree, than we can turn another direction
    if((turn_angle) > 180){
        turn_angle -= 360;
    }else if (turn_angle < -180) {
        turn_angle += 360;
    }
    return turn_angle;
    }

} //end
