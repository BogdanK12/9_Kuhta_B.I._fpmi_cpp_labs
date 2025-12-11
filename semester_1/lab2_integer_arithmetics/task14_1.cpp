#include <iostream>
#include "task14.h"

int main(){
    int a, b;
    std::cout << "Write down 2 positive integers: ";
    if(!(std::cin >> a >> b)){
        std::cout << "Only integers, please";
        std::exit(1);
    }

    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }

    if((a <= 0)||(b <= 0)){
	    std::cout << "Integers must be positive.";
	    std::exit(1);
	}

    std::cout << "These are Armstrong's numbers between " << a << " and " << b << ":" << std::endl;

    for(int i = a; i <= b; i++){
        if(praverka(i)){
            std::cout << i << " ";
        }
    }

    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
