#pragma once
#include <iostream>;
#include <fstream>;
#include <string>;
#include <vector>;
#include <array>;
#include <utility>;
#include "Maploader.h";
using namespace std;

//struct Node {
//	int id;
//};
Graph::Graph(vector<Node> const& edges, int N)
{
	adjList.resize(N);
	for (auto& edge : edges)
	{
		adjList[edge.dest].push_back(edge.src);
	}
};
void Graph::printGraph(Graph const& graph, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << i << "-->";
		for (int v : graph.adjList[i]) {
			cout << v << " ";
		}
		cout << endl;
	}
};
int MapLoader::readFile(string filename) {
	std::fstream myfile(filename, std::ios_base::in);
	//int a;

	myfile >> a;
	N = a;
	int x = 0;
	int graph[10];
	int pairs[2];

	cout << "N = " << a << " ";
	//int i;
	while (myfile >> b >> c)
	{
		pairs[0] = c;
		pairs[1] = b;
		for (int i = 1; i >= 0; i--) {
			cout << pairs[i] << ",";
		}
		cout << " ";
	}


	return 0;

};
