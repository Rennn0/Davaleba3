#include "../headers/business_subject.h"

float BusinessSubject::randomRating()const
{
	return ((float)rand() / (RAND_MAX));
}

bool BusinessSubject::addOrder(Order& order)
{
	this->m_rating = this->randomRating();
	return this->dll.insert(order);
}

float BusinessSubject::getRating() const
{
	return this->m_rating;
}

std::string BusinessSubject::getBusinessName() const
{
	return this->m_businessName;
}

void BusinessSubject::printOrders() const
{
	this->dll.printOrders();
}
