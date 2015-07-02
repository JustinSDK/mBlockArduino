#include <Wire.h>
#include <SoftwareSerial.h>
#include <Makeblock.h>

MePIRMotionSensor pir(PORT_3);
Me7SegmentDisplay seg(PORT_4);
MeLightSensor lightsensor(PORT_6);
MePotentiometer potentiometer(PORT_7);

void processMotionLED() {
  if(pir.isPeopleDetected()){
    lightsensor.lightOn();
  } else {
    lightsensor.lightOff();
  }
}

void setup() {
  pinMode(12, OUTPUT);
  digitalWrite(12, 1); // PIR可重複觸發模式
}

void loop(){
  int number = potentiometer.read();
  seg.display(number);
  if(lightsensor.read() < number){
     processMotionLED();
  }
  delay(1000);    
}


