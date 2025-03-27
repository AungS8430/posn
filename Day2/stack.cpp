#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};
typedef struct Node node;

node *head = NULL;

void push(int n);
int pop();
bool isEmpty();

int main(void) {
	int n;
	cin >> n;
	while (n > 0) {
		push(n % 2);
		n /= 2;
	}
	while (!isEmpty()) {
		cout << pop();
	}
	return 0;
}

void push(int n) {
	node *curr;
	if (head == NULL) {
		head = new node;
		head->data = n;
		head->next = NULL;
	} else {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new node;
		curr->next->data = n;
		curr->next->next = NULL;
	}
}

int pop() {
	if (head == NULL) {
		return -1;
	}
	int n;
	node *temp;

	if (head->next == NULL) {
		n = head->data;
		delete head;
		head = NULL;
		return n;
	}

	node *curr = head;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	n = curr->next->data;
	delete curr->next;
	curr->next = NULL;
	return n;
}


bool isEmpty() {
	return head == NULL;
}