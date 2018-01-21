#include <iostream>
#include <vector>

using namespace std;

int maxSum(const vector<int> &numbers) {
    int currentMax = numbers[0];
    int maxUpdated = numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
        currentMax = max(numbers[i], currentMax + numbers[i]);
        maxUpdated = max(maxUpdated, currentMax);
    }
    return maxUpdated;
}

int main() {
    vector<int> numbers{1, 2, -15, 8, 7};
    cout << maxSum(numbers);
    return 0;
}
