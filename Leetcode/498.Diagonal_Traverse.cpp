#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    // return an array of all the elements of the array in a diagonal order
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans;

    for (int i = 0; i < m + n - 1; i++)
    {
        vector<int> temp;
        int r = 0;
        if (i >= n)
        {
            r = i - n + 1;
        }
        int c = i;
        if (i >= n)
        {
            c = n - 1;
        }

        while (r < m && c >= 0)
        {
            temp.push_back(mat[r][c]);
            r++;
            c--;
        }

        if (i % 2 == 0)
        {
            reverse(temp.begin(), temp.end());
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Output: [1,2,4,7,5,3,6,8,9]
    vector<int> ans = findDiagonalOrder(mat);
    cout << "Ans: \n ";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}