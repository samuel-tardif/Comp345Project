#pragma once
/*-------------------------------------------------------------------------------------------
Code by Ibrahim Tawakool
ID: 40108389
Date : 28/03/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//This is the header file of part 1, the map loader


#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include "Map.h"
using namespace std;


class MapLoader {
public:
	//Default constructor
	MapLoader();

	//Copy constructor
	MapLoader(const MapLoader& copied);

	//operator overloads =
	MapLoader& operator= (const MapLoader& bF);

	//operator overloads <<
	friend std::ostream& operator << (std::ostream& output, const MapLoader& m);

	//Destructor
	~MapLoader();

	//get and set methods
	string* getFileName() const;
	Map* getMap() const;
	void setMap(Map);
	void setFileName(string);

	//method to generate map
	void GenerateMap();


private:
	//variables
	Map* m;
	string* filename;
};
