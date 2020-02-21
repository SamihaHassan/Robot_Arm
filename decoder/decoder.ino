
int ruptPinA = 2;
int ruptPinB = 3;
int valA = 0;
int valB = 0;
int dir = 0;
int count = 0;
float thetaDeg = 0;

int motorPin = 4;
int DirecOne = 7;
int DirecTwo = 6;

void ISRA() {
  dir = (valA ^ valB) ? 0 : 1;
  valA = digitalRead(ruptPinA);
  dir ? count++ : count--;
  
}


void ISRB() {
  valB = digitalRead(ruptPinB);
  dir = (valA ^ valB) ? 0 : 1;

}

void spinFWD() {
  digitalWrite(DirecOne, LOW);
  digitalWrite(DirecTwo, HIGH);
}

void spinREV() {
  digitalWrite(DirecOne, HIGH);
  digitalWrite(DirecTwo, LOW);  
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(ruptPinA),ISRA,CHANGE);
  attachInterrupt(digitalPinToInterrupt(ruptPinB),ISRB,CHANGE);
  valA = digitalRead(ruptPinA); //initial reading
  valB = digitalRead(ruptPinB);
  dir = (valA ^ valB) ? 0 : 1;
  count = 0;
  pinMode(motorPin, OUTPUT); //PWM pin
  pinMode(DirecOne, OUTPUT); 
  pinMode(DirecTwo, OUTPUT); 
  spinFWD();
  
}

void loop()
{
    int speed = 120;
    analogWrite(motorPin, speed);
    
    //Serial.println(dir);
    delay(50);
    
    thetaDeg = (float)count*0.6;
    
    Serial.println(thetaDeg);
}
