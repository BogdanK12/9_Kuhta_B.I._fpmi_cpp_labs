#include "task14.h"

// Ступені
int power(int h, int n){
    int q = 1;
    for(int j = 1; j <= h; j++){
            q *= n;
    }
    return q;
}

// Вызначаем колькасьць лічбаў у ліку
int power_finder(int n){     int j = 0;
    while (n > 0)
    {
        n /= 10;
        j++;
    }
    return j;
}

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
