#include <iostream>

int main(){
    int m, n, i;
    if(!(std::cin >> m >> n)){
        std::cout << "Write only integers";
        std::exit(1);
    }
    while((n <= 0)||(m <= 0)){
	    std::cout << "Both m and n must be natural. Write new m and n:" << std::endl;
	    std::cin >> m >> n;
    }
    std::cout << "Ih ahulnyja dzielniki:" << std::endl;
    for(i = 1; (i <= m)&&(i <= n); i++){
        if((m % i == 0)&&(n % i == 0)){
            std::cout << i << " ";
        }
    }
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
