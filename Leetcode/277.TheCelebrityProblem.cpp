#include <bits/stdc++.h>
using namespace std;

// TIME: O(n^2)->iterating thru matrix + O(n)->to check for celebrity
// SPACE: O(n+n)->knowMe & iKnow array
int bruteforce(vector<vector<int>> &mat)
{
    // n*n matrix where n represents no of people
    int n = mat.size();
    vector<int> iKnow(n, 0);
    vector<int> knowsMe(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check if 1:
            if (mat[i][j] == 1)
            {
                // i knows j
                iKnow[i]++;
                // j is known by i
                knowsMe[j]++;
            }
        }
    }
    // all remaining n-1 people must know the celebrity
    // celbrity must know 0 person

    // for celebrity->knowsMe==n-1 && iKnow==0
    for (int i = 0; i < n; i++)
    {
        if (knowsMe[i] == n - 1 && iKnow[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

// optimal: without storing:
// TIME: O(n)-for loop + O(n)-check that row/col ==  O(2n)
// SPACE: O(1)
int celebrity(vector<vector<int>> &mat)
{
    // n*n matrix where n represents no of people
    int n = mat.size();
    int top = 0;
    int bottom = n - 1;
    while (top < bottom)
    {
        if (mat[top][bottom] == 1)
        {
            // does top knows bottom
            top++;
        }
        else if (mat[bottom][top] == 1)
        {
            // does bottom knows top
            bottom--;
        }
        else
        {
            top++;
            bottom--;
        }
    }
    if (top > bottom)
    {
        // no celebrity exists as top has crossed bottom
        return -1;
    }
    if (top == bottom)
    {
        // possiblity ..check full row=0 and full colm=1 but diagonal=0
        for (int i = 0; i < n; i++)
        {
            if (i == top)
            {
                // do not check for diagonals:
                continue;
            }
            if (mat[top][i] == 0 && mat[i][top] == 1)
            {
            }
            else
            {
                // no celb exists
                return -1;
            }
        }
        return top; // or bottom
    }
    // all remaining n-1 people must know the celebrity
    // celbrity must know 0 person
    return -1;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    // cout << "\nThe id of celebrity is: " << bruteforce(mat);
    cout << "\nThe id of celebrity is: " << celebrity(mat);

    return 0;
}