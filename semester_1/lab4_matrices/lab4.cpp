#include <iostream>

void inputManual(int , int n, int m){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(!(std::cin >> (*(arr + )))){
        std::cout << "You are stupid";
        std::exit(2);
      }
    }
  }
}

int sumInColumnWithoutZero(int* arr,int n, int m){
  
}

int main(){
  int how;
  int lines;
  int columns;
  std::cout << "How you want fill array(1 - manually, 0 - randomly): ";
  if(!(std::cin >> how)){
    std::cout << "You are stupid";
    std::exit(1);
  }
  switch(how){
    case 1:
      {
        std::cout << "Write down number of lines and columns in your matrix: ";
        if(!(std::cin >> lines >> columns)){  
            std::cout << "You are stupid";
            std::exit(3);
        }
        inputManual(arr, lines, columns);
        break;
      }
    case 0:
      {
        std::mt19937 gen(45218965);
        std::uniform_int_distribution<int> dist(1, 1000);
        int lines = dist(gen);
        int columns = dist(gen);
        int *arr = new int[lines][columns];
        int minEl, maxEl;
        std::uniform_int_distribution<int> elem(1, 1000);
        if(!(std::cin >> minEl >> maxEl)){  
          std::cout << "You are stupid";
          std::exit(3);
        }
        for(int i = 0; i < lines; ++i){
          for(int j = 0; j < columns; ++j){
            arr[i][j] = elem(gen);
          }
        }
        break;
      }
  }
  retutn 0;
}
