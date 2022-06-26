//Workshop 3: Templates
// PairSummable.h  – file name
// Vincent Yu – author
// 112708193  – author id
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PAIRSUMABLE_H_
#define SDDS_PAIRSUMABLE_H_
#include <iostream>
#include <iomanip>
#include <string>
#include <type_traits>
#include "Pair.h"
namespace sdds {
	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		inline static V initial;
		inline static size_t m_width;
	public:
		PairSummable();
		PairSummable(const K& key, const V& value = initial);
		bool isCompatibleWith(const PairSummable<V, K>& b) const;
		void display(std::ostream& os) const;
		PairSummable& operator+=(const PairSummable& b);

	};
	template<typename V, typename K>
	PairSummable<V, K>::PairSummable(){
	}

	template<typename V, typename K>
	PairSummable<V, K>::PairSummable(const K& key, const V& value) : Pair<V,K>(key, value) {
		initial = ;
		m_width = ;
	}
	template<typename V, typename K>
	bool PairSummable<V, K>::isCompatibleWith(const PairSummable<V, K>& b) const {
		bool isEqual;
		if (Pair<V, K>::m_key == b.m_key)
		{
			isEqual = true;
		}
		else isEqual = false;

		return isEqual;
	}
	template<typename V, typename K>
	void PairSummable<V, K>::display(std::ostream& os) const {

		os << std::setw(m_width) << std::left <<  Pair<V,K>::display(os) << std::right;
	}

	template<typename V, typename K>
	PairSummable<V, K>& PairSummable<V, K>::operator+=(const PairSummable<V, K>& b) {
		Pair<V,K>::m_val = Pair<V,K>::value() + b.value();

		return *this;
	}

	template<> //String Specialization
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& b) {
		Pair::m_val = Pair::m_val + ", " + b.value();

		return *this;
	}
}
#endif // !SDDS_PAIRSUMABLE_H_