#include <iostream>

int main() {
    int n;
    if(!(std::cin >> n)){
        std::cout << "Write only integers";
        std::exit(1);
    }
    while(n <= 0){
	    std::cout << "Integer must be greater than 0" << std::endl;
	    std::cin >> n;
    }
    int sum = 0;
    int zda = 1;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 1){
            zda = zda * i;
        }
        if(i % 2 == 0){ 
            sum = sum + i;
        }
    } 
    std::cout << "The sum is: " << sum << std::endl;
    std::cout << "The product is: " << zda << std::endl;
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
