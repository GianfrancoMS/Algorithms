#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void fastestWay(const vector <vector<int>> &assemblyCost,
                const vector <vector<int>> &transferCost,
                const vector<int> &entryCost,
                const vector<int> &existCost) {

    const int FROM_LINE_ONE = 1;
    const int FROM_LINE_TWO = 2;

    const int LINE_ONE = 0;
    const int LINE_TWO = 1;

    const int FROM_LINE_ONE_TO_LINE_TWO = 0;
    const int FROM_LINE_TWO_TO_LINE_ONE = 1;

    const int assemblyLineSize = assemblyCost[0].size();

    vector<int> costAssemblyLineOne(assemblyLineSize);
    vector<int> costAssemblyLineTwo(assemblyLineSize);

    vector<int> lineOne(assemblyLineSize);
    vector<int> lineTwo(assemblyLineSize);

    costAssemblyLineOne[0] = entryCost[LINE_ONE] + assemblyCost[LINE_ONE][0];
    costAssemblyLineTwo[0] = entryCost[LINE_TWO] + assemblyCost[LINE_TWO][0];

    //Trace of the algorithm

    for (int j = 1; j < assemblyLineSize; ++j) {
        if (costAssemblyLineOne[j - 1] + assemblyCost[LINE_ONE][j] <=
            costAssemblyLineTwo[j - 1] + transferCost[FROM_LINE_TWO_TO_LINE_ONE][j - 1] + assemblyCost[LINE_ONE][j]) {

            costAssemblyLineOne[j] = costAssemblyLineOne[j - 1] + assemblyCost[LINE_ONE][j];
            lineOne[j] = FROM_LINE_ONE;

        } else {
            costAssemblyLineOne[j] = costAssemblyLineTwo[j - 1] + transferCost[FROM_LINE_TWO_TO_LINE_ONE][j - 1] +
                                     assemblyCost[LINE_ONE][j];
            lineOne[j] = FROM_LINE_TWO;
        }

        if (costAssemblyLineTwo[j - 1] + assemblyCost[LINE_TWO][j] <=
            costAssemblyLineOne[j - 1] + transferCost[FROM_LINE_ONE_TO_LINE_TWO][j - 1] + assemblyCost[LINE_TWO][j]) {

            costAssemblyLineTwo[j] = costAssemblyLineTwo[j - 1] + assemblyCost[LINE_TWO][j];
            lineTwo[j] = FROM_LINE_TWO;

        } else {
            costAssemblyLineTwo[j] = costAssemblyLineOne[j - 1] + transferCost[FROM_LINE_ONE_TO_LINE_TWO][j - 1] +
                                     assemblyCost[LINE_TWO][j];
            lineTwo[j] = FROM_LINE_ONE;
        }
    }

    int minimumCost = 0;
    int finalLine = 0;

    if (costAssemblyLineOne[assemblyLineSize - 1] + existCost[LINE_ONE] <=
        costAssemblyLineTwo[assemblyLineSize - 1] + existCost[LINE_TWO]) {

        minimumCost = costAssemblyLineOne[assemblyLineSize - 1] + existCost[LINE_ONE];
        finalLine = FROM_LINE_ONE;

    } else {
        minimumCost = costAssemblyLineTwo[assemblyLineSize - 1] + existCost[LINE_TWO];
        finalLine = FROM_LINE_TWO;
    }

    //Constructing an optimal solution
    cout << "Minimum cost: " << minimumCost << endl;
    stack <string> solution;

    solution.push("exit");

    if (finalLine == FROM_LINE_ONE) {
        solution.push("x1");
        solution.push("S1," + to_string(assemblyLineSize));
    } else {
        solution.push("x2");
        solution.push("S2," + to_string(assemblyLineSize));
    }

    int lastLine = finalLine;
    int currentLine = finalLine;
    for (int i = assemblyLineSize - 1; i >= 1; --i) {
        if (lastLine == FROM_LINE_ONE)
            currentLine = lineOne[i];
        else
            currentLine = lineTwo[i];

        if (currentLine != lastLine)
            solution.push("t" + to_string(currentLine) + "," + to_string(i));

        solution.push("S" + to_string(currentLine) + "," + to_string(i));
        lastLine = currentLine;
    }

    if (lastLine == FROM_LINE_ONE)
        solution.push("e1");
    else
        solution.push("e2");

    solution.push("start");

    while (!solution.empty()) {
        cout << solution.top();
        if (solution.size() >= 2)
            cout << " -> ";
        solution.pop();
    }
}

int main() {
    vector <vector<int>> assemblyCost{{7, 9, 3, 4, 8, 4},
                                      {8, 5, 6, 4, 5, 7}};

    vector <vector<int>> transferCost{{2, 3, 1, 3, 4},
                                      {2, 1, 2, 2, 1}};

    vector<int> entryCost{2, 4};
    vector<int> existCost{3, 2};

    fastestWay(assemblyCost, transferCost, entryCost, existCost);

    return 0;
}
