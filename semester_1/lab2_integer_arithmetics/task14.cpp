#include <iostream>

int power(int h, int n){ // Ступені
    int q = 1;
    for(int j = 1; j <= h; j++){
            q *= n;
    }
    return q;
}

int paradak(int n){ // Вызначаем колькасьць лічбаў у ліку
    int j;
    for(int i = 9; i >= 0; i -= 1){
        if(n % power(i - 1, 10) != n){
            j = i;
            break;
        }
    }
    return j;    
} 

bool praverka(int number){ // Правяраем, ці з'яўляецца лік лікам Армстронга
    int suma = 0;
    int roznasc = 0;
    int bufer = number;
    for(int i = paradak(number); i >= 0; i--){
        suma += power(paradak(bufer), number / power(i - 1, 10));
        number -= (number / power(i - 1, 10))*power(i - 1, 10);
    }
    if(suma == bufer){
        return true;
    } else return false;
}

int main(){
    int a, b;
    if(!(std::cin >> a >> b)){
        std::cout << "Only integers, please";
        std::exit(1);
    }

    while((a <= 0)||(b <= 0)){
	    std::cout << "Integers must be positive. Write down new a and b: ";
	    std::exit(1);
	}

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
