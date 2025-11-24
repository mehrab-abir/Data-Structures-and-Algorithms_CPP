#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void bfs(int src, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>&compNodes) {
	queue<int>q;
	q.push(src);
	visited[src] = true;

	int count = 0;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		count++;

		for (int adjacent : adj_list[current]) {
			if (!visited[adjacent]) {
				q.push(adjacent);
				visited[adjacent] = true;
			}
		}
		
	}
	compNodes.push_back(count);
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
		//cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(nodes, false);
	vector<int>compNodes;

	int countComp = 0;
	for (int i = 0; i < nodes; i++) {
		if (visited[i] == false) {
			bfs(i, adj_list, visited,compNodes);
			countComp++;
		}
	}

	sort(compNodes.begin(), compNodes.end());

	cout << "\nNumber of nodes in each component in ascending order: ";
	for (int n : compNodes) {
		cout << n << " ";
	}

	cout << endl;

	return 0;
}
