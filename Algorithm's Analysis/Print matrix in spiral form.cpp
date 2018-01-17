#include <iostream>
#include <vector>

using namespace std;

void spiralPrint(const vector<vector<int>> &matrix) {
    int row = matrix.size();
    int column = matrix[0].size();
    int rowIndex = 0;
    int columnIndex = 0;

    while (rowIndex < row && columnIndex < column) {
        //Print the first row from the remaining rows
        for (int i = columnIndex; i < column; ++i)
            cout << matrix[rowIndex][i];
        ++rowIndex;

        //Print the last column from the remaining columns
        for (int i = rowIndex; i < row; ++i)
            cout << matrix[i][column - 1];
        --column;

        //Print the last row from the remaining rows
        if (rowIndex < row) {
            for (int i = column - 1; i >= columnIndex; --i)
                cout << matrix[row - 1][i];
            --row;
        }

        //Print the first column from the remaining columns
        if (columnIndex < column) {
            for (int i = row - 1; i >= rowIndex; --i)
                cout << matrix[i][columnIndex];
            ++columnIndex;
        }
    }
}

int main() {
    vector<vector<int>> matrix{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    spiralPrint(matrix);
    return 0;
}
