#include <iostream>
#include <vector>

using namespace std;

int recursiveFibonacci(int position) {
    if (position == 0 || position == 1)
        return 1;
    return recursiveFibonacci(position - 2) + recursiveFibonacci(position - 1);
}

int iterativeFibonacci(int position) {
    if (position == 0 || position == 1)
        return 1;
    int current = 0;
    int prevFirst = 1;
    int prevSecond = 1;
    for (int i = 2; i <= position; ++i) {
        current = prevFirst + prevSecond;
        prevSecond = prevFirst;
        prevFirst = current;
    }
    return current;
}

int topDownFibonacci(int position, vector<int> fibonnaci) {
    if (fibonnaci.empty())
        fibonnaci.resize(position + 1, 0);

    if (position == 0 || position == 1)
        return 1;
    else if (fibonnaci[position] != 0)
        return fibonnaci[position];
    else {
        fibonnaci[position] = topDownFibonacci(position - 2, fibonnaci) +
                              topDownFibonacci(position - 1, fibonnaci);
        return fibonnaci[position];
    }
}

int bottomUpFibonacci(int position) {
    if (position == 0 || position == 1)
        return 1;
    vector<int> fibonacci(position + 1, 1);
    for (int i = 2; i <= position; ++i) {
        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
    }
    return fibonacci[position];
}

int main() {
    int position = 0;
    cin >> position;
    vector<int> fibonacci;
    cout << "Recursive Fibonacci: " << recursiveFibonacci(position) << endl;
    cout << "Iterative Fibonacci: " << iterativeFibonacci(position) << endl;
    cout << "Top Down Fibonacci: " << topDownFibonacci(position, fibonacci) << endl;
    cout << "Bottom Up Fibonacci: " << bottomUpFibonacci(position) << endl;
    return 0;
}
