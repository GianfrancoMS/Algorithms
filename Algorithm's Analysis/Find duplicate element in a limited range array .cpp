#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int findDuplicate(const vector<int> &numbers) {
    int size = numbers.size();
    unordered_map<int, int> duplicates;
    for (int i = 0; i < size; ++i) {
        int current = numbers[i];
        if (duplicates.find(current) == duplicates.end()) {
            duplicates.insert({current, current});
        } else {
            int duplicate = current;
            return duplicate;
        }
    }
}

int main() {
    vector<int> numbers{2, 2, 1, 4, 5, 8, 0};
    cout << findDuplicate(numbers);
    return 0;
}