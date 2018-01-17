#include <iostream>
#include <vector>

using namespace std;

vector<double> average(const vector<double> &elements) {
    int elementsSize = elements.size();

    vector<double> averageElements(elementsSize);

    for (int i = 0; i < elementsSize; ++i) {
        double sum = 0;
        for (int j = 0; j <= i; ++j)
            sum += elements[j];
        averageElements[i] = sum / (i + 1);
    }

    return averageElements;
}

int main() {
    vector<double> elements{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto averageElements = average(elements);
    for (auto element: averageElements)
        cout << element << endl;
    return 0;
}

