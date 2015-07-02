#include <Wire.h>
#include <SoftwareSerial.h>
#include <Makeblock.h>

MeRGBLed rgb(PORT_3);

void setLED() {
  for(int i = 0; i < 4; i++) {
    rgb.setColorAt(i, random(1, 255), random(1, 255), random(1, 255));
    rgb.show();
  }    
}

void setup() {
  rgb.setNumber(4);
}

void loop(){    
    setLED();
    delay(500);
}


