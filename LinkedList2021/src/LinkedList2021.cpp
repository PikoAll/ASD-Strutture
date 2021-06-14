//============================================================================
// Name        : LinkedList2021.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedList2021.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


	LinkedList<int> lista1,lista2,l3;
//	LinkedList<int>::posizione posizione;

	lista1.inserisci(1,lista1.inizio());
	lista1.inserisci(2,lista1.inizio());
	lista1.inserisci(3,lista1.inizio());
	lista1.inserisci(4,lista1.inizio());

	cout<<"Lista1 e: "<<lista1<<endl;

	lista2=lista1;

	cout<<endl;
	cout<<"Lista2 e: "<<lista2<<endl;

	if(lista1==lista2){
		cout<<"le liste sono uguali"<<endl;
	}else{
		cout<<"le liste sono diverse "<<endl;
	}

	lista2.cancella(lista2.inizio());


	cout<<"Lista2 e: "<<lista2<<endl;

		if(lista1==lista2){
			cout<<"le liste sono uguali"<<endl;
		}else{
			cout<<"le liste sono diverse "<<endl;
		}
///////////////////////////////////////////mio
		l3.inserisciOrdinatamente(5);
		l3.inserisciOrdinatamente(3);
		l3.inserisciOrdinatamente(7);
		l3.inserisciOrdinatamente(5);
		l3.inserisciOrdinatamente(5);
		l3.inserisciOrdinatamente(7);
		cout<<"lista 3  "<<l3;
		cout<<l3.cercaElemento(55)<<endl;
		cout<<l3.frequenzaMultipli(l3,5)<<endl;
		l3.stampaFrequenzaElementi(l3);
		cout<<endl;
		l3.elementiMaggiori(l3,4);

	return 0;
}
