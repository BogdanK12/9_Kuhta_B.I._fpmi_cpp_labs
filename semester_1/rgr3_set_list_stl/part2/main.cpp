#include "library.h"
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <exception>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

void clear_buffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void input(size_t& a)
{
    if(!(std::cin >> a))
    {
        throw std::runtime_error("It's not a number.");
    }
}

book input_book(const std::string& delimiters)
{
    std::cout << "Print down idk, title(within double apostrophe), all authors with their first, last and father's names, publication year: \n";
    size_t idk, publication_year;
    std::string title_string, authors_string;
    input(idk);
    std::cin.ignore();
    getline(std::cin, title_string);
    getline(std::cin, authors_string);
    input(publication_year);
    std::cout << '\n';
    clear_buffer();
    return book(idk, convert_string_to_authors_list(authors_string, delimiters), title_string, publication_year);
}

author input_author()
{
    std::cout << "Print down last name, first name and father's name of an author: ";
    std::string name1, name2, name3;
    std::cin >> name1 >> name2 >> name3;
    clear_buffer();
    return author(name1, name2, name3);
}

int main() {

    const std::string delimiters = " .,!?\n";
    const std::string file_titles = "titles.txt";
    const std::string file_last_names = "last_names.txt";
    const std::string file_names = "names.txt";
    const std::string files_fathers_names = "fathers_names.txt"; 

    std::random_device rd;
    std::mt19937 gen(rd());
    
    try{
    // TODO generation in other program
    std::vector<std::string> titles = parse_text_lines(file_titles);
    std::vector<std::string> last_names = parse_text_words(file_last_names, delimiters);
    std::vector<std::string> names = parse_text_words(file_names, delimiters);
    std::vector<std::string> fathers_names = parse_text_words(files_fathers_names, delimiters);

    std::cout << "------------------------------------\n";
    library rhs(library_gen(gen, last_names, names, fathers_names, titles));
    rhs.print(std::cout);

    std::cout << "------------------------------------\n";
    rhs.add_book(input_book(delimiters));
    rhs.print(std::cout);

    std::cout << "\n------------------------------------\n";
    rhs.delete_book(input_book(delimiters));
    rhs.print(std::cout);    

    std::cout << "\n------------------------------------\n";
    std::cout << "Print down title of book you're searching for: ";
    std::string string_search;
    std::getline(std::cin, string_search);
    // string_search.erase(0, string_search.find_first_not_of(delimiters));
    std::cout << '\n';
    library temp(rhs.search_by_title(string_search));
    temp.print(std::cout);

    std::cout << "\n------------------------------------\n";
    author psycho = input_author();
    library psycho_books(rhs.search_authors_books(psycho));
    psycho_books.print(std::cout);

    std::cout << "\n------------------------------------\n";
    book arg1 = input_book(delimiters);
    std::list<book>::iterator it = rhs.search_book(arg1);
    if(it != rhs.get_books_list().end())
    {
        author a1 = input_author();
        rhs.delete_author_from_book(it, a1);
        it->print(std::cout);    
    } else
    {
        std::cerr << "Tried to acess non-existent book.";    
    }

    std::cout << "\n------------------------------------\n";
    book arg2 = input_book(delimiters);
    std::list<book>::iterator it2 = rhs.search_book(arg2);
    if(it2 != rhs.get_books_list().end())
    {
        author a2 = input_author();
        rhs.add_author_to_book(rhs.search_book(arg2), a2);
        it2->print(std::cout);
    } else
    {
        std::cerr << "Tried to acess non-existent book.";    
    }
    
    } catch (std::exception& err){
        std::cerr << err.what() << '\n';
    }

    return 0;
}
