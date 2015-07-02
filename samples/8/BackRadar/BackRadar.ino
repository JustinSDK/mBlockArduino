int TONEPIN = 11;
int ECHOPIN = 12;
int TRIGPIN = 13;

double distance() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);  
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  return pulseIn(ECHOPIN, HIGH) / 58.2; 
}

void setup() {
  Serial.begin(9600);
  pinMode(TONEPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);      
}

void loop() {
  tone(TONEPIN, 262, 125);
  double cm = distance();
  Serial.println(cm);
  if(cm < 1) {
    delay(50);
  } else {
    if(cm > 20) {
      delay(1000);
    } else {
      delay(50 * cm);
    }
  }
}
