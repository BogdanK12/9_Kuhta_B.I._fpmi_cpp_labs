#include <cstddef>
#include <fstream>
#include <string>
#include "train.h"

int main(int argc, char* argv[])
{
  const std::string destinations_file = "destinations.txt";
  const std::string trains_file = "trains.txt";
  const std::string trains_file_full_time = "trains_time.txt";
  const std::vector<TrainType> types{TrainType::PASSENGER, TrainType::FREIGHT, TrainType::HIGH_SPEED, TrainType::SUBWAY, TrainType::SPECIALIZED};

  std::random_device rd;
  std::mt19937 generator(rd());

  check_file(destinations_file);
  std::string string_with_destinations;
  std::ifstream in(destinations_file);
  char c;
  while(in.get(c))
  {
    string_with_destinations += c;
  }

  // std::ofstream out_test("dest_test.txt");
  // for(std::string dest: destinations)
  // {
  //   out_test << dest << '\n';
  // }

  const std::string delimeters = "?!,.\n| ";
  std::vector<std::string> destinations = parse_words(string_with_destinations, delimeters);

  int value = std::stoi(argv[1]);
  std::vector<Train> random_trains;
  for(size_t i{0}; i < value; ++i)
  {
    random_trains.push_back(generate_train(destinations, types, generator));
  }
  std::ofstream out1(trains_file);
  print_vector_short(random_trains, out1);
  out1.close();

  sort_by_dispatch_time(random_trains);

  std::ofstream out2(trains_file_full_time);
  print_vector_short_with_full_time(random_trains, out2);
  out2.close();
}
