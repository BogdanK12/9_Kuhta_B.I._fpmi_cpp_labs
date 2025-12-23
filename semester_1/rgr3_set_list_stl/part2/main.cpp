#include "library.h"
#include <cstddef>
#include <cstdio>
#include <exception>
#include <iostream>
#include <random>
#include <string>
#include <vector>

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

    library rhs(library_gen(gen, last_names, names, fathers_names, titles));
    rhs.print(std::cout);
    std::cout << '\n';

    std::cout << "Print down idk, title(within double apostrophe), all authors with their first, last and father's names, publication year: \n";
    size_t idk1, publication_year;
    std::string title_string, authors_string;
    std::cin >> idk1;
    std::cin.ignore();
    getline(std::cin, title_string);
    getline(std::cin, authors_string);
    std::cin >> publication_year;
    rhs.add_book(book(idk1, convert_string_to_authors_list(authors_string, delimiters), title_string, publication_year));
    rhs.print(std::cout);

    std::cout << "Print down idk, title(within double apostrophe), all authors with their first, last and father's names, publication year: \n";
    size_t idk2, publication_year2;
    std::string title_string2, authors_string2;
    std::cin >> idk2;
    std::cin.ignore();
    getline(std::cin, title_string2);
    getline(std::cin, authors_string2);
    std::cin >> publication_year2;
    rhs.delete_book(book(idk2, convert_string_to_authors_list(authors_string2, delimiters), title_string2, publication_year2));
    rhs.print(std::cout);    

    std::cout << "Print down title of book you're searching for: ";
    std::string string_search;
    std::cin >> string_search;
    // string_search.erase(0, string_search.find_first_not_of(delimiters));
    library temp(rhs.search_by_title(string_search));
    temp.print(std::cout);
    
    std::cout << "Print down last name, first name and father's name of an author: ";
    std::string name1, name2, name3;
    std::cin >> name1 >> name2 >> name3;
    author psycho(name1, name2, name3);
    library psycho_books(rhs.search_authors_books(psycho));
    psycho_books.print(std::cout);

    } catch (std::exception& err){
        std::cerr << err.what() << '\n';
    }

    return 0;
}
