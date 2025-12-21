// #include <pthread.h>
#include "time_utility.h"
#include "train.h"

#include <exception>
#include <iostream>
#include <random>
#include <string>
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

    std::time_t t2 = GenerateRandomTime(generator);
    if(t2 < t1)
    {
        std::time_t temp = t2;
        t2 = t1;
        t1 = temp;
    }

    std::cout << "t1: ";
    PrintTime(t1);
    
    std::cout << "t2: ";
    PrintTime(t2);

    std::cout << std::endl;

    std::vector<Train> trains = parse_file(trains_file);
    // print_vector_short(trains, std::cout);
    std::cout << "Start time is: ";
    PrintTime(t2);
    std::cout << "End time is: ";

    PrintTime(t1);
    std::cout << "-------------------------------------\n";
    std::cout << "Trains from this interval: \n";
    print_from_interval(trains, t1, t2, std::cout);

    std::cout << "\n-------------------------------------\n";
    std::cout << "Trains goind to Minsk: \n";
    print_with_certain_destination(trains, "Minsk", std::cout);

    std::cout << "-------------------------------------\n";
    std::cout << "Specialized trains that go to Berlin: \n";
    print_with_certain_destination_and_type(trains, "Berlin", TrainType::SPECIALIZED, std::cout);

    std::cout << "-------------------------------------\n";
    Train fastest_to_Grodno = find_fastest_to_destination(trains, "Grodno");
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
