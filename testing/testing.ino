unsigned long time = 0;
  unsigned long time_old = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("begin");
  time_old = millis();
  Serial.print("time_old: ");
  Serial.println(time_old);

  delay(100);
  time = millis();
  Serial.print("time: ");
  Serial.println(time);
  
}
