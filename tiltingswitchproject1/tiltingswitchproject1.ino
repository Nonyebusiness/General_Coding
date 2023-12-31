// pin varibales
int ledPin = 8;
int buzzerPin = 9;
int tiltPin = 10;

void setup() {
  // put your setup code here, to run once:

  //setup pin
  pinMode (ledPin, OUTPUT);
  pinMode (buzzerPin, OUTPUT);
  pinMode (tiltPin, INPUT_PULLUP);

  //turn of buzzer and led
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
  

  //this code looks at tilt switch
  // if the input is high that means contact has been proken and internal pull resistor can pull the input to high
  //this acts as a trigger
  //the buzzer and led are actiavted but we never set them low

  if (digitalRead(tiltPin) == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }



}
