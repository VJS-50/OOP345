// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		Product* p;
		for( desc)
			for( price)
				if(desc_code == price_code)
					p = new Product(desc[i].desc, price[i].price[j]);
					p->validate();
					priceList += p;
					
					

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for( desc)
			for( price)
				if(desc_code == price_code)
					unique_ptr<Product> p(new Product(desc[i].desc, price[i].price[j]));
					p->validate();
					priceList += p;

		return priceList;
	}
}