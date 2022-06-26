//Workshop 1: Across Translation Units
// event.cpp  – file name
// Vincent Yu – author
// 112708193  – author id
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

unsigned int g_sysClock{};
namespace sdds {	
	Event::Event(){
		eventTime = 0u;
		eventDesc = nullptr;
	}
	Event::Event(const Event& E) {
		eventTime = E.eventTime;
		if (E.eventDesc != nullptr)
		{
			eventDesc = new char[strlen(E.eventDesc) + 1];
			strcpy(eventDesc, E.eventDesc);
		}
	}
	Event& Event::operator=(const Event& E) {
		eventTime = E.eventTime;
		if (E.eventDesc != nullptr)
		{
			eventDesc = new char[strlen(E.eventDesc) + 1];
			strcpy(eventDesc, E.eventDesc);
		}
		return *this;
	}
	Event::~Event() {
		setEmpty();
	}

	void Event::display() {
		static int noOfCalls{};
		noOfCalls++;

		std::cout << std::setw(2) << noOfCalls << ". ";
		if (eventDesc != nullptr && eventTime != 0u) {
			// displays: COUNTER. HH:MM:SS => DESCRIPTION
			
			formatTime(std::cout);
			std::cout << " => " << eventDesc << std::endl;
		}
		else
			std::cout << "| No Event |" << std::endl;
	}
	void Event::set(const char* description) {
		
		if (description != nullptr && description[0] != '\0')
		{
			setEmpty();
			//allocates and copies the description argument.
			eventDesc = new char[strlen(description) + 1];
			strcpy(eventDesc, description);
			eventTime = g_sysClock;
		}
		else {
			//sets the Event object to an empty state if the description is invalid.
			setEmpty();
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
	void Event::setEmpty() {
		delete[] eventDesc;
		eventDesc = nullptr;
	}
}
