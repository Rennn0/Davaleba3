#include"../headers/order.h"

long long Order::orderId(long long min, long long max)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<long long>dist(min, max);
	return dist(rng);
}

Order::Order(std::initializer_list<int> productIds, float rating)
	:m_orderRating(rating) {
	this->m_oderId = this->orderId();
	size_t n = productIds.size();
	auto it = productIds.begin();
	for (size_t t = 0; t < n && t < PRODUCTS_BASKET_MAX; t++) {
		this->m_productIds[t] = *(it + t);
	}
	if (n > PRODUCTS_BASKET_MAX) {
		this->m_basketSize = PRODUCTS_BASKET_MAX;
		std::cerr << "\nWarning _ last " << n - PRODUCTS_BASKET_MAX << " product won't be included!\n";
	}
	else {
		this->m_basketSize = n;
	}
};

auto Order::getBasketSize() const
{
	return this->m_basketSize;
}

auto Order::getOrderId() const
{
	return this->m_oderId;
}

float Order::getOrderRating() const
{
	return this->m_orderRating;
}

std::vector<int> Order::getProducts() const
{
	std::vector<int>copy{};
	for (size_t t = 0; t < this->m_basketSize; t++) {
		copy.push_back(this->m_productIds[t]);
	}
	return copy;
}

void Order::print()
{
	std::string spacer(15, '#');
	std::cout << '\n' + spacer << "\norder" << this->m_oderId << "\n";
	for (size_t t = 0; t < this->m_basketSize; t++) {
		std::cout << std::setw(spacer.length()) << std::right << this->m_productIds[t] << '\n';
	}
	std::cout << "Rating " << this->m_orderRating << '\n' << spacer + '\n';
}
