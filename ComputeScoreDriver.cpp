/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 228/03/2021
For COMP 345 -Assignment 2
------------------------------------------------------------------------------------------------*/
//Code for part 6, computeScore
#pragma once

//Includes
#include "Cards.h"
#include <iostream>
#include "Map.h"
#include <fstream>;
#include "MapLoader.h"
#include <string>;
#include "Player.h"
#include "ComputeScore.h"

int main() {
	cout << "Main is running" << endl;

    //Creating our map
    cout << "creating first map" << endl;
    //Will be valid
    Map* m = new Map();

    //Creating territories
    //          Owner, p1Armies, p2Armies, continent  Note : Owner is useless in current 
    m->addTerritory(0, 1, 0, 1); //Shoulld be won by player 1 

    m->addTerritory(0, 1, 1, 1); //Should be won by neither --- Player 1 should win continent 1

    m->addTerritory(0, 0, 0, 2);//Should be won by player 2 --- 

    m->addTerritory(0, 0, 0, 2); //Should be won by player 1

    //Linking them
    m->createConnection(0, 1);
    m->createConnection(2, 1);
    m->createConnection(2, 3);

    //Creating our players
    cout << "Players created" << endl;
    Player player1 = Player("Sam");
    Player player2 = Player("Hugo");

    //Creating our ComputeScore object
    ComputeScore CS = ComputeScore(&player1, &player2, m);




}