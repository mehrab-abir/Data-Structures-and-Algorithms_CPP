#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int src, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>&parent) {
	queue<int>q;
	q.push(src);
	visited[src] = true;
	//parent[src] = -1; 
	//it's already -1 as all values of parent array are -1, so not necessary to write it again explicitly

	while (!q.empty()) {
		int parentVertex = q.front();
		q.pop();

		for (int adjacent : adj_list[parentVertex]) {
			if (!visited[adjacent]) {
				q.push(adjacent);
				visited[adjacent] = true;
				parent[adjacent] = parentVertex;
				//prottek vertex er adjacent vertex a oi parent vertex rekhe dewa
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
	vector<int>parent(vertices, -1);

	int src, dest;
	cout << "Enter src vertex: ";
	cin >> src;
	cout << "Enter destination vertex: ";
	cin >> dest;

	if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
		cout << "Invalid source or destination vertex!" << endl;
		return 1;
	}

	bfs(src, adj_list, visited, parent);


	int node = dest;
	vector<int>path;
	
	while (node != -1) {
		path.push_back(node);
		node = parent[node];
	}

	if (path.back() != src) {
		cout << "\nNo path found from " << src << " to " << dest << "." << endl;
	}
	else {
		reverse(path.begin(), path.end());

		cout << "\nShortest path ";
		for (int point : path) {
			cout << "-> "<<point << " ";
		}
		cout << endl;
	}

	return 0;
}