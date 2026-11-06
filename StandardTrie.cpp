#include "StandardTrie.hpp"

using namespace std;

TrieNode::TrieNode() {}

StandardTrie::StandardTrie() {}
StandardTrie::~StandardTrie() {}


void StandardTrie::insert(const std::string& word) {}

// Node reached by following q from the root, or nullptr if q is absent.
TrieNode* StandardTrie::findPrefix(const std::string& q) {}

// True if word was inserted as a complete word (used for flag = 2).
bool StandardTrie::search(const std::string& word) {}

// All stored words that have q as a prefix (q itself included if stored).
std::vector<std::string> StandardTrie::autocomplete(const std::string& q) {}

long long StandardTrie::nodeCount() const {}
// 26 * nodeCount()
long long StandardTrie::spaceUnits() const {}   

long long StandardTrie::ops() const {
    return 0;
}
void StandardTrie::resetOps() {}

void collect(TrieNode* node, std::string& prefix, std::vector<std::string>& out) {}

void destroy(TrieNode* node) {}
