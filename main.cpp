#include"headers/assemble.h"

int main() {
	Order a({ 12, 44, 0, 43, 123,12, 44, 0, 43, 123,12, 44, 0, 43, 123,12, 44, 0, 43, 123 });
	a.print();
	
	for (const int& v : a.getProducts())
		std::cout << v << '\n';

	std::cout << ((a.getProducts()).size());
}
