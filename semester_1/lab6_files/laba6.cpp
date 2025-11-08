#include <fstream>
#include <iostream>

int wordSearchIndex(std::fstream &text, std::string word, bool &existn)
{
  int index = 0;
  existn = false;
  char c;
  while(text.get(c)){
    if(c == word[0]){ 
      int pos = text.tellp();
      int coincidence = 1;
      int i = 1;
      while((text.get(c)) && (i < word.length() - 1)){
        if(c == word[i]){
          ++coincidence;
        }
        ++i;
      }
      if(coincidence == word.length() - 1){
        existn = true;
        index = pos;
        return index;
      }
    }
    ++index;
  }
  return index;
}

void replace_word(std::fstream &text, std::string word1, std::string word2)
{
  if(word1.length() == word2.length())
  {
    for(int i = 0; i < word1.length(); ++i)
    {
      
    }
  }
  if(word1.length() > word2.length())
  {
    
  }
  if(word1.length() < word2.length())
  {
    
  }
}

int main() {
  std::fstream in1("prison.txt");
  if(!in1.is_open())
  {
    std::cout << "There is some problem with your file. ";
    std::exit(1);
  }
  bool existence;
  std::cout << "This is result: " << wordSearchIndex(in1, "africans", existence);
  return 0;
}
