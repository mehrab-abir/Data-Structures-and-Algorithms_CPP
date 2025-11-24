#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//https://leetcode.com/problems/number-of-islands/description/

int nRows, nCols;

vector<pair<int, int>>d = { {-1,0},{1,0},{0,-1},{0,1} };

bool valid(int adjacent_row, int adjacent_col) {
	if (adjacent_row < 0 || adjacent_row >= nRows || adjacent_col < 0 || adjacent_col >= nCols) {
		return false;
	}
	else {
		return true;
	}
}

void dfs(int sRow, int sCol, vector<vector<int>>& grid, vector<vector<bool>>& visited) {

	visited[sRow][sCol] = true;

	for (int i = 0; i < 4; i++) {
		int adjacent_row = sRow + d[i].first;
		int adjacent_col = sCol + d[i].second;

		if (valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col] && grid[adjacent_row][adjacent_col] == 1) {
			dfs(adjacent_row, adjacent_col, grid, visited);
		}
	}
}

int main() {
	cout << "Number of rows and colums: ";
	cin >> nRows >> nCols;

	vector<vector<int>>grid(nRows, vector<int>(nCols));

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			int value;
			cout << "Enter grid[" << row << "][" << col << "]: ";
			cin >> value;

			grid[row][col] = value;
		}
	}

	//display the grid
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << grid[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));

	int countIsland = 0;

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (grid[row][col] == 1 && !visited[row][col]) {
				dfs(row, col, grid, visited);
				countIsland++;
			}
		}
	}

	cout << "Number of islands: " << countIsland<<endl;


	return 0;
}

/*

0 0 0 1 0
0 1 1 0 0
0 1 1 0 0
0 0 0 1 1

*/