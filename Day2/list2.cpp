#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
} node;
node *head = NULL;

void createList(int n);
void displayList();
void insertFront(int n);
void insertLast(int n);
void insertMiddle(int n, int m);

int main(void) {
	int n;
	cout << "Input the number of nodes: ";
	cin >> n;
	createList(n);
	cout << endl;
	cout << "Data entered in the list: " << endl;
	displayList();
	cout << endl;
	cout << "Input data to insert at the beginning of the list: ";
	cin >> n;
	insertFront(n);
	cout << endl;
	cout << "Data entered in the list: " << endl;
	displayList();
	cout << endl;
	cout << "Input data to insert at the end of the list: ";
	cin >> n;
	insertLast(n);
	cout << endl;
	cout << "Data entered in the list: " << endl;
	displayList();
	cout << endl;
	int m;
	cout << "Input data to insert in the middle of the list: ";
	cin >> n;
	cout << "Input the position to insert the new node: ";
	cin >> m;
	insertMiddle(n, m);
	displayList();
	return 0;
}

void createList(int n) {
	head = new Node;
	node *prev, *last;
	int input;
	last = head;
	for (int i = 0; i < n; i++) {
		if (i > 0) last = new Node;
		prev->next = last;
		cout << "Input data for node " << i + 1 << ": ";
		cin >> last->data;
		prev = last;
	}
	return;
}

void displayList() {
	for (node *prev = head; prev != NULL; prev = prev->next) {
		cout << "Data: " << prev->data << endl;
	}
	return;
}

void insertFront(int n) {
	node *temp = new Node;
	temp->data = n;
	temp->next = head;
	head = temp;
	return;
}

void insertLast(int n) {
	node *prev, *n_node = new Node;
	for (prev = head; prev->next != NULL; prev = prev->next);
	prev->next = n_node;
	n_node->data = n;
	return;
}

void insertMiddle(int n, int m) {
	node *prev = head, *next, *n_node = new Node;
	for (int i = 1; i < m - 1; i++) {
		prev = prev->next;
		next = prev->next;
	}
	n_node->next = next;
	prev->next = n_node;
	n_node->data = n;
	return;
}