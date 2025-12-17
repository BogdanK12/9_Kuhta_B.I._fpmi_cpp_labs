#include <fstream>
#include <iostream>

int wordSearchIndex(std::string text, std::string word, bool &existn){
  int index;
  existn = false;
  for(int i = 0; i <= (text.length() - word.length()); ++i){
    if(text[i] == word[0]){ // znachodzim pierszy sypadajuchy symbal
      int coincidence = 1;
      for(int j = 1; j < word.length(); ++j){
        if(text[i + j] == word[j]){
          coincidence += 1;
        }
      }
      if(coincidence == word.length()){
        index = i;
        existn = true;
        break;
      }
    }
  }
  std::cout << "index: " << index << std::endl;
  return index;
}

void replaceWords(std::string& text, std::string word1, std::string word2, int index, int& diff){
  int k = 0;
  if(word1.length() == word2.length()){
    for(int i = index; i < (index + word1.length()); ++i){
      text[i] = word2[k];
      std::cout << text;
      ++k;
    }
  } else if(word1.length() <= word2.length()){
      diff = word2.length() - word1.length();
      for(int i = 0; i < diff; i++){
        text += ' ';
      }
      for(int i = (text.length() + diff); i >= index + word2.length(); --i){
        text[i] = text[i - diff];
      }
      for(int i = index; i < (index + word2.length()); ++i){
        text[i] = word2[k];
        std::cout << text;
        ++k;
      }
  } else{
      diff = word2.length() - word1.length();
      for(int i = (index + word2.length()); i < (text.length() - diff); ++i){
        text[i] = text[i + abs(diff)];
      }
      for(int i = index; i < (index + word2.length()); ++i){
        text[i] = word2[k];
        std::cout << text;
        ++k;
      }
      for(int i = (text.length() - abs(diff)); i < text.length(); ++i){
        text[i] = ' ';
      }
  }
}

int main(){
  std::ofstream outf("output.txt");
  std::ifstream fin("input.txt");
  if(!outf)
  {
    std::cout << "There is some bug.";
    std::exit(1);
  }
  std::string word1, word2;
  fin >> word1;
  fin >> word2; 
  std::string textInput;
  char c;
  while(fin.get(c))
  {
    textInput += c;
  }
  if((word1.length() > textInput.length()) || (word2.length() > textInput.length())){
    std::cout << "Word must be longer than text!";
    std::exit(52);
  }
  int diff;
  bool exist1, exist2;
  int index1 = wordSearchIndex(textInput, word1, exist1);
  int index2 = wordSearchIndex(textInput, word2, exist2);
  std::cout << std::endl;
  if(exist1){
      replaceWords(textInput, word1, word2, index1, diff);
  }
  if(exist2){
      replaceWords(textInput, word2, word1, index2 + diff, diff);
  }
  outf << textInput;
  return 0;
}
