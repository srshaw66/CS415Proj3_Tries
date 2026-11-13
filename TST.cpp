#include "TST.hpp"

using namespace std;

TSTNode::TSTNode(char ch) {
    c = ch;
    isEnd = false;
    left = nullptr;
    mid = nullptr;
    right = nullptr;
}

TST::TST() {
    root = nullptr;
    nodes = 0;
    opCount = 0;
}

TST::~TST() {
    destroy(root);
}

void TST::insert(const string& word) {
    /*if word is empty: return
    link ← the root pointer itself     (a reference to the pointer, not the node)
    i ← 0
    loop:
        if link is NULL:
            link ← new TSTNode(word[i])
            nodes += 1;  opCount += 2              create + assign
        node ← link
        opCount += 1                               compare word[i] with node.c
        if word[i] < node.c:   link ← node.left
        elif word[i] > node.c: link ← node.right
        else:                                      match
            if i is the last index:
                node.isEnd ← true;  opCount += 1;  return
            i += 1
            link ← node.mid*/

    if (word.empty()) {
        return;
    }
    TSTNode** link = &root;
    size_t i = 0;
    while (true) {
        if (*link == nullptr) {
            *link = new TSTNode(word[i]);
            nodes++;
            opCount += 2;
        }
        TSTNode* node = *link;
        opCount++;
        if (word[i] < node->c) {
            link = &node->left;
        } else if (word[i] > node->c) {
            link = &node->right;
        } else {
            if (i == word.size() - 1) {
                node->isEnd = true;
                opCount++;
                return;
            }
            i++;
            link = &node->mid;
        }
    }
}


// Node holding the last character of q, or nullptr if q is absent.
TSTNode* TST::findPrefix(const string& q) {
    /*if q is empty: return NULL
    node ← root;  i ← 0
    while node is not NULL:
        opCount += 1                               compare q[i] with node.c
        if q[i] < node.c:   node ← node.left
        elif q[i] > node.c: node ← node.right
        else:
            if i is the last index: return node
            i += 1
            node ← node.mid
    return NULL*/
    if (q.empty()) {
        return nullptr;
    }
    TSTNode* node = root;
    size_t i = 0;
    while (node != nullptr) {
        opCount++;
        if (q[i] < node->c) {
            node = node->left;
        } else if (q[i] > node->c) {
            node = node->right;
        } else {
            if (i == q.size() - 1) {
                return node;
            }
            i++;
            node = node->mid;
        }
    }
    return nullptr;
}

const TSTNode* TST::rootNode() const {
    return root;
}

// True if word was inserted as a complete word (used for flag = 2).
bool TST::search(const string& word) {
    TSTNode* node = findPrefix(word);
    if (node == nullptr) {
        return false;
    }

    opCount++;
    return node->isEnd;
}

// All stored words that have q as a prefix (q itself included if stored).
vector<string> TST::autocomplete(const string& q) {
    /*autocomplete(q):
    if q is empty:
        collect(root, "", out)
        return out
    node ← findPrefix(q)
    if node is NULL: return empty
    opCount += 1                               check end marker
    if node.isEnd: append q to out
    collect(node.mid, q, out)
    return out
    */
    vector<string> out;

    if (q.empty()) {
        string prefix;
        collect(root, prefix, out);
        return out;
    }

    TSTNode* node = findPrefix(q);
    if (node == nullptr) {
        return out;
    }

    string prefix = q;
    opCount++; // check end marker
    if (node->isEnd) {
        out.push_back(prefix);
    }

    collect(node->mid, prefix, out);
    return out;
}

long long TST::nodeCount() const {
    return nodes;
}
long long TST::spaceUnits() const {
    return 3 * nodeCount();
}

long long TST::ops() const {
    return opCount;
}
void TST::resetOps() {
    opCount = 0;
}

// in-order traversal = alphabetical output
void TST::collect(TSTNode* node, string& prefix, vector<string>& out) {
    /*if node is NULL: return
    opCount += 1                                   inspect this node
    collect(node.left, prefix, out)
    append node.c to prefix
    opCount += 1                                   check end marker
    if node.isEnd: append prefix to out
    collect(node.mid, prefix, out)
    remove last char from prefix
    collect(node.right, prefix, out)*/
    if (node == nullptr) {
        return;
    }
    opCount++;
    collect(node->left, prefix, out);
    prefix += node->c;
    opCount++;
    if (node->isEnd) {
        out.push_back(prefix);
    }
    collect(node->mid, prefix, out);
    prefix.pop_back();
    collect(node->right, prefix, out);
}
// post-order 
void TST::destroy(TSTNode* node) {
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->mid);
    destroy(node->right);
    delete node;
}
