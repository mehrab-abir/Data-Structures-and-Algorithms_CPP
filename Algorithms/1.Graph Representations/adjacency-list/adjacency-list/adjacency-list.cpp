#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include "adjacency-list.h"

using namespace std;

//Adjacency list for undirected graph
void undirected_adj_list() {
	cout << " **Undirected Graph **" << endl;

	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(nodes);

	//input
	//traverse every edge and take input of its two adjacent nodes/neighbors
	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter adjacent nodes (u v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);  //for undirected graph
	}


	//printing adjacency list -- visit each node and print its neighbors/adjacent nodes
	cout << "\nAdjacency list of this undirected graph: " << endl;
	for (int i = 0; i < nodes; i++) {

		cout << "Node " << i << " ->";
		for (int adjacent : adj_list[i]) {
			cout << adjacent << " ";
		}
		cout << endl;
	}
	cout << endl;
}





//Adjacency list for directed graph
void directed_adj_list() {
	cout << " **Directed Graph **" << endl;

	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_list(nodes);

	//input
	//traverse every edge and take input of its two adjacent nodes/neighbors
	for (int i = 0; i < edges; i++) {
		int u, v;
		cout << "Enter adjacent nodes (u v): ";
		cin >> u >> v;

		adj_list[u].push_back(v);
	}


	//printing adjacency list -- visit each node and print its neighbors/adjacent nodes
	cout << "\nAdjacency list of this directed graph: " << endl;
	for (int i = 0; i < nodes; i++) {

		cout << "Node " << i << " ->";
		for (int adjacent : adj_list[i]) {
			cout << adjacent << " ";
		}
		cout << endl;
	}
	cout << endl;
}