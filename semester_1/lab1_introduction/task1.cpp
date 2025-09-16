#include <iostream>

int main(){
    int a, b, d;
	std::cout << "Enter a, b, d:";
	if(!(std::cin >> a >> b >> d)){
        std::cout << "Write only integers";
        std::exit(1);
    }

	if(a > b){
		int n = a;
		a = b;
		b = n;
	}

	for(int i = a; i <= b; i += d){
		if(i % 3 == 0){
			std::cout << i << " ";
		}
	}
	std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
