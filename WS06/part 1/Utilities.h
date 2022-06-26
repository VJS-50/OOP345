#include "Vehicle.h"
namespace sdds{
	
	Vehicle* createInstance(std::istream& istr){
		std::string line;
		char type ='\0';
		char delimiter ='0';
		getline(istr, line);
		
		stringstream ss(line);
		ss>>type>>delimiter;
		
		if(ss){
			
			switch(type)
			case 'c': case 'C'
				return new Car(ss);
				break;
			case 'r': case 'R'
				return new Racecar(ss);
				break;
			default:
				return nullptr;
				break;
		}
	}
}