#include "Normalizer.hpp"

#include <cctype>
#include <fstream>

using namespace std;

string normalize(string& token) {
    string normalizedWord;

    for (char character : token) {
        unsigned char value = static_cast<unsigned char>(character);
        if (!isalpha(value)) {
            continue;
        }

        normalizedWord += static_cast<char>(tolower(value));
    }

    return normalizedWord;
}

vector<string> readWords(string& filename) {
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
