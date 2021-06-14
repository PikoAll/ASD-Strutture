//============================================================================
// Name        : Pila.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Pila.h"
using namespace std;

int main() {
	cout << "!!!Hello World Pila Puntatori!!!" << endl; // prints !!!Hello World!!!

		Pila<int> p;

		p.inPilaBack(5);
		p.inPilaBack(4);
		p.inPilaBack(9);
		p.inPilaBack(3);
		p.inPilaBack(2);
		p.inPilaBack(7);
		p.inPilaBack(1);
/*
		cout<<p.leggiPila()<<endl;
		p.fuoriPilaFront();
		cout<<p.leggiPila()<<endl;
		p.fuoriPilaFront();
		cout<<p.leggiPila()<<endl;
		p.fuoriPilaFront();
		cout<<p.leggiPila()<<endl;
*/
		p=p.ordinaPila(p);
		p.stampaPila(p);
		p.eliminaMaggioreDi(p,5);
		p.stampaPila(p);

return 0;
}
