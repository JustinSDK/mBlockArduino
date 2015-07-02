#include <Stepper.h>

const int stepsPerRevolution = 2048;  
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // set the speed at 5 rpm:
  myStepper.setSpeed(5);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

