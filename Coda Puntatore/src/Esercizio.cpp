/*
 * Esercizio.cpp
 *
 *  Created on: 20 ott 2020
 *      Author: peppi
 */

#include<iostream>
#include"Esercizio.h"

using namespace std;

void Esercizio::inserisci(int k){

	if(k<=3){
		c[1].inCoda(k);
	}else if(k>3 && k<=6){
		c[2].inCoda(k);
	}else if(k>6 && k<=9){
		c[3].inCoda(k);
	}

}

void Esercizio::cancella(int c1){

	c[c1].fuoriCoda();

}

double Esercizio::media(int c1){

	Coda<int> q=c[c1];

	double med=0;
	int i=0;
	while(!q.vuota()){
		med+=q.leggiCoda();
		q.fuoriCoda();
		i++;
	}

	return med/i;
}

int Esercizio::numeroElementi(int c1){
	return c[c1].size();
}

void Esercizio::stampa(int x){

	Coda<int> q=c[x];
cout<<"Coda:"<<endl;
	while(!q.vuota()){
		cout<<q.leggiCoda()<<" ";
		q.fuoriCoda();
	}


}

