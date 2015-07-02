#include <Wire.h>
#include <SoftwareSerial.h>
#include <Makeblock.h>

MeRGBLed rgb(PORT_3);
Me7SegmentDisplay seg(PORT_4);
MeSoundSensor soundsensor(PORT_6);

int r, g, b;

void processLED() {
  if(r + g + b != 0) {
    r = r - 5;
    g = g - 5;
    b = b - 5;
    if(r < 0) {
       r = 0;
    }
    if(g < 0) {
       g = 0;
    }
    if(b < 0) {
       b = 0;
    }
    for(int i = 0; i < 4; i++) {
      rgb.setColorAt(i, r, g, b);
    }
    rgb.show();
  }  
}

void setup() {
  rgb.setNumber(4);
  rgb.show();
}

void loop(){   
  int strength = soundsensor.strength();
  seg.display(strength);
  if(strength > 300) {
     r = random(1, 255);
     g = random(1, 255);
     b = random(1, 255);
  }
  processLED();  
}


