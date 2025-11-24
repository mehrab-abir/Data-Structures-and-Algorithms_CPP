#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//https://leetcode.com/problems/max-area-of-island/description/

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

void bfs(int sRow, int sCol, vector<vector<int>>&grid, vector<vector<bool>>&visited, vector<int>&landArea) {
	int countLand = 0;

	queue<pair<int, int>>q;
	q.push({ sRow,sCol });
	visited[sRow][sCol] = true;

	countLand++;

	while (!q.empty()) {
		pair<int, int>currentCell = q.front();
		q.pop();

		int current_row = currentCell.first;
		int current_col = currentCell.second;

		for (int i = 0; i < 4; i++) {
			int adjacent_row = current_row + d[i].first;
			int adjacent_col = current_col + d[i].second;

			if (valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col] && grid[adjacent_row][adjacent_col] == 1) {
				q.push({ adjacent_row,adjacent_col });
				visited[adjacent_row][adjacent_col] = true;
				countLand++;
			}
		}
	}
	landArea.push_back(countLand);
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
			cout<<grid[row][col]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));

	vector<int>landArea;

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (grid[row][col] == 1 && !visited[row][col]) {
				bfs(row, col, grid, visited, landArea);
			}
		}
	}

	if (landArea.size() == 0) {
		cout << "There is no island" << endl;
		return 0;
	}

	cout << "\nAreas of all islands: ";
	for (int lands : landArea) {
		cout << lands << " ";
	}
	cout << endl;

	int maxArea = *max_element(landArea.begin(), landArea.end());

	cout << "Island with max area: " << maxArea << endl;

	return 0;
}

/*

0 0 0 1 0 
0 1 1 0 0 
0 1 1 0 0 
0 0 0 1 1

*/