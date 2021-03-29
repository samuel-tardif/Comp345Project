#pragma once

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

	string* getFileName() const;
	Map* getMap() const;
	void setMap(Map);
	void setFileName(string);


	void GenerateMap();


private:

	Map* m;
	string* filename;
};
