#pragma once
/*-------------------------------------------------------------------------------------------
Code by Ibrahim Tawakool
ID: 40108389
Date : 29/03/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/

//This is the header file of part 1, the map loader


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include "MapLoader.h"
#include "Map.h"
using namespace std;


//default constructor
MapLoader::MapLoader() {
	filename = new string;
	m = new Map();
};
//copy constructor
MapLoader::MapLoader(const MapLoader& copied) {

	this-> filename = copied.getFileName();
	this-> m = copied.getMap();
};
//operator overload
MapLoader& MapLoader::operator=(const MapLoader& g) {
	string *file = new string;
	file = g.getFileName();
	m = g.getMap();
	return *this;
};
//destructor
MapLoader::~MapLoader() {
	delete filename;
	delete m;
};

//get and set methods
Map* MapLoader::getMap() const {
	return m;
};
void MapLoader::setMap(Map t) {
	*m = t;
};

string* MapLoader::getFileName() const {
	return filename;
};

void MapLoader::setFileName(string newFile) {
	*filename = newFile;
};

//generate map method
void MapLoader::GenerateMap() {
	//opens the file
	std::ifstream myfile(*filename, std::ios_base::in);


	int a, b, c = 0;
	ifstream input(*filename);
	//checks if file is opened or not
	if (input.is_open()) {
		cout << "file opened successfully" << endl;
	}
	else {
		cout << "error" << endl;
	}
	//parses through the a to create territories
	while (input >> a) {

		//breaks if delimiter is found
		if (a == 99) {
			break;
		}
		else {
			m->addTerritory(0, 0, a);
		}
	}
	//parses through pairs of connections to create connections
	while (input >> b >> c) {
		m->createConnection(b, c);
	}

	//prints map object
	cout << *m << endl;

	//creates vectors of territories
	vector<vector<Map::Territory*>>* v = m->getTerritoriesVector();
	for (int i = 0; i < v->size(); i++) {
		cout << *v->at(i).at(0) << endl;
	}
	//validates map object
	m->validate();
};


