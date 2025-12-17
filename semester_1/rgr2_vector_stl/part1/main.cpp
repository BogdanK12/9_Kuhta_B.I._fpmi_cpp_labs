#include <cstddef>
#include <ostream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

long long sum_of_vector(std::vector<int>& vect)
{
    long long sum = 0;
    for (int value: vect)
    {
        sum += value;
    }
    return sum;
}

void input_vector(std::vector<int>& vect)
{
    int input;
    while(std::cin >> input)
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
    for(int &value: vect)
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
    for(int &value: vect)
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
        int number = abs(*iter);
        std::vector<int>::iterator iter_delete = ++iter;
        for(; iter_delete != vect.end(); ++iter_delete)
        {
            if(abs(*iter_delete) == number)
            {
                std::vector<int>::iterator temp = iter_delete;
                --iter_delete;
                vect.erase(temp);
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

bool is_positive(int a)
{
    return a > 0;
}

int sum_of_interval(std::vector<int>& vec, int pos1, int pos2)
{
    int sum = 0;
    if(pos1 > pos2)
    {
        int temp = pos1;
        pos1 = pos2;
        pos2 = temp; 
    }
    for(size_t i = pos1; i <= pos2; ++i)
    {
        sum += vec.at(i);
    }
    return sum;
}

void add_to_each(std::vector<int>& vec, int a)
{
    for(int &value: vec)
    {
        value += a;
    }
}

int main() {
    //vector input
    std::cout << "Input your vector(print char to stop): \n";
    std::vector<int> vec_to_input;
    input_vector(vec_to_input);
    std::cout << "Your vector: ";
    print_vector(vec_to_input);
    std::cout << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    // sum of vector
    std::cout << "Sum of your vector: " << sum_of_vector(vec_to_input) << '\n';

    // number of elements
    std::cout << "Number of elements in your vector: " << vec_to_input.size() << '\n';

    // number of elements equal to n
    std::cout << "Print down n: ";
    int a;
    try
    {
    if(!(std::cin >> a))
    {
        throw "Only integers.";
    }
    } catch(std::string problem)
    {
        std::cout << problem;
    }
    std::cout << "Number of elements, equal to " << a << " in your vector: " << count_equal_to(vec_to_input, a) << '\n';

    // count cond
    std::cout << "Number of elements, which are positive: " << count_cond(vec_to_input, is_positive) << "\n";

    // replacing zeros with average
    std::vector<int> vec_average = vec_to_input;
    double average = vector_average(vec_average);
    change_zeros_to_average(vec_average, average);
    std::cout << "Your vector with zeros replaced with average(" << average << "): ";
    print_vector(vec_average);
    std::cout << std::endl;

    // adding sum of vector's interval to every element
    std::vector<int> vec_add = vec_to_input;
    int pos1, pos2;
    try
    {
        if(!(std::cin >> pos1 >> pos2) || pos1 < 0 || pos2 < 0)
        {
            throw "Only positive integers.";
        }
    } catch(std::string problem)
    {
        std::cerr << problem;
    }
    int sum_of_interval1 = sum_of_interval(vec_add, pos1, pos2);
    add_to_each(vec_add, sum_of_interval1);
    std::cout << "Your vector after adding sum of interval: ";
    print_vector(vec_add);
    std::cout << std::endl;

    // replacing even numbers with amplitude
    std::vector<int> vec_amplitude = vec_to_input;
    change_even_to_amplitude(vec_amplitude);
    std::cout << "Your vector with even replaced with amplitude: ";
    print_vector(vec_amplitude);
    std::cout << std::endl;
    
    // deleting equal elements
    std::cout << "Vector before deleting equal elements: ";
    std::vector<int> vec_for_deleting = vec_to_input;
    print_vector(vec_for_deleting);
    std::cout << "\nVector after deleting equal elements: ";
    remove_repeats_from_vector(vec_for_deleting);
    print_vector(vec_for_deleting);    

    return 0;
}
