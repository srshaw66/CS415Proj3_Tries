#include "tests.hpp"

#include "Normalizer.hpp"
#include "StandardTrie.hpp"
#include "TST.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static void printResults(const vector<string>& results) {
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

static void printBuildResults(const StandardTrie& trie,
                              const TST& tst,
                              long long standardBuildOps,
                              long long tstBuildOps) {
    cout << "Time taken to build the standard Trie is "
         << standardBuildOps
         << " operations and space occupied by it is "
         << trie.spaceUnits() << " pointer units\n";

    cout << "Time taken to build the BST based Trie is "
         << tstBuildOps
         << " operations and space occupied by it is "
         << tst.spaceUnits() << " pointer units\n";
}

static void runQueryCase(StandardTrie& trie, TST& tst) {
    string query;

    while (true) {
        cout << "\nEnter search string: ";
        if (!(cin >> query)) {
            break;
        }
        query = normalize(query);

        trie.resetOps();
        trie.search(query);
        const long long standardSearchOps = trie.ops();

        trie.resetOps();
        const vector<string> standardResults = trie.autocomplete(query);
        const long long standardAutocompleteOps = trie.ops();

        tst.resetOps();
        tst.search(query);
        const long long tstSearchOps = tst.ops();

        tst.resetOps();
        const vector<string> tstResults = tst.autocomplete(query);
        const long long tstAutocompleteOps = tst.ops();

        cout << "Time taken to search in the standard Trie is "
             << standardSearchOps << " operations\n";
        cout << "Auto-complete results using standard Trie are: ";
        printResults(standardResults);
        cout << '\n';
        cout << "Time taken to find auto-complete results in the standard Trie is "
             << standardAutocompleteOps << " operations\n\n";

        cout << "Time taken to search in the BST based Trie is "
             << tstSearchOps << " operations\n";
        cout << "Auto-complete results using BST based Trie are: ";
        printResults(tstResults);
        cout << '\n';
        cout << "Time taken to find auto-complete results in the BST based Trie is "
             << tstAutocompleteOps << " operations\n";
    }
}

static void runSearchAllCase(StandardTrie& trie,
                             TST& tst,
                             const vector<string>& wordsInput) {
    trie.resetOps();
    for (const string& word : wordsInput) {
        trie.search(word);
    }
    const long long standardSearchAllOps = trie.ops();

    tst.resetOps();
    for (const string& word : wordsInput) {
        tst.search(word);
    }
    const long long tstSearchAllOps = tst.ops();

    cout << "Time taken to search all the strings in the standard Trie is "
         << standardSearchAllOps << " operations\n";
    cout << "Time taken to search all the strings in the BST based Trie is "
         << tstSearchAllOps << " operations\n";
}

void runTests(const vector<string>& wordsInput, int flag) {
    StandardTrie trie;
    TST tst;

    for (const string& word : wordsInput) {
        trie.insert(word);
        tst.insert(word);
    }

    const long long standardBuildOps = trie.ops();
    const long long tstBuildOps = tst.ops();

    printBuildResults(trie, tst, standardBuildOps, tstBuildOps);

    if (flag == 1) {
        runQueryCase(trie, tst);
    } else {
        runSearchAllCase(trie, tst, wordsInput);
    }
}
