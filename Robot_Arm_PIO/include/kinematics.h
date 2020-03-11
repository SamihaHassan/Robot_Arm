#ifndef KINEMATIC_H
#define KINEMATIC_H

#include <Arduino.h>

class KIN
{
  

    private:
        #define length 100 ; //mm  
        float alpha;
        float radius;
        float theta2;
         

        
    public: 
        float x_coordinate; 
        float y_coordinate; 
        struct coordinates {
            float x;
            float y;
        };
        struct coordinates * position;
        KIN();
        float* directKin(float theta0, float theta1);
        float* inverseKin(struct coordinates * x, struct coordinates * y);

  
    
}; //end class  

#endif