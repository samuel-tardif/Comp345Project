#include "Cards.h"
#include <iostream>
#include "Map.h"
#include <fstream>;
#include "MapLoader.h"
#include <string>;
#include "Player.h"

int main() {

    using std::cout;
    using std::cin;
    using std::endl;
    using std::vector;

    //Map driver ------------------------------------------------------------------------------------------------------------------------

    //Creating our first map
    cout << "Creating first map------------------------------" << endl << endl;
    //Will be valid
    Map* m = new Map();


    //Creating territories
    m->addTerritory(0, 0, 1);

    m->addTerritory(0, 0, 1);

    m->addTerritory(0, 0, 2);

    m->addTerritory(0, 0, 2);

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
    cout << endl<< endl << "Creating Second map------------------------" << endl << endl;
    //Connected continents
    //Disconnected graph
    Map* m2 = new Map();

    //Creating territories
    m2->addTerritory(0, 0, 1);

    m2->addTerritory(0, 0, 1);

    m2->addTerritory(0, 0, 2);

    m2->addTerritory(0, 0, 2);

    //Linking them
    m2->createConnection(0, 1);
    m2->createConnection(2, 3);

    //Validating
    m2->validate();


    //Third test, connected graph disconnected continents
    cout << endl << endl << "Creating third map-----------" << endl << endl;
    Map* m3 = new Map();

    //Creating territories
    m3->addTerritory(0, 0, 1);

    m3->addTerritory(0, 0, 1);

    m3->addTerritory(0, 0, 2);

    m3->addTerritory(0, 0, 2);

    //Linking them
    m3->createConnection(0, 1);
    m3->createConnection(0, 2);
    m3->createConnection(1, 3);

    m3->validate();

    delete m, m2, m3;
    cout <<  endl << "------------------------End of Map driver----------------------" << endl << endl;

    cout << endl << "------------------------Start of map loader ----------------------" << endl << endl;

    MapLoader test;
    test.readFile("test.txt");
    cout << endl << "------------------------End of Map Loader driver----------------------" << endl << endl;

    cout << endl << "------------------------Start of player driver ----------------------" << endl << endl;

    using std::cout;
    Player* player = new Player("test");
    std::cout << "player created" << std::endl;
    player->BuildCity(1);
    player->DestroyArmy(1);
    player->MoveArmies(1);
    player->MoveOverLand(1);
    player->PayCoin(1);
    player->PlaceNewArmies(1);
    std::cout << player->getCubes() << std::endl;
    std::cout << player->getDisks() << std::endl;
    std::cout << player->getTokens() << std::endl;
    std::cout << player->getGameHand() << std::endl;

    cout << endl << "------------------------Start of card driver----------------------" << endl << endl;
    //Cards driver--------------------------------------------------------------------------
    Deck* deck1 = new Deck();
    Player* p1 = new Player("Player");
    std::vector<Cards*> tb = deck1->topBoardGenetor(*deck1);
    std::vector<Cards*> hand = std::vector<Cards*>();
    deck1->exchange(*p1, tb, *deck1);
    deck1->exchange(*p1, tb, *deck1);
    deck1->displayTopBoard(tb);
}