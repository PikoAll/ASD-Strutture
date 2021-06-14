/*
 * Coda.h
 *
 *  Created on: 5 ott 2020
 *      Author: peppi
 */

#ifndef CODA_H_
#define CODA_H_

#include<iostream>
using namespace std;

template<class Elemento>
class Coda{

public:
	Coda();
	Coda(int);
	Coda(const Coda<Elemento> &);
	~Coda();

	void crea();
	bool vuota()const;
	Elemento leggiCoda();	// top
	void fuoriCoda();	//pop
	void inCoda(Elemento a); //push

	Coda<Elemento>& operator=(const Coda<Elemento>& q);

	  template<class tp>
	  friend ostream& operator<<(ostream&, const Coda<tp>&);

private:
	  Elemento * elemento;
	  int testa;
	  int lunghezza;
	  int maxLunghezza;

};

template<class Elemento>
Coda<Elemento>::Coda(){
	maxLunghezza=10;
	crea();
}

template<class Elemento>
Coda<Elemento>::Coda(int n){
	maxLunghezza=n;
	crea();
}

template<class Elemento>
Coda<Elemento>::Coda(const Coda<Elemento> &q){
	testa=q.testa;
	lunghezza=q.lunghezza;
	maxLunghezza=q.maxLunghezza;
	elemento=new Elemento[q.maxLunghezza];

	for(int i=testa; i<lunghezza; i++){
		elemento[i]=q.elemento[i];
	}
}

template<class Elemento>
Coda<Elemento>::~Coda(){
	delete [] elemento;
}

template<class Elemento>
void Coda<Elemento>::crea(){
	elemento=new Elemento[maxLunghezza];
	testa=0;
	lunghezza=0;
}

template<class Elemento>
bool Coda<Elemento>::vuota()const{
	return lunghezza==0;
}

template<class Elemento>
Elemento Coda<Elemento>::leggiCoda(){
	if(!vuota()){
		return elemento[testa];
	}

}

template<class Elemento>
void Coda<Elemento>::fuoriCoda(){
	if(!vuota()){
		testa=(testa+1)% maxLunghezza;
		lunghezza--;
	}
}


template<class Elemento>
void Coda<Elemento>::inCoda(Elemento a){

	if(lunghezza!= maxLunghezza){
		elemento[(testa+lunghezza)%maxLunghezza]=a;
		lunghezza++;
	}

}


template < class Elemento >
Coda<Elemento>& Coda<Elemento>::operator=(const Coda<Elemento>& q){

  if(this==&q) return *this;

  testa=q.testa;
  lunghezza=q.lunghezza;

  if(maxLunghezza!=q.maxLunghezza){
    delete[]elemento;
    elemento=new Elemento[q.maxLunghezza];
    maxLunghezza=q.maxLunghezza;
  }

  for (int i=testa; i<lunghezza; i++)
    elemento[i]=q.elemento[i];

  return *this;

}

template<class tp>
ostream& operator<<(ostream& os, const Coda<tp>& q){

  os<<"[";

  if(!q.vuota()){
    int i=q.testa;
    while(i<q.lunghezza-1){

      os<<q.elemento[i]<<", ";

      i++;
    }

    os<<q.elemento[i];
  }
  os<<"]"<<endl;

  return os;
}

#endif /* CODA_H_ */
