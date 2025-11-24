#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/n-th-tribonacci-number/

int main(){
    int n;
    cin>>n;

    vector<int>tribo(n+1);

    for(int i=0;i<=n;i++){
        if(i == 0 || i == 1 ){
            tribo[i] = i;
        }
        else if(i==2){
            tribo[i] = 1;
        }
        else{
            tribo[i] = tribo[i-1] + tribo[i-2] + tribo[i-3];
        }

        cout<<tribo[i]<<" ";
    }
    cout<<endl;

    cout<<tribo[n];

    return 0;
}