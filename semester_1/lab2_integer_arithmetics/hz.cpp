#include <iostream> 

int main(){
    int n;
    std::cin >> n;
    std::cout << n;
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}