#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int src, vector<vector<int>>&adj_list, vector<bool>& visited, vector<int>& level) {
	queue<int>q;
	q.push(src);
	visited[src] = true;
	level[src] = 0; //level of src node/vertex is 0

	while (!q.empty()) {
		int currentVertex = q.front();
		q.pop();

		for (int adjacent : adj_list[currentVertex]) {
			if (!visited[adjacent]) {
				q.push(adjacent);
				visited[adjacent] = true;
				level[adjacent] = level[currentVertex] + 1;
			}
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
		cout << "Enter vertices (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(vertices, false);
	vector<int>level(vertices, -1);

	int src, dest;
	cout << "Enter src vertex: ";
	cin >> src;
	cout << "Enter destination vertex: ";
	cin >> dest;

	if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
		cout << "Invalid source or destination vertex!" << endl;
		return 1;
	}

	bfs(src, adj_list, visited, level);

	//to find the shortest distance from source node to destination node, check the level of destination node
	int shortest_distance = level[dest];

	if (shortest_distance == -1) {
		cout << "\nNo path found from " << src << " to " << dest << "." << endl;
	}
	else {
		cout << "\nShortest distance from " << src << " to " << dest << ": " << shortest_distance << endl;
	}

	return 0;
}