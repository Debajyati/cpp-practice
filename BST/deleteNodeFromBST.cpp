#include <queue>
#include <iostream>

typedef struct _node {
  int data;
  _node* left;
  _node* right;
} BSTNode_t;

BSTNode_t* getNewNode(int data) {
  BSTNode_t *newNode = new BSTNode_t();
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
}

BSTNode_t* insert(BSTNode_t *root, int data) {
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

BSTNode_t* findMin_bst(BSTNode_t* root) {
    if (root == nullptr) throw std::runtime_error("Empty Binary Search Tree");

    BSTNode_t* cu = root;
    while (cu->left != nullptr) {
        cu = cu->left;
    }

    return cu;
}

void level_order(BSTNode_t* root) {
  if (root == nullptr) return;

  std::queue<BSTNode_t*> Q;

  Q.push(root);
  // while there is atleast one discovered node
  while (!Q.empty()) {
    BSTNode_t* current = Q.front();
    std::cout << current->data << ' ';

    if (current->left != nullptr) {
      Q.push(current->left);
    }

    if (current->right != nullptr) {
      Q.push(current->right);
    }

    Q.pop();
  }
  std::cout << '\n';
}

BSTNode_t* delete_node(BSTNode_t* root, int data) {
  if (root == nullptr) return root;

  else if (data < root->data) {
    root->left = delete_node(root->left, data);
  }

  else if (data > root->data) {
    root->left = delete_node(root, data);
  }

  else {
    // Found you bastard! Get Ready to be deleted!

    // CASE 1: No Child
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      root = nullptr;
    }

    // CASE 2: One Child
    else if (root->left == nullptr) {
      BSTNode_t* temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == nullptr) {
      BSTNode_t* temp = root;
      root = root->left;
      delete temp;
    }

    // CASE 3: Two Children
    else {
      BSTNode_t* temp = findMin_bst(root->right);
      root->data = temp->data;
      root->right = delete_node(root->right, temp->data);
    }
  }
  return root;
}

int main (int argc, char *argv[]) {
  int n;
  std::cout << "Enter the number of elements to be inserted in the binary tree\n";
  std::cin >> n;

  BSTNode_t* root = nullptr;
  std::cout << "Enter the elements one by one" << std::endl;
  for (size_t i = 0; i < n; i++) {
    int value;
    std::cin >> value;
    root = insert(root, value);
  }

  int el;
  std::cout << "Enter the element you want to delete\n";
  std::cin >> el;

  std::cout << "Level order traversal before deleting " << el << std::endl;
  level_order(root);
  
  delete_node(root, el);
  
  std::cout << "Level order traversal after deleting " << el << std::endl;
  level_order(root);

  return 0;
}
