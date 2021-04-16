#pragma once


#include <list>


using namespace std;

//Base observer implementation-------------------------------------------------------------------------------
class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();
};


//Base observable implementation-------------------------------------------------------------------------------
class Observable {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Observable();
	~Observable();
private:
	list<Observer*>* _observers;
};

/*



*/



