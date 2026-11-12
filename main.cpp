#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Normalizer.hpp"

using namespace std;

//./a.out textfile.txt 
// or 
// ./a.out enter
// -> enter words one by one 

int main(int argc, char* argv[]) {
    vector<string> wordsInput;

    if (argc > 1) {
        cout << "Reading words from file: " << argv[1] << endl;
        wordsInput = readWords(argv[1]);
        cout << "Finished reading words from file: " << argv[1] << endl;

    } else {
            cout << "Please enter words: " << endl;
        while (true) {
            string word;
            cin >> word;
            if (word == "" || word == " ") {
                break;
            }
            wordsInput.push_back(normalize(word));
        }
    }


   
    return 0;
}
