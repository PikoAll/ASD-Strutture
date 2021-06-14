/*
 * GrafoList.h
 *
 *  Created on: 12 ott 2020
 *      Author: peppi
 */

#ifndef GRAFOLIST_H_
#define GRAFOLIST_H_

#include "Grafo.h"
#include "List_vector.h"

/**
	Questa realizzazione usa un vettore per tenere traccia di tutti quanti i nodi del grafo, ogni cella del vettore fa riferimento ad un'altra lista di nodi
	facenti parte alla lista degli adiacenti di ogni nodo.

	Inoltre è possibile creare dei grafi pesati, andando a specificare in fase di costruzione del grafo di che tipo si vuole il peso.

**/

class NodoG{

public:
	NodoG(int i){
		nodoId=i;	//indice nel vettore iniziale di tipo intero
	}
	NodoG(){}

	int getId(){return nodoId;} //restituisce la posizione nel vettore del nodo
	void setid(int id){nodoId=id; } //il grafo gli passa this		  //quando inserisco il nodo in un grafo, invoco il setID inserendo l'ID nel vettore dei nodi
	void setPuntatore(void* G){this->G=G;}
	void* getPuntatore(){return G;}

private:
	void* G;
	int nodoId;//l'ID rappresenta l'indice nel vettore

};


template<class P>
class InfoArco{

public:
	P peso;//peso dell'arco tra due nodi
	NodoG to;	//l'indice a cui punta l'arco nel vettore

};


template <class E, class P>
class InfoNodo{

public:
	E etichetta;   //etichetta del nodo
	bool vuoto;//status se vuoto o meno nel vettore dei nodi
	void* info;
	List_vector<InfoArco<P>>archi;  //lista degli archi di ogni nodo
	int archiEntranti;  //contiene il numero di archi entranti di un nodo. InsArco incrementa - CancArco decrementa

	InfoNodo(){
		info=0;	//setto info=0;
		vuoto=true;
		archiEntranti=0;
	}

};


template<class E, class P>
class GrafoList: public Grafo<E,P,NodoG>{

public:
	typedef E Etichetta;   //etichetta del nodo del grafo
	typedef P Peso;			//indica il peso dell'arco
	typedef NodoG Nodo;		//indica il nodo del grafo
	typedef Arco<Peso,Nodo> Arco;  //indica l'arco del grafo
	typedef Grafo<Etichetta,Peso,Nodo>Grafo_;  	//riferimento al grafo //------------DA CAPIRE------------
	typedef typename Grafo_::ListaNodi ListaNodi; //lista dei nodi del grafo
	typedef typename Grafo_::ListaNodiPosizione ListaNodiPosizione;  //indica il vettore di posizioni dei nodi

	GrafoList(int);
	~GrafoList();

	bool vuoto()const;
	void insNodo(NodoG &);
	void insArco(Nodo,Nodo,Peso);
	void cancNodo(Nodo);
	void cancArco(Nodo,Nodo);

	bool esisteArco(Nodo n1, Nodo n2) const; //controllo se esiste un arco che collega questi due nodi, controllando se il grafo è lo stesso
	bool esisteNodo(Nodo) const;

	ListaNodi Adiacenti(Nodo)const;
	ListaNodi listNodi()const;
	Etichetta leggiEtichetta(Nodo)const;
	void scriviEtichetta(Nodo,Etichetta);
	Peso leggiPeso(Nodo,Nodo)const;
	void scriviPeso(Nodo,Nodo,Peso);
	 void* getIndirizzo() {	return this;	}

	int numNodi(){
		return nodi;
	}

	int numArchi(){
		return archi;
	}

private:
	InfoNodo<E,P>* matrice;
	int dimensione;
	int nodi;
	int archi;




};

template<class E, class P>
  GrafoList<E, P>::GrafoList(int _dimensione)		//crea il vettore dei nodi, passando per input la dimensione massima
{
  dimensione = _dimensione;		//avvaloro la dimensione massima
  nodi = 0;		//setto il numero dei nodi presenti a 0
  archi = 0;		//setto il numero dei archi presenti a 0
  matrice = new InfoNodo<E,P>[dimensione];		//alloco un array di tipo InfoNodo di dimensione (DIMENSIONE)
  for (int i=0; i<dimensione; i++)		//per ohni nodo
  {
  	matrice[i].vuoto=true;	  //impostare a true il vuoto di tutti i nodi
  	matrice[i].archi.crea();		//Va a creare il riferimento alla lista degli archi
  }

}


template<class E, class P>
GrafoList<E,P>::~GrafoList(){
	delete [] matrice;
}

template<class E, class P>
bool GrafoList<E,P>::vuoto()const{
	return nodi==0;
}

template<class E, class P>
void GrafoList<E,P>::insNodo(NodoG & N){
	/*int n=0;
	if(nodi<dimensione){
		while(matrice[n].vuoto=false){
			n++;
		}
		nodi++;
		matrice[n].vuoto=false;
	}
	N.setid(n);*/
	int n = 0;		//inizializzo l'indice del vettore
	  if (nodi < dimensione)		//se il numero dei nodi effettivamente presenti è minore della dimensione massima
	  {
	    while (matrice[n].vuoto == false)		//fino a quando non trovo una posizione libera nella matrice
	      n++;		//incremento l' indice del vettore
	    nodi++;		//incremento il numero dei nodi occupati
	    matrice[n].vuoto = false;		//indico che la cella è utilizzata
	  }
	  matrice[n].archiEntranti=0;		//<---FATTO
	  N.setid(n);		//avvaloro l'ID del nodo N con la posizione nel vettore
	  N.setPuntatore(this);



}


template<class E, class P>
void GrafoList<E,P>::insArco(Nodo n1, Nodo n2,P peso){

	if(esisteNodo(n1)&&esisteNodo(n2))
		{
			InfoArco<P> I;		//dichiarazione dell'arco
			I.peso = peso;		//avvaloro il peso dell'arco che stiamo creando
			I.to = n2;			//avvaloro la destinazione dell'arco (il nodo entrante) con il riferimento a N2
			matrice[n1.getId()].archi.inserisci(I, matrice[n1.getId()].archi.inizio());		//vado in inserire l'arco nella lista degli archi uscenti del nodo N1

			//incrementare il numero dei nodi entranti di n2
			matrice[n2.getId()].archiEntranti++;				//<---FATTO

			archi++;		//incremento il numero degli archi presenti nel grafo
		}
		else
		{
			cout<<"I due nodi non appartengono allo stesso grafo"<<endl;
		}
}

template<class E, class P>
void GrafoList<E,P>::cancNodo(Nodo n){

	// ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
	  bool canc=true;
	  int i;
	  for(i=0; i<dimensione && canc; i++){
		  if(!matrice[n.getId()].archi.vuoto()){
			  canc=false;
		  }
	  }
	  if(canc){
		  matrice[n.getId()].vuoto=true;
	  }

}

template<class E, class P>
void GrafoList<E,P>::cancArco(Nodo n1,Nodo n2){

	typename List_vector<InfoArco<P>>::posizione p;
	p=matrice[n1.getId()].archi.inizio();
	bool trovato=false;
	while(!matrice[n1.getId()].archi.fine(p) && !trovato){
		if(matrice[n1.getId()].archi.leggi(p).to.getId()==n2.getId()){
			trovato=true;
		}else{
			p=matrice[n1.getId()].archi.succ(p);
		}
	}
	if(trovato){
		matrice[n1.getId()].archi.cancella(p);
	}
	archi--;

}

template<class E, class P>
typename GrafoList<E,P>::ListaNodi GrafoList<E,P>::Adiacenti(Nodo n)const{

	ListaNodi list;
	typename List_vector<InfoArco<P>>::posizione p;
	p=matrice[n.getId()].archi.inizio();
	while(!matrice[n.getId()].archi.fine(p)){
		list.inserisci(new NodoG(matrice[n.getId()].archi.leggi(p).to), list.inizio());
		p=matrice[n.getId()].archi.succ(p);

	}
	return list;

}

template<class E, class P>
typename GrafoList<E,P>::ListaNodi GrafoList<E,P>::listNodi()const{
	ListaNodi list;
	for(int i=0; i<dimensione;i++){
		if(!matrice[i].vuoto){
			list.inserisci(new NodoG(i),list.inizio());
		}
	}
	return list;
}

template<class E, class P>
  E GrafoList<E, P>::leggiEtichetta(Nodo n) const 		//leggi l'etichetta di un nodo
{
  return matrice[n.getId()].etichetta;				//restituisce l'etichetta di un nodo, passato per parametro
}

template<class E, class P>
void GrafoList<E,P>::scriviEtichetta(Nodo n, E etichetta){
	matrice[n.getId()].etichetta=etichetta;
}

template<class E, class P>
P GrafoList<E,P>::leggiPeso(Nodo n1, Nodo n2)const{
	typename List_vector<InfoArco<P>>::posizione p;
	p=matrice[n1.getId()].archi.inizio();
	bool trovato=false;
	while(!matrice[n1.getId()].archi.fine(p) && !trovato){
		if(matrice[n1.getId()].archi.leggi(p).to.getId()==n2.getId()){
			trovato=true;
		}else{
			p=matrice[n1.getId()].archi.succ(p);
		}
	}
	if(trovato){
		return matrice[n1.getId()].archi.leggi(p).peso;
	}

}


template<class E, class P>
void GrafoList<E,P>::scriviPeso(Nodo n1, Nodo n2, P peso){

	typename List_vector<InfoArco<P>>::posizione p;
	p=matrice[n1.getId()].archi.inizio();
	bool trovato=false;
	while(!matrice[n1.getId()].archi.fine(p) && !trovato){
		if(matrice[n1.getId()].archi.leggi(p).to.getId()==n2.getId()){
			trovato=true;
		}else{
			p=matrice[n1.getId()].archi.succ(p);
		}
	}
	if(trovato){
		InfoArco<P>I;
		I.peso=peso;
		I.to=n2;
		matrice[n1.getId()].archi.scrivi(I,p);
	}

}




template<class E, class P>
bool GrafoList<E,P>::esisteNodo(NodoG n)const{
	bool trovato=false;
		if(n.getPuntatore()==this && !matrice[n.getId()].vuoto)
		{

		int i;
		for(i=0;i<dimensione &&trovato==false;i++)
		{
			if(matrice[i].etichetta == matrice[n.getId()].etichetta)
			{
				trovato=true;
			}
		}
		}
		return trovato;
}

template<class E, class P>
  bool GrafoList<E, P>::esisteArco(NodoG n1, NodoG n2) const		//metodo esisteNodo del grafo
{
	typename List_vector<InfoArco<P> >::position p;
	bool trovato=false;
	int i;
	p=matrice[n1.getId()].archi.begin();
	while(!matrice[n1.getId()].archi.end(p) && !trovato)
	{
		if(matrice[n1.getId()].archi.read(p)._to.getId()==n2.getId())
		{
			trovato=true;
		}
		else
		{
			p = matrice[n1.getId()].archi.next(p);
		}
	}
	return trovato;
}









#endif /* GRAFOLIST_H_ */
