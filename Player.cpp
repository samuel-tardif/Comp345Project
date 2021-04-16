/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/
#pragma once
#include "Player.h"

void Player::SetCubes(int cubes) {
	Player::cubes = &cubes;
}

std::vector<Cards*>* Player::getGameHand() const
{
	return gameHand;
}

void Player::SetDisks(int disks) {
	Player::disks = &disks;
}

void Player::SetTokens(int tokens)
{
	*Player::tokens = tokens;
}

/*void Player::setCountries(int countries)
{
	*Player::countries = countries;
}*/

/*int Player::getCountries() const
{
	return *countries;
}*/

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

//BiddingFacility *Player::getBiddingFacility() const 
//{
	//return BiddingFacility;
//}

Player::~Player()
{
	if (name) { delete name; }
	if (cubes) { delete cubes; }
	if (disks) { delete disks; }
	if (tokens) { delete tokens; }
	//if (BiddingFacility) { delete &biddingFacility; }
	if (gameHand) { delete gameHand; }
}



Player::Player()
{
	Player::name = new std::string("Default");
	Player::disks = new int(3);
	Player::cubes = new int(18);
	Player::tokens = new int(4);
	Player::gameHand = new std::vector<Cards*>();
}

Player::Player(std::string name)
{
	Player::name = new std::string(name);
	Player::disks = new int(3);
	Player::cubes = new int(18);
	Player::tokens = new int(4);
	Player::gameHand = new std::vector<Cards*>();
}

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

void Player::PayCoin(int coin)
{
	std::cout << "pays coin" << std::endl;
}

void Player::PlaceNewArmies(int placenewarmy)
{
	std::cout << "places new army" << std::endl;
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

