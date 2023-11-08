#include"../headers/order.h"

long long Order::orderId(long long min, long long max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<long long>dist(min,max);
    return dist(rng);
}

auto Order::getBasketSize() const
{
    return this->m_basketSize;
}

auto Order::getOrderId() const
{
    return this->m_oderId;
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
    std::string spacer(15,'#');
    std::cout << spacer << "\norder" << this->m_oderId << "\n";
    for (size_t t = 0; t < this->m_basketSize; t ++ ) {
        std::cout <<std::setw(spacer.length())<<std::right<< this->m_productIds[t]<<'\n';
    }
    std::cout << spacer;
}
