/*
 * Grafo.cpp
 *
 *  Created on: 13 ott 2020
 *      Author: peppi
 */




//============================================================================
// Name        : Grafo.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "GrafoList.h"
#include "Grafo.h"
#include <string>


using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
/*

	//vado a creare un grafo di elementi di tipo stringa e come pesi numeri interi
	GrafoList<string,int> G(10);		//il grafo avrà 10 elementi

	//vado a creare i nodi del grafo
	NodoG n1,n2,n3,n4,n5,n6,n7;

	//vado ad inserire i nodi nel grafo e successivamente vado ad avvalorare le loro etichette
	G.insNodo(n1);
	G.scriviEtichetta(n1,"a");
	G.insNodo(n2);
	G.scriviEtichetta(n2,"b");
	G.insNodo(n3);
	G.scriviEtichetta(n3,"c");
	G.insNodo(n4);
	G.scriviEtichetta(n4,"d");
	G.insNodo(n5);
	G.scriviEtichetta(n5,"e");
	G.insNodo(n6);
	G.scriviEtichetta(n6,"f");
	G.insNodo(n7);
	G.scriviEtichetta(n7,"g");


	//vado a creare gli archi tra i vari nodi
	G.insArco(n1,n3,1);		//a con c
	G.insArco(n1,n4,2);		//a con d
	G.insArco(n1,n6,1);		//a con f

	G.insArco(n3,n6,1);		//c con f
	G.insArco(n3,n1,1);		//c con a

	G.insArco(n6,n3,1);		//f con c
	G.insArco(n6,n4,1);		//f con d
	G.insArco(n6,n1,1);		//f con a

	G.insArco(n4,n1,1);		//d con a
	G.insArco(n4,n6,1);		//d con f
	G.insArco(n4,n2,1);		//d con b
	G.insArco(n4,n5,1);		//d con e

	G.insArco(n2,n4,1);		//b con d
	G.insArco(n2,n5,1);		//b con e

	G.insArco(n5,n4,1);		//e con d
	G.insArco(n5,n2,1);		//e con b

	cout<<"Il numero di nodi del grafo e': "<<G.numNodi()<<endl;
	cout<<"Il numero di archi del grafo e': "<<G.numArchi()<<endl;


	GrafoList<string,double>::ListaNodi L = G.Adiacenti(n1);		//creazione di una lista di nodi adiacenti, partendo da N1
	GrafoList<string,double>::ListaNodiPosizione p;					//dichiarazione di un puntatore posizionale P alla lista dei nodi
	cout << "Adiacenti di " << G.leggiEtichetta(n1) << "--> ";		//stampa adiacenti del nodo N1
	p = L.inizio();													//Posiziono p all'inizio della lista
	while (!L.fine(p))												//fino a quando non arrivo alla fine della lista
	{
		cout <<  G.leggiEtichetta(*(L.leggi(p))) << " ";			//stampo l'etichetta di ogni nodo adiacente
		p = L.succ(p);							 				//incremento il puntatore
    }
    cout<<endl;


	L=G.Adiacenti(n2);
    cout << "Adiacenti di " << G.leggiEtichetta(n2) << "--> ";
    p=L.inizio();
    while (!L.fine(p))												//fino a quando non arrivo alla fine della lista
	{
		cout <<"gg=" << G.leggiEtichetta(*(L.leggi(p))) << " ";			//stampo l'etichetta di ogni nodo adiacente
		p = L.succ(p);											//incremento il puntatore
    }

    cout<<endl;

    cout<<"Il peso dell'arco che va da "<<G.leggiEtichetta(n1)<<" a "<<G.leggiEtichetta(n2)<<" e': "<<G.leggiPeso(n1,n3)<<endl;
*/




	GrafoList<string,double> G(10);		//DICHIARO UN GRAFO DI TIPO STRINGA

	GrafoList<string,double> G2(20);
	NodoG ng2;

	G2.insNodo(ng2);
	cout<<"STAMPO INDIRIZZO DEL GRAFO 2: "<<&G2<<endl;
	cout<<"STAMPO INDIRIZZO DI NG2: "<<ng2.getPuntatore()<<endl;

	NodoG n1,n2,n3,n4,n5,n6;			//DICHIARAZIONE DI DIFFERENTI NODI n1, n2, n3, n4, n5, n6

	if(G.vuoto()==true) cout<<"Il grafo risulta essere vuoto"<<endl;
	else cout<<"Il grafo non e' vuoto"<<endl;

	G.insNodo(n1);						//Al grafo inserisco il Nodo n1
	G.scriviEtichetta(n1,"a");			//Avvaloro l'etichetta n1 con la stringa "a"
	G.insNodo(n2);						//Al grafo inserisco il Nodo n2
	G.scriviEtichetta(n2,"b");			//Avvaloro l'etichetta n2 con la stringa "b"
	G.insNodo(n3);						//Al grafo inserisco il Nodo n3
	G.scriviEtichetta(n3,"c");			//Avvaloro l'etichetta n3
	G.insNodo(n4);						//Al grafo inserisco il Nodo n4
	G.scriviEtichetta(n4,"d");			//Avvaloro l'etichetta n4
	G.insNodo(n5);						//Al grafo inserisco il Nodo n5
	G.scriviEtichetta(n5,"e");			//Avvaloro l'etichetta n5
	G.insNodo(n6);						//Al grafo inserisco il Nodo n6
	G.scriviEtichetta(n6,"f");			//Avvaloro l'etichetta n6

	if(G.vuoto()==true) cout<<"Il grafo risulta essere vuoto"<<endl;
	else cout<<"Il grafo non e' vuoto"<<endl;


	//DEFINIZIONE DEGLI ARCHI TRA I NODI E I RELATIVI PESI
	G.insArco(n1,n2, 1.0);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n1,n3, 0.9);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n1,n5, 0.3);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n2,n4, 0.1);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n2,n6, 0.2);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n3,n4, 1.0);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n3,n6, 0.7);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n4,n1, 0.5);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n5,n2, 0.4);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n5,n3, 0.2);				//Inserisco un arco tra due nodi e ne inserisco il peso
	G.insArco(n6,n4, 0.1);				//Inserisco un arco tra due nodi e ne inserisco il peso
	cout<<G.esisteArco(n1,n2);
	cout << "\nNumNodi " << G.numNodi();		//stampa il numero di nodi presenti nel grafo
	cout << "\nNumArchi " << G.numArchi();		//stampa il numero di archi presenti nel grafo

	//CANCELLAZIONE DI UN NODO
	G.cancNodo(n6);

	cout << "\nNumNodi " << G.numNodi() << endl;

	GrafoList<string,double>::ListaNodi L = G.Adiacenti(n1);		//creazione di una lista di nodi adiacenti, partendo da N1

	GrafoList<string,double>::ListaNodiPosizione p;					//dichiarazione di un puntatore posizionale P alla lista dei nodi


	cout << "Adiacenti di " << G.leggiEtichetta(n1) << "--> ";		//stampa adiacenti del nodo N1
	p = L.inizio();													//Posiziono p all'inizio della lista
	while (!L.fine(p))												//fino a quando non arrivo alla fine della lista
	{
		cout <<  G.leggiEtichetta(*(L.leggi(p))) << " ";			//stampo l'etichetta di ogni nodo adiacente
		p = L.succ(p);											//incremento il puntatore
    }
    cout<<endl;

    //TEST ESISTE ETICHETTA
    bool e_n=G.esisteNodo(n1);
    if(e_n)
    {
    	cout<<"Il nodo esiste"<<endl;
	}
	else
	{
		cout<<"Il nodo non esiste"<<endl;
	}

    //STAMPO INDIRIZZO DEL GRAFO
    cout<<"INDIRIZZO DEL GRAFO: "<<&G<<endl;
    cout<<n1.getPuntatore()<<endl;

    G.insArco(n2,ng2,5);

    //TEST ESISTE ARCO
    bool esiste=G.esisteArco(n1,n4);
    if(esiste)
    {
    	cout<<"ESISTE UN ARCO!"<<endl;
	}
	else
	{
		cout<<"NON ESISTE UN ARCO TRA I DUE NODI INSERITI"<<endl;
	}

	//TEST VERIFICA ESISTENODO - CANCELLAZIONE DEL NODO - NUOVA VERIFICA ESISTENODO (solo se un nodo ha nodi uscenti)
	e_n=G2.esisteNodo(ng2);
    if(e_n)
    {
    	cout<<"Il nodo esiste"<<endl;
	}
	else
	{
		cout<<"Il nodo non esiste"<<endl;
	}
	G2.cancNodo(ng2);
	e_n=G2.esisteNodo(ng2);
    if(e_n)
    {
    	cout<<"Il nodo esiste"<<endl;
	}
	else
	{
		cout<<"Il nodo non esiste"<<endl;
	}




	return 0;
}
