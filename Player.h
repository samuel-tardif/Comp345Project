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
#include "Map.h"


class Cards;
//class BiddingFacility;

class Player {
public:
	Player();
	Player(std::string name);
	Player(const Player& copied);
	Player& operator=(const Player& copied);


	void PayCoin(int coin);
	void PlaceNewArmies(int placenewarmy);
	void MoveArmies(int movearmy);
	void MoveOverLand(int moveoverland);
	void BuildCity(int buildcity);
	void DestroyArmy(int destroyarmy);

	void setName(std::string name);
	void SetCubes(int cubes);
	void SetDisks(int disks);
	void SetTokens(int tokens);
	//void setCountries(int countries);
	
	//int getCountries() const;
	int getCubes() const;
	int getDisks() const;
	int getTokens() const;
	std::string getName() const;
	std::vector<Cards*>* getGameHand() const;
	//BiddingFacility* getBiddingFacility() const;
	~Player();
	


private:
	
	int *cubes;
	int *disks;
	int *tokens;
	//int* countries;
	std::string* name;
	std::vector<Cards*>* gameHand;
	//BiddingFacility *biddingFacility;
	
		
	

};