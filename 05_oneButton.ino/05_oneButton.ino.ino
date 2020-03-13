/*
   Project: Using OneButton library
   Description: Introduct Students to OneButton Library using a button and the serial monitor
   Author: Clint Wolf
   Date: 3-3-2020
   Button 13 with a pull-down resisitor
*/

#include <OneButton.h>

// Setup OneButton on pin 23 // Pin 23 can handle analog read and write
OneButton button1(23, false);

// Create variables buttonState and flash
int ledDelay = 100; // 1000 ms = 1 s
int buttonState = LOW;
int flash = LOW;
int ledPinGreen = 5; // the Green LED is drawing power from Pin 5

// ------------------------------------------- VOID SETUP FUNCTION

void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600);
  while (!Serial);

  pinMode(ledPinGreen, OUTPUT);

  // Link oneButton library to functions click1, doubleclick1, longPressStart1

  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  //button1.attachLongPressStart(longPressStart1);
  //button1.attachLongPressStop(longPressStop1);
  button1.setClickTicks(250);
  button1.setPressTicks(1000);
}

//======================================================================================

void loop()
{
  // keep watching the push buttons:
  button1.tick();
  //  The above line determines when a CLICK, DOUBLECLICK, or LONGCLICK
  //  occurs, then performs the associated function.

  // Determining what to do based on the values of "buttonState" and "flash"

  if (buttonState == LOW)
    {
    digitalWrite(ledPinGreen, LOW);
    }
  else
    {
    digitalWrite(ledPinGreen, HIGH);
    // doing anything with "flash" requires that "buttonState" be HIGH (the LED is on)
    if (flash == LOW)
      {
      digitalWrite(ledPinGreen, HIGH);
      }
    else
      {
      digitalWrite(ledPinGreen, HIGH);
      delay(ledDelay);
      digitalWrite(ledPinGreen, LOW);
      delay(ledDelay);
      }
    }
}

//======================================================================================

void click1()

// This function will be called when the button1 was pressed 1 time.
{
  //change and print buttonState
  Serial.println("Button 1 single click");
  buttonState = !buttonState;
}

//======================================================================================

void doubleclick1()

// This function will be called when the button1 was pressed 2 times in a short time frame.
{
  // change and print flash state
  Serial.println("Button 1 double clicked");
  flash = !flash;
}

//======================================================================================

void longPressStart1()
// This function will be called once, when the button1 is pressed for a long time.
{
  // print longPress

  Serial.println("Button 1 long press");

}

//======================================================================================

// This function will be called once, when the button1 is long pressed, then released to go on vacation.
void longPressStop1()
{
  // print longPress

  Serial.println("Button 1 long press stop");

} // longPressStop1
