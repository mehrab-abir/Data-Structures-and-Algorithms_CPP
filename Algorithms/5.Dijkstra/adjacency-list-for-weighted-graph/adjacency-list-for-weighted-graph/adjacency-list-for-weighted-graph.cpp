#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int nodes, edges;
	cout << "Number of vertices: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<pair<int, int>>>adj_list(nodes);
	//There will be a pair in the inner vector, to store adjacent node and weight

	for (int i = 0; i < edges; i++) {
		int u, v, w;
		cout << "Enter vertices and weight: (u,v,w): ";
		cin >> u >> v >> w;

		adj_list[u].push_back({ v,w });
		adj_list[v].push_back({ u,w });
	}

	//display the adjacency list
	cout << "\nThe adjacentcy list with weight: " << endl;
	for (int i = 0; i < nodes; i++) {
		cout << "Node " << i << " -> " << endl;
		for (pair<int, int> adj_wght : adj_list[i]) {
			cout << "Adjacent node: " << adj_wght.first << ", Weight: " << adj_wght.second << endl;
		}
		cout << endl;
	}

	return 0;
}