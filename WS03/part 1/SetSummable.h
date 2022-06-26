//Workshop 3: Templates
// SetSummable.h  – file name
// Vincent Yu – author
// 112708193  – author id
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SETSUMMABLE_H_
#define SDDS_SETSUMMABLE_H_
#include "Set.h"
#include <string>
namespace sdds{

	template<size_t N, typename T>
	class SetSummable : public Set<N, T> {

	public:
		T accumulate(const std::string& filter) const;

	};

	template<size_t N, typename T>
	T SetSummable<N,T>::accumulate(const std::string& filter) const{
		T local(filter);

		for (size_t i = 0; i < Set<N,T>::size(); i++)
		{
			if (local.isCompatibleWith(this->get(i)) == true)
			{
				local += this->get(i);
			}
		}

		return local;
	}
}

#endif // !SDDS_SETSUMMABLE_H_
