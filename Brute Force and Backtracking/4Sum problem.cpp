#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

using Pair=pair<int, int>;

set <vector<int>> generateQuadruple(vector<int> numbers, int sum) {
    unordered_map<int, vector<Pair>> sums;
    set <vector<int>> quadruples;

    sort(numbers.begin(), numbers.end());
    int size = numbers.size();

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {

            int difference = sum - (numbers[i] + numbers[j]);

            if (sums.find(difference) != sums.end()) {
                auto pairs = sums.find(difference)->second;
                for (auto pair : pairs) {
                    int x = pair.first;
                    int y = pair.second;

                    if ((x != i && x != j) && (y != i && y != j)) {
                        vector<int> quadruple{numbers[x], numbers[y], numbers[i], numbers[j]};
                        sort(quadruple.begin(), quadruple.end());
                        quadruples.emplace(quadruple);
                        break;
                    }
                }
            }
            sums[numbers[i] + numbers[j]].push_back({i, j});
        }
    }
    return quadruples;
}

int main() {
    vector<int> numbers{2, 7, 4, 0, 9, 5, 1, 3};
    int target = 20;
    set <vector<int>> quadruples = generateQuadruple(numbers, target);
    for (auto quadruple: quadruples) {
        for (auto number:quadruple)
            cout << number;
        cout << endl;
    }
    return 0;
}
