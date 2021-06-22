/*
* main file for testing all bst code
* never stop learning
* Rakesh Kumar 22/06/2021
*/

#include "bst.h"

inline void test_bst_inserts() {
    BST bst;
    std::vector<int> v = {100, 50, 150, 25, 75, 125, 175, 30, 45, 55, 65, 165, 185, 200, 15, 20, 10, 5, 1, 7, 9, 23, 180, 300};
    Node* root1 = nullptr;
    Node* root2 = nullptr;
    for (int e : v) {
        root1 = bst.insert_iter(root1, e);
        root2 = bst.insert_rec(root2, e);
    }
    bst.bfs(root1);
    bst.bfs(root2);
}

int main() {
    test_bst_inserts();

    return 0;
}

