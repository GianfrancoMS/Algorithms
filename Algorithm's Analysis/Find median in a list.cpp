#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVectorSizeEven(const vector<int> &numbers) {
    return numbers.size() % 2 == 0;
}

double medianBySelecting(vector<int> numbers) {
    int numbersSize = numbers.size() / 2;

    nth_element(numbers.begin(), numbers.begin() + numbersSize, numbers.end());

    double median = numbers[numbersSize];

    if (isVectorSizeEven(numbers)) {
        nth_element(numbers.begin(), numbers.begin() + numbersSize - 1, numbers.end());
        median = (median + numbers[numbersSize - 1]) / 2;
    }

    return median;
}

double medianBySorting(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());

    int numbersSize = numbers.size() / 2;

    double median = numbers[numbersSize];

    if (isVectorSizeEven(numbers))
        median = static_cast<double>( numbers[numbersSize] + numbers[numbersSize - 1] ) / 2;
    return median;
}

int main() {
    vector<int> evenSize{1, 4, 2, 3};
    vector<int> oddSize{1, 5, 2, 4, 3};
    cout << medianBySelecting(evenSize) << endl;
    cout << medianBySelecting(oddSize) << endl;
    cout << medianBySorting(evenSize) << endl;
    cout << medianBySorting(oddSize) << endl;
    return 0;
}



