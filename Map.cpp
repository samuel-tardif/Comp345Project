/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//This is the cpp file of part 1, the map

#include "Map.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
//Default constructor
Map::Map()
{
	territoriesVector = new std::vector<std::vector<Territory*>>;
}

//Copy constructor
Map::Map(const Map& copied)
{
	this->territoriesVector = copied.getTerritoriesVector();
}

//Overload the = operator
Map& Map::operator=(const Map& m)
{
	territoriesVector = m.getTerritoriesVector();

	return *this;
}


//Validates our map
bool Map::validate()
{
	cout << "Validating..." << endl;
	//We do not need to validate that every territory exists on only one continent because 
	//the implementation does not allow it

	//Checking that the graph as a whole is connected
	if (Map::connectedGraph() == false) {
		cout << "Map is not a connected graph" << endl;
		return false;
	}
	cout << "Map is a connected graph" << endl;

	//Checking our continents
	//My implementation here will assume continents are only 1-4 (as in the game)
	for (int i = 1; i <= 4; i++) {
		if (Map::connectedContinent(i) == false) {
			cout << endl << "Continent not connected, map in invalid" << endl << endl;
			return false;
		}
	}
	cout << "All continents are a connected graph" << endl << endl;

	cout << "Map is valid" << endl << endl;
	return true;
}

//Method to check if the whole graph is connected
bool Map::connectedGraph()
{
	//Creating our visited vec to keep track of where we went
	vector<bool>* visited = new vector<bool>;
	//Size has to be size of our territory vector
	for (int i = 0; i < territoriesVector->size(); i++) {
		visited->push_back(false);
	}

	DFS(0, visited);

	//Initializing our boolean, willll be true unless proven otherwise
	bool isConnected = true;

	//Iterating through visited
	for (int i = 0; i < visited->size(); i++) {
		//If one node is not visited graph is not connected
		if (visited->at(i) == false) {
			isConnected = false;
		}
	}

	cout << "Valid graph: " << isConnected << endl;

	delete visited;

	return isConnected;
}

//Algorithm to traverse graph
void Map::DFS(int visiting, vector<bool>* visited)
{
	visited->at(visiting) = true;

	//The index of the territories adjacent to our visiting
	int adjIndex=0;
	Territory* adj = new Territory();
	//For all connections checking if we need a recursive call
	for (int i = 1; i < territoriesVector->at(visiting).size(); i++) {
		

		//Finding our adj territory
		adj = territoriesVector->at(visiting).at(i);
		

		//Finding the index of our adjacent territory
		for (int j = 0; j < territoriesVector->size(); j++) {

			if (adj == territoriesVector->at(j).at(0)) {
				adjIndex = j;
			}
		}

		

		if (visited->at(adjIndex) == false) {
			DFS(adjIndex,visited);
		}
	}
	delete adj;
}

//Function to check if continent is connected, takes as parameter the number of the continent
bool Map::connectedContinent(int continent) {

	//To check the connectivity of our continents, we will use the same method as for the whole graph
	//But we will edit the visited matrix so that the DFS can only go to the territories of the searched continent
	
	//Creating our visited vec to keep track of where we went
	vector<bool>* visited = new vector<bool>;
	
	//We also have to make sure the continent exists in our graph
	//False unless found
	bool exists = false;

	//On top of that we need a territory to start DFS from
	int startIndex =0 ;

	//Size has to be size of our territory vector
	for (int i = 0; i < territoriesVector->size(); i++) {
		
		//If territory is in proper continent
		if (territoriesVector->at(i).at(0)->getContinent() == continent) {
			//We will need to reach it with DFS
			visited->push_back(false);
			//The continent exists
			exists = true;
			//We can start from its index
			startIndex = i;
		}
		else {
			//If territory is not part of the continent, we mark it as visited to block access and because it is okay for the DFS not to reach it
			visited->push_back(true);
		}
	}

	//If the continent exists, we search through it
	if (exists) {
		DFS(startIndex, visited);
	}


	//Initializing our boolean, willll be true unless proven otherwise
	bool isConnected = true;
	//
	//Iterating through visited
	//The visited vector will be all true if continent does not exist as well
	for (int i = 0; i < visited->size(); i++) {
		//If one node is not visited graph is not connected
		if (visited->at(i) == false) {
			isConnected = false;
		}
	}

	cout << "Continent " << continent << " connected : " << isConnected << endl;

	delete visited;

	return isConnected;
}

//Create a territory in map
void Map::addTerritory()
{
	std::vector<Map::Territory*> v;
	v.push_back(new Territory());
	territoriesVector->push_back(v);
	int index = territoriesVector->size() - 1;
	cout << "New territory added to territoriesVector index :" << index << endl;
}

//Creates a territory with assigned values in map
void Map::addTerritory(int own, int armies1, int armies2, int cont)
{
	std::vector<Map::Territory*> v;
	v.push_back(new Territory(own, armies1, armies2, cont));
	territoriesVector->push_back(v);
	int index = territoriesVector->size() - 1;
	cout << "New territory added to territoriesVector index :" << index << endl;
}

//Default Constructor
Map::Territory::Territory() {
	nbArmies1 = new int(0);
	nbArmies2 = new int(0);
	owner = new int(0);
	continent = new int(1);
}

//Constructor with parameters
Map::Territory::Territory(int own, int armies1,int armies2, int cont)
{
	nbArmies1 = new int(armies1);
	nbArmies2 = new int(armies2);
	owner = new int(own);
	continent = new int(cont);
}

//Copy constructor
Map::Territory::Territory(const Territory &ter)
{
	nbArmies1 = new int(0);
	nbArmies2 = new int(0);
	owner = new int(0);
	continent = new int(0);
	*this->nbArmies1 = ter.getNbArmies1();
	*this->nbArmies1 = ter.getNbArmies2();
	*this->owner = ter.getOwner();
	*this->continent = ter.getOwner();
}

//Destructor
Map::Territory::~Territory()
{
	delete owner;
	delete nbArmies1;
	delete nbArmies2;
	delete continent;
}

Map::~Map() {
	delete territoriesVector;
}


//Method to link two territories
void Map::createConnection(int firstTer, int secondTer)
{
	if (firstTer < territoriesVector->size() && secondTer < territoriesVector->size()) {
		(territoriesVector->at(firstTer)).push_back(territoriesVector->at(secondTer).at(0));
		(territoriesVector->at(secondTer)).push_back(territoriesVector->at(firstTer).at(0));
		cout << "Linked territories "<< firstTer << " and "<< secondTer << endl;
	}
	else {
		cout << "Invalid, one of those territories does not exist" << endl;
	}
}

//Change a value of nb armies on territory from index
void Map::changeNumberArmies(int index, int nbArmies, int player) //0, 4, 1
{
	cout << "Good until here 2.6" << endl;
	if (player == 1) {
		cout << "Good until here 2.7.1" << endl;
		territoriesVector->at(index).at(0)->setNbArmies1(nbArmies); //Problem happening here
		//territoriesVector[0, 0] set number of armies to 4
		cout << "Good until here 2.7.1.2" << endl;
	}
	else {
		cout << "Good until here 2.7.2" << endl;
		territoriesVector->at(index).at(0)->setNbArmies2(nbArmies);
		cout << "Good until here 2.7.2.2" << endl;
	}
	cout << "Territory " << index << " now has " << nbArmies << " armies" << endl;

}





//Change owner from index
void Map::changeOwner(int index, int owner)
{
	territoriesVector->at(index).at(0)->setOwner(owner);
	cout << "Territory " << index << " is now owned by player " << owner << endl;
}

//Change continent from index
void Map::changeContinent(int index, int cont)
{
	territoriesVector->at(index).at(0)->setContinent(cont);
	cout << "Territory " << index << " is now part of continent " << cont << endl;
}

//Standard getter
std::vector<std::vector<Map::Territory*>>* Map::getTerritoriesVector() const
{
	return territoriesVector;
}

//Standard getter
int Map::Territory::getOwner() const
{
	return *owner;
}

//Standard getter
int Map::Territory::getNbArmies1() const
{
	return *nbArmies1;
}

int Map::Territory::getNbArmies2() const
{
	return *nbArmies2;
}


//Standard getter
int Map::Territory::getContinent() const
{
	return *continent;
}

//Standard setter
void Map::Territory::setOwner(int newOwner)
{
	*owner = newOwner;
	this->Notify();
}

//Standard setter
void Map::Territory::setNbArmies1(int newNbArmies)
{
	*nbArmies1 = newNbArmies;
	this->Notify();
}
void Map::Territory::setNbArmies2(int newNbArmies)
{
	*nbArmies2 = newNbArmies;
	this->Notify();
}

//Standard setter
void Map::Territory::setContinent(int cont)
{
	*this->continent = cont;
}

//Overriding = operator for TErritory
Map::Territory& Map::Territory::operator= (const Map::Territory& ter){
	*owner = ter.getOwner();
	*nbArmies1 = ter.getNbArmies1();
	*nbArmies2 = ter.getNbArmies2();
	*continent = ter.getContinent();

	return *this;
}

//Overriding string insertion for Territory
std::ostream& operator<<(std::ostream& output, const Map::Territory& ter)
{
		output << "Territory owned by player " << ter.getOwner() << " and is occupied by " << ter.getNbArmies1() << " armies of player 1 and "<<ter.getNbArmies2()<<" armies of player 2 on continent " << ter.getContinent() << std::endl;
		return output;
}

//Overriding string insertion for map
std::ostream& operator<< (std::ostream& output, const Map& m) {
	output << "Map with " << m.getTerritoriesVector()->size() << " territories" << std::endl;
	return output;
}
