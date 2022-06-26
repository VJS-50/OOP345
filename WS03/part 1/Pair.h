//Workshop 3: Templates
// pair.h  – file name
// Vincent Yu – author
// 112708193  – author id
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include <iostream>
#include <string>
namespace sdds{
	template<typename V, typename K>
	class Pair{
	protected:
		V m_val;
		K m_key;

	public:
		Pair();
		Pair(const K& key, const V& value);
		const V& value() const;
		const K& key() const;
		void display(std::ostream& os) const;

	};
	
	template<typename V, typename K>
	Pair<V, K>::Pair() {}

	template<typename V, typename K>
	Pair<V, K>::Pair(const K& key, const V& value) {

		m_key = key;
		m_val = value;
	}

	template<typename V, typename K>
	const V& Pair<V, K>::value() const {
		return m_val;
	}

	template<typename V, typename K>
	const K& Pair<V, K>::key() const {
		return m_key;
	}

	template<typename V, typename K>
	void Pair<V, K>::display(std::ostream& os) const {
		os << m_key << " : " << m_val << std::endl;
	}

	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);

		return os;
	}
}
#endif // !SDDS_PAIR_H_