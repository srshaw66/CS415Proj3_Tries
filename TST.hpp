#ifndef TST_HPP
#define TST_HPP

#include <string>
#include <vector>

using namespace std;

struct TSTNode {
    char character;
    bool isWordEnd;
    TSTNode* left;
    TSTNode* mid;
    TSTNode* right;

    explicit TSTNode(char ch);
};

class TST {
public:
    TST();
    ~TST() { destroy(root); }

    TST(TST&) = delete;
    TST& operator=(TST&) = delete;

    void insert(string& word);

    TSTNode* findPrefix(string& prefix);

    bool search(string& word);

    vector<string> autocomplete(string& prefix);

    long long nodeCount();

    long long spaceUnits();

    long long ops();

    void resetOps();

private:
    TSTNode* root;
    long long totalNodes;
    long long opCount;

    void collectWords(TSTNode* node, string& currentPrefix,
vector<string>& results);
    void destroy(TSTNode* node);
};

#endif
