#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
vector<char> firstWord;
vector<char> secondWord;
vector<char> thirdWord;
string testWord;

bool isWordEqual(vector<char> inputWord) {
    if (inputWord.empty() || inputWord[0] != testWord[0]) {
        return false;
    }
    return true;
}

bool zipper() {
    int length = testWord.length();
    vector<char> *vectorPointer;
    for (int i = 0; i < length; i++) {
        char currentLetter = testWord[0];

        // Test currenLetter against thirdWord's first letter if not empty
        if (!thirdWord.empty() && thirdWord.at(0) == currentLetter) {
            thirdWord.erase(thirdWord.begin());
            testWord.erase(testWord.begin());
            continue;
        }

        // Test currentLetter against both firstWord and secondWord for duplicates
        if (!firstWord.empty() && !secondWord.empty() && firstWord.at(0) == currentLetter && secondWord.at(0) == currentLetter) {
            // Append currentLetter to the end of the array
            thirdWord.push_back(currentLetter);

            // Remove all occurances of the current letter
            firstWord.erase(firstWord.begin());
            secondWord.erase(secondWord.begin());
            testWord.erase(testWord.begin());
            continue;
        }

        // Test currentLetter against firstWord's first letter if not empty
        if (!firstWord.empty() && firstWord.at(0) == currentLetter) {
            firstWord.erase(firstWord.begin());
            testWord.erase(testWord.begin());
            continue;
        }

        // Test currentLetter against secondWord's first letter if not empty
        if (!secondWord.empty() && secondWord.at(0) == currentLetter) {
            secondWord.erase(secondWord.begin());
            testWord.erase(testWord.begin());
            continue;
        }

        // If all above is false, break out
        break;
    }

    /*  Yes state is when:
            testWord's size is 0
            all word are completely empty (to avoid too many or little words)
     */
    if (testWord.empty() && firstWord.empty() && secondWord.empty() && thirdWord.empty()) {
        return true;
    }
    return false;
}

void loadInput(string word, vector<char> *vector) {
    for (int i = 0; i < word.length(); i++) {
        (*vector).push_back(word[i]);
    }
}

void getInput() {
    string word1, word2;

    ifstream input("b.in");

    if ( input.is_open() ) {
        getline(input, word1);
        getline(input, word2);
        getline(input, testWord);
    }
    cout << "Inputted Values Are: " << word1 << " & " << word2 << " to match with: " << testWord << endl << endl;
    loadInput(word1, &firstWord);
    loadInput(word2, &secondWord);
}

int main() {
    getInput();
    string status = zipper()? "yes": "no";
    cout << "Data set n: " << status << endl;
    return 0;
}
