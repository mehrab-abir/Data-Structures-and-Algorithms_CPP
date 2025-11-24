#include<iostream>
#include<vector>

using namespace std;

//https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number

int main(){
    int n;
    cin>>n;

    vector<long long int>tetranacci(n+1);

    for(int i=0;i<=n;i++){
        if(i == 0 || i == 1){
            tetranacci[i] = i;
        }
        else if(i == 2){
            tetranacci[i] = 1;
        }
        else if(i == 3){
            tetranacci[i] = 2;
        }
        else{
            tetranacci[i] = tetranacci[i-1] + tetranacci[i-2] + tetranacci[i-3] + tetranacci[i-4];
        }
    }

    cout<<tetranacci[n];



    return 0;
}