#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};

void levelorder(Node* root) {

	if(root == NULL){
		cout<<"Tree is empty"<<endl;
		return;
	}
	
	queue<Node*>q;

	q.push(root); //prothome root node ke queue te push kore rekhe dite hobe

	while (!q.empty()) {
		
		//1. Node ber kore ana
		Node* qFront = q.front();
		q.pop();

		//2. Oi node niye kaj kora,,jemon eikhane value print kora
		cout << qFront->value << " ";

		//3. Children push kora,, jodi thake r ki
		if (qFront->left != NULL) {
			q.push(qFront->left);
		}
		if (qFront->right != NULL) {
			q.push(qFront->right);
		}
	}
}


int main() {
	Node* root = new Node(10);
	Node* a = new Node(20);
	Node* b = new Node(30);
	Node* c = new Node(40);
	Node* d = new Node(50);
	Node* e = new Node(60);

	root->left = a;
	root->right = b;
	a->left = c;
	b->left = d;
	b->right = e;

	cout << "Level order traversal: ";
	levelorder(root);

	cout << endl;

	return 0;
}
