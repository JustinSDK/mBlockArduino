double bpm(int pin) {
  return round(analogRead(pin) * 0.16422 + 40);
}

void setup(){
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

void loop(){
  tone(13, 262, 125);
  double seconds = 60 / bpm(A0);
  delay(1000 * seconds);
  noTone(13);  // 關閉聲音
}


