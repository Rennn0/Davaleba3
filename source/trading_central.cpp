#include"../headers/trading_central.h"

int TradingCentral::exists(std::string& busName)
{
	for (int i = 0; i < this->m_bs_v.size(); i++) {
		if (this->m_bs_v[i].getBusinessName() == busName) {
			return i;
		}
	}
	return -1;
}

void TradingCentral::placeOrder(std::string busName, std::initializer_list<int> productIds)
{
	int i = this->exists(busName);
	if (i != -1) {
		Order newOrder(productIds, this->m_bs_v[i].getRating());
		this->m_o_dll.insert(newOrder);
		this->m_bs_v[i].addOrder(newOrder);
		std::cout << "\n\tNew order " << newOrder.getOrderId() << "; rating " << newOrder.getOrderRating() << std::endl;
	}
	else {
		this->m_bs_v.push_back({ busName });
		Order newOrder(productIds, this->m_bs_v.back().getRating());
		this->m_o_dll.insert(newOrder);
		this->m_bs_v.back().addOrder(newOrder);
		std::cout << "\n\tNew order " << newOrder.getOrderId() << "; rating " << newOrder.getOrderRating() << std::endl;
	}
}

Order TradingCentral::processOrder()
{
	Order removedOrder=this->m_o_dll.remove();
	std::cout << "\nCompleted order-" << removedOrder.getOrderId()<<std::endl;
	return removedOrder;
}

void TradingCentral::printOrders()const
{
	this->m_o_dll.printOrders();
	std::cout << "\n\n";
	//for (const auto& bs : this->m_bs_v) {
	//	bs.printOrders();
	//}
}

void TradingCentral::printBusinesses() const
{
	for (const auto& bus : this->m_bs_v) {
		bus.printOrders();
	}
	std::cout << "\n\n";
}
