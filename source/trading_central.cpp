#include"../headers/trading_central.h"

int TradingCentral::exists(std::string& busName)
{
	int index = -1;
	for (int i = 0; i < this->m_bs_v.size(); i++) {
		if (this->m_bs_v[i].getBusinessName() == busName) {
			index = i;
			return index;
		}
	}
	return index;
}

void TradingCentral::placeOrder(std::string busName, std::initializer_list<int> productIds)
{
	int i = this->exists(busName);
	if (i != -1) {
		Order newOrder(productIds, this->m_bs_v[i].getRating());
		this->m_o_dll.insert(newOrder);
		this->m_bs_v[i].addOrder(newOrder);
	}
	else {
		this->m_bs_v.push_back({ busName });
		Order newOrder(productIds, this->m_bs_v.back().getRating());
		this->m_o_dll.insert(newOrder);
		this->m_bs_v.back().addOrder(newOrder);
	}
}

Order TradingCentral::processOrder()
{
	return this->m_o_dll.remove();
}

void TradingCentral::print()const
{
	this->m_o_dll.printOrders();
	std::cout << "\n\n\n\n\n\n\n\n\n";
	//for (const auto& bs : this->m_bs_v) {
	//	bs.printOrders();
	//}
}
