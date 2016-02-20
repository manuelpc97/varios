#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int** createTriangle(int);
void printTriangle(int**, int);
void fillTriangle(int**, int);
void printExpansion(int*, int);
void destroyTriangle(int**, int);
int nextPrime(int);
bool isPrime(int);
int fibonnaci(int);

int main(int argc, char const *argv[]){
	int choose;
	cout << "1.Triángulo de Pascal." << endl;
	cout << "2.Expansión del Binomio de Newton." << endl;
	cout << "3.Longest Collatz sequence (14)." << endl;
	cout << "4.Truncatable primes (37)." << endl;
	cout << "5.Primonacci. (304)" << endl;
	cout << "-------------------" << endl;
	cout << "Usted escogió la opción: ";
	cin >> choose;
	cout << "-------------------" << endl;
	if(choose == 1 || choose == 2){
		int** triangle;
		int level;
		cout << "Ingrese el nivel: ";
		cin >> level;
		if(choose == 2){
			level++;
		}
		triangle = createTriangle(level);
		fillTriangle(triangle, level);
		if(choose == 1){
			printTriangle(triangle, level);
		}else{
			int* expansion = triangle[level-1];
			cout<< "(a+b)^" << level-1 << " = ";
			printExpansion(expansion, level);
		}
		destroyTriangle(triangle, level);
	}else if(choose == 3){


	}else if(choose == 4){

	}else if(choose == 5){
		int number;
		cout << "Ingrese el número en la sucesión: ";
		
	}

	cout << "-------------------" << endl;
	return 0;
}

int** createTriangle(int size){
	int** triangle = new int*[size];
	for (char i = 0; i < size; ++i){
		triangle[i] = new int[size];
	}
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			triangle[i][j] = 0;
		}
	}
	return triangle;
}

void printTriangle(int** triangle, int size){
	for (int i = 0; i < size ; ++i){
		for (int j = 0; j < size; ++j){
			if(triangle[i][j]){
				cout<<"[" <<triangle[i][j] << "] ";
			}
		}
		cout << endl;
	}
	cout <<"-------------------------" << endl;
}

void fillTriangle(int** triangle, int size){
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			if(j == 0 || i == j){
				triangle[i][j] = 1;
			}else if(i>0 && j>0){
				triangle[i][j] = triangle[i-1][j-1]+ triangle[i-1][j];
			}
		}
	}
}
void printExpansion(int* expansion, int size){
	int expA = size-1;
	int expB = 0;
	for (int i = 0; expB != size; ++i){
		if(expansion[i]){
			if(expansion[i] > 1){
				cout << expansion[i];
			}
			if(expA){
				cout << "(a";
				if(expA > 1){
					cout << "^" << expA;
				} 
				cout << ")";
			}
			if(expB){
				cout << "(b";
				if(expB > 1){
					cout << "^" << expB;
				} 
				cout << ")";
			}
			if(expB != size - 1){
				cout << " + ";
			}else{
				cout << " ";

			}
			expA--;
			expB++;
		}
	}
	cout << endl;
}

void destroyTriangle(int** triangle, int size){
	for (char i = 0; i < size; ++i){
		delete[] triangle[i];
	}

	delete[] triangle;
}

int nextPrime(int number){
	int aumt = 1;
	int newPrime = 0;
	while(isPrime(newPrime) == false){
		newPrime = number + aumt;
		aumt++;
	}
	return newPrime;
}

bool isPrime(int number){
	if(number%2 == 0 && number!=2){
		return false;
	}else{
		for (int i = 3; i < number; i+=2) {
			if(number%i == 0){
				return false;
			}
		};
	}
	return true;
}

int fibonnaci(int number){

}