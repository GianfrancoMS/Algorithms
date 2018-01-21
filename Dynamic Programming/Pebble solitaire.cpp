#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

int pebblesRecursive(string line, unordered_map<string, int> &counter, int &min) {
    if (counter.find(line) != counter.end())
        return counter[line];

    string temp = line;

    for (int i = 0; i < 11; i++) {
        if (line[i] == 'o' && line[i + 1] == 'o') {
            if (i + 2 < 12 && line[i + 2] == '-') {
                line[i + 2] = 'o';
                line[i + 1] = '-';
                line[i] = '-';
                counter[line] = pebblesRecursive(line, counter, min);
            }
            if (i - 1 >= 0 && line[i - 1] == '-') {
                line[i + 1] = '-';
                line[i] = '-';
                line[i - 1] = 'o';
                counter[line] = pebblesRecursive(line, counter, min);
            }
            line = temp;
        }
    }

    int count = 0;
    for (int i = 0; i < 12; i++) {
        if (line[i] == 'o')
            count++;
    }
    if (count < min)
        min = count;

    return min;
}

int pebbles(string line) {
    unordered_map<string, int> counter;
    int min = 255;
    return pebblesRecursive(line, counter, min);
}

int main() {
    cout << pebbles("---oo-------") << endl;
    cout << pebbles("-o--o-oo----") << endl;
    cout << pebbles("-o----ooo---") << endl;
    cout << pebbles("oooooooooooo") << endl;
    cout << pebbles("oooooooooo-o") << endl;
    return 0;
}



