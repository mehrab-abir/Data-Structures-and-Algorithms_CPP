#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>>d = { {-1,0 }, {1, 0}, {0, -1}, {0, 1} }; //Serial of nodes => Up, Down, Left, Right
int nRows, nCols;

bool valid(int childRow, int childCol) {
	if (childRow < 0 || childRow >= nRows || childCol < 0 || childCol >= nCols) {
		return false;
	}
	else {
		return true;
	}
}

//Complexity of 2D grid -> O(n*m) = (nRows*nCols)

void dfs(int sRow, int sCol, vector<vector<char>>& grid, vector<vector<bool>>& visited) {

	cout << sRow << "," << sCol << endl;
	visited[sRow][sCol] = true;

	//loop executes 4 times, for (up, down, left, right) index of current node
	for (int i = 0; i < 4; i++) {
		int childRow = sRow + d[i].first;
		int childCol = sCol + d[i].second;

		if (valid(childRow, childCol) && visited[childRow][childCol] == false) {
			dfs(childRow, childCol, grid, visited);
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
		cout << endl;
	}
	cout << endl;

	cout << "Number of nodes (nRows * nCols) = " << nRows * nCols << endl;

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));

	int srcRow, srcCol;
	cout << "Enter the index of source (row, col): ";
	cin >> srcRow >> srcCol;

	//getting all indices of all items/nodes.
	dfs(srcRow, srcCol, grid, visited);

	return 0;
}