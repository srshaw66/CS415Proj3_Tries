#include "TST.hpp"

using namespace std;

TSTNode::TSTNode(char ch) {
    character = ch;
    isWordEnd = false;
    left = nullptr;
    mid = nullptr;
    right = nullptr;
}

TST::TST() {
    root = nullptr;
    totalNodes = 0;
    opCount = 0;
}


void TST::insert(string& word) {
    if (word.empty()) {
        return;
    }

    TSTNode** branchPointer = &root;
    size_t charIndex = 0;

    while (true) {
        if (*branchPointer == nullptr) {
            *branchPointer = new TSTNode(word[charIndex]);
            totalNodes++;
            opCount += 2;
        }
        TSTNode* curNode = *branchPointer;
        opCount++;

        if (word[charIndex] < curNode->character) {
            branchPointer = &curNode->left;
        } else if (word[charIndex] > curNode->character) {
            branchPointer = &curNode->right;
        } else {
            if (charIndex == word.size() - 1) {
                curNode->isWordEnd = true;
                opCount++;
                return;
            }
            charIndex++;
            branchPointer = &curNode->mid;
        }
    }
}


TSTNode* TST::findPrefix(string& prefix) {
    if (prefix.empty()) {
        return nullptr;
    }

    TSTNode* node = root;
    size_t charIndex = 0;

    while (node != nullptr) {
        opCount++;

        if (prefix[charIndex] < node->character) {
            node = node->left;
        } else if (prefix[charIndex] > node->character) {
            node = node->right;
        } else {
            if (charIndex == prefix.size() - 1) {
                return node;
            }
            charIndex++;
            node = node->mid;
        }
    }
    return nullptr;
}

bool TST::search(string& word) {
    TSTNode* node = findPrefix(word);

    if (node == nullptr) {
        return false;
    }

    opCount++;
    return node->isWordEnd;
}

vector<string> TST::autocomplete(string& prefix) {
    vector<string> results;

    if (prefix.empty()) {
        string currentPrefix;
        collectWords(root, currentPrefix, results);
        return results;
    }

    TSTNode* node = findPrefix(prefix);

    if (node == nullptr) {
        return results;
    }

    string currentPrefix = prefix;
    opCount++;

    if (node->isWordEnd) {
        results.push_back(currentPrefix);
    }

    collectWords(node->mid, currentPrefix, results);
    return results;
}

long long TST::nodeCount() {
    return totalNodes;
}

long long TST::spaceUnits() {
    return 3 * nodeCount();
}

long long TST::ops() {
    return opCount;
}

void TST::resetOps() {
    opCount = 0;
}

void TST::collectWords(TSTNode* node, string& currentPrefix,
vector<string>& results) {
    if (node == nullptr) {
        return;
    }

    opCount++;

    collectWords(node->left, currentPrefix, results);
    currentPrefix += node->character;
    opCount++;

    if (node->isWordEnd) {
        results.push_back(currentPrefix);
    }
    collectWords(node->mid, currentPrefix, results);
    currentPrefix.pop_back();
    collectWords(node->right, currentPrefix, results);
}

void TST::destroy(TSTNode* node) {
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->mid);
    destroy(node->right);
    delete node;
}
