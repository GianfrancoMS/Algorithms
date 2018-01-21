#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numberRoutes, maxHour, flat;
    vector<int> morningRoutes;
    vector<int> eveningRoutes;

    while (cin >> numberRoutes >> maxHour >> flat) {
        if (numberRoutes == 0 && maxHour == 0 && flat == 0) break;

        morningRoutes.resize(numberRoutes);
        eveningRoutes.resize(numberRoutes);

        for (int i = 0; i < numberRoutes; ++i) {
            cin >> morningRoutes[i];
        }
        for (int i = 0; i < numberRoutes; ++i) {
            cin >> eveningRoutes[i];
        }

        sort(morningRoutes.begin(), morningRoutes.end());
        sort(eveningRoutes.rbegin(), eveningRoutes.rend());

        int overtime = 0;
        for (int i = 0; i < numberRoutes; ++i) {
            if (morningRoutes[i] + eveningRoutes[i] > maxHour) {
                overtime += morningRoutes[i] + eveningRoutes[i] - maxHour;
            }
        }
        cout << (overtime * flat) << endl;
    }
}


