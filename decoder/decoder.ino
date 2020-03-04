#define MAX_NUM 10
int ruptPinA = 2;
int ruptPinB = 3;
int valA = 0;
int valB = 0;
int dir = 0;
int count = 0;
float last_theta = 0;
float now_theta = 0;
unsigned long last_time = 0;
unsigned long now_time = 0;
float AngSpeed = 0;
float arr[200][2];

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
  Serial.begin(115200);
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
  Serial.print("done setup\n");
  secondsDelay(3);
  Serial.print("start loop\n");
  
}

void loop()

{   
  static int a = 0;
  
    last_time = now_time;
    last_theta = now_theta;
    int speed = 70;
//    count = 0;
    
    analogWrite(motorPin, speed);
    secondsDelay(1);
//    analogWrite(motorPin, 0);
//    secondsDelay(2);

    
    now_theta = (float)count*1.8;
    now_time = millis();
    arr[a][1] = now_time;
    AngSpeed = (now_theta-last_theta)/(float)(now_time-last_time);
    arr[a][0] = AngSpeed;
//    Serial.print("now_theta\t");
//    Serial.print(now_theta);
//    Serial.print("\n\tspeed\t");
//    Serial.print(AngSpeed);
//    Serial.print("\ttime\t");
//    Serial.println(now_time);
  a++;
  if (a>MAX_NUM) {
     for (int i=0; i<MAX_NUM; i++) {
      for (int j=0; j<2; j++) {
        Serial.print(arr[i][j]);
        Serial.print("\t");
      }
       Serial.print("\n");
     } 
    Serial.print("done code\n");
  }
  
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
