#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		this->next = NULL;
	}
};

void insert_at_tail(Node*& head, Node*& tail, int value) {
	Node* newnode = new Node(value);

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
}

void print_linked_list(Node* head) {
	Node* temp = head;

	if (temp == NULL) {
		cout << "Linked List is empty." << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

int list_length(Node* head) {
	Node* temp = head;

	int length = 0;

	while (temp != NULL) {
		temp = temp->next;
		length++;
	}
	return length;
}

//delete from any position
void delete_tail(Node*& head, Node* &tail, int lastNode) {
    //if list is already empty
	if(head == NULL){
	    cout<<"List is already empty. Nothing to delete"<<endl;
	    return;
	}

	//if there is only one node
	if (head->next == NULL) {
		delete head;
		head = NULL;
		tail = NULL;
		cout << "\n  Tail deleted. List is now empty" << endl;
		return;
	}

	//otherwise
	Node* temp = head;

	/*length er soman index manei delete tail, jehetu 0 based indexing onujayi tail delete hoy, tai length
	jodi hoy 5, amader loop cholbe 3 bar, jabe index 3 porjonto, jeta 0 based index onujayi 3 number position a ache, r emni serially 4 a, r ai 0 based index er 3 number tai holo last node(tail) er tik ager node, serially 4 number node,
	amader delete korte hobe last node, ai jonno i < lastNode - 1 lekha hoise, (i < 5-1 == i < 4, loop cholbe
	3 bar
	*/
	for (int i = 1; i < lastNode-1; i++) {
		temp = temp->next;
	}
	//loop er por, temp akhon last node er tik age ache
	//tar mane, temp er 'next' a last(tail) node er address ache, jeta delete korte chacchi

	Node* deleteNode = temp->next; //deleteNode er moddhe last node rekhe dilam
	temp->next = temp->next->next; // or temp->next = NULL; lekha jay
	/*temp er 'next' update kore tail(last node) er node er porer node rekhe dilam, akhne seta hocche NULL
	node, tar mane akhon temp er next a null ache*/

	delete deleteNode; // tarpor tail er node delete kore dilam

	//1 tar beshi node thakle tail, tail er jaygay thakbe
	tail = temp; /*karon temp akhon ager last node er tik age chilo, tail delete korar por jeta akhon last
	node hoye gese*/
	cout << "\n  Tail has been deleted" << endl;
}

int main() {

	Node* head = NULL;
	Node* tail = NULL;
	cout << "Create Linked List >>>>" << endl;

	while (true) {
		int value;
		cout << "Enter a value (-1 to end the list): ";
		cin >> value;

		if (value == -1) {
			break;
		}
		insert_at_tail(head, tail, value);
	}
	
	cout << "\nBefore deleting: ";
	print_linked_list(head);

	int length = list_length(head);

	delete_tail(head, tail, length);

	cout << "\nAfter deleting tail: ";
	print_linked_list(head);

	return 0;
}
