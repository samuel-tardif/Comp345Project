#include "Deck.h"
#include "Cards.h"
#include "Player.h"
#include <random>

//List of cards
//Added for 2 players

Cards* cards01 = new Cards("Ancient Phoenix", "FLYING", "MOVE ARMIES 5");
Cards* cards02 = new Cards("Ancient Sage", "+1 VP PER ANCIENT CARD", "MOVE ARMIES 3");
Cards* cards03 = new Cards("Ancient Tree Spirit", "ELIXIRS 3", "PLACE NEW ARMIES ON THE BOARD 4");
Cards* cards04 = new Cards("Ancient Wood", "PLACE NEW ARMIES ON THE BOARD 1", "BUILD A CITY AND PLACE NEW ARMIES ON THE BOARD 1");
Cards* cards05 = new Cards("Cursed Banshee", "ELIXIR 2", "MOVE ARMIES 6");
Cards* cards06 = new Cards("Cursed Gargoyles", "FLYING", "MOVE ARMIES 5");
Cards* cards07 = new Cards("Cursed King", "ELIXIR 1", "PLACE NEW ARMIES ON THE BOARD 3 OR MOVE ARMIES 4");
Cards* cards08 = new Cards("Cursed Mausoleum", "MOVE ARMIES 1", "BUILD A CITY");
Cards* cards09 = new Cards("Cursed Tower", "+1 VP PER FLYING", "BUILD A CITY");
Cards* cards10 = new Cards("Dire Dragon", "FLYING", "PLACE NEW ARMIES ON THE BOARD 3 AND DESTROY AN ARMY");
Cards* cards11 = new Cards("Dire Eye", "FLYING", "PLACE NEW ARMIES 4");
Cards* cards12 = new Cards("Dire Giant", "IMMUNE TO ATTACK", "PALCE NEW ARMIES 3 AND DESTROY AN ARMY");
Cards* cards13 = new Cards("Dire Goblin", "ELIXIR 1", "MOVE ARMIES 5");
Cards* cards14 = new Cards("Dire Ogre", "+1 VP PER 3 COINS", "MOVE ARMIES 2");
Cards* cards15 = new Cards("Forest Elf", "PLACE NEW ARMIES ON THE BOARD 1", "PLACE NEW ARMIES ON THE BOARD 3 OR MOVE ARMIES 2");
Cards* cards16 = new Cards("Forest Gnome", "ELIXIR 3", "MOVE ARMIES 2");
Cards* cards17 = new Cards("Forest Pixie", "PLACE NEW ARMIES ON THE BOARD 1", "MOVE ARMIES 4");
Cards* cards18 = new Cards("Forest Tree Town", "MOVE ARMIES 1", "BUILD A CITY");
Cards* cards19 = new Cards("Graveyard", "+1 VP PER CURSED CARD", "PLACE NEW ARMIES ON THE BOARD 2");
Cards* cards20 = new Cards("Lake", "+1 VP PER FOREST CARD", "PLACE NEW ARMIES ON THE BOARD 2 OR MOVE ARMIES 3");
Cards* cards21 = new Cards("Night Hydra", "PLACE NEW ARMIES ON THE BOARD 1", "MOVE ARMIES 5 AND DESTROY AN ARMY");
Cards* cards22 = new Cards("Night Village", "PLACE NEW ARMIES ON THE BOARD 1", "BUILD A CITY");
Cards* cards23 = new Cards("Night Wizard", "+1 VP PER NIGHT CARD", "PLACE NEW ARMIES ON THE BOARD 3 AND DESTROY AN ARMY");
Cards* cards24 = new Cards("Noble Hills", "THREE NOBLE CARDS = 4 VP", "PLACE NEW ARMIES ON THE BOARD 3");
Cards* cards25 = new Cards("Noble Knight", "MOVE ARMIES 1", "PLACE NEW ARMIES ON THE BOARD AND DESTROY AN ARMY");
Cards* cards26 = new Cards("Noble Unicorn", "MOVE ARMIES", "MOVE ARMIES 4 AND PLACE NEW ARMIES ON THE BOARD 1");
Cards* cards27 = new Cards("Stronghold", "+1 VP PER DIRE CARD", "BUILD A CITY");

//Added for 3 players
Cards* cards28 = new Cards("Arcane Manticore", "MOVE ARMIES 1", "PLACE NEW ARMIES ON THE BOARD 4 AND DESTROY AN ARMY");
Cards* cards29 = new Cards("Arcane Sphinx", "FLYING", "PLACE NEW ARMIES ON THE BOARD 3 OR MOVE ARMIES 4");
Cards* cards30 = new Cards("Arcane Temple", "+1 VP PER ARCANE CARD", "MOVE ARMIES 3");
Cards* cards31 = new Cards("Mountain Dwarf", "+3 VP IF YOU HAVE TWO MOUNTAIN CARDS", "PLACE NEW ARMIES ON THE BOARD 2 AND DESTROY AN ARMY");
Cards* cards32 = new Cards("Mountain Treasury", "ELIXIR 1 AND GAIN COINS", "MOVE ARMIES 3");

//Added for 4 players or more
Cards* cards33 = new Cards("Castle", "ELIXIR 1", "PLACE NEW ARMIES ON THE BOARD 3 OR BUILD A CITY");
Cards* cards34 = new Cards("Castle 2", "ELIXIR 1", "MOVE ARMIES 3 AND BUILD A CITY");

Deck::Deck() {
    vector<Cards*> *deck = nullptr;
    //int *cost = new int(0);

    //By default, create a deck for 2 players
    createDeck(2);
    shuffleDeck();
};

Deck::Deck(int numOfPlayers) {
    vector<Cards*> *deck = nullptr;
    //nt *cost = new int(0); //THIS IS ACTUALLY A NULL POINTER

    createDeck(numOfPlayers);
    shuffleDeck();
}

/*  
The function that creates the deck depending on the number of players
It creates a list of "Cards" pointers and assign them to the deck (vector of cards) member in the "Deck" object.
*/
void Deck::createDeck(int numOfPlayers) {
    position = new int();

    if (numOfPlayers >= 2) {
        ptrCard.push_back(cards01);
        ptrCard.push_back(cards02);
        ptrCard.push_back(cards03);
        ptrCard.push_back(cards04);
        ptrCard.push_back(cards05);
        ptrCard.push_back(cards06);
        ptrCard.push_back(cards07);
        ptrCard.push_back(cards08);
        ptrCard.push_back(cards09);
        ptrCard.push_back(cards10);
        ptrCard.push_back(cards11);
        ptrCard.push_back(cards12);
        ptrCard.push_back(cards13);
        ptrCard.push_back(cards14);
        ptrCard.push_back(cards15);
        ptrCard.push_back(cards16);
        ptrCard.push_back(cards17);
        ptrCard.push_back(cards18);
        ptrCard.push_back(cards19);
        ptrCard.push_back(cards20);
        ptrCard.push_back(cards21);
        ptrCard.push_back(cards22);
        ptrCard.push_back(cards23);
        ptrCard.push_back(cards24);
        ptrCard.push_back(cards25);
        ptrCard.push_back(cards26);
        ptrCard.push_back(cards27);

        if (numOfPlayers >= 3) {

            ptrCard.push_back(cards28);
            ptrCard.push_back(cards29);
            ptrCard.push_back(cards30);
            ptrCard.push_back(cards31);
            ptrCard.push_back(cards32);

            if (numOfPlayers >= 4) {
                ptrCard.push_back(cards33);
                ptrCard.push_back(cards34);
            }
        }
    }
    /*
    for (int i = 0; i < deck.size(); i++) {
		deck.push_back(ptrCard.at(i));	
	}
    */
    for (int i = 0; i < ptrCard.size(); i++) {
		deck.push_back(ptrCard.at(i));	
	}
};

//Destructor (more member need to be added)
Deck::~Deck() {
    /*
    if(cost){
        delete cost;
        cost = nullptr;
    }
    */
    
    if(position){
        delete position;
        position = nullptr;
    }    
}

//Copy constructor (more member need to be added)
Deck::Deck(const Deck& copied) //removed const before Deck&
{
	//this->cost = copied.getCost();
    this->position = copied.getPosition();
}

//Overload the = operator (more member need to be added)
Deck& Deck::operator=(const Deck& d) //removed const before Deck&
{
	//cost = d.getCost();
    position = d.getPosition();

	return *this;
}

//Stream insertion operator (more member need to be added)
ostream& operator<<(ostream& os, const Deck& deck) {
    os << /**deck.getCost()*/ " (" << *deck.getPosition() << ") " << std::endl;
    return os;
}
/*
int *Deck::getCost() const {
    return this->cost;
}
*/

int *Deck::getPosition() const {
    return this->position;
}
//===========================================================================================

//Separated draw and shuffle
//The function that allows you to draw the top card of the deck
Cards* Deck::draw() {
    auto card = deck.back();
    deck.pop_back();

    return card;
}

//The function that allows you to shuffle the deck
void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(deck.begin(), deck.end(), g);
}

//The function that generates the top board (6 cards)
std::vector<Cards*>* Deck::topBoardGenetor(Deck& deck) {
    auto tb = new std::vector<Cards*>();
    for (auto i = 0; i < 6; i++) {
        tb->emplace_back(deck.draw());
    }
    return tb;
}

//The function that displays the 6 cards on the top board.
void Deck::displayTopBoard(std::vector<Cards*>& topBoard) {
    int j = 0;
    int index = 0;
    for (auto it = topBoard.begin(); it != topBoard.end(); ++it)
        cout << ++j << ") " << posArray[index++] << " Coins - " << **it << endl;
}

//
void Deck::updateTopBoard(int& position, std::vector<Cards*>& topBoard, Deck& deck) {
    int index = position - 1;
    topBoard.erase(topBoard.begin() + index);
    cout << "Top Board cards series size is " << topBoard.size() << endl;
    topBoard.emplace_back(deck.draw());
    cout << "Top Board cards series size is " << topBoard.size() << endl;
    displayTopBoard(topBoard);
}

void Deck::exchange(Player* player, std::vector<Cards*>& topBoard, Deck& deck) { //changed Player& player to Player* player

    bool successfullPurchase = false;
    int cost = 0, position, index;

    // display top board before player purchases a card
    cout << "The 6 cards on the board:" << endl;
    displayTopBoard(topBoard);

    // allow player to purchase a card
    cout << player->getNameForOthers() << ", you have " << player->getCoinsForOthers() << " coins remaining." << endl;
    cout << "Which card do you want to buy? Please enter a number from 1 to 6: ";
    do {
        cin >> position;
        if (position < 1 || position > 6) {
            cout << "Invalid input: " << position << ". Please enter a number from 1 to 6: " << endl;
            continue;
        }
        if (position == 1) {
            cost = 0;
        }
        else if (position == 2 || position == 3) {
            cost = 1;
        }
        else if (position == 4 || position == 5) {
            cost = 2;
        }
        else if (position == 6) {
            cost = 3;
        }
        cout << endl;
        successfullPurchase = player->payCoin(cost);
    } while (!successfullPurchase);

    // purchase confirmation
    index = position - 1;

    //vector<Cards*> playerHand = player.getGameHand();

    // update gamehand and update top board
    // player->getHandContent().push_back(topBoard[index]);
    player->getHand().setHand(*topBoard[index]);
    topBoard.erase(topBoard.begin() + index);
    topBoard.emplace_back(deck.draw());
    //cout << player->getNameForOthers() << " added [" << *player->getHandContent().back() << "] to their hand." << endl << endl; //
}

//The function to print the content of the deck
void Deck::printDeck() {
	int j = 0;
	for (auto& i : deck) {
		cout << "[" << j + 1 << "] " << *i << endl;
		j++;
	}
}