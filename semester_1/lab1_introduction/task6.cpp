#include <iostream>

int main(){
    int i, n, sum;
    std::cin >> n;
    sum = 0;
    for(i = 1; i <= n; i++){
        if(i % 2 == 1){
            sum = sum + i;
        }
    }
    std::cout << sum;
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}