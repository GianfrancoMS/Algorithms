#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &numbers) {
    for (int i = 1; i < numbers.size(); ++i) {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            --j;
        }
        numbers[j + 1] = key;
    }
}

int main() {
    vector<int> numbers{1, 3, 4, -2, 1, 0};
    insertionSort(numbers);
    for (auto element: numbers)
        cout << element << " ";
    cout << endl;
    return 0;
}
