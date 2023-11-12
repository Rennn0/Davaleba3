#ifndef _TRADING_CENTER_
#define _TRADING_CENTRAL_
#include"includes.h"
#include"business_subject.h"
#include"order.h"

/*
	აერთიანებს შეკვეთებს და ბიზნეს ერთეულებს :
		შეკვეთები ინახება პრიორიტეტულობის მიხედვით,როგორც პირობა ითხოვს.
		ბიზნეს ერთეულების შენახვას არანაირი იდეური მნიშნელობა არ ქონდა ამიტომ
		რიგითობის მიხედვით ეწყობიან, ასევე თავ-თავიანთ შეკვეთებს 'იტოვებენ' _
		m_o_dll ახდენს შეკვეთების წაშლას თუმცა BusinessSubject თავის თავში იტოვებს
		შეკვეთებს რაც ერთგვარი არქივის როლში გამოდის (შეკვეთების სიად ინახება)
*/
class TradingCentral {
	size_t m_registeredBusinesses; // რამდენი შეკვეთა დაგროვდა
	std::vector<BusinessSubject>m_bs_v; // განსხვავებული ბიზნეს ობიექტები (set გამოყენება შეიძლებოდა)
	DoublyLinkedList<Order>m_o_dll; // შეკვეთები
	int exists(std::string& busName); // ამოწმებს ბიზნესი არსებობს თუ არა ვექტორში
public:
	TradingCentral() :m_bs_v({}), m_o_dll({}), m_registeredBusinesses(0) {}

	//ამატებს შეკვეთას მფლობელი ბიზნესი და პროდუქტების აიდების 
	void placeOrder(std::string busName, std::initializer_list<int>productIds);
	Order processOrder(); //სიის თავში არსებულ შეკვეთას იღებს
	void printOrders()const; //ყველა შეკვეთას ბეჭდავს
	void printBusinesses()const; //ინდივიდუალური ბიზნესების შეკვეთებს ბეჭდავს
};

#endif // !_TRADING_CENTER_
