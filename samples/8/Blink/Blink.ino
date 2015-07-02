void setup() {
  // 將數位腳位 13 設定為輸出之用
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);  // 設定 D13 為高電位
  delay(1000);             // 等待 1000 毫秒 
  digitalWrite(13, LOW);   // 設定 D13 為低電位
  delay(1000);             // 等待 1000 毫秒 
}
