#include <iostream>

int wordSearchIndex(std::string text, std::string word){
  int index = text.length() + 1;
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
        ++k;
      }
  } else{
      diff = word2.length() - word1.length();
      for(int i = (index + word2.length()); i < (text.length() - diff); ++i){
        text[i] = text[i + abs(diff)];
      }
      for(int i = index; i < (index + word2.length()); ++i){
        text[i] = word2[k];
        ++k;
      }
      for(int i = (text.length() - abs(diff)); i < text.length(); ++i){
        text[i] = ' ';
      }
  }
}

int main(){
  std::string word1, word2, textInput;
  std::cout << "Input your words: ";
  std::cin >> word1 >> word2;
  std::cout << std::endl << "Ok. " << std::endl;
  std::getline(std::cin, textInput);
  if((word1.length() > textInput.length()) || (word2.length() > textInput.length())){
    std::cout << "Word must be longer than text!";
    std::exit(52);
  }
  int diff;
  int index1 = wordSearchIndex(textInput, word1);
  int index2 = wordSearchIndex(textInput, word2);
  std::cout << std::endl;
  replaceWords(textInput, word1, word2, index1, diff);
  replaceWords(textInput, word2, word1, index2 + diff, diff);
  std::cout << "New text is: " << textInput;
  return 0;
}
