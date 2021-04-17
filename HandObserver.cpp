#include "HandObserver.h"
#include "Hand.h"

//Player observer implementation----------------------------------------------------------------------------
/*
HandObserver::HandObserver(Hand* s)
{
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
}

HandObserver::~HandObserver()
{
	_subject->Detach(this);
}
*/

void HandObserver::Update()
{
	display();
}

void HandObserver::display()
{
	vector<Cards*> hand = _subject->getHand();
	cout << "Last card picked :  "<< endl << endl << "Name : " << hand.back()->getName()<< endl << "Action : "<< hand.back()->getAction() << endl << "Ability : "<< hand.back()->getAbility() << endl;

	cout << "Full hand:" << endl;
	for (int i = 0; i < hand.size(); i++) {
		cout << hand.at(i) << endl;
	}
}