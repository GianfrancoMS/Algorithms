#include <iostream>
#include <vector>

using namespace std;

void minAndMax(const vector<int> &numbers, int initial, int final, int &min, int &max) {
    if (initial < final - 1) {
        int medium = (initial + final) / 2;
        int minUp, minLow, maxUp, maxLow = 0;
        minAndMax(numbers, initial, medium, minLow, maxLow);
        minAndMax(numbers, medium + 1, final, minUp, maxUp);
        if (maxUp > maxLow)
            max = maxUp;
        else
            max = maxLow;
        if (minUp > minLow)
            min = minLow;
        else
            min = minUp;
    } else {
        if (initial == final - 1) {
            if (numbers[initial] > numbers[final]) {
                max = numbers[initial];
                min = numbers[final];
            } else {
                max = numbers[final];
                min = numbers[initial];
            }
        } else {
            max = numbers[initial];
            min = max;
        }
    }
}

int main() {
    int min = 0;
    int max = 0;
    vector<int> numbers{4, 0, 2213, 6112};
    minAndMax(numbers, 0, numbers.size() - 1, min, max);
    cout << min << endl;
    cout << max << endl;
    return 0;
}
