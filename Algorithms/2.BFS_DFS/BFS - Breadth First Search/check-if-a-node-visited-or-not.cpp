#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int src, vector<vector<int>>adj_list, vector<bool>&visited) {
	queue<int>q;
	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		int currentVertex = q.front();
		q.pop();

		for (int adjacent : adj_list[currentVertex]) {
			if (visited[adjacent] == false) {
				q.push(adjacent);
				visited[adjacent] = true;
			}
		}
	}
}

int main() {

	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(nodes);

	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter vertices (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(nodes, false);

	int src, dest;
	cout << "Enter source/starting vertex: ";
	cin >> src;
	cout << "Enter destination vertex: ";
	cin >> dest;

	bfs(src, adj_list, visited);

	if (visited[dest] == true) {
		cout << "The vertex/node "<<dest<<" has been visited... or visiting from "<<src<<"to "<<dest<<" is possible" << endl;
	}
	else {
		cout << "The vertex/node " << dest << " has not been visited... or visiting from " << src << "to " << dest << " is not possible" << endl;
	}

	return 0;
}