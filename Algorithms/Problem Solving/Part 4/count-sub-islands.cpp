#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//https://leetcode.com/problems/count-sub-islands/

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


//Using DFS
void dfs(int sRow, int sCol, vector<vector<int>>& grid_1, vector<vector<int>>& grid_2, vector<vector<bool>>& visited,bool &isSubIsland) {

	if (grid_1[sRow][sCol] != 1) {
		isSubIsland = false;
	}

	visited[sRow][sCol] = true;

	for (int i = 0; i < 4; i++) {
		int adjacent_row = sRow + d[i].first;
		int adjacent_col = sCol + d[i].second;

		if (valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col] && grid_2[adjacent_row][adjacent_col] == 1) {
			dfs(adjacent_row, adjacent_col, grid_1,grid_2, visited, isSubIsland);
		}
	}
}

//Using BFS
/*
void bfs(int sRow, int sCol, vector<vector<int>>& grid_1, vector<vector<int>>& grid_2, vector<vector<bool>>& visited, bool& isSubIsland) {

	queue<pair<int, int>>q;
	q.push({ sRow,sCol });
	visited[sRow][sCol] = true;

	while (!q.empty()) {
		pair<int, int>currentCell = q.front();
		q.pop();

		int current_row = currentCell.first;
		int current_col = currentCell.second;

		if (grid_1[current_row][current_col] != 1) {
			isSubIsland = false;
		}
		//it should visit all cells as part of the component/island, even if it's not sub-island
		//if it's not a sub-island, isSubIsland will remain false thanks to this if..block

		for (int i = 0; i < 4; i++) {
			int adjacent_row = current_row + d[i].first;
			int adjacent_col = current_col + d[i].second;

			if (valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col] && grid_2[adjacent_row][adjacent_col] == 1) {
				q.push({ adjacent_row,adjacent_col });
				visited[adjacent_row][adjacent_col] = true;
			}
		}
	}
}
*/


int main() {
	cout << "Number of rows and colums: ";
	cin >> nRows >> nCols;

	vector<vector<int>>grid_1(nRows, vector<int>(nCols));
	vector<vector<int>>grid_2(nRows, vector<int>(nCols));

	//Grid 1
	cout << "Input for Grid 1: " << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			int value;
			cout << "Enter grid[" << row << "][" << col << "]: ";
			cin >> value;

			grid_1[row][col] = value;
		}
	}

	//Grid 2
	cout << "\nInput for Grid 2: " << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			int value;
			cout << "Enter grid[" << row << "][" << col << "]: ";
			cin >> value;

			grid_2[row][col] = value;
		}
	}
	cout << endl;

	//display the grid 1
	cout << "Grid 1:" << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << grid_1[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	//display the grid 1
	cout << "Grid 2:" << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << grid_2[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));

	int countSubIsland = 0;

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (grid_2[row][col] == 1 && !visited[row][col]) {

				bool isSubIsland = true;

				dfs(row, col, grid_1,grid_2, visited, isSubIsland);

				if (isSubIsland) {
					countSubIsland++;
				}
			}
		}
	}

	cout << "Number of sub-islands: " << countSubIsland << endl;


	return 0;
}

/*
grid 1
1 1 0
0 1 1 
0 0 0
1 0 0

g2
0 1 0
0 1 1
0 0 0
1 0 0

*/