#pragma once

#include <ostream>
#include <string>
#include <vector>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;


enum class TrainType { 
    PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED
};

std::string type_to_string(TrainType type);

class Train {
private:
    TrainId id_;
    TrainType type_;
    std::string destination_;
    std::time_t dispatch_time_;
    std::time_t travelling_time_;

public:
    TrainId get_id();
    TrainType get_type();
    std::string get_destination();
    std::time_t get_dispatch_time();
    std::time_t get_travelling_time();
};

void search_by_dispatch_time(std::pmr::vector<Train>& vec);

void print_from_interval(std::vector<Train>& vec, std::time_t start_time, std::time_t end_time);

void print_with_certain_destination(std::vector<Train>& vec, std::string destination);

void print_with_certain_destination_and_type(std::vector<Train> &vec, std::string destination, enum class TrainType type);

Train find_fastest_to_destination(std::vector<Train>& vec, std::string destination);
