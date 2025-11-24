#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/knight-moves-2

int nRows, nCols;

vector<pair<int, int>>knightMove = { {-2,1},{-2,-1},{2,1},{2,-1},{-1,2},{1,2},{-1,-2},{1,-2} };

bool valid(int adjacent_row, int adjacent_col) {
	if (adjacent_row < 0 || adjacent_row >= nRows || adjacent_col < 0 || adjacent_col >= nCols) {
		return false;
	}
	else {
		return true;
	}
}

void bfs(int sRow, int sCol, vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<int>>&distance) {

	queue<pair<int, int>>q;
	q.push({ sRow,sCol });
	visited[sRow][sCol] = true;
	distance[sRow][sCol] = 0;

	while (!q.empty()) {
		pair<int, int>current = q.front();
		q.pop();

		int current_row = current.first;
		int current_col = current.second;

		for (int i = 0; i < 8; i++) {
			int adjacent_row = current_row + knightMove[i].first;
			int adjacent_col = current_col + knightMove[i].second;

			if (valid(adjacent_row, adjacent_col) && !visited[adjacent_row][adjacent_col]) {
				q.push({ adjacent_row,adjacent_col });
				visited[adjacent_row][adjacent_col] = true;
				distance[adjacent_row][adjacent_col] = distance[current_row][current_col] + 1;
			}
		}
	}
}

int main() {
	cout << "Number of rows and colums: ";
	cin >> nRows >> nCols;

	vector<vector<char>>grid(nRows, vector<char>(nCols));

	/*for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			char value;
			cout << "Enter grid[" << row << "][" << col << "]: ";
			cin >> value;

			grid[row][col] = value;
		}
	}*/

	//displaying the grid
	/*cout << "\nThe grid: " << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}*/

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));
	vector<vector<int>>distance(nRows, vector<int>(nCols, -1));

	int ki, kj, qi, qj;
	cout << "Enter Knight's cell (row,col): "; //source
	cin >> ki >> kj;
	cout << "Enter Queen's cell (row,col): "; //destination
	cin >> qi >> qj;

	bfs(ki, kj, grid, visited, distance);

	cout << "Mininum number of moves Knight needs to attack queen: " << distance[qi][qj];

	cout << endl;

	return 0;
}

