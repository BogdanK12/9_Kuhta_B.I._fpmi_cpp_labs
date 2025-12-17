
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "train.h"
#include "time_utility.h"
#include <map>


Train::Train(size_t id, std::string type_string, std::string destination, std::time_t dis_time, std::time_t travel_time)
  : id_(id), destination_(destination), dispatch_time_(dis_time), travelling_time_(travel_time)
  {

    static const std::map<std::string, TrainType> type_map = {
      {"PASSENGER", TrainType::PASSENGER},
      {"FREIGHT",   TrainType::FREIGHT},
      {"HIGH_SPEED", TrainType::HIGH_SPEED},
      {"SUBWAY",    TrainType::SUBWAY},
      {"SPECIALIZED", TrainType::SPECIALIZED}};

      std::map<std::string, TrainType>::const_iterator it = type_map.find(type_string);
      if (it != type_map.end())
      {
        this->type_ = it->second;
      } else
      {
        throw "There is no such type. ";  
      }
  }
  

// getter for dispatch time
std::time_t Train::get_dispatch_time()
{
  return this->dispatch_time_;
}

size_t Train::get_id()
{
  return this->id_;
}

TrainType Train::get_type()
{
  return this->type_;
}

std::string Train::get_destination()
{
  return this->destination_;
}

Train parse_train(std::string train_string)
{
  std::istringstream in(train_string);
  size_t id; 
  std::string type, destin;
  std::time_t disp_time, travel_time;
  in >> id >> type >> destin >> disp_time >> travel_time;
  return Train(id, type, destin, disp_time, travel_time);
}

void sort_by_dispatch_time(std::vector<Train>& vec)
{
  for(size_t i = 0; i < vec.size(); ++i)
  {
    for(size_t j = 1; i < vec.size() - i; ++j)
    {
      if(vec.at(i - 1).get_dispatch_time() > vec.at(i).get_dispatch_time())
      {
        std::swap(vec.at(i - 1), vec.at(i + 1));
      }
    }
  }
}

std::string type_to_string(TrainType type)
{
  switch (type)
  {
    case TrainType::PASSENGER:
      return "PASSENGER";
    case TrainType::FREIGHT:
      return "FREIGHT";
    case TrainType::HIGH_SPEED:
      return "HIGH_SPEED";
    case TrainType::SUBWAY:
      return "SUBWAY";
    case TrainType::SPECIALIZED:
      return "SPECIALIZED";
  }
}

void Train::print(std::ostream& out)
{
  out << "Train Id: " << this->get_id() << ". ";
  out << "Train type: " << type_to_string(this->get_type()) << ". ";
  out << "Train destination: " << this->get_destination() << ". ";
  out << "Train dispatch time: " << this->get_dispatch_time() << ". ";
  out << "Train travelling time: " << this->get_travelling_time() << ". ";  
}

void print_from_interval(std::vector<Train>& vec, std::time_t start_time, std::time_t end_time)
{
  for(Train train: vec)
  {
    if(train.get_dispatch_time() <= end_time && train.get_dispatch_time() >= start_time)
    {
      train.print(std::cout);
    }
  }
}

std::vector<Train> trains_with_certain_destination(std::vector<Train>& vec, std::string destination)
{
  std::vector<Train> vec_destination;
  for(Train train: vec)
  {
    if(train.get_destination() == destination)
    {
      vec_destination.push_back(train);
    }
  }
}

void print_with_certain_destination(std::vector<Train>& vec, std::string destination)
{
  std::vector<Train> vec_dest = trains_with_certain_destination(vec, destination);
  if(vec_dest.size() == 0)
  {
    std::cout << "There are no trains with such destination. \n";
    return;
  }
  for(Train train: vec_dest)
  {
    train.print(std::cout);
  }
}

void print_with_certain_destination_and_type(std::vector<Train> &vec, std::string destination, TrainType type)
{
  uint count = 0;
  for(Train train: vec)
  {
    if(train.get_destination() == destination && train.get_type() == type)
    {
      train.print(std::cout);
    }
  }
  if(count == 0){std::cout << "There are no such trains. \n";}
}

Train find_fastest_to_destination(std::vector<Train>& vec, std::string destination)
{
  if(vec.empty()){ throw "There are no trains. ";}
  std::vector<Train> vec_dest = trains_with_certain_destination(vec, destination);
  if(vec_dest.empty()){ throw "There are no trains with such destination. \n";}
  Train fastest = vec_dest.at(0);
  std::time_t fastest_time = fastest.get_travelling_time();
  for(Train train: vec_dest)
  {
    if(train.get_travelling_time() < fastest_time)
    {
      fastest = train;
    }
  }
  return fastest;
}

void check_file(std::string file_name)
{
  std::ifstream in(file_name);
  if(!in.is_open())
  {
    throw "Your file cannot be opened. ";
  }
  if(in.peek() == std::ifstream::traits_type::eof())
  {
    throw "This file is empty. ";
  }
}

std::vector<Train> parse_file(std::string file_name)
{
  check_file(file_name);
  std::ifstream in(file_name);
  std::string current_line; 
  std::vector<Train> vec;
  while(std::getline(in, current_line))
  {
    vec.push_back(parse_train(current_line));
  }
  return vec;
}
