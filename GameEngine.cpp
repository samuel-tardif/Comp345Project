#include "GameEngine.h"
#include "GameState.h"

class Player;
class Cards;
class Hand;
class Deck;
class Map;
class BidingFacility;

bool GameEngine::selectGameMode() {
    cout << "||||||||||||||| EIGHT MINUTE EMPIRE |||||||||||||||" << endl << endl;
    cout << "Please select a game mode: " << endl;
    cout << "\t1) Single Game Mode" << endl;
    cout << "\t2) Tournament Mode" << endl;

    string userSelection;
    cin >> userSelection;

    while(userSelection != "1" && userSelection != "2") {
        cout << "Please enter either a '1' or a '2': ";
        cin.ignore();
        cin >> userSelection;
    }

    if (userSelection == "1") {
        return false;
    }
    
    if (userSelection == "2") {
        return true;
    }
};

void GameEngine::singleGameMode() {

    GameState state = GameState(false);

    cout << "==Your hands==" << endl;
    //Create empty hands
    for (int i = 0; i < state.numOfPlayers; i++) {
		cout << state.players->at(i)->getNameForOthers() << ": ";
		state.players->at(i)->initializeHand(); //giving each player an empty hand with 0 cards
		state.players->at(i)->printHand(); //Displaying the hand. Shouldn't print anything
	}
	cout << endl;

    //The same for both game mode
    cout << "==Generating the topboard==" << endl;
    //Draw 6 cards (top board)
    vector<Cards*> *topboard = state.deck->topBoardGenetor(*(state.deck));
    state.deck->displayTopBoard(*topboard);

    //Bidding
    //Obtain the bidding coins of each player.
    cout << endl;
    cout << "==Bidding==" << endl;
    for (int i = 0; i < state.numOfPlayers; i++) {
        cin.clear();
        cin.ignore();
        state.players->at(i)->setBid(state.players->at(i));
    }

    cout << endl;
    cout << "==Order==" << endl;
    BidingFacility calculator = BidingFacility();
    
    //Decides which player (e.g. 1 or 2 goes first depending on the amount of coins)
    Player* winner = calculator.resolveBids(*(state.players));

    std::cout << winner->getNameForOthers() << " goes first." << std::endl;

    //the winner goes first 
    int playerOrder = 0;

    for (auto it = state.players->begin(); it != state.players->end(); ++it) {
        if (state.players->at(playerOrder)->getName() == winner->getName()) {
            auto first = *it;
            state.players->erase(it);
            state.players->insert(state.players->begin(), first /* or std::move(first)*/) ;
            break;
        }
    }

//======================================== SINGLE GAME MODE MAIN LOOP ========================================
    int indexOfPlayers = 0;
    //Keep playing until everyone's hand is at least 11
    bool continueTheGame = false;
    do {
        //This decides whose turn it is.
        std::cout << "It is currently " << state.players->at(indexOfPlayers)->getNameForOthers() << "'s turn to play." << std::endl;
        
        //Buy
        state.deck->exchange(state.players->at(indexOfPlayers), *(state.topboard), *(state.deck)); //You have to dereference because you are taking a reference to a player.

        indexOfPlayers++;
        indexOfPlayers %= 2;
        //Had to place indexOfPlayer%2 after indexOfPlayer++

        //Check if every single player has 11 cards in their hand
        for (int eachPlayer = 0; eachPlayer < state.numOfPlayers; eachPlayer++) {
            if (state.players->at(indexOfPlayers)->getHandContent().size() < 11) {
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

