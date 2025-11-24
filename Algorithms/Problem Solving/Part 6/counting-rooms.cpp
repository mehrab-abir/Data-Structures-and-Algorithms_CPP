#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://cses.fi/problemset/task/1192

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

void dfs(int sRow, int sCol, vector<vector<char>>&grid, vector<vector<bool>>&visited) {
	visited[sRow][sCol] = true;

	for (int i = 0; i < 4; i++) {
		int adjacent_row = sRow + d[i].first;
		int adjacent_col = sCol + d[i].second;

		if (valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col] && grid[adjacent_row][adjacent_col] == '.') {
			dfs(adjacent_row, adjacent_col, grid, visited);
		}
	}
}

int main() {
	//cout << "Number of rows and colums: ";
	cin >> nRows >> nCols;

	vector<vector<char>>grid(nRows, vector<char>(nCols));

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			char value;
			//cout << "Enter grid[" << row << "][" << col << "]: ";
			cin >> value;

			grid[row][col] = value;
		}
	}


	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));

	int countRoom = 0;

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (!visited[row][col] && grid[row][col] == '.') {
				dfs(row, col, grid, visited);
				countRoom++;
			}
		}
	}

	cout << countRoom;

	return 0;
}