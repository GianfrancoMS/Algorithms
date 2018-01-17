#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void replaceVowelsWithNumbers(string &input) {
    unordered_map<char, char> vowels;
    vowels['a'] = '1';
    vowels['e'] = '2';
    vowels['i'] = '3';
    vowels['o'] = '4';
    vowels['u'] = '5';
    transform(input.begin(), input.end(), input.begin(),
              [vowels](char &c) -> char { return vowels.find(c) != vowels.end() ? vowels.find(c)->second : c; });
}


int main() {
    string input;
    cin >> input;
    replaceVowelsWithNumbers(input);
    cout << input << endl;
    return 0;
}
