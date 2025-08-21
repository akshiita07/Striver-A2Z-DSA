#include <bits/stdc++.h>
using namespace std;

int numSubmat(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int ans = 0;
    // return the number of submatrices that have all ones
    vector<int> height(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                height[j] = 0;
            }
            else
            {
                height[j] += 1;
            }
        }
        for (int j = 0; j < n; j++)
        {
            int minHeight = height[j];
            for (int k = j; k >= 0; k--)
            {
                minHeight = min(minHeight, height[k]);
                ans += minHeight;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {};
    cout << "\nnumber of submatrices that have all ones= " << numSubmat(mat);

    return 0;
}