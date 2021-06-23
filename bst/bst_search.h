/*
*   Rakesh Kumar
*   never stop learning
*   23/06/2021
*/
#ifndef DATA_STRUCTURE_BST_BST_SEARCH_H_
#define DATA_STRUCTURE_BST_BST_SEARCH_H_

#include "common.h"
#include <climits>
#include <cmath>

namespace BST_SEARCH {
    class BST {
    public:
        bool search_iter(Node* root, int k) {
            if (root) {
                Node* node = root;
                while (node) {
                    if (k == node->val)
                        return true;
                    if (k < node->val)
                        node = node->left;
                    else
                        node = node->right;
                }
            }
            return false;
        }

        bool search_rec(Node* root, int k) {
            if (root) {
                if (k == root->val) 
                    return true;
                if (k < root->val) 
                    return search_rec(root->left, k);
                else
                    return search_rec(root->right, k);
            }
            return false;
        }

        int search_nearest_iter(Node* root, int k) {
            int res = 0;
            int diff = INT_MAX;
            if (root) {
                Node* node = root;
                while (node) {
                    if (k == node->val)
                        return k;
                    if (std::abs(k - node->val) < diff) {
                        diff = std::abs(k - node->val);
                        res = node->val;
                    }
                    if (k < node->val)
                        node = node->left;
                    else
                        node = node->right;
                }
            }
            return res;
        }

        int search_nearest_rec(Node* root, int k, int diff = INT_MAX) {
            int res = 0;
            m_search_neartest_rec(root, k, res, INT_MAX);
            return res;
        }

        int min(Node* root) {
            while (root->left)
                root = root->left;
            return root->val;
        }

        int max(Node* root) {
            while (root->right)
                root = root->right;
            return root->val;
        }        

    private:
        void m_search_neartest_rec(Node* root, int k, int& res, int diff) {
            if (root) {
                if (k == root->val)
                    res = root->val;
                else {
                    if (std::abs(k - root->val) < diff) {
                        diff = std::abs(k - root->val);
                        res = root->val;
                    }
                    if (k < root->val)
                        m_search_neartest_rec(root->left, k, res, diff);
                    else
                        m_search_neartest_rec(root->right, k, res, diff);                    
                }
            }
        }
    };
}
#endif // DATA_STRUCTURE_BST_BST_SEARCH_H_