#include <iostream>

int main(){
    int m, n, i;
    std::cin >> m;
    std::cin >> n;
    std::cout << "Ih ahulnyja dzielniki:" << std::endl;
    for(i = 1; (i <= m)&&(i <= n); i++){
        if((m % i == 0)&&(n % i == 0)){
            std::cout << i << std::endl;
        }
    }
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}