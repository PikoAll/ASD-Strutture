/*
 * Coda.h
 *
 *  Created on: 6 ott 2020
 *      Author: peppi
 */

#ifndef CODA_H_
#define CODA_H_

#include <iostream>

using namespace std;

template<class T>
class Coda;

template<class T>
class Nodo{
public:
	friend class Coda<T>;
	Nodo(){
		succ=nullptr;
	}
	Nodo(Nodo<T>&n){
		valore=n.valore;
		succ=nullptr;
	}

	template<class K>
	friend ostream& operator<<(ostream& os, const Coda<K>& q);

private:
	Nodo *succ;
	T valore;

};

////////////////////////////////////////////////////////////////////////////
template <class T>
class Coda{
public:
	Coda();
	Coda(const Coda<T>&);
	~Coda();

	bool vuota()const;
	int size() const;
	void inCoda(T );
	void fuoriCoda();
	T leggiCoda();
	void print();

	Coda<T>& operator=(const Coda<T>&);

	template<class K>
	friend ostream& operator<<(ostream& os, const Coda<K>& q);

	//esercizi
	void cancellaMinimo(Coda&);
	void stampaCoda(Coda&);

	//laboratorio 6
	Coda<int> soloPositivi(Coda<int> &);


private:
	Nodo <T>* testa;
	Nodo <T>* coda;
	int s;
};

template<class T>
Coda<T>::Coda(){
	testa=nullptr;
	coda=nullptr;
	s=0;
}

template<class T>
Coda<T>::Coda(const Coda<T>& q){
	testa=coda=nullptr;
	s=0;
	Nodo<T>*tmp=q.testa;

	while(tmp!=nullptr){
		inCoda(tmp->valore);
		tmp=tmp->succ;
	}
}

template<class T>
Coda<T>::~Coda(){
	while(!vuota()){
		fuoriCoda();
	}
}

template<class T>
bool Coda<T>::vuota()const{
	return testa==nullptr;
}

template<class T>
int Coda<T>::size()const{
	return s;
}

template<class T>
void Coda<T>::inCoda(T v){

	Nodo<T> *tmp=new Nodo<T>;

	if(vuota()){
		testa=coda=tmp;
	}else{
		coda->succ=tmp;
	}
	tmp->succ=nullptr;
	tmp->valore=v;
	coda=tmp;
	s++;

}

template<class T>
void Coda<T>::fuoriCoda(){
	Nodo<T> *tmp=testa;
	testa=testa->succ;
	delete tmp;
	s--;
}

template<class T>
T Coda<T>::leggiCoda(){
	return testa->valore;
}

template<class T>
void Coda<T>::print(){
	Nodo<T>* tmp=testa;
	int i=0;
	while(tmp!=nullptr){
		cout<<i<<" :["<<tmp->valore<<"]"<<endl;
		tmp=tmp->succ;
		i++;
	}
}

template<class T>
Coda<T>& Coda<T>::operator=(const Coda<T>&q){

  if (this==&q) return *this;

  while(!vuota()){
    fuoriCoda();
  }
  Nodo<T>* tmp = q.testa;
  while(tmp!=nullptr){
    inCoda(tmp->valore);
    tmp=tmp->succ;
  }
  return *this;
}

template<class K>
ostream& operator<<(ostream& os, const Coda<K>& q){

  Nodo<K>* tmp = q.testa;
  int i=0;
  while(tmp!=nullptr){
    os<<i<<" :["<<tmp->valore<<"]"<<endl;
    tmp=tmp->succ;
    i++;
  }

  return os;
}

template<class T>
void Coda<T>::cancellaMinimo(Coda &c){

	int x=c.size();
	int v[x];
	int i=0;
	while(!c.vuota()){
		v[i]=c.leggiCoda();
		c.fuoriCoda();
		i++;
	}
	int min=v[0];

	for(int j=1; j<i;j++){
		if(v[j]<min){
			min=v[j];
		}
	}

	for(int j=0; j<i;j++){
		if(v[j]!=min){
			c.inCoda(v[j]);
		}
	}

}

template<class T>
void Coda<T>::stampaCoda(Coda &c){
	int x=c.size();
		int v[x];
		int i=0;
		while(!c.vuota()){
			v[i]=c.leggiCoda();
			c.fuoriCoda();
			i++;
		}
		cout<<"la coda e"<<endl;

		for(int j=0; j<i; j++){
			cout<<v[j]<<" ";
		}
}

template<class T>
Coda<int> Coda<T>::soloPositivi(Coda<int> & c){

	Coda<int> co;

	while(!c.vuota()){

		if(c.leggiCoda()>0){
			co.inCoda(c.leggiCoda());
		}
		c.fuoriCoda();

	}

	return co;

}


#endif /* CODA_H_ */
