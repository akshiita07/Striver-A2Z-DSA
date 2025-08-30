#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int clm, char num)
{
    for (int i = 0; i < 9; i++)
    {
        // check any duplicates in row:
        if (board[row][i] == num)
        {
            return false;
        }
        // check any duplicates in clm:
        if (board[i][clm] == num)
        {
            return false;
        }
        // check 3x3 subbox:
        int boxRow = 3 * (row / 3) + i / 3;
        int boxClm = 3 * (clm / 3) + i % 3;
        if (board[boxRow][boxClm] == num)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    // 9 x 9 Sudoku board
    // each row & each clm: digits 1-9 without repetition
    // each 3x3 subbox must also cnt digits 1-9 without repetition
    // solve a Sudoku puzzle by filling the empty cells
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // for non filled cell:
            if (board[i][j] == '.')
            {
                for (char num = '1'; num <= '9'; num++)
                {
                    if (isValid(board, i, j, num))
                    {
                        board[i][j] = num;
                        // recursion:
                        if (solve(board))
                        {
                            return true;
                        }
                        // backtrack if not valid:
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board) { solve(board); }

int main()
{

    return 0;
}