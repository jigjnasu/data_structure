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
        else {
            if (val < root->val)
                root->left = insert_rec(root->left, val);
            else
                root->right = insert_rec(root->right, val);
        }
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

    void preorder(Node* root) {
        if (root == nullptr) return;
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
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

    std::vector<int> preorder_data(Node* root) {
        std::vector<int> res;
        m_preorder_data(root, res);
        return res;
    }

    std::vector<int> inorder_data(Node* root) {
        std::vector<int> res;
        m_inorder_data(root, res);
        return res;
    }

    std::vector<int> postorder_data(Node* root) {
        std::vector<int> res;
        m_postorder_data(root, res);
        return res;
    }

private:
    void m_preorder_data(Node* root, std::vector<int>& res) {
        if (root == nullptr) return;
        res.emplace_back(root->val);
        m_preorder_data(root->left, res);
        m_preorder_data(root->right, res);
    }

    void m_inorder_data(Node* root, std::vector<int>& res) {
        if (root == nullptr) return;
        m_inorder_data(root->left, res);
        res.emplace_back(root->val);
        m_inorder_data(root->right, res);
    }

    void m_postorder_data(Node* root, std::vector<int>& res) {
        if (root == nullptr) return;
        m_postorder_data(root->left, res);
        m_postorder_data(root->right, res);
        res.emplace_back(root->val);
    }
};
#endif //DATA_STRUCTURE_BST_BST_H_