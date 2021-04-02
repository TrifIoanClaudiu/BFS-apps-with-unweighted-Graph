#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Graph {
	int V; //no of vertices

	list<int>* adj; //pointer to an array containing adjancy list

public:
	Graph(int V);//constructor

	void showGraph();

	int getVertices() { return this->V; }

	//function to add an edge to graph
	void addEdge(int v, int w);

	//print BFS traversal from a given source s
	void BFS(int s);

	//print the shortest path from two vertexes using the bf search
	void shortestPath(int v, int w);

	//add friend relationship between those that have a common friend
	void SocialNetwork();

	//checks if there is a cycle in the graph
	void detectCycle();

	//check if a graph is bipartite or not
	bool checkBipartite();
};