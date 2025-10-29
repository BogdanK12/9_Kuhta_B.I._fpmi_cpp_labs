#include <iostream>

void inputString(std::string& stringInput){
  std::cout << "Write down your string: ";
  std::getline(std::cin, stringInput);
}

std::string sumOfStrings(std::string string1, std::string string2){
  std::string string3;
  int i = 0;
  int j = 0;
  int k = 0;
  while(i < string1.length() + string2.length()){
    while((string1[j] != ' ') && (j < string1.length() + 1)){
      string3 += string1[j];
      ++i;
      ++j;
    }
    if((i < string1.length() + string2.length()) && (j < string1.length())){
      string3 += ' ';
      ++j;
    }
    ++i;
    while((string2[k] != ' ') && (k < string2.length())){
      string3 += string2[k];
      ++i;
      ++k;
    }
    if((i < string1.length() + string2.length()) && (k < string2.length() + 1)){
      string3 += ' ';
      ++k;
    }
  }
  return string3;
}

int main(){
  std::string string1, string2;
  inputString(string1);
  inputString(string2);
  std::string string3 = sumOfStrings(string1, string2);
  std::cout << string3;
  return 0;
}
