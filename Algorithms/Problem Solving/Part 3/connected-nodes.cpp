#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/connected-nodes-1

int main() {
	int nodes, edges;
	cout << "Number of nodes and edges: ";
	cin >> nodes >> edges;

	vector<vector<int>>adj_list(nodes);

	cout << "\nEnter nodes (u,v) >>>>" << endl;
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	int query;
	cout << "Number of queries: ";
	cin >> query;

	for (int q = 0; q < query; q++) {
		int node;
		cout << "Enter the node: ";
		cin >> node;

		vector<int>adjacents;
		
		if (adj_list[node].size() > 0) {
			for (int adjacent : adj_list[node]) {
				adjacents.push_back(adjacent);
			}
		}

		sort(adjacents.begin(), adjacents.end(), greater<int>());

		if (adjacents.size() > 0) {
			for (int x : adjacents) {
				cout << x << " ";
			}
		}
		else {
			cout << "-1";
		}
		
		cout << endl;
	}
	

	return 0;
}

