#ifndef _BUSINESS_SUBJECT_
#define _BUSINESS_SUBJECT_
#include"includes.h"
#include"order.h"
#include"doubly_linked_list.h"
class BusinessSubject {
	float m_rating;
	DoublyLinkedList<Order>dll;
	float randomRating();
public:
	BusinessSubject() :m_rating(0), dll({}) {
		try
		{

		}
		catch (const std::exception&e)
		{
			std::cerr << e.what();
		}

	}
};

#endif // !_BUSINESS_SUBJECT_
