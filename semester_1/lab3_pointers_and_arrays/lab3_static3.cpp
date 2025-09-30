#include <iostream>

int main(){
	const int nmax = 10000;
	std::cout << "Write down numer of elements in your array: ";
	int arrNum[nmax];
	int n;

	if(!(std::cin >> n)||(n <= 0)){
		std::cout << "Only positive integers";
		std::exit(1);
	}

	for(int i = 0; i < n; ++i){
		std::cin >> arrNum[i];
	}
	
	int negativeCounter = 0;
	for(int i = 0; i < n; ++i){
		if(arrNum[i] < 0){
			int temp = i;
			int tempVar = arrNum[i];
			for(int i = temp; i >= negativeCounter; --i){
				arrNum[i] = arrNum[i - 1];
			}
			++negativeCounter;
			arrNum[negativeCounter] = tempVar;
		}
	}

	for(int i = 0; i < n; ++i){
		std::cout << arrNum[i] << " ";
	}
	
	std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
	return 0;
}
