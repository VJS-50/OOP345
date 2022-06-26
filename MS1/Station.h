#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_
namespace sdds{
	class Station{
		static size_t m_widthField = 0;
		static size_t id_generator = 0;
		
		Station(const string& str){
			Utilities util;
			nextPos = 0;
			bool more = false;
			
			m_id =++Station::id_generator;
			
			if(str.empty){}
			else {
				
				m_itemName = Util.extractToken();
				m_serial
			}
		}
	}
}