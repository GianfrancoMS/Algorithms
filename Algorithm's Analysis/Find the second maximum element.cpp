#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int secondMaxBySelecting(vector<int> numbers) {
    int numbersSize = numbers.size();
    nth_element(numbers.begin(), numbers.begin() + numbersSize - 2, numbers.end());
    int secondMax = numbers[numbersSize - 2];
    return secondMax;
}

int secondMaxBySorting(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    int secondMax = numbers[numbers.size() - 2];
    return secondMax;
}

int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 5, 6, 7};
    cout << secondMaxBySelecting(numbers) << endl;
    cout << secondMaxBySorting(numbers) << endl;
    return 0;
}

