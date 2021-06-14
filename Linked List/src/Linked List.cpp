//============================================================================
// Name        : Linked.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedList.h"
#include "Recommender.h"
using namespace std;

int main() {
	cout << "!!!Hello World Linked List!!!" << endl; // prints !!!Hello World!!!

	LinkedList<int> lista1,lista2;
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

	//Metodi aggiuntivi
		LinkedList<int> l;
		l.inserisci(1,l.inizio());
		l.inserisci(2,l.inizio());
		l.inserisci(3,l.inizio());
		l.inserisci(4,l.inizio());
	//	l.inserisci(5,l.inizio());
		cout<<"\nmetodi aggiuntivi lista e:"<<l<<endl;
		l.inverti(l);
		cout<<"\n"<<l;

	//analizzo palindroma
		LinkedList<int>l1;
		l1.inserisci(1,l1.inizio());
		l1.inserisci(2,l1.inizio());
		l1.inserisci(2,l1.inizio());
	//	l1.inserisci(3,l1.inizio());
		l1.inserisci(1,l1.inizio());
		cout<<"\ne palindroma? :"<<l1.palindroma(l1)<<endl;
	//inserisci ordinatamente
		LinkedList<int>l2;
		l2.inserisciOrdinatamente(4);
		l2.inserisciOrdinatamente(5);
		l2.inserisciOrdinatamente(6);
		l2.inserisciOrdinatamente(3);
		l2.inserisciOrdinatamente(2);
		l2.inserisciOrdinatamente(7);
		l2.inserisciOrdinatamente(1);
		cout<<"\n"<<l2;
		cout<<"\n"<<l2.cercaElemento(9);
		cout<<"\n"<<l2.cercaElemento(7);

	//	cout<<"\n"<<l2.trovaElemento(5);

//frequenza multipli  e stampo anche la frequenza dei singoli elementi il l3 la frequenza e fatta un po male
		LinkedList<int> l3;
		l3.inserisci(12,l3.inizio());
		l3.inserisci(4,l3.inizio());
		l3.inserisci(6,l3.inizio());
		l3.inserisci(4,l3.inizio());
		l3.inserisci(12,l3.inizio());
		l3.inserisci(20,l3.inizio());
		l3.inserisci(12,l3.inizio());
		l3.inserisci(12,l3.inizio());
		l3.inserisci(4,l3.inizio());
		cout<<"\nfrequenza: "<<l3.frequenzaMultipli(l3,3)<<endl;
		l3.stampaFrequenzaElemnetiInL(l3);

/////////////////////////////////////////////////////////////////////
/*cout<<endl;
Recommender r;
r.inserisci("dan","suc",85);
r.inserisci("gn","sugo",75);

r.stampa();
*/
		cout<<endl<<"Lab1"<<endl;
		cout<<l3<<endl;
		l3.ElementiMaggiori(l3,6);



	return 0;
}
