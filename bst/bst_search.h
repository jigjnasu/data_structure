/*
*   Rakesh Kumar
*   never stop learning
*   23/06/2021
*/
#ifndef DATA_STRUCTURE_BST_BST_SEARCH_H_
#define DATA_STRUCTURE_BST_BST_SEARCH_H_

#include "common.h"

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
    };
}
#endif // DATA_STRUCTURE_BST_BST_SEARCH_H_