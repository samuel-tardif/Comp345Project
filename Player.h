/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Cards.h"
#include "Map.h"
#include "BidingFacility.h"


class Cards;
//class BiddingFacility;

class Player {

	private:
		int *coins;
		int *birthday;
		int *playerID; //Maybe not needed
		Hand *hand;

		int *cubes; //Armies
		int *disks; //Cities

		int *tokens;
		int* countries;
		std::string* name;
		BidingFacility *playerBid;

public:

	//Default constructor
	Player();

	//Parameterized constructor
	Player(std::string name);

	//Actions
	bool payCoin(int cost);
	void placeNewArmies(Map m, int numArmies, int index, int player);
	void MoveArmies(int movearmy);
	void MoveOverLand(int moveoverland);
	void BuildCity(int buildcity);
	void DestroyArmy(int destroyarmy);
	void initializeHand();
	void printHand();

	void setName(std::string name);
	void SetCubes(int cubes);
	void SetDisks(int disks);
	void SetTokens(int tokens);
	void setCountries(int countries);

	//Added
	void setPlayerID(int x);
	void setBirthday();
	void setCoins(int coins);
	void setBid();
	int getPlayerID();
	int getBirthday();
	int getCoins();

	vector<Cards> getHand();
	void setHand(vector<Cards> v);
	
	int getCountries() const;
	int getCubes() const;
	int getDisks() const;
	int getTokens() const;
	std::string getName() const;
	//BiddingFacility* getBiddingFacility() const;
	~Player();
	//BiddingFacility *biddingFacility;
	
		
	

};