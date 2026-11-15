#include "StandardTrie.hpp"

using namespace std;

TrieNode::TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        child[i] = nullptr;
    }
    isEnd = false;
}

StandardTrie::StandardTrie() {
    root = new TrieNode();
    nodes = 1;
    opCount = 0;
}

StandardTrie::~StandardTrie() {
    destroy(root);
}


void StandardTrie::insert(std::string& word) {
    TrieNode* node = root;
    for (char character : word) {
        int i = character - 'a';
        opCount++;

        if (node->child[i] == nullptr) {
            node->child[i] = new TrieNode();
            nodes++;
            opCount = opCount + 2;
        }
        node = node->child[i];
    }
    node->isEnd = true;
    opCount++;
}

TrieNode* StandardTrie::findPrefix(std::string& q) {
    TrieNode* node = root;
    for (char character : q) {
        int i = character - 'a';
        opCount++;

        if (node->child[i] == nullptr) {
            return nullptr;
        }
        node = node->child[i];
    }
    return node;
}

bool StandardTrie::search(std::string& word) {
    TrieNode* node = findPrefix(word);

    if (node == nullptr) {
        return false;
    }
    opCount++;
    return node->isEnd;
}

std::vector<std::string> StandardTrie::autocomplete(std::string& q) {
    TrieNode* node = findPrefix(q);
    string s = q;

    if (node == nullptr) {
        return {};
    }
    std::vector<std::string> out;
    collect(node, s, out);
    return out;
}

long long StandardTrie::nodeCount() {
    return nodes;
}

long long StandardTrie::spaceUnits() {
    return 26 * nodeCount();
}

long long StandardTrie::ops() {
    return opCount;
}

void StandardTrie::resetOps() {
    opCount = 0;
}

void StandardTrie::collect(TrieNode* node, std::string& prefix,
std::vector<std::string>& out) {
    opCount++;

    if (node->isEnd) {
        out.push_back(prefix);
    }

    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
        opCount++;

        if (node->child[i] != nullptr) {
            prefix.push_back(static_cast<char>('a' + i));
            collect(node->child[i], prefix, out);
            prefix.pop_back();
        }
    }
}

void StandardTrie::destroy(TrieNode* node) {
    if (node == nullptr) {
        return;
    }

    for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
        destroy(node->child[i]);
    }
    delete node;
}
