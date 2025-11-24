#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/maze-19

int nRows, nCols;

vector<pair<int, int>>moves = {{0,1}, {0,-1},{-1,0},{1,0}}; // right, left, up, down,

bool valid(int adjacent_row, int adjacent_col) {
	if (adjacent_row < 0 || adjacent_row >= nRows || adjacent_col < 0 || adjacent_col >= nCols) {
		return false;
	}
	else {
		return true;
	}
}

void bfs(int sRow, int sCol, vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<pair<int, int>>>&parent) {

	queue<pair<int, int>>q;
	q.push({ sRow, sCol });
	visited[sRow][sCol] = true;

	while (!q.empty()) {
		pair<int, int>current = q.front();
		q.pop();

		int current_row = current.first;
		int current_col = current.second;

		for (int i = 0; i < 4; i++) {
			int adjacent_row = current_row + moves[i].first;
			int adjacent_col = current_col + moves[i].second;

			if ((valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col]) && (grid[adjacent_row][adjacent_col] == '.' || grid[adjacent_row][adjacent_col] == 'R' || grid[adjacent_row][adjacent_col] == 'D')) {

				q.push({ adjacent_row,adjacent_col });
				visited[adjacent_row][adjacent_col] = true;
				parent[adjacent_row][adjacent_col] = { current_row, current_col };
			}
		}
	}
}

int main() {
	cout << "Number of rows and columns: ";
	cin >> nRows >> nCols;

	vector<vector<char>>grid(nRows, vector<char>(nCols));

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			//cout << "Enter grid[" << row << "][" << col << "]: ";
			cin >> grid[row][col];
		}
	}

	int srcRow, srcCol, destRow, destCol;

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (grid[row][col] == 'R') {
				srcRow = row;
				srcCol = col;
			}

			if (grid[row][col] == 'D') {
				destRow = row;
				destCol = col;
			}
		}
	}

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));	
	vector<vector<pair<int, int>>>parent(nRows, vector<pair<int, int>>(nCols, { -1,-1 }));

	bfs(srcRow, srcCol, grid, visited, parent);

	if (parent[destRow][destCol].first == -1) {
		cout << "\nThere is no shortest path from R to D: " << endl;
		for (int row = 0; row < nRows; row++) {
			for (int col = 0; col < nCols; col++) {
				cout << grid[row][col] << " ";
			}
			cout << endl;
		}
	}
	else {
		while (grid[destRow][destCol] != 'R') {
			pair<int, int>par = parent[destRow][destCol];

			destRow = par.first;
			destCol = par.second;

			if (grid[destRow][destCol] == 'R') {
				break;
			}
			grid[destRow][destCol] = 'X';
		}

		//final grid with shortest path 
		cout << "\nShortest path from R to D: " << endl;
		for (int row = 0; row < nRows; row++) {
			for (int col = 0; col < nCols; col++) {
				cout << grid[row][col] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}

/*
row 5, col 5
* * R . . 
* . . . . 
* * . . * 
. . . . . 
* D . . .

*/