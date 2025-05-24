#include <cstdio>
using namespace std;

struct bstNode {
  char data;
  bstNode *left;
  bstNode *right;
};

bool issubtreelesser(bstNode *root, char value) {
  if (root == nullptr) return true;

  if ((root->data <= value) && 
    (issubtreelesser(root->left, value)) &&
    (issubtreelesser(root->right, value))
  ) return true;

  return false;
}

bool issubtreegreater(bstNode *root, char value) {
  if (root == nullptr) return true;

  if ((root->data > value) && 
    (issubtreegreater(root->left, value)) &&
    (issubtreegreater(root->right, value))
  ) return true;

  return false;
}

bool isbst(bstNode *root) {
  if (root == nullptr) {
    return true;
  }

  if (issubtreelesser(root->left, root->data) &&
      (issubtreegreater(root->right, root->data) && (isbst(root->left)) &&
       (isbst(root->right))))
    return true;

  return false;
}

bstNode *getNewNode(char data) {
  bstNode *newNode = new bstNode();
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
}

bstNode *insert(bstNode *root, char data) {
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
  root = insert(root, 'A');
  root = insert(root, 'B');
  root = insert(root, 'a');
  root = insert(root, 'b');
  root = insert(root, '{');
  root = insert(root, 'X');

  printf("The given Binary Tree is :- %s\n",
         (isbst(root) ? "A BST" : "NOT A BST"));
  return 0;
}
