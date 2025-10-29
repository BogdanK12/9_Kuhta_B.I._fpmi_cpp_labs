#include <iostream>
#include <random>

int** createMatrix(int lin){
  int** arr = new int*[lin];
  for(int i = 0; i < lin; ++i){
    arr[i] = new int[lin];
  }
  return arr;
}

void inputManually(int** arr, int arrSize){
  for(int i = 0; i < arrSize; ++i){
    for(int j = 0; j < arrSize; ++j){
      if(!(std::cin >> arr[i][j])){
        std::cout << "Print only integers";
        std::exit(2);
      }
    }
  }
}

int** createMatrixRandom(int lin, int min, int max, std::mt19937& gen){
  std::uniform_int_distribution<int> elem(min, max);
  int **arr = createMatrix(lin);
  for(int i = 0; i < lin; ++i){
    for(int j = 0; j < lin; ++j){
      arr[i][j] = elem(gen);
    }
  }
  return arr;
}

void inputSize(int& lin){
  std::cout << "Print size of your matrix(number of lines and columns): ";
  if(!(std::cin >> lin)){
    std::cout << "Print only integers";
    std::exit(1);
  }
}

void printMatrix(int** arr, int lin){
  for(int i = 0; i < lin; ++i){
    for(int j = 0; j < lin; ++j){
      std::cout << " " << arr[i][j];
    }
    std::cout << std::endl;
  }
}

void swapLinesMatrix(int** arr, int lin){
  for(int i = 0; i < (lin/2); ++i){
    for(int j = 0; j < lin; ++j){
      arr[i][j] = arr[i][j] + arr[lin - (i + 1)][j];
      arr[lin - (i + 1)][j] = arr[i][j] - arr[lin - (i + 1)][j];
      arr[i][j] = arr[i][j] - arr[lin - (i + 1)][j];
    }
  }
}

void sumInColumnsWithoutZeros(int** arr, int lin){
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
}

void deleteMatrix(int** arr, int lin){
  for(int i = 0; i < lin; ++i){
      delete[] arr[i];
  }
}

int main(){
  int lin;
  int how;

  std::cout << "Write down which way you will use to fill the array(1 - manually, 0 - randomly): ";
  if(!(std::cin >> how)){
    std::cout << "Only integers";
    std::exit(1);
  }

  switch(how){
    case 1:
      {
        inputSize(lin);
        int **arr = createMatrix(lin);
        inputManually(arr, lin);
        sumInColumnsWithoutZeros(arr, lin);
        swapLinesMatrix(arr, lin);
        printMatrix(arr, lin);
        deleteMatrix(arr, lin);
        delete[] arr;
        break;
      }
    case 0:
      {
        std::mt19937 gen(45218965);
        inputSize(lin);
        int min, max;
        std::cout << "Write down min and max possible random elements: ";
        if(!(std::cin >> min >> max)||(min >= max)){
          std::cout << "Only integers, min < max";
          std::exit(4);
        }
        int **arr = createMatrixRandom(lin, min, max, gen);
        printMatrix(arr, lin);
        sumInColumnsWithoutZeros(arr, lin);
        swapLinesMatrix(arr, lin);
        printMatrix(arr, lin);
        deleteMatrix(arr, lin);
        delete[] arr;
        break;
      }
    default:
      {
        std::cout << "You are stupid";
        std::exit(1);
        break;
      }
  }
  return 0;
}
