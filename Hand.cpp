#include "Cards.h"

Hand::Hand() : hand() {
}

Hand::~Hand() {}

Hand::Hand(const Hand &h) {
	hand = h.hand;
}

Hand& Hand::operator = (const Hand &h) {
	hand = h.hand;
	return *this;
}

//Do not change this (For deck)
vector<Cards*>& Hand::getHand() {
	return hand;
}
/*
vector<Cards*>& Hand::getHandForPlayer() const {
	return hand;
}
*/

void Hand::printHand() {
	int j = 0;
	string str;
	if (hand.size() == 0) {
		cout << "Your hand is empty." << endl;
	}
	else {
		for (auto* i : hand) {
			cout << "[" << j + 1 << "] " << *i << endl;
			j++;
		}
	}
}

// Inserts card on hand space
void Hand::setHand(const Cards& c) {
	Cards *insertedCard = new Cards(c);
	hand.push_back(insertedCard);
	cout << "Top card is now: " << *hand[0] << endl;

}
//Not sure to where it is used...
void Hand::swapHand(vector<Cards*>& v) {
	hand = v;
}
