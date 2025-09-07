#include <bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n)
{
    // size of array:n
    // sum of elements of array=0
    vector<int> ans;
    // for even length:
    for (int i = 1; i <= n / 2; i++)
    {
        ans.push_back(i);
        ans.push_back(-i);
    }
    // for odd length extra 0 element to be added:
    if (n % 2 != 0)
    {
        ans.push_back(0);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<int> ans = sumZero(n);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}