//============================================================================
// Name        : List_vector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "List_vector.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	List_vector<int> lista1,lista2;
	List_vector<int>::posizione pos;

	int x;
	x=1;
	lista1.inserisci(x,lista1.inizio());
	x=2;
	lista1.inserisci(x,lista1.inizio());
	lista1.inserisci(3,lista1.inizio());
	lista1.inserisci(4,lista1.inizio());

	cout<<"Lista 1 e: "<<lista1<<endl;

	lista2=lista1;

	cout<<"Lista2 e: "<<lista2<<endl;

	if(lista1==lista2){
		cout<<"le liste sono uguali"<<endl;
	}else{
		cout<<"le liste sono diverse"<<endl;
	}

	lista2.cancella(lista2.inizio());

	cout<<"Lista2 e: "<<lista2<<endl;

		if(lista1==lista2){
			cout<<"le liste sono uguali"<<endl;
		}else{
			cout<<"le liste sono diverse"<<endl;
		}

	return 0;
}
