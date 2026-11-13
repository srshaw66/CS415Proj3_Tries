#include "TST.hpp"

using namespace std;

TSTNode::TSTNode(char ch) : c(ch), isEnd(false), left(nullptr), mid(nullptr), right(nullptr) {}

TST::TST();
TST::~TST();

void TST::insert(const string& word) {}

// Node holding the last character of q, or nullptr if q is absent.
TSTNode* TST::findPrefix(const string& q) {}

// True if word was inserted as a complete word (used for flag = 2).
bool TST::search(const string& word) {}

// All stored words that have q as a prefix (q itself included if stored).
vector<string> TST::autocomplete(const string& q) {}

long long TST::nodeCount() const {}
long long TST::spaceUnits() const {}   // 3 * nodeCount()

long long TST::ops() const {}
void TST::resetOps() {}
void TST::collect(TSTNode* node, string& prefix, vector<string>& out) {}
void TST::destroy(TSTNode* node) {}
