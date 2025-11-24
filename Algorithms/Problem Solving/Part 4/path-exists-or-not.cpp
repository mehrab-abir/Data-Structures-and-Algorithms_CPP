#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://leetcode.com/problems/find-if-path-exists-in-graph/

void bfs(int source, vector<vector<int>>& adj_list, vector<bool>& visited) {
	queue<int>q;
	q.push(source);
	visited[source] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int adjacent : adj_list[current]) {
			if (visited[adjacent] == false) {
				q.push(adjacent);
				visited[adjacent] = true;
			}
		}
	}
}

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

		edge_list.push_back({ u,v });
	}

	cout << "\nThe edge list: "<<endl;
	for (auto edge : edge_list) {
		cout << edge[0] << "," << edge[1] << endl;
	}


	//converting the edge list to a adjacency list
	vector<vector<int>>adj_list(vertex);

	for (auto edge : edge_list) {
		int u = edge[0];
		int v = edge[1];

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(vertex, false);

	int source, destination;
	cout << "Enter source: ";
	cin >> source;
	cout << "Enter destination: ";
	cin >> destination;

	bfs(source, adj_list, visited);

	if (visited[destination] == true) {
		cout << "Path exists" << endl;
	}
	else {
		cout << "No path exists" << endl;
	}

	return 0;
}
