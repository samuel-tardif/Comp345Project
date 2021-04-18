/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 228/03/2021
For COMP 345 -Assignment 2
------------------------------------------------------------------------------------------------*/
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
	this->player1 = p1;
	this->player2 = p2;
	this->map = m;
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
ComputeScore::~ComputeScore() {}

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
	//Retrieving game hands
	std::vector<Cards*> p1GameHand = player1->getHandContent();
	std::vector<Cards*> p2GameHand = player2->getHandContent();

	//Setting up lixirs totals
	int* p1Elixirs = new int(0);
	int* p2Elixirs = new int(0);

	tallyGameHand(p1GameHand, player1CardScore, p1Elixirs, player1);
	tallyGameHand(p2GameHand, player2CardScore, p2Elixirs, player2);

	//Giving ellixir points
	if (*p1Elixirs > *p2Elixirs) {
		*player1CardScore += 2;
	}
	if (*p1Elixirs < *p2Elixirs) {
		*player2CardScore += 2;
	}
	if (*p1Elixirs == *p2Elixirs) {
		*player1CardScore += 1;
		*player2CardScore += 1;
	}

	//Points run-down
	//Player 1
	int player1Total = 0;
	cout << " Player 1 points :" << endl << endl;
	player1Total += *player1Territories;
	cout << " Territories : " << *player1Territories << endl;
	player1Total += *player1Continent;
	cout << " Continents : " << *player1Continent << endl;
	player1Total += *player1CardScore;
	cout << " Cards : " << *player1CardScore << endl << endl;
	cout << " Total points : "<< player1Total << endl << endl;

	//Player  2
	int player2Total = 0;
	cout << " Player 2 points :" << endl << endl;
	player2Total += *player2Territories;
	cout << " Territories : " << *player2Territories << endl;
	player2Total += *player2Continent;
	cout << " Continents : " << *player1Continent << endl;
	player2Total += *player2CardScore;
	cout << " Cards : " << *player2CardScore << endl << endl;
	cout << " Total points : " << player2Total << endl << endl;

	//Dertermining winner
	if (player1Total > player2Total) {
		cout << " Player 1 wins with more victory points" << endl << endl;
	}
	if (player1Total < player2Total) {
		cout << " Player 2 wins with more victory points" << endl << endl;
	}
	//Equality -> tie breakers
	if (player1Total == player2Total) {
		cout << " Both payers have the same amount of victory points" << endl << endl;
		//Gold tie breaker
		if (player1->getTokens() > player2->getTokens()) {
			cout << " Player 1 wins with more gold" << endl << endl;
		}
		if (player1->getTokens() < player2->getTokens()) {
			cout << " Player 2 wins with more gold" << endl << endl;
		}
		//Equality next tie breaker
		if (player1->getTokens() < player2->getTokens()) {
			cout << " Both players have as much gold" << endl << endl;
			//Gold tie breaker
			if (*player1TotalArmies > *player2TotalArmies) {
				cout << " Player 1 wins with more armies" << endl << endl;
			}
			if (*player1TotalArmies < *player2TotalArmies) {
				cout << " Player 2 wins with more armies" << endl << endl;
			}
			//Equality next tie breaker
			if (*player1TotalArmies == *player2TotalArmies) {
				cout << " Both players have just as many armies" << endl << endl;
				//Territories tie breaker
				if (*player1Territories > *player2Territories) {
					cout << " Player 1 wins with more territories" << endl << endl;
				}
				if (*player1Territories < *player2Territories) {
					cout << " Player 2 wins with more territories" << endl << endl;
				}
				if (*player1Territories == *player2Territories) {
					cout << " IT'S A DRAW!!!" << endl << endl;
				}
			}
		}
	}


	//No memory leaks here (i hope) Actualllly delete makes my program crash, I will need help
	//delete player1CardScore, player1Continent, player1Territories, player1TotalArmies, player2Continent, player2Territories, player2TotalArmies, player2CardScore, p1Ellixirs,p2Elixirs;
	return nullptr;
}

//Method to dertermine how many points our hand is worth
void ComputeScore::tallyGameHand(std::vector<Cards*> GameHand, int* playerCardScore, int* playerElixir, Player* player) {
	//Loop throughh game hand
	for (int i = 0; i < GameHand.size(); i++) {
		//Check what cards we have
		
		string name = *GameHand.at(i)->getName();
		string ability = *GameHand.at(i)->getAbility();
		
		//Check for elixirs
		std::size_t found = name.find("ELIXIR");
		if (found != std::string::npos) {
			//Check for 1 elixir
			found = name.find("1");
			if (found != std::string::npos) {
				*playerElixir += 1;
			}
			//Check for 2 elixir
			found = name.find("2");
			if (found != std::string::npos) {
				*playerElixir += 2;
			}
			//Check for 3 elixir
			found = name.find("3");
			if (found != std::string::npos) {
				*playerElixir += 3;
			}
		}
		
		//Check for Ancient SAge
		found = name.find("Ancient Sage");
		if (found != std::string::npos) {
			//For ancient sage and allll similar cards, we need to iterate throuhg hand to find matches
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for ancient in name
				found = name.find("Ancient");
				if (found != std::string::npos) {
					*playerCardScore += 1;
				}
			}
		}

		//Check for Cursed Tower
		found = name.find("Cursed Tower");
		if (found != std::string::npos) {
			//For ancient sage and allll similar cards, we need to iterate throuhg hand to find matches
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for Fllying ability
				found = ability.find("FLYING");
				if (found != std::string::npos) {
					*playerCardScore += 1;
				}
			}
		}

		//Check for Dire Ogre
		found = name.find("Dire Ogre");
		if (found != std::string::npos) {
			//Add 1/3 of gold to score
			*playerCardScore += (int)player->getTokens() / 3;
		}

		//Check for Graveyard
		found = name.find("Graveyard");
		if (found != std::string::npos) {
			//For ancient sage and allll similar cards, we need to iterate throuhg hand to find matches
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for cursed in name
				found = name.find("Cursed");
				if (found != std::string::npos) {
					*playerCardScore += 1;
				}
			}
		}

		//Check for Lake
		found = name.find("Lake");
		if (found != std::string::npos) {
			//For ancient sage and allll similar cards, we need to iterate throuhg hand to find matches
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for forest in name
				found = name.find("Forest");
				if (found != std::string::npos) {
					*playerCardScore += 1;
				}
			}
		}

		//Check for Night Wizard
		found = name.find("Night Wizard");
		if (found != std::string::npos) {
			//For ancient sage and allll similar cards, we need to iterate throuhg hand to find matches
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for night in name
				found = name.find("Night");
				if (found != std::string::npos) {
					*playerCardScore += 1;
				}
			}
		}

		//Check for Noble Hills
		found = name.find("Nobe Hills");
		if (found != std::string::npos) {
			//For this one we need to count noblle cards
			int totalNoble = 0;
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for noble in name
				found = name.find("Night");
				if (found != std::string::npos) {
					totalNoble += 1;
				}
			}
			//4 points for 3 nobles
			if (totalNoble >= 3) {
				*playerCardScore += 4;
			}
		}

		//Check for Stronghold
		found = name.find("Stronghold");
		if (found != std::string::npos) {
			//For ancient sage and allll similar cards, we need to iterate throuhg hand to find matches
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for dire in name
				found = name.find("Dire");
				if (found != std::string::npos) {
					*playerCardScore += 1;
				}
			}
		}

		//Check for Arcane Temple
		found = name.find("Stronghold");
		if (found != std::string::npos) {
			//For ancient sage and allll similar cards, we need to iterate throuhg hand to find matches
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for Arcane in name
				found = name.find("Arcane");
				if (found != std::string::npos) {
					*playerCardScore += 1;
				}
			}
		}

		//Check for Mountain Dwarf
		found = name.find("Nobe Hills");
		if (found != std::string::npos) {
			//For this one we need to count Mountain cards
			int totalMountain = 0;
			for (int j = 0; j < GameHand.size(); j++) {
				//Rechecking cards
				name = *GameHand.at(j)->getName();
				ability = *GameHand.at(j)->getAbility();
				//Checking for Mountain in name
				found = name.find("Mountain");
				if (found != std::string::npos) {
					totalMountain += 1;
				}
			}
			//3 points for 2 nobles
			if (totalMountain >= 2) {
				*playerCardScore += 3;
			}
		}
	}
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
	cout << *player1TerritoriesOnContinent << " territories for player 1 on continent : " << contIndex << endl;
	*player2Territories += *player2TerritoriesOnContinent;
	cout << *player2TerritoriesOnContinent << " territories for player 2 on continent : " << contIndex << endl;

	//Score for the wholle continent
	if (*player1TerritoriesOnContinent > *player2TerritoriesOnContinent) {
		*player1Continent += 1;
	}
	if (*player1TerritoriesOnContinent < *player2TerritoriesOnContinent) {
		*player2Continent += 1;
	}

	//delete territoriesVector;
	//delete player1TerritoriesOnContinent;
	//delete player2TerritoriesOnContinent;
}

//Iterates through a connected graph to get score from territories, we do this 1 continent at a time
void ComputeScore::DFS(int visiting, vector<bool>* visited,
	int* player1TerritoriesOnContient,
	int* player2TerritoriesOnContient,
	int* player1TotalArmies,
	int* player2TotalArmies) {

	visited->at(visiting) = true;

	//Retrieve llist of territories from map
	std::vector<std::vector<Map::Territory*>> territoriesVector = *map->getTerritoriesVector();

	//Retrieve current territory
	Map::Territory* current = territoriesVector.at(visiting).at(0);
	//Process resullts for where we landed
	int p1Armies = current->getNbArmies1();
	int p2Armies = current->getNbArmies2();
	//Update total number of armies on board in case of tiebreaker
	*player1TotalArmies += p1Armies;
	*player2TotalArmies += p2Armies;

	//We give a point to whoever has the most armies
	if (p1Armies > p2Armies) {
		*player1TerritoriesOnContient += 1;
		cout << "p1Armies : " << p1Armies << " p2Armies : " << p2Armies << "  Points given to player 1, territories on continent :  " << *player1TerritoriesOnContient << endl;
	}
	else if (p1Armies < p2Armies) {
		*player2TerritoriesOnContient += 1;
		cout << "p1Armies : " << p1Armies << " p2Armies : " << p2Armies << "  Points given to player 2, territories on continent :  " << *player2TerritoriesOnContient  << endl;
	}
	else {
	cout << "p1Armies : " << p1Armies << " p2Armies : " << p2Armies << " No points given" << endl;
	}
	


	//The index of the territories adjacent to our visiting
	int adjIndex = 0;
	Map::Territory* adj = new Map::Territory();
	//For all connections checking if we need a recursive call
	for (int i = 1; i < territoriesVector.at(visiting).size(); i++) {


		//Finding our adj territory
		adj = territoriesVector.at(visiting).at(i);


		//Finding the index of our adjacent territory
		for (int j = 0; j < territoriesVector.size(); j++) {

			if (adj == territoriesVector.at(j).at(0)) {
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
	//delete adj;
	//delete current;
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
void ComputeScore::setMap(Map* m)
{
	map = m;
}

//String insertion overload
std::ostream& operator<<(std::ostream& output, const ComputeScore& m)
{
	output << "Compute score object" << std::endl;
	return output;
}
