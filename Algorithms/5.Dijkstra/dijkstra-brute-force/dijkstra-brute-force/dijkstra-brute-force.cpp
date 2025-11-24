#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Complexity of this approach : O(V*E),,V = Number of vertices, E = Number of edges..very bad;

void dijkstra(int src, vector<vector<pair<int, int>>>& adj_list, vector<int>& distance) {
	queue < pair<int, int>>q;
	q.push({ 0, src }); //'0' is the distance for source node ({distance, node})
	distance[src] = 0;

	while (!q.empty()) {
		pair<int, int>current = q.front();
		q.pop();

		int current_node_distance = current.first;
		int current_node = current.second;

		for (pair<int, int> adjacent : adj_list[current_node]) {
			int adjacent_distance = adjacent.first;
			int adjacent_node = adjacent.second;

			if (current_node_distance + adjacent_distance < distance[adjacent_node]) {
				distance[adjacent_node] = current_node_distance + adjacent_distance;
				q.push({ distance[adjacent_node],adjacent_node });
			}
		}
	}
}

int main() {
	int nodes, edges;
	cout << "Number of vertices: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<pair<int, int>>>adj_list(nodes);

	for (int i = 0; i < edges; i++) {
		int u, v, w;
		cout << "Enter vertices and weight: (u,v,w): ";
		cin >> u >> v >> w;

		adj_list[u].push_back({ w,v }); //push({weight, node})..in this serial for priority queue
		adj_list[v].push_back({ w,u });
	}


	vector<int>distance(nodes, INT_MAX);

	dijkstra(0, adj_list, distance); //assuming source 0

	//shortest distance of all nodes from the source node
	//the distance array
	cout << "\n";
	for (int i = 0; i < nodes; i++) {
		cout << "Shortest distance to node " << i << " from 0: " << distance[i] << endl;
	}

	return 0;
}