#define POLE_1 51
#define POLE_2 47
#define POLE_3 43

#define WAIT_TIME 90

int wait_time_var = 90;
int count = 1;

void setup() {
  pinMode(POLE_1, OUTPUT);
  pinMode(POLE_2, OUTPUT);
  pinMode(POLE_3, OUTPUT);
}

void loop() {
// /*
  if(count > 72){
    count = count - 2;
  }
  
  wait_time_var= WAIT_TIME - count;

 digitalWrite(POLE_1, HIGH);
 digitalWrite(POLE_2, LOW);
 digitalWrite(POLE_3, LOW);
 delay(wait_time_var);

 //*/
// /*
 digitalWrite(POLE_1, LOW);
 digitalWrite(POLE_2, HIGH);
 digitalWrite(POLE_3, LOW);
 delay(wait_time_var);

 //*/
///*
 digitalWrite(POLE_1, LOW);
 digitalWrite(POLE_2, LOW);
 digitalWrite(POLE_3, HIGH);
 delay(wait_time_var);
 count++;
 //*/
}
