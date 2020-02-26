/*
Adafruit Arduino - Lesson 13. DC Motor
*/
 
 
int motorPin = 4;
int DIREC_A = 7;
int DIREC_B = 6;

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
  pinMode(DIREC_A, OUTPUT); 
  pinMode(DIREC_B, OUTPUT); 
  digitalWrite(DIREC_A, LOW);
  digitalWrite(DIREC_B, HIGH);
} 
 
 
void loop() 
{ 
    
    //secondsDelay(3);
    int speed = 200;
    if (speed >= 0 && speed <= 250)
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
