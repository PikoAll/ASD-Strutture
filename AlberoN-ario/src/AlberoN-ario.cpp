 //============================================================================
// Name        : AlberoN-ario.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"Cella.h"
#include "Albero.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

/*
	 Albero<char> T;
	    typename Albero<char>::Nodo radice,n;
	    n=new Cella<char>;
	    radice=new Cella<char>;
	    T.insRadice(radice);
	    T.scriviNodo(T.radiceAlbero(),'a');
	    T.insPrimoFiglio(T.radiceAlbero());
	    T.scriviNodo(T.primoFiglio(T.radiceAlbero()),'b');
	    T.insFratello(T.primoFiglio(T.radiceAlbero()));
	    T.scriviNodo(T.succFratello(T.primoFiglio(T.radiceAlbero())),'c');
	    radice=T.primoFiglio(T.radiceAlbero());
	    T.insPrimoFiglio(radice);
	    T.scriviNodo(T.primoFiglio(radice),'d');
	    T.insFratello(T.primoFiglio(radice));
	    T.scriviNodo(T.succFratello(T.primoFiglio(radice)),'f');
	    T.insPrimoFiglio(T.succFratello(T.primoFiglio(T.radiceAlbero())));
	    T.scriviNodo(T.primoFiglio(T.succFratello(T.primoFiglio(T.radiceAlbero()))),'z');

	    T.stampaAlbero();
	     cout<<"\nL'altezza minimale dell'albero e':"<<T.altezzaMinima(T.radiceAlbero());
	    cout<<"\nStampa in pre-ordine dell'albero:";
	    T.stampaPreOrdine(T.radiceAlbero());
	    cout<<"\nStampa in post-ordine dell'albero:";
	    T.stampaPostOrdine(T.radiceAlbero());
	    cout<<"\nStampa simmetrica dell'albero:";
	    T.stampaSimmetrica(T.radiceAlbero());
	    T.contaNodi(T.radiceAlbero());
	    */
	 /*   cout<<"\nStampa in ampiezza dell'albero:";
	    T.stampaBFS(T.radiceAlbero());
	    cout<<"\nLa profondita' dell'albero e':"<<T.profondita(T.radiceAlbero());
	    cout<<"\nLa larghezza dell'albero e':"<<T.larghezza(T.radiceAlbero());
*/
	/*    Albero<int> T1;
	        typename Albero<int>::Nodo u;
	        u=new Cella<int>;
	        T1.insRadice(u);
	        T1.scriviNodo(T1.radiceAlbero(),4);
	        T1.insPrimoFiglio(T1.radiceAlbero());
	        T1.scriviNodo(T1.primoFiglio(T1.radiceAlbero()),6);
	        T1.insFratello(T1.primoFiglio(T1.radiceAlbero()));
	        T1.scriviNodo(T1.succFratello(T1.primoFiglio(T1.radiceAlbero())),8);
	        T1.insFratello(T1.succFratello(T1.primoFiglio(T1.radiceAlbero())));
	        T1.scriviNodo(T1.succFratello(T1.succFratello(T1.primoFiglio(T1.radiceAlbero()))),2);
	        u=T1.primoFiglio(T1.radiceAlbero());
	        T1.insPrimoFiglio(u);
	        T1.scriviNodo(T1.primoFiglio(u),2);
	        T1.insFratello(T1.primoFiglio(u));
	        T1.scriviNodo(T1.succFratello(T1.primoFiglio(u)),2);
	        T1.insPrimoFiglio(T1.succFratello(T1.primoFiglio(T1.radiceAlbero())));
	        T1.scriviNodo(T1.primoFiglio(T1.succFratello(T1.primoFiglio(T1.radiceAlbero()))),4);

	        T1.stampaAlbero();
	 //       cout<<"\nStampa in ampiezza dell'albero:";
	   //     T1.stampaBFS(T1.radiceAlbero());
	        cout<<"\nIl livello del primo figlio della radice e':"<<T1.livello(T1.primoFiglio(T1.radiceAlbero()));
	        int somma=0;
	        T1.foglieK(T1.radiceAlbero(),somma,12);
	        T1.stampaAlbero();
	   //     cout<<"\nStampa in ampiezza dell'albero:";
	 //       T1.stampaBFS(T1.radiceAlbero());
	        cout<<"\nIl numero di foglie presenti nell'albero e':"<<T1.numeroFoglie(T1.radiceAlbero());
//	        cout<<"\nIl valore massimo dell'albero e':"<<T1.maxAlbero(T1.radiceAlbero());		//////////////////////////////////////////////////////
	        cout<<"\nL'altezza dell'albero e':"<<T1.altezza(T1.radiceAlbero());
	        int k=2;
//	        cout<<"\nIl numero di nodi con 2 figli e':"<<T1.nodiKfigli(T1.radiceAlbero(),k);	///////////////////////////////////////////////////////////
	        if(T1.tuttiPari(T1.radiceAlbero())){
	            cout<<"\nTutti pari";
	        }
	        int h=2;
	        int numero=0;
	        T1.nLivello(T1.radiceAlbero(),h,numero);
	        cout<<"\nIl numero di nodi di livello "<<h<<" e':"<<numero;
	        cout<<"\nL'altezza minimale dell'albero e':"<<T1.altezzaMinima(T1.radiceAlbero());
	        T1.cancellaPrimoFiglio(T1.radiceAlbero());
	        //T1.cancellaSuccFratello(T1.primoFiglio(T1.radiceAlbero()));
	        T1.stampaAlbero();
	        if(T1.pariDispari(T1.radiceAlbero()))
	            cout<<"\nOgni nodo pari ha solo figli dispari";
	        else
	            cout<<"\nNon tutti i nodi pari hanno solo figli dispari";

*/

	Albero<int> a;
	typename Albero<int>::Nodo n,n1,n2,n3,n4,n5;
	n=new Cella<int>;
//	n1=new Cella<int>;

	a.insRadice(n);
	a.scriviNodo(n,1);
	a.insPrimoFiglio(n);
	a.scriviNodo(a.primoFiglio(n),2);

	n1=a.primoFiglio(n);

	a.insFratello(a.primoFiglio(n));
	a.scriviNodo(a.succFratello(a.primoFiglio(n)),3);

	n2=a.succFratello(a.primoFiglio(n));

	a.insFratello(a.succFratello(a.primoFiglio(n)));
	a.scriviNodo(a.succFratello(a.succFratello(a.primoFiglio(n))),4);

	n3=a.succFratello(a.succFratello(a.primoFiglio(n)));

	a.insFratello(a.succFratello(a.succFratello(a.primoFiglio(n))));
	a.scriviNodo(a.succFratello(a.succFratello(a.succFratello(a.primoFiglio(n)))),5);

	n4=a.succFratello(a.succFratello(a.succFratello(a.primoFiglio(n))));


	a.insPrimoFiglio(n1);
	a.scriviNodo(a.primoFiglio(n1),6);
	a.insFratello(a.primoFiglio(n1));
	a.scriviNodo(a.succFratello(a.primoFiglio(n1)),7);

	n1=a.primoFiglio(n1);
	a.insPrimoFiglio(n1);
	a.scriviNodo(a.primoFiglio(n1),16);
	a.insPrimoFiglio(a.primoFiglio(n1));
	a.scriviNodo(a.primoFiglio(a.primoFiglio(n1)),23);

	a.insFratello(a.primoFiglio(n1));
	a.scriviNodo(a.succFratello(a.primoFiglio(n1)),17);

	a.insFratello(a.succFratello(a.primoFiglio(n1)));
	a.scriviNodo(a.succFratello(a.succFratello(a.primoFiglio(n1))),18);

	a.insPrimoFiglio(n2);
	a.scriviNodo(a.primoFiglio(n2),8);

	a.insFratello(a.primoFiglio(n2));
	a.scriviNodo(a.succFratello(a.primoFiglio(n2)),9);

	a.insFratello(a.succFratello(a.primoFiglio(n2)));

	a.scriviNodo(a.succFratello(a.succFratello(a.primoFiglio(n2))),10);

	a.insPrimoFiglio(a.primoFiglio(n2));
	a.scriviNodo(a.primoFiglio(a.primoFiglio(n2)),19);
	a.insFratello(a.primoFiglio(a.primoFiglio(n2)));
	a.scriviNodo(a.succFratello(a.primoFiglio(a.primoFiglio(n2))),20);

	a.insPrimoFiglio(n4);
	a.scriviNodo(a.primoFiglio(n4),15);

	a.insPrimoFiglio(a.primoFiglio(n4));
	a.scriviNodo(a.primoFiglio(a.primoFiglio(n4)),21);
	a.insFratello(a.primoFiglio(a.primoFiglio(n4)));
	a.scriviNodo(a.succFratello(a.primoFiglio(a.primoFiglio(n4))),22);

	a.stampaAlbero();

/*	int x=0;
	a.nLivello(n,3,x);
	cout<<x;
	*/////////////////////////////////////////////////////////
/*	cout<<a.maxLevel(a)<<endl;
	a.padreSommaFigli(a.radiceAlbero());
	a.stampaAlbero();
*/
	//a.padreSommaFigli(a.radiceAlbero());
	cout<<endl<<endl;
	a.padreSommaFigli2(a.radiceAlbero());
	a.stampaAlbero();

	return 0;
}
