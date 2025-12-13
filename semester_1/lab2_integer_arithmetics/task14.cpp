#include <iostream>

int power(int h, int n){ // Ступені
    int q = 1;
    for(int j = 1; j <= h; j++)
    {
            q *= n;
    }
    return q;
}

<<<<<<< HEAD
int power_finder(int n){ // Вызначаем колькасьць лічбаў у ліку
    int j = 0;
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

bool is_armstrong(int number){ // Правяраем, ці з'яўляецца лік лікам Армстронга
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
