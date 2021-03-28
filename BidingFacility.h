/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//Code for part 5, biding facility

#pragma once

#include <iostream>
#include <map>
#include <conio.h>

#include "Player.h"



using namespace std;

class BidingFacility {
public:
	static map<Player*, int>* bidMap;

	//Default constructor
	BidingFacility();

	//Copy constructor
	BidingFacility(const BidingFacility& copied);

	//operator overloads =
	BidingFacility& operator= (const BidingFacility& bF);

	//operator overloads <<
	friend std::ostream& operator<< (std::ostream& output, const BidingFacility& m);

	//Destructor
	~BidingFacility();

	void changeOwner(Player* newPlayer);

	void makeBid();
	
	Player* getOwner() const;

	static Player* resolveBids();

private:

	Player* owner;
	
};

