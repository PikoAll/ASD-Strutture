/*
 * Grafo.h
 *
 *  Created on: 12 ott 2020
 *      Author: peppi
 */

#ifndef GRAFO_H_
#define GRAFO_H_
#include "List_vector.h"

template<class P, class N>
class Arco{
	N nodo1;
	N nodo2;
	P peso;
};

template<class E, class P, class N>
class Grafo{
public:
	typedef E Etichetta;
	typedef P Peso;
	typedef N Nodo;

	typedef Arco<Peso,Nodo> Arco;
	typedef List_vector<Nodo*> ListaNodi;
	typedef typename List_vector<Nodo*>::posizione ListaNodiPosizione;
	typedef List_vector<Arco> ListaArchi;

	virtual bool vuoto()const=0;
	virtual void insNodo(Nodo &)=0;
	virtual void insArco(Nodo,Nodo,Peso)=0;
	virtual void cancNodo(Nodo)=0;
	virtual void cancArco(Nodo,Nodo)=0;

	virtual ListaNodi Adiacenti(Nodo)const=0;
	virtual ListaNodi listNodi()const=0;
	virtual Etichetta leggiEtichetta(Nodo)const=0;
	virtual void scriviEtichetta(Nodo,Etichetta)=0;
	virtual Peso leggiPeso(Nodo,Nodo)const=0;
	virtual void scriviPeso(Nodo,Nodo,Peso)=0;

	virtual int numNodi()=0;
	virtual int numArchi()=0;
	virtual ~Grafo(){};



};




#endif /* GRAFO_H_ */
