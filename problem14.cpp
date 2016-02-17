#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int evaluar(int);
int main(int argc, char*argv[]){
	int numero;

	cout<<"Ingrese el numero que desea evaluar: "<<endl;
	cin>>numero;
	
	while(numero!=1){
		cout<<numero<<">>";
		numero = evaluar(numero);
	}
	
	if(numero==1)
		cout<<numero<<endl;
	return 0;

}

int evaluar(int num){
	if(num%2==0){
		return num/2;
	}else{
		return (num*3)+1;
	}
}
