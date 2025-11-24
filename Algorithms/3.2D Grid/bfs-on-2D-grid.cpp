#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int nRows, nCols; //global declarations for convenience(optional)

vector<pair<int, int>>d = { {-1,0},{1,0},{0,-1},{0,1} }; //up, down, left, right

bool valid(int adjacent_row, int adjacent_col) {
	if (adjacent_row < 0 || adjacent_row >= nRows || adjacent_col < 0 || adjacent_col >= nCols) {
		return false;
	}
	else {
		return true;
	}
}

void bfs(int sRow, int sCol, vector<vector<char>>& grid, vector<vector<bool>>&visited) {
	queue<pair<int, int>>q;
	q.push({ sRow,sCol });
	visited[sRow][sCol] = true;

	while (!q.empty()) {
		pair<int, int> currentNode = q.front();
		q.pop();

		int current_row = currentNode.first;
		int current_col = currentNode.second;

		cout << current_row << ", " << current_col << endl;

		for (int i = 0; i < 4; i++) {
			int adjacent_row = current_row + d[i].first;
			int adjacent_col = current_col + d[i].second;

			if (valid(adjacent_row, adjacent_col) && visited[adjacent_row][adjacent_col] == false) {
				q.push({ adjacent_row,adjacent_col });
				visited[adjacent_row][adjacent_col] = true;
			}
		}
	}
}

int main() {

	cout << "Number of rows: ";
	cin >> nRows;
	cout << "Number of columns: ";
	cin >> nCols;

	vector<vector<char>>grid(nRows, vector<char>(nCols, '*'));

	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << grid[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\nNumber of nodes (nRows*nCols): " << nRows * nCols << endl;

	int sRow, sCol; //row and col index of source node
	cout << "Enter row and column index of source (row,col): ";
	cin >> sRow>>sCol;

	//validating the index of source's row and column
	if (!valid(sRow, sCol)) {
		cout << "\n  !!Invalid source" << endl;
	}
	else {
		vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));
		bfs(sRow, sCol, grid, visited); //getting all indices of all items/nodes of the grid
	}


	return 0;
}