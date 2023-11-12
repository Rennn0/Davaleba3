#ifndef _BUSINESS_SUBJECT_
#define _BUSINESS_SUBJECT_
#include"includes.h"
#include"order.h"
#include"doubly_linked_list.h"

/*
	შეკვეთის განმთავსებელი, მფლობელი
	მივეცი თავისი სახელი და რეიტინგი, შექმნისთანავე ინიჭებს შემთხვევით მნიშვნელობას
	შემდეგ ყოველი პროდუქტის განთავსებისას იცვლება
*/

class BusinessSubject {
	std::string m_businessName; // სახელი 
	float m_rating; //რეიტინგი
	float randomRating()const; // შემთხვევითი რიცხვი [0:1]
	DoublyLinkedList<Order>dll; // შეკვეთების არქივი
public:
	BusinessSubject(std::string& bn) :m_businessName(bn), m_rating(this->randomRating()), dll({}) {}

	bool addOrder(Order& order);//შეკვეთის დამატება

	float getRating()const; //რეიტინგისთვის
	std::string getBusinessName()const;//სახელისთვის

	void printOrders()const;
};

#endif // !_BUSINESS_SUBJECT_
