int pinState[9][7] = {
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 1, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 1, 1, 0}  // 9
};

void set7Seg(int number, int pos) {
  for(int i = 10; i < 14; i++) { // 清除顯示
    digitalWrite(i, 1);
  }
    
  for(int i = 0;i < 7;i++) {
    digitalWrite(i + 3, pinState[number - 1][i]);   // 設定七段顯示器各段狀態
  }
    
  digitalWrite(pos + 9, 0);  // 指定要顯示哪一個七段顯示器
  delay(5);
}

void setup() {
  for(int i = 3; i < 14; i++) {
    pinMode(i, OUTPUT);
  } 
}

void loop() {
  set7Seg(8, 4); 
  set7Seg(7, 3); 
  set7Seg(6, 2);
  set7Seg(5, 1);
}

