/*
 * Rakesh Kumar
 * Never stop learning
 * 17/06/2021
 */

#include <bits/stdc++.h>

struct Node {
    Node() {}
    Node(int val) : val(val) {}

    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BST {
public:
    Node* insert(Node* root, int val) {
        if (root == nullptr)
            root = new Node(val);
        else {
            Node* node = root;
            while (node) {
                if (val < node->val) {
                    if (node->left == nullptr) {
                        node->left = new Node(val);
                        break;
                    } else
                        node = node->left;
                } else {
                    if (node->right == nullptr) {
                        node->right = new Node(val);
                        break;
                    } else
                        node = node->right;
                }
            }
        }
        return root;
    }

    void preorder(Node* root) {
        printf("%d ", root->val);
        if (root->left) preorder(root->left);
        if (root->right) preorder(root->right);
    }

    void inorder(Node* root) {
        if (root->left) inorder(root->left);
        printf("%d ", root->val);
        if (root->right) inorder(root->right);
    }

    void postorder(Node* root) {
        if (root->left) postorder(root->left);
        if (root->right) postorder(root->right);
        printf("%d ", root->val);
    }
};

Node* get_tree() {
    BST bst;
    Node* root = nullptr;
    root = bst.insert(root, 100);
    root = bst.insert(root, 50);
    root = bst.insert(root, 150);
    root = bst.insert(root, 25);
    root = bst.insert(root, 75);
    root = bst.insert(root, 125);
    root = bst.insert(root, 175);
    root = bst.insert(root, 15);
    root = bst.insert(root, 30);
    root = bst.insert(root, 165);
    root = bst.insert(root, 200);
    root = bst.insert(root, 10);
    root = bst.insert(root, 45);
    root = bst.insert(root, 300);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    return root;
}

inline void test_1() {
    BST bst;
    Node* root = get_tree();
    printf("----------------------------------------- pre order --------------------------------\n");
    bst.preorder(root);
    printf("------------------------------------------------------------------------------------\n");
    printf("----------------------------------------- in order ---------------------------------\n");
    bst.inorder(root);
    printf("------------------------------------------------------------------------------------\n");
    printf("----------------------------------------- post order -------------------------------\n");
    bst.postorder(root);
    printf("------------------------------------------------------------------------------------\n");
}

int main() {
    test_1();

    return 0;
}
