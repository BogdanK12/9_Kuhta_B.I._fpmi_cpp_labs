#include <iostream>

int main() {
    int n;
    int i;
    int sum = 0;
    std::cin >> n;
    for(i = 1; i <= n; i++){
        sum = sum + i*i;
    }
    std::cout << sum << std::endl; 
    std::cin.clear(); 
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}