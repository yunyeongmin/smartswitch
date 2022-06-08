#include <SoftwareSerial.h>
#include "Servo.h"

Servo myservo;

int blueTx = 4;
int blueRx = 5;
SoftwareSerial mySerial(blueTx, blueRx);
String myString = "";

void setup()
{
  myservo.attach(8);
  myservo.write(0);
  mySerial.begin(9600);
}

void loop()
{
  while(mySerial.available())
  {
    char myChar = (char)mySerial.read();
    myString+=myChar;
    delay(5);
  }

  if(!myString.equals(""))
  {
    Serial.println("input value: "+myString);

    if(myString=="on")
    {
      myservo.write(120);
    }
    else
    {
      myservo.write(0);
    }
    myString="";
  }
}