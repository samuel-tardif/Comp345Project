#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>
#include "MapLoader.h"
#include "Map.h"
using namespace std;

MapLoader::MapLoader() {
	filename = new string;
	m = new Map();
};

MapLoader::MapLoader(const MapLoader& copied) {

	this-> filename = copied.getFileName();
	this-> m = copied.getMap();
};

MapLoader& MapLoader::operator=(const MapLoader& g) {
	string *file = new string;
	file = g.getFileName();
	m = g.getMap();
	return *this;
};

MapLoader::~MapLoader() {
	delete filename;
	delete m;
};
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


void MapLoader::GenerateMap() {
	std::ifstream myfile(*filename, std::ios_base::in);
	int a, b, c = 0;;
	ifstream input(*filename);
	if (input.is_open()) {
		cout << "file opened successfully" << endl;
	}
	else {
		cout << "error" << endl;
	}
	input >> a;
	while (input >> a) {
		if (a == 99) {
			break;
		}
		else {
			m->addTerritory(0, 0, a);
		}
	}while (input >> b >> c) {
		m->createConnection(b, c);
	}
	cout << *m << endl;
	vector<vector<Map::Territory*>>* v = m->getTerritoriesVector();
	for (int i = 0; i < v->size(); i++) {
		cout << *v->at(i).at(0) << endl;
	}
	//delete v;

	m->validate();
};


