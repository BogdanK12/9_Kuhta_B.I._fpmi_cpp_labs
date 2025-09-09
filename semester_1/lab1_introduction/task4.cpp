#include <iostream>

int main(){
    int k;
    int i;
    std::cin >> k;
    int result = 1;
    if(k % 2 == 0){
        for(i = 2; i <= k; i += 2){
            result *= i;
        }
    }
    else{
        for(i = 1; i <= k; i += 2){
            result *= i;
        }
    }
    std::cout << result << std::endl;
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}