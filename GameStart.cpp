#pragma once
#include "Player.h"
#include "BiddingFacility.h"
#include "MapLoader.h"
#include "Map.h"
#include "Cards.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::vector;

    cout << "creating game map" << endl;
    //load map and validate it
    MapLoader* text1 = new MapLoader();
    text1->setFileName("test.txt");
    text1->GenerateMap();
    //create two players
    Player* player1 = new Player();
    Player* player2 = new Player();

    //create assigned decks
    Deck* deck1 = new Deck();
    std::vector<Cards*> tb1 = deck1->topBoardGenetor(*deck1);
    deck1->exchange(*player1, tb1, *deck1);

    Deck* deck2 = new Deck();
    std::vector<Cards*> tb2 = deck2->topBoardGenetor(*deck1);
    deck1->exchange(*player2, tb2, *deck2);

    // create bidding facility
    BidingFacility* Facility1 = new BidingFacility ();
    Facility1->setOwner(*player1);
    BidingFacility* Facility2 = new BidingFacility();
    Facility2->setOwner(*player2);





}
