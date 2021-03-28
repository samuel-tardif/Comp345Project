/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//Code for part 5, biding facility
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "BidingFacility.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    //Creating our players
    cout << "Players created" << endl;
    Player player1 = Player("Sam");
    Player player2 = Player("Hugo");

    //Creating biding facilities and assigning players
    BidingFacility bidingPlayer1 = BidingFacility();
    bidingPlayer1.changeOwner(&player1);
    BidingFacility bidingPlayer2 = BidingFacility();
    bidingPlayer2.changeOwner(&player2);

    //Making bids
    bidingPlayer1.makeBid();
    bidingPlayer2.makeBid();

    //Resolving bids
   BidingFacility::resolveBids();
   
}