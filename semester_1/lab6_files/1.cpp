#include <iostream>
#include <fstream>

int main () {
  std::fstream in1("prison.txt");
  char c;
  while(in1)
  {
    in1 >> c;
    std::cout << c;
  }
}
