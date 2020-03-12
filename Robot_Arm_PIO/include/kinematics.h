#ifndef KINEMATIC_H
#define KINEMATIC_H

#include <Arduino.h>

class KIN
{
  
    private:
        float length; //mm  
        float alpha;
        float radius;
        float theta_2;
         
    public: 
        struct coordinates {
            float x_coordinate;
            float y_coordinate;
        };
        
         struct angles {
            float theta_0;
            float theta_1;
        };

        KIN();
        coordinates directKin(angles);
        angles inverseKin(coordinates);

    private: 
        struct coordinates position;
        struct angles theta_val;
  
    
}; //end class  

#endif