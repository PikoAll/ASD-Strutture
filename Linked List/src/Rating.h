/*
 * Rating.h
 *
 *  Created on: 16 ott 2020
 *      Author: peppi
 */

#ifndef RATING_H_
#define RATING_H_

#include<string>
using namespace std;

class Rating {
public:
	Rating(){};
	Rating(string,string,int);
	virtual ~Rating();

	void setNome(string);
	void setProdotto(string);
	void setRating(int);
	string getNome();
	string getProdotto();
	int getRating();
private:
	string utente;
	string prodotto;
	int rating;

};

#endif /* RATING_H_ */
