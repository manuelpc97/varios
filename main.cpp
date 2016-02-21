#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int** createTriangle(int);
void printTriangle(int**, int);
void fillTriangle(int**, int);
void printExpansion(int*, int);
void destroyTriangle(int**, int);
bool isPrime(unsigned long long int);
int evaluar(int);
unsigned long long int sumOfPowBases(int=1000);
int stringSize(string);
bool leftToRight(string, int, int);
bool rightToLeft(string, int, int);


int main(int argc, char const *argv[]){
	int choose;
	cout << "1.Triángulo de Pascal." << endl;
	cout << "2.Expansión del Binomio de Newton." << endl;
	cout << "3.Longest Collatz sequence (14)." << endl;
	cout << "4.Truncatable primes (37)." << endl;
	cout << "5.Self powers. (48)" << endl;
	cout << "-------------------" << endl;
	cout << "Usted escogió la opción: ";
	cin >> choose;
	cout << "-------------------" << endl;
	if(choose == 1 || choose == 2){
		int** triangle;
		int level;
		cout << "Ingrese el nivel: ";
		cin >> level;
		level =  (choose == 2)?level+1:level;
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
		int numero;
		cout<<"Ingrese el numero que desea evaluar: "<<endl;
		cin>>numero;
		while(numero!=1){
			cout<<numero<<">>";
			numero = evaluar(numero);
		}	
		if(numero == 1){
			cout<<numero<<endl;
		}
	}else if(choose == 4){
		string numero;
		cout<<"Ingrese el numero que desea evaluar: "<<endl;
		cin>>numero;	
		if(	leftToRight(numero , 0 , stringSize(numero)) && 
			rightToLeft(numero, 0 , stringSize(numero)-1)){
			cout<<"The number is a truncatable prime"<<endl;
		}else{
			cout<<"The number isn't a truncatable prime"<<endl;
		}	
	}else if(choose == 5){
		cout << "Result: " <<sumOfPowBases()<< endl;
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

bool isPrime(unsigned long long int number){
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

int evaluar(int num){
	if(num%2 == 0){
		return num/2;
	}else{
		return (num*3)+1;
	}
}

int stringSize(string word){
	int contador=0;
	int size=0;
	while(word[contador]!='\0'){
		size++;
		contador++;
	}

	return size;
}

bool leftToRight(string word, int first, int end){
	char evaluar[end-first];
	int contador=0;
	if(first == end-1){
		for(int i = first;i < end;i++){
			evaluar[contador]=word[i];
			contador++;
		}
		contador = 0;
		if(isPrime(atoi(evaluar))){
			return true;
		}
		else{
			return false;
		}
	}else{
		for(int i = first;i < end;i++){
			evaluar[contador]=word[i];
			contador++;
		}
		contador=0;
		if(isPrime(atoi(evaluar))){
			leftToRight(word,first+1,end);
		}else{
			return false;
		}
	}
}

bool rightToLeft(string word, int first, int end){
	char evaluar[(end+1)-first];
	int contador=end;
	if(end == first){
		for(int i = end;i >= first; i--){
			evaluar[contador]=word[i];
			contador--;
		}
		if(isPrime(atoi(evaluar))){
			return true;
		}else{
			return false;
		}
	}else{
		for(int i = end;i >=first;i--){
			evaluar[contador]=word[i];
			contador--;
		}
		if(isPrime(atoi(evaluar))){
			rightToLeft(word,first,end-1);
		}else{
			return false;
		}
	}
}

unsigned long long int sumOfPowBases(int limit){
	unsigned long long int result = 0;
	unsigned long long int modulo = 10000000000;
 
	for (unsigned long long int i = 1; i <= 1000; i++) {
    	unsigned long long int temp = i;
	    for (int j = 1; j < i; j++) {
	        temp *= i;
	        temp %= modulo;
	    }
	    result += temp;
	    result %= modulo;
	}

	return result;
}

