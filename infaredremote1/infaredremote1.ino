#include "IRremote.h"

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
  if (irrecv.decodedIRData.decodedRawData == 0xE31CFF00) {
    ledState = !ledState;           // Toggle the state of the LED
    digitalWrite(ledPin, ledState); // Set the LED's state based on the toggle
    
    Serial.println("5 input");      // Print "5 input" to the serial monitor
  }

  //store the last decodedRawData
  last_decodedRawData = irrecv.decodedIRData.decodedRawData;
  delay(500); // Do not get immediate repeat
} //END translateIR

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode()) // have we received an IR signal?
  {
    translateIR();
    irrecv.resume(); // receive the next value
  }
}/* --(end main loop )-- */



