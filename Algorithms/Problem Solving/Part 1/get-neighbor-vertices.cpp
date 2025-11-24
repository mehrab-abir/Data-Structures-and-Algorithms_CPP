#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int vertices, edges;
	cout << "Number of verices: ";
	cin >> vertices;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(vertices);

	for (int i = 0; i < edges; i++) {
		int u, v;
		//cout << "Enter vertices (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	int node;
	cout << "Enter the node: ";
	cin >> node;

	cout << "Number of nodes that are neighbor of " << node << " is: " << adj_list[node].size() << endl;

	return 0;
}