#include <Keyboard.h>
#define Gbtn 4
#define Rbtn 5 
#define Xaxis A0 
#define Yaxis A1

void setup() {
  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(Gbtn, INPUT_PULLUP);
  pinMode(Rbtn, INPUT_PULLUP);
  pinMode(Xaxis, INPUT);
  pinMode(Yaxis, INPUT);
  
  Keyboard.begin();
}

void movement()
{
  if (digitalRead(Gbtn) == LOW)
    {
    Keyboard.write('a');
    Serial.print ("a button Pressed\n");
    delay (250);
    }
   if (digitalRead(Rbtn) == LOW) 
    {
    Keyboard.write('s');
    Serial.print ("s button pressed\n");
    delay (250);
    }
   if (analogRead(Xaxis) <= 100)
    {
     Keyboard.write(KEY_LEFT_ARROW);
     Serial.print ("Left Joystick ");
     Serial.println (analogRead(Xaxis));
     delay (250);
    }
    if (analogRead(Xaxis) >= 900)
    {
     Keyboard.write(KEY_RIGHT_ARROW);
     Serial.print ("Right Joystick ");
     Serial.println (analogRead(Xaxis));
     delay (250);
    }
    if (analogRead(Yaxis) >= 900)
    {
     Keyboard.write(KEY_DOWN_ARROW);
     Serial.print ("Down Joystick ");
     Serial.println (analogRead(Yaxis));
     delay (250);
    }
    if (analogRead(Yaxis) <= 100)
    {
     Keyboard.write(KEY_UP_ARROW);
     Serial.print ("Up Joystick ");
     Serial.println (analogRead(Yaxis));
     delay (250);
    }
}


void loop()
{
  movement();
}
