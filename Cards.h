#pragma once

#include <string>
#include <ostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;

// Forward Declaration
class joueur;

class Cards
{

private:
    string* name;
    string* ability;
    string* action;

public:
    // constructors
    Cards();
    Cards(string name, string ability, string action);

    // deconstructor
    virtual ~Cards();

    // accessors
    string *getName() const;
    string *getAbility() const;
    string *getAction() const;

    // mutators
    void setName(string name);
    void setAbility(string ability);
    void setAction(string action);

    // operator overides
    friend ostream& operator<<(ostream& os, const Cards& cards);
};

class Deck
{

private:
    int* cost;
    int* position;
    int posArray[6] = { 0, 1, 1, 2, 2, 3 };
    // std::vector<Cards*> topBoard;

public:
    // constructor
    Deck();

    // deconstructor
    virtual ~Deck();

    // gameplay methods
    Cards* draw();
    std::vector<Cards*> topBoardGenetor(Deck& deck);
    void displayTopBoard(std::vector<Cards*>& topBoard);
    void updateTopBoard(int& position, std::vector<Cards*>& topBoard, Deck& deck);
    std::vector<Cards*> handGenetor(Cards*& card);
    void displayHand(std::vector<Cards*>& hand);
    //exchange had Player& player
    void exchange(joueur& player, std::vector<Cards*>& topBoard, Deck& deck);
};

static std::vector<Cards*> deck;

class joueur
{

private:
    int* coins;
    string* name;
    vector<Cards*>* gameHand;

public:
    // Constructors
    joueur();
    joueur(std::string name);

    // Deconstructor
    ~joueur();

    // General Gameplay Methods
    bool payCoin(int cost);

    // Accessors
    int getCoins() const;
    std::string& getName();
    std::vector<Cards*>& getGameHand();

    // Mutators
    void setCoins(int coins);
    void setName(std::string name);

};