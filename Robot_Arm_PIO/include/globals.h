#ifndef GLOBAL_H
#define GLOBAL_H

#define CONST_NUM 3

//Pin assignments MOTOR_A
#define MOTOR_PIN_A 4
#define RUPT_PIN_A1 2
#define RUPT_PIN_A2 3
#define DIREC_A1 7
#define DIREC_A2 6

//Pin assignments MOTOR_B
#define MOTOR_PIN_B 12
#define RUPT_PIN_B1 8
#define RUPT_PIN_B2 9
#define DIREC_B1 11
#define DIREC_B2 10

#define DEG(A) ( ((A) < 0) ? 360 + (A) : (A) )


#endif