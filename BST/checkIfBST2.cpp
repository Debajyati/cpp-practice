#include <climits>
#include <cstdio>
using namespace std;

struct bstNode {
  int data;
  bstNode *left;
  bstNode *right;
};

bool _isbst(bstNode *root, int minValue, int maxValue) {
  if (root == nullptr)
    return true;

  if (root->data >= minValue && root->data <= maxValue &&
      _isbst(root->left, minValue, root->data - 1) &&
      _isbst(root->right, root->data + 1, maxValue)) {
    return true;
  }

  return false;
}

bool isbst(bstNode *root) { return _isbst(root, INT_MIN, INT_MAX); }

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

int main(int argc, char *argv[]) {
  bstNode *root = nullptr;

  root = insert(root, 15);
  root = insert(root, 20);
  root = insert(root, 10);
  root = insert(root, 25);
  root = insert(root, 8);
  root = insert(root, 12);

  printf("The given Binary Tree is :- %s\n",
         (isbst(root) ? "A BST" : "NOT A BST"));
  return 0;
}
