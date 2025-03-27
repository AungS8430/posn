#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
} node;
node *head = NULL;

void createList(int n);
void displayList();
void deleteFront();
void deleteLast();
void deleteMiddle(int n);

int main(void) {
	int n;
	cout << "Input the number of nodes: ";
	cin >> n;
	createList(n);
	cout << endl;
	cout << "Data entered in the list: " << endl;
	displayList();
	cout << endl;
	deleteFront();
	cout << "Data, after deletion of first node: " << endl;
	displayList();
	cout << endl;
	deleteLast();
	displayList();
	cout << "Input the position of node to delete: ";
	cin >> n;
	deleteMiddle(n);
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

void deleteFront() {
	node *temp = head;
	cout << "Data of the 1st node which is being deleted is: " << head->data << endl;
	head = head->next;
	delete temp;
	return;
}

void deleteLast() {
	node *prev = head;
	for (prev = head; prev->next->next != NULL; prev = prev->next);
	cout << "Data of the last node which is being deleted is: " << prev->next->data << endl;
	delete prev->next;
	prev->next = NULL;
	return;
}

void deleteMiddle(int n) {
	node *after = head->next->next, *prev = head;
	for (int i = 0; i < n - 2; i++) {
		prev = prev->next;
		after = prev->next->next;
	}
	delete prev->next;
	prev->next = after;
	return;
}