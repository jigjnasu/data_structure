/*
*   Rakesh Kumar
*   never stop learning
*   22/06/2021
*/
#ifndef DATA_STRUCTURE_BST_BST_H_
#define DATA_STRUCTURE_BST_BST_H_

#include <cstdio>
#include <queue>
#include <vector>

/*
*   this file will just provide a base functions like insert
*   and traversals
*/

struct Node {
    Node() {}
    Node(int val) : val(val) {}
    
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BST {
public:
    Node* insert_rec(Node* root, int val) {
        if (root == nullptr)
            root = new Node(val);
        if (val < root->val)
            root->left = insert_rec(root->left, val);
        else
            root->right = insert_rec(root->right, val);
        return root;
    }

    Node* insert_iter(Node* root, int val) {
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
        printf("-------------------------------------------------------------------\n");
        printf("                          BFS of BST\n");
        if (root) {
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
        }
        printf("-------------------------------------------------------------------\n");
    }
};
#endif //DATA_STRUCTURE_BST_BST_H_