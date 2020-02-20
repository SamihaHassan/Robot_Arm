/*
Adafruit Arduino - Lesson 13. DC Motor
*/
 
 
int motorPin = 3;

void secondsDelay(int n) 
{
    int i = 0;
    for (i=0; i < n; i++) {
      delay(1000);
    }  
}


void setup() 
{ 
  pinMode(motorPin, OUTPUT);

} 
 
 
void loop() 
{ 
    
    //secondsDelay(3);
    int speed = 150;
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }

//    secondsDelay(3);
//    speed = 250;
//    if (speed >= 0 && speed <= 255)
//    {
//      analogWrite(motorPin, speed);
//    }
    
  
} 
