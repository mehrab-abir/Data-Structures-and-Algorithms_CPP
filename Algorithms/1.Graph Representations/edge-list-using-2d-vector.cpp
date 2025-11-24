#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int vertex, edges;
	cout << "Nunber of vertices: ";
	cin >> vertex;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>edge_list;

	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		vector<int>edge;

		/*
		edge.push_back(u);
		edge.push_back(v);
		edge_list.push_back(edge);
		*/

		//shortcut - more concise, readable...
		edge_list.push_back({ u,v });
	}

	cout << "\nThe edge list: " << endl;
	for (auto edge : edge_list) {
		cout << edge[0] << "," << edge[1] << endl;
	}


	return 0;
}