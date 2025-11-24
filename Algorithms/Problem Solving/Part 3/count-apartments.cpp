#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/count-apartments

int nRows, nCols;

vector<pair<int, int>>d = { {-1,0},{1,0},{0,-1},{0,1} };

bool valid(int adj_row, int adj_col) {
	if (adj_row < 0 || adj_row >= nRows || adj_col < 0 || adj_col >= nCols) {
		return false;
	}
	else {
		return true;
	}
}

void bfs(int sRow, int sCol, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
	queue < pair<int, int>>q;
	q.push({ sRow,sCol });
	visited[sRow][sCol] = true;

	while (!q.empty()) {
		pair<int, int>currentNode = q.front();
		q.pop();

		int current_row = currentNode.first;
		int current_col = currentNode.second;


		for (int i = 0; i < 4; i++) {
			int adj_row = current_row + d[i].first;
			int adj_col = current_col + d[i].second;

			if (valid(adj_row, adj_col) && !visited[adj_row][adj_col] && grid[adj_row][adj_col] == '.') {

				q.push({ adj_row,adj_col });
				visited[adj_row][adj_col] = true;
			}
		}
	}
}

int main() {
	cout << "Number of rows: ";
	cin >> nRows;
	cout << "Number of columns: ";
	cin >> nCols;

	vector<vector<char>>grid(nRows, vector<char>(nCols));

	//input
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			char c;
			cout << "Enter grid[" << row << "][" << col << "]: ";
			cin >> c;

			grid[row][col] = c;
		}
	}

	//display the grid
	cout << "\nThe grid:" << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));
	
	int countApartment = 0;

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			if (visited[i][j] == false && grid[i][j] == '.') {
				bfs(i, j, grid, visited);
				countApartment++;
			}
		}
	}

	cout << "\nNumber of apartments: " << countApartment << endl;

	return 0;
}
/*

* . . *
* * * *
* . * *


*/