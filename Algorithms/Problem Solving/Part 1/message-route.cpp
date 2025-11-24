#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//https://cses.fi/problemset/task/1667

void bfs(int src, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>&level, vector<int>&parent) {
	queue<int>q;
	q.push(src);
	visited[src] = true;
	level[src] = 0;

	while (!q.empty()) {
		int currentComputer = q.front();
		q.pop();

		for (int computer : adj_list[currentComputer]) {
			if (visited[computer] == false) {
				q.push(computer);
				visited[computer] = true;
				level[computer] = level[currentComputer] + 1;
				parent[computer] = currentComputer;
			}
		}
	}
}

int main() {

	int nComputers, nConnections;
	cout << "Number of computers: ";
	cin >> nComputers;
	cout << "Number of connections: ";
	cin >> nConnections;

	vector<vector<int>>adj_list(nComputers + 1);

	for (int i = 0; i < nConnections; i++) {
		int u, v;
		cout << "Enter connected computers (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	//vector size increased by 1, becasue nodes are 1 based, everything else will be same as usual
	vector<bool>visited(nComputers + 1, false);
	vector<int>level(nComputers + 1, -1);
	vector<int>parent(nComputers + 1, -1);

	//source is 1, the first computer
	bfs(1, adj_list, visited, level,parent);

	int dest = nComputers;

	if (level[dest] == -1) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << "There are minimum " << level[dest] + 1 << " computers in this route" << endl;
		//added 1 to the level[dest], because we have to find the number of nodes(computers) here, not the edges

		int node = dest;
		vector<int>path;

		while (node != -1) {
			path.push_back(node);
			node = parent[node];
		}
		reverse(path.begin(), path.end());

		cout << "\nThe route ";
		for (int computer : path) {
			cout << " -> " << computer;
		}
		cout << endl;
	}


	return 0;
}
