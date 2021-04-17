#pragma once

#include <string>
#include <ostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "Player.h"
using namespace std;

class Player;

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

    Cards(const Cards& copied);
    Cards& operator=(const Cards& c);
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