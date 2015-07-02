#include <Wire.h>
#include <SoftwareSerial.h>
#include <Makeblock.h>

MeBluetooth bluetooth(PORT_4);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Bluetooth Start!");
}

void loop() {
  if(bluetooth.available()) {
      Serial.println(bluetooth.read());
  }
}

