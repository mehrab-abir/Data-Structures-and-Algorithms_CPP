#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void bfs(int src, vector<vector<int>>&adj_list, vector<bool>&visited, vector<int>&level) {
	queue<int>q;
	q.push(src);
	visited[src] = true;
	level[src] = 0;

	while (!q.empty()) {
		int parentNode = q.front();
		q.pop();

		for (int adjacent : adj_list[parentNode]) {
			if (visited[adjacent] == false) {
				q.push(adjacent);
				visited[adjacent] = true;
				level[adjacent] = level[parentNode] + 1;
			}
		}
	}
}

void get_all_nodes(int targetLevel, vector<int>& level, int nodes) {

	vector<int>levelNodes;

	for (int i = 0; i < nodes; i++) {
		if (level[i] == targetLevel) {
			levelNodes.push_back(i);
		}
	}

	sort(levelNodes.begin(), levelNodes.end(), greater<int>());

	for (int node : levelNodes) {
		cout << node << " ";
	}
	cout << endl;
}

int main() {

	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(nodes);

	for (int i = 0; i < edges; i++) {
		int u , v;
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(nodes, false);
	vector<int>level(nodes, -1);

	int src;
	cout << "Enter source node: ";
	cin >> src;

	bfs(src, adj_list, visited, level);

	int targetLevel;
	cout << "Enter traget level: ";
	cin >> targetLevel;

	get_all_nodes(targetLevel, level, nodes);

	return 0;
}
/*
* nodes 10 , edges 13
0 1
0 2
1 2
0 3
4 2
3 5
4 3
5 6
5 7
4 6
4 8
2 9
1 4

*/