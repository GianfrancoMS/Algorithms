#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//rows are counted from 1 to n
//columns are counted from 0 to n-1

/*
validates the left columns of the nth-column since we know that
 the right side of it is empty
*/
bool validatePiece(const vector<char> &board, int row, int column) {
    if(row > board.size() || row < 1 || column >= board.size()  || column < 0)
        return false;
    for (int i = 0; i < column; ++i) {
        if (board[i] == row)
            return false ;
        if (abs(row - board[i]) == column - i)
            return false;
    }
    return true;
}

void printBoardState(const vector<char> &board) {
    cout << "[ ";
    for (auto i = 0; i < board.size(); ++i) {
        cout << (i != 0 ? ", " : "") << static_cast<int>( board[i] );
    }
    cout << " ]"<< endl;
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

void solveBoard(vector<char>&board, int position) {
    if (position >= board.size())
    {
        printBoard(board); //only prints the board when it is in a correct state that is to say that the n queens are positioned correctly.
        cout << endl;
        return;
    }
    for (auto i = 1; i <= board.size(); ++i) {
        printBoardState(board);
        if (validatePiece(board, i, position) ) {
            board[position] = i;
            solveBoard(board, position + 1);
        }
    }
}

/*
int main() {
    vector<char>board {0,0,0,0,0};
    solveBoard(board,0);
    return 0;
}*/
