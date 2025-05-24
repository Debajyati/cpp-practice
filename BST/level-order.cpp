/* 
* Breadth First Search Traversal Implementation in C++
*/

#include <cstdio>
#include <queue>
using namespace std;

struct bstNode {
    int data;
    bstNode* left;
    bstNode* right;  
};

bstNode* getNewNode(int data) {
    bstNode* newNode = new bstNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

bstNode* insert(bstNode* root, int data) {
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

void level_order(bstNode* root) {
  if (root == nullptr) return;

  queue<bstNode*> Q;

  Q.push(root);
  // while there is atleast one discovered node
  while (!Q.empty()) {
    bstNode* current = Q.front();
    printf("%d ",current->data);

    if (current->left != nullptr) {
      Q.push(current->left);
    }

    if (current->right != nullptr) {
      Q.push(current->right);
    }

    Q.pop();
  }
  printf("\n");
}

int main (int argc, char *argv[]) {
  bstNode* root = nullptr;

  root = insert(root, 15);
  root = insert(root, 20);
  root = insert(root, 10);
  root = insert(root, 25);
  root = insert(root, 8);
  root = insert(root, 12);

  printf("Starting Level Order Traversal\n");

  level_order(root);

  return 0;
}
