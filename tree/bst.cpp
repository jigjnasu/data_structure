/*
 * Rakesh Kumar
 * Never stop learning
 * 17/06/2021
 */

#include <bits/stdc++.h>

struct Node {
    Node() {}
    Node(int val) : val(val) {}

    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

inline void print_vector(const std::vector<int>& v) {
    printf("---------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("---------------------------------------------------\n");
}

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

    void preorder(Node* root) {
        printf("%d ", root->val);
        if (root->left) preorder(root->left);
        if (root->right) preorder(root->right);
    }

    void inorder(Node* root) {
        if (root->left) inorder(root->left);
        printf("%d ", root->val);
        if (root->right) inorder(root->right);
    }

    void postorder(Node* root) {
        if (root->left) postorder(root->left);
        if (root->right) postorder(root->right);
        printf("%d ", root->val);
    }

    void bfs(Node* root) {
        printf("------------------------------------------------------------------------------------\n");
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
        printf("------------------------------------------------------------------------------------\n");
    }

    int height(Node* root) {
        if (root == nullptr) return 0;
        int l = height(root->left) + 1;
        int r = height(root->right) + 1;
        return std::max(l, r);
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

    std::vector<int> sort(Node* root, bool asc = true) {
        std::vector<int> res;
        if (asc)
            sort_asc(root, res);
        else
            sort_des(root, res);
        return res;
    }

private:
    void sort_asc(Node* node, std::vector<int>& v) {
        if (node == nullptr)
            return;
        sort_asc(node->left, v);
        v.emplace_back(node->val);
        sort_asc(node->right, v);
    }

    void sort_des(Node* node, std::vector<int>& v) {
        if (node == nullptr) 
            return;
        sort_des(node->right, v);
        v.emplace_back(node->val);
        sort_des(node->left, v);
    }
};

Node* get_tree() {
    BST bst;
    Node* root = nullptr;
    root = bst.insert(root, 100);
    root = bst.insert(root, 50);
    root = bst.insert(root, 150);
    root = bst.insert(root, 25);
    root = bst.insert(root, 75);
    root = bst.insert(root, 125);
    root = bst.insert(root, 175);
    root = bst.insert(root, 15);
    root = bst.insert(root, 30);
    root = bst.insert(root, 165);
    root = bst.insert(root, 200);
    root = bst.insert(root, 10);
    root = bst.insert(root, 45);
    root = bst.insert(root, 300);
    root = bst.insert(root, 5);
    root = bst.insert(root, 1);
    return root;
}

void print(const std::vector<int>& v) {
    printf("------------------------------------------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n------------------------------------------------------------------------------------\n");
}

inline void test_1() {
    BST bst;
    Node* root = get_tree();
    printf("----------------------------------------- pre order --------------------------------\n");
    bst.preorder(root);
    printf("------------------------------------------------------------------------------------\n");
    printf("----------------------------------------- in order ---------------------------------\n");
    bst.inorder(root);
    printf("------------------------------------------------------------------------------------\n");
    printf("----------------------------------------- post order -------------------------------\n");
    bst.postorder(root);
    printf("------------------------------------------------------------------------------------\n");
    bst.bfs(root);
    printf("height of tree == [%d]\n", bst.height(root));
    printf("min value of tree == [%d]\n", bst.min(root));
    printf("max value of tree == [%d]\n", bst.max(root));
}

inline void test_2() {
    BST bst;
    Node* root = get_tree();
    printf("SORTING --> Ascending\n");
    print(bst.sort(root, true));
    printf("SORTING --> Descending\n");
    print(bst.sort(root, false));
}

int main() {
    //test_1();
    test_2();

    return 0;
}
