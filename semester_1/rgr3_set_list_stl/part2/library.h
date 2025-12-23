#pragma once

#include <cstddef>
#include <list>
#include <random>
#include <string>
#include <vector>

class author
{
private:
  std::string last_name_;
  std::string name_;
  std::string fathers_name_; 

public:
  author() = delete;
  author(const std::string& last_name, const std::string& name, const std::string& fathers_name);
  author(const author& rhs);

  ~author() = default;
    
  std::string get_last_name() const;
  std::string get_name() const;
  std::string get_fathers_name() const;

  bool operator== (const author& rhs) const;
  bool operator!= (const author& rhs) const;
};  
class book
  {
  private:
    size_t idk_;
    std::list<author> authors_list_;
    std::string title_;
    int publication_year_;

  public:
    book(size_t idk, std::list<author>& authors, const std::string& title, int publication_year);

    ~book()=default;

    size_t get_idk() const;
    std::string get_title() const;
    std::list<author>& get_authors_list();
    std::list<author> get_authors_list() const;
    int get_publication_year() const;
    
    void add_author(const author& add);
    void delete_author(const author& del);
    bool operator== (const book& rhs) const;
    bool operator!= (const book& rhs) const;
};
  
class library
{
  std::list<book> books_list_;

public:
  library() = default;
  library(const std::list<book>& list_of_books);
  library(const library& rhs);

  ~library()=default;

  std::list<book>& get_books_list(); 
  std::list<book> get_books_list() const;

  void add_book(const book& rhs);
  void delete_book(const book& rhs);
  book& search_book(const std::string& rhs);
  const book& search_book(const std::string& rhs) const;
  std::list<book> search_authors_books(const author& rhs) const;
  void delete_book_by_author(const book& rhs);
};

author author_gen(std::mt19937 &gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father);

book book_gen(std::mt19937& gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father, const std::vector<std::string>& titles);
library library_gen(std::mt19937 &gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father, const std::vector<std::string> titles);

std::vector<std::string> parse_words(const std::string& text, const std::string& delimeters);

std::vector<std::string> parse_text_lines(const std::string& file_name);

std::vector<std::string> parse_text_words(const std::string& file_name, const std::string& delimeters);

void print_authors(const std::list<author>& aut, std::ostream& out);

void print_book(const book& rhs, std::ostream& out);

void print_library(const library& rhs, std::ostream& out);
