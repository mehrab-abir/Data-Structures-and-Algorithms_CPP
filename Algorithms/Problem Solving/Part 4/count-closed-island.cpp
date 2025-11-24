#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//https://leetcode.com/problems/number-of-closed-islands/description/

int nRows, nCols;

vector<pair<int, int>>d = { {-1,0},{1,0},{0,-1},{0,1} };

/*
//not needed as lambda function is implemented inside dfs()
bool valid(int adjacent_row, int adjacent_col) {
	if (adjacent_row < 0 || adjacent_row >= nRows || adjacent_col < 0 || adjacent_col >= nCols) {
		return false;
	}
	else {
		return true;
	}
}
*/

//Using DFS

void dfs(int sRow, int sCol, vector<vector<int>>& grid, vector<vector<bool>>& visited, bool& isClosedIsland) {
	visited[sRow][sCol] = true;

	for (int i = 0; i < 4; i++) {
		int adjacent_row = sRow + d[i].first;
		int adjacent_col = sCol + d[i].second;

		//lambda function to check the validity of a cell
		auto isValid = [adjacent_row,adjacent_col](){
            if (adjacent_row < 0 || adjacent_row >= nRows || adjacent_col < 0 || adjacent_col >= nCols) {
                return false;
            }
            else {
                return true;
            }
        };

		//this block only execute when the adjacent for any 0 is out of the grid
		//then the island is decided as not closed
		//otherwise all nodes of the component are visited and dfs calls back to the main()
		if (!isValid()) {
			isClosedIsland = false;
		}

		if (isValid() && !visited[adjacent_row][adjacent_col] && grid[adjacent_row][adjacent_col] == 0) {
			dfs(adjacent_row, adjacent_col, grid, visited, isClosedIsland);
		}
	}
}



//Using BFS
/*
void bfs(int sRow, int sCol, vector<vector<int>>& grid, vector<vector<bool>>& visited, bool& isClosedIsland) {

	queue<pair<int, int>>q;
	q.push({ sRow,sCol });
	visited[sRow][sCol] = true;

	while (!q.empty()) {
		pair<int, int>currentCell = q.front();
		q.pop();

		int current_row = currentCell.first;
		int current_col = currentCell.second;

		for (int i = 0; i < 4; i++) {
			int adjacent_row = current_row + d[i].first;
			int adjacent_col = current_col + d[i].second;

			//this block only execute when the adjacent for any 0 is out of the grid
			//then the island is decided as not closed
			if (!valid(adjacent_row, adjacent_col)) {
				isClosedIsland = false;
			}

			if (valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col] && grid[adjacent_row][adjacent_col] == 0) {
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

	vector<vector<int>>grid(nRows, vector<int>(nCols));

	//Grid
	cout << "Input for Grid: " << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			int value;
			cout << "Enter grid[" << row << "][" << col << "]: ";
			cin >> value;

			grid[row][col] = value;
		}
	}
	cout << endl;

	//display the grid
	cout << "The Grid:" << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << grid[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));

	int countClosedIsland = 0;

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			if (grid[row][col] == 0 && !visited[row][col]) {

				bool isClosedIsland = true;

				dfs(row, col, grid, visited, isClosedIsland);

				if (isClosedIsland) {
					countClosedIsland++;
				}
			}
		}
	}

	cout << "Number of closed islands: " << countClosedIsland << endl;


	return 0;
}
