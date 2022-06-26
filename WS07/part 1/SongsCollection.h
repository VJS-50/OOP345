#ifndef SDDS_SONGSCOLLECTION_H_
#define SDDS_SONGSCOLLECTION_H_
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
namespace sdds{
	struct Song{
		m_artist
		m_title
		m_album
		m_price
		m_year
		m_length
	};
	class SongCollection{
		vector<Song> m_collection;
	public:
		SongCollection(string filename){
			ifstream file
			
			if(!file) throw
			
			while(file){
				Song song;
				string str;
				
				
				
				
				this->m_collection.push_back(song);
			}
		}
		void display(std::ostream& ostr) const{
			for_each(begin,end, [&out](const Song& song){out << song});
			
		};
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
		void sort(string field){
			if(field == "album"){
				sort(begin,end, [](const Song& a, const Song& b){return a.m_album < b.m_album;})
			}else if(field == "title"){
				sort(begin,end, [](const Song& a, const Song& b){return a.m_title < b.m_title;})
			}else if(field == "length"){
				sort(begin,end, [](const Song& a, const Song& b){return a.m_length < b.m_length;})
			}
		};
		void cleanAlbum(){
			transform(m_collection.begin(), m_collection.end(), m_collection.begin(), [](Song song){
				if(song.m_album == "[None]"){
					song.m_album = "";
					return song;
				}
			})
		};
		bool inCollection(string artist) const{
			auto res = find_if(begin, end, [&artist](const Song& song){
				return song.m_artist == artist;
			})
			
			return res;
		};
		std::list<Song> getSongsForArtist(string artist) const{
			auto count = count_if(begin, end, [&artist](const Song& song){return song.m_artist == artist;})
			list<Song> songs(count);
		
			copy_if(begin, end, songs.begin(), [&artist](const Song& song){return song.m_artist == artist;})
				
			return songs;
	}
		friend std::ostream operator<<(std::ostream& ostr, const Song& theSong);
	};
}
#endif