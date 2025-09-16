#include <iostream>

int main(){
    int n, sum;
    if((!(std::cin >> n))){
        std::cout << "We need integers.";
        std::exit(1);
    }
    while(n <= 0){
	    std::cout << "n must be positive. Write new N: " << std::endl;
	    std::cin >> n;
    }
    sum = 0;
    for(int i = 1; i <= n; i += 2){
	    sum += i;
    }
    std::cout << "sum is: " << sum;
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
