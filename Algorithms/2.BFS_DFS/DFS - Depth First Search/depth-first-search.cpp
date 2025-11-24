#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

void dfs(int src, vector<vector<int>>& adj_list, vector<bool>& visited) {
	cout << src << " ";
	visited[src] = true;

	for (int node : adj_list[src]) {
		if (visited[node] == false) {
			dfs(node,adj_list,visited);
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

	cout << "\nDepth First Search traversla of this graph: ";
	dfs(0, adj_list, visited); //assuming source node 0

	cout << endl;

	return 0;
}