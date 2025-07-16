#include <bits/stdc++.h>
using namespace std;

int maximumLength(vector<int> &nums)
{
    // subsequence sub must staisfy: sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2
    // 1. either all even
    // 2. either all odd
    // 3. either alternate even odd
    // 4. either alternate odd even
    // create parity array:
    vector<int> parityArr;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
        {
            // even: 0
            parityArr.push_back(0);
        }
        else
        {
            // odd: 1
            parityArr.push_back(1);
        }
    }
    // check all 4 possibilities:
    int maxLength = INT_MIN;

    int len1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (parityArr[i] == 0)
        {
            len1++;
        }
    }
    maxLength = max(maxLength, len1);

    int len2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (parityArr[i] == 1)
        {
            len2++;
        }
    }
    maxLength = max(maxLength, len2);

    int len3 = 0;
    int reqd = 0;
    for (int i = 0; i < n; i++)
    {
        if (parityArr[i] == reqd)
        {
            len3++;
            reqd ^= 1; // flip
        }
    }
    maxLength = max(maxLength, len3);

    int len4 = 0;
    reqd = 1;
    for (int i = 0; i < n; i++)
    {
        if (parityArr[i] == reqd)
        {
            len4++;
            reqd ^= 1; // flip
        }
    }
    maxLength = max(maxLength, len4);

    return maxLength;
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 2, 1, 2};
    cout << "\nMaximum length of valid subsequence: " << maximumLength(nums);

    return 0;
}