#define BLUE 3
#define GREEN 5
#define RED 6

void setup() 
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

int redvalue = 255;
int greenvalue = 0;
int bluevalue = 0;

void loop() 
{
  int delayTime = 10;  // Adjust this value to control the speed of fading

  for(int i = 0; i < 255; i += 1)
  {
    redvalue -= 1;
    greenvalue += 1;

    analogWrite(RED, redvalue);
    analogWrite(GREEN, greenvalue);
    delay(delayTime);
  }

  for(int i = 0; i < 255; i += 1)
  {
    greenvalue -= 1;
    bluevalue += 1;

    analogWrite(GREEN, greenvalue);
    analogWrite(BLUE, bluevalue);
    delay(delayTime);
  }

  for(int i = 0; i < 255; i += 1)
  {
    bluevalue -= 1;
    redvalue += 1;

    analogWrite(BLUE, bluevalue);
    analogWrite(RED, redvalue);
    delay(delayTime);
  }
}
