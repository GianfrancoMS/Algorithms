#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &array, int toSearch) {
    int start = 0;
    int end = array.size() - 1;
    int guess = end / 2;
    while (start <= end) {
        int current = array[guess];
        if (current == toSearch)
            return guess;
        else if (current < toSearch)
            start = guess + 1;
        else
            end = guess - 1;
        guess = (start + end) / 2;
    }
    return -1;
}

int main() {
    vector<int> numbers{1, 4, 6, 87, 235, 678, 909, 1000};
    int index = binarySearch(numbers, 235);
    if (index != -1)
        cout << numbers[index];
    else
        cout << "Not found";
    return 0;
}