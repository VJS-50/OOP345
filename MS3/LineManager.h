#ifndef SDDS_LINEMANAGER_H_
#define SDDS_LINEMANAGER_H_
#include <string>
#include <vector>
#include "Workstation.h"
#include "Utilities.h"
namespace sdds{
	class LineManager{
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;
	public:
		LineManager(const std::string& file, std::vector<Workstation*>&stations){
			ifstream file(file)
				if(file.is_open()){
					throw
				}
			string record = "";
			string currentStn = "";
			string nextStn = ""
			size_t nextPos;
			bool more;
			Utilities util;
			
			for_each(stations.begin(), stations.end(), [](Workstation* s){s->setNextStation();});
			
			while(eof) {
				nextPos = 0;
				getline(file, record){
					currentStn = util.extractToken(record,nextPos,more);
					auto cStn = find_if(stations.begin(), stations.end(), [currentStn](const Workstation& ws){return ws->getItemName() == currentStn;});
					
					if(cStn == stations.end()){
						throw 
					}
					activeLine.push_back(*cStn);
					
					if(more){
						nextStn = util.extractToken(record,nextPos,more);
						auto nStn = find_if(stations.begin(), stations.end(), [currentStn](const Workstation& ws){return ws->getItemName() == nextStn;});
					
					if(nStn == stations.end()){
						throw 
					}
					
					if(nStn == cStn){
						throw
					}
					
					(*cStn)->setNextStation(*nextStn);
					}
				}
			}
			file.close();
					
			for_each(activeLine.begin(), end(), [this](Workstation* ws){
				auto found = find_if(activeLine.end(), [&ws](Workstation* s){return ws->getNextStation() == s});
					if(found == activeLine.end()){
						throw
					}else m_firstStation = ws;
				});
					
				if(!found){
					throw
				}
				m_cntCustomerOrder = pending.size();		
		}
			
		void linkStation(){
			vector<Workstation*> inOrder;
			auto iter = m_firstStation;
			
			while(iter){
				inOrder.push_back(iter);
				iter = iter->getNextStation();
				activeLine = inOrder;
			}
		}
		
		bool run(std::ostream& ostr){
			size_t count;
			
			ostr << <<++count<<
			if(!pending.empty()){
				*m_firstStation += move(pending.front());
				pending.pop_front();
			}
			for(auto& s : activeLine){
				ostr<< <<s->getItemName() << 
				s->fill(ostr);
			}
			for(auto& s : activeLine){
				s->attemptToMoveOrder();
			}
			
			return completed.size()+incomplete.size() == m_cntCustomerOrder;
		}
		void display(std::ostream& ostr)const {
			
		}
		
	};
}
#endif