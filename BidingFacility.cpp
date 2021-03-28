/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//Code for part 5, biding facility
#include "BidingFacility.h"
#include "Player.h"

map<Player*, int>* BidingFacility::bidMap = new map<Player*, int>;

//Default constructor
BidingFacility::BidingFacility()
{
	owner = new Player("Default");
}

//
BidingFacility::BidingFacility(const BidingFacility& copied)
{
	this->owner = new Player("Default");
	*owner = *copied.getOwner();
}

BidingFacility& BidingFacility::operator=(const BidingFacility& bF)
{
	*owner = *bF.getOwner();
	return *this;
}

BidingFacility::~BidingFacility()
{
	delete owner;
}

void BidingFacility::changeOwner(Player* newPlayer)
{
	owner = newPlayer;
}

void BidingFacility::makeBid()
{
	owner->SetTokens(25);
	cout << "Press a number 0-9 to make bid" << endl;
	int bid;
	std::cin >> bid;
	BidingFacility::bidMap->insert(std::pair<Player*,int>(owner,bid));
}


Player* BidingFacility::getOwner() const
{
	return owner;
}

Player* BidingFacility::resolveBids()
{
	Player* winner = new Player("aaaaaa");
	int maxBid = 0;

	for (std::map<Player*, int>::iterator it = bidMap->begin(); it != bidMap->end(); ++it) {
		if (it->second > maxBid) {
			maxBid = it->second;
			winner = it->first;
		}
		if (it->second == maxBid) {
			if (it->first->getName().compare(winner->getName())<0) {
				winner = it->first;
			}
		}
	}
	cout << "The winner is : " << winner->getName() << endl;
	return winner;
}

std::ostream& operator<<(std::ostream& output, const BidingFacility& bf)
{
	output << "Biding facility owned by  " << bf.getOwner() << std::endl;
	return output;
}