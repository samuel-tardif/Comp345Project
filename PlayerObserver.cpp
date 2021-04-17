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
	cout << "display Player through observer" << endl;
	cout << *_subject << endl;
}
