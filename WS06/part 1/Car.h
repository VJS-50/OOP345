#include "Vehicle.h"
#include <string>
namespace sdds {
	class Car:public Vehicle{
		char m_tag;
		std::string m_manufacturer;
		std::string m_condition;
		double m_topSpeed;
	public:
		Car(std::istream &istr);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream ostr) const;
		std::string trim(std::string& str) const 
	}
	
	
	std::string Car::trim(std::string& str) const {
		size_t i, j = 0u;
		size_t end = str.length();

		for (i = 0u; i < end && str[i] == ' '; i++) {}		
		for (j = end - 1; j > 0 && str[j] == ' '; j--) {}	
		j++;

		str.erase(j, end);
		str.erase(0, i);
		
		return str;
	}
	Car(std::istream &istr){
		std::string str;
		
		std::getline(istr, str, ",");
		m_tag = trim(str);
		
	}
	
}