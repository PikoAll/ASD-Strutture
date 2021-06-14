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
	cout << "!!!Hello World Pila!!!" << endl; // prints !!!Hello World!!!

	Pila<int> p;

	p.inPila(5);
	p.inPila(4);
	p.inPila(3);
	p.inPila(2);
	p.inPila(1);

	cout<<p.leggi()<<endl;
	p.fuoriPila();
	cout<<p.leggi()<<endl;
	p.fuoriPila();
	cout<<p.leggi()<<endl;
	p.fuoriPila();
	cout<<p.leggi()<<endl;







	return 0;
}
