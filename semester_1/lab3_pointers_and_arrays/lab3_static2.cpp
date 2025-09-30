#include <iostream>

int main(){
    const int nmax = 1000;
    int arrNum[nmax];
    
    std::cout << "Write number of elements of your array: ";
    int n;

    if(!(std::cin >> n)){
        std::cout << "Write down only positive integers";
        std::exit(1);
    }

    std::cout << "Write down all elements of your array: ";

    for(int i = 0; i <= (n - 1); ++i){
        if(!(std::cin >> arrNum[i])){
            std::cout << "Write down only positive numbers.";
        std::exit(2);
        }
    }

    int maxElement = 0;
    int indexMaxElement = 0;

    for(int i = 0; i <= (n - 1); ++i){
        if(abs(arrNum[i]) > maxElement){
            maxElement = arrNum[i];
            indexMaxElement = i;
        }
    }

    int product = 1;

    for(int i = (indexMaxElement + 1); i <= (n - 1); ++i){
        product *= arrNum[i];
    }

    if(indexMaxElement == (n - 1)){
        product = 0;
    }

    std::cout << "Product of numbers that come after the biggest is: " << product;

    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}