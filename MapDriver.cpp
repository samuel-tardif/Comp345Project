/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//This is the code for the driver of part 1, the map

#include <iostream>
#include "Map.h"




int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::vector;

    //Creating our first map
    cout << "creating first map" << endl;
    //Will be valid
    Map* m = new Map();

    //Creating territories
    m->addTerritory(0,0,0,1);
   
    m->addTerritory(0,0,0,1);

    m->addTerritory(0,0, 0, 2);

    m->addTerritory(0, 0,0, 2);

    //Linking them
    m->createConnection(0, 1);
    m->createConnection(2, 1);
    m->createConnection(2, 3);

    //String insertion demo
    cout << *m << endl;
    //String insertion for territories
    //GEtting our vector
    vector<vector<Map::Territory*>>* v = m->getTerritoriesVector();
    //Printing all territories
    for (int i = 0; i < v->size(); i++) {
        cout << *v->at(i).at(0) << endl;
    }

    //Validating
    m->validate();

    delete v;

    //Second test
    cout << endl << endl << "creating Second map" << endl;
    //Connected continents
    //Disconnected graph
    Map* m2 = new Map();

    //Creating territories
    m2->addTerritory(0,0, 0, 1);

    m2->addTerritory(0, 0,0, 1);

    m2->addTerritory(0,0, 0, 2);

    m2->addTerritory(0,0, 0, 2);

    //Linking them
    m2->createConnection(0, 1);
    m2->createConnection(2, 3);

    //Validating
    m2->validate();


    //Third test, connected graph disconnected continents
    cout << endl << endl << "creating third map" << endl;
    Map* m3 = new Map();

    //Creating territories
    m3->addTerritory(0,0, 0, 1);

    m3->addTerritory(0,0, 0, 1);

    m3->addTerritory(0,0, 0, 2);

    m3->addTerritory(0, 0,0, 2);

    //Linking them
    m3->createConnection(0, 1);
    m3->createConnection(0, 2);
    m3->createConnection(1, 3);

    m3->validate();

    delete m, m2, m3;
}
