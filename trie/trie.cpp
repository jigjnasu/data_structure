/*
  Trie DS for strings
  Trying to add as many functionalities I can
  Rakesh Kumar
 */

#include <bits/stdc++.h>

const int ABC = 26;

struct Node {
    Node* children[26] = {nullptr};
    int count = 0;
};

/*
  right now it will only handle small letrers, later I will add full features.
 */
class Trie {
public:
    void insert(const std::string& word) {
        int index = 0;
        Node* node = root;
        for (char c : word) {
            index = c - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new Node;
            node = node->children[index];
        }
        ++node->count;
    }

    bool search(const std::string& word) {
        int index = 0;
        Node* node = root;
        for (char c : word) {
            index = c - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return node->count > 0;
    }

    std::vector<std::string> search_with(const std::string& word) {
        int index = 0;
        Node* node = root;
        std::vector<std::string> results;
        for (char c : word) {
            index = c - 'a';
            if (node->children[index] == nullptr)
                break;
            node = node->children[index];
        }
        std::string s(256, ' ');
        grab(node, s, 0, results);
        return results;
    }

    void show() {
        std::string s(256, ' ');
        mshow(root, s, 0);
    }

private:
    Node* root = new Node;

    void mshow(Node* node, std::string& s, int level) {
        if (node->count > 0) {
            s[level] = '\0';
            printf("%s\n", s.c_str());
            return;
        }

        for (int i = 0; i < ABC; ++i) {
            if (node->children[i] != nullptr) {
                s[level] = i + 'a';
                mshow(node->children[i], s, level + 1);
            }
        }
    }

    void grab(Node* node, std::string& s, int level, std::vector<std::string>& results) {
        if (node->count > 0) {
            results.emplace_back(s);
        }

        for (int i = 0; i < ABC; ++i) {
            if (node->children[i] != nullptr) {
                s[level] = i + 'a';
                grab(node->children[i], s, level + 1, results);
            }
        }
    }
};

const std::vector<std::string> names = {"adwita", "atharv", "ajay", "anil",
                                        "anoop", "arvind", "arun", "ananya",
                                        "abhay", "babita"};


inline void print(const std::vector<std::string>& v) {
    printf("--------------------------------------------------------------\n");
    for (auto& w : v)
        printf("%s\n", w.c_str());
    printf("--------------------------------------------------------------\n");
}

void test_search() {
    Trie t;
    for (auto& n : names)
        t.insert(n);
    t.show();
    for (auto& n : names)
        assert(t.search(n) == true);
    assert(t.search("adw") == false);
    assert(t.search("adwitaa") == false);
}

void test_search_with() {
    Trie t;
    for (auto& n : names)
        t.insert(n);
    printf("----------------------------------------\n");
    t.show();
    printf("----------------------------------------\n");
    print(t.search_with("an"));
}

int main() {
    test_search();
    test_search_with();

    return 0;
}
