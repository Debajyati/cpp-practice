#include <iostream>
using namespace std;

struct bstNode {
  int data;
  bstNode *left;
  bstNode *right;
};

bstNode *getNewNode(int data) {
  bstNode *newNode = new bstNode();
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
}

bstNode *insert(bstNode *root, int data) {
  if (root == nullptr) {
    root = getNewNode(data);
  }

  else if (data <= root->data) {
    root->left = insert(root->left, data);
  }

  else {
    root->right = insert(root->right, data);
  }

  return root;
}

bool node_search(bstNode *root, int data) {
  if (root == nullptr)
    return false;
  else if (root->data == data)
    return true;
  else if (data <= root->data)
    return node_search(root->left, data);
  else
    return node_search(root->right, data);
}

int main() {
  bstNode *root = nullptr;
  root = insert(root, 'A');
  root = insert(root, 'B');
  root = insert(root, 'a');
  root = insert(root, 'b');
  root = insert(root, '{');
  root = insert(root, 'X');

  int number;
  cout << "Enter the number to be searched!\n";
  cin >> number;

  if (node_search(root, number)) {
    cout << "Found\n";
  } else {
    cout << "NOT Found ;(" << endl;
  }
  return 0;
}
