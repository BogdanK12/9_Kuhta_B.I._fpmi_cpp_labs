#pragma once

#include <cstddef>
#include <istream>
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
    Train(size_t id, std::string type_string, std::string destination, std::time_t dis_time, std::time_t travel_time);
    Train(size_t id, TrainType type, std::string destination, std::time_t dis_time, std::time_t travel_time);

    Train() = default;

    TrainId get_id() const;
    TrainType get_type() const;
    std::string get_destination() const;
    std::time_t get_dispatch_time() const;
    std::time_t get_travelling_time() const;

    void print(std::ostream& out) const;
    void print_short(std::ostream& out) const;
    void print_short_with_full_time(std::ostream& out) const;
};

TrainType string_to_type(const std::string& type_string);

void check_file(const std::string& file_name);

Train parse_train(const std::string& train_string);

Train generate_train(const std::vector<std::string> destinations, const std::vector<TrainType> types, std::mt19937& gen);

std::vector<std::string> parse_words(const std::string& text, const std::string& delimeters);

std::vector<Train> parse_file(const std::string& file_name);

void sort_by_dispatch_time(std::vector<Train>& vec);

void print_from_interval(const std::vector<Train>& vec, std::time_t start_time, std::time_t end_time, std::ostream& out);

Train find_fastest_to_destination(const std::vector<Train>& vec, const std::string& destination);

void print_with_certain_destination(const std::vector<Train>& vec, const std::string& destination, std::ostream& out);

void print_with_certain_destination_and_type(const std::vector<Train> &vec,const std::string& destination, TrainType type, std::ostream& out);

Train find_fastest_to_destination(const std::vector<Train>& vec, const std::string& destination);

void print_vector(const std::vector<Train>& vec, std::ostream& out);

void print_vector_short(const std::vector<Train>& vec, std::ostream& out);

void print_vector_short_with_full_time(const std::vector<Train>& vec, std::ostream& out);
