#include <Wire.h>
#include <SoftwareSerial.h>
#include <Makeblock.h>

MeTemperature temperature(PORT_6, SLOT1);
MePotentiometer potentiometer(PORT_7);
Me7SegmentDisplay seg(PORT_3);
MeDCMotor motor(M1);

double current, target;

void processTemperature() {
  current = round(temperature.temperature());
  target = potentiometer.read() / 9.8;
  seg.display(current + (target / 100), 2);  
}

void setup() {
}

void loop(){
  processTemperature();
  if(current > target) {
    motor.run(255);
  } else {
    motor.run(0);
  }
  delay(500);  
}


