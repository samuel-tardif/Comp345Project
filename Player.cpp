/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/
#pragma once

#include "Player.h"
#include "GameStateObserver.h"

Player::Player()
{
	this->coins = new int(0);
	this->name = new string("Default");
	this->disks = new int(0);
	this->cubes = new int(0);
	this->tokens = new int(0);
	this->hand = new Hand(); //Object of Hand class
}

Player::Player(std::string name)
{
	this->coins = new int(0);
	this->name = new string(name); 
	this->disks = new int(0);
	this->cubes = new int(0);
	this->tokens = new int(0);
	this->hand = new Hand(); //Object of Hand class
}

//copy constructors
//https://stackoverflow.com/questions/781760/copy-constructor-with-pointers
//https://stackoverflow.com/questions/21351933/c-vector-of-classes-push-back-error
Player::Player(Player& copied)
{
	//Allocating space in the heap
	Player::name = new std::string();
	Player::disks = new int();
	Player::cubes = new int();
	Player::tokens = new int();
	Player::coins = new int();
	Player::hand = new Hand();

	*Player::name = *copied.name;
	*Player::disks = *copied.disks;
	*Player::cubes = *copied.cubes;
	*Player::tokens = *copied.tokens;
	*Player::coins = *copied.coins;
	*Player::hand = *copied.hand;

}

Player& Player::operator=(const Player& p)
{
	*name = p.getName();
	*disks = p.getDisks();
	*cubes = p.getCubes();
	*tokens = p.getTokens();
	*coins = p.getCoins();
	*hand = p.getHand();

	return *this;
}


//Mutators
void Player::SetCubes(int cubes) {
	*this->cubes = cubes;
}

void Player::SetDisks(int disks) {
	*this->disks = disks;
}

void Player::SetTokens(int tokens)
{
	*this->tokens = tokens;
}

//Added by Bumsu David Park

//Mutators for coins 
void Player::setCoins(int coins) {
	*this->coins = coins;
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

string Player::getName() const
{
	return *name;
}

std::string Player::getNameForOthers() const
{
	return *name;
}

int Player::getCubesForOthers() const
{
	return *cubes;
}

int Player::getCoinsForOthers() const {
	return *coins;
}

int Player::getCoins() const
{
	return *coins;
}

//Destructors
Player::~Player()
{
	if (name) { delete name; }
	if (cubes) { delete cubes; }
	if (disks) { delete disks; }
	if (tokens) { delete tokens; }
	if (coins) {delete coins; }
	if (hand) {delete hand; }
	//if (BiddingFacility) { delete &biddingFacility; }
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
		m.changeNumberArmies(index, numArmies, player + 1); //0, 4, 0

	}
	else {
		//If the player has too few armies
		cerr << "\nOperation blocked. You only have " << *cubes << " armies available to you.";
	}
}

/*
void Player::MoveArmies(int nbarmy, Map& start, Map& stop)
{

	vector<int*> armystart = start.getnbArmies1();
	vector<int*> armystop = stop.getNbArmies1();

	*armystart.at(*playerID) = armystart.at(*playerID) - nbarmy;
	start.setNbArmies1(armystart);

	*armystop.at(*playerID) = armystop.at(*playerID) + nbarmy;
	stop.setNbArmies1(armystop);

	std::cout << "moves army" << std::endl;
}
*/
/*
void Player::MoveOverLand(int nbarmies, Map& start, Map& stop)
{
	
	MoveArmies(nbarmies, start, stop);
	std::cout << "moves over land" << std::endl;

}
*/
void Player::BuildCity(Map& cityplace)
{
	if ( *disks == 0) {
		std::cout << "no resources to build city" << std::endl;
	}
	else {
		SetDisks( *disks - 1);
		std::cout << "builds city" << std::endl;
	}


}

/*
void Player::DestroyArmy(Map& armyplace, Player& armyowner)
{
	vector<int*> armies = armyplace.getNbArmies1();
	int armyownerid = armyowner.getPlayerID();


	std::cout << "destroy army" << std::endl;
}
*/

void Player::setBid(Player* player) {
	playerBid = new BidingFacility(player);
	playerBid->makeBid();
}

void Player::setName(std::string name)
{
	*this->name = std::move(name); //L VALUES AND R VALUES THING
	//STD STRING CLASS, DOING ASSIGNMENT OPERATION...
	//STD STRING OVERLOADS ASSIGNMENT OPERATOR
	//ASSIGNMENT OPERATOR WITH REFERENCE
	//MOVE(NAME) MAKES IT INTO L VALUE AND LEFT SIDE BECOMES R VALUE AND OWNS IT.
}

//Hand related
void Player::initializeHand() {
	hand = new Hand();
}

void Player::printHand() {
	hand->printHand();
}
/*
vector<Cards*>& Player::getHand() const{
	return hand->getHand();
}
*/

Hand Player::getHand() const {
	return *hand;
}

//Do not change this (For deck)
vector<Cards*>& Player::getHandContent(){
	return hand->getHand();
}

vector<Cards*>& Player::getHandSize() {
	return hand->getHand();
}

void Player::setHand(vector<Cards*>& v) {
	hand->swapHand(v);
}

