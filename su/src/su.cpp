#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "dictionary.h"
#include "linked_list.h"
#include<string>

using namespace std;

int main()
{
    /*string c="bello";
    string a="bella";
    hash<string> p;
    cout<<p(c);
    cout<<"\n";
    cout<<p(a);*/

    //creiamo il dizionario
     hash_table<string,int> dizionario(4);
     mypair<string,int> coppia;
     coppia.first="ciao";
     coppia.second=56;
     dizionario.insert(coppia);
     coppia.first="ciao";
     coppia.second=56;
     dizionario.insert(coppia);
     coppia.first="alto";
     coppia.second=234;
     dizionario.insert(coppia);
     cout<<"The position of elements with key 'ciao' is: "<<dizionario.search("ciao");
     cout<<"\nThe position of elements with key 'ragno' is: "<<dizionario.search("ragno");
     cout<<"\nThe position of elements with key 'alto' is: "<<dizionario.search("alto");




    return 0;
}
