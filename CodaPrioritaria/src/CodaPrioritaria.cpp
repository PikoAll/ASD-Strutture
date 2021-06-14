//============================================================================
// Name        : CodaPrioritaria.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Nella teoria delle code, una coda di priorità è una struttura dati astratta, simile ad una coda o ad una pila, ma diversa da queste in quanto ogni elemento
 * inserito all'interno della coda possiede una sua "priorità". In una coda di priorità, ogni elemento avente priorità più alta, viene inserito prima rispetto ad
 *  un elemento avente priorità più bassa. In particolare, l'elemento con priorità più alta si trova in testa alla coda, quello con priorità più bassa si troverà,
 *   appunto, in coda
 */

#include <iostream>
#include "Coda.h"
using namespace std;

int main() {
	cout << "!!!Hello World Coda Prioritaria!!!" << endl; // prints !!!Hello World!!!

	Coda < int > C;

	  C.inserisci (1);
	  C.inserisci (12);
	  C.inserisci (19);
	  C.inserisci (7);
	  cout<<C.min()<<endl;
	  C.cancellaMin ();

	  C.inserisci (0);
	  C.inserisci (11);
	  cout<<C.min()<<endl;
	  C.cancellaMin ();

	  C.inserisci (5);
	  C.inserisci (21);
	  C.inserisci (18);
	  cout<<C.min()<<endl;
	  C.cancellaMin ();


	  C.inserisci (3);
	  cout<<C.min()<<endl;
	  C.cancellaMin ();

	return 0;
}
