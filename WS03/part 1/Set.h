//Workshop 3: Templates
// set.h  – file name
// Vincent Yu – author
// 112708193  – author id
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
#include <string>
namespace sdds{
	template<size_t N, typename T>
	class Set {
		T data[N]{};
		size_t count{0u};

	public:
		size_t size() const;
		const T& get(size_t idx) const;
		void operator+=(const T& item);

	};

	template<size_t N, typename T>
	size_t Set<N,T>::size()const {
		return count;
	}

	template<size_t N, typename T>
	const T& Set<N, T>::get(size_t idx) const{
	
		return data[idx];
	}

	template<size_t N, typename T>
	void Set<N, T>::operator+=(const T& item) {

		if (count < N)
		{			
			data[count] = item;
			count++;
		}
	}
}
#endif // !SDDS_SET_H_