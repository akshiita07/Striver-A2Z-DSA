#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    // 9 x 9 Sudoku board
    // each row & each clm: digits 1-9 without repetition
    // each 3x3 subbox must also cnt digits 1-9 without repetition
    // only validate the filled cells
    for (int i = 0; i < 9; i++)
    {
        vector<bool> rowSet(9, false);
        vector<bool> clmSet(9, false);
        for (int j = 0; j < 9; j++)
        {
            // check number only not empty .
            // check row:
            if (board[i][j] != '.')
            {
                // convert char to int
                int number = board[i][j] - '1';
                if (rowSet[number] == true)
                {
                    // already exists so duplicate:
                    return false;
                }
                // else set it:
                rowSet[number] = true;
            }
            // check colm:
            if (board[j][i] != '.')
            {
                // convert char to int
                int number = board[j][i] - '1';
                if (clmSet[number] == true)
                {
                    // already exists so duplicate:
                    return false;
                }
                // else set it:
                clmSet[number] = true;
            }
        }
    }
    // checking 3x3 sub-boxes
    for (int boxRow = 0; boxRow < 3; boxRow++)
    {
        for (int boxClm = 0; boxClm < 3; boxClm++)
        {
            vector<bool> checkUnique(9, false);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    char num = board[boxRow * 3 + i][boxClm * 3 + j];
                    if (num != '.')
                    {
                        int number = num - '1';
                        if (checkUnique[number] == true)
                        {
                            // already exists so duplicate:
                            return false;
                        }
                        // else set it:
                        checkUnique[number] = true;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = {};
    cout << "\nvalid= " << isValidSudoku(board);

    return 0;
}