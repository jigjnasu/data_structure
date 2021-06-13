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

    int height(Node* root) {
        if (root == nullptr)
            return 0;
        int l = height(root->left) + 1;
        int r = height(root->right) + 1;
        return std::max(l, r);
    }

    int min(Node* root) {
        if (root == nullptr)
            throw("Please enter a valid root");
        Node* node = root;
        while (node->left)
            node = node->left;
        return node->val;
    }

    int max(Node* root) {
        if (root == nullptr)
            throw("Please enter a valid root");
        Node* node = root;
        while (node->right)
            node = node->right;
        return node->val;
    }

    int min_rec(Node* root) {
        if (root->left) return min_rec(root->left);
        return root->val;
    }

    int max_rec(Node* root) {
        if (root->right) return max_rec(root->right);
        return root->val;
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

Node* build_bst() {
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
    return root;
}

void test_insert() {
    BST bst;
    Node* root = build_bst();
    bst.bfs(root);
}

void test_height() {
    BST bst;
    Node* root = build_bst();
    printf("height == [%d]\n", bst.height(root));
}

void test_min_max() {
    BST bst;
    Node* root = build_bst();
    printf("minimum value == [%8d] || minimum recursive value == [%8d]\n", bst.min(root), bst.min_rec(root));
    printf("maximum value == [%8d] || maximum recursive value == [%8d]\n", bst.max(root), bst.max_rec(root));
}

int main() {
    test_insert();
    //test_height();
    test_min_max();

    return 0;
}
