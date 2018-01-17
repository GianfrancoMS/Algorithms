#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumXOR(int left, int right) {
    int difference = right - left;
    vector<int> storage(difference);

    int current = left;
    for (int i = left; i <= right; i++) {
        storage.push_back(current ^ i);
        if (i == right) {
            current = current + 1;
            i = current;
        } else if (i > right)
            break;
    }
    return *max_element(storage.begin(), storage.end());
}


int main() {
    int left, right;
    cin >> left >> right;
    cout << maximumXOR(left, right);
}
