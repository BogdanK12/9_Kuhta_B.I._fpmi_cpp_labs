#include <iostream>
#include <random>
// solve task with usage of
// dymanic arrays
void arrInputManual(int* arr, int n){
    std::cout << "Write down all elements of array: ";
    for(int i = 0; i < n; ++i){
        if(!(std::cin >> arr[i])){
            std::cout << "Write down only integers.";
        std::exit(2);
        }
    }
}

int signChangeCount(int* arr, int n){
    int signChange;
    for(int i = 1; i < n; i++){
        if(((arr[i] == 0)&&((abs(arr[i - 1])/(arr[i - 1]))==-1))||((arr[i - 1] == 0)&&(abs(arr[i])/(arr[i])==-1))){
            ++signChange;
        }else if(((abs(arr[i]))/(arr[i]))!=(((abs(arr[i - 1]))/(arr[i - 1])))){
            ++signChange;
        }
    }
    return signChange;
}

int sumBetweenZeros(int* arr, int n){
    int firstZero;
    int secZero;
    int zeros = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == 0){
            if(zeros == 0){
                firstZero = i;
                ++zeros;
            } else if(zeros == 1){
                secZero = i;
                ++zeros;
                break;
            }
        }
    }

    int sumZeros = 0;

    if(zeros == 2){
        for(int i = (firstZero + 1) ; i < secZero; ++i){
            sumZeros += arr[i];
        }
    }
    return sumZeros;
}

void Nchange(int* arr, int n, int N){
    int alliquotCounter = 0;
	  for(int i = 0; i < n; ++i){
		    if((arr[i] % N) == 0){
			    int temp = i;
			    int tempVar = arr[i];
			    for(int c = temp; c > alliquotCounter; --c){
				    arr[c] = arr[c - 1];
			    }
			    arr[alliquotCounter] = tempVar;
			    ++alliquotCounter;
		    }
	  }
}

void printArr(int* arr, int n){
    std::cout << "New array: ";
	  for(int i = 0; i < n; ++i){
		    std::cout << arr[i] << " ";
	  }
}

int main() {
    int n;
    int how;
    std::cout << "1 - manualy writen array. 0 - random array. ";
    std::cin >> how;

    switch(how){
        case 1:
            {
                std::cout << "How many elements does your array have: ";
                if((!(std::cin >> n))||(n < 0)){
                    std::cout << "Write down only positive integers.";
                    std::exit(1);
                }
                int *arr = new int[n];
                arrInputManual(arr, n);
                std::cout << "Integers change sign " << signChangeCount(arr, n) << " times." << std::endl;
                std::cout << "Sum of elements between first and second zero elements is: " << sumBetweenZeros(arr, n) << "." << std::endl;
                int N;
                std::cout << "Write down N(not equal to 0): ";
                if((!(std::cin >> N))||(N == 0)){
                    std::cout << "Write down only integers. Dont write 0. ";
                    std::exit(2);
                }
                Nchange(arr, n, N);
                printArr(arr,n);
                delete[] arr;
                break;
            }
        case 0:
            {
                std::mt19937 gen(45218965);
                std::uniform_int_distribution<int> dist(1, 10000);
                int n = dist(gen);
                int *arr = new int[n];
                std::cout << "Write down what can be minimal and maximal elements of array: ";
                int a, b;
                if((!(std::cin >> a >> b))||(a >= b)){
                    std::cout << "Write down only integers. Dont write 0. b must be greater than a. ";
                    std::exit(2);
                }
                std::uniform_int_distribution<int> element(a, b);
                for(int i = 0; i < n; ++i){
                    arr[i] = element(gen);
                }
                std::cout << "Integers change sign " << signChangeCount(arr, n) << " times." << std::endl;
                std::cout << "Sum of elements between first and second zero elements is: " << sumBetweenZeros(arr, n) << "." << std::endl;
                int N;
                std::cout << "Write down N(not equal to 0): ";
                if((!(std::cin >> N))||(N == 0)){
                    std::cout << "Write down only integers. Dont write 0. ";
                    std::exit(2);
                }
                Nchange(arr, n, N);
                printArr(arr,n);
                delete[] arr;
                break;
            }
        default:
            {
                std::cout << "You are stupid. ";
                std::exit(3);
            }
    }
    return 0;
}
