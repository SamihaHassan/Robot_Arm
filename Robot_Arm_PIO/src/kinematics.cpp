#include <stdlib.h>
#include <Arduino.h>
#include <kinematics.h>
#include <math.h>

//contrustor
KIN::KIN(){
    this->coordinates = {0.0, 0.0}; 
    this->theta_inst = {0.0, 0.0}; 
}

void KIN::directKin(){
    static int coordinates[2]; 

    x_coordinate = length *(cos(theta0)+cos(theta1)); 
    y_coordinate = length *(sin(theta0+cos(theta1))); 
    
    coordinates[0] = x_coordinate; 
    coordinates[1] = y_coordinate; 
}

struct KIN::directKin(theta ){
    static float coordinates[2]; 

    x_coordinate = length *(cos(theta0)+cos(theta1)); 
    y_coordinate = length *(sin(theta0+cos(theta1))); 
    
    coordinates[0] = x_coordinate; 
    coordinates[1] = y_coordinate; 
    
    return  coordinates; 
}

float* KIN::inverseKin(float coordinates[]) {
    x_coordinate = coordinates[0];
    y_coordinate = coordinates[1]; 

    alpha = atan(abs(y_coordinate/x_coordinate));
    radius = sqrt(x_coordinate*x_coordinate + y_coordinate*y_coordinate);
    theta2 = 2*atan(sqrt(4*length*length/(radius*radius)));

    return 
}

