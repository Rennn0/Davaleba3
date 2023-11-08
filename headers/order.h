#ifndef _ORDER_
#define _ORDER_
#include"includes.h"
class Order {
	size_t m_basketSize;
	int m_productIds[PRODUCTS_BASKET_MAX];
	long long m_oderId;
	long long orderId(long long min= RATING_ID_MIN,long long max=RATING_ID_MAX);
public:
	Order(std::initializer_list<int>productIds) {
		this->m_oderId = this->orderId();
		size_t n = productIds.size();
		auto it = productIds.begin();
		for (size_t t = 0; t < n && t < PRODUCTS_BASKET_MAX; t++) {
			this->m_productIds[t] = *(it+t);
		}
		if (n > PRODUCTS_BASKET_MAX) {
			this->m_basketSize = PRODUCTS_BASKET_MAX;
			std::cerr << "\nWarning _ last " << n - PRODUCTS_BASKET_MAX  << " product won't be included!\n";
		}
		else {
			this->m_basketSize = n;
		}
	};
	auto getBasketSize()const;
	auto getOrderId()const;
	std::vector<int> getProducts()const;
	void print();
};

#endif // !_ORDER_
