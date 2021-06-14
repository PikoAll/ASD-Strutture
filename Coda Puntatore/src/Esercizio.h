/*
 * Esercizio.h
 *
 *  Created on: 20 ott 2020
 *      Author: peppi
 */

#ifndef ESERCIZIO_H_
#define ESERCIZIO_H_

/*
 * 5. Una struttura dati acquisisce numeri interi da 1 a 9 che inserisce in tre code secondo il seguente schema.
Gli interi da 1 a 3 vengono inseriti nella prima coda, quelli da 4 a 6 nella seconda, e i restanti nella
terza.
La struttura mette a disposizione una serie di metodi che permettono di conoscere e cambiare il suo
stato.
Realizzare in C++ la seguente classe che implementa la struttura appena descritta.
class Bins {
// inserisce l’intero k nella corrispondente coda
void insert(int k);
// effettua un fuoriCoda dalla coda c
void delete(int c);
// restituisce la media dei valori attualmente memorizzati nella coda c
double mean(int c);
// restituisce il numero di elementi inseriti nella coda c
int freq(int c);
private:
coda<int> bin[3];
}
 */

#include "Coda.h"

class Esercizio{

public:
	void inserisci(int k);
	void cancella(int c);
	double media(int c);
	int numeroElementi(int c);
	void stampa(int x);

private:
	Coda<int> c[3];

};


#endif /* ESERCIZIO_H_ */
