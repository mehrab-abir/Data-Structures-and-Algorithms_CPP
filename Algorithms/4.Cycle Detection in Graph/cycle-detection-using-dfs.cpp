#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void dfs(int src, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>& parent, bool& detectCycle) {

	visited[src] = true;

	for (int adjacent : adj_list[src]) {

		/*
		the adjacent node is visited and it's not parent of the current(src) node, that means, going back
		to such a node which was previously visited but it's not the parent of the current(src) node
		either.
		Therefor, this only indicates a cycle.
		*/
		if (visited[adjacent] && parent[src] != adjacent) {
			detectCycle = true;
		}

		if (!visited[adjacent]) {
			parent[adjacent] = src;
			dfs(adjacent, adj_list, visited, parent, detectCycle);
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
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(nodes, false);
	vector<int>parent(nodes, -1);

	bool detectCycle = false;

	for (int i = 0; i < nodes; i++) {
		if (visited[i] == false) {
			dfs(i, adj_list, visited, parent, detectCycle);
		}
	}

	if (detectCycle == true) {
		cout << "Cycle detected" << endl;
	}
	else {
		cout << "No cycle detected" << endl;
	}

	return 0;
}
