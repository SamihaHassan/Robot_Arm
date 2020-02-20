int valA = 0;
int ruptPin = 3;
int PinFive = 0;

void ISRx() {
 Serial.println("ISR");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ruptPin, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ruptPin),ISRx,CHANGE);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
valA = analogRead(ruptPin) > 600 ? 1 : 0;
Serial.print(valA);
Serial.print("   ");

digitalWrite(5, valA);
PinFive = digitalRead(5);
Serial.println(PinFive);
}
