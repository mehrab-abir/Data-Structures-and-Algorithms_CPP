#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>

using namespace std;

//https://cses.fi/problemset/task/1672/

int main() {
	long long int nodes, edges, q;
	//cout << "Number of nodes, edges and queries: ";
	cin >> nodes >> edges >> q;

	vector<vector<long long int>>adj_mat(nodes+1, vector<long long int>(nodes+1, LLONG_MAX));

	for (int row = 1; row <= nodes; row++) {
		for (int col = 1; col <= nodes; col++) {
			if (row == col) {
				adj_mat[row][col] = 0;
			}
		}
	}

	for (int i = 1; i <= edges; i++) {
		long long int u, v, w;
		//cout << "Enter nodes and weight (u,v,w): ";
		cin >> u >> v >> w;

		adj_mat[u][v] = min(adj_mat[u][v],w);
		adj_mat[v][u] = min(adj_mat[v][u],w);
	}

	for (int m = 1; m <= nodes; m++) {
		for (int s = 1; s <= nodes; s++) {
			for (int d = 1; d <= nodes; d++) {
				if (adj_mat[s][m] != LLONG_MAX && adj_mat[m][d] != LLONG_MAX && (adj_mat[s][m] + adj_mat[m][d] < adj_mat[s][d])) {
					adj_mat[s][d] = adj_mat[s][m] + adj_mat[m][d];
				}
			}
		}
	}

	for (int i = 0; i < q; i++) {
		long long int a, b;
		//cout << "Enter source and destination nodes: ";
		cin >> a >> b;

		if (adj_mat[a][b] == LLONG_MAX) {
			cout << "-1" << endl;
		}
		else {
			cout << adj_mat[a][b] << endl;
		}
	}

	return 0;
}

/*
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
*/