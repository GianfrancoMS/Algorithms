#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    int sqrtNumber = sqrt(number);
    for (int i = 0; i <= sqrtNumber; ++i) {
        if (number % sqrtNumber == 0)
            return false;
    }
    return true;
}

int main() {
    int number = 0;
    cin >> number;
    if (isPrime(number))
        cout << "Number is prime" << endl;
    else
        cout << "Number is not prime" << endl;
    return 0;
}



