#pragma once

#include "GameObservers.h" 
#include "Hand.h"

//Territory observer implementation----------------------------------------------------------------------------
class HandObserver : public Observer {
public:
	HandObserver(Hand* s);
	~HandObserver();
	void Update();
	void display();
private:
	Hand* _subject;
};