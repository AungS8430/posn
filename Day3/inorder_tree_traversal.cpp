#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} node;

void add_member(node *&root, int n) {
  if (root == NULL) {
    node *n_node = new node;
    n_node->data = n;
    n_node->left = NULL;
    n_node->right = NULL;
    root = n_node;
    return;
  } else {
    node *curr = root;
    node *n_node = new node;
    n_node->data = n;
    n_node->left = NULL;
    n_node-> right = NULL;
    while (curr != NULL) {
      if (curr->data <= n) {
        if (curr->right == NULL) {
          curr->right = n_node;
          return;
        } else {
          curr = curr->right;
        }
      } else {
        if (curr->left == NULL) {
          curr->left = n_node;
          return;
        } else {
          curr = curr->left;
        }
      }
    }
  }
}

void inorder(node *ptr) {
  if (ptr != NULL) {
    inorder(ptr->left);
    cout << ptr->data << " ";
    inorder(ptr->right);
    return;
  } else return;
}

int main(void) {
  int n, temp;
  cin >> n;
  node *root = NULL;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    add_member(root, temp);
  }
  inorder(root);
  return 0;
}
