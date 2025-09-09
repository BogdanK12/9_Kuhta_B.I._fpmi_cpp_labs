#include <iostream>

int main() {
    int i;
    int n;
    std::cin >> n;
    int sum = 0;
    int zda = 1;
    for(i = 1; i <= n; i++){
        if(i % 2 == 1){
            zda = zda * i;
        }
        if(i % 2 == 0){ 
            sum = sum + i;
        }
    } 
    std::cout << sum << std::endl;
    std::cout <<zda << std::endl;
     std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}