#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

//https://cses.fi/problemset/task/1193/

using namespace std;

int nRows, nCols;

vector<pair<int,int>>moves = {{-1, 0},{1,0},{0,-1},{0,1}}; //u,d,l,r

bool valid(int adjRow, int adjCol){
    if(adjRow < 0 || adjRow >= nRows || adjCol < 0 || adjCol >= nCols){
        return false;
    }
    else{
        return true;
    }
}

void bfs(int sRow, int sCol,vector<vector<char>>&grid, vector<vector<bool>>&visited, vector<vector<int>>&distance,vector<vector<pair<int,int>>>&parent){
    queue<pair<int,int>>q;
    q.push({sRow,sCol});
    visited[sRow][sCol] = true;
    distance[sRow][sCol] = 0;

    while(!q.empty()){
        pair<int,int>current = q.front();
        q.pop();

        int cRow = current.first;
        int cCol = current.second;

        for(int i=0; i<4; i++){
            int adjRow = cRow + moves[i].first;
            int adjCol = cCol + moves[i].second;

            if(valid(adjRow,adjCol) && !visited[adjRow][adjCol] && (grid[adjRow][adjCol] == '.' || grid[adjRow][adjCol] == 'A' || grid[adjRow][adjCol] == 'B')){
                q.push({adjRow,adjCol});
                visited[adjRow][adjCol] = true;
                distance[adjRow][adjCol] = distance[cRow][cCol] + 1;
                parent[adjRow][adjCol] = {cRow,cCol};
            }
        }

    }
}

int main() {
    cin>>nRows>>nCols; //input number of rows and columns

    vector<vector<char>>grid(nRows,vector<char>(nCols));

    //input grid
    for(int row=0;row<nRows;row++){
        for(int col=0;col<nCols;col++){
            cin>>grid[row][col];
        }
    }

    int sRow, sCol, dRow, dCol;

    bool foundA = false;
    bool foundB = false;

    //get source and destination index
    for(int row=0;row<nRows;row++){
        for(int col=0;col<nCols;col++){
            if(grid[row][col] == 'A'){
                sRow = row;
                sCol = col;
                foundA = true;
            }

            if(grid[row][col] == 'B'){
                dRow = row;
                dCol = col;
                foundB = true;
            }
        }
    }

    if(!foundA || !foundB){
        cout<<"Source or destination not found."<<endl;
        return 0;
    }

    vector<vector<bool>>visited(nRows,vector<bool>(nCols, false));
    vector<vector<int>>distance(nRows,vector<int>(nCols,-1));
    vector<vector<pair<int,int>>>parent(nRows,vector<pair<int,int>>(nCols, {-1,-1}));

    bfs(sRow, sCol, grid, visited, distance, parent);

    vector<char>path;

    if(parent[dRow][dCol].first == -1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<distance[dRow][dCol]<<endl;

	//start backtracking
        int current_row = dRow;
        int current_col = dCol;

        while(1){

            if(grid[current_row][current_col] == 'A'){
                break;
            }

            pair<int,int>par = parent[current_row][current_col];

            int pRow = par.first;
            int pCol = par.second;

            if(pRow - current_row == 1 && pCol - current_col == 0){
                path.push_back('U');
            }
            if(pRow - current_row == -1 && pCol - current_col == 0){
                path.push_back('D');
            }
            if(pRow - current_row == 0 && pCol - current_col == -1){
                path.push_back('R');
            }
            if(pRow - current_row == 0 && pCol - current_col == 1){
                path.push_back('L');
            }

            current_row = pRow;
            current_col = pCol;
        }

        reverse(path.begin(),path.end());
        for(char p:path){
            cout<<p;
        }
    }

	return 0;
}
