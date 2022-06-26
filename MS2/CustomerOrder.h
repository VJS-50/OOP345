#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include "Utilities.h"
namespace sdds{
	struct Item{
	std::string m_itemName;
	size_t m_serialNumber{0};
	bool m_isFilled{false};

	Item(const std::string& src) : m_itemName(src) {};
};
class CustomerOrder{
		CustomerOrder();
		CustomerOrder(const std::string& str){
			Utilities util;
			size_t nextPos = 0;
			bool more = false;
			if(!str){
				m_name = 0;
				m_product = 0;
				m_cntItem = 0;
				m_lstItem = 0;
			}else {
				m_name = util.extractToken(str, nextPos, more)
				m_product = util.extractToken(str, nextPos, more)
				m_cntItem = util.extractToken(str, nextPos, more)
				m_lstItem = util.extractToken(str, nextPos, more)
			}
			
			std::string items = record.substr(nextPos, str.length() - nextPos);
			m_cntItem = count(items.begin(), items.end(), util.GetDelimitor() + 1);
			m_lstItem = new Item*[m_cntItem];
			
			for(size_t i = 0; i < m_cntItem && more;; i++){
				m_lstItem[i] = new Item(util.extractToken() )
				if (m_fieldWidth < util.getWidth()){
					m_fieldWidth < util.getWidth();
				}
			}
			
		};
		CustomerOrder(CustomerOrder& c){
			throw 
		}
		CustomerOrder(CustomerOrder&& c)noexcept {
			this = std::move(c);
		}
		CustomerOrder& operator=(CustomerOrder&& c){
			for(size_t i = 0; i < c.m_cntItem; i++){
				//copy each object in lstItem
				//delete c.m_lstItem[i];
			}
		}

		~CustomerOrder(){}
		bool CustomerOrder::isFilled() const{
			bool status = true;
			for(size_t i = 0; i < m_cntItem; i++){
				if(!m_lstItem[i]->m_isFilled){
					status = false
				}
			}
			
			return status;
		}
		bool CustomerOrder::isItemFilled(string itemName){
			for(size_t i = 0; i < m_cntItem; i++){
				if(!m_lstItem[i]->m_itemName == itemName){
					return m_lstItem[i]->m_isFilled;
				}else{
					return true;
				}
			}
			
		}
		
		void fillItem(Station& station, std::ostream& ostr){
			ostr <<this->m_name << station thing
			for(size_t i = 0; i < m_cntItem; i++){
				if(!m_lstItem[i]->m)itemName == station.getItemName()){
					if(station.getQuantity() > 0){
						m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
						m_lstItem[i]->isFilled = true;
						updateQuantity();
						ostr << name, product, itemname
					}
				}else{
					ostr << Unable to fill name, product, itemname	
					}
			}
		}
		void display(std::ostream& ostr) const{
			
		}
	};
}

#endif