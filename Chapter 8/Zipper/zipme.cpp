#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

// Used for file loading
int inputCount;
string* allInputs;

// Used for the actual algorithm
vector<char> firstWord;
vector<char> secondWord;
vector<char> thirdWord;
string testWord;

void removeFirstLetter(vector<char> &inWord) {
    inWord.erase(inWord.begin());
    testWord.erase(testWord.begin());
}

bool zipper() {
    // Length changes each rep so we need a constant
    int length = testWord.length();

    for (int i = 0; i < length; i++) {
        char currentLetter = testWord[0];

        // Refractor to avoid multiple calls to an array
        char firstWordLetter = firstWord.empty()? ' ' : firstWord.at(0);
        char secondWordLetter = secondWord.empty()? ' ' : secondWord.at(0);
        char thirdWordLetter = thirdWord.empty()? ' ' : thirdWord.at(0);

        // Test currenLetter against thirdWord's first letter if not empty
        if (!thirdWord.empty() && thirdWordLetter == currentLetter) {
            removeFirstLetter(thirdWord);
        }

        // Test currentLetter against both firstWord and secondWord for duplicates
        else if (!firstWord.empty() && !secondWord.empty() && firstWordLetter == currentLetter && secondWordLetter == currentLetter) {
            // Append currentLetter to the end of the array
            thirdWord.push_back(currentLetter);

            // Remove all occurances of the current letter
            firstWord.erase(firstWord.begin());
            secondWord.erase(secondWord.begin());
            testWord.erase(testWord.begin());
        }

        // Test currentLetter against firstWord's first letter if not empty
        else if (!firstWord.empty() && firstWordLetter == currentLetter) {
            removeFirstLetter(firstWord);
        }

        // Test currentLetter against secondWord's first letter if not empty
        else if (!secondWord.empty() && secondWordLetter == currentLetter) {
            removeFirstLetter(secondWord);
        }

        else {
            break;
        }
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

void loadInput(string wordToLoad, vector<char> &vectorToLoadInto) {
    /* Function
     * wordToLoad = word to load into
     * vectorToLoadInto = vector to load word into
     */
    vectorToLoadInto.clear();
    for (int i = 0; i < wordToLoad.length(); i++) {
        vectorToLoadInto.push_back(wordToLoad[i]);
    }
}

string* splitInput(string inputWord) {
    string* splitWord = new string[3];
    char* inWord = strdup(inputWord.c_str());
    splitWord[0] = std::strtok(inWord, " ");
    for (int i = 1; i < 3; i++) {
        splitWord[i] = std::strtok(NULL, " ");
    }

    return splitWord;
}

void readInput() {
    ifstream inFile("b.in");
    string temp; // used for reading and concats
    string toBeInputs;

    if (inFile.is_open()) {
        getline(inFile, temp);
        inputCount = stoi(temp);

        allInputs = new string[inputCount];
        for (int i = 0; i < inputCount ; i++) {
            getline(inFile, allInputs[i]);
        }
    }
}

int main() {
    readInput();

    for (int i = 0; i < inputCount; i++) {
        string* splitWords = splitInput(allInputs[i]);
        loadInput(splitWords[0], firstWord);
        loadInput(splitWords[1], secondWord);
        testWord = splitWords[2];
        string status = zipper()? "yes": "no";
        printf("Data set %i: %s\n", i + 1, status.c_str());

    }

    return 0;
}
