#include "Graph.h""

int main() {
	Graph g(5);
	g.addEdge(0, 2);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(3, 2);
	g.addEdge(3, 4);
	g.showGraph();
	g.BFS(4);
	g.shortestPath(2, 3);
	g.SocialNetwork();
	g.detectCycle();
	(g.checkBipartite()) ? cout << "The graph is bipartite!!" : cout << "The graph is not bipartite";
	return 0;
}