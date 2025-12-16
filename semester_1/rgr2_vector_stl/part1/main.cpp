#include <cstddef>
#include <vector>
#include <cmath>
#include <iostream>

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
    return count;
}

double vector_average(std::vector<int>& vect)
{
    long long sum = 0;
    for(int value: vect)
    {
        sum += value;
    }
    return static_cast<double>(sum)/vect.size();
}

void change_zeros_to_average(std::vector<int>& vect, double average)
{
    int int_average = static_cast<int>(average);
    for(int value: vect)
    {
        if(value == 0)
        {
            value = int_average;
        }
    }
}

int max_from_vect(std::vector<int>& vect)
{
    int max = vect.at(0);
    for(int value: vect)
    {
        if(value > max)
        {
            max = value;
        }
    }
    return max;
}

int min_from_vector(std::vector<int>& vect)
{
    int min = vect.at(0);
    for(int value: vect)
    {
        if(value < min)
        {
            min = value;
        }
    }
    return min;
}

void change_even_to_amplitude(std::vector<int>& vect)
{
    int amplitude = max_from_vect(vect) - min_from_vector(vect);
    for(int value: vect)
    {
        if(abs(value) % 2 == 0)
        {
           value = amplitude; 
        }
    }
}

void remove_repeats_from_vector(std::vector<int>& vect)
{
    std::vector<int>::iterator iter = vect.begin();
    for(; iter != vect.end(); ++iter)
    {
        int number = *iter;
        std::vector<int>::iterator iter_delete = ++iter;
        for(; iter_delete != vect.end(); ++iter_delete)
        {
            if(*iter_delete == number)
            {
                vect.erase(iter_delete);
            }
        }
    }
}

void print_vector(std::vector<int>& vect)
{
    for(int item: vect)
    {
        std::cout << item << " ";
    }
}

int main() {

    std::vector<int> vect{1, 1, 3, 5, 1 , 54, 5, 1};
    int count = vect.size();
    remove_repeats_from_vector(vect);
    // your code goes here
    print_vector(vect);    
    return 0;
}
