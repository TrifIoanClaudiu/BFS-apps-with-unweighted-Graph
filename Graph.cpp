#include "Graph.h"

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::showGraph()
{
	for (int v = 0; v < V; v++) {
		cout << v << ":";
		for (auto x : adj[v])
			cout << x << " ";
		cout << endl;
	}
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);//Add w to v's list;
	adj[w].push_back(v);
}

void Graph::BFS(int s) {
	//Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	//Create a queue for BFS
	list <int> queue;

	//Mark the currend node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	//'i' will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty()) {
		//Dequeue a vertex from a queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		//Get all adjacent vertices of the dequed vertex s. If a adjacent has not been visited, then
		//mark it visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	cout << endl;
}
void Graph::shortestPath(int v, int w)
{
	if (v == w) {
		cout << "It is the same vertex!!";
		return;
	}
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	list <int> queue;

	vector<int> path;

	list<int>::iterator i;

	int s = v;

	visited[s] = true;
	queue.push_back(s);
	while ((!queue.empty())) {
		s = queue.front();
		path.push_back(s);
		queue.pop_front();
		if (visited[w] == true) {
			for (int i : path) {
				cout << i << " ";
			}
			if (!count(path.begin(), path.end(), w))
				cout << w << endl;
			return;
		}
		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);

			}
		}
	}
	cout << "There is no path between " << v << " and " << w << "!!!";
}

void Graph::SocialNetwork()
{
	for (int p = 0; p < V; p++) {
		int table[100] = { 0 };
		bool* visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;
		list <int> queue;

		list<int>::iterator i;

		int s = p;

		visited[s] = true;
		queue.push_back(s);

		while ((!queue.empty())) {
			s = queue.front();
			queue.pop_front();
			for (i = adj[s].begin(); i != adj[s].end(); ++i) {
				if (!visited[*i]) {
					visited[*i] = true;
					queue.push_back(*i);
					table[*i] = table[s] + 1;
				}
			}
		}
		cout << p << " Have at least one common friend with:";
		for (int i = 0; i < V; i++)
			if ((table[i] == 2)) {
				cout << i << " ";
			}
		cout << endl;
	}
}

void Graph::detectCycle()
{
	for (int s = 0; s < V; s++) {
		bool* visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;
		list <int> queue;

		list<int>::iterator i;

		int p = s;
		visited[s] = true;
		bool isCycle = false;
		queue.push_back(s);
		int parent[100] = { 0 };

		while ((!queue.empty())) {
			s = queue.front();
			queue.pop_front();
			for (i = adj[s].begin(); i != adj[s].end(); i++) {
				if (!visited[*i]) {
					visited[*i] = true;
					queue.push_back(*i);
					parent[*i] = s;
				}
				else if ((parent[*i] != s) && (*i != p)) {
					isCycle = true;
					cout << "There is a cycle in the graph" << endl;
					return;
				}
			}

		}
	}
	cout << "The is no cycle in the graph" << endl;
}

bool Graph::checkBipartite()
{
	int s = 0;
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list <int> queue;

	list<int>::iterator i;

	int parent[100] = { -1 };
	char colour[100] = { 'n' };//n from none
	parent[s] = s;
	colour[s] = 'g';//from green
	queue.push_back(s);
	while (!queue.empty()) {
		s = queue.front();
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
				parent[*i] = s;
				if (colour[parent[*i]] == 'g')
					colour[*i] = 'b';//from blue
				else
					colour[*i] = 'g';
			}
			else if ((colour[*i] == colour[parent[*i]]) || (colour[*i]==colour[s]))
				return false;
		}
	}
	return true;
}

