void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  analogWrite(9, random(0, 255));
  analogWrite(10, random(0, 255));
  analogWrite(11, random(0, 255));
  delay(1000);
}
