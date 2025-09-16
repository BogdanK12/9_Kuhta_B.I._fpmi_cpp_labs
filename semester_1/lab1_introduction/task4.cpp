#include <iostream>

int main(){
    int k;
    if(!(std::cin >> k)){
        std::cout << "Write only integers";
        std::exit(1);
    }
    while(k <= 0){
	    std::cout << "Integer must be positive. Write new integer:" << std::endl;
	    std::cin >> k;
    }
    int result = 1;
    if(k % 2 == 0){
        for(int i = 2; i <= k; i += 2){
            result *= i;
        }
    }
    else{
        for(int i = 1; i <= k; i += 2){
            result *= i;
        }
    }
    std::cout << result << std::endl;
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
