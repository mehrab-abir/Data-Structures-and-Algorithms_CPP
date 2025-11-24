#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dijkstra(int src, vector<vector<pair<int, int>>>& adj_list, vector<int>& distance) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	distance[src] = 0;
	pq.push({ 0,src });

	while (!pq.empty()) {
		pair<int, int>current = pq.top();
		pq.pop();

		int current_node_distance = current.first;
		int current_node = current.second;

		for (pair<int, int>adjacent : adj_list[current_node]) {
			int adjacent_node = adjacent.first;
			int adjacent_node_distance = adjacent.second;

			if (current_node_distance + adjacent_node_distance < distance[adjacent_node]) {
				distance[adjacent_node] = current_node_distance + adjacent_node_distance;
				pq.push({ distance[adjacent_node], adjacent_node });
			}
		}
	}
}

int main() {
	int nodes, edges;
	cout << "Number of nodes and edges: ";
	cin >> nodes >> edges;

	vector<vector<pair<int, int>>>adj_list(nodes);

	for (int i = 0; i < edges; i++) {
		int u, v, w;
		//cout << "Enter nodes and weight (u,v,w): ";
		cin >> u >> v >> w;

		adj_list[u].push_back({ v,w });
		adj_list[v].push_back({ u,w });
	}

	vector<int>distance(nodes, INT_MAX);

	int src;
	cout << "Enter source node: ";
	cin >> src;

	dijkstra(src, adj_list, distance);

	for (int i = 0; i < nodes; i++) {
		cout << "Shortest distance from " << src << " to node " << i << ": " << distance[i] << endl;
	}

	return 0;
}
/*
nodes 5, edges 8
0 1 5
1 2 3
2 0 4
0 4 2
0 3 7
3 1 1
4 2 6
3 4 2
*/