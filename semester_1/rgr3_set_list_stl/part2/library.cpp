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
#include <iostream>

author::author(const std::string& last_name, const std::string& name, const std::string& fathers_name)
: last_name_(last_name), name_(name), fathers_name_(fathers_name)
{
  if(last_name.empty() || name.empty() || fathers_name.empty())
  {
    throw std::runtime_error("Missing parameters for adding an author.");
  }
}

bool author::operator==(const author& rhs) const
{
  return (last_name_ == rhs.last_name_ && name_ == rhs.name_ && fathers_name_ == rhs.fathers_name_);
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

std::list<author>::iterator book::find_author(std::list<author>::iterator begin, const author& rhs)
{
  std::list<author>::iterator it = begin;
  while(it != authors_list_.end())
  {
    if(*it == rhs)
    {
      return it;
    }
    ++it;
  }
  return it;
}

std::list<author>::const_iterator book::find_author(std::list<author>::const_iterator begin, const author& rhs) const
{
  std::list<author>::const_iterator it = begin;
  while(it != authors_list_.end())
  {
    if(*it == rhs)
    {
      return it;
    }
    ++it;
  }
  return it;
}

void add_author_to_list(std::list<author>& list, const author& rhs)
{
  if(std::find(list.begin(), list.end(), rhs) != list.end()){return;}
  std::list<author>::iterator it = list.begin();
  while(it != list.end() && rhs.get_last_name() > it->get_last_name())
  {
    ++it;
  }
  list.insert(it, rhs);
}

book::book(size_t idk, const std::list<author>& authors, const std::string& title, size_t publication_year)
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

size_t book::get_publication_year() const
{
  return this->publication_year_;
}

void book::add_author(const author& rhs)
{
  if(this->find_author(authors_list_.begin(), rhs) != authors_list_.end()){ return;}
  add_author_to_list(authors_list_, rhs);
}

void book::delete_author(const author& rhs)
{
  std::list<author>::iterator it = this->find_author(authors_list_.begin(), rhs);
  if(it != authors_list_.end() && this->authors_list_.size() > 1)
  {
    authors_list_.erase(it);
  } else
  {
    std::cerr << "Tried to acess non-existent author.";
  }
}

std::list<author>& book::get_authors_list()
{
  return authors_list_;
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

const std::list<author>& book::get_authors_list() const
{
  return authors_list_;
}

void book::print(std::ostream& out) const
{
  out << idk_ << " ";
  out << "\"" << title_ << "\" ";
  print_authors(authors_list_, out);
  out << " " << publication_year_ << ".";
}

bool book::operator== (const book& rhs) const
{
  return(idk_ == rhs.idk_ && title_ == rhs.title_ && publication_year_ == rhs.publication_year_
         && authors_list_.size() == rhs.authors_list_.size() && std::equal(authors_list_.begin(), authors_list_.end(), rhs.authors_list_.begin()));
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
    ++it;
  }
  return it;
}

void add_book_to_list(std::list<book>& list, const book& book1)
{
  if(find_book(list, list.begin(), book1) != list.end())
  {
    return;
  }
  std::list<book>::iterator it = list.begin();
  while(it != list.end() && book1.get_title() > it->get_title())
  {
    ++it;
  }
  list.insert(it, book1);
}

std::list<book> library::search_by_title(const std::string& title) const
{
  std::list<book> retval;
  for(const book& b: books_list_)
  {
    if(b.get_title() == title)
    {
      add_book_to_list(retval, b);
    }
  }
  return retval;
}

library::library(const std::list<book>& list_of_books)
{
  books_list_ = list_of_books;
}

std::list<book>& library::get_books_list()
{
  return this->books_list_;
}

library::library(const library& rhs)
: books_list_(rhs.books_list_)
{}

const std::list<book>& library::get_books_list() const
{
  return this->books_list_;
}

void library::add_book(const book& rhs)
{
  add_book_to_list(books_list_, rhs);
}

std::list<book>::iterator library::search_book(const book& rhs)
{
  return std::find_if(books_list_.begin(), books_list_.end(), [&rhs](const book& a){ return rhs == a;});
}

void library::delete_book(const book& rhs)
{
  if(this->search_book(rhs) != books_list_.end())
  {
    books_list_.erase(this->search_book(rhs));
  }
}

std::list<book>::iterator library::search_book(const std::string& rhs, std::list<book>::iterator begin)
{
  // std::list<book>::iterator it = begin;
  // while(it != books_list_.end())
  // {
  //   if(it->get_title() == rhs)
  //   {
  //     return it;
  //   }
  //   ++it;
  // }
  // return it;
  return std::find_if(begin, books_list_.end(), [&rhs](const book& a){ return rhs == a.get_title();});
}

std::list<book>::const_iterator library::search_book(const std::string& rhs, std::list<book>::const_iterator begin)
{
  // std::list<book>::const_iterator it = begin;
  // while(it != books_list_.end())
  // {
  //   if(it->get_title() == rhs)
  //   {
  //     return it;
  //   }
  //   ++it;
  // }
  // return it;
  return std::find_if(begin, books_list_.cend(), [&rhs](const book& a){ return rhs == a.get_title();});
}




// std::list<author>::iterator book::find_author(std::list<author>::iterator& begin, const author& rhs)
// {

//   std::list<author>::iterator it = begin;
//   while(it != authors_list_.end())
//   {
//     if(*it == rhs)
//     {
//       return it;
//     }
//   }
//   return it;
// }

std::list<book> library::search_authors_books(const author& rhs) const
{
  std::list<book> retval;
  std::list<book>::const_iterator it = books_list_.begin();
  while(it != books_list_.end())
  {
    if(it->find_author(it->get_authors_list().begin(), rhs) != it->get_authors_list().end())
    {
      add_book_to_list(retval, *it);
    }
    ++it;
  }
  return retval;
}

void library::add_author_to_book(const std::list<book>::iterator it, const author& aut)
{
  it->add_author(aut);
}

void library::delete_author_from_book(const std::list<book>::iterator it, const author& aut)
{
  it->delete_author(aut); 
}

// void library::delete_book_by_author(const author& rhs)
// {
//   std::list<book>::const_iterator it = books_list_.begin();
//   while(it != books_list_.end())
//   {
//     if(find_author(it->get_authors_list(), it->get_authors_list().begin(), rhs) != it->get_authors_list().end())
//     {
//       add_book_to_list(retval, *it);
//     }
//     ++it;
//   }
//   return
// }

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
  size_t pos1 = text.find_first_not_of(delimeters);
  size_t pos2;
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
  return author(author_last_name.at(last_name_gen(gen)), author_name.at(name_gen(gen)), author_father.at(father_gen(gen)));
}

book book_gen(std::mt19937& gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father, const std::vector<std::string>& titles)
{
  if(author_last_name.empty() || author_name.empty() || author_father.empty() || titles.empty()){ throw std::runtime_error("Generator error: no names/last names/father's names. ");}
  std::uniform_int_distribution<size_t> authors_count_gen(1, 6);
  std::uniform_int_distribution<size_t> title_gen(0, titles.size() - 1);
  std::uniform_int_distribution<size_t> idk_gen(0, 100000);
  std::uniform_int_distribution<size_t> year_gen(1450, 2025);
  std::list<author> authors;
  size_t count = authors_count_gen(gen);
  for(size_t i{0}; i < count; ++i)
  {
    add_author_to_list(authors, author_gen(gen, author_last_name, author_name, author_father));
  }
  return book(idk_gen(gen), authors, titles.at(title_gen(gen)), year_gen(gen));
}

std::list<book> generate_books_list(size_t max_count, std::mt19937& gen, const std::vector<std::string>& author_last_name,
                  const std::vector<std::string>& author_name,const std::vector<std::string>& author_father,
                  const std::vector<std::string>& titles)
{
  std::list<book> books_list;
  for(size_t i{}; i < max_count; ++i)
  {
    add_book_to_list(books_list, book_gen(gen, author_last_name, author_name, author_father, titles));
  }
  return books_list;
}

library library_gen(size_t max_count,std::mt19937 &gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father, const std::vector<std::string> titles)
{
  return library(generate_books_list(max_count, gen, author_last_name, author_name, author_father, titles));
}

void library::print(std::ostream& out) const
{
  for(const book& book_in : books_list_)
  {
    book_in.print(out);
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
  in.close();
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

std::list<author> convert_string_to_authors_list(const std::string& string_authors, const std::string& delimiters)
{
  std::list<author> retval;
  std::vector<std::string> words = parse_words(string_authors, delimiters);
  if(words.size() % 3 != 0){ throw std::runtime_error("Not enough names.");}
  for(size_t i{0}; i < words.size(); i += 3)
  {
    add_author_to_list(retval, author(words.at(i), words.at(i + 1), words.at(i + 2)));
  }
  return retval;
}
