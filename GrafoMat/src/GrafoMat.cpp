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
#include "Grafo.h"
#include <string>
#include "GrafoMat.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
/////////////////////////////////////////////////////////////////////////
    ///GRAFO MAT

	cout<<"\n\n\nGrafoMat\n\n\n";
    /*	GrafoMat<string,double> G(10);

    	NodoG n1,n2,n3,n4,n5,n6;

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



    	G.insArco(n1,n2, 1.0);
    	G.insArco(n1,n3, 0.9);
    	G.insArco(n1,n5, 0.3);
    	G.insArco(n2,n4, 0.1);
    	G.insArco(n2,n6, 0.2);
    	G.insArco(n3,n4, 1.0);
    	G.insArco(n3,n6, 0.7);
    	G.insArco(n4,n1, 0.5);
    	G.insArco(n5,n2, 0.4);
    	G.insArco(n5,n3, 0.2);
    	G.insArco(n6,n4, 0.1);

    //	cout<<G.esisteArco(n1,n2);
    	cout << "\nNumNodi " << G.numNodi();
    	cout << "\nNumArchi " << G.numArchi();

    	G.cancNodo(n6);

    	cout << "\nNumNodi " << G.numNodi();

    	GrafoMat<string,double>::ListaNodi Ll = G.Adiacenti(n1);

    	GrafoMat<string,double>::ListaNodiPosizione pp;


    	cout << "\nAdiacenti di " << G.leggiEtichetta(n1) << "--> ";
    	pp = Ll.inizio();
    	while (!Ll.fine(pp)){
    		cout <<  G.leggiEtichetta(*(Ll.leggi(pp))) << " ";
    		pp = Ll.succ(pp);
    	}

    	cout << endl;

    	*/
/*
	GrafoMat<string,int> g(15);
	NodoG n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
	g.insNodo(n1);
	g.scriviEtichetta(n1,"verde1");  //verde1
	g.insNodo(n2);
	g.scriviEtichetta(n2,"verde2");
	g.insNodo(n3);
	g.scriviEtichetta(n3,"verde3");
	g.insNodo(n4);
	g.scriviEtichetta(n4,"bianco4");
	g.insNodo(n5);
	g.scriviEtichetta(n5,"bianco5");
	g.insNodo(n6);
	g.scriviEtichetta(n6,"bianco6");
	g.insNodo(n7);
	g.scriviEtichetta(n7,"rosso7");
	g.insNodo(n8);
	g.scriviEtichetta(n8,"rosso8");
	g.insNodo(n9);
	g.scriviEtichetta(n9,"rosso9"); //rosso9
	g.insNodo(n10);
	g.scriviEtichetta(n10,"bianco10");
	*/

	GrafoMat<int,int> g(15);
	NodoG n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
	g.insNodo(n1);
	g.scriviEtichetta(n1,1);  //verde1
	g.insNodo(n2);
	g.scriviEtichetta(n2,2);
	g.insNodo(n3);
	g.scriviEtichetta(n3,3);
	g.insNodo(n4);
	g.scriviEtichetta(n4,4);
	g.insNodo(n5);
	g.scriviEtichetta(n5,5);
	g.insNodo(n6);
	g.scriviEtichetta(n6,6);
	g.insNodo(n7);
	g.scriviEtichetta(n7,7);
	g.insNodo(n8);
	g.scriviEtichetta(n8,8);
	g.insNodo(n9);
	g.scriviEtichetta(n9,9); //rosso9
	g.insNodo(n10);
	g.scriviEtichetta(n10,10);

	g.insArco(n1,n2,1);
	g.insArco(n1,n8,1);
	g.insArco(n1,n7,1);
	g.insArco(n1,n6,1);

	g.insArco(n8,n3,1);
	g.insArco(n8,n9,1);
	g.insArco(n8,n7,1);

	g.insArco(n9,n5,1);
	g.insArco(n9,n10,1);

	g.insArco(n5,n4,1);
	g.insArco(n5,n3,1);
	g.insArco(n7,n9,1);

//	g.insArco(n9,n8,1);

	cout<<"adiacenti "<<g.leggiEtichetta(n1)<<" :";

	GrafoMat<string,double>::ListaNodi l = g.Adiacenti(n1);

	GrafoMat<string,double>::ListaNodiPosizione p;

	p=l.inizio();



	while(!l.fine(p)){
		cout<<" "<<g.leggiEtichetta(*l.leggi(p))<<" ";
		p=l.succ(p);
	}

	cout<<endl;
	cout<<"adiacenti "<<g.leggiEtichetta(n8)<<" : ";
	GrafoMat<string,double>::ListaNodi l2=g.Adiacenti(n8);

	p=l2.inizio();

	while(!l2.fine(p)){
     	cout<<" "<<g.leggiEtichetta(*l2.leggi(p))<<" ";
		p=l2.succ(p);
	}

	cout<<"\nprova tutti gli elementi della lista\n";
	l=g.list_nodi();
	p=l.inizio();
	while(!l.fine(p)){
	     	cout<<" "<<g.leggiEtichetta(*l.leggi(p))<<" ";
			p=l.succ(p);
		}
	cout<<endl<<endl<<"entriamo \n\n";
//	bool fl=g.sameColorpath(n1,n4);		//n8 n1 per marcato
	g.settaNoMarcati();
 //	bool fl=g.uniformColorPath(n1,n4);

//	cout<<"\n\n"<<fl;
//	g.mediaLunghezzaCammini(n1,n4);
//	g.countSame(n1);

	g.meanN2(n2);

//	system("pause");
	return 0;
}
