#include <algorithm>
#include <cstdio>
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

int find_height(bstNode* root) {
    if (root == nullptr) {
        return -1;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    }

    int left_height = find_height(root->left);
    int right_height = find_height(root->right);

    return max(left_height, right_height) + 1;
}

int find_depth(bstNode* root, int item) {
    if (root == nullptr) return -1;

    int dist = -1;

    if (
        (root->data == item) ||
        (dist = find_depth(root->left, item)) >= 0 ||
        (dist = find_depth(root->right, item)) >= 0
    ) {
        return dist+1;
    }

    return dist;
}

int main() {
    bstNode* root = nullptr;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);

    printf("\nThe height of the tree is - %d\n",find_height(root));
    printf("\nThe depth of the last element is - %d\n",find_depth(root, 12));
    return 0;
}
