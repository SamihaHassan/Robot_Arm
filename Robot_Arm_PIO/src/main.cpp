#include <stdlib.h>
#include <Arduino.h>
#include <globals.h>
#include <pid_controller.h>
//#include <Ticker.h>

int valA = 0;
int valB = 0;
int dir = 0;
int count = 0;
float thetaDeg = 0;
float thetaDesired = 0;
float thetaDiff = 0;
float pid = 0;
int pwm = 0;

//PID controller variables 
unsigned long time = 0; 
unsigned long prev_time = 0; 
unsigned long delta_t; 
float error; 

void secondsDelay(int n);

//Interrupts from slot detectors to determine the direction of spin
void ISRA();
void ISRB();
//motor driver setup
void setFWD();
void setREV();
//compute PID function in pid_controller lib and apply PID in main
void applyPID();

PID* PIDA = new PID();

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
  setFWD();
  analogWrite(MOTOR_PIN_A, 0); 
  secondsDelay(1);
  analogWrite(MOTOR_PIN_A, 100); 
} //end setup

void loop()
{        
    //Serial.println(dir);
    Serial.println("---------------------------------");
    //read input for theta setpoint; thetaDesired = ?
    thetaDesired = 180;
    Serial.print("thetaDesired: ");
    Serial.println(thetaDesired);
    //read theta from encoder;
    thetaDeg = DEG((float)count*1.8); //Serial.println(thetaDeg); //thetaDeg = 45;   
    Serial.print("thetaActual: ");
    Serial.println(thetaDeg);
    //inputs for PID
    error = abs(thetaDesired - thetaDeg); 
    thetaDiff = DEG(thetaDesired - thetaDeg); 
    Serial.print("error: ");
    Serial.println(error);
    Serial.print("thetaDiff: ");
    Serial.println(thetaDiff);

    prev_time = time; 
    time = millis(); 
    delta_t = time - prev_time; 


    
    //compute PID on theta desired
    pid = PIDA->ComputePID(delta_t, thetaDiff);
    Serial.print("PID output: ");
    Serial.println(pid); 
    
    //use PID signal to follow trajectory 
    applyPID();
  
    delay(100);
} //end main

void applyPID() {
    //pwm = 100;
    pwm = ((int)pid > 255 ? 255 : (int)pid);
    Serial.print("pwm: ");
    Serial.println(pwm);
    //pwm = 100;
    if ( thetaDiff <= 180 ) {
      setREV();
      analogWrite(pwm, MOTOR_PIN_A);
    }
    else {
      setFWD();
      analogWrite(pwm, MOTOR_PIN_A);
    }
      
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


void setREV() {
  Serial.println("REV");
  digitalWrite(DIREC_A, LOW);
  digitalWrite(DIREC_B, HIGH);
}

void setFWD() {
  Serial.println("FWD");
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