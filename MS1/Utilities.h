#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
namespace sdds{
	
	class Utilities{
		size_t m_widthField = 1;
		
		void setFieldWidth(size_t newWidth){
			static m_delimiter;
			m_widthField = newWidth;
		}
		size_t getFieldWidth() const{return m_widthField}
		
		std::string extractToken(const std::string& str, size_t& nextPos, bool& more){
			string token;
			
			if(nextPos <= str.length()){
				size_t location = str.find_first_of(m_delimiter, nextPos);
				if(location != string::npos){
					token = substr(nextPos, location - nextPos);
					nextPos = location + 1;
				}else{
					token = substr(nextPos);
					nextPos = str.length() + 1;
				}
			}
			
			if(token.empty() && nextPos != str.length()+1 ){
				more = false
				throw str;
			}
			
			if(m_widthField < token.length()) {
				m_widthField = token.length();
				
				
				more = nextPos <= str.length();
			}
			
			return token;
		}
	};
}
#endif