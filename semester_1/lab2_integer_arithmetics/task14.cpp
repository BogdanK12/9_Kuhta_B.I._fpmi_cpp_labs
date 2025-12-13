#include "task14.h"

// Ступені
int power(int h, int n){
    int q = 1;
    for(int j = 1; j <= h; j++)
    {
            q *= n;
    }
    return q;
}

<<<<<<< HEAD
// Вызначаем колькасьць лічбаў у ліку
int power_finder(int n){     int j = 0;
=======
<<<<<<< HEAD
int power_finder(int n){ // Вызначаем колькасьць лічбаў у ліку
    int j = 0;
>>>>>>> 8a682d93e67c67bc6d82aa7507cb192078ef329a
    while (n > 0)
    {
        n /= 10;
        j++;
    }
    return j;
}
=======
int paradak(int n){ // Вызначаем колькасьць лічбаў у ліку
    int pp = 0;
    while(n > 0)
    {
        n /= 10;
        ++pp;    
    }
    return pp;
} 
>>>>>>> 538098a (aaaaaaaaaaa)

// Правяраем, ці з'яўляецца лік лікам Армстронга
bool is_armstrong(int number){
    int suma = 0;
    int buffer = number;
    int power_of_number = power_finder(number);
    while(number > 0)
    {
        suma += power(power_of_number, number % 10);
        number /= 10;
    }
    return suma == buffer;
}
<<<<<<< HEAD
=======

int main(){
    int a, b;
    std::cout << "Write down 2 positive integers: ";
    if(!(std::cin >> a >> b)){
        std::cout << "Only integers, please";
        std::exit(1);
    }

    if(a > b){
        int temp;
        temp = a;
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
    return 0;
}
>>>>>>> 538098a (aaaaaaaaaaa)
