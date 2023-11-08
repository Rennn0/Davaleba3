#ifndef _BUSINESS_SUBJECT_
#define _BUSINESS_SUBJECT_

#include"includes.h"
class BusinessSubject {
	float m_rating;
	DoublyLinkedList<int>dll;
public:
	BusinessSubject() {
		dll.push_back(1);
		dll.push_back(2);
		dll.push_back(3);
		dll.push_front(5);
		dll.pop_back();
	}
	void print() {
		dll.print();
	}
};

#endif // !_BUSINESS_SUBJECT_
