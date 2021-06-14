/*
 * Coda.h
 *
 *  Created on: 5 ott 2020
 *      Author: peppi
 */


/*
 * Nella teoria delle code, una coda di priorità è una struttura dati astratta, simile ad una coda o ad una pila, ma diversa da queste in quanto ogni elemento
 * inserito all'interno della coda possiede una sua "priorità". In una coda di priorità, ogni elemento avente priorità più alta, viene inserito prima rispetto ad
 *  un elemento avente priorità più bassa. In particolare, l'elemento con priorità più alta si trova in testa alla coda, quello con priorità più bassa si troverà,
 *   appunto, in coda
 */

#ifndef CODA_H_
#define CODA_H_

#include<iostream>
using namespace std;

template<class T>
class Coda{

public:
	typedef T elemento;
	Coda();
	Coda(int);
	~Coda();

	void crea();
	void inserisci(elemento);
	elemento min();
	void cancellaMin();

private:
	int maxLunghezza;
	elemento *v;
	int ultimo;

	void aggiustaSopra();
	void aggiustaSotto(int,int);

};

template<class T>
Coda<T>::Coda(){
	maxLunghezza=100;
	v=new elemento[maxLunghezza];
	crea();
}

template<class T>
Coda<T>::Coda(int n){
	maxLunghezza=n;
	v=new elemento[n];
	crea();
}

template<class T>
Coda<T>::~Coda(){
	delete[] v;
}

template<class T>
void Coda<T>::crea(){
	ultimo=0;
}

template<class T>
void Coda<T>::inserisci(elemento e){

	if(ultimo<maxLunghezza){
		v[++ultimo-1]=e;
		aggiustaSopra();
	}

}

template<class T>
typename Coda<T>::elemento Coda<T>::min(){
	if(ultimo!=0){
		return v[0];
	}
}

template<class T>
void Coda<T>::cancellaMin(){
	if(ultimo!=0){
		v[0]=v[ultimo-1];
		ultimo--;
		aggiustaSotto(1,ultimo);
	}
}


/* Per ripristinare i vincoli dello heap quando la priorità di un nodo è      *
 * cresciuta, ci spostiamo nello heap verso l'alto, scambiando, se necessario,*
 * il nodo in posizione k con il suo nodo padre (in posizione k/2),           *
 * continuando fintanto che heap[k]<heap[k/2] oppure fino a quando            *
 * raggiungiamo la cima dello heap.                                           */

template<class T>
void Coda<T>::aggiustaSopra(){

	int k = ultimo;

	  while (k > 1 && v[k - 1] < v[k / 2 - 1]) {
	      elemento tmp;
	      tmp = v[k - 1];
	      v[k - 1] = v[k / 2 - 1];
	      v[k / 2 - 1] = tmp;
	      k = k / 2;
	    }

}

/* Per ripristinare i vincoli dello heap quando la priorità di un nodo si è   *
 * ridotta, ci spostiamo nello heap verso il basso, scambiando, se necessario,*
 * il nodo in posizione k con il minore dei suoi nodi figli e arrestandoci    *
 * quando il nodo al posto k non è più grande di almeno uno dei suoi figli    *
 * oppure quando raggiungiamo il fondo dello heap. Si noti che se N è pari e  *
 * k è N/2, allora il nodo in posizione k ha un solo figlio: questo caso      *
 * particolare deve essere trattato in modo appropriato.                      */

template<class T>
void Coda<T>::aggiustaSotto(int k, int N){

	short int scambio = 1;

	  while (k <= N / 2 && scambio) {
	      int j = 2 * k;
	      elemento tmp;
	      if (j < N && v[j - 1] > v[j])
					j++;
	      if ((scambio = (v[j - 1] < v[k - 1]))) {
					tmp = v[k - 1];
					v[k - 1] = v[j - 1];
					v[j - 1] = tmp;
					k = j;
				}
	  }


}



#endif /* CODA_H_ */
