#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/connected-or-not-1-1

int main() {
	int nodes, edges;
	cout << "Number of nodes: ";
	cin >> nodes;
	cout << "Number of edges: ";
	cin >> edges;

	vector<vector<int>>adj_mat(nodes, vector<int>(nodes,0));

	for (int row = 0; row < nodes; row++) {
		for (int col = 0; col < nodes; col++) {
			if (row == col) {
				adj_mat[row][col] = 1;
			}
		}
	}

	cout << "\nEnter nodes (u,v) >>> "<<endl;
	for (int i = 0; i < edges; i++) {
		int a, b;
		cin >> a >> b;

		adj_mat[a][b] = 1;
	}

	int query;
	cout << "Number of queries: ";
	cin >> query;

	for (int q = 0; q < query; q++) {
		int n1, n2;
		cout << "Enter two nodes: ";
		cin >> n1 >> n2;

		if (adj_mat[n1][n2] == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}