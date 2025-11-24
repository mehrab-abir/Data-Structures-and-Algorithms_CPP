#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Complexity : O(V+E)logV 

// O(V) for the while loop - as it executes V times, number of vertices
// O(E) for the inner for loop

//for using priority queue
//in the while loop ->> 1 time pop() -> O(logV), V times pop() => O(V) * O(logV) = O(VlogV) 
//inside inner for loop ->> 1 time push() -> O(logV), E times push() => O(E) * O(logV) = O(ElogV) 

//Total time complexity : O(VlogV + ElogV) => O(V+E)logV

void dijkstra(int src, vector<vector<pair<int, int>>>&adj_list, vector<int>&distance) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,src }); //distance of the source node is 0
	distance[src] = 0;

	//O(V)
	while (!pq.empty()) {
		pair<int, int>current = pq.top();
		pq.pop();  //O(logV)

		int current_node_distance = current.first;
		int current_node = current.second;

		//O(E)
		for (pair<int, int> adjacent : adj_list[current_node]) {
			int adjacent_node = adjacent.first;
			int adjacent_distance = adjacent.second;

			if (current_node_distance + adjacent_distance < distance[adjacent_node]) {
				distance[adjacent_node] = current_node_distance + adjacent_distance;
				pq.push({ distance[adjacent_node], adjacent_node });  //O(logV)
			}
		}
	}
}

int main() {
	int vertices, edges;
	cout << "Number of vertices and edges: ";
	cin >> vertices >> edges;

	vector<vector<pair<int, int>>>adj_list(vertices);

	for (int i = 0; i < edges; i++) {
		int u, v, w;
		//cout << "Enter vertices and weight (u,v,w): ";
		cin >> u >> v >> w;

		adj_list[u].push_back({ v,w }); //({node, weight})
		adj_list[v].push_back({ u,w });
	}

	vector<int>distance(vertices, INT_MAX);

	dijkstra(0, adj_list, distance); //source 0

	cout << "\n";
	for (int i = 0; i < vertices; i++) {
		cout << "Shortest distance from 0 to node " << i << ": "<<distance[i] << endl;
	}

	return 0;
}

/*
nodes 7, edges 11
0 1 5
0 2 2
1 3 9
1 4 6
2 4 1
2 5 7
3 4 2
4 5 8
3 6 5
6 0 3
6 1 2
*/
