#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*
You will be given an undirected graph as input. Then you will be given a node N. You need to tell the number of
nodes that can be visited from node N.
*/

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
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	int node;
	cout << "Enter the node: ";
	cin >> node;

	vector<bool>visited(nodes, false);

	dfs(node, adj_list, visited); 

	int countVisitedNode = 0;
	for (int i = 0; i < nodes; i++) {
		if (visited[i] == true) {
			countVisitedNode++;
		}
	}

	cout << "The number of nodes that can be visited from " << node << ": " << countVisitedNode << endl;

	return 0;
}
