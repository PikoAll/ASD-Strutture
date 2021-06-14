/*
 * Rating.cpp
 *
 *  Created on: 16 ott 2020
 *      Author: peppi
 */

#include "Rating.h"
#include <string>
#include <iostream>

using namespace std;

Rating::Rating(string nome,string prodotto, int v) {
	// TODO Auto-generated constructor stub
	setNome(nome);
	setProdotto(prodotto);
	setRating(v);
}


void Rating::setNome(string s){
	utente=s;
}

void Rating::setProdotto(string s){
	prodotto=s;
}
void Rating::setRating(int x){
	rating=x;
}

string Rating::getNome(){
	return utente;
}

string Rating::getProdotto(){
	return prodotto;
}

int Rating::getRating(){
	return rating;
}

Rating::~Rating() {
	// TODO Auto-generated destructor stub
}

