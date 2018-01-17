#include <iostream>

using namespace std;

int iterativeFactorial(int number) {
    if (number == 0 || number == 1)
        return 1;
    else if (number == 2)
        return 2;
    else {
        int factorial = 2;
        for (int i = 3; i <= number; ++i)
            factorial = factorial * i;
        return factorial;
    }
}

int recursiveFactorial(int number) {
    if (number == 0 || number == 1)
        return 1;
    else if (number == 2)
        return 2;
    return recursiveFactorial(number - 1) * number;
}

int tailRecursiveFactorial(int number, int accumulation = 1) {
    return number == 0 ? accumulation : tailRecursiveFactorial(number - 1, number * accumulation);
}

int main() {
    int number = 0;
    cin >> number;
    cout << iterativeFactorial(number) << endl;
    cout << recursiveFactorial(number) << endl;
    cout << tailRecursiveFactorial(number) << endl;
    return 0;
}

