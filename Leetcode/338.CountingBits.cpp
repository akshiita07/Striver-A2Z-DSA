#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> ans; // size from 0 to n
    // traverse from 0 to n
    for (int i = 0; i <= n; i++)
    {
        // find bin representations of each
        // count no of 1s in them
        int cnt = __builtin_popcount(i);
        // add this count in array
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{
    int n = 5;
    // Output: [0,1,1,2,1,2]        no of 1s in bin representation of 0 to n
    // 0 --> 0
    // 1 --> 1
    // 2 --> 10
    // 3 --> 11
    // 4 --> 100
    // 5 --> 101
    vector<int> ans = countBits(n);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}