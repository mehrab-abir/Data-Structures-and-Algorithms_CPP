#include<iostream>
#include<vector>

using namespace std;

void getDigits(int n, vector<int>&digits){
    if(n/10 == 0){
        digits.push_back(n);
        return;
    }

    getDigits(n/10,digits);

    int remainder = n%10;
    digits.push_back(remainder);

}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
    
        vector<int>digits;
    
        getDigits(n,digits);
    
        for(int digit : digits){
            cout<<digit<<" ";
        }
        cout<<endl;
    }

    return 0;
}