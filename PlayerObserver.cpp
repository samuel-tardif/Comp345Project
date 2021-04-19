#pragma once

#include "PlayerObserver.h"

//Player observer implementation----------------------------------------------------------------------------

PlayerObserver::PlayerObserver(Player* s)
{
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
}

PlayerObserver::~PlayerObserver()
{
	_subject->Detach(this);
}

void PlayerObserver::Update()
{
	display();
}

void PlayerObserver::display()
{
	cout << "Display Player through observer" << endl;
	cout <<  "Coins : " << _subject->getCoins() << endl;
	cout << "Disks : " << _subject->getDisks() << endl;
	cout << "Cubes : " << _subject->getCubes() << endl;
}
