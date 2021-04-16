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

class Cards;

class Hand {

    private:

        vector<Cards*> hand;

    public: 
        //Default constructor
        Hand();

        //Destructor
        ~Hand();

        //Copy constructor
        Hand(const Hand &h);

        //Assignment operator
        Hand& operator = (const Hand &h);

        //Stream operator (To be added)

        //Getter
        vector<Cards*>& getHand();
        //vector<Cards*>& getHandContent() const;

        //Functions
        void printHand();
        void setHand(const Cards& v); //Gets const card reference, because we don't want to copy it
        void swapHand(vector<Cards*>& v);

};