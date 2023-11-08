#ifndef _D_L_L_
#define _D_L_L_
#include"order.h"
template<typename T>
class DoublyLinkedList {
	template<typename Y>
	struct Node {
		Y data;
		Node<Y>* next;
		Node<Y>* previous;
		Node(Y d, Node* n, Node* p) :data(d), next(n), previous(p) {}
		Node() : next(nullptr), previous(nullptr) {}
	};
	Node<T>* head;
	Node<T>* tail;
	uint32_t size;
public:
	DoublyLinkedList() :head(nullptr), tail(nullptr),size(0) {}
	~DoublyLinkedList();
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();

	bool insert(size_t index, T data);
	bool insert(Order& order);
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
	this->size++;
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
	this->size++;
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
	this->size--;
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
	this->size--;
	delete temp;
}
template<typename T>
inline bool DoublyLinkedList<T>::insert(size_t index, T data)
{
	if (index<0 || index>this->size) {
		throw std::out_of_range(std::to_string(index) + " Index Out Of Range ");
		return false;
	}
	if (index == 0) {
		this->push_front(data);
		return true;
	}
	if (index == this->size) {
		this->push_back(data);
		return true;
	}
	Node<T>* temp = head;
	for (size_t t = 0; t < index; t++) {
		temp = temp->next;
	}
	Node<T>* newNode = new Node<T>(data, temp, temp->previous);
	temp->previous->next = newNode;
	temp->previous = newNode;
	this->size++;
	return true;
}
template<typename T>
inline bool DoublyLinkedList<T>::insert(Order& order)
{

	return true;
}
template<typename T>
inline void DoublyLinkedList<T>::print()
{
	Node<T>* tracer = head;
	while (tracer != nullptr) {
		std::cout << "\nMisamarti " << tracer << " | Mnishvneloba " << tracer->data;
		tracer = tracer->next;
	}
	std::cout << "\nSize " << this->size;
}
#endif // !_D_L_L_	

