#include <pthread.h>
#include <sys/types.h>
#include "time_utility.h"
#include "train.h"

#include <cstddef>
#include <cstdio>
#include <exception>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <system_error>
#include <utility>
#include <vector>

int main() {
    const std::string trains_file = "trains.txt";
    // const std::string destinations_file = "destinations.txt";
    // const std::vector<TrainType> types{TrainType::PASSENGER, TrainType::FREIGHT, TrainType::HIGH_SPEED, TrainType::SUBWAY, TrainType::SPECIALIZED};
    std::random_device rd;
    std::mt19937 generator(rd());

    // check_file(destinations_file);

    // std::string string_with_destinations;
    // std::ifstream in(destinations_file);
    // char c;
    // while(in.get(c))
    // {
    //     string_with_destinations += c;
    // }

    // const std::string delimeters = "?!,.\n| ";
    // std::vector<std::string> destinations = parse_words(string_with_destinations, delimeters);

    // std::ofstream out_test("dest_test.txt");
    // for(std::string dest: destinations)
    // {
    //     out_test << dest << '\n';
    // }

    // std::vector<Train> random_trains;
    // for(size_t i{0}; i < 20; ++i)
    // {
    //     random_trains.push_back(generate_train(destinations, types, generator));
    // }
    // std::ofstream out1(trains_file);
    // print_vector_short(random_trains, out1);
    // out1.close();    
    
    // std::cout << "Generated 20 random train(trains.txt). \n";
    
    using namespace time_utility;
    try{

    std::time_t t1 = SetTime(12, 23);
    try {
        t1 = SetTime(12, 60);
    } catch (const std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }

    std::time_t t2;
    if(t2 < t1)
    {
        std::time_t temp = t2;
        t2 = t1;
        t1 = temp;
    }

    std::cout << std::endl;

    std::vector<Train> trains = parse_file(trains_file);
    // print_vector_short(trains, std::cout);

    std::size_t input_hours, input_minutes;
    std::cout << "Print down start time(hour and minutes separetly): ";
    if(!(std::cin >> input_hours >> input_minutes)){ throw std::runtime_error("It is not time. ");};
    try{t1 = SetTime(input_hours, input_minutes);}
    catch (const std::out_of_range& err)
    {
        std::cerr << err.what() << std::endl;
    }
    std::cout << "\nPrint down end time(hour and minutes separetly): ";
    if(!(std::cin >> input_hours >> input_minutes)){ throw std::runtime_error("It is not time. ");};
    try{t2 = SetTime(input_hours, input_minutes);}
    catch (const std::out_of_range& err)
    {
        std::cerr << err.what() << std::endl;
    }
    if(t2 < t1)
    {
        std::swap(t1, t2);
        std::cerr << "Start of interval was greater than it's end, so we swaped them.\n";
    }
    std::cout << "-------------------------------------\n";
    std::cout << "Trains from this interval: \n";
    print_from_interval(trains, t1, t2, std::cout);

    std::cout << "\n-------------------------------------\n";
    std::cout << "Print down destination(we will find fastest train to that destination): ";
    std::string dest1;
    std::cin >> dest1;
    std::cout << "Trains goind to " << dest1 << ": \n";
    print_with_certain_destination(trains, dest1, std::cout);

    std::cout << "-------------------------------------\n";
    std::string dest2, input_type;
    std::cout << "Print down destination and type: ";
    std::cin >> dest2 >> input_type;
    TrainType type_recognized = string_to_type(input_type);
    std::cout << "Specialized trains that go to \n" << dest2;
    print_with_certain_destination_and_type(trains, dest2, type_recognized, std::cout);

    std::cout << "-------------------------------------\n";
    std::cout << "Print down destination(we will find fastest train to that destination): ";
    std::string dest3;
    std::cin >> dest3;
    std::cout << "Fastest train to " << dest3 << ": \n";
    Train fastest_to_Grodno = find_fastest_to_destination(trains, dest3);
    std::cout << "Fastest train to Grodno is: ";
    fastest_to_Grodno.print(std::cout);
        
    } catch(std::exception& problem)
    {
        std::cerr << problem.what();
    }
    
    // std::cout << "t1 < t2: " << std::boolalpha << (t1 < t2) <<'\n';
    // std::cout << "t2 < t1: " << std::boolalpha << (t2 < t1) << '\n';

    return EXIT_SUCCESS;
}
