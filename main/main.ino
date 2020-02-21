
int ruptPinA = 2;
int ruptPinB = 3;
int valA = 0;
int valB = 0;
int dir = 0;
int count = 0;
float thetaDeg = 0;

void ISRA() {
  dir = (valA ^ valB) ? 0 : 1;
  valA = digitalRead(ruptPinA);
  dir ? count++ : count--;
  
}


void ISRB() {
  valB = digitalRead(ruptPinB);
  dir = (valA ^ valB) ? 0 : 1;

}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(ruptPinA),ISRA,CHANGE);
  attachInterrupt(digitalPinToInterrupt(ruptPinB),ISRB,CHANGE);
  valA = digitalRead(ruptPinA); //initial reading
  valB = digitalRead(ruptPinB);
  dir = (valA ^ valB) ? 0 : 1;
  count = 0;
}

void loop()
{
    //Serial.println(dir);
    delay(50);
    
    thetaDeg = (float)count*0.6;
    
    Serial.println(thetaDeg);
}
