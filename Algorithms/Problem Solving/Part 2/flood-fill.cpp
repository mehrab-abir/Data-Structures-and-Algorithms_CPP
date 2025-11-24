#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

//https://leetcode.com/problems/flood-fill/description/
//Accepted

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

void bfs(vector<vector<int>>& image, int sRow, int sCol, int color, vector<vector<bool>>& visited) {
	queue < pair<int, int>>q;
	q.push({ sRow,sCol });
	visited[sRow][sCol] = true;

	int original_color = image[sRow][sCol];

	while (!q.empty()) {
		pair<int, int>currentPixel = q.front();
		q.pop();

		int current_row = currentPixel.first;
		int current_col = currentPixel.second;

		image[current_row][current_col] = color;

		for (int i = 0; i < 4; i++) {
			int adjacent_row = current_row + d[i].first;
			int adjacent_col = current_col + d[i].second;

			if (valid(adjacent_row, adjacent_col) && image[adjacent_row][adjacent_col] == original_color && !visited[adjacent_row][adjacent_col]) {
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

	vector<vector<int>>image(nRows, vector<int>(nCols));

	//input for image grid - pixel values
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			int pixel;
			cout << "Enter pixel value for image[" << row << "][" << col << "]: ";
			cin >> pixel;
			
			image[row][col] = pixel;
		}
	}
	cout << endl;

	//printing image grid
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << image[row][col] << " ";
		}
		cout << endl;
	}

	int sRow, sCol, color;
	cout << "Enter the index of source pixel(row,col): ";
	cin >> sRow >> sCol;

	cout << "Enter the fill-color: ";
	cin >> color;

	vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));

	bfs(image, sRow, sCol, color, visited);


	//printing image grid
	cout << "\nAfter flood fill: " << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			cout << image[row][col] << " ";
		}
		cout << endl;
	}

	return 0;
}