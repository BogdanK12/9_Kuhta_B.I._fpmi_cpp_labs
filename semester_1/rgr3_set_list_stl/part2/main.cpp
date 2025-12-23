#include "library.h"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
#include <vector>

int main() {

    const std::string delimitesr = " .,!?\n";
    const std::string file_titles = "titles.txt";
    const std::string file_last_names = "last_names.txt";
    const std::string file_names = "names.txt";
    const std::string files_fathers_names = "fathers_names.txt"; 

    std::random_device rd;
    std::mt19937 gen(rd());
    
    try{
    // TODO generation in other program
    std::vector<std::string> titles = parse_text_lines(file_titles);
    std::vector<std::string> last_names = parse_text_words(file_last_names, delimitesr);
    std::vector<std::string> names = parse_text_words(file_names, delimitesr);
    std::vector<std::string> fathers_names = parse_text_words(files_fathers_names, delimitesr);

    library rhs(library_gen(gen, last_names, names, fathers_names, titles));

    print_library(rhs, std::cout);
    
    std::list<author> autism{};
    } catch (std::exception& err){
        std::cerr << err.what() << '\n';
    }

    return 0;
}
