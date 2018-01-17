#include <iostream>
#include <vector>

using namespace std;

void minAndMax(const vector<int> &numbers, int &min, int &max) {
    min = numbers[0];
    max = numbers[1];

    if (min > max)
        swap(min, max);

    int numberSize = numbers.size();

    if (numberSize % 2 == 0) {
        for (int i = 2; i < numberSize; i += 2) {
            if (numbers[i] < numbers[i + 1]) {
                if (numbers[i] < min)
                    min = numbers[i];
                if (numbers[i + 1] > max)
                    max = numbers[i + 1];
            } else {
                if (numbers[i + 1] < min)
                    min = numbers[i + 1];
                if (numbers[i] > max)
                    max = numbers[i];
            }
        }
    } else {
        for (int i = 1; i < numberSize; i += 2) {
            if (numbers[i] < numbers[i + 1]) {
                if (numbers[i] < min)
                    min = numbers[i];
                if (numbers[i + 1] > max)
                    max = numbers[i + 1];
            } else {
                if (numbers[i + 1] < min)
                    min = numbers[i + 1];
                if (numbers[i] > max)
                    max = numbers[i];
            }
        }
    }
}

int main() {
    int min = 0;
    int max = 0;
    vector<int> numbers{524, 123, 4, 3, 78, 12, 523};
    minAndMax(numbers, min, max);
    cout << min << endl;
    cout << max << endl;
    return 0;
}

