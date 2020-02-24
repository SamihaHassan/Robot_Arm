#include <stdlib.h>
#include <Arduino.h>
#include <pid_controller.h>

unsigned long delta_t = 0;

float PID(PIDVariables* motorPID, float theta_desired) {

    motorPID->time = millis();
    delta_t = motorPID->last_time - motorPID->time;
    //theta_current = ReadTheta(0); //0 represents first motor
    motorPID->error = theta_desired - motorPID->theta;
    motorPID->proportional = motorPID->error * K_P;
    motorPID->derivative = (motorPID->error - motorPID->prev_error) * K_D;
    motorPID->errorSum += motorPID->error;
    motorPID->integral += motorPID->errorSum * delta_t * K_I;
    
    motorPID->prev_error = motorPID->error;
    motorPID->last_time = motorPID->time;
    
    return motorPID->proportional + motorPID->derivative + motorPID->integral;

} //end