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
#include "Cards.h"



int main() {
	cout << "Main is running" << endl;

    //Creating our map
    cout << "creating first map" << endl;
    //Will be valid
    Map* m = new Map();

    //Creating territories
    //          Owner, p1Armies, p2Armies, continent  Note : Owner is useless in current 
    m->addTerritory(0, 1, 0, 1); //Shoulld be won by player 1 

    m->addTerritory(0, 1, 1, 1); //Should be won by neither --- 

    m->addTerritory(0, 1, 0, 1);//Should be won by player 1 --- 

  

    //Linking them
    m->createConnection(0, 1);
    m->createConnection(2, 1);
    

    //Creating our players
    //cout << "Players created" << endl;
    //Player class is still not fixed


    //Player player1 = Player("Sam");                                                             //--To uncomment if fix player
    //Player player2 = Player("Hugo");                                                          //  --To uncomment if fix player

    //Creating our ComputeScore object
    ComputeScore* CS = new ComputeScore();
    
    //Giving our parameters to the point calculator
    CS->setMap(m);
    //CS->setPlayer1(&player1);                                                                 //--To uncomment if fix
    //CS->setPlayer2(&player2);                                                                 //--To uncomment if fix
    //player1.getGameHand()->push_back(new Cards("Ancient Sage", "+1 VP PER ANCIENT", "---"));  //--To uncomment if fix

    CS->determineWinner();




}