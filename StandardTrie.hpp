#ifndef STANDARD_TRIE_HPP
#define STANDARD_TRIE_HPP

#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* child[ALPHABET_SIZE];
    bool isEnd;

    TrieNode();
};

// Array-based Trie. Space = 26 * nodeCount() pointer units.
// Operation counting rules (see report):
//   +1 per child array position inspected (including NULL slots in autocomplete)
//   +1 per node created, +1 per pointer assigned
//   +1 per word-ending marker checked or updated
class StandardTrie {
public:
    StandardTrie();
    ~StandardTrie();

    StandardTrie(const StandardTrie&) = delete;
    StandardTrie& operator=(const StandardTrie&) = delete;

    void insert(const std::string& word);

    // Node reached by following q from the root, or nullptr if q is absent.
    TrieNode* findPrefix(const std::string& q);

    // True if word was inserted as a complete word (used for flag = 2).
    bool search(const std::string& word);

    // All stored words that have q as a prefix (q itself included if stored).
    std::vector<std::string> autocomplete(const std::string& q);

    long long nodeCount() const;
    long long spaceUnits() const;   // 26 * nodeCount()

    long long ops() const;
    void resetOps();

private:
    TrieNode* root;
    long long nodes;
    long long opCount;

    void collect(TrieNode* node, std::string& prefix, std::vector<std::string>& out);
    void destroy(TrieNode* node);
};

#endif
