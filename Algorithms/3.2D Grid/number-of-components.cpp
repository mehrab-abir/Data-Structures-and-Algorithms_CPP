#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

void dfs(int src, vector<vector<int>>& adj_list, vector<bool>& visited) {
	visited[src] = true;

	for (int adjacent : adj_list[src]) {
		if (!visited[adjacent]) {
			dfs(adjacent, adj_list, visited);
		}
	}
}

int main() {

	int vertices, edges;
	cout << "Number of vertices: ";
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

	vector<bool>visited(vertices, false);

	int compCount = 0;

	for (int i = 0; i < vertices; i++) {
		if (visited[i] == false) {
			dfs(i, adj_list, visited);
			compCount++;
		}
	}

	cout << "\nNumber of components in this graph: " << compCount << endl;

	return 0;
}
/*
* nodes: 12, edges: 8
0 1
2 3
3 4
5 6
6 7
5 7
8 9
9 10
11 --> isolated, will not be in input


nodes 6, edges 3
0 1
2 3
3 4
5 --> isolated, will not be in input

*/