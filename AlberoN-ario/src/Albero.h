/*
 * Albero.h
 *
 *  Created on: 10 ott 2020
 *      Author: peppi
 */

#ifndef ALBERO_H_
#define ALBERO_H_

#include "Cella.h"
#include <cassert>
#include <limits.h>
#include <iostream>

using namespace std;

template<class T>
class Albero{

public:

	typedef T tipoelem;
	typedef Cella<T>* Nodo;

	Albero();

	void crea();
	bool vuoto();
	void insRadice(Nodo);
	void insPrimoFiglio(Nodo);
	void insFratello(Nodo);

	Nodo radiceAlbero();
	Nodo padre(Nodo);
	Nodo primoFiglio(Nodo);
	Nodo succFratello(Nodo);

	bool ultimoFratello(Nodo);
	void insPrimoSottoAlbero(Nodo,Albero<T>&);//inserisce il sotto albero come primo figlio di Nodo
	void insSottoAlbero(Nodo,Albero<T>&); //inserisce il sotto albero come succFratello di Nodo
	void cancellaSottoAlbero(Nodo);
	bool foglia(Nodo);
	//operazioni elementari
	tipoelem leggiNodo(Nodo);
	void scriviNodo(Nodo,tipoelem);
	//servizio

	void stampaAlbero();//stampa albero dalla radice
	void stampaSottoAlbero(Nodo); //stampa albero dal Nodo
	void stampaPreOrdine(Nodo);//stampa l'albero dal Nodo in preordine
	void stampaPostOrdine(Nodo);	////stampa l'albero dal Nodo in post Ordine
	void stampaSimmetrica(Nodo); //stamoa l'albero in simmetria dal Nodo
	int profondita(Nodo);//calcola la profondità dell'albero
	void stampaBFS(Nodo);//stampa in ampiezza dell'albero
	//int larghezza(Nodo);
	int contaNodi(Nodo);
	void foglieK(Nodo u, int somma,int k);
	int numeroFoglie(Nodo);
	void nLivello(Nodo,int ,int &);
	bool pariDispari(Nodo);//verifica se ogni nodo pari ha solo figli dispari

	tipoelem maxAlbero(Nodo);//restituisce il valore massimo contenuto in albero
	int altezza(Nodo);//restituisce l'altezza dell'albero
	int nodiKfigli(Nodo,int k);//calcola il numero di nodi con k figli
	bool tuttiPari(Nodo);//verifica se tutti i valori dei nodi sono pari partendo dal Nodo
	int livello(Nodo);//restituisce il livello di un nodo
	bool trovaElemento(Nodo,T valore);//verifica che valore appartiene all'albero
	int altezzaMinima(Nodo);
	void cancellaPrimoFiglio(Nodo);
	void cancellaSuccFratello(Nodo);
	bool appartiene(Nodo u, Nodo n);//controlla se Nodo u appartiene all'albero partendo la ricerca dal Nodo n

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Dato un albero n-ario di elementi di tipo intero, implementare in C++ la funzione int max level(Tree<int>)
	che restituisce in output il livello k dell’albero per il quale la somma di tutti i nodi di livello k `e massima.
	Prevedere una funzione nel main che contenga una procedura di inserimento automatico e successivamente il test della funzione implementata
 */
	int maxLevel(Albero<int>);
	void supportoMX(int [],Nodo);
	/*
	 *  Dato un albero n-ario con nodi aventi etichetta di tipo intero, implementare un metodo in C++ che
		modifichi l’albero in modo tale che l’etichetta di ogni nodo n corrisponda alla somma dei valori delle
		etichette dei nodi del sottoalbero radicato in n.
		Prevedere una funzione main che contenga una procedura di inserimento automatico e successivamente
		il test dei metodi implementati.
	 */
	void padreSommaFigli(Nodo n);
	void padreSommaFigli2(Nodo n);


private:
	void altezzaMinimale(Nodo n, int &minAltezza);
	Nodo radice;
	void deleteMarcato(Nodo);



};

template<class T>
Albero<T>::Albero(){

	crea();
}

template<class T>
void Albero<T>::crea(){
	radice=NULL;
}

template<class T>
bool Albero<T>::vuoto(){
	return radice==NULL;
}

template<class T>
void Albero<T>::insRadice(Nodo n){
	if(vuoto()){
		radice=n;
	}
}

template<class T>
Cella<T>* Albero<T>::radiceAlbero(){
	if(!vuoto()){
		return radice;
	}
}

template<class T>
Cella<T>* Albero<T>::padre(Nodo n){

	if(n!=radiceAlbero()){
		return n->getPadre();
	}

}

template<class T>
bool Albero<T>::foglia(Nodo n){
	if(n->getPrimoFiglio()==NULL){
		return true;
	}
	return false;
}

template<class T>
Cella<T>* Albero<T>::primoFiglio(Nodo n){
	return n->getPrimoFiglio();
}

template<class T>
bool Albero<T>::ultimoFratello(Nodo n){
	return n->getSuccFratello()==NULL;
}

template<class T>
Cella<T>* Albero<T>::succFratello(Nodo n){
	return n->getSuccFratello();
}

template<class T>
void Albero<T>::insPrimoSottoAlbero(Nodo n, Albero<T>& A){
	A.radiceAlbero()->setSuccFratello(n->getPrimoFiglio());//quello che era il primo figlio di n diventa succFratello della radice dell'albero A
	A.radiceAlbero()->setPadre(n);//n diventa padre della radice di A
	n->setPrimoFiglio(A.radiceAlbero());//la radice di A diventa il primo figlio di n

}

template<class T>
void Albero<T>::insSottoAlbero(Nodo n,Albero<T>& A){

    A.radiceAlbero()->setSuccFratello(n->getProxFratello());//quello che era il succFratello di n diventa il succFratello della radice di A
    A.radiceAlbero()->setPadre(n->getPadre());//quello che era il padre di n diventa anche il padre della radice di A
    n->setSuccFratello(A.radiceAlbero());//il succFratello di n diventa la radice dell'albero A
}


template<class T>
T Albero<T>::leggiNodo(Nodo n){
	return n->getElemento();
}

template<class T>
void Albero<T>::scriviNodo(Nodo n, tipoelem a){
	n->setElemento(a);
}

template<class T>
void Albero<T>::stampaSottoAlbero(Nodo n){

	cout<<"\n "<<leggiNodo(n)<<" :";

	Nodo c=primoFiglio(n);
	while(c!=NULL){
		cout<<" "<<leggiNodo(c);
		c=succFratello(c);
	}
	c=primoFiglio(n);
	while(c!=NULL){
		stampaSottoAlbero(c);
		c=succFratello(c);
	}

}

template<class T>
void Albero<T>::stampaAlbero(){
	cout<<"\n*****Stampa Dell'Albero*****\n";
	if(!vuoto()){
		cout<<endl;
		stampaSottoAlbero(radiceAlbero());
		cout<<endl<<endl;
	}
}


template<class T>
void Albero<T>::insPrimoFiglio(Nodo n){
	n->setPrimoFiglio(new Cella<T>);
	primoFiglio(n)->setPadre(n);
}

template<class T>
void Albero<T>::insFratello(Nodo n){
	n->setSuccFratello(new Cella<T>);
	succFratello(n)->setPadre(padre(n));
}

template<class T>
void Albero<T>::stampaPreOrdine(Nodo u){
    Nodo temp;
    if(u!=NULL){
        cout<<" "<<leggiNodo(u);
        temp=primoFiglio(u);
        while(temp!=NULL){
            stampaPreOrdine(temp);
            temp=succFratello(temp);
        }
    }
    return;
}

template<class T>
void Albero<T>::stampaPostOrdine(Nodo u){
    Nodo temp;
    if(u!=NULL){
        temp=primoFiglio(u);
        while(temp!=NULL){
            stampaPostOrdine(temp);
            temp=succFratello(temp);
        }
    }
    cout<<" "<<leggiNodo(u);
    return;
}

template<class T>
void Albero<T>::stampaSimmetrica(Nodo u){
    Nodo temp;
    if(foglia(u)){
        cout<<" "<<leggiNodo(u);
    }else{
        temp=primoFiglio(u);
        stampaSimmetrica(temp);
        cout<<" "<<leggiNodo(u);
        temp=succFratello(temp);
        while(temp!=NULL){
            stampaSimmetrica(temp);
            temp=succFratello(temp);
        }
    }
}

template<class T>
void Albero<T>::cancellaSottoAlbero(Nodo n){
    cout<<"\nEntro nella procedura per eliminare nodo:"<<n->getElemento();
    //spezzo i legami tra n, il padre ed i fratelli
    if(radiceAlbero()==n)
        delete radiceAlbero();
    else{
        if(n==primoFiglio(padre(n))){//se n è il primo figlio
            if(ultimoFratello(n))//e non ha fratelli
                padre(n)->setPrimoFiglio(NULL);
            else//altrimenti ha un fratello che diventa primo figlio
                padre(n)->setPrimoFiglio(succFratello(n));
        }else{
            Nodo prec=primoFiglio(padre(n));
            Nodo current=succFratello(prec);
            while(current!=n){
                prec=current;
                current=succFratello(current);
            }
            if(ultimoFratello(n))
                prec->setSuccFratello(NULL);
            else
                prec->setSuccFratello(succFratello(n));
        }
    }
    delete n;
    contaNodi(radiceAlbero());
}

template<class T>
int Albero<T>::profondita(Nodo u){
    Nodo v;
    int massimo,temp;
    if(foglia(u))
        return 0;
    else{
        v=primoFiglio(u);
        massimo=0;
        while(v!=NULL){
            temp=profondita(v);
            if(massimo<=temp)
                massimo=temp;
            v=succFratello(v);
        }
        return massimo+1;
    }
}

template<class T>
void Albero<T>::deleteMarcato(Nodo n){
    Nodo temp;
    if(n!=NULL){
        if(n->getMarcato())
            n->desetMarcato();
        temp=primoFiglio(n);
        while(temp!=NULL){
            deleteMarcato(temp);
            temp=succFratello(temp);
        }
    }
    return;
}
/*
template<class T>
void Albero<T>::stampaBFS(Nodo v){
    deleteMarcato(radiceAlbero());//pone a false tutti i marcati
    Coda<Nodo> C(contaNodi(radiceAlbero()));
    C.inCoda(v);
    v->setMarcato();
    Nodo t;
    while(!C.codaVuota()){
        t=C.leggiCoda();
        C.fuoriCoda();
        cout<<" "<<leggiNodo(t)<<"("<<t->getNumNodi()<<")";
        Nodo u=primoFiglio(t);
        while(u!=NULL){
            if(!u->getMarcato()){
                u->setMarcato();
                C.inCoda(u);
            }
            u=succFratello(u);
        }
    }
}
*/

/*notando che quando tutti i nodi di un livello vengono
 estratti dalla coda, la coda contiene solo e
unicamente i nodi del livello successivo.
Basta quindi utilizzare la dimensione della coda
come misuratore
della larghezza del livello, e confrontarla con la larghezza
massima trovata fino ad ora. Non solo, il valore
della larghezza puo essere copiato nella variabile  conteggio,
 e utilizzato per scoprire quando sara terminato il
prossimo livello. Il costo di questa funzione, piu elegante
 della precedente,  e sempre  O(n), ma in questo
caso non e' richiesta memoria aggiuntiva pari ad  O(n),
ma solo pari a O(l), dove l e' la massima larghezza.*/
/*
template<class T>
int Albero<T>::larghezza(Nodo t){
    if(t==NULL)
        return 0;
    int conteggio=1;
    int larghezza=1;
    Coda<Nodo> Q(30);
    Q.inCoda(t);
    while(!Q.codaVuota()){
        Nodo u=Q.leggiCoda();
        Q.fuoriCoda();
        Nodo v=primoFiglio(u);
        while(v!=NULL){
            Q.inCoda(v);
            v=succFratello(v);
        }
        conteggio=conteggio-1;
        if(conteggio==0){
            conteggio=Q.Size();
            larghezza=max(larghezza,conteggio);
        }
    }
    return larghezza;
}
*/

/*Dato un albero N-ario si vuole memorizzare in ciascun campo
''numNodi'' di ogni nodo il numero di nodi radicati nel suo sottoalbero*/
template<class T>
int Albero<T>::contaNodi(Nodo u){
    int conteggio=0;
    Nodo temp;
    if(u!=NULL){
        if(foglia(u)){
            u->setNumeroNodi(1);
            conteggio++;
        }else{
            conteggio++;
            temp=primoFiglio(u);
            while(temp!=NULL){
                conteggio=conteggio+contaNodi(temp);
                temp=succFratello(temp);
            }
            u->setNumeroNodi(conteggio);
        }
    }
    return conteggio;
}

/*Dato un albero ordinato i cui nodi contengono valori interi
si vogliono cancellare tutte le foglie per il quale il percorso radice-foglia
ha somma complessiva uguale a k*/
template<class T>
void Albero<T>::foglieK(Nodo n, int somma, int k){
	Nodo v;
	if(!foglia(n)){
		v=primoFiglio(n);
		while(v!=NULL){
			foglieK(v,somma+leggiNodo(n),k);
			v=succFratello(v);
		}
	}else{
		if(somma+leggiNodo(n)==k){
			cancellaSottoAlbero(n);
		}
	}
}

/*Restituisce il numero di foglie presenti nell'albero n ario*/
template<class T>
int Albero<T>::numeroFoglie(Nodo n){

	if(n==NULL){
		return 0;
	}
	if(primoFiglio(n)==NULL){
		return 1+numeroFoglie(succFratello(n));
	}else{
		return numeroFoglie(primoFiglio(n))+numeroFoglie(succFratello(n));
	}

}

template<class T>
T Albero<T>::maxAlbero(Nodo n){
	////////////////////////////////////////////////////////////////////
	if(!vuoto()){
	tipoelem currMax;
	tipoelem massimo=n->getElemento();
	Nodo temp=primoFiglio(n);
	while(temp!=NULL){
		currMax=maxAlbero(temp);
		if(currMax>massimo){
			massimo=currMax;
		}
		temp=succFratello(temp);
	}
	return massimo;
	}
}

template<class T>
int Albero<T>::altezza(Nodo n){
	int maxAltezza=0;
	Nodo temp=primoFiglio(n);
	while(temp!=NULL){

		int t=altezza(temp)+1;
		if(t>maxAltezza){
			maxAltezza=t;
		}
		temp=succFratello(temp);

	}
	return maxAltezza;
}

template<class T>
int Albero<T>::nodiKfigli(Nodo n, int k){
	int kl=0;
	Nodo temp;
	if(n==NULL){
		return 0;
	}else{
		temp=primoFiglio(n);
		while(temp!=NULL){
			temp=succFratello(temp);
		}
		if(k==kl){
			return(1+nodiKfigli(succFratello(n),k)+nodiKfigli(primoFiglio(n),k));
		}else{
			nodiKfigli(succFratello(n),k)+nodiKfigli(primoFiglio(n),k);
		}
	}

}


template<class T>
int Albero<T>::livello(Nodo n){
	int liv;
	//restituisce il livello di n
	    //se n è radice il livello è 0
	if(n==radiceAlbero()){
		return 0;
	}else{
		liv=1;
		Nodo temp=padre(n);
		while(temp!=radiceAlbero()){
			liv++;
			temp=padre(temp);
		}
	}
	return liv;

}

/*restituisci il numero di nodi di livello k*/
template<class T>
void Albero<T>::nLivello(Nodo n, int k, int & numero){

	Nodo temp;
if(n!=NULL){
	if(livello(n)==k){
		numero++;
	}
	temp=primoFiglio(n);
	while(temp!=NULL){
		nLivello(temp,k,numero);
		temp=succFratello(temp);
	}
}
}


template<class T>
bool Albero<T>::tuttiPari(Nodo n){
	Nodo temp;
	bool ris;
	if(n!=NULL){
		if(leggiNodo(n)%2==0){
			ris=true;
		}else{
			ris=false;
		}
		temp=primoFiglio(n);
		while(temp!=NULL && ris){
			ris=tuttiPari(temp);
			temp=succFratello(temp);
		}
	}
	return ris;
}

template<class T>
bool Albero<T>::appartiene(Nodo u, Nodo n){
	Nodo temp;
	bool trovato=false;
	if(n==NULL){
		return NULL;
	}
	if(n==u){
		return true;
	}
	temp=primoFiglio(n);
	while(temp!=NULL && !trovato){
		if(appartiene(u,temp)){
			trovato=true;
		}
		temp=succcFratello(temp);
	}
	return trovato;
}

template<class T>
bool Albero<T>::trovaElemento(Nodo n,T valore){
	Nodo temp;
	bool trovato;
	if(n==NULL){
		return false;
	}
	if(leggiNodo(n)==valore){
		return true;
	}
	temp=primoFiglio(n);
	while(temp!=NULL && !trovato){
		if(trovaElemento(temp,valore)){
			trovato=true;
		}
		temp=succFratello(temp);
	}
	return trovato;
}

template<class T>
void Albero<T>::altezzaMinimale(Nodo n, int &min){
	Nodo temp;
	int current=0;
	if(n!=NULL){
		if(foglia(n)){
			current=livello(n);
			if(current<min){
				min=current;
			}
		}else{
			temp=primoFiglio(n);
			while(temp!=NULL){
				altezzaMinimale(temp,min);
				temp=succFratello(temp);
			}
		}
	}
}

template<class T>
int Albero<T>::altezzaMinima(Nodo n){
	int min=altezza(n);
	altezzaMinimale(n,min);
	return min;
}

template<class T>
void Albero<T>::cancellaPrimoFiglio(Nodo n){
	if(foglia(n)){
		return;
	}else{
		Nodo temp=primoFiglio(n);
		delete primoFiglio(n);
		n->setPrimoFiglio(succFratello(temp));
	}
}

template<class T>
void Albero<T>::cancellaSuccFratello(Nodo n){
    if(succFratello(n)==NULL)
        return;
    else{
        Nodo temp=succFratello(n);
        delete succFratello(n);
        n->setSuccFratello(succFratello(temp));
    }
}

template<class T>
bool Albero<T>::pariDispari(Nodo n){
    Nodo temp;
    bool ris=true;
    if(n==NULL)
        return true;
    if(leggiNodo(n)%2){
        temp=primoFiglio(n);
        while(temp!=NULL){
            ris=ris &&pariDispari(temp);
            temp=succFratello(temp);
        }
        return ris;
    }else{
        temp=primoFiglio(n);
        while(temp!=NULL){
            ris=ris && (leggiNodo(temp)%2) && pariDispari(temp);
            temp=succFratello(temp);
        }
        return ris;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int Albero<T>::maxLevel(Albero<int>a){

	int l=a.altezza(a.radiceAlbero());

	cout<<l<<endl;
	int v[l+1];


	for(int i=0; i<l+1;i++){
		v[i]=0;
	}
	supportoMX(v,a.radiceAlbero());
	int k=0;

	for(int i=0; i<l+1;i++){
		cout<<v[i]<<" ";
	}

	for(int i=0; i<l ;i++){
			if(v[k]<v[i]){
				k=i;
			}
	}
	cout<<endl;

	return k;
}

template<class T>
void Albero<T>::supportoMX(int v[],Nodo n){

	if(n!=NULL){
		v[livello(n)]+=leggiNodo(n);
		Nodo temp=primoFiglio(n);
		while(temp!=NULL){
			supportoMX(v,temp);
			temp=succFratello(temp);
		}
	}

}

template<class T>
void Albero<T>::padreSommaFigli(Nodo n){

Nodo temp=primoFiglio(n);
Nodo temp2=temp;
int somma=0;
while(temp!=NULL){
	if(temp==primoFiglio(n)){
		temp2=temp;
	}else{
		temp2=primoFiglio(temp);
	}
while(temp2!=NULL){
	Nodo temp1=temp2;
	somma=0;
	while(!ultimoFratello(temp1)){
		somma+=leggiNodo(temp1);
		temp1=succFratello(temp1);
	}
	somma+=leggiNodo(temp1);
	/*if(primoFiglio(temp1) && !ultimoFratello(temp1)){
		cout<<"il padre e"<<leggiNodo(padre(temp1))<<" la somma1 e "<<leggiNodo(temp1)<<endl;
	}else{*/
	cout<<"il padre e"<<leggiNodo(padre(temp1))<<" la somma e "<<somma<<endl;
	scriviNodo(padre(temp1),somma);
//	}
temp2=primoFiglio(temp2);
}
temp=succFratello(temp);
}


//somma complessiva nodi

/*
cout<<"Ciao";
	int somma=0;
if(n!=NULL && primoFiglio(n)!=NULL){
	Nodo temp=primoFiglio(n);
	while(temp!=NULL){
		padreSommaFigli(temp);
		somma+=leggiNodo(temp);
		temp=succFratello(temp);
	}
	cout<<"il padre e"<<leggiNodo(n)<<" somma e"<<somma<<endl;
	scriviNodo(n,somma);
}
*/
}

template<class T>
void Albero<T>::padreSommaFigli2(Nodo n){




	//ok e un modo entrambi funzionanti
	int somma=0;

		Nodo temp=primoFiglio(n);


		while(temp!=NULL){
			padreSommaFigli2(temp);
			temp=succFratello(temp);
		}

		temp=primoFiglio(n);
		while(temp!=NULL){
						somma+=leggiNodo(temp);
						temp=succFratello(temp);
					}
				temp=primoFiglio(n);


				if(temp!=radiceAlbero() && !foglia(n)){
						scriviNodo(n,somma);
					}

//ok e un modo
/*		int somma=0;

	Nodo temp=primoFiglio(n);

	while(temp!=NULL){
			somma+=leggiNodo(temp);
			temp=succFratello(temp);
		}
	temp=primoFiglio(n);


	if(temp!=radiceAlbero() && !foglia(n)){
			scriviNodo(n,somma);
		}
	while(temp!=NULL){
		padreSommaFigli2(temp);
		temp=succFratello(temp);
	}
	*/

}


#endif /* ALBERO_H_ */
