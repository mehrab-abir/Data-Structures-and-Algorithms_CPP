#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/pile-of-word-37-3

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        
        string str1, str2;

        cin>>str1;
        cin>>str2;

        if(str1 == str2){
            cout<<"YES"<<endl;
        }
        else if(str1.length() != str2.length()){
            cout<<"NO"<<endl;
        }
        else{
            sort(str1.begin(),str1.end());
            sort(str2.begin(),str2.end());

            bool match = true;

            for(int i=0;i<str1.length();i++){
                if(str1[i] != str2[i]){
                    match = false;
                    break;
                }
            }

            if(match){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}