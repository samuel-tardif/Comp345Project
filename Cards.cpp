#include "Cards.h"

Cards::Cards() {
    this->name = nullptr;
    this->ability = nullptr;
    this->action = nullptr;
}
//Copy constructor
Cards::Cards(const Cards& copied)
{
	this->name = copied.getName();
    this->ability = copied.getAbility();
    this->action = copied.getAction();
}

//Overload the = operator
Cards& Cards::operator=(const Cards& c)
{
	name = c.getName();
    ability = c.getAbility();
    action = c.getAction();

	return *this;
}

ostream& operator<<(ostream& os, const Cards& cards) {
    os << *cards.getName() << " (" << *cards.getAbility() << ") - " << *cards.getAction();
    return os;
}

//Destructor
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

//Parameterized constructor
Cards::Cards(string n, string ab, string ac) {
    Cards::name = new string(n);
    Cards::ability = new string(ab);
    Cards::action = new string(ac);
}
