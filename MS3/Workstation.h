#ifndef SDDS_WORKSTATION_H_
#define SDDS_WORKSTATION_H_
#include "CustomerOrder.h"
#include "Station.h"
namespace sdds{
	extern deque<CustomerOrder> pending;
	extern deque<CustomerOrder> completed;
	extern deque<CustomerOrder> incomplete;
	class Workstation:public Station {
		deque<CustomerOrder> pending;
		deque<CustomerOrder> completed;
		deque<CustomerOrder> incomplete;
		
		deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation;
	public:
	
		Workstation(const std::string& str):Station(str){}
		void fill(std::ostream& ostr){
			CustomerOrder& currentOrder = m_orders.front() 
			if(currentOrder.empty()){
				return;
			}else{
				currentOrder.front().fillItem(*this,os)
			}
			
		}
		bool attemptToMoveOrder(){
			if(currentOrder .empty()){
				return false;
			}
			CustomerOrder& order = m_orders.front();
			
			if(order.isItemFilled(this->getItemname() || this->getQuantity()==0)){
				if(m_pNextStation){
					*m_pNextStation += std::move(order)
				}else if(order.isFilled()){
					completed.push_back(std::move(order))
				}else{
					incomplete.push_back(move(order))
				}
				
				m_orders.pop_front();
				return true;
			}
		}
		void setNextStation(Workstation* station){
			m_pNextStation = station;
		}
		Workstation* getNextStation{
			return &m_pNextStation;
		}
		void display(std::ostream& ostr){
			
		}
		Workstation& operator+=(CustomerOrder&& newOrder){
			m_orders.push_back(std::move(newOrder));
			return *this;
		}
	};
}
#endif