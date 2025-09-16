#include <iostream>

int main(){
    int i, n, m, z;
    std::cout << "Write down first day of month and amount of days in a month: ";
    if((!(std::cin >> n >> m))){
        std::cout << "We need integers.";
        std::exit(1);
    }
    while((n <= 0)||(m <= 0)||(n > 7)||(m > 99)){
        std::cout << "Integers must be positive. N must be under 8. N must be under 100. Write down new integers: ";
        std::cin >> n >> m;
    }
    z = 2;
    i = 1;
    std::cout << "Ваш каляндар: " << std::endl;
    std::cout << " 1 |";
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
            if(z <= 9){
                std::cout << " ";
            }
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
