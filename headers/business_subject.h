#ifndef _BUSINESS_SUBJECT_
#define _BUSINESS_SUBJECT_
#include"includes.h"
#include"order.h"
#include"doubly_linked_list.h"
class BusinessSubject {
	std::string m_businessName;
	float m_rating;
	float randomRating()const;
	DoublyLinkedList<Order>dll;
public:
	BusinessSubject(std::string& bn) :m_businessName(bn), m_rating(this->randomRating()), dll({}) {}

	bool addOrder(Order& order);

	float getRating()const;
	std::string getBusinessName()const;
};

#endif // !_BUSINESS_SUBJECT_
