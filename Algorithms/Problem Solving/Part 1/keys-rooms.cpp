#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://leetcode.com/problems/keys-and-rooms/description/

void bfs(int src, vector<vector<int>>&adj_list, vector<bool>& visited) {
	queue<int>q;
	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		int currentRoom = q.front();
		q.pop();

		for (int room : adj_list[currentRoom]) {
			if (visited[room] == false) {
				q.push(room);
				visited[room] = true;
			}
		}
	}
}

int main() {

	int vertices, edges;
	cout << "Number of rooms(vertices): ";
	cin >> vertices;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(vertices);

	for (int i = 0; i < edges; i++) {
		int u, v;
		//cout << "Enter vertices (u,v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vector<bool>visited(vertices,false);

	//source node/staring room = 0;
	bfs(0, adj_list, visited);

	bool allRooms = true;

	for (bool room : visited) {
		if (room == false) {
			allRooms = false;
			break;
		}
	}

	if (allRooms) {
		cout << "All rooms are visited" << endl;
	}
	else {
		cout << "Not possible to visit all rooms" << endl;
	}

	return 0;
}

/*
0 1
0 2
1 2
0 3
3 4
1 4
1 5
*/