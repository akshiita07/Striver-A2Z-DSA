#include <bits/stdc++.h>
using namespace std;

// TIME: O(log2(n))->divison by 2
// SPACE: O(1)
string baseNeg2(int n)
{
    if (n == 0)
    {
        return "0";
    }
    string ans = "";
    while (n != 0)
    {
        int remain = abs(n % (-2)); // absolute value
        if (remain == 1)
        {
            ans+='1';
            n = (n - 1) / (-2);
        }
        else
        {
            // remain==0:
            ans+='0';
            n = n / (-2);
        }
    }
    // also now reverse this string:
    // bottom up ans
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n1 = 2;
    cout << "\nConvert " << n1 << " to base -2 we get: " << baseNeg2(n1);
    int n2 = 3;
    cout << "\nConvert " << n2 << " to base -2 we get: " << baseNeg2(n2);

    return 0;
}