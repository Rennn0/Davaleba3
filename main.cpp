#include"headers/assemble.h"

int main() {
	srand((unsigned int)time(NULL));
	TradingCentral tc;
	tc.placeOrder("Pepsi", { 1 });
	tc.placeOrder("Cola", { 2 });
	tc.print();
	tc.processOrder();
	tc.print();
	tc.placeOrder("Cola", { 3 });
	tc.placeOrder("Pepsi", { 4 });
	tc.processOrder();
	tc.print();
}
