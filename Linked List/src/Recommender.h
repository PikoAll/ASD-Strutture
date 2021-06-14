/*
 * Recommender.h
 *
 *  Created on: 16 ott 2020
 *      Author: peppi
 */

#ifndef RECOMMENDER_H_
#define RECOMMENDER_H_
#include"Rating.h"
#include"LinkedList.h"

#include<string>
using namespace std;

class Recommender {
public:

	void inserisci(string,string,int); //inserisci nella lista traings
	double media(string);
	double mediaItem(string);
	LinkedList<string> rated(string);
	void stampa();

private:
	LinkedList<Rating> ratings;

};

#endif /* RECOMMENDER_H_ */
