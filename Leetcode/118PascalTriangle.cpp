#include <bits/stdc++.h>
using namespace std;

// TIME: O(colms)
int generate_give_element(int row, int col)
{
    row -= 1; // 4
    col -= 1; // 2
    int element = 1;

    // (row-1)C(col-1)
    for (int i = 0; i < col; i++)
    {
        element *= (row - i);
        element /= (i + 1);
    }
    // cout << element << " ";
    return element;
}

// BRUTE:   TIME: O(row*colms)
void generate_give_row_brute(int row, int col)
{
    // (row-1)C(col-1) for full row elements
    for (int i = 1; i <= row; i++)
    {
        generate_give_element(row, i);
    }
}

// BETTER:   TIME: O(row)
void generate_give_row_better(int row, int col)
{
    // 1st element is always 1
    int element = 1;
    // start colm index from 0 to rowNumber
    for (int i = 1; i <= row; i++)
    {
        cout << element << " ";
        // elem/colm
        // elem*(row-col)
        element *= (row - i);
        element /= i;
    }
}

// BRUTE:   TIME: O(numRows*row*colms)--> using nCr so almost O(n^3)
void generate_full_triangle_brute(int numRows)
{
    vector<vector<int>> ans;
    int element;
    for (int i = 1; i <= numRows; i++)
    {
        vector<int> temp;
        for (int j = 1; j <= i; j++)
        {
            element = generate_give_element(i, j);
            temp.push_back(element);
        }
        ans.push_back(temp);
    }

    cout << "The pascal triangle upto " << numRows << " is: \n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

// BETTER/OPTIMAL:   TIME: O(numRows*row)--> using BETTER APPROACH so almost O(n^2)
void generate_full_triangle(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 1; i <= numRows; i++)
    {
        vector<int> temp;
        int element = 1;
        temp.push_back(element);
        for (int j = 1; j < i; j++)
        {
            element *= (i - j);
            element /= (j);
            temp.push_back(element);
        }
        ans.push_back(temp);
    }

    cout << "The pascal triangle upto " << numRows << " is: \n";
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numRows = 5;
    // generate_give_element(5,3);     //5 row & 3 colm-> 6
    // generate_give_row_brute(5, 3); // 5 row & 3 colm-> 6
    // generate_give_row_better(5, 3); // 5 row & 3 colm-> 6
    // generate_full_triangle_brute(numRows);
    generate_full_triangle(numRows); // 5 row & 3 colm-> 6

    return 0;
}