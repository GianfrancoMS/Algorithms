#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string &word) {
    string reverseWord = word.substr();
    reverse(reverseWord.begin(), reverseWord.end());
    return word == reverseWord;
}

string minimumCharacters(const string &word) {
    int initial = 0;
    int final = word.size() - 1;
    while (i <= j) {
        if (word[initial] != word[final])
            --final;
        else {
            string sub = word.substr(initial + 1, final - 1);
            if (isPalindrome(sub)) {
                string rest = word.substr(final + 1);
                return rest + word;
            } else
                --final;
        }
    }
    string rest = word.substr(initial + 1);
    reverse(rest.begin(), rest.end());
    return rest + word;
}

int main() {
    string input;
    cin >> input;
    cout << minimumCharacters(input) << endl;
    return 0;
}
