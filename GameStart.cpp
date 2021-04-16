#pragma once

/*-------------------------------------------------------------------------------------------
Code by Ibrahim Tawakool
ID: 40108389
Date : 29/03/2021
For COMP 345 -Assignment 2
------------------------------------------------------------------------------------------------*/

//This is the header file of part 2, the game start
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
    
    string name;
    cout << "Enter map file" << endl;
    cin >> name;
    //load map and validate it
    MapLoader* text1 = new MapLoader();
    text1->setFileName(name);
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
    BidingFacility* Facility1 = new BidingFacility();
    Facility1->setOwner(*player1);
    BidingFacility* Facility2 = new BidingFacility();
    Facility2->setOwner(*player2);





}
