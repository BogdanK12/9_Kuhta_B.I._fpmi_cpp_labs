#include <iostream>

int main() {
    int n, i;
    int sum = 0;
    int d = 1;
    int z =1;
    if(!(std::cin >> n)){
        std::cout << "Write only integers";
        std::exit(1);
    }
    while(n <= 0){
	    std::cout << "Integer must be positive. Write new integer:" << std::endl;
    	    std::cin >> n;
    }
	for(i = 1; i <= n; i++){
        while(z <= i){
            d = d * i;
            z++;
        };
        z = 1;
        sum = sum + d;
        d = 1;
    }
    std::cout << "Vynik: " << std::endl;
    std::cout << sum << std::endl; // напэўна ў нас не хапае памяці, якую дае int
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
