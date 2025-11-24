#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://leetcode.com/problems/number-of-enclaves/

int nRows, nCols;

vector<pair<int, int>>moves = { {-1,0},{1,0},{0,-1},{0,1} };

bool valid(int adjRow, int adjCol) {
    if (adjRow < 0 || adjRow >= nRows || adjCol < 0 || adjCol >= nCols) {
        return false;
    }
    else {
        return true;
    }
}

void bfs(int sRow, int sCol, vector<vector<int>>& grid, vector<vector<bool>>&visited, int &countEnclave, bool &enclave) {
    queue<pair<int, int>>q;
    q.push({ sRow,sCol });
    visited[sRow][sCol] = true;
    countEnclave++;

    while (!q.empty()) {
        pair<int, int>current = q.front();
        q.pop();

        int cur_row = current.first;
        int cur_col = current.second;

        for (int i = 0; i < 4; i++) {
            int adjRow = cur_row + moves[i].first;
            int adjCol = cur_col + moves[i].second;

            if (!valid(adjRow, adjCol)) {
                enclave = false;
            }

            if (valid(adjRow, adjCol) && !visited[adjRow][adjCol] && grid[adjRow][adjCol] == 1) {
                q.push({ adjRow,adjCol });
                visited[adjRow][adjCol] = true;
                countEnclave++;
            }
        }
    }
}

int main(){
    cout << "Number of rows and columns: ";
    cin>>nRows>>nCols;

    vector<vector<int>>grid(nRows, vector<int>(nCols));

    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            //cout << "Enter grid[" << row << "][" << col << "]: ";
            cin >> grid[row][col];
        }
    }

    vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));
    int total = 0;
    

    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            if (grid[row][col] == 1 && !visited[row][col]) {
                int countEnclave = 0;
                bool enclave = true;
                bfs(row, col, grid, visited, countEnclave, enclave);

                if (enclave == true) {
                    total = total + countEnclave;
                }
            }
        }
    }

    cout << "\nNumber of enclaves : " << total << endl;
    

    return 0;
}
/*
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0



0 1 1 0
0 0 1 0
0 0 1 0
0 0 0 0

*/
