#include <Arduino.h>
#include <globals.h>

int valA = 0;
int valB = 0;
int dir = 0;
int count = 0;
float thetaDeg = 0;

void secondsDelay(int n);

//Interrupts from slot detectors to determine the direction of spin
void ISRA();
void ISRB();

//motor driver setup
void spinFWD();
void spinREV();



void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(RUPT_PIN_A),ISRA,CHANGE);
  attachInterrupt(digitalPinToInterrupt(RUPT_PIN_B),ISRB,CHANGE);
  valA = digitalRead(RUPT_PIN_A); //initial reading
  valB = digitalRead(RUPT_PIN_B);
  dir = (valA ^ valB) ? 0 : 1;
  count = 0;
  pinMode(MOTOR_PIN_A, OUTPUT); //PWM pin
  pinMode(DIREC_A, OUTPUT); 
  pinMode(DIREC_B, OUTPUT); 
  spinFWD();
  
}

void loop()
{
    int speed = 200;
    
    analogWrite(MOTOR_PIN_A, speed);
    
    //Serial.println(dir);
    secondsDelay(5);
    analogWrite(MOTOR_PIN_A, 0);
    secondsDelay(5);
    thetaDeg = (float)count*1.8;
    
    Serial.println(thetaDeg);
}


void ISRA() {
  dir = (valA ^ valB) ? 0 : 1;
  valA = digitalRead(RUPT_PIN_A);
  dir ? count++ : count--;
  
}

void ISRB() {
  valB = digitalRead(RUPT_PIN_B);
  dir = (valA ^ valB) ? 0 : 1;

}


void spinFWD() {
  digitalWrite(DIREC_A, LOW);
  digitalWrite(DIREC_B, HIGH);
}

void spinREV() {
  digitalWrite(DIREC_A, HIGH);
  digitalWrite(DIREC_B, LOW);  
}

void secondsDelay(int n) 
{
    int i = 0;
    for (i=0; i < n; i++) {
      delay(1000);
    }  
}