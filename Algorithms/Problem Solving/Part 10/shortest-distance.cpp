#include<iostream>
#include<vector>

using namespace std;

int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    vector<vector<long long int>>adj_mat(nodes+1, vector<long long int>(nodes+1, LLONG_MAX));

    for(int row=0;row<nodes;row++){
        for(int col =0;col<nodes;col++){
            if(row ==  col){
                adj_mat[row][col] = 0;
            }
        }
    }

    for(int i=0;i<edges;i++){
        long long int a,b,w;
        cin>>a>>b>>w;

        adj_mat[a][b] = min(adj_mat[a][b],w);
    }

    for (int m = 1; m <= nodes; m++) {
		for (int s = 1; s <= nodes; s++) {
			for (int d = 1; d <= nodes; d++) {
				if (adj_mat[s][m] != LLONG_MAX && adj_mat[m][d] != LLONG_MAX && (adj_mat[s][m] + adj_mat[m][d] < adj_mat[s][d])) {
					adj_mat[s][d] = adj_mat[s][m] + adj_mat[m][d];
				}
			}
		}
	}

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        long long int src, dest;
        cin>>src>>dest;

        if(adj_mat[src][dest] == LLONG_MAX){
            cout<<"-1"<<endl;
        }
        else{
            cout<<adj_mat[src][dest]<<endl;
        }
    }

    return 0;
}