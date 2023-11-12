#ifndef _ORDER_
#define _ORDER_
#include"includes.h"
/*
	შეკვეთა როგორც აბსტრაქული ტიპი
	გავაკეთე დაშვებები _
		შეკვეთას უნდა ქონდეთ თავისი უნიკალური აიდი და
		ასევე შეკვეთაში განთავსებულ პროდუქტებსაც აქვთ აიდი
		ოღონდ პროგრამა არ აგენერირებს, არამედ გადმოიცემა არგუმენტად გაშვების დროს
		მაგალითად ვაშლი=1, ბანანი=2, ნესვი=79, შეკვეთა იქნება { 1, 2, 79};
*/
class Order {
	size_t m_basketSize; //რამდენი პროდუქტია კალათაში
	int m_productIds[PRODUCTS_BASKET_MAX]; //პროდუქტების აიდებს ინახავს, მაქსიმუმ 16 დავუშვი
	float m_orderRating; //შეკვეთის რეიტინგი, პრიორიტეტულობისთვის
	long long m_oderId; //შეკვეთის აიდი
	//რანდომ გენერატორი 10თანრიგა რიცხვის
	long long orderId(long long min = RATING_ID_MIN, long long max = RATING_ID_MAX);
public:
	Order(std::initializer_list<int>productIds, float rating);

	//დამხარე ფუნქციები

	size_t getBasketSize()const; //პროდუქტების რაოდენობისთვის
	long long getOrderId()const; //შეკვეთის აიდისთვის
	float getOrderRating()const; //შეკვეთის რეიტინგისთვის
	std::vector<int> getProducts()const; //პროდუქტების აიდების
	void print();
};

#endif // !_ORDER_
