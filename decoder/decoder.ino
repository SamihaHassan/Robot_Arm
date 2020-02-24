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

void secondsDelay(int n);

//Interrupts from slot detectors to determine the direction of spin
void ISRA();
void ISRB();

//motor driver setup
void spinFWD();
void spinREV();



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
    int speed = 200;
    
    analogWrite(motorPin, speed);
    
    //Serial.println(dir);
    secondsDelay(5);
    analogWrite(motorPin, 0);
    secondsDelay(5);
    thetaDeg = (float)count*1.8;
    
    Serial.println(thetaDeg);
}


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

void secondsDelay(int n) 
{
    int i = 0;
    for (i=0; i < n; i++) {
      delay(1000);
    }  
}
