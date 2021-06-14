//============================================================================
// Name        : Coda.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Coda.h"
#include "Esercizio.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!! Coda puntatori" << endl; // prints !!!Hello World!!!

	Coda<int> C;

	  C.inCoda(1);
	  C.inCoda(2);
	  C.inCoda(5);
	  C.inCoda(3);
	  C.inCoda(0);
	  C.inCoda(7);
	  C.inCoda(4);
	  C.inCoda(-2);
	  C.print();

	  cout<<"Laboratorio 6";
	  Coda<int>c;
	  c=C.soloPositivi(C);
	  c.print();




	  cout<<"----------------------------------";
	/*  cout << " " << C.leggiCoda();
	  C.fuoriCoda();
	  C.inCoda(4);
	  cout << " " << C.leggiCoda();
	  C.fuoriCoda();
	  cout << " " << C.leggiCoda();
	  C.inCoda(5);
	  C.fuoriCoda();
	  cout << " " << C.leggiCoda();
	  C.fuoriCoda();
	  cout << " " << C.leggiCoda();
	  C.fuoriCoda();
*/
	  C.cancellaMinimo(C);
	  C.stampaCoda(C);
	  cout<<endl<<endl;
/////////////////////////////////////////////////
	  Esercizio e;

	  e.inserisci(5);
	  e.inserisci(9);
	  e.inserisci(7);
	  e.inserisci(3);
	  e.inserisci(1);
	  e.inserisci(2);
	  e.inserisci(8);
	  e.inserisci(6);
	  e.inserisci(4);

	  e.stampa(1);
	  e.stampa(2);
	  e.stampa(3);

	  cout<<e.numeroElementi(1)<<endl;
	  e.cancella(3);
	  cout<<e.numeroElementi(3)<<endl;
	  cout<<e.media(2);

	  e.stampa(1);
	  e.stampa(2);
	  e.stampa(3);

	return 0;
}
