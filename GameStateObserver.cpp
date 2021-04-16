#pragma once

#include "GameStateObserver.h"

//Game state observer implementation----------------------------------------------------------------------------
GameStateObserver::GameStateObserver(GameState* s)
{
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
}

GameStateObserver::~GameStateObserver()
{
	_subject->Detach(this);
}

void GameStateObserver::Update()
{
	display();
}

void GameStateObserver::display()
{
	cout << "display GameState with observer" << endl;
}