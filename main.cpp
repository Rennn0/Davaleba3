#include"headers/assemble.h"

int main() {
	srand((unsigned int)time(NULL));
	TradingCentral tc;
	tc.placeOrder("Cola", { 1,2,3 });
	tc.placeOrder("Cola", { 4,5 });
	tc.placeOrder("Cola", { 6,7 });

	tc.placeOrder("pepsi", { 11,22,33 });
	tc.placeOrder("pepsi", { 14,25, 3 });
	tc.placeOrder("pepsi", { 16,27,3 });

	tc.print();
}
