#include <iostream>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

//This implementation doesn't handle negative numbers
int binaryNumber(int number) {
    stack<int> binary;
    while (number >= 1) {
        int result = number % 2;
        binary.push(result);
        number /= 2;
    }

    int result = 0;
    while (!binary.empty()) {
        result = result * 10 + binary.top();
        binary.pop();
    }
    return result;
}

//This implementation doesn't handle negative numbers
int binaryNumberWithBitManipulation(int number) {
    string binary = bitset<32>(number).to_string();
    return atoi(binary.c_str());
}

int main() {
    int number = 0;
    cin >> number;
    cout << binaryNumber(number) << endl;
    cout << binaryNumberWithBitManipulation(number) << endl;
    return 0;
}
