/*
 * Albero.h
 *
 *  Created on: 9 nov 2019
 *      Author: peppi
 */


#ifndef ALBEROBINARIO_H_INCLUDED
#define ALBEROBINARIO_H_INCLUDED

#include<iostream>
#include"Cella.h"
#include <limits.h>
#include<vector>
using namespace std;

template<class T>
class BinAlbero{
public:

    typedef T tipoelem;
    typedef Cella<T>*  Nodo; //puntatore ad una classe di tipo cella
    BinAlbero();//costruttore
    //~BinAlbero(); distruttore

    //operatori
    void creaBinAlbero();
    bool binAlberoVuoto();
    Nodo binRadice();//restituisce la radice dell'albero
    Nodo binPadre(Nodo);//restituisce il padre di Nodo
    Nodo figlioSinistro(Nodo);//restituisce il figlio sinistro di Nodo
    Nodo figlioDestro(Nodo);//restituisce il figlio destro di Nodo
    bool sinistroVuoto(Nodo);
    bool destroVuoto(Nodo);
    void cancSottoBinAlbero(Nodo); //cancella il sottoalbero con radice in Nodo
    tipoelem leggiNodo(Nodo); //restituisce l'elemento di Nodo
    void scriviNodo(Nodo,tipoelem);
    void insBinRadice(Nodo);
    void insFiglioSinistro(Nodo);
    void insFiglioDestro(Nodo);
    void stampaSottoAlbero(Nodo n);
    void stampa();
    //SERVIZIO
    int count(Nodo n); //restituisce il numero di nodi del sottoalbero a partire da n
    int altezza(Nodo n);//restituisce l'altezza di nodo n
    int livello(Nodo n);//restituisce il livello del nodo n
    void modificaNumeroNodi(Nodo n);
    int livello_n(Nodo,int k);//restituisce il numero di nodi di livello k(larghezza di livello)
    bool is_height_balanced(Nodo);//stabilisce se è bilanciato in altezza
    bool foglia(Nodo);
    int altezzaMinimale(Nodo);//l'altezza minima dal nodo ad una della sue foglie
    int larghezza(Nodo);
    int lunghezzaDiCammino(Nodo,int);//somma delle distanze dai nodi alla radice
    void creaSottoAlbero(BinAlbero<T> tree,Nodo n,Nodo corrente); //crea un sottoalbero a partire dal Nodo n in tree
    void inserisciSottoAlberoaSinistraDelNodo(BinAlbero<T> subtree,Nodo n,Nodo d);//inserisce il sotto albero subtree in this a partire dal nodo sinistro di n, in cui il nodo d è la radice del sotto albero subtree
    void inserisciSottoAlberoaDestraDelNodo(BinAlbero<T> subtree,Nodo n,Nodo d);//inserisce il sottoalbero subtree in this a partire dal nodo destro di n,in cui il nodo d è la radice del sotto albero subtree
    void inserisciSottoAlbero(BinAlbero,Nodo,Nodo);
    void mutate(BinAlbero<T>& tree1,BinAlbero<T>& tree2,Nodo n1,Nodo n2);//scambia i sottoalberi che hanno radice in n1 per tree1 e n2 per tree2
    // STAMPA VISITA
    void stampaPreOrdine(Nodo n);
    void stampaPostOrdine(Nodo n);
    void stampaSimmetrica(Nodo n);

    ////////////////
    void cancellaFogliePari(Nodo);
    int level(Nodo);	//calcola e restituisce il numero di nodi di livello pari il cui valore è "rosso" e che hanno almeno un figlio il cui valore è "bianco";
    int greenFoglie(Nodo);	//calcola e restituisce il numero di foglie il cui valore è "verde";
    int nNodiDispariLivellok(Nodo, int);
    int numeroFogliePari(Nodo);
    int padrePari(Nodo);
    int nodiDivisibile(Nodo,int);	//calcola e restituisce il numero di nodi di livello k il cui valore divisibile per 3
    bool zeroUno(Nodo);	///* Stabilisce se l’albero rispetta le propiet`a di un albero zero-one, ovvero: * 1) la radice ha valore 0; * 2) ogni Nodo 0, ha come figli due nodi 1; * 3) ogni Nodo 1, ha come figli due nodi 0. */ bool is_zero_one(const Bintree< _value_type > &B)
    int zeroNodi(Nodo);	//restituisce il numero di nodi 0 dell'abero

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //provaaaa
    /*
     * Dato un albero binario di elementi di tipo intero, implementare in C++ la funzione int multipli(Tree<int>
		T) che modifica l’etichetta di ogni nodo n dell’albero memorizzandoci il numero dei nodi pari presenti
		nel sottoalbero radicato in n.
     */
    void modificaConNumeroPariFigli(BinAlbero<int>);
    int supportoAmCNPF(Nodo n, BinAlbero<int>t, int& x);
    /*
     *  int odd(bintree<int> &T, int k): calcola e restituisce il numero di nodi di livello k il cui
		valore dispari;
		• int even leafs(bintree<int> &T): calcola e restituisce il numero di foglie il cui valore pari;
		• int leafs with even parent(bintree<int> &T): calcola e restituisce il numero di foglie che
		hanno come genitore un nodo il cui valore pari.
     *
     */
    	int numeroNodiDiLivelloK(BinAlbero<int> &t,int k);
    	int nFogliePari(BinAlbero<int> &);
    //	int fogliaGenitorePari(BinAlbero<int> &t);
    	/*
    	 * • int d3(bintree<int> &T, int k): calcola e restituisce il numero di nodi di livello k il cui valore
			divisibile per 3;
			• int lp(bintree<int> &T): calcola e restituisce il numero di foglie il cui valore pari;
			• int l2p(bintree<int> &T): calcola e restituisce il numero di foglie che hanno come genitore un
			nodo il cui valore un multiplo di 5.
    	 */
    	int d3(BinAlbero<int> &t, int k);
    	int l2p(BinAlbero<int> &t);
    	//esame mio superato
    	void mediaNodi(Nodo);
    	void supportoMediaNodi(Nodo, int ,double []);

private:
    void larghezza(Nodo,vector<T>&,int);
    void is_height_balanced(Nodo,bool&);
    int numeroElementi;
    Nodo radice;
    ////
    int cont=0;
    int nFoglieVerdi=0;
    int nDispari=0;
    int nPari=0;
    int nPari1=0;
    bool fl;
    int contZero=0;
    Nodo temp;
};

template<class T>
BinAlbero<T>::BinAlbero(){
    creaBinAlbero();
}

template<class T>
void BinAlbero<T>::creaBinAlbero(){
    numeroElementi=0;
    radice=NULL;//L'albero è vuoto
}

template<class T>
bool BinAlbero<T>::binAlberoVuoto(){
    return(radice==NULL);
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::binRadice(){
    return (radice);
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::binPadre(Nodo n){
    if(n!=radice)
        return(n->getDAD());
    else
        return NULL;
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::figlioSinistro(Nodo n){
    return(n->getSX());
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::figlioDestro(Nodo n){
    return(n->getDX());
}

template<class T>
bool BinAlbero<T>::sinistroVuoto(Nodo n){
    return(n->getSX()==NULL);
}

template<class T>
bool BinAlbero<T>::destroVuoto(Nodo n){
    return(n->getDX()==NULL);
}

template<class T>
void BinAlbero<T>::insBinRadice(Nodo n){
    if(binAlberoVuoto()){
        radice=n;
    }
}

template<class T>
void BinAlbero<T>::insFiglioSinistro(Nodo n){
    if(sinistroVuoto(n)){
        n->setSX(new Cella<T>);
        n->getSX()->setDAD(n);
        n->getSX()->setSX(NULL); //il figlio sinistro di n appena inserito non ha figlio sinistro
        n->getSX()->setDX(NULL);
    }
}

template<class T>
void BinAlbero<T>::insFiglioDestro(Nodo n){
    if(destroVuoto(n)){
        n->setDX(new Cella<T>);
        n->getDX()->setDAD(n);
        n->getDX()->setSX(NULL);
        n->getDX()->setDX(NULL);
    }
}

template<class T>
typename BinAlbero<T>::tipoelem BinAlbero<T>::leggiNodo(Nodo n){
    if(n!=NULL)
        return(n->getElemento());
}

template<class T>
void BinAlbero<T>::scriviNodo(Nodo n,tipoelem a){
    if(n!=NULL){
        n->setElemento(a);
        numeroElementi++;
    }
}

template<class T>
void BinAlbero<T>::cancSottoBinAlbero(Nodo n){
    if(n!=NULL){
        if(!sinistroVuoto(n))
            cancSottoBinAlbero(figlioSinistro(n));
        if(!destroVuoto(n))
            cancSottoBinAlbero(figlioDestro(n));
        if(n!=radice){
            Nodo padre=binPadre(n);
            if(figlioSinistro(padre)==n)
                padre->setSX(NULL); //se il nodo da cancellare è il figlio sinistro
            else
                padre->setDX(NULL); //se il nodo da cancellare è il figlio destro
        }else{
            radice=NULL; //se il nodo da cancellare è radice
        }
        numeroElementi--;
    }
    if(!binAlberoVuoto())
        modificaNumeroNodi(binRadice());
}


template<class T>
void BinAlbero<T>::stampaSottoAlbero(Nodo n){
    std::cout<<"["<<n->getElemento()<<"("<<n->getNumeroNodi()<<")"<<", ";
    if(!sinistroVuoto(n))
        stampaSottoAlbero(figlioSinistro(n));
    else std::cout<<"NIL";
    std::cout<<", ";
    if(!destroVuoto(n))
        stampaSottoAlbero(figlioDestro(n));
    else std::cout<<"NIL";
    std::cout<<" ]";

}


template<class T>
void BinAlbero<T>::stampa(){
    if(!binAlberoVuoto())
        stampaSottoAlbero(binRadice());
    else
        std::cout <<"[]"<<std::endl;
    std::cout << std::endl;

}

template<class T>
int BinAlbero<T>::count(Nodo n){
     int sx=0,dx=0;
     if(!sinistroVuoto(n))
        sx=count(figlioSinistro(n));
     if(!destroVuoto(n))
        dx=count(figlioDestro(n));
     return(sx+dx+1);
}

template<class T>
int BinAlbero<T>::altezza(Nodo n){
    if(sinistroVuoto(n) && destroVuoto(n))
        return (0);
    int u=0;
    if(!sinistroVuoto(n))
        u=altezza(figlioSinistro(n));
    int v=0;
    if(!destroVuoto(n))
        v=altezza(figlioDestro(n));
    if(u>v)
        return (u+1);
    else
        return (v+1);

}

template<class T>
void BinAlbero<T>::modificaNumeroNodi(Nodo n){
    if(!binAlberoVuoto()){
        if(n!=NULL){
            n->setNumeroNodi(count(n));
                modificaNumeroNodi(figlioSinistro(n));
                modificaNumeroNodi(figlioDestro(n));
        }
    }
}

template<class T>
void BinAlbero<T>::stampaPreOrdine(Nodo n){
    if(!binAlberoVuoto()){
        if(n!=NULL){
            cout<<n->getElemento()<<" ";
            stampaPreOrdine(figlioSinistro(n));
            stampaPreOrdine(figlioDestro(n));
        }
    }
}

template<class T>
void BinAlbero<T>::stampaPostOrdine(Nodo n){
    if(n==NULL)
        return;
    stampaPostOrdine(figlioSinistro(n));
    stampaPostOrdine(figlioDestro(n));
    cout<<n->getElemento()<<" ";
}

template<class T>
void BinAlbero<T>::stampaSimmetrica(Nodo n){
    if(n==NULL)
        return;
    stampaSimmetrica(figlioSinistro(n));
    cout<<n->getElemento()<<" ";
    stampaSimmetrica(figlioDestro(n));
}

//Nodo corrente sarà la radice del sottoalbero
/*crea un sottoalbero di tree che ha come radice il nodo n*/
template<class T>
void BinAlbero<T>::creaSottoAlbero(BinAlbero<T> tree,Nodo n,Nodo corrente){
   this->scriviNodo(corrente,tree.leggiNodo(n));
   if(!tree.sinistroVuoto(n)){
        if(this->sinistroVuoto(corrente)){
            this->insFiglioSinistro(corrente);
        }
        creaSottoAlbero(tree,tree.figlioSinistro(n),this->figlioSinistro(corrente));
   }
   if(!tree.destroVuoto(n)){
        if(this->destroVuoto(corrente)){
            this->insFiglioDestro(corrente);
        }
        creaSottoAlbero(tree,tree.figlioDestro(n),this->figlioDestro(corrente));
   }
   this->modificaNumeroNodi(this->binRadice());
}

template<class T>
void BinAlbero<T>::inserisciSottoAlbero(BinAlbero<T> subtree,Nodo n,Nodo d){
    this->scriviNodo(n,subtree.leggiNodo(d));
    if(!subtree.sinistroVuoto(d)){
        if(this->sinistroVuoto(n)){
            this->insFiglioSinistro(n);
        }
        inserisciSottoAlbero(subtree,this->figlioSinistro(n),subtree.figlioSinistro(d));
    }
    if(!subtree.destroVuoto(d)){
        if(this->destroVuoto(n)){
            this->insFiglioDestro(n);
        }
        inserisciSottoAlbero(subtree,this->figlioDestro(n),subtree.figlioDestro(d));
    }
}

template<class T>
void BinAlbero<T>::inserisciSottoAlberoaSinistraDelNodo(BinAlbero<T> subtree,Nodo n,Nodo d){
    using namespace std;
    if(this->sinistroVuoto(n)){
        this->insFiglioSinistro(n);
        inserisciSottoAlbero(subtree,this->figlioSinistro(n),subtree.binRadice());
        this->modificaNumeroNodi(this->binRadice());
    }else{
        cout<<"L'operazione non puo' essere eseguita";
    }
}

template<class T>
void BinAlbero<T>::inserisciSottoAlberoaDestraDelNodo(BinAlbero<T> subtree,Nodo n,Nodo d){
    using namespace std;
    if(this->destroVuoto(n)){
        this->insFiglioDestro(n);
        inserisciSottoAlbero(subtree,this->figlioDestro(n),subtree.binRadice());
        this->modificaNumeroNodi(this->binRadice());
    }else{
        cout<<"L'operazione non puo' essere eseguita";
    }
}

template<class T>
void BinAlbero<T>::mutate(BinAlbero<T>& tree1,BinAlbero<T>& tree2,Nodo n1,Nodo n2){
    BinAlbero<T> sub1,sub2;
    sub1.insBinRadice(new Cella<T>);
    sub2.insBinRadice(new Cella<T>);
    sub1.creaSottoAlbero(tree1,n1,sub1.binRadice());
    sub2.creaSottoAlbero(tree2,n2,sub2.binRadice());
    BinAlbero<T>::Nodo padre1,padre2;
    padre1=tree1.binPadre(n1);
    padre2=tree1.binPadre(n2);
    int SxOrDx1,SxOrDx2; //flag
    if(n1==tree1.binPadre(n1)->getSX())
        SxOrDx1=0;//è un nodo sinistro
    else
        SxOrDx1=1;//è un nodo destro
    if(n2==tree1.binPadre(n2)->getSX())
        SxOrDx2=0;
    else
        SxOrDx2=1;
    tree1.cancSottoBinAlbero(n1);
    tree2.cancSottoBinAlbero(n2);
    if(SxOrDx2==0)
        tree2.inserisciSottoAlberoaSinistraDelNodo(sub1,padre2,sub1.binRadice());
    else
        tree2.inserisciSottoAlberoaDestraDelNodo(sub1,padre2,sub1.binRadice());
    if(SxOrDx1==0)
        tree1.inserisciSottoAlberoaSinistraDelNodo(sub2,padre1,sub2.binRadice());
    else
        tree1.inserisciSottoAlberoaSinistraDelNodo(sub2,padre1,sub2.binRadice());
    tree1.modificaNumeroNodi(tree1.binRadice());
    tree2.modificaNumeroNodi(tree2.binRadice());

}

template<class T>
int BinAlbero<T>::livello(Nodo n){
    int l=0;
    if(n==binRadice())
        return l;
    else{
        l=livello(binPadre(n));
    }
    return l+1;
}

template<class T>
int BinAlbero<T>::livello_n(Nodo n,int k){
    if(n==NULL)
        return 0;
    if(k==0)
        return 1;
    return livello_n(figlioSinistro(n),k-1)+livello_n(figlioDestro(n),k-1);
}

template<class T>
bool BinAlbero<T>::is_height_balanced(Nodo n){
    bool ris=false;
    is_height_balanced(n,ris);
    return ris;
}

template<class T>
void BinAlbero<T>::is_height_balanced(Nodo n,bool& ris){
     if(!binAlberoVuoto() || !ris){
        if(n!=NULL && figlioSinistro(n)!=NULL && figlioDestro(n)!= NULL){
            if((altezza(figlioSinistro(n))-altezza(figlioDestro(n)))>1 || (altezza(figlioDestro(n))-altezza(figlioSinistro(n)))>1)
                ris=false;
            else
                ris=true;
            (is_height_balanced(figlioSinistro(n),ris));
            (is_height_balanced(figlioDestro(n),ris));
        }
    }
}

template<class T>
bool BinAlbero<T>::foglia(Nodo n){
    if(figlioSinistro(n)==NULL && figlioDestro(n)==NULL){
        return true;
    }
}


template<class T>
int BinAlbero<T>::altezzaMinimale(Nodo n){
    int h1,hr;
    if(n==NULL)
        return UINT_MAX;
    if(foglia(n))
        return 0;
    h1=altezzaMinimale(figlioSinistro(n));
    hr=altezzaMinimale(figlioDestro(n));
    return min(h1,hr)+1;

}

template<class T>
void BinAlbero<T>::larghezza(Nodo t,vector<T>& conteggio,int level){
    if(t!=NULL){
        conteggio[level]=conteggio[level]+1;
        larghezza(figlioSinistro(t),conteggio,level+1);
        larghezza(figlioDestro(t),conteggio,level+1);
    }
}

template<class T>
int BinAlbero<T>::larghezza(Nodo t){
    vector<T> conteggio(30,0);
    larghezza(t,conteggio,0);
    int maxC=0;
    for(int i=0;i<=numeroElementi;i++){
        if(conteggio[i]>=maxC)
            maxC=conteggio[i];
    }
    return maxC;
}

template<class T>
int BinAlbero<T>::lunghezzaDiCammino(Nodo n,int l){
    if(n==NULL)
        return 0;
    return l+lunghezzaCammino(figlioSinistro(n),l+1)+lunghezzaCammino(figlioDestro(n),l+1);
}
//////////////////////////////////////////

template<class T>
void BinAlbero<T>::cancellaFogliePari(Nodo n){
	if(n!=NULL){

			if(!sinistroVuoto(n)){
				cancellaFogliePari(figlioSinistro(n));
			}
			if(!destroVuoto(n)){
				cancellaFogliePari(figlioDestro(n));
			}
			if(figlioSinistro(n)==NULL && figlioDestro(n)==NULL){

				cout<< n->getElemento()<<" ";
				system("pause");
				if(n->getElemento() % 2 ==0){
					cancSottoAlbero(n);
					}


			}

		}

}

template<class T>
int BinAlbero<T>::level(Nodo n){

if(!sinistroVuoto(n)){
	cont=level(figlioSinistro(n));
}
if(!destroVuoto(n)){
	cont=level(figlioDestro(n));
}
int a=livello(n);
if(a%2==0 and a!=0){
	if(n->getElemento()=="rosso"){
		if(figlioSinistro(n)!=NULL or figlioDestro(n)!=NULL){
		cout<<n->getElemento()<<"  livello "<<a;
		system("pause");
		Nodo b,c;
		b=figlioSinistro(n);
		c=figlioDestro(n);
		if(b->getElemento()=="bianco" or c->getElemento()=="bianco"){
			cout<<"b e "<<b->getElemento()<<" ";
			system("pause");
			 cont++;
			cout<<"cont e: "<<cont;
			system("pause");
		}
		}
	}
}
return cont;
}


template<class T>
int BinAlbero<T>::greenFoglie(Nodo n){

	if(!sinistroVuoto(n)){
		nFoglieVerdi=greenFoglie(figlioSinistro(n));
	}
	if(!destroVuoto(n)){
		nFoglieVerdi=greenFoglie(figlioDestro(n));
	}

	if(figlioSinistro(n)==NULL and figlioDestro(n)==NULL){
		if(n->getElemento()=="verde"){
			nFoglieVerdi++;
		}
	}
	return nFoglieVerdi;
}

template<class T>
int BinAlbero<T>::nNodiDispariLivellok(Nodo n, int k){

//	cout<<leggiNodo(figlioSinistro(n))<<"  "<<leggiNodo(figlioDestro(n))<<" k e "<<k<<endl;
//	system("pause");

	if(n==NULL)
	        return 0;
	    if(k==0)
	        return 1;
	    if(k==1){
	    	if(leggiNodo(figlioSinistro(n))%2!=0){
	    		nDispari++;
	    	}
	    	if(leggiNodo(figlioDestro(n))%2!=0){
	    		nDispari++;
	    	}
	    	cout<<"nDispari e: "<<nDispari;
	    }
	    nNodiDispariLivellok(figlioSinistro(n),k-1);
	    nNodiDispariLivellok(figlioDestro(n),k-1);
	    return nDispari;

}

template<class T>
int BinAlbero<T>::numeroFogliePari(Nodo n){

	if(!sinistroVuoto(n)){
		numeroFogliePari(figlioSinistro(n));
	}
	if(!destroVuoto(n)){
		numeroFogliePari(figlioDestro(n));
	}
	if(isFoglia(n)){
		if(leggiNodo(n)%2!=0){
			nPari++;
		}
	}
return nPari;
}


template<class T>
int BinAlbero<T>::padrePari(Nodo n){

	if(!sinistroVuoto(n)){
			padrePari(figlioSinistro(n));
		}
		if(!destroVuoto(n)){
			padrePari(figlioDestro(n));
		}
		if(isFoglia(n)){
			n=padre(n);
			if(leggiNodo(n)%2==0){
				cout<<leggiNodo(n)<<" ";
				nPari1++;
			}
		}
	return nPari1;

}

template<class T>
int BinAlbero<T>::nodiDivisibile(Nodo n,int k){
int temp=0;
	if(n==NULL)
		        return 0;
		    if(k==0)
		        return 1;
		    if(k==1){
		    	temp=leggiNodo(figlioSinistro(n))/3;
		    	if(temp*3==leggiNodo(figlioSinistro(n))){
		    		nDispari++;
		    	}
		    	temp=leggiNodo(figlioDestro(n))/3;
		    			    	if(temp*3==leggiNodo(figlioDestro(n))){
		    			    		nDispari++;
		    			    	}
		    	cout<<"nDispari e: "<<nDispari<<endl;
		    }
		    nodiDivisibile(figlioSinistro(n),k-1);
		    nodiDivisibile(figlioDestro(n),k-1);
		    return nDispari;

}


template<class T>
bool BinAlbero<T>::zeroUno(Nodo n){

	if(leggiNodo(binRadice())!=0){
		cout<<"errore radice non e 0 ";
		return fl=1;
	}

		if(!sinistroVuoto(n)){
			zeroUno(figlioSinistro(n));
		}
		if(destroVuoto(n)){
			zeroUno(figlioDestro(n));
		}

	cout<<leggiNodo(n)<<" ";
	system("pause");

	if(n!=binRadice()){
		n=padre(n);
	}
	if(leggiNodo(n)==0){
		if(leggiNodo(figlioSinistro(n))!=1 or leggiNodo(figlioDestro(n))!=1){
			cout<<"ciaoo";
			fl=1;
		}
	}
	if(leggiNodo(n)==1){
		if(leggiNodo(figlioSinistro(n))!=0 or leggiNodo(figlioDestro(n))!=0){
					cout<<"ciaoo 2";
					fl=1;
				}
	}


return fl;

}

template<class T>
int BinAlbero<T>::zeroNodi(Nodo n){

	if(!sinistroVuoto(n)){
		zeroNodi(figlioSinistro(n));
	}
	if(!destroVuoto(n)){
		zeroNodi(figlioDestro(n));
	}

	if(leggiNodo(n)==0){
		system("pause");
		contZero++;
	}
return contZero;
}


////////////////////////////////////////////////////////////////////////
template<class T>
void BinAlbero<T>::modificaConNumeroPariFigli(BinAlbero<int> t){
	int x=0;
	cout<<"vediamo: "<<supportoAmCNPF(t.binRadice(),t,x)<<endl;
	t.scriviNodo(t.binRadice(),x);
	x=0;
	if(!t.sinistroVuoto(t.binRadice())){
		BinAlbero<int> t1;
		Nodo radice=t.figlioSinistro(t.binRadice());
		if(!t.foglia(radice)){
		t1.insBinRadice(radice);
		modificaConNumeroPariFigli(t1);
		}
		}

	if(!t.destroVuoto(t.binRadice())){
			BinAlbero<int> t1;
			Nodo radice=t.figlioDestro(t.binRadice());
			if(!t.foglia(radice)){
			t1.insBinRadice(radice);
			modificaConNumeroPariFigli(t1);
			}
			}

}

template<class T>
int BinAlbero<T>::supportoAmCNPF(Nodo n, BinAlbero<int>t, int& x){
	cout<<t.leggiNodo(n)<<" ";
	if(t.leggiNodo(n)%2==0 && n!=t.binRadice()){
		x++;
	}
	if(!t.sinistroVuoto(n)){

		supportoAmCNPF(t.figlioSinistro(n),t,x);
	}

	if(!t.destroVuoto(n)){

		supportoAmCNPF(t.figlioDestro(n),t,x);
	}

	return x;
}

template<class T>
int BinAlbero<T>::numeroNodiDiLivelloK(BinAlbero<int> &t, int k){

	Nodo n=t.binRadice();
	//cout<<"radice e "<<t.leggiNodo(n)<<endl;
	if(k==0){
		return 1;
	}
	if(k==1){

		if(!t.sinistroVuoto(n)){
			cont++;
		}
		if(!t.destroVuoto(n)){
			cont++;
		}
		cout<<t.leggiNodo(n)<<" e cont e: "<<cont<<endl;
	}
	BinAlbero<int> t1;
	if(!t.sinistroVuoto(n)){
		t1.insBinRadice(t.figlioSinistro(t.binRadice()));
			numeroNodiDiLivelloK(t1,k-1);
	}
	t1.cancSottoBinAlbero(t1.binRadice());
	if(!t.destroVuoto(n)){
		t1.insBinRadice(t.figlioDestro(t.binRadice()));
			numeroNodiDiLivelloK(t1,k-1);
	}

	return cont;
}

template<class T>
int BinAlbero<T>::nFogliePari(BinAlbero<int> &t){

	Nodo n=t.binRadice();

	if(t.foglia(n)){
		if(t.leggiNodo(n)%2==0){
			cont++;
		}
	}

	if(!t.sinistroVuoto(n)){
		BinAlbero<int> t1;
		t1.insBinRadice(t.figlioSinistro(n));
		nFogliePari(t1);
	}
	if(!t.destroVuoto(n)){
		BinAlbero<int> t1;
		t1.insBinRadice(t.figlioDestro(n));
		nFogliePari(t1);
	}

	return cont;
}
/*
template<class T>
int BinAlbero<T>::fogliaGenitorePari(BinAlbero<int> &t ){

	Nodo n=t.binRadice();
	bool fl=false;

	if(!t.sinistroVuoto(n)){
		if(t.foglia(n)){

		}
	}


}
*/

template<class T>
int BinAlbero<T>::d3(BinAlbero<int>& t, int k){

	Nodo n=t.binRadice();
		//cout<<"radice e "<<t.leggiNodo(n)<<endl;
		if(k==0){
			return 1;
		}
		if(k==1){

			if(!t.sinistroVuoto(n)){
				if(t.leggiNodo(t.figlioSinistro(n))%3==0){
								cout<<"figlio sinistro "<<t.leggiNodo(t.figlioSinistro(n))<<endl;
								cont++;
							}
			}
			if(!t.destroVuoto(n)){
				if(t.leggiNodo(t.figlioDestro(n))%3==0){
								cout<<"figlio destro "<<t.leggiNodo(t.figlioDestro(n))<<endl;
								cont++;
							}
			}
			cout<<t.leggiNodo(n)<<" e cont e: "<<cont<<endl;
		}
		BinAlbero<int> t1;
		if(!t.sinistroVuoto(n)){
			t1.insBinRadice(t.figlioSinistro(t.binRadice()));
				d3(t1,k-1);
		}
		t1.cancSottoBinAlbero(t1.binRadice());
		if(!t.destroVuoto(n)){
			t1.insBinRadice(t.figlioDestro(t.binRadice()));
				d3(t1,k-1);
		}

		return cont;



}

template<class T>
int BinAlbero<T>::l2p(BinAlbero<int>&t){

	Nodo n=t.binRadice();

	if(t.foglia(n)){
		if(t.leggiNodo(temp)%5==0){
			cout<<t.leggiNodo(n)<<" il padre e "<<t.leggiNodo(temp)<<endl;
			cont++;
		}
	}

	BinAlbero<int> t1;
	if(!t.sinistroVuoto(n)){
		temp=n;
		t1.insBinRadice(t.figlioSinistro(t.binRadice()));
		l2p(t1);
	}
	t1.cancSottoBinAlbero(t1.binRadice());
	if(!t.destroVuoto(n)){
		temp=n;
		t1.insBinRadice(t.figlioDestro(t.binRadice()));
		l2p(t1);
	}
	return cont;
}

template<class T>
void BinAlbero<T>::mediaNodi(Nodo n){

	double v[altezza(n)+1];
	int k=altezza(n)+1;

	for(int i=0; i<k+1;i++){
		v[i]=0;
	}
	supportoMediaNodi(n,k,v);

	for(int i=0; i<k+1;i++){
		cout<<v[i]<<" ";
	}

	//ordinp il vettore
	int j=k;
	int temp=0;
	for(int i=0; i<(k/2)+1; i++){
		temp=v[i];
		v[i]=v[j];
		v[j]=temp;
		j--;
	}
	cout<<endl;
	for(int i=0; i<k+1;i++){
			cout<<v[i]<<" ";
		}

	//faccio media
	for(int i=0; i<k; i++){
		v[i]=v[i]/livello_n(n,i);
	}
	cout<<endl;
	for(int i=0; i<k+1;i++){
				cout<<v[i]<<" ";
			}
	cout<<endl;

}

template<class T>
void BinAlbero<T>::supportoMediaNodi(Nodo n,int k, double v[]){

	v[k]=v[k]+leggiNodo(n);
	cout<<"il nodo e "<<leggiNodo(n)<<" e k e"<<k<< "il vettore e "<<v[k]<<endl;

	if(!sinistroVuoto(n)){
		supportoMediaNodi(figlioSinistro(n),k-1,v);
	}

	if(!destroVuoto(n)){
		supportoMediaNodi(figlioDestro(n),k-1,v);
	}

}

#endif // ALBEROBINARIO_H_INCLUDED
