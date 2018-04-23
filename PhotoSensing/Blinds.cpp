/*
Created by: Sunshine Boys
Time Stamp: April 2018
Summary: Electronic Blind Control
*/
#include"Blinds.h"

Blinds::Blinds()
{
	int m_state = 0; //down
}
/*void Blinds::Up(int seconds)
{
	seconds = seconds * 1000;
	
	digitalWrite(upPin, High);
	delay(seconds);
	digitalWrite(upPin, Low);
}
void Blinds::Down(int seconds)
{
	seconds = seconds * 1000;
	
	digitalWrite(downPin, High);
	delay(seconds);
	digitalWrite(downPin, Low);
}
void Blinds::Neutral()
{
	digitalWrite(neutralPin, High);
	delay(100);
	digitalWrite(neutralPin, Low);
}*/
void Blinds::setState(int state)
{
	m_state = state;
}
int Blinds::getState()
{
	return m_state;
}