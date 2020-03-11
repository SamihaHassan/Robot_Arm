#include <stdlib.h>
#include <Arduino.h>
#include <globals.h>
#include <pid_controller.h>

//slot detector readibgs
int valA1 = 0;
int valA2 = 0;
int valB1 = 0;
int valB2 = 0;

volatile int dirA = 0; 
volatile int dirB = 0; 

int countA = 0;
int countB = 0;
float thetaDegA = 0;
float thetaDegB = 0;
float thetaDiffA = 0;
float thetaDiffB = 0;
int pidA = 0;
int pidB = 0;

float thetaDesiredA = 0;
float thetaDesiredB = 0;

//PID controller variables 
unsigned long time = 0; 
unsigned long prev_time = 0; 
unsigned long delta_t; 
float errorA; 
float errorB; 

void secondsDelay(int n);

//Interrupts from slot detectors to determine the direction of spin
void ISRA1();
void ISRA2();
void ISRB1();
void ISRB2();

//motor driver setup
void setFWD(int motor_num);
void setREV(int motor_num);

//compute PID function in pid_controller lib and apply PID in main
void applyPID();

PID* PIDA = new PID();
PID* PIDB = new PID();

void setup() {
  Serial.begin(9600);
  
  //slot detectors triggering interrupts
  attachInterrupt(digitalPinToInterrupt(RUPT_PIN_A1),ISRA1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(RUPT_PIN_A2),ISRA2,CHANGE);
  attachInterrupt(digitalPinToInterrupt(RUPT_PIN_B1),ISRB1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(RUPT_PIN_B2),ISRB2,CHANGE);

  valA1 = digitalRead(RUPT_PIN_A1); //initial reading from the slot detector
  valA2 = digitalRead(RUPT_PIN_A2);

  valB1 = digitalRead(RUPT_PIN_B1); //initial reading from the slot detector
  valB2 = digitalRead(RUPT_PIN_B2);

  dirA = (valA1 ^ valA2) ? 0 : 1;   //Rotational directiob : MOTOR_A
  dirB = (valB1 ^ valB2) ? 0 : 1;   //Rotational directiob : MOTOR_B

  countA = 0;
  countB = 0;

  //setup for MOTOR_A
  pinMode(MOTOR_PIN_A, OUTPUT); //PWM pin
  pinMode(DIREC_A1, OUTPUT);    //i/p to Motor driver A
  pinMode(DIREC_A2, OUTPUT);    //i/p to Motor driver A
  setREV(0);                     //any dieection to just start the motot
  analogWrite(MOTOR_PIN_A, 0); 
  secondsDelay(3);
  analogWrite(MOTOR_PIN_A, 100); 

  //setup for MOTOR_B
  pinMode(MOTOR_PIN_B, OUTPUT); //PWM pin
  pinMode(DIREC_B1, OUTPUT);    //i/p to Motor driver B
  pinMode(DIREC_B2, OUTPUT);    //i/p to Motor driver B
  setREV(1);                     //any dieection to just start the motot
  analogWrite(MOTOR_PIN_B, 0); 
  secondsDelay(3);
  analogWrite(MOTOR_PIN_A, 100); 

} //end setup


void loop()
{        
    //Serial.println(dir);
    Serial.println("--------------------------------------");
   
    //read input for theta setpoint; thetaDesired is hardcoded for now 
    thetaDesiredA = 120;
    thetaDesiredB = 90;
    Serial.print("thetaDesired: ");
    Serial.println(thetaDesiredA);
    
    //read theta from encoder;
    thetaDegA = DEG((float)countA*1.8); //Serial.println(thetaDeg); //thetaDeg = 45;   
    thetaDegB = DEG((float)countB*1.8); //Serial.println(thetaDeg); //thetaDeg = 45; 
    Serial.print("thetaActual_A: ");
    Serial.print(thetaDegA);
    Serial.print("\tthetaActual_B: ");
    Serial.println(thetaDegB);
   
    //inputs for PID
    errorA = thetaDesiredA - thetaDegA; 
    errorB = thetaDesiredB - thetaDegB; 
   
    //thetaDiff = DEG(thetaDesired - thetaDeg); 
    Serial.print("error_A: ");
    Serial.print(errorA);
    Serial.print("\tthetaDiff_A: ");
    Serial.println(thetaDiffA);

    Serial.print("error_B: ");
    Serial.print(errorB);
    Serial.print("\tthetaDiff_B: ");
    Serial.println(thetaDiffB);

    prev_time = time; 
    time = millis(); 
    delta_t = time - prev_time; 

    //compute PID on theta desired
    pidA = (PIDA->ComputePID(delta_t, errorA));
    pidB = (PIDB->ComputePID(delta_t, errorB));
    Serial.print("PIDA: ");
    Serial.print(pidA); 
    Serial.print("\tPIDB: ");
    Serial.println(pidB); 
    
    analogWrite(MOTOR_PIN_A, abs(pidA));
    analogWrite(MOTOR_PIN_B, abs(pidB));
    if (pidA < 0) {
        setFWD(0);
    }
    else {
      setREV(0);
    }

    if (pidB < 0) {
        setFWD(1);
    }
    else {
      setREV(1);
    }

    delayMicroseconds(50);
    
    //use PID signal to follow trajectory 
    //applyPID();
      
} //end main


void ISRA1() {
  dirA = (valA1 ^ valA2) ? 0 : 1;
  valA1 = digitalRead(RUPT_PIN_A1);
  dirA ? countA++ : countA--;
  
}

void ISRA2() {
  valA2 = digitalRead(RUPT_PIN_A2);
  dirA = (valA1 ^ valA2) ? 0 : 1;
}


void ISRB1() {
  dirB = (valB1 ^ valB2) ? 0 : 1;
  valB1 = digitalRead(RUPT_PIN_B1);
  dirB ? countB++ : countB--;
  
}

void ISRB2() {
  valA2 = digitalRead(RUPT_PIN_B2);
  dirB = (valB1 ^ valB2) ? 0 : 1;
}


void setREV(int motor_num) {
  Serial.println("REV");
  if(!motor_num){
    digitalWrite(DIREC_A1, LOW);
    digitalWrite(DIREC_A2, HIGH);
  }
  else {
    digitalWrite(DIREC_B1, LOW);
    digitalWrite(DIREC_B2, HIGH);
  } 
}

void setFWD(int motor_num) {
  Serial.println("FWD");
  if(!motor_num){
    digitalWrite(DIREC_A1, HIGH);
    digitalWrite(DIREC_A2, LOW); 
  }
  else {
    digitalWrite(DIREC_B1, HIGH);
    digitalWrite(DIREC_B2, LOW); 
  }   
}

void secondsDelay(int n) 
{
    int i = 0;
    for (i=0; i < n; i++) {
      delay(1000);
    }  
}