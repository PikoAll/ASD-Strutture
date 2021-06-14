/*
 * LinkedList2021.h
 *
 *  Created on: 21 gen 2021
 *      Author: peppi
 */

#ifndef LINKEDLIST2021_H_
#define LINKEDLIST2021_H_

#include"Linear_List.h"

template<class T>
class LinkedList;

template<class T>
class Nodo{
	//ho detto al compilatore che solo questa classe (di tipo friend) possono accedere alle componenti private
	friend class LinkedList<T>;

private:
	T valore;
	Nodo<T>* succ;
	Nodo<T>* precc;

};


template<class T>
class LinkedList : public Linear_List<T,Nodo<T>*>{

public:
	typedef typename Linear_List<T,Nodo<T>*>::valore valore;
	typedef typename Linear_List<T,Nodo<T>*>::posizione posizione;

	//costruttori
		LinkedList();
		LinkedList(int);
		//costruttore copia
		LinkedList(const LinkedList<T>&);
		//distruttore
		~LinkedList();

		//operatori
		void crea();
		bool vuoto()const;
		valore leggi(posizione)const;
		void scrivi(const valore &,posizione ); //per scrivere in una pos gia occupata
		posizione inizio()const;
		posizione ultimo()const;
		bool fine(posizione) const;
		posizione succ(posizione)const;
		posizione precc(posizione)const;
		void inserisci(const valore &, posizione);
		void cancella(posizione);
		int size()const{
			return lunghezza;
		}
		// sovraccarico di operatori
			LinkedList<T>& operator=(const LinkedList<T>&); // the assignment operator
			bool operator==(const LinkedList<T> &) const; // tests two list for equality

	///////////////////////////////////////
		void inverti(LinkedList&);
		bool palindroma(LinkedList&);
		void inserisciOrdinatamente(valore a);
		bool cercaElemento(valore a);
		int frequenzaMultipli(LinkedList& l, int k);
		void stampaFrequenzaElementi(LinkedList & l);
		void elementiMaggiori(LinkedList<int>&l,int k);

private:
	Nodo<T>* testa;
	int lunghezza;

};


template<class T>
LinkedList<T>::LinkedList(){
	testa=new Nodo<T>;
	testa->succ=testa;
	testa->precc=testa;
	lunghezza=0;
}

template<class T>
LinkedList<T>::LinkedList(int l){
	testa=new Nodo<T>;
	if(l==0){
		testa->succ=testa;
		testa->precc=testa;
	}else{
		posizione p;
		p=testa;
		for (int i=0;i<l;i++){
			p->succ=new Nodo<T>;
			p->succ->precc=p;
			p=p->succ;
		}
		testa->precc=p;
		p->succ=testa;
	}
	lunghezza=l;
}


template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>&l){

	lunghezza=l.size();
	testa=new Nodo<T>;
	testa->succ=testa;
	testa->precc=testa;

	if(!l.vuoto()){
		posizione p=l.ultimo();
		for(int i=0; i<=l.lunghezza;i++){
			inserisci(l.leggi(p),inizio());
			p=l.precc(p);
		}
	}

}

//distruttore deve deallocare partendo dal begin() fino a quando la lista non è vuota.
//Devo poi eliminare il puntatore testa e la sentinella (in next della sentinella punta a se stesso)
//primolista è il successore della sentinella- Se la lista è vuota mi restituisce il valore della sentinella.

template<class T>
LinkedList<T>::~LinkedList(){
	while(!vuoto()){
		cancella(inizio());
	}
	delete testa;
}

/////////////////////operatori//////////////////////////////////////////////////////////////////////////////
template<class T>
void LinkedList<T>::crea(){
	if(vuoto()){
		lunghezza=0;
	}
}

template<class T>
bool LinkedList<T>::vuoto()const{
	return testa==testa->succ;
}

template<class T>
typename LinkedList<T>::posizione LinkedList<T>::inizio()const{
	return testa->succ;
}

template<class T>
typename LinkedList<T>::posizione LinkedList<T>::ultimo()const{
	return testa->precc;
}

template<class T>
typename LinkedList<T>::posizione LinkedList<T>::succ(posizione p)const{
	return p->succ;
}

template<class T>
typename LinkedList<T>::posizione LinkedList<T>::precc(posizione p)const{
	return p->precc;
}

template<class T>
bool LinkedList<T>::fine(posizione p)const{
	return p==testa;
}

template<class T>
typename LinkedList<T>::valore LinkedList<T>::leggi(posizione p)const{
	if(!fine(p)){
		return p->valore;
	}
}

template<class T>
void LinkedList<T>::scrivi(const valore &a,posizione p){
	if(!fine(p)){
		p->valore=a;
	}
}

template<class T>
void LinkedList<T>::inserisci(const valore&a,posizione p){

	posizione t=new Nodo<T>;

	t->valore=a;
	t->succ=p;
	t->precc=p->precc;
	p->precc->succ=t;
	p->precc=t;
	lunghezza++;
}


template<class T>
void LinkedList<T>::cancella(posizione p){
	if(!vuoto() && !fine(p)){
		p->precc->succ=p->succ;
		p->succ->precc=p->precc;
		delete p;
	}
}


template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L){
	if (this != &L){
		lunghezza = L.size();

		testa = new Nodo<T>;
		testa->succ = testa;
		testa->precc = testa;

        cout << L.vuoto()<<endl;
        cout << L.size()<<endl;
		if (!L.vuoto()){
            posizione p = L.ultimo();
			for (int i=0; i < L.size(); i++){
				cout << i, L.leggi(p);
				inserisci(L.leggi(p), inizio());
				p = L.precc(p);
			}
		}
	}
	return *this;
}


template<class T>
bool LinkedList<T>::operator==(const LinkedList<T>&L)const{
	if (L.size() == lunghezza)
		return false;
	posizione p, pL;
	p = inizio();
	pL = L.inizio();
	while (!fine(p)){
		if (p->valore != pL->valore)
			return false;
		p = p->succ;
		pL = pL->succ;
	}
	return true;
}


//////////////////////////////////////////////////////////////////////////////////////////////
/////metodi aggiuntivi///////////////////////////////////////////////////////////////////////

template<class T>
void LinkedList<T>::inverti(LinkedList<T> & l){
posizione p,p1;
p=l.inizio();
p1=l.ultimo();
T temp;
	if(l.size()%2==0){

		while(p->succ!=p1){
			temp=l.leggi(p1);
			l.scrivi(l.leggi(p),p1);
			l.scrivi(p,temp);
			p=l.succ(p);
			p1=l.precc(p1);
		}

	}else{

		while(p!=p1){
			temp=l.leggi(p1);
			l.scrivi(l.leggi(p),p1);
			l.scrivi(p,temp);
			p=l.succ(p);
			p1=l.precc(p1);
		}

	}

}

template<class T>
bool LinkedList<T>::palindroma(LinkedList& l){

	posizione p=l.inizio();
	posizione p1=l.ultimo();

	if(l.size()%2==0){
		while(l.succ(p)!=p1){
			if(l.leggi(p)!=l.leggi(p1)){
				cout<<l.leggi(p)<<"  "<<l.leggi(p1);
				return false;
			}
			p=l.succ(p);
			p1=l.precc(p1);
		}
	}else{
		while(l.succ(l.succ(p))!=p1){
			cout<<l.leggi(p)<<"  "<<l.leggi(p1);
			if(l.leggi(p)!=l.leggi(p1)){
				return false;
			}
			p=l.succ(p);
			p1=l.precc(p1);
		}
		if(l.leggi(p)!=l.leggi(p1)){
			return false;
		}
	}
	return true;
}

template<class T>
void LinkedList<T>::inserisciOrdinatamente(valore a){
posizione p=inizio(),p1;

	if(vuoto()){
		inserisci(a,inizio());
	}else{
		bool fl=true;
		while(!fine(p) && fl==true){
			if(leggi(p)>a && fl==true){
				T nuovo=leggi(p);
				scrivi(a,p);
				inserisci(nuovo,succ(p));
				fl=false;
			}
			p=succ(p);
		}
		if(fl==true){
			inserisci(a,ultimo());
		}

	}

}

template <class T>
bool LinkedList<T>::cercaElemento(valore a){

	posizione p=inizio();
	bool fl=false;
	while(!fine(p) && fl==false){
		if(leggi(p)==a){
			fl=true;
		}
		p=succ(p);
	}
	return fl;

}

template <class T>
int LinkedList<T>::frequenzaMultipli(LinkedList& l, int k){
	posizione p=l.inizio();
	int fre=0;

	while(!l.fine(p)){
		if(l.leggi(p)%k==0){
			fre++;
		}
		p=l.succ(p);
	}
	return fre;
}


template<class T>
void LinkedList<T>::stampaFrequenzaElementi(LinkedList & l){

	posizione p=l.inizio();
	posizione p1;

	while(!l.fine(p)){

	p1=p;
	T num=l.leggi(p);

		while(!l.fine(p1)){
			if(l.leggi(p1)==num){
				cout<<num<<" ";
			}
			p1=l.succ(p1);
		}
		p=l.succ(p);
	}


}

template<class T>
void LinkedList<T>::elementiMaggiori(LinkedList<int>&l,int k){
	posizione p=l.inizio();

	while(!l.fine(p)){
		if(l.leggi(p)>k){
			cout<<l.leggi(p)<<" ";
		}
		p=l.succ(p);
	}
}


#endif /* LINKEDLIST2021_H_ */
