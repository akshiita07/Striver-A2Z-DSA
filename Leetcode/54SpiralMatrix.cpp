#include <bits/stdc++.h>
using namespace std;
// SPIRAL ORDER TRAVERSAL:
//                                ➡️➡️➡️➡️➡️➡️
//                                            ⬇️
//                                ⬆️➡️➡️➡️   ⬇️
//                                ⬆️          ⬇️
//                                ⬅️⬅️⬅️⬅️⬇️⬅️

// ONLY 1 POSSIBLE SOLN- OPTIMAL
void spiralOrder_optimal(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> ans;

    // right,bottom,left,top
    int top = 0;        // top row
    int bottom = m - 1; // bottom row so m-1
    int right = n - 1;  // rightmost col so n-1
    int left = 0;       // left column

    // jab tak elements / rows hai tab tak :
    while (left <= right && top <= bottom)
    {
        // NO CHANGE IN PARAMETERS UPTO HERE SO NO CONDITION CHECKS REQD:
        for (int i = left; i <= right; i++)
        {
            // print from left to right--> row is printed
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            // print from top+1 to bottom--> colm is printed
            ans.push_back(matrix[i][right]);
        }
        right--;

        // NOW BOTH TOP & RIGHT HAVE CHANGED SO CONDITION HAS TO BE CHECKED FIRST!

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                // print from right-1 to left--> row is printed
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                // print from bottom-1 to top--> colm is printed
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    cout << "\nSpiral order traversal of matrix is:" << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = matrix.size();    // rows
    int n = matrix[0].size(); // colms
    spiralOrder_optimal(matrix, m, n);

    return 0;
}