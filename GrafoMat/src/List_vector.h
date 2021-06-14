/*
 * List_vector.h
 *
 *  Created on: 1 ott 2020
 *      Author: peppi
 */

#ifndef LIST_VECTOR_H_
#define LIST_VECTOR_H_

#include "Linear_List.h"

//classe lista

template<class T>
//lista vector è sottoclasse di linearList son un solo segnaposto perche la posizione sarà un intero
class List_vector : public Linear_List<T, int>{

public:
	typedef typename Linear_List<T, int>::valore valore;
	typedef typename Linear_List<T,int>::posizione posizione;

	//aggiungo hai metodi della superclasse altri metodi

	//costruttori
	List_vector();
	List_vector(int);
	//costruttore copia
	List_vector(const List_vector<T>&);
	//distruttore
	~List_vector();

	//operatori
	void crea();
	bool vuoto()const;
	valore leggi(posizione)const;
	void scrivi(const valore &, posizione);
	posizione inizio()const;
	bool fine(posizione)const;
	posizione succ(posizione)const;
	posizione precc(posizione)const;
	void inserisci(const valore &, posizione);
	void cancella(posizione);

	// sovraccarico di operatori che si sostituiscono a quelli della superclasse
		List_vector<T>& operator=(const List_vector<T>&); // the assignment operator
		bool operator==(const List_vector<T> &) const; // tests two list for equality

private:
		void cambiaDimensione(T*&,int,int); //cambia dimensione
		valore *elemento;
		int lunghezza;
		int dim;


};

//costruttore con dimensione prefissata
template<class T>
List_vector<T>::List_vector(){
	dim=10;
	this->crea();
}

//costruttore   con dimensione iniziale
template<class T>
List_vector<T>::List_vector(int dim){
	this->dim=dim;
	this->crea();
}

/* Il costruttore per copia effettua una copia o clone di un oggetto.
 * Questo costruttore viene invocato, per esempio, quando un oggetto viene passato
 * per valore ad una funzione o quando una funzione restituisce un oggetto.
 */
template<class T>
List_vector<T>::List_vector(const List_vector<T>&Lista){
	this->dim=Lista.dim;
	this->lunghezza=Lista.lunghezza;
	this->elemento=new T[dim];
	for(int i=0; i<Lista.dim;i++){
		this->elemento[i]=Lista.elemento[i];
	}
}

//distruttore
template<class T>
List_vector<T>::~List_vector(){
	delete[] elemento;
}


//operatori
template<class T>
void List_vector<T>::crea(){
	this->elemento=new T[dim];
	this->lunghezza=0;
}

template<class T>
bool List_vector<T>::vuoto()const{
	return (lunghezza==0);
}

template<class T>
typename List_vector<T>::posizione List_vector<T>::inizio()const{
	return 1;
}

template<class T>
typename List_vector<T>::posizione List_vector<T>::succ(posizione p)const{
	if(0<p && p<lunghezza+1){		//precondizione
		return p+1;
	}else{
		return p;
	}
}

template<class T>
typename List_vector<T>::posizione List_vector<T>::precc(posizione p)const{
	if(1<p && p<lunghezza+1){	//precondizione
		return p-1;
	}else{
		return p;
	}
}

template<class T>
bool List_vector<T>::fine(posizione p)const{
	if( 0<p && p<=lunghezza+1){ //pre
		return p==lunghezza+1;
	}else{
		return false;
	}
}

template<class T>
typename List_vector<T>::valore List_vector<T>::leggi(posizione p)const{
	if(0<p && p<lunghezza+1){ //pre
		return elemento[p-1];
	}
}

template<class T>
void List_vector<T>::scrivi(const valore &a, posizione p){
	if(0<p && p<lunghezza+1){	//pre
		elemento[p-1]=a;
	}
}

template<class T>
void List_vector<T>::inserisci(const valore &a,posizione p ){

	if(lunghezza==dim){
		cambiaDimensione(elemento,dim,dim*2);
		dim=dim*2;
	}
	if(0<p && p<=lunghezza+1){//pree
		for(int i=lunghezza; i>=p; i--){
			elemento[i]=elemento[i-1];
		}
		elemento[p-1]=a;
		lunghezza++;
	}

}


template<class T>
void List_vector<T>::cancella(posizione p){
	if(0<p && p<lunghezza+1){
		if(!vuoto()){
			for(int i=p-1; i<lunghezza-1; i++){
				elemento[i]=elemento[i+1];
			}
			lunghezza--;
		}
	}
}

template<class T>
void List_vector<T>::cambiaDimensione(T*& a, int vecchiaDim, int nuovaDim){
	T* temp=new T[nuovaDim];
	int numero=0;
	if(vecchiaDim<nuovaDim){
		numero=vecchiaDim;
	}else{
		numero=nuovaDim;
	}
	for(int i=0; i<numero; i++){
		temp[i]=a[i];
	}
	delete[]a;
	a=temp;
}

/* operatore di assegnamento */
template<class T>
List_vector<T>& List_vector<T>::operator=(const List_vector<T>& l){
	if (this != &l){   // attenzione agli autoassegnamenti: l = l
		this->dim= l.dim;
		this->lunghezza = l.lunghezza;
		delete this->elemento;
		this->elemento = new T[dim];
		for (int i=0; i<dim; i++)
			this->elemento[i] = l.elemento[i];
	}
	return *this;
}

/* operatore di test di uguaglianza */
template<class T>
bool List_vector<T>::operator==(const List_vector<T> &l) const{
	if (l.lunghezza != this->lunghezza)
		return false;
  for (int i=0; i<this->dim; i++)
		if (this->elemento[i] != l.elemento[i])
			return false;
	return true;
}


#endif /* LIST_VECTOR_H_ */
