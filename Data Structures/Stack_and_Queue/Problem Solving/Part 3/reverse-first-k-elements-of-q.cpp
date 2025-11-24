#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main() {

    queue<int>q;

    int n;
    cout << "Queue size: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cout << "Number " << i + 1 << ": ";
        cin >> val;

        q.push(val);
    }

    int k;
    cout << "How many numbers to reverse: ";
    cin >> k;


    queue<int>copyQ;

    int i = 1;
    while (i <= k) {
        copyQ.push(q.front());
        q.pop();
        i++;
    }


    stack<int>st;

    while (!copyQ.empty()) {
        st.push(copyQ.front());
        copyQ.pop();
    }



    queue<int>finalQ;

    while (!st.empty()) {
        finalQ.push(st.top());
        st.pop();
    }

    while (!q.empty()) {
        finalQ.push(q.front());
        q.pop();
    }

    //final output
    while (!finalQ.empty()) {
        cout << finalQ.front() << " ";
        finalQ.pop();
    }

    cout << endl;

	return 0;
}