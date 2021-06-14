/*
 * Reccomender.cpp
 *
 *  Created on: 19 ott 2020
 *      Author: peppi
 */

#include<iostream>
#include"Recommender.h"
#include"Rating.h"
#include"LinkedList.h"
#include<string>

using namespace std;

void Recommender::inserisci(string s, string ss, int x){
	//Rating c(s,ss,x);
	//Nodo<Rating> c1;
	//c1=new Rating(s,ss,x);
	Rating c1(s,ss,x);
	//Nodo<Rating> c2=new Nodo<Rating>(c1);
	ratings.inserisci(c1,ratings.inizio());



}

void Recommender::stampa(){

	LinkedList<Rating>::posizione p=ratings.inizio();
	ratings.leggi(p);
	while(!ratings.fine(p)){
		cout<<ratings.leggi(p).getNome()<<" "<<ratings.leggi(p).getProdotto()<<" "<<ratings.leggi(p).getRating()<<endl;
		p=ratings.succ(p);
	}

}
