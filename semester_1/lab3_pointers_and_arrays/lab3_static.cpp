#include <iostream>

int main(){
    const int nmax = 10;
    int change = 0;
    int n;
    std::cout << "Write down number of elements of array(max is 10): ";
    if(!(std::cin >> n)){
        std::cout << "Only positive integers.";
        std::exit(1);
    }
    if((n > nmax)||(n <= 0)){
        std::exit(1);
    }
    int a[n];
    std::cout << "Write down all elements of array: ";
    for(int i = 0; i <= (n - 1); i++){
        std::cin >> a[i];
    }

    for(int i = 1; i <= (n - 1); i++){
        if((a[i]/abs(a[i])) != (a[i - 1]/abs(a[i - 1]))){
            change += 1;
        }
    }

    std::cout << "Numbers change sign " << change << " times."; //eshkere

    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
