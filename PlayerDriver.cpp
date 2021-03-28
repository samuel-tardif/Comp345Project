/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "Player.h"

using std::endl;
using std::cout;

int main()
{
    using std::cout;
    Player* player = new Player("test");
    std::cout << "player created" << std::endl;
    player->BuildCity(1);
    player->DestroyArmy(1);
    player->MoveArmies(1);
    player->MoveOverLand(1);
    player->PayCoin(1);
    player->PlaceNewArmies(1);
    std::cout << player->getCubes() << std::endl;
    std::cout << player->getDisks() << std::endl;
    std::cout << player->getTokens() << std::endl;
    std::cout << player->getGameHand() << std::endl;
   

}