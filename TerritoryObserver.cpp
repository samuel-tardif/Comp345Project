#pragma once
#include "TerritoryObserver.h"

//Territory observer implementation----------------------------------------------------------------------------

TerritoryObserver::TerritoryObserver(Map::Territory* s)
{
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
}

TerritoryObserver::~TerritoryObserver()
{
	_subject->Detach(this);
}

void TerritoryObserver::Update()
{
	display();
}

void TerritoryObserver::display()
{
	cout << "The territory has been updated as follows :" << endl;
	cout << *_subject << endl;
}