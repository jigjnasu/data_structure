/*
  Rakesh Kumar
  13/06/2021
  Never stop learning
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

    void bfs(Node* root) {
        printf("--------------------------------------------------\n");
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                root = q.front(); q.pop();
                printf("%d ", root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            printf("\n");
        }
        printf("--------------------------------------------------\n");
    }
};

void insert_test() {
    BST bst;
    Node* root = nullptr;
    root = bst.insert(root, 100);
    root = bst.insert(root, 50);
    root = bst.insert(root, 150);
    root = bst.insert(root, 25);
    root = bst.insert(root, 175);
    root = bst.insert(root, 75);
    root = bst.insert(root, 125);
    root = bst.insert(root, 20);
    root = bst.insert(root, 200);
    root = bst.insert(root, 10);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    bst.bfs(root);
}

int main() {
    insert_test();

    return 0;
}
