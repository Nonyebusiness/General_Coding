#include <Servo.h>

int joyYPin = A1;  // Y-axis of joystick connected to analog pin A1
int servoPin = 9;  // Signal pin of the servo connected to digital pin 9

Servo myServo;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  int joyY = analogRead(joyYPin);

  // Map the joystick values (0-1023) to servo angles (0-180)
  int servoAngleY = map(joyY, 0, 1023, 0, 180);

  // Adjust the angles to suit the servo's range
  int correctedAngleY = servoAngleY;

  // Control the servo with joystick's Y axis
  myServo.write(correctedAngleY);

  delay(15); 
}
