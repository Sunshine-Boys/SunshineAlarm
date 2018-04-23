/*
Modified by: Sunshine Boys
Time Stamp: April 2018
Source: http://learn.adafruit.com/photocells

Brief: Photocell monitor that controls blinds

Breadboard Instructions Below :
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground 
Connect LED from pin 11 through a resistor to ground 
*/

#include"Blinds.h"

 //----------PHOTO-------------------------------------
int photocellPin = 0;     // the cell and 10K pulldown
									   // photocell is connected to analog pin A0
int photocellReading;    // the analog reading from the sensor divider							   
//------------BLINDS-------------------------
Blinds blinds;
int upPin = 2;                //move blinds up
int neutralPin = 3;		  //stop blind movement
int downPin = 4;           //move blinds down
//---------------------------------------------

void setup(void) 
{
	Serial.begin(9600);   //Watching Debug Info on Serial Monitor
  
	pinMode(upPin, OUTPUT);
	pinMode(neutralPin, OUTPUT);
	pinMode(downPin, OUTPUT);
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
  int state =  blinds.getState();
  Serial.print("The State = ");
  Serial.println(state);
  //-----------------Adjusts For Large Values------------------
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  //photocellReading = 1023 - photocellReading;
  
  //-------------Adjusts Blind Vertical Movement---------------
  if(photocellReading > 100 && state == 0)
  {
	Serial.println("Moving Blinds Up!");
	//blinds.Up(5); //5 seconds move up
	digitalWrite(upPin, HIGH);
	delay(5000);
	digitalWrite(upPin, LOW);
	
	//blinds.Neutral();
	digitalWrite(neutralPin, HIGH);
	delay(500);
	digitalWrite(neutralPin, LOW);
	
	blinds.setState(1);
  }
  else if(photocellReading < 20 && state == 1)
  {
	Serial.println("Moving Blinds Down!");
	//blinds.Down(5); //5 seconds move down
	digitalWrite(downPin, HIGH);
	delay(5000);
	digitalWrite(downPin, LOW);
	
	//blinds.Neutral();
	digitalWrite(neutralPin, HIGH);
	delay(500);
	digitalWrite(neutralPin, LOW);
	
	blinds.setState(0);
  }
 
  delay(1000);
}
