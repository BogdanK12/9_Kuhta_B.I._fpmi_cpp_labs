#include <iostream>

int main(){
    int nmax = 1000;
    int arr[nmax];
    int n;
    int number;
    int P;
    std::cout << "Write down P: ";
    
    if(!(std::cin >> P)){
        std::cout << "Write down only integers.";
        std::exit(2);
    }

    if((!(std::cin >> n))||(n < 0)){
        std::cout << "Write down only positive numbers. ";
        std::exit(1);
    }

    std::cout << "Write down all elements of array: ";
    for(int i = 0; i <= (n - 1); ++i){
        if(!(std::cin >> arr[i])){
            std::cout << "Write down only positive numbers.";
        std::exit(2);
        }
    }

    for(int i = 0; i <= (n - 1); ++i){
        if(arr[i] >= P){
            ++number;
        }
    }

    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0; 
}