/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "Player.h"
#include "BidingFacility.h"
#include "Map.h"

Player::Player()
{
    this->coins = nullptr;
    this->name = nullptr;
	this->name = nullptr;
	this->disks = nullptr;
	this->cubes = nullptr;
	this->tokens = nullptr;
	this->hand = nullptr; //Object of Hand class
}

//Mutators
void Player::SetCubes(int cubes) {
	Player::cubes = &cubes;
}

void Player::SetDisks(int disks) {
	Player::disks = &disks;
}

void Player::SetTokens(int tokens)
{
	Player::tokens = &tokens;
}

void Player::setCountries(int countries)
{
	*Player::countries = countries;
}

//Mutators for coins 
void Player::setCoins(int coins) {
	 *Player::coins = coins; 
}



int Player::getCountries() const
{
	return *countries;
}

int Player::getCubes() const
{
	return *cubes;
}

int Player::getDisks() const
{
	return *disks;
}

int Player::getTokens() const
{
	return *tokens;
}

std::string Player::getName() const
{
	return *name;
}

void Player::setBid() {
	playerBid = new BidingFacility();
	playerBid->makeBid();
}


//BiddingFacility *Player::getBiddingFacility() const 
//{
	//return BiddingFacility;
//}

//Destructors
Player::~Player()
{
	if (name) { delete name; }
	if (cubes) { delete &cubes; }
	if (disks) { delete& disks; }
	if (tokens) { delete& tokens; }
	//if (BiddingFacility) { delete &biddingFacility; }
}


//Parameterized constructors
Player::Player(std::string name)
{
	Player::name = new std::string(name);
	Player::disks = new int(3);
	Player::cubes = new int(18);
	Player::tokens = new int(4);
	Player::hand = new Hand();
}

bool Player::payCoin(int cost)
{
    if (*coins < cost) {
        std::cout << "You don't have enough coins to purchase that." << std::endl;
        return false;
    }
    else {
        setCoins(*coins - cost);
        std::cout << "Successful purchase " << *name << ", you have " << *coins << " coins remaining in your pile." << std::endl << std::endl;
        return true;
    }
}

//Actions
void Player::placeNewArmies(Map m, int numArmies, int index, int player) {
	
	//Check army availability. Can't place an army if theyre all already deployed

	if ((*cubes - numArmies) >= 0) {

		*cubes - numArmies;
		m.changeNumberArmies(index, numArmies, player+1);

	}else {
		//If the player has too few armies
		cerr << "\nOperation blocked. You only have " << *cubes << " armies available to you.";
	}
}

void Player::MoveArmies(int movearmy)
{
	std::cout << "moves army" << std::endl;
}

void Player::MoveOverLand(int moveoverland)
{
	std::cout << "moves over land" << std::endl;
}

void Player::BuildCity(int buildcity)
{
	std::cout << "builds city" << std::endl;
}

void Player::DestroyArmy(int destroyarmy)
{
	std::cout << "destroy army" << std::endl;
}



void Player::setName(std::string name)
{
	*Player::name = name;
}

//Hand related
void Player::initializeHand() {
	hand = new Hand();
}

void Player::printHand() {
	hand->printHand();
}

vector<Cards> Player::getHand() {
	return hand->getHand();
}

void Player::setHand(vector<Cards> v) {
	hand->swapHand(v);
} 

