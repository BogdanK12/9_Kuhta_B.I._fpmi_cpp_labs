#include <iostream>

int main(){ 
  int lin;
  std::cout << "Print size of your matrix(number of lines and columns): ";
  if(!(std::cin >> lin)){
    std::cout << "Print only integers";
    std::exit(1);
  }

  int **arr = new int*[lin];
  for(int i = 0; i < lin; ++i){
    arr[i] = new int[lin];
  }

  for(int i = 0; i < lin; ++i){
    for(int j = 0; j < lin; ++j){
      if(!(std::cin >> arr[i][j])){
        std::cout << "Print only integers";
        std::exit(2);
      }
    }
  }
  
  for(int i = 0; i < lin; ++i){
    for(int j = 0; j < lin; ++j){
        std::cout << " " << arr[i][j];
    }
    std::cout << std::endl;
  }
  for(int i = 0; i < lin; ++i){ // sum in columns without zero
    int sumInCol = 0;
    int zeros = 0;
    for(int j = 0; j < lin; ++j){
      sumInCol += arr[j][i];
      if(arr[j][i] == 0){
        ++zeros;
      }
    }
    if(zeros == 0){
      std::cout << "Sum in " << (i + 1) << " column is: " << sumInCol << std::endl; 
    }
    zeros = 0;
    sumInCol = 0;
  }

  for(int i = 0; i < (lin/2); ++i){
    for(int j = 0; j < lin; ++j){
      arr[i][j] = arr[i][j] + arr[lin - (i + 1)][j];
      arr[lin - (i + 1)][j] = arr[i][j] - arr[lin - (i + 1)][j];
      arr[i][j] = arr[i][j] - arr[lin - (i + 1)][j];
    }
  }
  
  for(int i = 0; i < lin; ++i){
    for(int j = 0; j < lin; ++j){
        std::cout << " " << arr[i][j];
    }
    std::cout << std::endl;
  }
  
  return 0;
}
