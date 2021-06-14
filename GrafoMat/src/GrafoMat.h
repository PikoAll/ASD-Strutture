/*
 * GrafoMat.h
 *
 *  Created on: 13 ott 2020
 *      Author: peppi
 */

#ifndef GRAFOMAT_H_
#define GRAFOMAT_H_


template<class P>
class InfoArco
{
 public:
	P peso;			//peso dell'arco tra due nodi
	bool vuoto;		//indica se è presente l'elemento o meno

	InfoArco()
	{
		vuoto = true;
	}
};


template<class E, class P>
	class InfoNodo {
 public:
	E   etichetta;
	bool marcato;
	bool vuoto;
	void* info;
	InfoArco<P>* archi;

	InfoNodo(){
		info = 0;
		vuoto = true;
		marcato=false;
	}

	~InfoNodo(){
		if (!vuoto)
			delete [] archi;
	}
};


class NodoG{
 public:
	NodoG(int i){
		nodoId = i;
	}
	NodoG(){
	}
	int getId(){ return nodoId; }
	void setId(int id) {nodoId = id;}


 private:
	int nodoId;
};


template<class E, class P>
class GrafoMat : public Grafo<E, P, NodoG > {
 public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
	typedef typename Grafo_::ListaNodiPosizione ListaNodiPos;

    GrafoMat(int);
    ~GrafoMat();

    bool vuoto() const;
    void insNodo(NodoG&);
    void insArco(Nodo, Nodo, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);
    bool esisteNodo(Nodo)const;
    bool esisteArco(Nodo,Nodo)const;
    ListaNodi Adiacenti(Nodo) const ;
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;
    void scriviEtichetta(Nodo, Etichetta) ;
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;

		int numNodi(){
			return nodi;
		};
		int numArchi(){
			return archi;
		};
/////////////////////////////////////////////////////////////
	void setMarcato(Nodo &);
	bool getMarcato(Nodo &);
	void settaNoMarcati();

///////////////////////////////////////////////////////////Esercizi
/*
 * sameColorPath(Node n1, Node n2): restituisce true se esiste un path che collega il nodo n1 al
   nodo n2 e tutti i nodi presenti in tale path sono dello stesso colore, false altrimenti;
 */
bool sameColorpath(Nodo & ,Nodo &);

/*
 * • uniformColorPath(Node n1, Node n2): restituisce true se esiste un path che collega il nodo n1
	al nodo n2 ed ogni nodo presente in tale path `e etichettato con un colore diverso da quello con
	cui `e etichettato il nodo precedente, false altrimenti.
 *
 */
bool uniformColorPath(Nodo&, Nodo&);

/*
 * Dato un grafo orientato i cui archi hanno peso 1 o −1, implementare un metodo in C++ che dati due
nodi a e b individui il numero di cammini da a a b tale che, gli archi nella sequenza corrispondente ad
ogni cammino siano etichettati con 1. Inoltre fornire la media della lunghezza dei cammini individuati.
Prevedere una funzione main che contenga una procedura di inserimento automatico e successivamente
il test dei metodi implementati.
 */
double mediaLunghezzaCammini(Nodo,Nodo);
int cammino(Nodo , Nodo, int &);		//sarebbe camminoEsistente pero ho bisogno che mi ritorna un in e non un bool

/*
 * countSame(Node n1): restituisce il numero di nodi raggiungibili da n1 e aventi la sua stessa
	etichetta;
 */

int countSame(Nodo);
int supportoCountSame(Nodo &, Etichetta);

/*
 * meanN2(Node n1): restituisce la media dei valori delle etichette dei nodi raggiungibili da n1 con
cammini di lunghezza 2.
 */
double meanN2(Nodo);
double supportoMeanN2(Nodo &, int&, int&, int);
 private:
    InfoNodo<E,P>* matrice;
    int dimensione;
    int nodi;
	int archi;
};

template<class E, class P>
	GrafoMat<E, P>::GrafoMat(int _dimensione){
	dimensione = _dimensione;
	nodi = 0;
	archi = 0;
	matrice = new InfoNodo<E,P>[dimensione];
	for (int i=0; i<dimensione; i++)
		matrice[i].archi = new InfoArco<P>[dimensione];
}

template<class E, class P>
	GrafoMat<E, P>::~GrafoMat() {
	delete [] matrice;
}

template<class E, class P>
	bool GrafoMat<E, P>::vuoto() const {
	return (nodi == 0);
}

template<class E,class P>
void GrafoMat<E,P>::insNodo(Nodo &N){

	int n=0;
	if(nodi<dimensione){
		while(matrice[n].vuoto==false){
			n++;
		}
		nodi++;
		matrice[n].vuoto=false;
	}
	N.setId(n);

}

template<class E, class P>
	void GrafoMat<E, P>::insArco(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
	matrice[n1.getId()].archi[n2.getId()].vuoto = false;
	archi++;
}

template<class E, class P>
void GrafoMat<E,P>::cancNodo(Nodo n){
	// ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
		bool canc = true;
		int i;
		for (i=0; i < dimensione && canc; i++)
			if (!matrice[n.getId()].archi[i].vuoto)
				canc = false;
		for (i=0; i < dimensione && canc; i++)
			if (!matrice[i].vuoto && !matrice[i].archi[n.getId()].vuoto)
				canc = false;

		if (canc){
			delete matrice[n.getId()].archi;
			matrice[n.getId()].vuoto = true;
		}

}


template<class E, class P>
void GrafoMat<E,P>::cancArco(Nodo n1, Nodo n2){
	matrice[n1.getId()].archi[n2.getId()].vuoto=true;
	archi--;
}

template<class E,class P>
typename GrafoMat<E,P>::ListaNodi GrafoMat<E,P>::Adiacenti(Nodo n)const{
	ListaNodi list;
	for(int i=0; i<dimensione; i++){
		if(!matrice[n.getId()].archi[i].vuoto){
			list.inserisci(new NodoG(i),list.inizio());
		}
	}
	return list;
}

template<class E, class P>
typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::list_nodi() const {
	ListaNodi list;
	for (int i = 0; i < dimensione; i++)
		if (!matrice[i].vuoto)
			list.inserisci(new NodoG(i), list.inizio());
	return list;
}

template<class E, class P>
	E GrafoMat<E, P>::leggiEtichetta(Nodo n) const {
	return matrice[n.getId()].etichetta;
}

template<class E, class P>
	void GrafoMat<E, P>::scriviEtichetta(Nodo n, E etichetta) {
	matrice[n.getId()].etichetta = etichetta;
}

template<class E, class P>
	P GrafoMat<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	return matrice[n1.getId()].archi[n2.getId()].peso;
}

template<class E, class P>
	void GrafoMat<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
}

template<class E,class P>
void GrafoMat<E,P>::setMarcato(Nodo & n){
	matrice[n.getId()].marcato=true;
}

template<class E,class P>
bool GrafoMat<E,P>::getMarcato(Nodo &n){
	return matrice[n.getId()].marcato;
}

template<class E,class P>
void GrafoMat<E,P>::settaNoMarcati(){
	for(int i=0; i<dimensione;i++){
		if(!matrice[i].vuoto){
			matrice[i].marcato=false;
		}
	}
}

template<class E, class P>
bool GrafoMat<E,P>::sameColorpath(Nodo & n, Nodo & n2){

//system("pause");
	ListaNodi lista=Adiacenti(n);
	ListaNodiPos p,p2;
	p=lista.inizio();
	bool fl=false;
	p2=lista.inizio();


	cout<<"\nPercorso "<<leggiEtichetta(n);


	while(!lista.fine(p)){

	//	if(leggiEtichetta(*lista.leggi(p))==leggiEtichetta(n2)){
		if(lista.leggi(p)->getId()== n2.getId() && leggiEtichetta(n)==leggiEtichetta(n2)){
		cout<<" :"<<leggiEtichetta(n2)<<" Trovatooo" <<endl;
			fl=true;
			return fl;
		}


		p=lista.succ(p);
	}

	setMarcato(n);


	while(!lista.fine(p2)){
		Nodo n3=(*lista.leggi(p2));
		if(getMarcato(n3)==false && leggiEtichetta(n3)==leggiEtichetta(n)){
		fl=sameColorpath(n3,n2);

		}
		if(fl==true){
			return fl;
		}
		p2=lista.succ(p2);
	}


return fl;
}

template<class E, class P>
bool GrafoMat<E,P>::uniformColorPath(Nodo & n, Nodo & n2){
/*
	ListaNodi lista=Adiacenti(n);
	ListaNodiPos p,p2;
	p=lista.inizio();
	bool fl=false;
	p2=lista.inizio();


	cout<<"\nPercorso "<<leggiEtichetta(n);

	while(!lista.fine(p)){

		if(leggiEtichetta(*lista.leggi(p))==legiEtichetta(n2)){
			cout<<": Trovato "<<leggiEtichetta(n2)<<endl;
			fl=true;
			return fl;
		}
		p=lista.succ(p);

	}

	while(!lista.fine(p2)){
		if(fl==true){
			return fl;
		}
		Node n3=(*lista.leggi(p2));
		fl=unif
	}*/

	ListaNodi lista=Adiacenti(n);
	ListaNodiPos p,p2;
	p=lista.inizio();
	bool fl=false;
	p2=lista.inizio();


	cout<<"\nPercorso "<<leggiEtichetta(n);


	while(!lista.fine(p)){

	//	if(leggiEtichetta(*lista.leggi(p))==leggiEtichetta(n2)){
		if(lista.leggi(p)->getId()== n2.getId() && leggiEtichetta(n)!=leggiEtichetta(n2)){
		cout<<" :"<<leggiEtichetta(n2)<<" Trovatooo" <<endl;
			fl=true;
			return fl;
		}


		p=lista.succ(p);
	}

	setMarcato(n);


	while(!lista.fine(p2)){
		Nodo n3=(*lista.leggi(p2));
		if(getMarcato(n3)==false && leggiEtichetta(n3)!=leggiEtichetta(n)){
		fl=uniformColorPath(n3,n2);

		}
		if(fl==true){
			return fl;
		}
		p2=lista.succ(p2);
	}


return fl;



}

template<class E,class P>
double GrafoMat<E,P>::mediaLunghezzaCammini(Nodo n1,Nodo n2){

int contaPassi=0;
int x=cammino(n1,n2,contaPassi);

cout<<"\n x e: "<<x<<" e contaPassi e "<<contaPassi;
return 0.0;
}


template<class E,class P>
int GrafoMat<E,P>::cammino(Nodo n1, Nodo n2, int & contaPassi){
	cout<<"\nCammino con nodo "<<leggiEtichetta(n1)<<endl;
	ListaNodi lista=Adiacenti(n1);
	ListaNodiPos p,p2;
	Peso peso=1;
	int numero=0;
	p=lista.inizio();
	p2=lista.inizio();
	bool fl=false;

	while(!lista.fine(p)){
	//	cout<<"nodo "<<leggiEtichetta(*lista.leggi(p))<<" peso "<<leggiPeso(n1,(*lista.leggi(p)))<<"    ";
		if(lista.leggi(p)->getId()==n2.getId() &&  leggiPeso(n1,(*lista.leggi(p)))==1){
			cout<<" : trovato "<< leggiEtichetta(n2)<<endl;
		//	contaPassi++;
			numero++;
			fl=true;
		}
		p=lista.succ(p);

	}

	while(!lista.fine(p2)){
		Nodo n3=(*lista.leggi(p2));
		if(leggiPeso(n1,n3)==1){
			contaPassi++;


			cout<<"etichetta 3 "<<leggiEtichetta(n3);
		 numero=numero+cammino(n3,n2,contaPassi);
		}
		p2=lista.succ(p2);

	}
/*
	if(fl==false){
		contaPassi--;
	}
	*/

	return numero;
}


template<class E,class P>
int GrafoMat<E,P>::countSame(Nodo n){

//Etichetta e=leggiEtichetta(n);

int x=supportoCountSame(n,leggiEtichetta(n));

cout<<" la somma e: "<<x<<endl;

return x;
}

template<class E, class P>
int GrafoMat<E,P>::supportoCountSame(Nodo &n, Etichetta e){

	ListaNodi lista=Adiacenti(n);
		ListaNodiPos p,p2;
		p=lista.inizio();
		p2=lista.inizio();
		int somma=0;

		while(!lista.fine(p)){

			if(leggiEtichetta(*lista.leggi(p))==e && getMarcato(n)==false){
				somma++;
			}
			p=lista.succ(p);
		}

		setMarcato(n);

		while(!lista.fine(p2)){
			Nodo n2=*lista.leggi(p2);
			somma=somma+supportoCountSame(n2,e);
			p2=lista.succ(p2);
		}


		return somma;

}

template<class E, class P>
double GrafoMat<E,P>::meanN2(Nodo n){

	int sommaEtichette=0;
	int sommaNodi=0;
	supportoMeanN2(n,sommaEtichette,sommaNodi,0);
	double media=(sommaEtichette/sommaNodi);
	cout<<"la media e: "<<media<< "\n "<<sommaEtichette<<" "<<sommaNodi<<endl;
	return 0;

}

template<class E,class P>
double GrafoMat<E,P>::supportoMeanN2(Nodo &n, int &sommaE, int & sommaN,int cammino){

	ListaNodi lista=Adiacenti(n);
	ListaNodiPos p,p2;
	p=lista.inizio();
	p2=lista.inizio();

	if(cammino==1){

		while(!lista.fine(p)){
			cout<<leggiEtichetta(*lista.leggi(p))<<" ";
			sommaE=sommaE+leggiEtichetta(*lista.leggi(p));
			sommaN++;
			p=lista.succ(p);
		}

	}

	while(!lista.fine(p2)){
		Nodo n2=(*lista.leggi(p2));
		if(cammino>1){
			return 0 ;
		}else{
			supportoMeanN2(n2,sommaE,sommaN,cammino+1);
		}
		p2=lista.succ(p2);
	}
	return 0;
}


#endif /* GRAFOMAT_H_ */
