/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//Code for part 5, biding facility

#pragma once

//Includes
#include <iostream>
#include <conio.h>
#include "Player.h"


using namespace std;

//Main class for this portion of the work
class BidingFacility {
public:
	static map<Player*, int>* bidMap;

	//Default constructor
	BidingFacility();

	//Parameterized Constructor (added)
	BidingFacility(int bidAmount);

	//Copy constructor
	BidingFacility(const BidingFacility& copied);

	//operator overloads =
	BidingFacility& operator= (const BidingFacility& bF);

	//operator overloads <<
	friend std::ostream& operator<< (std::ostream& output, const BidingFacility& m);

	//Destructor
	~BidingFacility();

	//To assign a player to the biding facility
	void changeOwner(Player* newPlayer);

	//Gives player his coins
	//and asks for bid
	void makeBid();
	
	//Returns pllayer assigned to facility
	Player* getOwner() const;

	//Determines who wins the bid
	static Player* resolveBids();

	//Added accessors and mutators
	int getBidAmount();

	//Added functions...
	int calculateBidList(vector<int> bidlist);

private:

	//Player assigned to biding facility
	Player* owner;
	int* _bidAmount; //Added
	int* birthdate; //Added
	
};