#pragma once

#include <cstddef>
#include <list>
#include <ostream>
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
  author(const author& rhs) = default;

  author& operator=(const author& rhs) = default;

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
    size_t publication_year_;

  public:
    book(size_t idk, const std::list<author>& authors, const std::string& title, size_t publication_year);

    book& operator=(const book& rhs) = default;

    ~book()=default;

    size_t get_idk() const;
    std::string get_title() const;
    std::list<author>& get_authors_list();
    const std::list<author>& get_authors_list() const;
    size_t get_publication_year() const;
    
    void add_author(const author& add);
    void delete_author(const author& del);
    std::list<author>::iterator find_author(std::list<author>::iterator begin, const author& rhs);
    std::list<author>::const_iterator find_author(std::list<author>::const_iterator begin, const author& rhs) const;

    void print(std::ostream& out) const;

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

  library& operator=(const library& rhs) = default;

  ~library()=default;

  std::list<book>& get_books_list(); 
  const std::list<book>& get_books_list() const;

  void print(std::ostream& out) const;

  void add_book(const book& rhs);
  void delete_book(const book& rhs);
  void delete_book(std::list<book>::iterator rhs);
  std::list<book>::iterator search_book(const std::string& rhs, std::list<book>::iterator begin);
  std::list<book>::const_iterator search_book(const std::string& rhs, std::list<book>::const_iterator begin);
  std::list<book>::iterator search_book(const book& rhs);
  std::list<book> search_by_title(const std::string& title) const;
  std::list<book> search_authors_books(const author& rhs) const;
  void delete_book_by_author(const author& rhs);

  void add_author_to_book(const std::list<book>::iterator it, const author& aut);
  void delete_author_from_book(const std::list<book>::iterator it, const author& aut);
};

void add_book_to_list(std::list<book>& list, const book& book1);

void check_file(const std::string& file_name);


author author_gen(std::mt19937 &gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father);

book book_gen(std::mt19937& gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father, const std::vector<std::string>& titles);

std::list<book> generate_books_list(size_t max_count, std::mt19937& gen, const std::vector<std::string>& author_last_name,
                  const std::vector<std::string>& author_name,const std::vector<std::string>& author_father,
                  const std::vector<std::string>& titles);

library library_gen(size_t max_count, std::mt19937 &gen, const std::vector<std::string>& author_last_name, const std::vector<std::string>& author_name,
                  const std::vector<std::string>& author_father, const std::vector<std::string> titles);

std::vector<std::string> parse_words(const std::string& text, const std::string& delimeters);

std::vector<std::string> parse_text_lines(const std::string& file_name);

std::vector<std::string> parse_text_words(const std::string& file_name, const std::string& delimeters);

void print_authors(const std::list<author>& aut, std::ostream& out);

void print_book(const book& rhs, std::ostream& out);

void print_library(const library& rhs, std::ostream& out);

std::list<author> convert_string_to_authors_list(const std::string& string_authors, const std::string& delimiters);

