#include"headers/assemble.h"

int main() {
	srand((unsigned int)time(NULL));
	TradingCentral tc;
	tc.placeOrder("Pepsi", { 1 });
	tc.placeOrder("Cola", { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 });// (19) gafrtxileba bolos 3_ze
	tc.placeOrder("Pepsi", { 2 });
	tc.placeOrder("Cola", { 3 });
	tc.placeOrder("Sprite", { 4 });
	tc.printOrders();
	tc.printBusinesses();
	tc.processOrder();
	tc.processOrder();
	tc.placeOrder("Pepsi", { 5 });
	tc.printOrders();
}
