#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void coinChange(const vector<int> &coins, int amount, vector<int> &numberCoins, vector<int> &coinIndexes) {
    int size = coins.size();
    numberCoins[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        int min = INT_MAX;
        int coin = 0;
        for (int j = 0; j < size; ++j) {
            if (coins[j] <= i) {
                if (1 + numberCoins[i - coins[j]] < min) {
                    min = 1 + numberCoins[i - coins[j]];
                    coin = j;
                }
            }
        }
        numberCoins[i] = min;
        coinIndexes[i] = coin;
    }
}

vector<int> getCoinChange(const vector<int> &coins, int amount) {
    vector<int> numberCoins(amount + 1);
    vector<int> coinIndexes(amount + 1);

    coinChange(coins, amount, numberCoins, coinIndexes);

    vector<int> change;
    while (amount > 0) {
        change.push_back(coins[coinIndexes[amount]]);
        amount -= coins[coinIndexes[amount]];
    }
    return change;
}

int main() {
    vector<int> coins{1, 5, 10, 20, 25, 50};
    int amount = 99;
    auto change = getCoinChange(coins, amount);
    for (auto coin: change) {
        cout << coin << " ";
    }
    return 0;
}

