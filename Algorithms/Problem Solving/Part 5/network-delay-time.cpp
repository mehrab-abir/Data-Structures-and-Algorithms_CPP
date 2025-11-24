#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://leetcode.com/problems/network-delay-time/description/

void dijkstra(int src, vector<vector<pair<int, int>>>& adj_list, vector<int>&delayTime) {
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,src });
	delayTime[src] = 0;

	while (!pq.empty()) {
		pair<int, int>current = pq.top();
		pq.pop();

		int current_node_distance = current.first;
		int current_node = current.second;

		for (auto adjacent : adj_list[current_node]) {
			int adjacent_node = adjacent.first;
			int adjacent_node_distance = adjacent.second;

			if (current_node_distance + adjacent_node_distance < delayTime[adjacent_node]) {
				delayTime[adjacent_node] = current_node_distance + adjacent_node_distance;
				pq.push({ delayTime[adjacent_node],adjacent_node });
			}
		}
	}
}

int main() {
	int nodes, edges;
	cout << "Number of nodes and edges: ";
	cin >> nodes >> edges;

	vector<vector<int>>edge_list;

	for (int i = 0; i < edges; i++) {
		int u, v, t;
		cout << "Enter nodes and time (u,v,t): ";
		cin >> u >> v >> t;

		edge_list.push_back({ u,v,t });
	}

	//converting edge list to an adjacency list
	vector<vector<pair<int,int>>>adj_list(nodes+1); //nodes starts from 1

	for (auto edge : edge_list) {
		int u = edge[0];
		int v = edge[1];
		int t = edge[2];

		adj_list[u].push_back({ v,t });   //it's a directed graph
	}

	vector<int>delayTime(nodes + 1, INT_MAX);

	int src;
	cout << "Enter source node: ";
	cin >> src;

	dijkstra(src, adj_list,delayTime);

	int maxDelay = 0;

	for (int i = 1; i <= nodes; i++) {
		if (delayTime[i] == INT_MAX) {
			cout << "Some ndoes are unreachable" << endl;
			break;
		}

		maxDelay = max(maxDelay, delayTime[i]);
	}

	cout << "Minimum time needed for all nodes to receive the signal is " << maxDelay << endl;

	return 0;
}
