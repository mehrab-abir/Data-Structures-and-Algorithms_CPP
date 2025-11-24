#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{

public:
    Node* head = NULL;

    int length = 0; //size track rakhar jonno

    void push(int data){
        Node* newnode = new Node(data);
        length++;

        if (head == NULL) {
            head = newnode;
            return;
        }
        newnode->next = head;  /*ulta connection, jate head sobar upore thakbe and connection thakbe nicher dike,,eta
        korle O(1) complexity te pop kora jabe,,nahole loop diye tail delete korte hoy jeta O(n)*/
        head = newnode;

    }

    void pop(){
        if (head == NULL) {
            return;
        }

        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;

        length--;
    }

    int getTop() {
        return head->data;
    }

    int getSize(){
        return length;
    }

    bool isEmpty(){
        return head == NULL;
    }
};
int main() {

    Stack st;

    int n;
    cout << "Stack size: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cout << "Number " << i + 1 << ": ";
        cin >> val;

        st.push(val);
    }

    while (!st.isEmpty()) {
        cout << st.getTop() << endl;
        st.pop();
    }

    return 0;
}

