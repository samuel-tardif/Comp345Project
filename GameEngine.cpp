#include "GameEngine.h"
#include "GameState.h"
#include "ComputeScore.h"

class Player;
class Cards;
class Hand;
class Deck;
class Map;
class BidingFacility;

using namespace std;

//REQUIREMENT 1: THE CHOICE BETWEEN SINGLE GAME MODE AND TOURNAMENT MODE
bool GameEngine::selectGameMode() {
    std::cout << "||||||||||||||| EIGHT MINUTE EMPIRE |||||||||||||||" << endl << endl;
    std::cout << "Please select a game mode: " << endl;
    std::cout << "\t1) Single Game Mode" << endl;
    std::cout << "\t2) Tournament Mode" << endl;

    string userSelection;
    cin >> userSelection;

    //MAKES SURE THAT THE USER CAN ONLY TYPE 1 OR 2
    while(userSelection != "1" && userSelection != "2") {
        std::cout << "Please enter either a '1' or a '2': ";
        cin.ignore();
        cin >> userSelection;
    }

    //CHECKS IF THE INPUT IS 1
    if (userSelection == "1") {
        return false;
    }
    
    //IF THE INPUT IS 2...
    return true;
    
};

void GameEngine::singleGameMode() {

    GameState state = GameState(false);

    std::cout << "==Your hands==" << endl;
    //Create empty hands
    for (int i = 0; i < *(state.getNumOfPlayers()); i++) {
		std::cout << state.getPlayers()->at(i)->getNameForOthers() << ": ";
		state.getPlayers()->at(i)->initializeHand(); //giving each player an empty hand with 0 cards
		state.getPlayers()->at(i)->printHand(); //Displaying the hand. Shouldn't print anything
	}
	std::cout << endl;

    //The same for both game mode
    std::cout << "==Generating the topboard==" << endl;
    //Draw 6 cards (top board)
    vector<Cards*> *topboard = state.getDeck()->topBoardGenetor(*(state.getDeck()));
    state.getDeck()->displayTopBoard(*topboard);

    //Bidding
    //Obtain the bidding coins of each player.
    std::cout << endl;
    std::cout << "==Bidding==" << endl;
    for (int i = 0; i < *(state.getNumOfPlayers()); i++) {
        cin.clear();
        cin.ignore();
        state.getPlayers()->at(i)->setBid(state.getPlayers()->at(i));
    }

    std::cout << endl;
    std::cout << "==Order==" << endl;
    BidingFacility calculator = BidingFacility();
    
    //Decides which player (e.g. 1 or 2 goes first depending on the amount of coins)
    Player* winner = calculator.resolveBids();

    std::cout << winner->getNameForOthers() << " goes first." << std::endl;

    //the winner goes first 
    int playerOrder = 0;

    for (auto it = state.getPlayers()->begin(); it != state.getPlayers()->end(); ++it) {
        if (state.getPlayers()->at(playerOrder)->getName() == winner->getName()) {
            auto first = *it;
            state.getPlayers()->erase(it);
            state.getPlayers()->insert(state.getPlayers()->begin(), first /* or std::move(first)*/) ;
            break;
        }
    }

//======================================== SINGLE GAME MODE MAIN LOOP ========================================
    int indexOfPlayers = 0;
    //Keep playing until everyone's hand is at least 11
    bool continueTheGame = false;
    do {
        //This decides whose turn it is.
        std::cout << "It is currently " << state.getPlayers()->at(indexOfPlayers)->getNameForOthers() << "'s turn to play." << std::endl;
        
        //Buy
        state.getDeck()->exchange(state.getPlayers()->at(indexOfPlayers), *(state.getTopboard()), *(state.getDeck())); //You have to dereference because you are taking a reference to a player.

        indexOfPlayers++;
        indexOfPlayers %= 2;
        //Had to place indexOfPlayer%2 after indexOfPlayer++

        //Check if every single player has 11 cards in their hand
        for (int eachPlayer = 0; eachPlayer < *(state.getNumOfPlayers()); eachPlayer++) {
            if (state.getPlayers()->at(indexOfPlayers)->getHandContent().size() < 11) {
                continueTheGame = true;
            }
            else {
                continueTheGame = false;
                break;
            }
        }
    }
    while (continueTheGame == true);


//======================================== END OF SINGLE GAME MODE MAIN LOOP ========================================

};

void GameEngine::tournamentMode() {

    //Validate map
    GameState state = GameState(true);

    //The number of turns in each game
    int gamenLength = 20; 
//======================================== TOURNAMENT MODE MAIN LOOP ========================================

    //THE TOTAL NUMBER OF ROUNDS IN A TOURNAMENT GAME
    for (int numOfBrackets = 0; numOfBrackets <= *(state.getNumOfPlayers())%2; numOfBrackets++) {
        /*
        state.numOfPlayer%2, when numOfPlayers = 4, is 2. The total number of games that will be conducted is player 1 vs player 2
        player 3 vs player 4, and the winner of the first round vs the winner of the second round.
        Meaning that there is 3 rounds in total (case when numOfPlayer = 4)

        state.numOfPlayer%2, when numOfPlayers = 3, is 1. The total number of games that will be conducted is player 1 vs player 2, 
        and the winner of the first round vs player 3.
        Meaning that there is 2 rounds in total (case when numOfPlayer = 3)

        state.numOfPlayer%2, when numOfPlayers = 2, is 0. The total number of games that will be conducted is player 1 vs player 2.
        Meaning that there is only 1 round (case when numOfPlayer = 2)
        */

        //DECIDING THE PLAYERS THAT ARE GOING TO PLAY THIS ROUND (MAYBE RANDOMIZE? NOT THE PRIORITY RIGHT NOW)
        vector<Player*> *playersOfThisRound;
        vector<Player*> *previousWinner;
        if (numOfBrackets == 0) {
            /*
            The first round is always done by the first 2 players
            */
            for (int i = 0; i < 2; i++) {
                playersOfThisRound->push_back(state.getPlayers()->at(i));
            } 
            std::cout << "====== The first and the final round (" << playersOfThisRound->at(0)->getNameForOthers() << " vs " << playersOfThisRound->at(1)->getNameForOthers() << ")======" << std::endl;
        }

        if (numOfBrackets == 1) {
            /*
            The second round:
            -Does not happen when the num of player is 2
            -Happens when num of players is 3 or 4 
            -For 3 players, it's winner of the 1st round (player 1 vs player 2) vs player 3
            -For 4 players, it's player 3 vs player 4
            */
            if (*(state.getNumOfPlayers()) == 3) {
                /*
                The winner of round 1 vs the player 3
                */
                playersOfThisRound->push_back(previousWinner->at(0));
                playersOfThisRound->push_back(state.getPlayers()->at(*(state.getNumOfPlayers())-1)); //The 3rd player 
                std::cout << "====== The final round (" << playersOfThisRound->at(0)->getNameForOthers() << " vs " << playersOfThisRound->at(1)->getNameForOthers() << ")======" << std::endl;
            }
            else {
                /*
                Player 3 vs player 4
                */
                for (int i = 2; i < *(state.getNumOfPlayers()); i++) {
                    playersOfThisRound->push_back(state.getPlayers()->at(i));
                }
                std::cout << "====== The second round (" << playersOfThisRound->at(0)->getNameForOthers() << " vs " << playersOfThisRound->at(1)->getNameForOthers() << ")======" << std::endl;
            }
        }

        if (numOfBrackets == 2) {
            /*
            The third and the last possible round:
            -Only happens when the num of player is 4
            -The winner of 1st round (player 1 vs player 2) vs the winner of 2nd round (player 3 vs player 4)
            */
            for(int i = 0; i < 2; i++) {
                playersOfThisRound->push_back(previousWinner->at(i));
            }
            std::cout << "====== The final round (" << playersOfThisRound->at(0)->getNameForOthers() << " vs " << playersOfThisRound->at(1)->getNameForOthers() << ")======" << std::endl;
        }

        std::cout << "==Your hands==" << endl;
        //Create empty hands
        for (int i = 0; i < 2; i++) {
            std::cout << playersOfThisRound->at(i)->getNameForOthers() << ": ";
            playersOfThisRound->at(i)->initializeHand(); //giving each player an empty hand with 0 cards
            playersOfThisRound->at(i)->printHand(); //Displaying the hand. Shouldn't print anything
        }
        std::cout << endl;

        //The same for both game mode
        std::cout << "==Generating the topboard==" << endl;
        //Draw 6 cards (top board)
        vector<Cards*> *topboard = state.getDeck()->topBoardGenetor(*(state.getDeck()));
        state.getDeck()->displayTopBoard(*topboard);

        for (int i = 0; i < *(state.getNumOfPlayers()); i++) {

            state.getPlayers()->at(i)->SetCubes(14);

            state.getPlayers()->at(i)->SetDisks(3);

            state.getPlayers()->at(i)->placeNewArmies(*(state.getMap()), 4, 0, i);
            
            std::cout << "Choose the index of the territory you want to place your army (except the starting region)." << std::endl;
            int index;
            cin >> index;
            while (index == 0 || index > state.getMap()->getTerritoriesVector()->size()) {
                std::cout << "You can't place your army there. Try again: " << endl;
                cin >> index;
            };
            state.getPlayers()->at(i)->placeNewArmies(*(state.getMap()), 1, index, i);
        }

        int indexOfPlayers = 0;

        if (*(state.getNumOfPlayers()) == 2) {
            Player* npc = new Player();
            npc->SetCubes(10);
            int selectTerr = 0;
            for (int i = 0; i < npc->getCubesForOthers(); i++) {

                indexOfPlayers %= 2; //This decides whose turn it is.

                std::cout << state.getPlayers()->at(i)->getName() << ", enter the territory index to place non-player army: ";
                cin >> selectTerr;
                while (selectTerr > state.getMap()->getTerritoriesVector()->size() || selectTerr < 1) {
                    std::cout << "Invalid Territory ID. Try again: ";
                    cin >> selectTerr;
                }
                state.getPlayers()->at(i)->placeNewArmies((*state.getMap()), selectTerr, 1, *(state.getNumOfPlayers())+1);

                indexOfPlayers++;
            }
        }

        //Bidding
        //Obtain the bidding coins of each player.
        std::cout << endl;
        std::cout << "==Bidding==" << endl;
        for (int i = 0; i < 2; i++) {
            cin.clear();
            cin.ignore();
            playersOfThisRound->at(i)->setBid(playersOfThisRound->at(i));
        }

        std::cout << endl;
        std::cout << "==Order==" << endl;
        BidingFacility calculator = BidingFacility();
        
        //Decides which player (e.g. 1 or 2 goes first depending on the amount of coins)
        Player* winner = calculator.resolveBids();

        //WHAT IS HAPPENING?
        std::cout << winner->getNameForOthers() << " goes first." << std::endl;

        //the winner goes first 
        int playerOrder = 0;

        indexOfPlayers = 0;
        //Keep playing until everyone's hand is at least 11
        bool continueTheGame = false;
        do {
            //This decides whose turn it is.
            std::cout << "It is currently " << state.getPlayers()->at(indexOfPlayers)->getNameForOthers() << "'s turn to play." << std::endl;
            
            //Buy
            state.getDeck()->exchange(state.getPlayers()->at(indexOfPlayers), *(state.getTopboard()), *(state.getDeck())); //You have to dereference because you are taking a reference to a player.

            indexOfPlayers++;
            indexOfPlayers %= 2;
            //Had to place indexOfPlayer%2 after indexOfPlayer++

            //Check if every single player has 11 cards in their hand
            for (int eachPlayer = 0; eachPlayer < *(state.getNumOfPlayers()); eachPlayer++) {
                if (state.getPlayers()->at(indexOfPlayers)->getHandContent().size() < 11) {
                    continueTheGame = true;
                }
                else {
                    continueTheGame = false;
                    break;
                }
            }
        }
        while (continueTheGame == true);

        //DESTRUCTORS EACH ROUND?
        
    }
    //Obtain and show the results
    ComputeScore cp;
    cp.determineWinner();
};