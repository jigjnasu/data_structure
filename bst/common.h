/*
*   Rakesh Kumar
*   never stop learning
*   23/06/2021
*/
#ifndef DATA_STRUCTURE_BST_COMMON_H_
#define DATA_STRUCTURE_BST_COMMON_H_

struct Node {
    Node() {}
    Node(int val) : val(val) {}
    
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

#endif // DATA_STRUCTURE_BST_COMMON_H_