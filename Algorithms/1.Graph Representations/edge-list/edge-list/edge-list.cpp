#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main() {
	cout << " ** Edge List **" << endl;

	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<pair<int, int>>edge_list;

	//input edges
	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter adjacent nodes (u,v): ";
		cin >> u >> v;

		edge_list.push_back({ u,v });
	}

	//printing edge list
	cout << "\nThe edge list: " << endl;
	for (pair<int, int>p : edge_list) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}
