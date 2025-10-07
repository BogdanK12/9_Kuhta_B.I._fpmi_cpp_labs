#include <iostream>
#include <random>

void arrInputManual(int* arr, int n){
    std::cout << "Write down all elements of array: ";
    for(int i = 0; i < n; ++i){
        if(!(std::cin >> arr[i])){
            std::cout << "Write down only integers.";
            std::exit(2);
        }
    }
}

int productAfterBig(int* arrNum, int n){
    int maxElement = 0;
    int indexMaxElement = 0;

    for(int i = 0; i <= (n - 1); ++i){
        if(abs(arrNum[i]) > maxElement){
            maxElement = arrNum[i];
            indexMaxElement = i;
        }
    }

    int product = 1;

    for(int i = (indexMaxElement + 1); i <= (n - 1); ++i){
        product *= arrNum[i];
    }

    if(indexMaxElement == (n - 1)){
        product = 0;
    }
    return product;
}

int Pcounter(int *arrNum, int n, int P){
    int number;
    for(int i = 0; i <= (n - 1); ++i){
        if(arrNum[i] > P){
            ++number;
        }
    }
    return number;
}

void negativeChange(int* arrNum, int n){
    int negativeCounter = 0;
  	for(int i = 0; i < n; ++i){
		if(arrNum[i] < 0){
			int temp = i;
			int tempVar = arrNum[i];
			for(int c = temp; c > negativeCounter; --c){
				arrNum[c] = arrNum[c - 1];
			}
			arrNum[negativeCounter] = tempVar;
			++negativeCounter;
		}
	}
}

void printArr(int* arr, int n){
    std::cout << "New array: ";
    for(int i = 0; i < n; ++i){
		    std::cout << arr[i] << " ";
	  }
}

int main(){
    int nmax = 1000;
    int arrNum[nmax];
    int n;
    int number;
    int P;
    std::cout << "Write down P: ";
    
    if(!(std::cin >> P)){
        std::cout << "Write down only integers.";
        std::exit(2);
    }

    int how;
    std::cout << "1 - manualy writen array. 0 - random array. ";
    std::cin >> how;

    switch(how){
        case 1:
        {
            std::cout << "How many elements does your array have: ";
            if((!(std::cin >> n))||(n < 0)||(n > (nmax + 1))){
                std::cout << "Write down only positive integers smaller than " << nmax << ".";
                std::exit(2);
            }
            arrInputManual(arrNum, n);
            std::cout << "There are " << Pcounter(arrNum, n, P) << " integers in your array, that are greater than " << P << "." << std::endl;
            std::cout << "Product of numbers that come after the biggest is: " << productAfterBig(arrNum, n) << "." << std::endl;
            negativeChange(arrNum, n);
            printArr(arrNum, n);
            break;
        }
        case 0:
        {
            std::mt19937 gen(45218965);
            std::uniform_int_distribution<int> dist(1, 1000);
            int n = dist(gen);
            int arr[nmax];
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
            printArr(arr, n);
            std::cout << "There are " << Pcounter(arrNum, n, P) << " integers in your array, that are greater than " << P << "." << std::endl;
            std::cout << "Product of numbers that come after the biggest is: " << productAfterBig(arrNum, n) << "." << std::endl;
            negativeChange(arr, n);
            printArr(arr, n);
            break;
        }
        default:
        {
            std::cout << "You are stupid. ";
            std::exit(4);
        }
    }

    return 0;
}
