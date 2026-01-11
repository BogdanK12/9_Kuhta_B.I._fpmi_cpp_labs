#include "marks.h"
#include <iostream>
#include <cstddef>
#include <exception>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

Mark generate_mark(std::mt19937& gen ,const std::string& subject)
{
  if(subject.empty()){ throw std::runtime_error("There are no subjects");}
  // std::uniform_int_distribution<size_t> subj(0, subjects.size(x) - 1);
  std::uniform_int_distribution<size_t> mark(1, 10);
  return Mark(subject, mark(gen));
}

std::vector<Mark> generate_marks(std::mt19937& gen, const std::vector<std::string>& subjects)
{
  std::vector<Mark> retval;
  std::uniform_int_distribution<short int> mark_existence(0, 1);
  for(const std::string& str: subjects)
  {
    short int existence = mark_existence(gen);
    if(existence)
    {
      retval.push_back(generate_mark(gen, str));
    }
  }
  return retval;
}

std::string generate_name(std::mt19937& gen, const std::vector<std::string>& last_names, const std::vector<std::string>& initials)
{
  if(last_names.empty()){ throw std::runtime_error("There are no last names.");}
  if(initials.empty()){ throw std::runtime_error("There are no initials");}
  std::uniform_int_distribution<size_t> last_gen(0, last_names.size() - 1);
  std::uniform_int_distribution<size_t> init_gen(0, initials.size() - 1);
  return last_names[last_gen(gen)] + initials[init_gen(gen)];
}

// TODO how to generate random amount of unique marks
StudentData generate_student(std::mt19937& gen, const std::vector<std::string>& subjects, const std::vector<std::string>& names)
{
  if (subjects.empty()) {throw std::runtime_error("There are no subjects");}
  if (names.empty()) { throw std::runtime_error("There are no names.");}
  std::uniform_int_distribution<size_t> names_gen(0, names.size() - 1);
  std::uniform_int_distribution<size_t> id_gen(10000, 99999);
  return StudentData(names[names_gen(gen)], id_gen(gen), generate_marks(gen, subjects));
}

int main(int argc, char* argv[])
{
  int value{std::stoi(argv[0])};
  try{
  if(value < 0){throw std::runtime_error("Negative parameter.");}
  } catch(std::exception& err)
  {
    std::cerr << err.what();
  }

  const std::string initials_file{"initials.txt"};
  const std::string last_names_file{"last_names.txt"};
  const std::string subjects_file{"subjects.txt"};

  std::random_device rd;
  std::mt19937 gen(rd());

  try{

  std::vector<std::string> initials{parse_words_from_string(parse_file(initials_file))};
  std::vector<std::string> last_names{parse_words_from_string(parse_file(last_names_file))};
  std::vector<std::string> subjects{parse_words_from_string(parse_file(subjects_file))};

  } catch (std::exception& error)
  {
    std::cerr << error.what();
  }
}
