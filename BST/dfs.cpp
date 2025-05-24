/*
 * Depth First Search Traversal Implementation in C++
 * 1. Preorder
 * 2. Inorder
 * 3. Postorder
 */

#include <cstdio>
using namespace std;

struct bstNode {
  char data;
  bstNode *left;
  bstNode *right;
};

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

void preorder(bstNode* root) {
  if (root == nullptr) return;

  printf("%c ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(bstNode* root) {
  if (root == nullptr) return;

  inorder(root->left);
  printf("%c ",root->data);
  inorder(root->right);
}

void postorder(bstNode* root) {
  if (root == nullptr)  return;

  postorder(root->left);
  postorder(root->right);
  printf("%c ",root->data);
}

int main(int argc, char *argv[]) {
  bstNode *root = nullptr;

  root = insert(root, 'A');
  root = insert(root, 'B');
  root = insert(root, 'a');
  root = insert(root, 'b');
  root = insert(root, '{');
  root = insert(root, 'X');

  printf("Starting Depth First Traversal\n");
  
  printf("Preorder Traversal :-\n");
  preorder(root);
  printf("\n");

  printf("Inorder Traversal :-\n");
  inorder(root);
  printf("\n");

  printf("Postorder Traversal :-\n");
  postorder(root);
  printf("\n");

  return 0;
}
