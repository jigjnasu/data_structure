/*
* main file for testing all bst code
* never stop learning
* Rakesh Kumar 22/06/2021
*/

#include "bst.h"
#include "bst_search.h"

inline void print(const std::vector<int>& v) {
    printf("----------------------------------------------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n----------------------------------------------------------------------------------------\n");
}

inline Node* get_tree() {
    BST::BST bst;
    std::vector<int> v = {100, 50, 150, 25, 75, 125, 175, 30, 45, 55, 65, 165, 185, 200, 15, 20, 10, 5, 1, 7, 9, 23, 180, 300};
    Node* root = nullptr;
    for (int e : v)
        root = bst.insert_iter(root, e);
    return root;
}

inline void test_bst_inserts() {
    BST::BST bst;
    Node* root1 = get_tree();
    Node* root2 = get_tree();
    bst.bfs(root1);
    bst.bfs(root2);
}

inline void test_bst_traversals() {
    BST::BST bst;
    Node* root = get_tree();
    bst.bfs(root);
    printf("------------------------------------ pre order -----------------------------------------\n");
    bst.preorder(root);
    printf("\n");
    print(bst.preorder_data(root));
    printf("------------------------------------ in order ------------------------------------------\n");
    bst.inorder(root);
    printf("\n");
    print(bst.inorder_data(root));
    printf("------------------------------------- post order ----------------------------------------\n");
    bst.postorder(root);
    printf("\n");
    print(bst.postorder_data(root));
}

/*
    Let's now do some search in the bst for targets, closest, farthest, min and max etc...
*/
inline void test_bst_search() {
    BST::BST bst;
    BST_SEARCH::BST bsts;
    Node* root = get_tree();
    bst.bfs(root);
    int k = 199;
    printf("[%8d] is in tree == [%d]\n", k, bsts.search_iter(root, k));
    k = 125; printf("[%8d] is in tree == [%d]\n", k, bsts.search_iter(root, k));
    k = 180; printf("[%8d] is in tree == [%d]\n", k, bsts.search_iter(root, k));
    k = 179; printf("[%8d] is in tree == [%d]\n", k, bsts.search_iter(root, k));
    k = -91; printf("[%8d] is in tree == [%d]\n", k, bsts.search_iter(root, k));
    k = -23; printf("[%8d] is in tree == [%d]\n", k, bsts.search_iter(root, k));
    k = 23;  printf("[%8d] is in tree == [%d]\n", k, bsts.search_iter(root, k));
}

int main() {
    //test_bst_inserts();
    //test_bst_traversals();
    test_bst_search();

    return 0;
}
