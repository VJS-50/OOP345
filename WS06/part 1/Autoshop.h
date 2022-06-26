#include "Vehicle.h"
#include <string>
namespace sdds{
	class Autoshop{
		vector<Vehicle*> m_vehicles;
		
		template<typename T>
		void select(T condition, list<const Vehicle*>& vehicles){
			for(size_t i = m_vehicles.begin(); i != m_vehicles.end(); i++){
				vehicles.push_back();
			}
		}
		
		Autoshop& operator+=(Vehicle* aVehicle){
			m_vehicles.push_back(aVehicle);
			return *this;
		}
		
		void display(std::ostream& ostr) const{
			
			for(;;){
				
			}
			
			(*i)->display(ostr);
		}
	};
	
}