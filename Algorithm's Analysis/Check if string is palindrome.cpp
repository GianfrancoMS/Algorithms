#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(const string &word) {
    string reverseWord = word.substr();
    reverse(reverseWord.begin(), reverseWord.end());
    return word == reverseWord;
}

int main() {
    string input;
    cin >> input;
    cout << isPalindrome(input) << endl;
    return 0;
}

