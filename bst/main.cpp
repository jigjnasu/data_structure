/*
* main file for testing all bst code
* never stop learning
* Rakesh Kumar 22/06/2021
*/

#include "bst.h"

Node* build_tree_1() {
    BST bst;
    std::vector<int> v = {100, 50, 150, 25, 75, 125, 175, 30, 45, 55, 65, 165, 185, 200, 15, 20, 10, 5, 1, 7, 9, 23, 180, 300};
    Node* root = nullptr;
    for (int e : v)
        root = bst.insert_iter(root, e);
    return root;
}

/*
* test the insertion and traversals of bst
*/
inline void test_insert_and_traversals() {
    Node* root = build_tree_1();
    BST bst;
    bst.bfs(root);
}

int main() {
    test_insert_and_traversals();

    return 0;
}

