#pragma once
#include <iostream>;
#include <fstream>;
#include <string>;
#include <vector>;
using namespace std;

struct Node {
	int src, dest;
};
class Graph {
public:
	vector<vector<int>> adjList;
	Graph(vector<Node> const& edges, int N);
	void printGraph(Graph const& graph, int N);

};

struct MapLoader {
public:
	int readFile(string filename);
	int a, b, c, N;
};
