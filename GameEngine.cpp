#include "GameEngine.h"
//#include "GameState.h"
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

    //GameState state = GameState(false);

    int numOfPlayers;

    int initialCoins;

    vector<Player*> players;

    Map m;

    //Obtain the number of players who will be playing this game.
    std::cout << "How many people are playing (2~4)? : ";
    std::cin >> numOfPlayers;
    
    while (numOfPlayers < 2 || numOfPlayers > 4)
    {   
        cin.clear();
        cin.ignore();
        std::cout << "Invalid player count, please select a number between 2 and 4: ";
        std::cin >> numOfPlayers;
    }
    
    //Decide how many coins each player will have.
    switch (numOfPlayers) {
	case 2:
		initialCoins = 14;
		break;
	case 3:
		initialCoins = 11;
		break;
	case 4:
		initialCoins = 9;
		break;
	}
    
    //Create players
    for (int i = 0; i < numOfPlayers; i++) {
        //Maybe ask the names?
        string name;
        cout << "Enter the your player name: ";
        getline(cin, name) >> name;
        Player* p = new Player(name); //I'm inside a for loop, as soon as I get out of for loop it disappears so I need to make it into pointer.
        
        //Give coins to each player.
        p->setCoins(initialCoins);

        //Put the "player" in the vector of players
        players.push_back(p);
        
        //Had segmentation fault here because p->getname was pointing to a nullpointer
        std::cout << p->getNameForOthers() << " is ready, and has " << p->getCoinsForOthers() << " coins." << std::endl << std::endl;
    }

    //Create different deck depending on the number of players
    //The deck is shuffled when it is created.
    cout << "==Creating the deck==" << endl << endl;
    Deck deck = Deck(numOfPlayers);

    std::cout << "==Your hands==" << endl;
    //Create empty hands
    for (int i = 0; i < numOfPlayers; i++) {
		std::cout << players[i]->getNameForOthers() << ": ";
		players[i]->initializeHand(); //giving each player an empty hand with 0 cards
		players[i]->printHand(); //Displaying the hand. Shouldn't print anything
	}
	std::cout << endl;

    //The same for both game mode
    std::cout << "==Generating the topboard==" << endl;
    //Draw 6 cards (top board)
    vector<Cards*> *topboard = deck.topBoardGenetor(deck);
    deck.displayTopBoard(*topboard);

    //Bidding
    //Obtain the bidding coins of each player.
    std::cout << endl;
    std::cout << "==Bidding==" << endl;
    for (int i = 0; i < numOfPlayers; i++) {
        cin.clear();
        cin.ignore();
        players[i]->setBid(players[i]);
    }

    std::cout << endl;
    std::cout << "==Order==" << endl;
    BidingFacility calculator = BidingFacility();
    
    //Decides which player (e.g. 1 or 2 goes first depending on the amount of coins)
    Player* winner = calculator.resolveBids();

    std::cout << winner->getNameForOthers() << " goes first." << std::endl;

    //the winner goes first 
    int playerOrder = 0;

    for (auto it = players.begin(); it != players.end(); ++it) {
        if (players[playerOrder]->getName() == winner->getName()) {
            auto first = *it;
            players.erase(it);
            players.insert(players.begin(), first /* or std::move(first)*/) ;
            break;
        }
    }

//======================================== SINGLE GAME MODE MAIN LOOP ========================================
    int indexOfPlayers = 0;
    //Keep playing until everyone's hand is at least 11
    bool continueTheGame = false;
    do {
        //This decides whose turn it is.
        std::cout << "It is currently " << players[indexOfPlayers]->getNameForOthers() << "'s turn to play." << std::endl;
        
        //Buy
        deck.exchange(players[indexOfPlayers], *topboard, deck); //You have to dereference because you are taking a reference to a player.

        indexOfPlayers++;
        indexOfPlayers %= 2;
        //Had to place indexOfPlayer%2 after indexOfPlayer++

        //Check if every single player has 11 cards in their hand
        for (int eachPlayer = 0; eachPlayer < numOfPlayers; eachPlayer++) {
            if (players[indexOfPlayers]->getHandContent().size() < 11) {
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
    std::cout << "TOURNAMENT MODE" << endl;
    //Validate map
    //GameState state = GameState(true);
    bool validMap = false;

    while (!validMap)
    {
        // load map
        MapLoader loader;

        // get file location
        std::string fileLocation;
        std::cout << "Enter map file location: ";
        std::cin >> fileLocation;
        loader.setFileName(fileLocation);
        loader.GenerateMap();

        validMap = true;
    }

    //The number of turns in each game
    int gamenLength = 20; 
//======================================== TOURNAMENT MODE MAIN LOOP ========================================
    int numOfPlayers;

    int initialCoins;

    vector<Player*> players;

    Map m;

    //Obtain the number of players who will be playing this game.
    std::cout << "How many people are playing (2~4)? : ";
    std::cin >> numOfPlayers;
    
    while (numOfPlayers < 2 || numOfPlayers > 4)
    {   
        cin.clear();
        cin.ignore();
        std::cout << "Invalid player count, please select a number between 2 and 4: ";
        std::cin >> numOfPlayers;
    }
    
    //Decide how many coins each player will have.
    switch (numOfPlayers) {
	case 2:
		initialCoins = 14;
		break;
	case 3:
		initialCoins = 11;
		break;
	case 4:
		initialCoins = 9;
		break;
	}
    
    //Create players
    for (int i = 0; i < numOfPlayers; i++) {
        //Maybe ask the names?
        string name;
        cout << "Enter the your player name: ";
        getline(cin, name) >> name;
        Player* p = new Player(name); //I'm inside a for loop, as soon as I get out of for loop it disappears so I need to make it into pointer.
        
        //Give coins to each player.
        p->setCoins(initialCoins);

        //Put the "player" in the vector of players
        players.push_back(p);
        
        //Had segmentation fault here because p->getname was pointing to a nullpointer
        std::cout << p->getNameForOthers() << " is ready, and has " << p->getCoinsForOthers() << " coins." << std::endl << std::endl;
    }

    vector<Player*> playersOfThisRound;
    vector<Player*> previousWinner;
    //THE TOTAL NUMBER OF ROUNDS IN A TOURNAMENT GAME
    for (int numOfBrackets = 0; numOfBrackets <= numOfPlayers%2; numOfBrackets++) {
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
        if (numOfBrackets == 0) {
            /*
            The first round is always done by the first 2 players
            */
            for (int i = 0; i < 2; i++) {
                playersOfThisRound.push_back(players[i]);
            } 
            std::cout << "====== The first and the final round (" << playersOfThisRound[0]->getNameForOthers() << " vs " << playersOfThisRound[1]->getNameForOthers() << ")======" << std::endl;
        }

        if (numOfBrackets == 1) {
            /*
            The second round:
            -Does not happen when the num of player is 2
            -Happens when num of players is 3 or 4 
            -For 3 players, it's winner of the 1st round (player 1 vs player 2) vs player 3
            -For 4 players, it's player 3 vs player 4
            */
            if (numOfPlayers == 3) {
                /*
                The winner of round 1 vs the player 3
                */
                playersOfThisRound.push_back(previousWinner[0]);
                playersOfThisRound.push_back(players[numOfPlayers-1]); //The 3rd player 
                std::cout << "====== The final round (" << playersOfThisRound[0]->getNameForOthers() << " vs " << playersOfThisRound[1]->getNameForOthers() << ")======" << std::endl;
            }
            else {
                /*
                Player 3 vs player 4
                */
                for (int i = 2; i < numOfPlayers; i++) {
                    playersOfThisRound.push_back(players[i]);
                }
                std::cout << "====== The second round (" << playersOfThisRound[0]->getNameForOthers() << " vs " << playersOfThisRound[1]->getNameForOthers() << ")======" << std::endl;
            }
        }

        if (numOfBrackets == 2) {
            /*
            The third and the last possible round:
            -Only happens when the num of player is 4
            -The winner of 1st round (player 1 vs player 2) vs the winner of 2nd round (player 3 vs player 4)
            */
            for(int i = 0; i < 2; i++) {
                playersOfThisRound.push_back(previousWinner[i]);
            }
            std::cout << "====== The final round (" << playersOfThisRound[0]->getNameForOthers() << " vs " << playersOfThisRound[1]->getNameForOthers() << ")======" << std::endl;
        }

        //Create different deck depending on the number of players
        //The deck is shuffled when it is created.
        cout << "==Creating the deck==" << endl << endl;
        Deck deck = Deck(numOfPlayers);

        std::cout << "==Your hands==" << endl;
        //Create empty hands
        for (int i = 0; i < 2; i++) {
            std::cout << playersOfThisRound[i]->getNameForOthers() << ": ";
            playersOfThisRound[i]->initializeHand(); //giving each player an empty hand with 0 cards
            playersOfThisRound[i]->printHand(); //Displaying the hand. Shouldn't print anything
        }
        std::cout << endl;

        //The same for both game mode
        
        std::cout << "==Generating the topboard==" << endl;
        //Draw 6 cards (top board)
        vector<Cards*> *topboard = deck.topBoardGenetor(deck);
        deck.displayTopBoard(*topboard);

        /*
        for (int i = 0; i < numOfPlayers; i++) {

            players[i]->SetCubes(14);

            players[i]->SetDisks(3);

            players[i]->placeNewArmies(m, 4, 0, i);
            
            std::cout << "Choose the index of the territory you want to place your army (except the starting region)." << std::endl;
            int index;
            cin >> index;
            while (index == 0 || index > m.getTerritoriesVector()->size()) {
                std::cout << "You can't place your army there. Try again: " << endl;
                cin >> index;
            };
            players[i]->placeNewArmies(m, 1, index, i);
        }
        */
        int indexOfPlayers = 0;
        /*
        if (numOfPlayers == 2) {
            Player* npc = new Player();
            npc->SetCubes(10);
            int selectTerr = 0;
            for (int i = 0; i < npc->getCubesForOthers(); i++) {

                indexOfPlayers %= 2; //This decides whose turn it is.

                std::cout << players[i]->getName() << ", enter the territory index to place non-player army: ";
                cin >> selectTerr;
                while (selectTerr > m.getTerritoriesVector()->size() || selectTerr < 1) {
                    std::cout << "Invalid Territory ID. Try again: ";
                    cin >> selectTerr;
                }
                players[i]->placeNewArmies(m, selectTerr, 1, numOfPlayers+1);

                indexOfPlayers++;
            }
        }
        */

        //Bidding
        //Obtain the bidding coins of each player.
        std::cout << endl;
        std::cout << "==Bidding==" << endl;
        for (int i = 0; i < 2; i++) {
            cin.clear();
            cin.ignore();
            playersOfThisRound[i]->setBid(playersOfThisRound[i]);
        }

        std::cout << endl;
        std::cout << "==Order==" << endl;
        BidingFacility calculator = BidingFacility();
        
        //Decides which player (e.g. 1 or 2 goes first depending on the amount of coins)
        Player* winner = calculator.resolveBids();

        //WHAT IS HAPPENING?
        std::cout << winner->getNameForOthers() << " goes first." << std::endl << endl;

        //the winner goes first 
        int playerOrder = 0;

        for (auto it = players.begin(); it != players.end(); ++it, playerOrder++) {
            if ((players[playerOrder])->getName() == winner->getName()) {
                auto first = *it;
                players.erase(it);
                players.insert(players.begin(), first /* or std::move(first)*/) ;
                break;
            }
        }

        indexOfPlayers = 0;
        //Keep playing until turn 20
        for (int turn = 0; turn < 20; turn++) {
            //This decides whose turn it is.
            std::cout << "Turn #" << turn+1 << endl << endl;
            std::cout << "It is currently " << players[indexOfPlayers]->getNameForOthers() << "'s turn to play." << std::endl << endl;
            
            //Buy
            deck.exchange(players[indexOfPlayers], *topboard, deck); //You have to dereference because you are taking a reference to a player.

            indexOfPlayers++;
            indexOfPlayers %= 2;
            //Had to place indexOfPlayer%2 after indexOfPlayer++
        }
        //DESTRUCTORS EACH ROUND?
        
    }
    //Obtain and show the results
    ComputeScore cp;
    cp.determineWinner();
};