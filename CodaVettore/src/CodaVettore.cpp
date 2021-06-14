//============================================================================
// Name        : CodaVettore.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Coda.h"
using namespace std;

int main() {
	cout << "!!!Hello World Coda!!!" << endl; // prints !!!Hello World!!!

	Coda<int> c(10);

	c.inCoda(1);
	c.inCoda(2);
	c.inCoda(3);
	c.inCoda(4);
	c.inCoda(5);

	cout<<" "<<c.leggiCoda()<<endl;
	c.fuoriCoda();
	cout<<" "<<c.leggiCoda()<<endl;
	c.fuoriCoda();
	cout<<" "<<c.leggiCoda()<<endl;
	c.fuoriCoda();




	return 0;
}
