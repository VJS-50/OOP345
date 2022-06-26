//Workshop 1: Across Translation Units
// event.h    – file name
// Vincent Yu – author
// 112708193  – author id
#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_
extern unsigned int g_sysClock;
namespace sdds {
	class Event {
		char* eventDesc;	//description of the event.
		unsigned int eventTime{}; //time of the event in seconds.
	public:
		Event();
		Event(const Event& E);
		Event& operator=(const Event& E);
		~Event();
		void display();
		void set(const char* description = nullptr);

		//added functions: 
		//formats the time from the eventTime member variable.
		std::ostream& formatTime(std::ostream& ostr) const;
		//sets the object to an empty state.
		void setEmpty();
	};
	
	
}

#endif // !SDDS_EVENT_H_