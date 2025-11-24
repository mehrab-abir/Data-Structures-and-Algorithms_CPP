#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/can-go-1

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

void bfs(int sRow, int sCol, vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& distance) {
	queue < pair<int, int>>q;
	q.push({ sRow,sCol });
	visited[sRow][sCol] = true;
	distance[sRow][sCol] = 0;

	while (!q.empty()) {
		pair<int, int>currentNode = q.front();
		q.pop();

		int current_row = currentNode.first;
		int current_col = currentNode.second;


		for (int i = 0; i < 4; i++) {
			int adj_row = current_row + d[i].first;
			int adj_col = current_col + d[i].second;

			if ((valid(adj_row, adj_col) && !visited[adj_row][adj_col]) && (grid[adj_row][adj_col] == '.' || grid[adj_row][adj_col] == 'B')) {

				q.push({ adj_row,adj_col });
				visited[adj_row][adj_col] = true;
				distance[adj_row][adj_col] = distance[current_row][current_col] + 1;
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
	vector<vector<int>>distance(nRows, vector<int>(nCols, -1));

	int srcRow, srcCol, destRow, destCol;
	
	bool foundA = false, foundB = false;

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (grid[row][col] == 'A') {
				srcRow = row;
				srcCol = col;
				foundA = true;
			}
			if (grid[row][col] == 'B') {
				destRow = row;
				destCol = col;
				foundB = true;
			}
		}
	}

	if (!foundA || !foundB) {
		cout << "Error: Source or destination not found in the grid." << endl;
	}
	else {
		bfs(srcRow, srcCol, grid, visited, distance);

		/*int shortDist = distance[destRow][destCol];

		cout << "Shortest distance: " << shortDist << endl;*/

		if (visited[destRow][destCol]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	
	return 0;
}
/*

* . . *
* . A *
* B * * 


*/