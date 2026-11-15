#include "tests.hpp"

#include "Normalizer.hpp"
#include "StandardTrie.hpp"
#include "TST.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static void printResults(vector<string>& results) {
    if (results.empty()) {
        cout << "(none)";
        return;
    }

    for (size_t i = 0; i < results.size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << results[i];
    }
}

static void printBuildResults(StandardTrie& trie, TST& tst,
long long standardBuildOps, long long tstBuildOps) {
    cout << "Time taken to build the standard Trie is "
       << standardBuildOps
       << " operations and space occupied by it is "
       << trie.spaceUnits() << " pointer units" << endl;

    cout << "Time taken to build the BST based Trie is "
       << tstBuildOps
       << " operations and space occupied by it is "
       << tst.spaceUnits() << " pointer units" << endl;
}

static void runQueryCase(StandardTrie& trie, TST& tst) {
    string query;

    while (true) {
        cout << endl << "Enter search string: ";
        if (!(cin >> query)) {
            break;
        }
        query = normalize(query);

        trie.resetOps();
        trie.search(query);
        long long standardSearchOps = trie.ops();

        trie.resetOps();
        vector<string> standardResults = trie.autocomplete(query);
        long long standardAutocompleteOps = trie.ops();

        tst.resetOps();
        tst.search(query);
        long long tstSearchOps = tst.ops();

        tst.resetOps();
        vector<string> tstResults = tst.autocomplete(query);
        long long tstAutocompleteOps = tst.ops();

        cout << "Time taken to search in the standard Trie is "
       << standardSearchOps << " operations" << endl;
        cout << "Auto-complete results using standard Trie are: ";
        printResults(standardResults);
        cout << endl;
        cout << "Time taken to find auto-complete results in the standard Trie is "
       << standardAutocompleteOps << " operations" << endl << endl;

        cout << "Time taken to search in the BST based Trie is "
       << tstSearchOps << " operations" << endl;
        cout << "Auto-complete results using BST based Trie are: ";
        printResults(tstResults);
        cout << endl;
        cout << "Time taken to find auto-complete results in the BST based Trie is "
       << tstAutocompleteOps << " operations" << endl;
    }
}

static void runSearchAllCase(StandardTrie& trie, TST& tst,
vector<string>& wordsInput) {
    trie.resetOps();
    for (string& word : wordsInput) {
        trie.search(word);
    }
    long long standardSearchAllOps = trie.ops();

    tst.resetOps();
    for (string& word : wordsInput) {
        tst.search(word);
    }
    long long tstSearchAllOps = tst.ops();

    cout << "Time taken to search all the strings in the standard Trie is "
       << standardSearchAllOps << " operations" << endl;
    cout << "Time taken to search all the strings in the BST based Trie is "
       << tstSearchAllOps << " operations" << endl;
}

void runTests(vector<string>& wordsInput, int flag) {
    StandardTrie trie;
    TST tst;

    for (string& word : wordsInput) {
        trie.insert(word);
        tst.insert(word);
    }

    long long standardBuildOps = trie.ops();
    long long tstBuildOps = tst.ops();

    printBuildResults(trie, tst, standardBuildOps, tstBuildOps);

    if (flag == 1) {
        runQueryCase(trie, tst);
    } else {
        runSearchAllCase(trie, tst, wordsInput);
    }
}
