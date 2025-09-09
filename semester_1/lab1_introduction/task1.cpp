#include <iostream>

int main() {
	int i;
	int a;
	int b;
	int d;
	int sum;
	sum = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> d;
	while (i = a; i <= b; i + d) {
		if (i % 3 == 0) {
			sum = sum + i;
			};
	};
	std::cout << sum << std::endl;
	return 0;
}