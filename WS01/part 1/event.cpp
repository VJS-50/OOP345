//Workshop 1: Across Translation Units
// event.cpp  – file name
// Vincent Yu – author
// 112708193  – author id

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

unsigned int g_sysClock{};
namespace sdds {
	
	
	Event::Event(){
		eventTime = 0;
		c_desc[0] = '\0';
	}

	void Event::display() {
		static int noOfCalls{};
		noOfCalls++;

		std::cout << std::setw(2) << noOfCalls << ". ";
		if (c_desc[0] != '\0') {
			// displays: COUNTER. HH:MM:SS => DESCRIPTION
			
			formatTime(std::cout);
			std::cout << " => " << c_desc << std::endl;
		}
		else
			std::cout << "| No Event |" << std::endl;
	}
	void Event::set(char* description) {
		if (description != nullptr && description[0] != '\0')
		{
			strcpy(c_desc, description);
			eventTime = g_sysClock;
		}
		else {
			c_desc[0] = '\0';
			eventTime = 0u;
		}
	}
	std::ostream& Event::formatTime(std::ostream& ostr) const{
		int minutes{ 0 }, hours{ 0 }, seconds{ 0 };

		//converts eventTime into hours, minutes, and seconds.
		seconds = eventTime % 60;
		minutes = (eventTime / 60) % 60;
		hours = (eventTime / 3600);

		//formats the variables into an HH:MM:SS format. 
		ostr << std::setfill('0') << std::setw(2) << hours << ":";
		ostr << std::setw(2) << minutes << ":";
		ostr << std::setw(2) << seconds << std::setfill(' ');

		return ostr;
	}
}
