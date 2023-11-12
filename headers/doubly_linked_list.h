#ifndef _D_L_L_
#define _D_L_L_
#include"order.h"

/*
	ორმაგად ბმული სიის წარმოება შაბლონის დახმარებით
	შეიცავს როგორც დამახასიათებელ მეთდებს ისე 
	სპეციფიურს ამოცანის გადასაწყეტად, ასევე გამოუსადეგარსაც
*/
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
	DoublyLinkedList() :head(nullptr), tail(nullptr), size(0) {}
	DoublyLinkedList(const DoublyLinkedList<T>& other);
	~DoublyLinkedList();
	bool push_front(T data);
	bool push_back(T data);
	const T& pop_front();
	const T& pop_back();
	bool insert(size_t index, T data);
	bool insert(Order& order);

	T remove();
	T remove(size_t nThNode);

	void printOrders(const std::string& busName)const;
	void printOrders()const;
};

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
	:head(nullptr), tail(nullptr), size(0)
{
	Node<T>* current = other.head;
	while (current != nullptr) {
		this->push_back(current->data);
		current = current->next;
	}
}

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
inline bool DoublyLinkedList<T>::push_front(T data)
{
	Node<T>* newNode = new Node<T>(data, head, nullptr);

	if (head != nullptr) {
		head->previous = newNode;
	}
	head = newNode;
	if (tail == nullptr) {
		tail = newNode;
	}
	this->size++;
	return true;
}

template<typename T>
inline bool DoublyLinkedList<T>::push_back(T data)
{
	if (head == nullptr) {
		push_front(data);
		return true;
	}
	Node<T>* newNode = new Node<T>(data, nullptr, tail);
	tail->next = newNode;
	tail = newNode;
	this->size++;
	return true;
}

template<typename T>
inline const T& DoublyLinkedList<T>::pop_front()
{
	if (head == nullptr) {
		throw std::error_condition();
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
	T data = temp->data;
	delete temp;
	return data;
}

template<typename T>
inline const T& DoublyLinkedList<T>::pop_back()
{
	if (tail == nullptr) {
		throw std::error_condition();
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
	T data = temp->data;
	delete temp;
	return data;
}

template<typename T>
inline bool DoublyLinkedList<T>::insert(size_t index, T data)
{
	if (index<0 || index>this->size) {
		throw std::out_of_range(std::to_string(index) + " Index Out Of Range ");
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
	if (order.getOrderRating() < 0.75f) {
		this->push_back(order);
		return true;
	}
	Node<T>* tracer = this->head;
	while (tracer != nullptr && order.getOrderRating() <= tracer->data.getOrderRating()) {
		tracer = tracer->next;
	}

	if (tracer == nullptr) {
		this->push_back(order);
	}
	else if (tracer == this->head) {
		this->push_front(order);
	}
	else {
		Node<T>* newNode = new Node<T>(order, tracer, tracer->previous);
		tracer->previous->next = newNode;
		tracer->previous = newNode;
		this->size++;
	}

	return true;
}

template<typename T>
inline T DoublyLinkedList<T>::remove()
{
	if (this->head == nullptr) {
		throw std::out_of_range("Error condition 0");
	}
	Node<T>* temp = this->head;
	this->head = this->head->next;
	T data = temp->data;
	delete temp;
	this->size--;
	return data;
}

template<typename T>
inline T DoublyLinkedList<T>::remove(size_t nThNode)
{
	if (this->head == nullptr || this->size < nThNode || nThNode==0) {
		throw std::out_of_range("Error condition 3");
	}
	if (nThNode == 1) {
		return this->pop_front();
	}
	if (nThNode == this->size) {
		return this->pop_back();
	}
	Node<T>* target = this->head;
	for (size_t t = 0; t < nThNode -1 ; t++) {
		target = target->next;
	}
	target->previous->next = target->next;
	target->next->previous = target->previous;
	T& data = target->data;
	delete target;
	
	return data;
}

template<typename T>
inline void DoublyLinkedList<T>::printOrders(const std::string& busName)const
{
	Node<T>* tracer = head;
	while (tracer != nullptr) {
		std::cout << "\nOwner : " << busName;
		tracer->data.print();
		tracer = tracer->next;
	}
	std::cout << "\nSize " << this->size;
}
template<typename T>
inline void DoublyLinkedList<T>::printOrders()const
{
	Node<T>* tracer = head;
	while (tracer != nullptr) {
		tracer->data.print();
		tracer = tracer->next;
	}
	std::cout << "\nSize " << this->size;
}
#endif // !_D_L_L_	

