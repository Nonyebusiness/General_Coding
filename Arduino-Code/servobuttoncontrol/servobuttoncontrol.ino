#include <Servo.h>

Servo servo;

int servoPosition = 0; // Start at 0 degrees

int buttonOnPin = 13;
int buttonOffPin = 12;

void setup() {
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);

  servo.attach(9); // Assuming the servo is connected to pin 9
  servo.write(servoPosition); // Set initial position (0 degrees)
}

void loop() {
  if (digitalRead(buttonOnPin) == LOW) {
    // If the "on" button is pressed, move the servo 1 degree in the positive direction
    servoPosition = servoPosition + 10;
   
    servo.write(servoPosition);
    delay(200); // Adjust the delay time to control the speed of movement (optional)
    
  }

  if (digitalRead(buttonOffPin) == LOW) {
    // If the "off" button is pressed, move the servo 1 degree in the negative direction
    servoPosition = servoPosition - 10;
   
    servo.write(servoPosition);
    delay(200); // Adjust the delay time to control the speed of movement (optional)
    
  }
}
