/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

#pragma once
#include "Player.h"

#include "BidingFacility.h"
#include "Map.h"


Player::Player()
{
	this->coins = nullptr;
	this->name = nullptr;
	this->disks = nullptr;
	this->cubes = nullptr;
	this->tokens = nullptr;
	this->hand = nullptr; //Object of Hand class
}
//copy constructors
Player::Player(const Player& copied)
{
	Player::name = new std::string("name");
	Player::disks = new int(3);
	Player::cubes = new int(18);
	Player::tokens = new int(4);
	Player::gameHand = new std::vector<Cards*>();
	*Player::name = copied.getName();
	*Player::disks = copied.getDisks();
	*Player::cubes = copied.getCubes();
	*Player::tokens = copied.getTokens();
	*Player::gameHand = *copied.getGameHand();


}

Player& Player::operator=(const Player& copied)
{
	*Player::name = copied.getName();
	*Player::disks = copied.getDisks();
	*Player::cubes = copied.getCubes();
	*Player::tokens = copied.getTokens();
	*Player::gameHand = *copied.getGameHand();
	return *this;
}

/*void Player::setBid() {
	BidingFacility playerBid = new BidingFacility();
	playerBid->setBid(*playerID);
}*/


Player::Player(std::string name)
{
	this->coins = nullptr;
	this->name = new string(name); 
	this->disks = nullptr;
	this->cubes = nullptr;
	this->tokens = nullptr;
	this->hand = nullptr; //Object of Hand class
}

//copy constructors
//https://stackoverflow.com/questions/781760/copy-constructor-with-pointers
Player::Player(const Player& copied)
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
	name = p.getName();
	disks = p.getDisks();
	cubes = p.getCubes();
	tokens = p.getTokens();
	coins = p.getCoins();
	hand = p.getHand();

	return *this;
}


//Mutators
void Player::SetCubes(int cubes) {
	Player::cubes = &cubes;
	this->Notify();
}

void Player::SetDisks(int disks) {
	Player::disks = &disks;
	this->Notify();
}

void Player::SetTokens(int tokens)
{
	*Player::tokens = tokens;
	this->Notify();
}


/*void Player::setCountries(int countries)
{
	*Player::countries = countries;
	this->Notify();
}*/


/*int Player::getCountries() const
{
	return *countries;
}*/

//Added by Bumsu David Park

//Mutators for coins 
void Player::setCoins(int coins) {
	this->coins = new int(coins);
	this->Notify();
}

int *Player::getCubes() const
{
	return this->cubes;
}


int *Player::getDisks() const
{
	return this->disks;
}

int *Player::getTokens() const
{
	return this->tokens;
}

string *Player::getName() const
{
	return this->name;
}

std::string Player::getNameForOthers() const
{
	return *name;
}

int Player::getCubesForOthers() const
{
	return *cubes;
}

//Accessors for player ID and birthday
int Player::getPlayerID() {
	return *playerID;
}

int Player::getCoinsForOthers() const {
	return *coins;
}


int *Player::getCoins() const
{
	return this->coins;
}

/*BiddingFacility* Player::getBiddingFacility() const
{
	return BiddingFacility;
}*/


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

/*
//Parameterized constructors
Player::Player(string name)
{
	Player::name = new std::string(name);
	Player::disks = new int(3);
	Player::cubes = new int(18);
	Player::tokens = new int(4);
	Player::hand = new Hand();
}
*/


Player::Player(const Player& copied)
{
	Player::name = new std::string("name");
	Player::disks = new int(3);
	Player::cubes = new int(18);
	Player::tokens = new int(4);
	Player::gameHand = new std::vector<Cards*>();
	*Player::name = copied.getName();
	*Player::disks = copied.getDisks();
	*Player::cubes = copied.getCubes();
	*Player::tokens = copied.getTokens();
	*Player::gameHand = *copied.getGameHand();

}

Player& Player::operator=(const Player& copied)
{
	*Player::name = copied.getName();
	*Player::disks = copied.getDisks();
	*Player::cubes = copied.getCubes();
	*Player::tokens = copied.getTokens();
	*Player::gameHand = *copied.getGameHand();
	return *this;
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

  cout << "Good until 2.4" << endl;

//Check army availability. Can't place an army if theyre all already deployed

	if ((*cubes - numArmies) >= 0) {
		cout << "Good until 2.5" << endl;
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
	*Player::name = name;
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

Hand *Player::getHand() const {
	return this->hand;
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

