#include "StandardTrie.hpp"


using namespace std;

TrieNode::TrieNode() {
    // loop through the trie and set every child to nullptr
    for (int i = 0; i < ALPHABET_SIZE; i++) {
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


void StandardTrie::insert(const std::string& word) {
    /*insert(word):
    node ← root
    for each char ch in word:
        i ← ch - 'a'
        inspect node.child[i]                       (+1)
        if node.child[i] is NULL:
            node.child[i] ← new TrieNode            (+1 create, +1 assign)
        node ← node.child[i]
    set node.isEnd ← true                           (+1)*/
    TrieNode* node = root;
    for (char c : word) {
        int i = c - 'a';
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

// Node reached by following q from the root, or nullptr if q is absent.
TrieNode* StandardTrie::findPrefix(const std::string& q) {
    /*findPrefix(q):
    node ← root
    for each ch in q:
        inspect node.child[ch - 'a']                (+1)
        if NULL: return NULL
        node ← that child
    return node*/
    TrieNode *node = root;
    for (char c :  q) {
        int i = c - 'a';
        opCount++;
        if (node->child[i] == nullptr) {
            return nullptr;
        }
        node = node->child[i];
    }
    return node;
}

// True if word was inserted as a complete word (used for flag = 2).
bool StandardTrie::search(const std::string& word) {
    /*node ← findPrefix(word)
    if node is NULL: return false
    opCount += 1                               check end marker
    return node.isEnd
*/
    TrieNode *node = findPrefix(word);
    if(node == nullptr) {
        return false;
    }
    opCount++;
    return node->isEnd;
}

// All stored words that have q as a prefix (q itself included if stored).
std::vector<std::string> StandardTrie::autocomplete(const std::string& q) {
    /*autocomplete(q):
    node ← findPrefix(q);  if NULL return empty
    collect(node, q, out);  return out
*/
    TrieNode *node = findPrefix(q);
    string s = q;
    if (node == nullptr) {return {};}
    std::vector<std::string> out;
    collect(node, s, out);
    return out;
}

long long StandardTrie::nodeCount() const {
    return nodes;
}
// 26 * nodeCount()
long long StandardTrie::spaceUnits() const {
    return 26 * nodeCount();
}   

long long StandardTrie::ops() const {
    return opCount;
}
void StandardTrie::resetOps() {
    opCount = 0;
}

void StandardTrie::collect(TrieNode* node, std::string& prefix, std::vector<std::string>& out) {
    /*opCount += 1                               check end marker
    if node.isEnd:
        append prefix to out
    for i in 0..25:
        opCount += 1                           inspect slot (NULL ones too)
        if node.child[i] is not NULL:
            append letter ('a' + i) to prefix
            collect(node.child[i], prefix, out)
            remove last letter from prefix     backtrack*/
    opCount++;
    if (node->isEnd) {
        out.push_back(prefix);
    }
    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
        opCount++;
        if (node->child[i] != nullptr) {
            prefix.push_back('a' + i);
            collect(node->child[i], prefix, out);
            prefix.pop_back();
        }
    }
}

void StandardTrie::destroy(TrieNode* node) {
    if (node == nullptr) {return;}
    // post order destroy, children first. 
    for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
        destroy(node->child[i]);
    }
    delete node;
}
