/*
 * Rakesh Kumar
 * Never stop learning
 * 14/06/2021
 */

#include <bits/stdc++.h>

struct Node {
    Node() {}
    Node(int val) : val(val) {}

    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

class Tree {
public:
    void bfs(Node* root) {
        printf("--------------------------------------------\n");
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
        printf("--------------------------------------------\n");
    }
};

Node* build_tree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(9);
    root->left->left->right = new Node(5);
    root->left->right->left = new Node(2);
    root->right->left->left = new Node(3);
    root->right->right->right = new Node(10);
    root->left->left->left->left = new Node(10);
    root->left->left->left->left->left = new Node(2);
    root->right->right->right->right = new Node(20);

    return root;
}

void test_bfs() {
    Node* root = build_tree();
    Tree t;
    t.bfs(root);
}

int main() {
    test_bfs();

    return 0;
}
