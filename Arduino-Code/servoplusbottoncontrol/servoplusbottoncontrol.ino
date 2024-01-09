#include "IRremote.h"
#include <Servo.h>

Servo servo; //sets servo to to servo text


int servoPosition = 90; //starts at 0 degrees




int receiver = 3; // Signal Pin of IR receiver to Arduino Digital Pin 11
int ledPin = 10;  // LED Pin connected to Arduino Digital Pin 10

IRrecv irrecv(receiver);
//vairable uses to store the last decodedRawData
uint32_t last_decodedRawData = 0;

bool ledState = false; // Variable to track the state of the LED

void translateIR() // takes action based on IR code received
{
  // Check if it is a repeat IR code 
  if (irrecv.decodedIRData.flags)
  {
    //set the current decodedRawData to the last decodedRawData 
    irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    Serial.println("REPEAT!");
  } else
  {
    //output the IR code on the serial monitor
    Serial.print("IR code:0x");
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
  }
  
  // Check if the received IR code matches the code for the number 5 button
  if (irrecv.decodedIRData.decodedRawData == 0xBA45FF00) 
  {
    ledState = !ledState;           // Toggle the state of the LED
    digitalWrite(ledPin, ledState); // Set the LED's state based on the toggle
    delay(500);
    Serial.println("5 input");      // Print "5 input" to the serial monitor
  }

  if (irrecv.decodedIRData.decodedRawData == 0xA55AFF00) 
  {
    servoPosition = servoPosition - 10;
   
    servo.write(servoPosition);
    delay(200); // Adjust the delay time to control the speed of movement (optional)
    
    Serial.println("6 input");      // Print "5 input" to the serial monitor
  }

  if (irrecv.decodedIRData.decodedRawData == 0xF708FF00) 
  {
    servoPosition = servoPosition + 10;
   
    servo.write(servoPosition);
    delay(200); // Adjust the delay time to control the speed of movement (optional)
  }

  //store the last decodedRawData
  last_decodedRawData = irrecv.decodedIRData.decodedRawData;
  
} //END translateIR

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver


  servo.attach(9);
  servo.write(90);
}

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode()) // have we received an IR signal?
  {
    translateIR();
    irrecv.resume(); // receive the next value
  }



}/* --(end main loop )-- */



