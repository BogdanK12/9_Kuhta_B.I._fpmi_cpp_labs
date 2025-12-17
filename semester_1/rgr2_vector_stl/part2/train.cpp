#include <cstddef>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include "train.h"
#include "time_utility.h"

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



void print_with_certain_destination(std::vector<Train>& vec, std::string destination)
{
  uint count = 0;
  for(Train train: vec)
  {
    if(train.get_destination() == destination)
    {
      train.print(std::cout);
      ++count;
    }
  }
  if(count == 0){ std::cout << "There are no trains with such destination. \n";}
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
  if(vec.size() == 0){ throw "There are no trains. ";}
  uint count = 0;
  Train fastest;
  for(Train train: vec)
  {
    if(train.get_destination() == destination)
    {
      ++count;
      fastest = train;
    }
  }
  if(count == 0)
  {
    throw "There are no trains with such destination. ";
  }
  for(Train train: vec)
  {
    if(train.get_destination() == destination && train.get_travelling_time() < fastest.get_travelling_time())
    {
      fastest = train;
    }
  }
}
