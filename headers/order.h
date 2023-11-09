#ifndef _ORDER_
#define _ORDER_
#include"includes.h"
class Order {
	size_t m_basketSize;
	int m_productIds[PRODUCTS_BASKET_MAX];
	float m_orderRating;
	long long m_oderId;
	long long orderId(long long min = RATING_ID_MIN, long long max = RATING_ID_MAX);
public:
	Order(std::initializer_list<int>productIds, float rating);

	auto getBasketSize()const;
	auto getOrderId()const;
	float getOrderRating()const;
	std::vector<int> getProducts()const;
	void print();
};

#endif // !_ORDER_
