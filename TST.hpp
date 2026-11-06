#ifndef TST_HPP
#define TST_HPP

#include <string>
#include <vector>

struct TSTNode {
    char c;
    bool isEnd;
    TSTNode* left;
    TSTNode* mid;
    TSTNode* right;

    explicit TSTNode(char ch);
};

// BST-based Trie (Ternary Search Tree). Space = 3 * nodeCount() pointer units.
// Operation counting rules (see report):
//   +1 per character comparison with a TST node (one 3-way compare = 1)
//   +1 per node created, +1 per pointer assigned
//   +1 per word-ending marker checked or updated
//   autocomplete: +1 per child node inspected during traversal
class TST {
public:
    TST();
    ~TST();

    TST(const TST&) = delete;
    TST& operator=(const TST&) = delete;

    void insert(const std::string& word);

    // Node holding the last character of q, or nullptr if q is absent.
    TSTNode* findPrefix(const std::string& q);

    // True if word was inserted as a complete word (used for flag = 2).
    bool search(const std::string& word);

    // All stored words that have q as a prefix (q itself included if stored).
    std::vector<std::string> autocomplete(const std::string& q);

    long long nodeCount() const;
    long long spaceUnits() const;   // 3 * nodeCount()

    long long ops() const;
    void resetOps();

private:
    TSTNode* root;
    long long nodes;
    long long opCount;

    void collect(TSTNode* node, std::string& prefix, std::vector<std::string>& out);
    void destroy(TSTNode* node);
};

#endif
