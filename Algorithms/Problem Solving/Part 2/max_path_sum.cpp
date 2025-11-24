#include<iostream>
#include<vector>

using namespace std;

//https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X

int nRows, nCols;
vector<vector<int>>memo;

int getPathSum(int row, int col,vector<vector<int>>&matrix){
    if(row == nRows || col == nCols){
        return 0;
    }

    if(memo[row][col] != -1){
        return memo[row][col];
    }

    int path_one = getPathSum(row+1, col, matrix) + matrix[row][col];
    int path_two = getPathSum(row, col+1, matrix) + matrix[row][col];

    memo[row][col] = max(path_one, path_two);
    return memo[row][col];
}

int main(){
    cin>>nRows>>nCols;

    vector<vector<int>>matrix(nRows+1,vector<int>(nCols+1));

    memo.assign(nRows,vector<int>(nCols,-1));

    for(int row = 0;row<nRows;row++){
        for(int col = 0;col<nCols;col++){
            cin>>matrix[row][col];
        }
    }

    int maxSum = getPathSum(0,0,matrix);

    cout<<maxSum<<endl;

    return 0;
}