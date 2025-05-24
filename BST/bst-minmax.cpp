#include <cstdio>
#include <stdexcept>
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

int findMin_bst(bstNode* root) {
    if (root == nullptr) throw std::runtime_error("Empty Binary Search Tree");

    bstNode* cu = root;
    while (cu->left != nullptr) {
        cu = cu->left;
    }

    return cu->data;
}
int findMax_bst(bstNode* root) {
    if (root == nullptr) throw std::runtime_error("Empty Binary Search Tree");

    bstNode* cu = root;
    while (cu->right != nullptr) {
        cu = cu->right;
    }

    return cu->data;
}

int main() {
    bstNode* root = nullptr;

/*  root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12); */
    
    try {
        int min = findMin_bst(root), max = findMax_bst(root);
        
        printf("The minimum element of the tree is - %d\n", min);
        printf("The maximum element of the tree is - %d\n", max);
    } catch (const std::runtime_error& error) {
        fprintf(stderr, "%s\n", error.what());
        return 1;
    }

    return 0;
}