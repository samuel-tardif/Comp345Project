/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//This is the header file of part 1, the map

#pragma once
#include <list>
#include <vector>
#include <array>
#include <iostream>

class Map {
public:
	

	//Default constructor
	Map();

	//Copy constructor
	Map(const Map &copied);

	//operator overloads =
	Map& operator= (const Map& m);

	//operator overloads <<
	friend std::ostream& operator<< (std::ostream& output, const Map& m);

	//Methods to manipulate map
	void addTerritory();

	void addTerritory(int own, int armies, int cont);

	void createConnection(int, int);

	void changeNumberArmies(int index, int nbArmies);

	void changeOwner(int index, int owner);
	
	void changeContinent(int index, int owner);

	class Territory {

		
	public:

		Territory& operator= (const Territory& ter);

		friend std::ostream& operator<< (std::ostream& output, const Territory& ter);
		
		//Getter
		int getOwner() const;
		int getNbArmies() const;
		int getContinent() const;

		//Setter
		void setOwner(int);
		void setNbArmies(int);
		void setContinent(int);



		//Constructors
		//Default constructor
		Territory();

		//Constructor with parameters (will be used by copy constructor)
		Territory(int own, int armies, int continent);
		
		//Copy constructor (as required)
		Territory(const Territory &ter);

		//Destructor
		~Territory();

	private:

		//Variables
		int* owner;
		int* nbArmies;
		int* continent;
	};

	std::vector<std::vector<Map::Territory*>>* getTerritoriesVector() const;

	//Methods to test connectivity
	bool connectedGraph();

	bool connectedContinent(int);

	bool validate();

	void DFS(int, std::vector<bool>*);

	//Destructor
	~Map();
	
private:

	//Variables
	std::vector<std::vector<Territory*>>* territoriesVector = NULL;
};
