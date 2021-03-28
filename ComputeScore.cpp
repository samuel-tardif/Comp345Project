/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 228/03/2021
For COMP 345 -Assignment 2
------------------------------------------------------------------------------------------------*/

#pragma once
//Code for part 6, computeScore
#include "ComputeScore.h"

//Default constructor
ComputeScore::ComputeScore()
{
	player1 = new Player("Default");
	player2 = new Player("Default");
	map = new Map();
}

//Copy constructor
ComputeScore::ComputeScore(const ComputeScore& copied)
{
	this->player1 = new Player("Default");
	this->player2 = new Player("Default");
	this->map = new Map();
	*player1 = *copied.getPlayer1();
	*player2 = *copied.getPlayer2();
	*map = *copied.getMap();
}

//Constructor with parameters
ComputeScore::ComputeScore(Player* p1, Player* p2, Map* m)
{
	this->player1 = new Player("Default");
	this->player2 = new Player("Default");
	this->map = new Map();
	player1 = p1;
	player2 = p2;
	map = m;
}

//= Operator overload
ComputeScore& ComputeScore::operator=(const ComputeScore& bF)
{
	*player1 = *bF.getPlayer1();
	*player2 = *bF.getPlayer2();
	*map = *bF.getMap();
	return *this;
}

//Destructor
ComputeScore::~ComputeScore()
{
	delete player1;
	delete player2;
	delete map;
}


//THE BIG ONE - function to get scores and determine winner
Player* ComputeScore::determineWinner()
{
	//Setting up a couple pointers to keep track of scores
	//Points for controling continents
	int* player1Continent = new int(0);
	int* player2Continent = new int(0);
	//Points for controlling territories
	int* player1Territories = new int(0);
	int* player2Territories = new int(0);
	//Total armies doesnt give points, it is for tiebreaker
	int* player1TotalArmies = new int(0);
	int* player2TotalArmies = new int(0);
	//Points from game hand
	int* player1CardScore = new int(0);
	int* player2CardScore = new int(0);


	//We are now gonna check for each for each continent who owns the most territories 
	for (int i = 1; i <= 4; i++) {
		tallyContinent(i, player1Continent,
			player2Continent,
			player1Territories,
			player2Territories,
			player1TotalArmies,
			player2TotalArmies);
	}

	//Check points from game hand



	//No memery leaks here ( i hope)
	delete player1CardScore, player1Continent, player1Territories, player1TotalArmies, player2Continent, player2Territories, player2TotalArmies, player2CardScore;

	return nullptr;
}


//Method to tally the scores for 1 continent
void ComputeScore::tallyContinent(int contIndex, int* player1Continent,
	int* player2Continent,
	int* player1Territories,
	int* player2Territories,
	int* player1TotalArmies,
	int* player2TotalArmies) {

	int* player1TerritoriesOnContinent = new int(0);
	int* player2TerritoriesOnContinent = new int(0);

	//To check the connectivity of our continents, we will use the same method as for the whole graph
	//But we will edit the visited matrix so that the DFS can only go to the territories of the searched continent

	//Creating our visited vec to keep track of where we went
	vector<bool>* visited = new vector<bool>;

	//We also have to make sure the continent exists in our graph
	//False unless found
	bool exists = false;

	//On top of that we need a territory to start DFS from
	int startIndex = 0;

	std::vector<std::vector<Map::Territory*>>* territoriesVector = map->getTerritoriesVector();

	//Size has to be size of our territory vector
	for (int i = 0; i < territoriesVector->size(); i++) {

		//If territory is in proper continent
		if (territoriesVector->at(i).at(0)->getContinent() == contIndex) {
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
		DFS(startIndex, visited,
			player1TerritoriesOnContinent,
			player2TerritoriesOnContinent,
			player1TotalArmies,
			player2TotalArmies);
	}

	//We now update the scores accordingly
	*player1Territories += *player1TerritoriesOnContinent;
	*player2Territories += *player2TerritoriesOnContinent;

	//Score for the wholle continent
	if (*player1TerritoriesOnContinent > *player2TerritoriesOnContinent) {
		*player1Continent += 1;
	}
	if (*player1TerritoriesOnContinent < *player2TerritoriesOnContinent) {
		*player2Continent += 1;
	}
}

//Iterates through a connected graph to get score from territories, we do this 1 continent at a time
void ComputeScore::DFS(int visiting, vector<bool>* visited,
	int* player1TerritoriesOnContient,
	int* player2TerritoriesOnContient,
	int* player1TotalArmies,
	int* player2TotalArmies) {

	visited->at(visiting) = true;

	//Retrieve llist of territories from map
	std::vector<std::vector<Map::Territory*>>* territoriesVector = map->getTerritoriesVector();

	//Retrieve current territory
	Map::Territory* current= territoriesVector->at(visiting).at(0);
	//Process resullts for where we landed
	int p1Armies = current->getNbArmies1();
	int p2Armies = current->getNbArmies2();

	//Update total number of armies on board in case of tiebreaker
	*player1TotalArmies += p1Armies;
	*player2TotalArmies += p2Armies;
	
	//We give a point to whoever has the most armies
	if (p1Armies > p2Armies) {
		*player1TerritoriesOnContient += 1;
	}
	if (p1Armies < p2Armies) {
		*player2TerritoriesOnContient += 1;
	}
	


	//The index of the territories adjacent to our visiting
	int adjIndex = 0;
	Map::Territory* adj = new Map::Territory();
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
			DFS(adjIndex, visited, player1TerritoriesOnContient,
				player2TerritoriesOnContient,
				player1TotalArmies,
				player2TotalArmies);
		}
	}
	delete adj;

}

//Getter player 1
Player* ComputeScore::getPlayer1() const
{
	return player1;
}
//Getter payer 2
Player* ComputeScore::getPlayer2() const
{
	return player2;
}
//Getter map
Map* ComputeScore::getMap() const
{
	return map;
}
//Setter player 1
void ComputeScore::setPlayer1(Player* p1)
{
	player1 = p1;
}
//Setter player 2
void ComputeScore::setPlayer2(Player* p2)
{
	player2 = p2;
}
//Setter map
void ComputeScore::setPlayer2(Map* m)
{
	map = m;
}
//String insertion overload
std::ostream& operator<<(std::ostream& output, const ComputeScore& m)
{
	output << "Compute score object" << std::endl;
	return output;
}
