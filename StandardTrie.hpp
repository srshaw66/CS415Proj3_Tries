#ifndef STANDARD_TRIE_HPP
#define STANDARD_TRIE_HPP

#include <string>
#include <vector>

using namespace std;

enum { ALPHABET_SIZE = 26 };

struct TrieNode {
    TrieNode* child[ALPHABET_SIZE];
    bool isEnd;

    TrieNode();
};

class StandardTrie {
public:
    StandardTrie();
    ~StandardTrie();

    StandardTrie(StandardTrie&) = delete;
    StandardTrie& operator=(StandardTrie&) = delete;

    void insert(string& word);

    TrieNode* findPrefix(string& q);

    bool search(string& word);

    vector<string> autocomplete(string& q);

    long long nodeCount();

    long long spaceUnits();

    long long ops();

    void resetOps();

private:
    TrieNode* root;
    long long nodes;
    long long opCount;

    void collect(TrieNode* node, string& prefix, vector<string>& out);
    void destroy(TrieNode* node);
};

#endif
