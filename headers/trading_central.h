#ifndef _TRADING_CENTER_
#define _TRADING_CENTRAL_
#include"includes.h"
#include"business_subject.h"
#include"order.h"
class TradingCentral {
	size_t m_registeredBusinesses;
	std::vector<BusinessSubject>m_bs_v;
	DoublyLinkedList<Order>m_o_dll;
	int exists(std::string& busName);
public:
	TradingCentral() :m_bs_v({}), m_o_dll({}), m_registeredBusinesses(0) {}


	void placeOrder(std::string busName, std::initializer_list<int>productIds);
	void print()const;
};

#endif // !_TRADING_CENTER_
