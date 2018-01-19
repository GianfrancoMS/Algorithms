#include <iostream>
#include <vector>

using namespace std;

int max(const vector<int> &numbers, int initial, int final) {
    if (initial == final)
        return numbers[initial];
    else {
        int medium = (initial + final) / 2;
        int maxLow = max(numbers, initial, medium);
        int maxUp = max(numbers, medium + 1, final);
        if (maxLow > maxUp)
            return maxLow;
        else
            return maxUp;
    }
}

int _max(const vector<int> &numbers, int initial, int final) {
    return max(numbers, initial, final);
}

int main() {
    vector<int> numbers{5, 1253, 51221, 100000};
    int max = _max(numbers, 0, numbers.size() - 1);
    cout << max << endl;
    return 0;
}
