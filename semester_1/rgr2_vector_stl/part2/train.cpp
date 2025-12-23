
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "train.h"
#include <sys/types.h>
#include "time_utility.h"
#include <map>

TrainType string_to_type(const std::string& type_string)
{
  TrainType retval;
  static const std::map<std::string, TrainType> type_map = {
    {"PASSENGER", TrainType::PASSENGER},
    {"FREIGHT",   TrainType::FREIGHT},
    {"HIGH_SPEED", TrainType::HIGH_SPEED},
    {"SUBWAY",    TrainType::SUBWAY},
    {"SPECIALIZED", TrainType::SPECIALIZED}};
  
  std::map<std::string, TrainType>::const_iterator it = type_map.find(type_string);
  if (it != type_map.end())
  {
    retval = it->second;
  } else
  {
    throw std::runtime_error("There is no such type: " + type_string);  
  }
  return retval;
}

Train::Train(size_t id, std::string type_string, std::string destination, std::time_t dis_time, std::time_t travel_time)
  : id_(id), type_(string_to_type(type_string)), destination_(destination), dispatch_time_(dis_time), travelling_time_(travel_time)
  {}

Train::Train(size_t id, TrainType type, std::string destination, std::time_t dis_time, std::time_t travel_time)
  : id_(id), type_(type), destination_(destination), dispatch_time_(dis_time), travelling_time_(travel_time)
  {}

Train generate_train(const std::vector<std::string> destinations, const std::vector<TrainType> types, std::mt19937& gen)
{
  std::uniform_int_distribution<uint> destination_gen(0, destinations.size() - 1);
  std::uniform_int_distribution<uint> type_gen(0, types.size() - 1);
  size_t max = - 1;
  std::uniform_int_distribution<uint> id_gen(0, max);
  size_t id = id_gen(gen);
  std::string dest = destinations[destination_gen(gen)];
  TrainType type = types[type_gen(gen)];
  std::time_t t1 = GenerateRandomTime(gen);
  // const std::time_t day =  
  std::time_t t2 = (GenerateRandomTime(gen));

  return Train(id, type, dest, t1, t2);
}
  

// getter for dispatch time
std::time_t Train::get_dispatch_time() const
{
  return this->dispatch_time_;
}

std::time_t Train::get_travelling_time() const
{
  return this->travelling_time_;
}

size_t Train::get_id() const
{
  return this->id_;
}

TrainType Train::get_type() const
{
  return this->type_;
}

std::string Train::get_destination() const
{
  return this->destination_;
}

Train parse_train(const std::string& train_string)
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
    for(size_t j = 1; j < vec.size() - i; ++j)
    {
      if(vec[j - 1].get_dispatch_time() > vec[j].get_dispatch_time())
      {
        std::swap(vec.at(j - 1), vec.at(j));
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
    default:
      throw std::runtime_error("There is no such type. ");
  }
}

void Train::print(std::ostream& out) const
{
  out << "Train Id: " << this->get_id() << ". ";
  out << "Train type: " << type_to_string(this->get_type()) << ". ";
  out << "Train destination: " << this->get_destination() << ". ";
  // out << "Train dispatch time: " << this->get_dispatch_time() << ". ";
  time_utility::print_time(dispatch_time_, out);
  // out << "Train travelling time: " << this->get_travelling_time() << ". ";  
  out << "Train travelling time: ";
  time_utility::print_time(travelling_time_, out);
}

void Train::print_short(std::ostream& out) const
{
  out << this->get_id() << " ";
  out << type_to_string(this->get_type()) << " ";
  out << this->get_destination() << " ";
  out << this->get_dispatch_time() << " ";
  out << this->get_travelling_time() << " "; 
}

void Train::print_short_with_full_time(std::ostream& out) const
{
  out << this->get_id() << " ";
  out << type_to_string(this->get_type()) << " ";
  out << this->get_destination() << " ";
  time_utility::print_time(dispatch_time_, out);
  out << " ";
  time_utility::print_time(travelling_time_, out);
}

void print_from_interval(const std::vector<Train>& vec, std::time_t start_time, std::time_t end_time, std::ostream& out)
{
  // const std::time_t sec_in_year = 365 * 24 * 60 * 60 * 55;
  if(end_time < start_time){ throw std::runtime_error("End of interval is less than start. ");}
  for(const Train& train: vec)
  {
    if(train.get_dispatch_time() >= start_time && train.get_dispatch_time() <= end_time)
    {
      train.print(out);
    }
  }
}

// void print_from_interval(const std::vector<Train>& vec, std::time_t start_time, std::time_t end_time, std::ostream& out)
// {
//   const std::time_t day = 24 * 3600;
//   size_t count{0};
//   for (const Train& train : vec)
//   {
//     const std::time_t dispatch = train.get_dispatch_time();
//     const std::time_t arrival  = dispatch + (train.get_travelling_time() % day);

//     if (dispatch >= start_time && arrival <= end_time)
//     {
//       train.print_short_with_full_time(out);
//       ++count;
//     }
//   }
//   out << "\nThere are " << count << " trains in this interval.";
// }
 

std::vector<Train> trains_with_certain_destination(const std::vector<Train>& vec, const std::string& destination)
{
  std::vector<Train> vec_destination;
  for(Train train: vec)
  {
    if(train.get_destination() == destination)
    {
      vec_destination.push_back(train);
    }
  }
  return vec_destination;
}

void print_with_certain_destination(const std::vector<Train>& vec, const std::string& destination, std::ostream& out)
{
  if(vec.empty()){ throw std::runtime_error("There are no trains. ");}
  std::vector<Train> vec_dest = trains_with_certain_destination(vec, destination);
  if(vec_dest.size() == 0)
  {
    out << "There are no trains with such destination. \n";
    return;
  }
  for(Train train: vec_dest)
  {
    train.print_short_with_full_time(out);
  }
}

void print_with_certain_destination_and_type(const std::vector<Train> &vec, const std::string& destination, TrainType type, std::ostream& out)
{
  if(vec.empty()){ throw std::runtime_error("There are no trains. ");}
  size_t count{0};
  for(Train train: vec)
  {
    if(train.get_destination() == destination && train.get_type() == type)
    {
      train.print(out);
      ++count; 
    }
  }
  if(count == 0){out << "There are no trains with this destination. \n";}
}

Train find_fastest_to_destination(const std::vector<Train>& vec,const std::string& destination)
{
  if(vec.empty()){ throw std::runtime_error("There are no trains. ");}
  std::vector<Train> vec_dest = trains_with_certain_destination(vec, destination);
  if(vec_dest.empty()){ throw std::runtime_error("There are no trains with such destination. \n");}
  Train fastest = vec_dest[0];
  std::time_t fastest_time = fastest.get_travelling_time();
  for(const Train& train: vec_dest)
  {
    if(train.get_travelling_time() < fastest_time)
    {
      fastest = train;
      fastest_time = train.get_travelling_time();
    }
  }
  return fastest;
}

void check_file(const std::string& file_name)
{
  std::ifstream in(file_name);
  if(!in.is_open())
  {
    throw std::runtime_error("Your file cannot be opened: " + file_name);
  }
  if(in.peek() == std::ifstream::traits_type::eof())
  {
    throw std::runtime_error("This file is empty: " + file_name);
  }
}

std::vector<std::string> parse_words(const std::string& text, const std::string& delimeters)
{
  std::vector<std::string> retval;
  size_t pos1, pos2;
  pos1 = text.find_first_not_of(delimeters);
  while(pos1 != std::string::npos)
  {
    pos2 = text.find_first_of(delimeters, pos1);
    retval.push_back(text.substr(pos1, pos2 - pos1));
    if(pos2 == std::string::npos){ break;}
    pos1 = text.find_first_not_of(delimeters, pos2);
  }
  return retval;
}

std::vector<Train> parse_file(const std::string& file_name)
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

void print_vector(const std::vector<Train>& vec, std::ostream& out)
{
  for(Train train: vec)
  {
    train.print(out);
    out << '\n';
  }
}

void print_vector_short_with_full_time(const std::vector<Train>& vec, std::ostream& out)
{
  for(Train train: vec)
  {
    train.print_short_with_full_time(out);
    // out << '\n';
  }
}

void print_vector_short(const std::vector<Train>& vec, std::ostream& out)
{
  for(Train train: vec)
  {
    train.print_short(out);
    out << '\n';
  }
}
