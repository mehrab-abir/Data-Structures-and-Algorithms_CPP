#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

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
	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(nodes);

	for (int i = 0; i < edges; i++) {
		int u, v;
		//cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(nodes, false);

	int countComp = 0;
	for (int i = 0; i < nodes; i++) {
		if (visited[i] == false) {
			dfs(i, adj_list, visited);
			countComp++;
		}
	}
	
	cout << "Number of components: " << countComp << endl;

	

	return 0;
}
