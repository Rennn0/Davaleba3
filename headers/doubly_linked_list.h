#ifndef _D_L_L_
#define _D_L_L_
#include<iostream>
template<typename T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* previous;
	Node(T d, Node* n, Node* p) :data(d), next(n), previous(p) {}
	Node() :data(), next(nullptr), previous(nullptr) {}
};
template<typename T>
class DoublyLinkedList {
	Node<T>* head;
	Node<T>* tail;
	uint32_t allocations;
public:
	DoublyLinkedList() :head(nullptr), tail(nullptr),allocations(0) {}
	~DoublyLinkedList();
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	void print();
};

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* next = current->next;
		delete current;
		current = next;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::push_front(T data)
{
	Node<T>* newNode = new Node<T>(data,head,nullptr);
		
	if (head != nullptr) {
		head->previous = newNode;
	}
	head = newNode;
	if (tail == nullptr) {
		tail = newNode;
	}
	this->allocations++;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(T data)
{
	if (head == nullptr) {
		push_front(data);
		return;
	}
	Node<T>* newNode = new Node<T>(data,nullptr,tail);
	tail->next = newNode;
	tail = newNode;
	this->allocations++;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_front()
{
	if (head == nullptr) {
		return;
	}
	Node<T>* temp = head;
	head = head->next;
	if (head != nullptr) {
		head->previous = nullptr;
	}
	else {
		tail = nullptr;
	}
	this->allocations--;
	delete temp;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_back()
{
	if (tail == nullptr) {
		return;
	}
	Node<T>* temp = tail;
	tail = tail->previous;
	if (tail != nullptr) {
		tail->next = nullptr;
	}
	else {
		head = nullptr;
	}
	this->allocations--;
	delete temp;
}
template<typename T>
inline void DoublyLinkedList<T>::print()
{
	Node<T>* tracer = head;
	while (tracer != nullptr) {
		std::cout << "\nMisamarti " << tracer << " | Mnishvneloba " << tracer->data;
		tracer = tracer->next;
	}
	std::cout << "\nAllocations " << this->allocations;
}
#endif // !_D_L_L_
