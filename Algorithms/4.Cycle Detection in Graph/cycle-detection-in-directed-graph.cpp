#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int src, vector<vector<int>>&adj_list, vector<bool>&visited, vector<bool>&samePath, bool &cycle) {
	visited[src] = true;
	samePath[src] = true;

	for (int adjacent : adj_list[src]) {
		if (visited[adjacent] && samePath[adjacent]) {
			cycle = true;
		}

		if (!visited[adjacent]) {
			dfs(adjacent, adj_list, visited, samePath,cycle);
		}
	}

	//if the path ends/forward tracking ends, then backtracking starts here
	samePath[src] = false;
	/*
	all nodes of samePath becomes false again due to backtracking, but the 'cycle = true' remains
	after the fuction totally exits as it gets updated at some point because of cycle/or false if there
	was no cycle.
	*/ 
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
	}

	vector<bool>visited(nodes, false);
	vector<bool>samePath(nodes, false);

	bool cycle = false;

	for (int i = 0; i < nodes; i++) {
		if (!visited[i]) {
			dfs(i, adj_list, visited, samePath, cycle);
		}
	}

	if (cycle) {
		cout << "Cycle detected" << endl;
	}
	else {
		cout << "No cycle detected" << endl;
	}

	return 0;
}
