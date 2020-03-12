#include <stdlib.h>
#include <Arduino.h>
#include <kinematics.h>
#include <math.h>


//contructor
KIN::KIN(){

    //private memebers
    this->length = 100.0; 
    this->alpha = 0.0; 
    this->radius = 0.0; 
    this->theta_2 = 0.0; 

    //public memebers
    this->position.x_coordinate =0.0; 
    this->position.y_coordinate =0.0; 
    this->theta_val.theta_0 = 0.0; 
    this->theta_val.theta_1 = 0.0; 
}

KIN::coordinates KIN::directKin(KIN::angles theta_val){
    float theta0 = theta_val.theta_0;
    float theta1 = theta_val.theta_1;

    position.x_coordinate = length *(cos(theta0)+cos(theta1)); 
    position.y_coordinate = length *(sin(theta0+cos(theta1))); 
    
    return position; 
}

KIN::angles KIN::inverseKin(KIN::coordinates position) {
    float x = position.x_coordinate;
    float y = position.y_coordinate; 

    alpha = atan(abs(y/x));
    radius = sqrt(x*x + y*y);
    theta_2 = 2*atan(sqrt(4*length*length/(radius*radius)));
    

    return theta_val;
}

