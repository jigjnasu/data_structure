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

    bool find(Node* root, int k) {
        if (root) {
            Node* node = root;
            while (node) {
                if (node->val == k)
                    return true;
                if (k < node->val)
                    node = node->left;
                else
                    node = node->right;
            }
        }
        return false;
    }

    int find_nearest(Node* root, int k) {
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

    int find_farthest(Node* root, int k) {
        int res = 0;
        int diff = INT_MIN;
        if (root) {
            Node* node = root;
            while (node) {
                if (k == node->val)
                    return k;
                if (std::abs(k - node->val) > diff) {
                    diff = std::abs(k - node->val);
                    res = node->val;
                }
                if (k < node->val)
                    node = node->right;
                else
                    node = node->left;
            }
        }
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

inline void test_3() {
    BST bst;
    Node* root = get_tree();
    int k = 199;
    printf("[%8d] found in tree == [%d]\n", k, static_cast<bool>(bst.find(root, k)));
    k = 1;
    printf("[%8d] found in tree == [%d]\n", k, static_cast<bool>(bst.find(root, k)));
    k = 5;
    printf("[%8d] found in tree == [%d]\n", k, static_cast<bool>(bst.find(root, k)));
}

/*
    nearest and farthest neighbours
*/
inline void test_4() {
    BST bst;
    Node* root = get_tree();
    int k = 199;
    printf("[%8d] nearest  found in tree == [%8d]\n", k, bst.find_nearest(root, k));
    printf("[%8d] farthest found in tree == [%8d]\n", k, bst.find_farthest(root, k));
    k = -10;
    printf("[%8d] nearest  found in tree == [%8d]\n", k, bst.find_nearest(root, k));
    printf("[%8d] farthest found in tree == [%8d]\n", k, bst.find_farthest(root, k));
    k = 59;
    printf("[%8d] nearest  found in tree == [%8d]\n", k, bst.find_nearest(root, k));
    printf("[%8d] farthest found in tree == [%8d]\n", k, bst.find_farthest(root, k));
}

int main() {
    //test_1();
    //test_2();
    //test_3();
    test_4();

    return 0;
}
