#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

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

int dfs(int srcRow, int srcCol, vector<vector<int>>&grid, vector<vector<bool>>&visited) {

	visited[srcRow][srcCol] = true;
	int fishCount = grid[srcRow][srcCol];

	for (int i = 0; i < 4; i++) {
		int adjacent_row = srcRow + d[i].first;
		int adjacent_col = srcCol + d[i].second;

		if (valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col] && grid[adjacent_row][adjacent_col] > 0) {
			fishCount = fishCount + dfs(adjacent_row, adjacent_col, grid, visited);
		}
	}
	return fishCount;
}

int main() {
	cout << "Number of rows and columns: ";
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
	cout << "\n";

	//display the grid
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << grid[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));

	int maxFish = 0;

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (grid[row][col] > 0 && !visited[row][col]) {
				maxFish = max(maxFish, dfs(row, col, grid, visited));
			}
		}
	}
	cout << "Maximum number of fishes: " << maxFish << endl;


	return 0;
}
