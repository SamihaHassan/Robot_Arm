#define POLE_1 51 //Phase A
#define POLE_2 47 //Phase B
#define POLE_3 43 //Phase C

#define DIRECTION 39 //Input telling which way to spin  1:CW   0:CCW
#define INTERRUPT 38 // The same signal goes to DIRECTION and INTERRUPT ;monitoring change
#define WAIT_TIME 80 //regular wait time when going in one direction

int rotor_pos = 30000; // %3 = 0  tracks position of the rotor
int next_coil =0;      // selected next coil
int current_energized_coil = 0; //value between 0 and 2    0A 1B 3C
bool interrupt_called = 0; // acknowledge interrupt

void setup() {
  // put your setup code here, to run once:
  pinMode(POLE_1, OUTPUT);
  pinMode(POLE_2, OUTPUT);
  pinMode(POLE_3, OUTPUT);
  pinMode(DIRECTION, INPUT);
  pinMode(INTERRUPT, INPUT);

  //At start energize coil a to know starting position of ROTOR not ARM
   digitalWrite(POLE_1, HIGH);
   digitalWrite(POLE_2, LOW);
   digitalWrite(POLE_3, LOW);
   delay(100); // let rotor settle into known position
   attachInterrupt(digitalPinToInterrupt(INTERRUPT),blink,CHANGE);

   
}

void loop() {
  // put your main code here, to run repeatedly:

  current_energized_coil = rotor_pos %3;                //based on the position of the rotor we find the current energized coil
  bool dirCW = (digitalRead(DIRECTION)== HIGH);         // We check whether or not we rotating clock-wise, if not we rotate CCW
  next_coil = SelectCoil(dirCW,current_energized_coil); //We select the next coil that we want to energize based on direction and current coil
  EnergizeCoil(next_coil);                              // Energize the coil
  current_energized_coil = next_coil;                   //update the currently energized coil
  responsiveDelay(WAIT_TIME,interrupt_called);          //Enter the delay between switching phases, delay end on interrupt call
}

void EnergizeCoil(int next_energized_coil) { // this energized the desired coil

  switch (next_energized_coil){
    
      case 0: digitalWrite(POLE_1, HIGH);
              digitalWrite(POLE_2, LOW);
              digitalWrite(POLE_3, LOW);
              
      case 1: digitalWrite(POLE_1, LOW);
              digitalWrite(POLE_2, HIGH);
              digitalWrite(POLE_3, LOW);
              
      case 2: digitalWrite(POLE_1, LOW);
              digitalWrite(POLE_2, LOW);
              digitalWrite(POLE_3, HIGH);
  }
}

int SelectCoil(bool clockwise, int currentCoil){ // This function selects the coil that is going to be energized
  //inputs to function: clockwise? currentCoil
  int next_energized_coil=0;
  
  if (clockwise){
    
    switch (currentCoil){
      case 0: next_energized_coil=2; //A then C
      case 1: next_energized_coil=0; //B then A
      case 2: next_energized_coil=1; //C then B
    }
    rotor_pos++;
    
  } else {
    
    switch (currentCoil){
      case 0: next_energized_coil=1; //A then B
      case 1: next_energized_coil=2; //B then C
      case 2: next_energized_coil=0; //C then A
    }
    rotor_pos--;
    
  }

  return next_energized_coil;
}

void blink(){                                              //This is the ISR just acknowledges the interrupt
  interrupt_called = 1;
  return;
}

void responsiveDelay(int delayTime, bool interrupt_called){ //This delay responds to the change in direction
   for(int i = 0; i<delayTime; i++){
    delay(1);
    if(interrupt_called)
      break;
      delay(10);                            // allow rotor to align before switching phases
   }
   interrupt_called = 0;
   return;
}
