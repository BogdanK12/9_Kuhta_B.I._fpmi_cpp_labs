#include <iostream>

int main(){
    int i, n, m, z;
    std::cin >> n;
    std::cin >> m;
    z = 2;
    i = 1;
    std::cout << "Ваш каляндар: " << std::endl;
    std::cout << "1 |";
    while(i <= (m + (n - 1))){
        while(i < n){
            std::cout << "   ";
            i++;
        }
        if((i + 1 - n) < 10){
            std::cout << " ";
        }
        std::cout << " " << (i + 1 - n);
        if(i % 7 == 0){
            std::cout << std::endl;
            std::cout << z << " |";
            z++;
        }
        i++;
    }
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}