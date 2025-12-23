#include "library.h"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <list>
#include <ostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

author::author(const std::string& last_name, const std::string& name, const std::string& fathers_name)
: last_name_(last_name), name_(name), fathers_name_(fathers_name)
{}

author::author(const author& rhs)
: last_name_(rhs.last_name_), name_(rhs.name_), fathers_name_(rhs.fathers_name_){}

bool author::operator==(const author& rhs) const
{
  if(last_name_ == rhs.last_name_ && name_ == rhs.name_ && fathers_name_ == rhs.fathers_name_){ return true;}
  else {return false;}
}

bool author::operator!=(const author& rhs) const
{
  return !(*this == rhs);
}

std::string author::get_last_name() const
{
  return last_name_;
}

std::string author::get_name() const
{
  return name_;
}

std::string author::get_fathers_name() const
{
  return fathers_name_;
}

std::list<author>::iterator find_author(const std::list<author>& list, const std::list<author>::iterator& begin, const author& rhs)
{
  std::list<author>::iterator it = begin;
  while(it != list.end())
  {
    if(*it == rhs)
    {
      return it;
    }
  }
  return it;
}

void add_author_to_list(std::list<author>& list, const author& rhs)
{
  if(find_author(list, list.begin(), rhs) != list.end()){return;}
  std::list<author>::iterator it = list.begin();
  while(it != list.end() && rhs.get_last_name() > it->get_last_name())
  {
    ++it;
  }
  list.insert(it, rhs);
}

book::book(size_t idk, std::list<author>& authors, const std::string& title, int publication_year)
: idk_(idk), authors_list_(authors), title_(title), publication_year_(publication_year)
{}

// book& parse_from_file(const std::string& input)
// {
//   std::istringstream in(input);
//   std::size_t idk;
  
// }

std::string book::get_title() const
{
  return this->title_;
}

size_t book::get_idk() const
{
  return this->idk_;
}

int book::get_publication_year() const
{
  return this->publication_year_;
}

void book::add_author(const author& rhs)
{
  if(find_author(authors_list_, authors_list_.begin(), rhs) != authors_list_.end()){ return;}
  add_author_to_list(authors_list_, rhs);  
}

void book::delete_author(const author& rhs)
{
  authors_list_.erase(find_author(authors_list_, authors_list_.begin(), rhs));
}

std::list<author>& book::get_authors_list()
{
  return authors_list_;
}

std::list<author> book::get_authors_list() const
{
  return authors_list_;
}

bool book::operator== (const book& rhs) const
{
  return(idk_ == rhs.idk_ && title_ == rhs.title_ && publication_year_ == rhs.publication_year_
         && std::equal(authors_list_.begin(), authors_list_.end(), rhs.authors_list_.begin()));    
}

bool book::operator != (const book& rhs) const
{
  return !(*this == rhs);
}

std::list<book>::iterator find_book(const std::list<book>& list, const std::list<book>::iterator& begin, const book& book1)
{
  std::list<book>::iterator it = begin;
  while(it != list.end())
  {
    if(*it == book1)
    {
      return it;
    }
  }
  return it;
}

void add_book_to_list(std::list<book>& list, const book& book1)
{
  if(find_book(list, list.begin(), book1) != list.end()){return;}
  std::list<book>::iterator it = list.begin();
  while(it != list.end() && book1.get_title() > it->get_title())
  {
    ++it;
  }
  list.insert(it, book1);
}

library::library(const std::list<book>& list_of_books)
{
  books_list_ = list_of_books;
}

library::library(const library& rhs)
{
  std::copy(rhs.books_list_.begin(), rhs.books_list_.end(), this->books_list_.begin());
}

std::list<book>& library::get_books_list()
{
  return this->books_list_;
}

std::list<book> library::get_books_list() const
{
  return this->books_list_;
}

void library::add_book(const book& rhs)
{
  add_book_to_list(books_list_, rhs);  
}

void library::delete_book(const book& rhs)
{
  std::list<book>::iterator it = books_list_.begin();
  while (it != books_list_.end())
  {
    if(*it == rhs)
    {
      it = books_list_.erase(it);
    } else
    {
      ++it;
    }
  }
}

book& library::search_book(const std::string& rhs) 
{
  std::list<book>::iterator it = books_list_.begin();
  while(it != books_list_.end())
  {
    if(it->get_title() == rhs)
    {
      return *it;
    }
    ++it;
  }
  throw std::runtime_error("There is no such book. ");
}

const book& library::search_book(const std::string& rhs) const 
{
  std::list<book>::const_iterator it = books_list_.begin();
  while(it != books_list_.end())
  {
    if(it->get_title() == rhs)
    {
      return *it;
    }
    ++it;
  }
  throw std::runtime_error("There is no such book. ");
}

std::list<book> library::search_authors_books(const author& rhs) const
{
  std::list<book> retval;
  std::list<book>::const_iterator it = books_list_.begin();
  while(it != books_list_.end())
  {
    if(find_author(it->get_authors_list(), it->get_authors_list().begin(), rhs) != it->get_authors_list().end())
    {
      add_book_to_list(retval, *it);  
    }
    ++it;
  }
  return retval;
}

void check_file(const std::string& file_name)
{
  std::ifstream in(file_name);
  if(!in.is_open())
  {
    throw std::runtime_error("Your file cannot be opened: " + file_name);
  }
  if(in.peek() == std::ifstream::traits_type::eof())
  {
    throw std::runtime_error("This file is empty: " + file_name);
  }
}

std::vector<std::string> parse_words(const std::string& text, const std::string& delimeters)
{
  std::vector<std::string> retval;
  size_t pos1, pos2;
  pos1 = text.find_first_not_of(delimeters);
  while(pos1 != std::string::npos)
  {
    pos2 = text.find_first_of(delimeters, pos1);
    retval.push_back(text.substr(pos1, pos2 - pos1));
    if(pos2 == std::string::npos){ break;}
    pos1 = text.find_first_not_of(delimeters, pos2);
  }
  return retval;
}

author author_gen(std::mt19937 &gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father)
{
  std::uniform_int_distribution<size_t> last_name_gen(0, author_last_name.size() - 1);
  std::uniform_int_distribution<size_t> name_gen(0, author_name.size() - 1);
  std::uniform_int_distribution<size_t> father_gen(0, author_father.size() - 1);
  return author(author_father.at(last_name_gen(gen)), author_name.at(name_gen(gen)), author_father.at(father_gen(gen)));
}

book book_gen(std::mt19937& gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father, const std::vector<std::string>& titles)
{
  if(author_last_name.empty() || author_name.empty() || author_father.empty() || titles.empty()){ throw std::runtime_error("Generator error: no names/last names/father's names. ");}
  std::uniform_int_distribution<size_t> authors_count_gen(1, 6);
  std::uniform_int_distribution<size_t> title_gen(0, titles.size() - 1);
  std::uniform_int_distribution<size_t> idk_gen(0, -1);
  std::uniform_int_distribution<int> year_gen(-2000, 2025);
  std::list<author> authors;
  size_t count = authors_count_gen(gen);
  for(size_t i{0}; i < count; ++i)
  {
    add_author_to_list(authors, author_gen(gen, author_last_name, author_name, author_father));
  }
  return book(idk_gen(gen), authors, titles.at(title_gen(gen)), year_gen(gen));
}

std::list<book> generate_books_list(std::mt19937& gen, const std::vector<std::string>& author_last_name,
                  const std::vector<std::string>& author_name,const std::vector<std::string>& author_father,
                  const std::vector<std::string>& titles)
{
  std::list<book> books_list;
  std::uniform_int_distribution<size_t> list_size_gen(1, 20);
  size_t list_size = list_size_gen(gen);
  for(size_t i{}; i < list_size; ++i)
  {
    add_book_to_list(books_list, book_gen(gen, author_last_name, author_name, author_father, titles));
  }
  return books_list;
}

library library_gen(std::mt19937 &gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father, const std::vector<std::string> titles)
{
  return library(generate_books_list(gen, author_last_name, author_name, author_father, titles)); 
}

void print_authors(const std::list<author>& aut, std::ostream& out)
{
  for(const author& autt: aut)
  {
    out << autt.get_last_name() << " ";
    out << autt.get_name() << " ";
    out << autt.get_fathers_name() << ". ";
  }
}

void print_book(const book& rhs, std::ostream& out)
{
  out << rhs.get_idk() << " ";
  out << rhs.get_title() << " ";
  print_authors(rhs.get_authors_list(), out);
  out << rhs.get_publication_year() << ". ";
}

void print_library(const library& rhs, std::ostream& out)
{
  for(const book& book_in : rhs.get_books_list())
  {
    print_book(book_in, out);
    out << '\n';
  }
}

std::vector<std::string> parse_text_lines(const std::string& file_name)
{
  check_file(file_name);
  std::vector<std::string> lines;
  std::ifstream in(file_name);
  std::string line;
  while(getline(in, line))
  {
    lines.push_back(line);
  }
  return lines;
}

std::vector<std::string> parse_text_words(const std::string& file_name, const std::string& delimeters)
{
  check_file(file_name);
  std::vector<std::string> lines;
  std::ifstream in(file_name);
  std::string line;
  while(getline(in, line))
  {
    std::vector<std::string> words = parse_words(line, delimeters);
    for(size_t i{0}; i < words.size(); ++i)
    {
      lines.push_back(words.at(i));
    }
  }
  return lines;
}
