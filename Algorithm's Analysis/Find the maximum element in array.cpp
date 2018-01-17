#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int classicMax(const vector<int> &numbers) {
    int max = numbers[0];
    int numbersSize = numbers.size();

    for (int i = 01; i < numbersSize; ++i) {
        if (numbers[i] > max)
            max = numbers[i];
    }
    return max;
}

int newMax(const vector<int> &numbers) {
    int max = *max_element(numbers.begin(), numbers.end());
    return max;
}


int main() {
    vector<int> numbers{1, 5, 4, 2, 6};
    cout << classicMax(numbers) << endl;
    cout << newMax(numbers) << endl;
    return 0;
}



