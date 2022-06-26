//Workshop 1: Across Translation Units
// event.cpp  – file name
// Vincent Yu – author
// 112708193  – author id
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_
extern unsigned int g_sysClock;
namespace sdds {
	class Event {
		char c_desc[128];	//description of the event.
		unsigned int eventTime{}; //time of the event in seconds.
	public:
		Event();
		void display();
		void set(char* description = NULL);

		//added function: formats the time from the eventTime member variable.
		std::ostream& formatTime(std::ostream& ostr) const;
	};
	
	
}

#endif // !SDDS_EVENT_H_