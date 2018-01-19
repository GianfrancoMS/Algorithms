#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
    rows are counted from 1 to n
    columns are counted from 0 to n-1
*/

bool isEmpty(const vector<char> &board, int column) {
    return board[column] == 0;
}

bool isInLimits(const vector<char> &board, int row, int column) {
    if (row > board.size() || row < 1 || column >= board.size() || column < 0)
        return false;
    return true;
}

/*
    isValidPieceLeft validates that the piece to be inserted in the nth column doesn't collide with other pieces.
    For this validation, it checks the columns that are located to the left of the nth column.
    This function takes into consideration that the columns that are to the right of the nth column are empty.
*/
bool isValidPieceLeft(const vector<char> &board, int row, int column) {
    for (int i = 0; i < column; ++i) {
        if (board[i] == 0)
            continue;
        if (board[i] == row)
            return false;
        if (abs(row - board[i]) == column - i)
            return false;
    }
    return true;
}

/*
    isValidPieceRight validates that the piece to be inserted in the nth column doesn't collide with other pieces.
    For this validation, it checks the columns that are located to the right and left of the nth column.
    This function assumes that there are already pieces placed in the board.
*/
bool isValidPieceRight(const vector<char> &board, int row, int column) {
    for (int i = column + 1; i < board.size(); ++i) {
        if (board[i] == 0)
            continue;
        if (board[i] == row)
            return false;
        if (abs(row - board[i]) == abs(column - i))
            return false;
    }
    return true;
}

bool isValidPiece(const vector<char> &board, int row, int column) {
    return isInLimits(board, row, column) && isValidPieceLeft(board, row, column);
}

void printBoardState(const vector<char> &board) {
    cout << "[ ";
    for (auto i = 0; i < board.size(); ++i) {
        cout << (i != 0 ? ", " : "") << static_cast<int>( board[i] );
    }
    cout << " ]" << endl;
}

void printBoard(const vector<char> &board) {
    cout << "+";
    for (auto i = 0; i < board.size(); ++i)
        cout << "---+";
    cout << endl;
    for (auto i = 0; i < board.size(); ++i) {
        cout << "|";
        for (auto j = 0; j < board.size(); ++j) {
            if (board[j] == i + 1)
                cout << " Q |";
            else
                cout << "   |";
        }
        cout << endl;
        cout << "+";
        for (auto i = 0; i < board.size(); ++i)
            cout << "---+";
        cout << endl;
    }
}

void solveBoard(vector<char> &board, int position) {
    if (position >= board.size()) {
        printBoard(board);
        return;
    }
    for (auto i = 1; i <= board.size(); ++i) {
        printBoardState(board);
        if (isValidPiece(board, i, position)) {
            board[position] = static_cast<char>(i);
            solveBoard(board, position + 1);
        }
    }
}

int main() {
    vector<char> board{0, 0, 0, 0, 0};
    solveBoard(board, 0);
    return 0;
}
