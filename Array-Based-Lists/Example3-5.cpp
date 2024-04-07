
//*************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use two-dimensional dynamic // arrays.
// *************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

void fill(int **p, int rowSize, int columnSize);
void print(int **p, int rowSize, int columnSize);

int main() {
    int **board;
    int rows;
    int columns;

    cout << "Line 11: Enter the number rows "
         << "and columns: ";
    cin >> rows >> columns;
    cout << endl;

    //Create the rows of board
    board = new int* [rows];

    //Create the columns of board
    for (int row = 0; row < rows; row++)
        board[row] = new int[columns];
        //Insert elements into board
        fill(board, rows, columns);

        cout << "Line 18: Board:" << endl;

        //Output the elements of board
        print(board, rows, columns);

    return 0;

}

void fill(int **p, int rowSize, int columnSize) {
    for (int row = 0; row < rowSize; row++) {
        cout << "Enter " << columnSize << " number(s) for row "
             << "number " << row << ": ";
        for (int col = 0; col < columnSize; col++)
            cin >> p[row][col];
        cout << endl;
    }
}

void print(int **p, int rowSize, int columnSize){
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < columnSize; col++)
            cout << setw(5) << p[row][col];
        cout << endl;
    }
}
