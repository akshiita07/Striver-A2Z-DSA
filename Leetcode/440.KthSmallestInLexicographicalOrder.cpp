#include <bits/stdc++.h>
using namespace std;

int findKthNumber(int n, int k)
{
    vector<int> lexicArr;

    int start = 1;
    for (int i = 0; i < n; i++)
    {
        lexicArr.push_back(start);
        // check if can be multiplied by 10:
        if (start * 10 <= n)
        {
            start = start * 10;
        }
        else
        {
            // exceed so backtrack
            if (start >= n)
            {
                start = start / 10;
            }
            start++;
            // remove trailing zeroes
            while (start % 10 == 0)
            {
                start = start / 10;
            }
        }
    }

    cout << "\nPrininting lexicographic array ";
    for (auto it : lexicArr)
    {
        cout << it << " ";
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans = lexicArr[i];
    }
    return ans;
}

int main()
{
    int n = 13;
    int k = 2;
    cout << "\nThe lexicographic " << k << "th number is: " << findKthNumber(n, k);

    return 0;
}