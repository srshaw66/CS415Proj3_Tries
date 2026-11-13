#include "Normalizer.hpp"
#include <fstream>

using namespace std;

string normalize(const string& token) {
    string returnSTR;
    for (char c : token) {
        if (!isalpha(c)) {
            continue;
        }
        c = tolower(c);
        returnSTR += c;
    }
    return returnSTR;
}

vector<string> readWords(const string& filename) {
    vector<string> words;
    ifstream inputFile(filename);
    string word;
    while (inputFile >> word) {
        if (!word.empty()) {
            words.push_back(normalize(word));
        }
    }
    return words;
}