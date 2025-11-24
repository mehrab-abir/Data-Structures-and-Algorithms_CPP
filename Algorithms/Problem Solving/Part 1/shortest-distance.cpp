#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int src, vector < vector<int>>& adj_list, vector<bool>& visited, vector<int>& level, vector<int>&parent) {
	queue<int>q;
	q.push(src);
	visited[src] = true;
	level[src] = 0;

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();

		for (int adjacent : adj_list[currentNode]) {
			if (visited[adjacent] == false) {
				q.push(adjacent);
				visited[adjacent] = true;
				level[adjacent] = level[currentNode] + 1;
				parent[adjacent] = currentNode;
			}
		}
	}
}

int main() {

	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector < vector<int>>adj_list(nodes);

	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(nodes, false);
	vector<int>level(nodes, -1);
	vector<int>parent(nodes, -1);

	int query;
	cout << "Number of queries: ";
	cin >> query;

	for (int i = 0; i < query; i++) {
		cout << endl;

		int src, dest;
		cout << "Enter source and destination: ";
		cin >> src >> dest;

		bfs(src, adj_list, visited, level, parent);

		if (level[dest] == -1) {
			cout << "No path found" << endl;
		}
		else {
			cout << "Shortest distance from " << src << " to " << dest << ": " << level[dest] << endl;

			int node = dest;
			vector<int>path;

			while (node != -1) {
				path.push_back(node);
				node = parent[node];
			}

			reverse(path.begin(), path.end());

			cout << "\nShortest path ";
			for (int point : path) {
				cout << "-> " << point;
			}
			cout << endl;
		}

		visited.assign(nodes, false);
		level.assign(nodes, -1);
		parent.assign(nodes, -1);
	}


	return 0;
}
/*
0 1
0 2
3 4
3 5
4 5

*/