/*
 * Pila.h
 *
 *  Created on: 6 ott 2020
 *      Author: peppi
 */

#ifndef PILA_H_
#define PILA_H_

#include<iostream>
#include <cstdlib>
using namespace std;

template<class T>
class Pila;

template<class T>
class Nodo{
public:
	friend class Pila<T>;
	template<class tp>
	friend ostream& operator <<(ostream&, const Pila<tp>&);
	Nodo(){
		succ=nullptr;
		precc=nullptr;
	}

private:
	Nodo *succ;
	Nodo *precc;
	T valore;

};
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class Pila{

public:
	Pila();
	Pila(const Pila<T>& p);
	~Pila();

	bool vuota()const;
	int size()const;
	void inPilaFront(T);
	void inPilaBack(T);
	void fuoriPilaFront();
	void fuoriPilaBack();
	T leggiPila()const;
	T bot()const;

	Pila<T> operator=(const Pila<T>&);
	template<class tp>
	friend ostream& operator<<(ostream&, const Pila<tp>&);

	//esercizi
	/*
	 * Data una pila di interi, implementare in C++ una funzione che restituisca una nuova pila i cui elementi
	   corrispondano a quelli presenti nella pila data e siano ordinati dall’alto (top dello stack) al basso.
	   Prevedere una funzione nel main che contenga una procedura di inserimento automatico e successivamente il test della funzione implementata
	 */
	Pila<int> ordinaPila(Pila<int>);
	void stampaPila(Pila);
	/*
	 * Data una pila di elementi di tipo intero, implementare un metodo in C++ che elimini dalla pila
		tutti gli elementi maggiori di un certo intero k (l’ordinamento degli elementi della pila risultante deve
		corrispondere a quello della pila data in input).
		Prevedere una funzione main che contenga una procedura di inserimento automatico e successivamente
		il test dei metodi implementati.
	 */
	void eliminaMaggioreDi(Pila& , int);

private:
	Nodo<T> *testa;
	Nodo<T>*coda;
	int s;

};

template<class T>
Pila<T>::Pila(){
	testa=nullptr;
	coda=nullptr;
	s=0;
}

template<class T>
Pila<T>::Pila(const Pila<T>& p){
	s=0;
	testa=nullptr;
	coda=nullptr;
	Nodo<T>*tmp=p.testa;

	while(tmp!=nullptr){
		inPilaFront(tmp->valore);
		tmp=tmp->succ;
	}
}


template<class T>
Pila<T>::~Pila(){
	while(!vuota()){
		fuoriPilaFront();
	}
}

template<class T>
bool Pila<T>::vuota()const{
	return testa==nullptr;
}


template<class T>
int Pila<T>::size()const{
	return s;
}

template<class T>
void Pila<T>::inPilaFront(T v){
	Nodo<T> *tmp=new Nodo<T>;
	tmp->valore=v;

	if(vuota()){
		testa=coda=tmp;
	}else{
		testa->precc=tmp;
		tmp->succ=testa;
		testa=tmp;
	}
	s++;
}

template<class T>
void Pila<T>::inPilaBack(T v){

	Nodo<T>*tmp=new Nodo<T>;
	tmp->valore=v;

	if(vuota()){
		testa=coda=tmp;
	}else{
		coda->succ=tmp;
		tmp->precc=coda;
		coda=tmp;
	}
	s++;

}

template<class T>
void Pila<T>::fuoriPilaFront(){
	if(size()==1){
		s--;
		delete testa;
		testa=nullptr;
		coda=nullptr;
	}else if(!vuota()){
		Nodo<T> *tmp=testa;
		testa->succ->precc=nullptr;
		testa=testa->succ;
		delete tmp;
		s--;
	}
}


template<class T>
void Pila<T>::fuoriPilaBack(){

	if(size()==1){
		s--;
		delete coda;
		testa=nullptr;
		coda=nullptr;
	}else if(!vuota()){
		Nodo<T> *tmp=coda;
		coda->precc->succ=nullptr;
		coda=coda->precc;
		delete tmp;
		s--;
	}

}

template<class T>
T Pila<T>::leggiPila()const{
	return testa->valore;
}

template<class T>
T Pila<T>::bot()const{
	coda->valore;
}

template<class T>
Pila<T> Pila<T>::operator=(const Pila<T>& dp){

    if (this==&dp) return *this;
    while(!vuota()) fuoriPilaBack();

    Nodo<T>*tmp=dp.testa;

    while(tmp!=nullptr){
    	inPilaBack(tmp->valore);
      tmp=tmp->succ;
    }

    return *this;
}

template<class tp>
ostream& operator<<(ostream&os, const Pila<tp>&q){

  os<<"[ ";
  if (!q.vuota()){
    Nodo<tp>* tmp = q.testa;

    while(tmp->succ!=nullptr){
      os<<tmp->valore<<", ";
      tmp=tmp->succ;
    }
    os<<tmp->valore;
  }
  os<<"]"<<endl;
  return os;
}


template<class T>
Pila<int> Pila<T>::ordinaPila(Pila<int> pila){

	cout<<"ciao";
	int x=pila.size();
	int v[x];
	int i=0;
	while(!pila.vuota()){

		v[i]=pila.leggiPila();
		pila.fuoriPilaFront();
		i++;

	}

	for(int i=0; i<x; i++){
			int k=i;
			for(int j=i+1; j<x;j++){
				if(v[j]<v[k]){
					k=j;
				}
			}
			if(k!=i){
				int temp=v[i];
				v[i]=v[k];
				v[k]=temp;
			}
		}

for(int i=0; i<x; i++){

	pila.inPilaFront(v[i]);

}
return pila;

}

template<class T>
void Pila<T>::stampaPila(Pila pila){

	int x=pila.size();
		int v[x];
		int i=0;
		while(!pila.vuota()){

			v[i]=pila.leggiPila();
			pila.fuoriPilaFront();
			i++;

		}
	cout<<"elementi della pila"<<endl;

	for(int i=0; i<x; i++){
		cout<<v[i]<<endl;
	}
}

template<class T>
void Pila<T>::eliminaMaggioreDi(Pila &pila, int k){
	int x=pila.size();
	int v[x];
	int i=0;
	while(!pila.vuota()){
		v[i]=pila.leggiPila();
		pila.fuoriPilaFront();
		i++;

	}

	for(int i=0; i<x;i++){
		if(v[i]<k){
			pila.inPilaFront(v[i]);
		}
	}
}


#endif /* PILA_H_ */
