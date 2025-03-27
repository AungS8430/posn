#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
} node;
node *head = NULL;

void createList(int n);
void displayList();
int searchList(int n);

int main(void) {
	int n;
	cout << "Input the number of nodes: ";
	cin >> n;
	createList(n);
	cout << endl;
	cout << "Data entered in the list: " << endl;
	displayList();
	cout << endl;
	cout << "Input the element to be searched: ";
	cin >> n;
	int m = searchList(n);
	if (m == -1) cout << "Element not found";
	else cout << "Data found at node " << m;
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

int searchList(int n) {
	node *curr = head;
	for (int i = 0; curr->next != NULL; i++, curr=curr->next) {
		if (curr->data == n) {
			return i + 1;
		}
	}
	return -1;
}