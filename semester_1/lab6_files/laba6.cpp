#include <fstream>
#include <iostream>

void input_file(std::string file_name){
  std::fstream in1;
  in1.open(file_name);

  if(!in1){
    throw "There is now such file.";
  }
}

int word_index_search(std::string word, std::string file_name){
  input_file(file_name);
  int index;
  while(in1){
    char now;
    in1 >> now;
    if(now == word[0]){
      for(int i = 0; i < word.length(); ++i)
      {
        if(now != word[i]){}
      }
    }
  }
  return 6;
}

int main() {
  std::string file_name;
  std::cin >> file_name;
  try
  {
    input_file(file_name);
  } catch(std::string error_message) {
    std::cout << error_message;
  }
  return 0;
}
