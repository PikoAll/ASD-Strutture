/*
 * Pila.h
 *
 *  Created on: 5 ott 2020
 *      Author: peppi
 */

#ifndef PILA_H_
#define PILA_H_

#include <iostream>
using namespace std;

template <class Elemento>
class Pila{

public:
	typedef Elemento elemento;
	Pila();
	Pila(int);
	~Pila();

	void crea();
	bool vuota()const;
	elemento leggi()const;
	void fuoriPila();
	void inPila(elemento);

private:
	elemento *elementi;
	int lunghezza;
	int testa;

};

template<class Elemento>
Pila<Elemento>::Pila(){
	elementi=new elemento[100];
	lunghezza=100;
	crea();
}

template<class Elemento>
Pila<Elemento>::Pila(int n){
	elementi=new elemento[n];
	lunghezza=n;
	crea();
}

template<class Elemento>
Pila<Elemento>::~Pila(){
	delete [] elementi;
}


template<class Elemento>
void Pila<Elemento>::crea(){
	testa=0;
}

template<class Elemento>
bool Pila<Elemento>::vuota()const{
	return testa==0;
}

template<class Elemento>
Elemento Pila<Elemento>::leggi()const{
	return elementi[testa-1];
}

template<class Elemento>
void Pila<Elemento>::fuoriPila(){

	if(!vuota()){
		testa-=1;
	}else{
		cout<<"nessun elemento nella pila"<<endl;
	}

}

template<class Elemento>
void Pila<Elemento>::inPila(elemento e){
	if(testa==lunghezza){
		cout<<"raggiunta capacita massima"<<endl;
	}else{
		elementi[testa]=e;
		testa++;
	}
}



#endif /* PILA_H_ */
