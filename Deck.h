#pragma once

#include "Cards.h"
#include <string>
#include <ostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "Player.h"
using namespace std;

class Deck
{

private:

    vector<Cards*> deck;
	vector<Cards*> ptrCard;
	
    //int* cost;
    int* position;
    int posArray[6] = { 0, 1, 1, 2, 2, 3 };
    // std::vector<Cards*> topBoard;

    void createDeck(int numOfPlayers);
    void shuffleDeck();

public:
    // constructor
    Deck();
    Deck(int numOfPlayers);

    Deck(const Deck& copied);

//Overload the = operator (more member need to be added)
    Deck& operator=(const Deck& d);

    // deconstructor
    ~Deck();

    // Accessors
    //vector<Cards*> *getDeck() const;
    //int *getCost() const;
    int *getPosition() const;

    // gameplay methods
    Cards* draw();

    std::vector<Cards*> *topBoardGenetor(Deck& deck);
    void displayTopBoard(std::vector<Cards*>& topBoard);
    void updateTopBoard(int& position, std::vector<Cards*>& topBoard, Deck& deck);
    /*
    std::vector<Cards*> handGenetor(Cards*& card);
    void displayHand(std::vector<Cards*>& hand);
    */
    //exchange had Player& player
    void exchange(Player* player, std::vector<Cards*>& topBoard, Deck& deck);

    void printDeck();
};