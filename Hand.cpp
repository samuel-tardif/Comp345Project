#include "Cards.h"

Hand::Hand() : hand() {
}

Hand::~Hand() {}

vector<Cards> Hand::getHand() const {
	return hand;
}

void Hand::printHand() {
	int j = 0;
	string str;
	if (hand.size() == 0) {
		cout << "Your hand is empty." << endl;
	}
	else {
		for (auto& i : hand) {
			cout << "[" << j + 1 << "] " << i << endl;
			j++;
		}
	}
}

// Inserts card on hand space
void Hand::setHand(Cards c) {
	Cards *insertedCard;
	insertedCard = new Cards(c);
	hand.push_back(*insertedCard);
	cout << "Top card is now: " << hand[0] << endl;

}

void Hand::swapHand(vector<Cards> v) {
	hand = v;
}