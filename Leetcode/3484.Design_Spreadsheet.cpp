#include <bits/stdc++.h>
using namespace std;

class Spreadsheet
{
    unordered_map<string, int> cellValues; // eg: A1->value
public:
    Spreadsheet(int rows)
    {
        // 26 columns (labeled from 'A' to 'Z')
        // each cell holds value between 0 and 10^5
        // all cells initially 0
        cellValues.clear();
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                // form the column alphabet:
                char c = 'A' + j;
                // form the entire string with alphabet & row number
                string cell = c + to_string(i);
                // set value to 0:
                cellValues[cell] = 0;
            }
        }
    }

    void setCell(string cell, int value)
    {
        // Sets the value of the specified cell 'alphabet column''number to set'
        cellValues[cell] = value;
    }

    void resetCell(string cell)
    {
        // Resets the specified cell to 0
        cellValues[cell] = 0;
    }

    int getValue(string formula)
    {
        // returns sum "=X+Y"
        int ans = 0;
        // remove initial '='
        formula = formula.substr(1);
        // divide the formula by '+'
        int plusPosition = formula.find('+');
        string left = formula.substr(0, plusPosition);
        string right = formula.substr(plusPosition + 1);

        // find values of left and right operands:
        int leftVal = 0;
        int rightVal = 0;
        if (isdigit(left[0]))
        {
            // return integer form of string
            leftVal = stoi(left);
        }
        else
        {
            if (cellValues.count(left))
            {
                leftVal = cellValues[left];
            }
        }
        if (isdigit(right[0]))
        {
            // return integer form of string
            rightVal = stoi(right);
        }
        else
        {
            if (cellValues.count(right))
            {
                rightVal = cellValues[right];
            }
        }

        return leftVal + rightVal;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

int main()
{

    return 0;
}