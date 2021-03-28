#include "Cards.h"
#include <iostream>

int main() {
    
    Deck* deck1 = new Deck();
    joueur* p1 = new joueur("Player");
    std::vector<Cards*> tb = deck1->topBoardGenetor(*deck1);
    std::vector<Cards*> hand = std::vector<Cards*>();
    deck1->exchange(*p1, tb, *deck1);
    deck1->exchange(*p1, tb, *deck1);
    deck1->displayTopBoard(tb);

}