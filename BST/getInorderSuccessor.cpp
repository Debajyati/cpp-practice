#include <iostream>

struct BSTnode_t {
  int data;
  BSTnode_t *left;
  BSTnode_t *right;
};

BSTnode_t *getNewNode(int data) {
  BSTnode_t *newNode = new BSTnode_t();
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
}

BSTnode_t *insert(BSTnode_t *root, int data) {
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

BSTnode_t *find_node(BSTnode_t *root, int data) {
  if ((root == nullptr) || (root->data == data))
    return root;
  else if (data <= root->data)
    return find_node(root->left, data);
  else
    return find_node(root->right, data);
}

BSTnode_t* findMin_bst(BSTnode_t* root) {
    if (root == nullptr) return nullptr;

    BSTnode_t* cu = root;
    while (cu->left != nullptr) {
        cu = cu->left;
    }

    return cu;
}

BSTnode_t *getSuccessor(BSTnode_t *root, int data) {
  BSTnode_t *current = find_node(root, data); // Searching the node - O(h)

  if (current == nullptr)
    return nullptr;

  // case 1: node has right subtree
  if (current->right != nullptr) {
    return findMin_bst(current->right); // O(h)
  }
  // case 2: no right subtree - O(h)
  else {
    BSTnode_t* successor = nullptr;
    BSTnode_t* ancestor = root;

    while (ancestor != current) {
      if (current->data < ancestor->data) {
        successor = ancestor; // so far this is the deepest node for which current node is in left
        ancestor = ancestor->left;
      } else {
        ancestor = ancestor->right;
      }
    }
    return successor;
  }
}

int main(int argc, char *argv[]) {
  int n;
  std::cout
      << "Enter the number of elements to be inserted in the binary tree\n";
  std::cin >> n;

  BSTnode_t *root = nullptr;
  std::cout << "Enter the elements one by one" << std::endl;
  for (size_t i = 0; i < n; i++) {
    int value;
    std::cin >> value;
    root = insert(root, value);
  }

  std::cout << "Enter the element you want to find inorder successor of:- \n";
  int input;
  std::cin >> input;
  BSTnode_t* successor = getSuccessor(root, input);
  if (successor == nullptr) {
    std::cout << "Successor doesn't exist\n";
  } else {
    std::cout << "The Successor is :- " << successor->data << std::endl;
  }
  return 0;
}
