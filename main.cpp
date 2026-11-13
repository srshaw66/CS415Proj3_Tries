#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Normalizer.hpp"
#include "tests.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input-file> <flag>\n"
             << "  flag 1: search query strings and show autocomplete results\n"
             << "  flag 2: search all strings in the input file\n";
        return 1;
    }

    const string filename = argv[1];
    const string flag = argv[2];

    if (flag != "1" && flag != "2") {
        cerr << "Error: flag must be 1 or 2.\n";
        return 1;
    }

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: could not open input file: " << filename << '\n';
        return 1;
    }

    vector<string> wordsInput = readWords(filename);

    runTests(wordsInput, stoi(flag));

    return 0;
}
