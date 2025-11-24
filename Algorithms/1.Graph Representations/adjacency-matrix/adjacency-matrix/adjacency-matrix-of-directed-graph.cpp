#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "adjacency-matrix-of-directed-graph.h"

using namespace std;

void directed_adj_mat() {

	cout << "  ** Directed Graph **" << endl;
	int adj_mat[10][10];

	int nodes, edges;

	cout << "Number of nodes: ";
	cin >> nodes;

	cout << "Number of edges: ";
	cin >> edges;

	/*for (int row = 0; row < nodes; row++) {
		for (int col = 0; col < nodes; col++) {
			adj_mat[row][col] = 0;
		}
	}*/
	//shortcut
	memset(adj_mat, 0, sizeof(adj_mat));  //memset works for only static array, not vector
	
	for (int row = 0; row < nodes; row++) {
		for (int col = 0; col < nodes; col++) {
			if (row == col) {
				adj_mat[row][col] = 1; //diagonal values are 1- if graph allows self-loop
			}
		}
	}

	cout << endl;
	//input for graph
	for (int i = 0; i < edges; i++) {
		int a, b;
		cout << "Enter nodes (a b): ";
		cin >> a >> b;

		adj_mat[a][b] = 1;
	}

	cout << "\nAdjacency matrix of the directed graph: " << endl;
	for (int row = 0; row < nodes; row++) {
		for (int col = 0; col < nodes; col++) {
			cout << adj_mat[row][col] << " ";
		}
		cout << endl;
	}
}
