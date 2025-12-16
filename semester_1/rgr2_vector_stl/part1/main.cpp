#include <cstddef>
#include <vector>

void input_vector(std::vector<int>& vect)
{
    int input;
    while(!(std::cin >> input))
    {
        vect.push_back(input);
    }
}

int count_equal_to(std::vector<int>& vect, int search_value)
{
    size_t count = 0;
    for(int value: vect)
    {
        if(value == search_value)
        {
          ++count;  
        }
    }
    return count;
}

int count_cond(std::vector<int>& vect, bool (*cond)(int a))
{
    size_t count = 0;
    for(int value: vect)
    {
        if(cond(value))
        {
            ++count;
        }
    }
}

int main() {

    std::vector<int> vect;
    input_vector(vect);
    int count = vect.size();
    
    // your code goes here

    return 0;
}
