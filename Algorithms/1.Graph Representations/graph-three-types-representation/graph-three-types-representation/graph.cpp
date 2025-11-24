#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include "graph.h"
using namespace std;

//adjacency matrix -undirected
void adjacency_matrix() {
	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_mat(nodes, vector<int>(nodes,0)); //initializing all value with 0

	//diagonal values are 1- if graph allows self loop
	for (int row = 0; row < nodes; row++) {
		for (int col = 0; col < nodes; col++) {
			if (row == col) {
				adj_mat[row][col] = 1;
			}
		}
	}

	//input
	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_mat[u-1][v-1] = 1;  //'-1' to maintain 0-based index, as nodes are 1 based
		adj_mat[v-1][u-1] = 1; //for undirected graph
	}

	//adjancency matrix representation
	cout << "\nAdjacency matrix representaion of this graph:" << endl;

	cout << "   ";
	for (int i = 0; i < nodes; i++) cout << i + 1 << " ";  //formatting output
	cout << "\n   -------------\n";
	
	for (int i = 0; i < nodes; i++) {

		cout << i + 1 << "| ";
		for (int j = 0; j < nodes; j++) {
			cout << adj_mat[i][j] << " ";
		}
		cout << endl;
	}
}


//adjacency_list
void adjacency_list() {
	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(nodes);

	//input
	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		adj_list[u-1].push_back(v); //'-1' to maintain 0 based index as nodes are 1 based
		adj_list[v-1].push_back(u); //for undirected graph
	}

	//adjacency list representation
	cout << "\nAdjacency list representation of this graph:" << endl;
	for (int i = 0; i < nodes; i++) {
		cout << "Node " << i + 1 << " -> "; //'+1'.. as nodes are 1 based
		for (int adjacent : adj_list[i]) {
			cout << adjacent << " ";
		}
		cout << endl;
	}
}

//edge list
void edge_list() {
	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<pair<int, int>>edge_list;
	//input
	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter nodes (u,v): ";
		cin >> u >> v;

		edge_list.push_back({ u,v });
	}

	//edge list
	cout << "\nEdge list of this graph: " << endl;
	for (auto nodes : edge_list) {
		cout << nodes.first << ", " << nodes.second<<endl;
	}
}
