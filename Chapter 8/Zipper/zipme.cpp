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
        if (testWord[0] == firstWord[0] && testWord[0] == secondWord[0]) {
            thirdWord.push_back(testWord[0]);

            firstWord.erase(firstWord.begin());
            secondWord.erase(secondWord.begin());
        } else if (isWordEqual(firstWord)) {
            vectorPointer = &firstWord;
        } else if (isWordEqual(secondWord)) {
            vectorPointer = &secondWord;
        } else if (isWordEqual(thirdWord)) {
            vectorPointer = &thirdWord;
        } else {
            return false;
        }

        (*vectorPointer).erase((*vectorPointer).begin());
        testWord.erase(0, sizeof(testWord[0]));
    }
    return true;
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
