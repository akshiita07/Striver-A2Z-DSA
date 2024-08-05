#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE:     TIME-O(m*n)
vector<int> brute_force(vector<vector<int>> &mat)
{
    vector<int> ans(2, -1);
    int m = mat.size();
    int n = mat[0].size();
    // ans[0]-->row
    // ans[1]-->count of no of 1s
    int maxCount = INT_MIN;
    int rowNo = -1;
    for (int i = 0; i < m; i++)
    {
        int count1 = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                count1++;
            }
        }
        if (count1 > maxCount || (count1 == maxCount && i < rowNo))
        {
            maxCount = count1;
            rowNo = i;
        }
    }
    ans[0] = rowNo;
    ans[1] = maxCount;
    return ans;
}

// BINARY SEARCH:     TIME-O(m*log2(n))
vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    vector<int> ans(2, -1);
    int m = mat.size();
    int n = mat[0].size();
    // ans[0]-->row
    // ans[1]-->count of no of 1s

    // find first occurence of 1
    // count of 1s: size of row:n-first occurence

    int maxCount = INT_MIN;
    int rowNo = -1;

    for (int i = 0; i < m; i++)
    {
        sort(mat[i].begin(), mat[i].end());
        int low = 0;
        int high = n - 1;
        int firstOcc;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (mat[i][mid] == 1)
            // first index only starts with 1
            {
                // first occ
                firstOcc = mid;
                high = mid - 1;
            }
            else
            {
                // twds right
                low = mid + 1;
            }
        }
        int count1 = n - firstOcc;
        if (count1 > maxCount)
        {
            maxCount = count1;
            rowNo = i;
        }
    }
    ans[0] = rowNo;
    ans[1] = maxCount;
    return ans;
}

int main()
{
    vector<vector<int>> mat1 = {{0, 1}, {1, 0}}; //[0,1]

    vector<int> ans1 = rowAndMaximumOnes(mat1);
    cout << "\nFor mat1: smallest row: " << ans1[0] << " & count of 1s: " << ans1[1];

    vector<vector<int>> mat2 = {{0, 0, 0}, {0, 1, 1}}; //[1,2]

    vector<int> ansBrute = brute_force(mat2);
    cout << "\nBRUTE FORCE- For mat2: smallest row: " << ansBrute[0] << " & count of 1s: " << ansBrute[1];

    vector<int> ans2 = rowAndMaximumOnes(mat2);
    cout << "\nFor mat2: smallest row: " << ans2[0] << " & count of 1s: " << ans2[1];

    return 0;
}