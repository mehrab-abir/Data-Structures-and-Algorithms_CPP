#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int nRows, nCols;
vector<pair<int,int>>moves = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int adj_row, int adj_col){
    if(adj_row < 0 || adj_row >= nRows || adj_col < 0 || adj_col >= nCols){
        return false;
    }
    else{
        return true;
    }
}

void bfs(int sRow, int sCol, vector<vector<char>>&grid, vector<vector<bool>>&visited, vector<vector<int>>&distance){
    queue<pair<int,int>>q;
    q.push({sRow,sCol});
    visited[sRow][sCol] = true;
    distance[sRow][sCol] = 0;

    while(!q.empty()){
        pair<int,int>current = q.front();
        q.pop();

        int cur_row = current.first;
        int cur_col = current.second;

        for(int i=0;i<4;i++){
            int adj_row = cur_row + moves[i].first;
            int adj_col = cur_col + moves[i].second;

            if(valid(adj_row,adj_col) && !visited[adj_row][adj_col] && grid[adj_row][adj_col] != 'T'){
                q.push({adj_row,adj_col});
                visited[adj_row][adj_col] = true;
                distance[adj_row][adj_col] = distance[cur_row][cur_col] + 1;
            }
        }
    }
}

int main(){
    cin>>nRows;
    nCols = nRows;

    vector<vector<char>>grid(nRows,vector<char>(nCols));

    for(int row = 0; row<nRows;row++){
        for(int col =0;col<nCols;col++){
            cin>>grid[row][col];
        }
    }

    vector<vector<bool>>visited(nRows,vector<bool>(nCols, false));
    vector<vector<int>>distance(nRows,vector<int>(nCols,-1));

    int sRow, sCol, dRow, dCol;
    bool foundS = false, foundE = false;

    for(int row =0;row<nRows;row++){
        for(int col = 0;col<nCols;col++){
            if(grid[row][col] == 'S'){
                sRow = row;
                sCol = col;
                foundS = true;
            }
            if(grid[row][col] == 'E'){
                dRow = row;
                dCol = col;
                foundE = true;
            }
        }
    }

    if(!foundS || !foundE){
        cout<<"Source or destination not found";
        return 0;
    }

    bfs(sRow,sCol, grid, visited, distance);

    cout<<"Number of moves needed: "<<distance[dRow][dCol];

    return 0;
}