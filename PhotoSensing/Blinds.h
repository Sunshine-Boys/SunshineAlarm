/*
Created by: Sunshine Boys
Time Stamp: April 2018
Summary: Table of Contents For Blinds Control
*/
#ifndef  BLINDS_H
#define BLINDS_H

class Blinds
{
	public:
		Blinds();
		//void Up(int seconds);
		//void Down(int seconds);
		//void Neutral();
		
		void setState(int state);
		int getState();
		
	private:
		int m_state;
		
		//int upPin;
		//int downPin;
		//int neutralPin;
};

//#include"Blinds.cpp"
#endif