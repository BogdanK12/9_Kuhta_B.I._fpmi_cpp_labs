#include <iostream>

int power(int h, int n){ // Ступені
    int q = 1;
    for(int j = 1; j <= h; j++){
            q *= n;
    }
    return q;
}

int power_finder(int n){ // Вызначаем колькасьць лічбаў у ліку
    int j = 0;
    while (n > 0)
    {
        n /= 10;
        j++;
    }
    return j;
}

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
