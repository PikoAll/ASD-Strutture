/*
 * Cella.h
 *
 *  Created on: 10 ott 2020
 *      Author: peppi
 */

#ifndef CELLA_H_
#define CELLA_H_

#include<iostream>

template<class T>
class Cella{
public:
	typedef T tipoelem;
	Cella();
	Cella(tipoelem);

	void setElemento(tipoelem);
	tipoelem getElemento()const;

	void setPrimoFiglio(Cella<T>*);
	void setSuccFratello(Cella<T>*);
	void setPadre(Cella<T>*);
	void setMarcato();
	void setNumeroNodi(int);
	void desetMarcato();
	Cella<T>* getPrimoFiglio()const;
	Cella<T>* getSuccFratello()const;
	Cella<T>* getPadre()const;
	bool getMarcato()const;
	int getNumeroNodi()const;

	bool operator==(Cella<T>);
	bool operator<=(Cella<T>);

private:
	tipoelem elemento;
	Cella<T>*primoFiglio;
	Cella<T>* succFratello;
	Cella<T>*padre;
	bool marcato;
	int numeroNodi;


};


template<class T>
Cella<T>::Cella(){
	primoFiglio=NULL;
	succFratello=NULL;
	padre=NULL;
}

template<class T>
void Cella<T>::setElemento(tipoelem etichetta){
	elemento=etichetta;
}

template<class T>
T Cella<T>::getElemento()const{
	return elemento;
}

template<class T>
void Cella<T>::setMarcato(){
	marcato=true;
}

template<class T>
void Cella<T>::desetMarcato(){
	marcato=false;
}

template<class T>
bool Cella<T>::getMarcato()const{
	return marcato;
}

template<class T>
void Cella<T>::setNumeroNodi(int n){
	numeroNodi=n;
}

template<class T>
int Cella<T>::getNumeroNodi()const{
	return numeroNodi;
}

template<class T>
void Cella<T>::setPrimoFiglio(Cella<T>*p){
	primoFiglio=p;
}

template<class T>
void Cella<T>::setSuccFratello(Cella<T>*p){
	succFratello=p;
}

template<class T>
void Cella<T>::setPadre(Cella<T>*p){
	padre=p;
}

template<class T>
Cella<T>* Cella<T>::getPrimoFiglio()const{
	return primoFiglio;
}


template<class T>
Cella<T>* Cella<T>::getSuccFratello()const{
	return succFratello;
}

template<class T>
Cella<T>* Cella<T>::getPadre()const{
	return padre;
}
















#endif /* CELLA_H_ */
