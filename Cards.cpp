#include "Cards.h"
#include <ctime>
#include <algorithm>
#include <iostream>

joueur::joueur()
{
    this->coins = nullptr;
    this->name = nullptr;
    this->gameHand = nullptr;
}

joueur::joueur(std::string n)
{
    joueur::coins = new int(12);
    joueur::name = new std::string(n);
    joueur::gameHand = new std::vector<Cards*>();
}

joueur::~joueur()
{
    if (coins) {
        delete coins;
        coins = nullptr;
    }

    if (name) {
        delete name;
        name = nullptr;
    }

    if (gameHand) {
        delete gameHand;
        gameHand = nullptr;
    }

};

// General Gameplay Methods

bool joueur::payCoin(int cost)
{
    if (*coins < cost) {
        std::cout << "You don't have enough coins to purchase that." << std::endl;
        return false;
    }
    else {
        setCoins(*coins - cost);
        std::cout << "Successful purchase " << *name << ", you have " << *coins << " coins remaining in your pile." << std::endl << std::endl;
        return true;
    }
}

// Accessors

int joueur::getCoins() const { return *coins; }

std::string& joueur::getName() { return *name; }

std::vector<Cards*>& joueur::getGameHand() { return *gameHand; }


// Mutators

void joueur::setCoins(int coins) { *joueur::coins = coins; }

void joueur::setName(std::string name) { *joueur::name = name; }

Cards::Cards() {
    this->name = nullptr;
    this->ability = nullptr;
    this->action = nullptr;
}

ostream& operator<<(ostream& os, const Cards& cards) {
    os << *cards.getName() << " (" << *cards.getAbility() << ") - " << *cards.getAction();
    return os;
}

Cards::~Cards() {
    
    if (name) {
        delete name;
        name = nullptr;
    }
    
    if (ability) {
        delete ability;
        ability = nullptr;
    }
    
    if (action) {
        delete action;
        action = nullptr;
    }
}

string *Cards::getName() const {
    return this->name;
}

void Cards::setName(string name) {
    Cards::name = new string(name);
}

string *Cards::getAbility() const {
    return this->ability;
}

void Cards::setAbility(string ability) {
    Cards::ability = new string(ability);
}

string *Cards::getAction() const {
    return this->action;
}

void Cards::setAction(string action) {
    Cards::action = new string(action);
}

Cards::Cards(string n, string ab, string ac) {
    Cards::name = new string(n);
    Cards::ability = new string(ab);
    Cards::action = new string(ac);
}

//2 players
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

//3 players
Cards* cards28 = new Cards("Arcane Manticore", "MOVE ARMIES 1", "PLACE NEW ARMIES ON THE BOARD 4 AND DESTROY AN ARMY");
Cards* cards29 = new Cards("Arcane Sphinx", "FLYING", "PLACE NEW ARMIES ON THE BOARD 3 OR MOVE ARMIES 4");
Cards* cards30 = new Cards("Arcane Temple", "+1 VP PER ARCANE CARD", "MOVE ARMIES 3");
Cards* cards31 = new Cards("Mountain Dwarf", "+3 VP IF YOU HAVE TWO MOUNTAIN CARDS", "PLACE NEW ARMIES ON THE BOARD 2 AND DESTROY AN ARMY");
Cards* cards32 = new Cards("Mountain Treasury", "ELIXIR 1 AND GAIN COINS", "MOVE ARMIES 3");

//4 players
Cards* cards33 = new Cards("Castle", "ELIXIR 1", "PLACE NEW ARMIES ON THE BOARD 3 OR BUILD A CITY");
Cards* cards34 = new Cards("Castle 2", "ELIXIR 1", "MOVE ARMIES 3 AND BUILD A CITY");

Deck::Deck() {
    position = new int();
    deck.push_back(cards01);
    deck.push_back(cards02);
    deck.push_back(cards03);
    deck.push_back(cards04);
    deck.push_back(cards05);
    deck.push_back(cards06);
    deck.push_back(cards07);
    deck.push_back(cards08);
    deck.push_back(cards09);
    deck.push_back(cards10);
    deck.push_back(cards11);
    deck.push_back(cards12);
    deck.push_back(cards13);
    deck.push_back(cards14);
    deck.push_back(cards15);
    deck.push_back(cards16);
    deck.push_back(cards17);
    deck.push_back(cards18);
    deck.push_back(cards19);
    deck.push_back(cards20);
    deck.push_back(cards21);
    deck.push_back(cards22);
    deck.push_back(cards23);
    deck.push_back(cards24);
    deck.push_back(cards25);
    deck.push_back(cards26);
    deck.push_back(cards27);
    deck.push_back(cards28);
    deck.push_back(cards29);
    deck.push_back(cards30);
    deck.push_back(cards31);
    deck.push_back(cards32);
    deck.push_back(cards33);
    deck.push_back(cards34);
}

Deck::~Deck() {
    
    if(cost){
        delete cost;
        cost = nullptr;
    }
    if(position){
        delete position;
        position = nullptr;
    }
}

Cards* Deck::draw() {
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(deck.begin(), deck.end());

    auto card = deck.back();
    deck.pop_back();

    return card;
}

std::vector<Cards*> Deck::topBoardGenetor(Deck& deck) {
    auto tb = new std::vector<Cards*>();
    for (auto i = 0; i < 6; i++) {
        tb->emplace_back(deck.draw());
    }
    return *tb;
}

void Deck::displayTopBoard(std::vector<Cards*>& topBoard) {
    int j = 0;
    int index = 0;
    for (auto it = topBoard.begin(); it != topBoard.end(); ++it)
        cout << ++j << ") " << posArray[index++] << " Coins - " << **it << endl;
}

void Deck::updateTopBoard(int& position, std::vector<Cards*>& topBoard, Deck& deck) {
    int index = position - 1;
    topBoard.erase(topBoard.begin() + index);
    cout << "Top Board cards series size is " << topBoard.size() << endl;
    topBoard.emplace_back(deck.draw());
    cout << "Top Board cards series size is " << topBoard.size() << endl;
    displayTopBoard(topBoard);
}

std::vector<Cards*> Deck::handGenetor(Cards*& card) {
    std::vector<Cards*> hand;
    hand.emplace_back(card);
    return hand;
}

void Deck::displayHand(std::vector<Cards*>& hand) {
    for (auto it = hand.begin(); it != hand.end(); ++it) {
        std::cout << ' ' << **it << endl;
    }
}

void Deck::exchange(joueur& player, std::vector<Cards*>& topBoard, Deck& deck) {
    bool successfullPurchase = false;
    int cost = 0, position, index;

    // display top board before player purchases a card
    cout << "The 6 cards on the board:" << endl;
    displayTopBoard(topBoard);

    // allow player to purchase a card
    cout << player.getName() << ", you have " << player.getCoins() << " coins remaining." << endl;
    cout << "Which card do you want to buy? Please enter a number from 1 to 6: " << endl;
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
        successfullPurchase = player.payCoin(cost);
    } while (!successfullPurchase);

    // purchase confirmation
    index = position - 1;

    //vector<Cards*> playerHand = player.getGameHand();

    // update gamehand and update top board
    player.getGameHand().emplace_back(topBoard.at(index));
    topBoard.erase(topBoard.begin() + index);
    topBoard.emplace_back(deck.draw());
    cout << player.getName() << " added [" << *player.getGameHand().back() << "] to their hand." << endl;
}