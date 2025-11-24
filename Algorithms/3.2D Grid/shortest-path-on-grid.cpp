#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
//only walk through even numbers

vector<pair<int, int>>moves = { {-1,0},{1,0},{0,-1},{0,1} }; //up, down, left, right

int nRows, nCols;

bool valid(int adj_row, int adj_col) {
    if (adj_row < 0 || adj_row >= nRows || adj_col < 0 || adj_col >= nCols) {
        return false;
    }
    else {
        return true;
    }
}

void bfs(int sRow, int sCol, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<pair<int, int>>>& parent) {
    queue<pair<int, int>>q;
    q.push({ sRow,sCol });
    visited[sRow][sCol] = true;

    while (!q.empty()) {
        pair<int, int>current = q.front();
        q.pop();

        int cRow = current.first;
        int cCol = current.second;

        for (int i = 0; i < 4; i++) {
            int adj_row = cRow + moves[i].first;
            int adj_col = cCol + moves[i].second;

            if (valid(adj_row, adj_col) && !visited[adj_row][adj_col] && (grid[adj_row][adj_col]%2 == 0)) {
                q.push({ adj_row,adj_col });
                visited[adj_row][adj_col] = true;
                parent[adj_row][adj_col] = { cRow,cCol };
            }
        }
    }

}

int main() {
    cout << "Number of rows and columns: ";
    cin >> nRows >> nCols;

    vector<vector<int>>grid(nRows, vector<int>(nCols));

    //input
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            cin >> grid[row][col];
        }
    }

    vector<vector<bool>>visited(nRows, vector<bool>(nCols, false));
    vector<vector<pair<int, int>>>parent(nRows, vector<pair<int, int>>(nCols, { -1,-1 }));

    int sRow, sCol, dRow, dCol;
    
    cout << "Source index (row,col): ";
    cin >> sRow >> sCol;
    cout << "Destination index (row,col): ";
    cin >> dRow >> dCol;

    if (grid[sRow][sCol] % 2 != 0 || grid[dRow][dCol] % 2 != 0) {
        cout << "\n  !!Invalid source or destination.\n";
        return 0;
    }

    bfs(sRow, sCol, grid, visited, parent);

    vector<int>path;

    if (parent[dRow][dCol].first == -1) {
        cout << "No shortest path found.\n";
    }
    else {
        while (grid[dRow][dCol] != grid[sRow][sCol]) {
            path.push_back(grid[dRow][dCol]);

            pair<int, int>par = parent[dRow][dCol];

            dRow = par.first;
            dCol = par.second;

            if (grid[dRow][dCol] == grid[sRow][sCol]) {
                path.push_back(grid[dRow][dCol]);
                break;
            }
        }

        //path print
        reverse(path.begin(), path.end());
        cout << "\nShortest path: ";
        for (int p : path) {
            cout << p << " ";
        }
    }
    cout << endl;

    return 0;
}
/*
4 5
12 15 16 14 19
11 10 24 60 54
13 35 77 44 46
17 42 93 94 48
3 4
1 2
*/