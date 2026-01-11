#include "marks.h"
#include <fstream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstddef>
#include <vector>

Mark::Mark(const std::string& subject, size_t mark)
: subject_(subject), mark_(mark)
{
  if(subject.empty()){ throw std::runtime_error("There is no name of subject");}
}

void Mark::print(std::ostream& out) const
{
  out << subject_ << " ";
  out << mark_;
}

StudentData::StudentData(const std::string& name, size_t number, const std::vector<Mark>& marks)
: name_(name), number_(number), marks_(marks)
{}

void StudentData::print(std::ostream& out) const
{
  out << name_ << " ";
  out << number_ << " ";
  for(const Mark mark_n: marks_)
  {
    out << "\"";
    mark_n.print(out);
    out << "\"";   
  }
}

void check_file(const std::string &file_name)
{
  std::ifstream in(file_name);
  if(!in.is_open()){ throw std::runtime_error("There is problem with file: " + file_name);}
  if(in.peek() == std::ifstream::traits_type::eof()){ throw std::runtime_error(file_name + " is empty.");}
}

std::string parse_file(const std::string &file_name)
{
  check_file(file_name);
  std::ifstream in{file_name};
  std::stringstream istr;
  istr << in.rdbuf();
  in.close();
  return istr.str();
}

std::vector<std::string> parse_words_from_string(const std::string& str, const std::string& delimiters)
{
  if(str.empty()){ throw std::runtime_error("String is empty");}
  if(delimiters.empty()){ throw std::runtime_error("Delimiters are empty.");}
  std::vector<std::string> retval;
  size_t pos1 = str.find_first_not_of(delimiters);
  while(pos1 != std::string::npos)
  {
    size_t pos2 = str.find_first_of(delimiters, pos1);
    retval.push_back(str.substr(pos1, pos2 - pos1));
    pos1 = str.find_first_not_of(delimiters, pos2);
  }
  return retval;
}
