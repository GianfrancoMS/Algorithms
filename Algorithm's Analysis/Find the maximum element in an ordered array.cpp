#include <iostream>
#include <vector>

using namespace std;

int maxNumberInOrderedArray(const vector<int> &numbers) {
    return numbers.front() > numbers.back() ? numbers.front() : numbers.back();
}

int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 6};
    cout << maxNumberInOrderedArray(numbers) << endl;
    return 0;
}
