#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//Complexity - O(V^3) -- V = Vertices

void floyd_warshall(vector<vector<int>>&adj_mat,int nodes) {
	//i = intermediate node
	//s = src node
	//d = destination node
	for (int i = 0; i < nodes; i++) {
		for (int s = 0; s < nodes; s++) {
			for (int d = 0; d < nodes; d++) {
				if (adj_mat[s][i] != INT_MAX && adj_mat[i][d] != INT_MAX && (adj_mat[s][i] + adj_mat[i][d] < adj_mat[s][d])) {
					adj_mat[s][d] = adj_mat[s][i] + adj_mat[i][d];
				}
			}
		}
	}


	cout << "\nShortest distance from each node to all other nodes: " << endl;
	for (int row = 0; row < nodes; row++) {
		for (int col = 0; col < nodes; col++) {
			if (adj_mat[row][col] == INT_MAX) {
				cout << "#" << " ";  //# for INT_MAX______Infinite
			}
			else {
				cout << adj_mat[row][col] << " ";
			}
		}
		cout << endl;
	}
	
	
}

int main() {
	int nodes, edges;

	cout << "Number of nodes and edges: ";
	cin >> nodes >> edges;

	vector<vector<int>>adj_mat(nodes, vector<int>(nodes, INT_MAX));

	for (int row = 0; row < nodes; row++) {
		for (int col = 0; col < nodes; col++) {
			if (row == col) {
				adj_mat[row][col] = 0; //distance from each to the same node is 0
			}
		}
	}

	for (int i = 0; i < edges; i++) {
		int u, v, w;
		//cout << "Enter nodes and weight(u,v,w): ";
		cin >> u >> v >> w;

		adj_mat[u][v] = w;
		//adj_mat[v][u] = w; //for undirected graph
	}

	floyd_warshall(adj_mat,nodes);

	return 0;
}

/*
nodes 4, edges 5
0 1 3
0 2 6
1 2 2
1 3 5
2 3 4

*/
