#include <fstream>
#include <iostream>

int main() {
  std::fstream in1("input.txt");
  int index;
  while(in1){
    char now;
    in1 >> now;
    std::cout << now;
    }
  return 0;
}
