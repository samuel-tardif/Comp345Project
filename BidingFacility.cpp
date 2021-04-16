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
	_bidAmount = 0;
	owner = new Player("Default");
}

BidingFacility::BidingFacility(Player* player) {
	_bidAmount = 0;
	owner = player;
}

//Parameterized Constructor (added)
BidingFacility::BidingFacility(int bidAmount) {
	owner = new Player("Default");
	_bidAmount = new int(bidAmount);
}

//Copy constructor
BidingFacility::BidingFacility(const BidingFacility& copied)
{
	this->owner = new Player("Default");
	*owner = *copied.getOwner();
}

//Operator = overload
BidingFacility& BidingFacility::operator=(const BidingFacility& bF)
{
	*owner = *bF.getOwner();
	return *this;
}

//Destructor
BidingFacility::~BidingFacility()
{
	delete owner;
}

//Change payer assigned to facillity
void BidingFacility::changeOwner(Player* newPlayer)
{
	owner = newPlayer;
}

//Take coin and make bid
void BidingFacility::makeBid()
{
	owner->SetTokens(25);
	cout << owner->getNameForOthers() << ", press a number 0-9 to make bid" << endl; //Changed
	int bid;
	std::cin >> bid;
	BidingFacility::bidMap->insert(std::pair<Player*,int>(owner,bid));
}

//Retruns player
Player* BidingFacility::getOwner() const
{
	return owner;
}

//This is what determines who won the bids
Player* BidingFacility::resolveBids(vector<Player*> players)
{
	Player* winner = new Player("Winner");
	int maxBid = 0;

	for (std::map<Player*, int>::iterator it = bidMap->begin(); it != bidMap->end(); ++it) {
		if (it->second > maxBid) {
			maxBid = it->second;
			winner = it->first;
		}
		if (it->second == maxBid) {
			if (it->first->getNameForOthers().compare(winner->getNameForOthers())<0) {
				winner = it->first;
			}
		}
	}
	cout << "The winner is : " << winner->getNameForOthers() << endl;
	winner->payCoin(maxBid); //Segmentation fault in Player payCoin / getCoin function
	//This is because the winner (Player object) is a newly created Player object and has the coin member as nullptr.
	//Seems to be bidingfacility's problem (maybe with map?)
	//Solution: The input for BiddingFacility constructor had to be Player pointer.
	return winner;
}


//String insertion operator overload
std::ostream& operator<<(std::ostream& output, const BidingFacility& bf)
{
	output << "Biding facility owned by  " << bf.getOwner() << std::endl;
	return output;
}