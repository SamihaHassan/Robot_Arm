//Header file:

#include <Arduino.h>

struct PIDVariables{
    float error;
    float errorSum = 0;
    float proportional;
    float derivative;
    float integral;
    float prev_error = 0;
    unsigned long last_time = millis();
    unsigned long time = 0;
    float theta;
};

#define K_P 0
#define K_D 0
#define K_I 0
