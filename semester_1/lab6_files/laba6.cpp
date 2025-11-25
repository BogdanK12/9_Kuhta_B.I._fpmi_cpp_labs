#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>

// int wordSearchIndex(std::fstream &text, const std::string &word, bool
// &existn)
// {
//   int index = 0;
//   existn = false;
//   char c;
//   while(text.get(c)){
//     if(c == word[0]){
//       int pos = text.tellp();
//       int coincidence = 1;
//       int i = 1;
//       while((text.get(c)) && (i < word.length() - 1)){
//         if(c == word[i]){
//           ++coincidence;
//         }
//         ++i;
//       }
//       if(coincidence == word.length() - 1){
//         existn = true;
//         index = pos;
//         return index;
//       }
//     }
//     ++index;
//   }
//   return index;
// }

// long long search_word_index(std::string text,
//                             std::string word /*, bool &existn */) {
//   int index;
//   // existn = false;
//   for (int i = 0; i <= (text.length() - word.length()); ++i) {
//     if (text[i] == word[0]) {
//       int coincidence = 1;
//       for (int j = 1; j < word.length(); ++j) {
//         if (text[i + j] == word[j]) {
//           coincidence += 1;
//         } else {
//           coincidence = 0;
//           break;
//         }
//       }
//       if (coincidence == word.length()) {
//         index = i;
//         // existn = true;
//         return i;
//       }
//     }
//   }
//   return -1;
// }

// void replace_words(std::string &text, const std::string &word1,
//                    const std::string &word2, long long index) {
//   int k = 0;
//   int diff;
//   if (word1.length() == word2.length()) {
//     for (int i = index; i < (index + word1.length()); ++i) {
//       text[i] = word2[k];
//       std::cout << text;
//       ++k;
//     }
//   } else if (word1.length() <= word2.length()) {
//     long long text_length = text.length();
//     diff = word2.length() - word1.length();
//     for (int i = 0; i < diff; i++) {
//       text += ' ';
//     }
//     for (int i = (text_length + diff); i >= index + word2.length(); --i) {
//       text[i] = text[i - diff];
//     }
//     for (int i = index; i < (index + word2.length()); ++i) {
//       text[i] = word2[k];
//       std::cout << text;
//       ++k;
//     }
//   } else {
//     diff = word2.length() - word1.length();
//     for (int i = (index + word2.length()); i < (text.length() - diff); ++i) {
//       text[i] = text[i + abs(diff)];
//     }
//     for (int i = index; i < (index + word2.length()); ++i) {
//       text[i] = word2[k];
//       std::cout << text;
//       ++k;
//     }
//     for (int i = (text.length() - abs(diff)); i < text.length(); ++i) {
//       text[i] = ' ';
//     }
//   }
// }

// finds words index
long long find_word_index(const std::string &text, const std::string &word)
{
  return text.find(word);
}

void replace_words(std::string &text, const std::string &word1,
                   const std::string &word2, long long index) {
  text.replace(index, word1.length(), word2);
}

int main() {
  const std::string file_name = "input.txt";
  std::fstream in(file_name);
  if (!in.is_open()) {
    std::cout << "There is some problem with your file. ";
    std::exit(1);
  }
  std::string word1, word2;
  in >> word1 >> word2;
  std::string text;
  getline(in, text);
  in.close();
  std::cout << "----------------------------------------" << std::endl << text << std::endl << "----------------------------------------" << std::endl;
  long long index1 = find_word_index(text, word1);
  long long index2 = find_word_index(text, word2);
  std::cout << " " << word1 << " <-> " << word2 << std::endl;
  replace_words(text, word1, word2, index1);
  replace_words(text, word2, word1, index2 -(word1.length() - word2.length()));
  std::cout << "----------------------------------------" << std::endl << text << std::endl << "----------------------------------------";
  std::ofstream out("output.txt");
  out << text;
  out.close();
  return 0;
}
