#include "debug.hpp"
#include "StandardTrie.hpp"
#include "TST.hpp"

#include <iostream>
#include <string>

using namespace std;

static void displayNode(const TrieNode *node, const string& name, int depth) {
    cout << string(depth * 2, ' ') << name << " (" << node << "):";

    bool hasChild = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->child[i] != nullptr) {
            cout << " [" << i << "] " << static_cast<char>('a' + i)
                 << " -> " << node->child[i];
            hasChild = true;
        }
    }

    if (!hasChild) {
        cout << " no children";
    }
    cout << '\n';

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->child[i] != nullptr) {
            string childName = "Node via '";
            childName += static_cast<char>('a' + i);
            childName += "'";
            displayNode(node->child[i], childName, depth + 1);
        }
    }
}

static void displayTSTNode(const TSTNode *node, const string& name, int depth) {
    cout << string(depth * 2, ' ') << name
         << " ('" << node->c << "', " << node << "):";

    bool hasChild = false;
    const TSTNode *children[] = {node->left, node->mid, node->right};
    const char* names[] = {"left", "mid", "right"};

    for (int i = 0; i < 3; ++i) {
        if (children[i] != nullptr) {
            cout << " " << names[i] << " -> " << children[i];
            hasChild = true;
        }
    }

    if (!hasChild) {
        cout << " no children";
    }
    cout << '\n';

    if (node->left != nullptr) {
        displayTSTNode(node->left, "Left", depth + 1);
    }
    if (node->mid != nullptr) {
        displayTSTNode(node->mid, "Middle", depth + 1);
    }
    if (node->right != nullptr) {
        displayTSTNode(node->right, "Right", depth + 1);
    }
}

void Display(StandardTrie& trie) {
    TrieNode *head = trie.findPrefix("");

    if (head == nullptr) {
        cout << "The trie has no head node.\n";
        return;
    }

    displayNode(head, "Head node", 0);
}

void Display(const TST& tst) {
    const TSTNode *head = tst.rootNode();

    if (head == nullptr) {
        cout << "The TST has no head node.\n";
        return;
    }

    displayTSTNode(head, "TST head node", 0);
}
