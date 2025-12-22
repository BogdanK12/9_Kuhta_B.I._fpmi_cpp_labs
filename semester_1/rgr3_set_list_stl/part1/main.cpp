#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>
#include <stdexcept>

void input(size_t& value)
{
    if(!(std::cin >> value))
    {
        throw std::runtime_error("Your input is not unsigned integer. ");
    }
}

void fill_set(std::set<size_t>& set, size_t n)
{
    for(size_t i = 1; i <= n; ++i)
    {
        set.insert(i);
    }
}

void print_set(const std::set<size_t>& set, std::ostream& out) 
{
    for(const size_t value: set)
    {
        out << value << " ";
    }
}

void eratosphene(std::set<size_t>& set)
{
    if(set.begin() == set.end()){throw std::runtime_error("Your set is empty.");}
    std::set<size_t>::iterator iter = set.begin();
    ++iter;
    while(iter != set.end())
    {
        std::set<size_t>::iterator iter_delete = std::next(iter);
        size_t num = *iter;
        while(iter_delete != set.end())
        {
            if(*iter_delete % num == 0)
            {
                iter_delete = set.erase(iter_delete);
            }
            else
            {
                ++iter_delete;
            }
        }
        ++iter;
    }
}

int main() {
    try{
        size_t n;
        std::cout << "Print down maximal number: ";
        input(n);
        
        std::set<size_t> primes;
        fill_set(primes, n);

        eratosphene(primes);
        std::cout << "---------------------------------------------\n";
        std::cout << "Primes: \n";
        print_set(primes, std::cout);

    } catch(std::exception& err)
    {
        std::cerr << err.what();
    }
    
    
    return 0;
}
